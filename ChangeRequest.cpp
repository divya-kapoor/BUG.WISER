// ChangeRequest.cpp
/*------------------------------------------------------------
Revision History:
Rev. 3 - 2024/07/30 Added error handling for input change request date by JK
Rev. 2 - 2024/07/18 Updated by Liza Awwad
Rev. 1 - 2024/06/30 Original by Liza Awwad
------------------------------------------------------------------
This module is used to manage change requests. It provides functionality
for initializing and processing change requests.
-----------------------------------------------------------------*/
#include "ChangeRequest.h"
#include "errors.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <stdexcept>
#include <cstring> // For strncpy

using namespace std;

// Declaration of the external file stream for change requests
// Array to store currently displayed change requests
ChangeRequest RequestsonScreen[20];
std::fstream changeRequestFile;

/*===========================================================*/  
// Function to initialize the change request system
bool ChangeRequest::initChangeRequest() {
    openRequestFile("ChangeRequest.dat"); // Open the change request file
    if (changeRequestFile.is_open()) {
    } else {
        std::cout << "Failed to open the file: ChangeRequest.dat\n";
    }
    return changeRequestFile.is_open(); // Return true if file is open, otherwise false
}
/*===========================================================*/  
// Default constructor that initializes the request date to empty
ChangeRequest::ChangeRequest() {
    memset(requestDate, 0, sizeof(requestDate)); // Clear the requestDate array
    memset(requesterInfo, 0, sizeof(requesterInfo)); // Clear the requesterInfo array
    memset(productReleaseInfo, 0, sizeof(productReleaseInfo)); // ^ productReleaseInfo ^
    memset(changeId, 0, sizeof(changeId)); // Clear the changeItems array
}
/*===========================================================*/  
/* Copy constructor that initializes a new ChangeRequest object as a
   copy of an existing ChangeRequest object */
