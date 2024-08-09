// ProductRelease.cpp
/*------------------------------------------------------------
Revision History:
Rev. 2 - 2024/07/30 fixed error handling by JK
Rev. 1 - 2024/07/13 Original by Shiny Kumarapeli
--------------------------------------------------------------
Declared productReleaseFile as an extern to allow ReportControl to
read its contents without needing to open the file again.
Using an array of ProductReleases to store the releases that where
just read to avoid needing to read the file twice.
Nested while loop in getNext() function to ensure the menu allows 
the user to view as many pages as required with mmaximum 20 items 
each time.
------------------------------------------------------------*/
#include "ProductRelease.h"
#include "errors.h"
#include <limits>
#include <iostream>
#include <ostream>
#include <fstream>
#include <cstring>

std::fstream productReleaseFile;
using namespace std;
/*===========================================================*/
// Array to hold the ProductRelease objects displayed on the screen at any given time
ProductRelease onScreen[20]; 
/*===========================================================*/
// Function called but ScenarioControl to initialize all things related to ProductRelease
bool ProductRelease::initProductRel() { 
    openReleaseFile("ProductRelease.dat"); // Call openReleaseFile() to handle the file
    if (productReleaseFile.is_open()) {
    } else {
        cout << "Failed to open the file: ProductRelease.dat\n";
    }
    return productReleaseFile.is_open();
}
/*===========================================================*/
void ProductRelease::inputReleaseID() {

//- - - INPUT PRODUCT RELEASE ID - - - 
    // cout << "Please enter product Release ID:\n(1-8 characters)\n";
    // cin.ignore();  // Ignore any leftover characters in the buffer
    //  // Use getline to read the full line for releaseID
    // cin.getline(releaseID, sizeof(releaseID)); 
    cout << "Please enter product Release ID:\n(1-8 characters)\n";
    cin >> releaseID;

    while (strlen(releaseID) < 1 || strlen(releaseID) > 8) {
        ERROR_invalidDataRange();
        cout << "Please enter product Release ID:\n(1-8 characters)\n";
        cin >> releaseID;               // if this allows space needs to be fixed.
    }
}
/*===========================================================*/
void ProductRelease::inputReleaseDate() {
//- - - INPUT PRODUCT RELEASE DATE - - - 
    // cout << "Please enter product Release Date:\n(yyyy-mm-dd, E.g. 2000-11-22)\n";
    // // Use getline to read the full line for releaseDate
    // cin.getline(releaseDate, sizeof(releaseDate));
    cin.ignore(numeric_limits<streamsize>::max(),'\n');

    int releaseDateLen; // keep track of the length of input

    bool validRelDateInput = false;   // keep track of error handling for input
    // loop input for phone number so long as the input is not valid.
    do {    
        // Prompt user for the release date
        cout << "\nPlease enter product Release Date:\n"; 
        cout << "(yyyy-mm-dd, E.g. 2000-11-22)\n"; 
        cin >> releaseDate;
        releaseDateLen = strlen(releaseDate);
        // check if input is within data range first
        if (releaseDateLen != 10) {
            ERROR_invalidDataRange();
        }
        // if it is, check if date follows correct format.
        validRelDateInput = true;
            
        for (int i = 0; i < 4; i++) {
            if (!isdigit(releaseDate[i])) {
                validRelDateInput = false;
                break;
            }
        }
        if (releaseDate[4] != '-'){
            validRelDateInput = false;
        }
        if (validRelDateInput) {
            for (int i = 5; i < 7; i++) {
                if (!isdigit(releaseDate[i])) {
                    validRelDateInput = false;
                    break;
                }
            }
        }
        if (releaseDate[7] != '-'){
            validRelDateInput = false;
        }
        if (validRelDateInput) {
            for (int i = 8; i < 10; i++) {
                if (!isdigit(releaseDate[i])) {
                    validRelDateInput = false;
                    break;
                }
            }
        }
        // output error if any invalid data formats were inputted.
        if (!validRelDateInput) {
            ERROR_invalidDataFormat();
        }
    } while (!validRelDateInput);
}
/*===========================================================*/
void ProductRelease::addProductRelease(Product product) {
    inputReleaseID();
    inputReleaseDate();
    int choice; // Variable to track what the user selects

    do {
        // Confirmation question, display what the user has input thus far
        cout << "\nIs the following information correct:\n";
   //     cout << "is it here" << endl;                SHINY IDK IF YOU STILL NEED THIS
        cout << "Product Name: " << product.name << endl;
        cout << "Release ID: " << releaseID << endl;
        cout << "Release Date: " << releaseDate << endl;
        cout << "\n1) Confirm\n0) Cancel \nType your selection and press ENTER: ";

        cin >> choice; // Read the user's choice

        if (cin.fail()) {
            cin.clear();
            cin.ignore();
            choice = -1;    // choice is invalid
        }
        if (choice == 1) {
            // Set the mainProduct to be the product what was chosen before
            mainProduct = product; 
            writeRelease(); // Call writeRelease() to add the new entry to the file
            cout << "Product Release created, returning to the previous menu.\n";
        } 
        else if (choice == 0) {
            cout << "Operation cancelled, returning to the previous menu.\n";
        } 
        else { // If the user does not select either '1' or '0' print an error message
            ERROR_invalidSelection();
        }
    } while (choice != 1 && choice != 0);
}
/*===========================================================*/
ProductRelease ProductRelease::selectProductRel(const Product product) {
    // Set the file pointer to the beginning of the file
    productReleaseFile.seekg(0, ios::beg); 
    return getNext(product); // Return what the getNext() function returns
}
/*===========================================================*/
void ProductRelease::openReleaseFile(const string &filename) {
    // Open the desired file, if it does not yet exist, create on with that name
    productReleaseFile.open(filename, ios::in | ios::out | ios::binary | ios::app); 
}
/*===========================================================*/
void ProductRelease::writeRelease() {
    if (productReleaseFile.is_open()) {
        productReleaseFile.clear();
        //productReleaseFile.seekp(0, std::ios::end);
    //}
    productReleaseFile.write(reinterpret_cast<const char*>(this),sizeof(ProductRelease));
    if (productReleaseFile.fail()) {
        std::cerr << "Error writing ChangeItem to file." << std::endl;
        //return false;
    }

    productReleaseFile.flush();
    //return true;
    } 
}
/*===========================================================*/
ProductRelease ProductRelease::getNext(const Product product) {
    ProductRelease cur;
    int setCounter = 0; // Tracks which 'page' you are on
    // How many valid numerical options are on the screen at the moment
    int numOnScreen = 0; 
    /* Initial selection for choice to avoid incrememnting or...
     ...decrementing setCounter upon opening */
    string choice = "S"; 
    
    // While loop to keep running until a valid choice is made other than N or P
    while ((choice == "P")| (choice == "N")| (choice == "S")){ 

        if (productReleaseFile.is_open()) {
            /* If user wants to see the previous page,
            ...make sure this is not the first page */
            if (choice == "P"){ 
                if (setCounter == 0) {
                }
                else {  
                    setCounter--;
                }
            }
            else if (choice == "N"){ // Display the next page if desired
                setCounter++;
            }
            productReleaseFile.clear();  // Clear any EOF flag
            cout << "== P for the previous 20 items ==\n"
                 << "== N for the next 20 items ==\n";

            // Prompt the user to select a release ID
            cout << "\nPlease Select a Release ID" << endl;
            // Ensure we start reading from the correct 'page'
            productReleaseFile.seekg((setCounter * 20) * sizeof(ProductRelease)); 
            numOnScreen = 0; // Reset the counter of how many are on the screen

            while (numOnScreen < 20){ // Read the structure until the end of the 'page'
                productReleaseFile.read(reinterpret_cast<char*>(&cur),
                                        sizeof(ProductRelease));

                if (productReleaseFile.eof()) { // Check if we read past the EOF
                    productReleaseFile.clear();  // Clear the EOF flag
                    break;
                }  
                // Print release ID read to screen if it belongs to the correct product
                if (strcmp(cur.mainProduct.name, product.name) == 0){ 
                    cout << (numOnScreen + 1) << ") " << cur.releaseID << "\n";
                    // Add the release ID to the temporary array in position numOnScreen
                    onScreen[numOnScreen] = cur; 
                    // Incrememnt how many valid numerical options there are
                    numOnScreen++;
                }
            }   
        }
         // Prompt the user to make a selection
        cout << "Type your selection and press ENTER: ";
        cin >> choice;
        cout << endl;
    }
    // Validate the users choice, if "0" return without a ProductRelease
    if (choice == "0"){ 
        ProductRelease empty; 
        return empty;
    }
     // Get the integer equivalent of 'choice'
    for (unsigned int curLetter = 0; curLetter < choice.length(); curLetter++){
        // If the user entered a letter, make them start again
        if (!isdigit(choice[curLetter])){ 
            cout << "ERROR: Invalid data range.\n\n";
            return getNext(product); // Call this function again
        }
    }
    int selection = stoi(choice);
    // Ensure the user picked a valid number 
    if (0 < selection && selection <= numOnScreen){
        return onScreen[selection - 1]; // Return the corresponding ProductRelease
    }
    else {
        // If not a valid number, make the user start again
        ERROR_invalidDataRange();
        return getNext(product);
    }    
}
/*===========================================================*/
void ProductRelease::closeReleaseFile() {
    if (productReleaseFile.is_open()) {
        productReleaseFile.close(); // Close the ProductRelease.dat file
    }
}
/*===========================================================*/
ProductRelease ProductRelease::operator=(const ProductRelease& other) {
    if (this != &other) {
        strcpy(releaseID, other.releaseID); // Set the release ID to match
        strcpy(releaseDate, other.releaseDate); // Set the release date to match
        mainProduct = other.mainProduct; // Set the main product to match
    }
    return *this;
}
/*===========================================================*/
