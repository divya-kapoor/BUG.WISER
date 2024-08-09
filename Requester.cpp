// Requester.cpp
/*------------------------------------------------------------
Revision History:
Rev. 3 - 2024/07/29 matched couts to user manual, added error handling for
                    all input functions by JK
Rev. 2 - 2024/07/15 edited prompts, changed parameters, functions types, removed some
         functions by JK
Rev. 1 - 2024/07/14 Original by Divya Kapoor
--------------------------------------------------------------
This module implements the Requester class which handles the details
related to individuals who make requests in the BugWiser Tracking
System. This includes attributes for personal and contact information
and methods for managing these requester details.
-------------------------------------------------------------*/
// Requester.cpp
#include "Requester.h"
#include "errors.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <cstring> // for strlen
#include <limits> // for numeric_limits

using namespace std;

Requester requestersOnScreen[20];
std::fstream requesterFile;
// Constructor
Requester::Requester() : name(""), phone(""), email(""), dept("") {}
/*=============================================================*/  
// Initialize a new Requester
bool Requester::initReq() {
openRequesterFile("Requester.dat"); 
    if (requesterFile.is_open()) {
    } else {
        cout << "Failed to open the file: Requester.dat\n";
    }
    return requesterFile.is_open();
}
/*=============================================================*/  
// Input phone number
void Requester::inputPhone() {
    int phoneLen; // keep track of the length of input

    bool validPhoneInput = false;   // keep track of error handling for input
    // loop input for phone number so long as the input is not valid.
    do {    
        cout << "Please enter phone number:\n"
             << "(10-11 digits, no dashes E.g. 11234567890)\n"; 
        cin >> phone;
        phoneLen = strlen(phone);
        // check if input is within data range first
        if (phoneLen < 10 || phoneLen > 11) {
            ERROR_invalidDataRange();
        }
        // if it is, check if each character is a digit.
        else{
            validPhoneInput = true;
            
            for (int i = 0; i < phoneLen; i++) {
                if (!isdigit(phone[i])) {
                    ERROR_invalidDataFormat();
                    validPhoneInput = false;
                    break;
                }
            }
        }
    } while (!validPhoneInput);
}
/*=============================================================*/  
// Input name
void Requester::inputName() {
    // v  DO NOT CHANGE THIS COUT PLEASE: IT MATCHES THE USER MANUAL v
    cout << "\nPlease enter full name:\n(1-30 characters, E.g. Jane Doe)\n";
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    char userInputName[32]; // temp char name to test data range
    
    do {
        cin.getline(userInputName, sizeof(userInputName));
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        if (strlen(userInputName) < 1 || strlen(userInputName) > 30) {
            ERROR_invalidDataRange();
            cout << "Please enter full name:\n(1-30 characters, E.g. Jane Doe)\n";
            // Use getline to read the full line for name
        }
    } while (strlen(userInputName) < 1 || strlen(userInputName) > 30);

    strcpy(name, userInputName);    // copy to Requester name if valid.
}
/*=============================================================*/  
// Input email
string Requester::inputEmail() {
    // v  DO NOT CHANGE THIS COUT PLEASE: IT MATCHES THE USER MANUAL v
    string tempEmail;
    cout << "\nPlease enter email:\n(1-24 characters, E.g. janedoe@gmail.com)\n";
    cin >> tempEmail;

    while (tempEmail.length() < 1 || tempEmail.length() > 24) {
        ERROR_invalidDataRange();
        cout << "Please enter email:\n(1-24 characters, E.g. janedoe@gmail.com)\n";
        cin >> email;
    }
    strncpy(email, tempEmail.c_str(), sizeof(email));    // copy to Requester name if valid.
    return email;
}
/*=============================================================*/  
// Input department
void Requester::inputDept() {
    // v  DO NOT CHANGE THIS COUT PLEASE: IT MATCHES THE USER MANUAL v
    cout << "\nIf applicable, please enter department:\n"
         << "(0-12 characters, E.g. Marketing)\n";
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    char userInputDept[14]; // temp char name to test data range
    
    do {
        cin.getline(userInputDept, sizeof(userInputDept));
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        if (strlen(userInputDept) > 12) {
            ERROR_invalidDataRange();
    cout << "\nIf applicable, please enter department:\n"
         << "(0-12 characters, E.g. Marketing)\n";
            // Use getline to read the full line for  department
        }
    } while (strlen(userInputDept) > 12);

    strcpy(dept, userInputDept);    // copy to Requester department if valid.
}
/*=============================================================*/  
// Add a new requester
bool Requester::addRequester() {
    inputPhone();
    inputName();
    string newEmail = inputEmail();
    inputDept();
    Requester cur;
    requesterFile.seekg(0, ios::beg);
    while (requesterFile.read(reinterpret_cast<char*>(&cur), sizeof(Requester))){
        if (strcmp(cur.email, newEmail.c_str()) == 0){
            string pick;
            cout << "ERROR: Already Exists." << endl;
            cout << "1) Re-enter" << endl;
            cout << "2) Return to the previous menu." << endl;
            cout << "Type your selection and press ENTER: ";
            cin >> pick;
            if (pick == "1"){
                return addRequester();
            }
            else {
                return false;
            }

        }          
    }
    
    // v  DO NOT CHANGE THIS COUT PLEASE: IT MATCHES THE USER MANUAL v
    cout << "\n------Create New: Requester------" << endl;
    std::cout << "Is the following information correct: \n";
    std::cout << "Phone Number: " << phone << std::endl;
    std::cout << "Name: " << name << std::endl;
    std::cout << "Email: " << email << std::endl;
    std::cout << "Department: " << dept << "\n" << std:: endl; 

    
    int confirmation;

    // do while loop to continuously ask for user input.
    do {
        // v  DO NOT CHANGE THIS COUT PLEASE: IT MATCHES THE USER MANUAL v
        cout << "1) Confirm\n0) Cancel \nType your selection and press ENTER: ";

        std::cin >> confirmation;

        if (confirmation == 1) {
            // writeRequester(*this);
            writeRequester();
            std::cout << "\nRequester has been added, returning to the previous menu.\n";
            return true;
        } 
        else if (confirmation == 0){
            std::cout << "\nOperation cancelled, returning to the previous menu.\n";
            return false;
        }
        else {
            ERROR_invalidSelection();
            return false;
        }
    } while (confirmation != 1 && confirmation != 0);
    return false;
}
/*=============================================================*/  
// Select requester from the list and return the selected Requester object
Requester Requester::selectRequester() {
    requesterFile.seekg(0, ios::beg); // Set the file pointer to the beginning of file
    return getNext(); // Return what the getNext() function returns
}
/*=============================================================*/  
// Close requester file ( clean up ?)
void Requester::closeRequesterFile() {
    if (requesterFile.is_open()) {
        requesterFile.close(); 
    }
}
/*=============================================================*/  
// Open requester file
bool Requester::openRequesterFile(const std::string &filename) {
    requesterFile.open(filename, ios::in | ios::out | ios::binary | ios::app);
    return requesterFile.is_open();
}
/*=============================================================*/  
// Write requester details to file
bool Requester::writeRequester() {
   if (requesterFile.is_open()) {
         
    requesterFile.clear();
    requesterFile.write(reinterpret_cast<const char*>(this),sizeof(Requester));
    
    requesterFile.flush();
        return true;
    }
    return false;
}
/*=============================================================*/  
// Get the next requester from the file
Requester Requester::getNext() {
    Requester cur;
    int setCounter = 0; // Tracks which 'page' you are on
     // How many valid numerical options are on the screen at the moment
    int numOnScreen = 0;
     /* Initial selection for choice to avoid incrememnting or
        ...decrementing setCounter upon opening */
    string choice = "S";
    
    // While loop to keep running until a valid choice is made other than N or P
    while ((choice == "P")| (choice == "N")| (choice == "S")){ 

        if (requesterFile.is_open()) {
            // If user wants to see the previous page, make sure this is not the first page
            if (choice == "P"){ 
                if (setCounter == 0) {
                    cout << "Already on the first menu.\n" << endl;
                }
                else {  
                    setCounter--;
                }
            }
            else if (choice == "N"){ // Display the next page if desired
                setCounter++;
            }
            requesterFile.clear();  // Clear any EOF flag
            cout << "== P for the previous 20 items ==\n"
                 << "== N for the next 20 items ==\n";
            
             // Prompt the user to select a Requester
            cout << "\nPlease Select a Requester:" << endl;
            // Ensure we start reading from the correct 'page'
            requesterFile.seekg((setCounter * 20) * sizeof(Requester)); 
            numOnScreen = 0; // Reset the counter of how many are on the screen

            while (numOnScreen < 20){ // Read the structure until the end of the 'page'
                // requesterFile.read((char*)&cur.name, sizeof(cur.name)); // Save name
                // requesterFile.read((char*)&cur.phone, sizeof(cur.phone)); // Save phone
                // requesterFile.read((char*)&cur.email, sizeof(cur.email)); // save email
                // requesterFile.read((char*)&cur.dept, sizeof(cur.dept));// Save department
                // Read the structure until the end of the 'page'
                requesterFile.read(reinterpret_cast<char*>(&cur),
                                        sizeof(Requester));
                if (requesterFile.eof()) { // Check if we read past the EOF
                    requesterFile.clear();  // Clear the EOF flag
                    break;
                }  

                 // Print release ID read to screen if it belongs to the correct product
                cout << (numOnScreen + 1) << ") " << cur.email << "\n";
                // Add the release ID to the temporary array in position numOnScreen
                requestersOnScreen[numOnScreen] = cur; 
                numOnScreen++; // Incrememnt how many valid numerical options there are
                
            }   
        }
        // Prompt the user to make a selection
        cout << "Type your selection and press ENTER: "; 
        cin >> choice;
        cout << endl;
        
        // handle invalid inputs.
        if (cin.fail() || (choice != "P" && choice != "N" && (choice.empty()
                       || !isdigit(choice[0]) || stoi(choice) < 1 
                       || stoi(choice) > numOnScreen))) {
            cin.clear(); // Clear error flags
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
            ERROR_invalidSelection();
            choice = "S"; // Reset choice to stay in the loop
        }
    }
    // // Validate the users choice, if "0" return without a ProductRelease
    // if (choice == "0"){ 
    //     Requester empty; 
    //     return empty;
    // }
    // Get the integer equivalent of 'choice'
    // for (unsigned int curLetter = 0; curLetter < choice.length(); curLetter++){ 
    //     // If the user entered a letter, make them start again
    //     if (!isdigit(choice[curLetter])){ 
    //         cout << "ERROR: Invalid data range.\n\n";
    //         return getNext(); // Call this function again
    //     }
    // }
    int selection = stoi(choice);
     // Ensure the user picked a valid number 
    if (0 < selection && selection <= numOnScreen){
        // Return the corresponding ProductRelease
        return requestersOnScreen[selection - 1]; 
    }
    // else {
    //     // If not a valid number, make the user start again
    //     ERROR_invalidDataRange();
    //     return getNext();
    // }    
    return Requester();
}

/*=============================================================*/  