ChangeRequest::ChangeRequest(const ChangeRequest& other) {
    // Copy each member from the other ChangeRequest object
    std::strncpy(requestDate, other.requestDate, sizeof(requestDate) - 1);
    requestDate[sizeof(requestDate) - 1] = '\0'; 
    std::strncpy(requesterInfo, other.requesterInfo, sizeof(requesterInfo) - 1);
    requesterInfo[sizeof(requesterInfo) - 1] = '\0';
    std::strncpy(productReleaseInfo, other.productReleaseInfo,
                                     sizeof(productReleaseInfo) - 1);
    productReleaseInfo[sizeof(productReleaseInfo) - 1] = '\0';
    std::strncpy(changeId, other.changeId, sizeof(changeId) - 1);
    changeId[sizeof(changeId) - 1] = '\0';
}
/*===========================================================*/  
// Assignment operator to copy the contents of another ChangeRequest object to this one
ChangeRequest& ChangeRequest::operator=(const ChangeRequest& other) {
    if (this != &other) {
        // Copy each member from the other ChangeRequest object
        std::strncpy(requestDate, other.requestDate, sizeof(requestDate) - 1);
        requestDate[sizeof(requestDate) - 1] = '\0'; 
        std::strncpy(requesterInfo, other.requesterInfo, sizeof(requesterInfo) - 1);
        requesterInfo[sizeof(requesterInfo) - 1] = '\0';
        std::strncpy(productReleaseInfo, other.productReleaseInfo,
                                         sizeof(productReleaseInfo) - 1);
        productReleaseInfo[sizeof(productReleaseInfo) - 1] = '\0';
        std::strncpy(changeId, other.changeId, sizeof(changeId) - 1);
        changeId[sizeof(changeId) - 1] = '\0';
    }
    return *this;
}
/*===========================================================*/  
// Function to input a new change request from the user
void ChangeRequest::inputChangeRequest() {
    // std::cout << "Please enter the Request Date:\n"; // Prompt user for the request date
    //      cout << "(yyyy-mm-dd, E.g. 2000-11-22)\n"; 
    // std::cin >> dateStr;

    // // Copy the input date to the requestDate member
    // std::strncpy(requestDate, dateStr.c_str(), sizeof(requestDate) - 1);
    // requestDate[sizeof(requestDate) - 1] = '\0'; 

    // return dateStr;  


    int requestDateLen; // keep track of the length of input

    bool validReqDateInput = false;   // keep track of error handling for input
    // loop input for phone number so long as the input is not valid.
    do {    
        cout << "Please enter the Request Date:\n"; // Prompt user for the request date
        cout << "(yyyy-mm-dd, E.g. 2000-11-22)\n"; 
        cin >> requestDate;
        requestDateLen = strlen(requestDate);
        // check if input is within data range first
        if (requestDateLen != 10) {
            ERROR_invalidDataRange();
            validReqDateInput = false;
        }
        // if it is, check if date follows correct format.
        else{
            validReqDateInput = true;
        }
            
        for (int i = 0; i < 4; i++) {
            if (!isdigit(requestDate[i])) {
                validReqDateInput = false;
                break;
            }
        }
        if (requestDate[4] != '-'){
            validReqDateInput = false;
        }
        if (validReqDateInput) {
            for (int i = 5; i < 7; i++) {
                if (!isdigit(requestDate[i])) {
                    validReqDateInput = false;
                    break;
                }
            }
        }
        if (requestDate[7] != '-'){
            validReqDateInput = false;
        }
        if (validReqDateInput) {
            for (int i = 8; i < 10; i++) {
                if (!isdigit(requestDate[i])) {
                    validReqDateInput = false;
                    break;
                }
            }
        }
        // output error if any invalid data formats were inputted.
        if (!validReqDateInput) {
            ERROR_invalidDataFormat();
        }
    } while (!validReqDateInput);
}
/*===========================================================*/  
// Function to select an existing change request from a list
ChangeRequest ChangeRequest::selectChangeRequest(const std::vector<ChangeRequest> 
                                                       &changeRequests) {
    if (changeRequestFile.is_open()) {
        // Move the file pointer to the beginning of the file
        changeRequestFile.seekg(0, std::ios::beg); 
    }

    if (changeRequests.empty()) {
        std::cerr << "No change requests found." << std::endl;
        exit(1); // Exit if no change requests found
    }

    // Display each change request's date
    std::cout << "List of Change Requests:\n";
    for (size_t i = 0; i < changeRequests.size(); ++i) {
        std::cout << i + 1 << ". Request Date: " 
                  << changeRequests[i].requestDate << std::endl;
    }

    size_t selection;
    std::cout << "Type your selection and press ENTER: ";
    std::cin >> selection; // Get the user's selection

    if (selection > 0 && selection <= changeRequests.size()) {
        return changeRequests[selection - 1]; // Return the selected change request
    } 
    else {
        std::cerr << "Invalid selection. Returning the first request.\n";
        // Return the first change request if the selection is invalid
        return changeRequests[0]; 
    }
}
/*===========================================================*/  
// Function to add a new change request
void ChangeRequest::addChangeRequest(const std::string& requesterEmail,
                                     const char* productReleaseInfoInput,
                                     const char* changeItemsInput) {
    int choice; 
    inputChangeRequest();

    do {
        std::cout << "------Create New: Request------\n";
        std::cout << "Is the following information correct:\n";
        std::cout << "Requester: " << requesterEmail << "\n";
        std::cout << "Request Date: " << requestDate << "\n\n";
        std::cout << "1) Confirm\n0) Cancel\nType your selection and press ENTER: ";

        std::cin >> choice; // Get the user's choice

        if (cin.fail()) {
            cin.clear();
            cin.ignore();
            choice = -1;    // choice is invalid
        }
        if (choice == 1) {
            // Create a new ChangeRequest object and set its members
            ChangeRequest newRequest;
            std::strncpy(newRequest.requesterInfo, requesterEmail.c_str(),
                        sizeof(newRequest.requesterInfo) - 1);
            newRequest.requesterInfo[sizeof(newRequest.requesterInfo) - 1] = '\0';
            std::strncpy(newRequest.productReleaseInfo, productReleaseInfoInput,
                        sizeof(newRequest.productReleaseInfo) - 1);
            newRequest.productReleaseInfo[sizeof(newRequest.productReleaseInfo)-1]='\0';
            std::strncpy(newRequest.changeId, changeItemsInput,
                        sizeof(newRequest.changeId) - 1);
            newRequest.changeId[sizeof(newRequest.changeId) - 1] = '\0';

            writeRequest(newRequest); // Write the new request to file
            std::cout << "\nNew change request added, returning to the previous menu.\n";
        } 
        else if (choice == 0) {
            std::cout << "\nOperation cancelled, returning to the previous menu.\n";
        } 
        else {
            ERROR_invalidSelection();
        }
    } while (choice != 1 && choice != 0);
}
/*===========================================================*/  
// Function to open the change request file
void ChangeRequest::openRequestFile(const std::string &filename) {
    if (changeRequestFile.is_open()) {
        changeRequestFile.close(); // Close the file if it is already open
    }
    // Open the file in binary mode
    changeRequestFile.open(filename, ios::in | ios::out | ios::binary | ios::app); 
    if (!changeRequestFile) {
        std::cerr << "Error opening file: " << filename << std::endl;
    } 
    else {
    }
}
/*===========================================================*/  
// Function to write a change request to the file
void ChangeRequest::writeRequest(const ChangeRequest& requestObject) {
    if (changeRequestFile.is_open()) {
       // Write each member of the change request to the file
        changeRequestFile.write(reinterpret_cast<const char*>(this),sizeof(ChangeRequest));
    }
}
/*===========================================================*/  
// Function to retrieve the next change request based on user selection
ChangeRequest ChangeRequest::getNext(const ChangeRequest changeRequest) {
    ChangeRequest cur;
    int setCounter = 0;     // Tracks which 'page' you are on
    // How many valid numerical options are on the screen at the moment
    int numOnScreen = 0;    
    std::string choice = "S";

    // While loop to keep running until a valid choice is made other than N or P
    while ((choice == "P") | (choice == "N") | (choice == "S")) {
        if (changeRequestFile.is_open()) {
            // If user wants to see the previous page, make sure this isn't the first page
            if (choice == "P") {   
                if (setCounter == 0) {
                    std::cout << "Already on the first menu.\n";
                } 
                else {
                    setCounter--;
                }
            } 
            else if (choice == "N") {
                setCounter++;
            }

            changeRequestFile.clear();  // Clear any EOF flag
            std::cout << "Please Select a Change Request" << std::endl;
            // Ensure we start reading from the correct 'page'
            changeRequestFile.seekg((setCounter * 20) * sizeof(ChangeRequest)); 
            numOnScreen = 0;     // Reset the counter of how many are on the screen
            while (numOnScreen < 20) {
                // Read the structure until the end of the 'page'
                changeRequestFile.read(reinterpret_cast<char*>(&cur),
                                       sizeof(ChangeRequest));

                // Check if we read past the EOF
                if (changeRequestFile.eof()) {
                    changeRequestFile.clear();  // Clear the EOF flag
                    break;
                }

                // Print the request date read to screen if it belongs to correct product
                if (std::strcmp(cur.requestDate, changeRequest.requestDate) == 0) {
                    std::cout << (numOnScreen + 1) << ") " << cur.requestDate << "\n";
                    // Add the request to the temporary array in position numOnScreen
                    RequestsonScreen[numOnScreen] = cur;
                    numOnScreen++;
                }
            }
        }
        std::cout << "Type your selection and press ENTER: ";
        std::cin >> choice;
        std::cout << std::endl;
    }

    // Validate the user's choice, if "0" return without a ChangeRequest
    if (choice == "0") {
        std::cout << "return to main" << std::endl;
    }

    // Get the integer equivalent of 'choice'
    for (unsigned int curLetter = 0; curLetter < choice.length(); curLetter++) {
        // If the user entered a letter, make them start again
        if (!isdigit(choice[curLetter])) {  
            std::cout << "ERROR: Invalid data range.\n\n";
            return getNext(changeRequest);
        }
    }

    int selection = std::stoi(choice);
    // Ensure the user picked a valid number, and return the corresponding ChangeRequest
    if (0 < selection && selection <= numOnScreen) {     
        std::cout << RequestsonScreen[selection - 1].requestDate << std::endl;
        return RequestsonScreen[selection - 1];
    } 
    else {
        // If not a valid number, make the user start again
        ERROR_invalidDataRange(); 
        return getNext(changeRequest);
    }
}
/*===========================================================*/  
// Function to close the change request file
void ChangeRequest::closeRequestFile() {
    if (changeRequestFile.is_open()) {
        changeRequestFile.close();
        std::cout << "File closed.\n";
    }
}
/*===========================================================*/  
// Function to print a change request.
void printChangeRequest(const ChangeRequest& cr) {
    std::cout << "Requester: " << cr.requesterInfo << "\n";
    std::cout << "Request Date: " << cr.requestDate << "\n";
    std::cout << "Product Release Info: " << cr.productReleaseInfo << "\n";
    std::cout << "Change ID: " << cr.changeId << "\n";
}
/*===========================================================*/  