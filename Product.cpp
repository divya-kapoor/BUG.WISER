// Product.cpp
/*------------------------------------------------------------
Revision History:
Rev. 3 - 2024/07/18 Filled in the functionality
Rev. 2 - 2024/07/14 fixed formatting of coding conventions and changed type
         for selectProduct() by JK
Rev. 1 - 2024/06/30 Original by Liza Awwad
----------------------------------------------------------
This module is used to manage products. It provides functionality for 
initializing, inputting names, adding, selecting, and closing products.
----------------------------------------------------------*/
#include "Product.h"
#include "errors.h"
#include <limits>
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

// Declare an array to store products that are currently on screen
Product ProductonScreen[20];   
fstream productFile;  

/*===========================================================*/
// Default constructor
Product::Product() {
    strcpy(name, "");   // initialise empty string.
}
/*===========================================================*/
// Constructor for Product, used in assessing to select an anticipated fix release ID.
Product::Product(const char* productName) {
    strncpy(name, productName, sizeof(name) -1);    
}
/*===========================================================*/
// Initialize the product system by opening the file
bool Product::initProduct() {
    openProductFile("Product.dat"); // Open the product file
    if (productFile.is_open()) {
    } 
    else {
        cout << "Failed to open the file: Product: Product.dat\n";
    }
    return productFile.is_open(); // Return true if the file is open, otherwise false
}

/*===========================================================*/
// Function to input a new product name from the user
string Product::inputProductName() {
    // cout << "Please enter new product name:\n(1-10 characters, E.g. Pear)\n";
    // cin >> name; // Read the product name from the user

    // search in the product file for the product name inputted
    //  IF product name already exists, then  ERROR_keyUniqueness();
    //  ELSE: addProduct();

        // v  DO NOT CHANGE THIS COUT PLEASE: IT MATCHES THE USER MANUAL v
    cout << "Please enter new product name:\n(1-10 characters, E.g. Pear)\n";
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    string userInputProduct; // temp char name to test data range
    
    do {
        cin >> userInputProduct;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        if (userInputProduct.length() < 1 || userInputProduct.length() > 10) {
            ERROR_invalidDataRange();
            cout << "Please enter new product name:\n(1-10 characters, E.g. Pear)\n";
            // Use getline to read the full line for name
        }
    } while (userInputProduct.length() < 1 || userInputProduct.length() > 10);

    strcpy(name, userInputProduct.c_str());    // copy to Requester name if valid.
    return userInputProduct;
}

/*===========================================================*/
// Function to add a new product to the system
bool Product::addProduct() {
    string newName = inputProductName();
    Product cur;
    productFile.seekg(0, ios::beg);
    while (productFile.read(reinterpret_cast<char*>(&cur), sizeof(Product))){
        if (strcmp(cur.name, newName.c_str()) == 0){
            string pick;
            cout << "ERROR: Already Exists." << endl;
            cout << "1) Re-enter" << endl;
            cout << "2) Return to the previous menu." << endl;
            cout << "Type your selection and press ENTER: ";
            cin >> pick;
            if (pick == "1"){
                return addProduct();
            }
            else {
                return false;
            }

        }          
    }

    bool addedProd = false;

    int choice;

    do {
        cout << "\nIs the following information correct:\n";
        cout << "Product Name: " << name << " " << "\n";
        cout << "\n1) Confirm\n0) Cancel \nType your selection and press ENTER: ";

        cin >> choice; // Read the user's choice

        if (cin.fail()) {
            cin.clear();
            cin.ignore();
            choice = -1;    // choice is invalid
        }
        if (choice == 1) {
            writeProduct(); // Write the product to the file
            cout << "Product added, returning to the previous menu.\n";
            addedProd = true;
        } 
        else if (choice == 0) {
            cout << "Operation cancelled, returning to the previous menu.\n";
            addedProd = false;
        } 
        else {
            ERROR_invalidSelection();
            addedProd = false;
        }
    } while (choice != 1 && choice != 0);

    return addedProd;
}

/*===========================================================*/  
// Function to select an existing product from the file
Product Product::selectProduct() {
    productFile.seekg(0, ios::beg); // Move the file pointer to the beginning of the file
    return getNext();

}

/*===========================================================*/
// Function to close the product file
void Product::closeProductFile() {
    if (productFile.is_open()) {
        productFile.close(); // Close the file
    }
}

/*===========================================================*/
// Function to open the product file
void Product::openProductFile(const string &filename) {
    // Open the file in binary mode
    productFile.open(filename, ios::in | ios::out | ios::binary | ios::app); 
}

/*===========================================================*/
// Function to write a product to the file
void Product::writeProduct() {
    if (productFile.is_open()) {        
        productFile.clear();
        // Write the product to the file
        productFile.write(reinterpret_cast<const char*>(this),sizeof(Product));
    }
    
    productFile.flush();
}

/*===========================================================*/
// Function to seek to the beginning of the product file
void Product::seekToBeginningOfFile() {
    if (productFile.is_open()) {
         // Move the file pointer to the beginning of the file
        productFile.seekg(0, ios::beg);
    }
}

/*===========================================================*/
// Function to get the next product from the file based on user selection
Product Product::getNext() {
    Product cur;
    int setCounter = 0;     // Tracks which 'page' you are on
    // How many valid numerical options are on the screen at the moment
    int numOnScreen = 0;    
    string choice = "S";

    // While loop to keep running until a valid choice is made other than N or P
    while ((choice == "P") | (choice == "N") | (choice == "S")) {
        if (productFile.is_open()) {
             // If user wants to see the previous page, make sure this isn't the first page
            if (choice == "P") {    
                if (setCounter == 0) {
                    cout << "Already on the first menu.\n";
                } 
                else {
                    setCounter--;
                }
            } 
            else if (choice == "N") {
                setCounter++;
            }

            productFile.clear();  // Clear any EOF flag
            cout << "== P for the previous 20 items ==\n"
                 << "== N for the next 20 items ==\n";

            cout << "\nPlease Select a Product" << endl;
             // Ensure we start reading from the correct 'page'
            productFile.seekg((setCounter * 20) * sizeof(Product)); 
            numOnScreen = 0;     // Reset the counter of how many are on the screen
            while (numOnScreen < 20) {
                // Read the structure until the end of the 'page'
                productFile.read(reinterpret_cast<char*>(&cur), sizeof(Product));
                // Check if we read past the EOF
                if (productFile.eof()) {
                    productFile.clear();  // Clear the EOF flag
                    break;
                }

                // Print the product name read to screen
                cout << (numOnScreen + 1) << ") " << cur.name << "\n";
                // Add the product to the onScreen array
                ProductonScreen[numOnScreen] = cur;
                numOnScreen++;
            }
        }
        cout << "Type your selection and press ENTER: ";
        cin >> choice;
        cout << endl;
    }

    // Validate the user's choice, if "0" return without a Product
    if (choice == "0") {
        cout << "return to main" << endl;
    }

    // Get the integer equivalent of 'choice'
    for (unsigned int curLetter = 0; curLetter < choice.length(); curLetter++) {
        // If the user entered a letter, make them start again
        if (!isdigit(choice[curLetter])) {       
            cout << "ERROR: Invalid data range.\n\n";
            return getNext();
        }
    }

    int selection = stoi(choice); // Convert choice to integer
    // Ensure the user picked a valid number, and return the corresponding Product
    if (0 < selection && selection <= numOnScreen) {     
        return ProductonScreen[selection - 1];
    } 
    else {
        // If not a valid number, make the user start again
        ERROR_invalidDataRange();
        return getNext();
    }
}
