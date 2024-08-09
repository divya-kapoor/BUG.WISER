// ChangeItem.cpp
/*------------------------------------------------------------
Revision History:
Rev. 6 - 2024/07/23 Implemented assess()
                    Included errors.h
Rev. 5 - 2024/07/21 Added in modSelectChangeItem(bool, bool, bool, bool, bool)
                    Added in modPriority()
                    Added in assess() 
                    Added in querySelectChangeItem(Product) 
                    Added in viewChangeItem() by Shiny Kumarapeli
Rev. 4 - 2024/07/21 Reworked all functions by Divya, Shiny
Rev. 3 - 2024/07/17 Fixed functions and formatting
Rev. 2 - 2024/07/15 added a constructor by JK
Rev. 1 - 2024/07/14 Original by Divya Kapoor
------------------------------------------------------------------
This module implements the ChangeItem class which includes attributes
like priority, description, status, and anticipated release ID and
methods for initializing, modifying, assessing, and managing these change items.
------------------------------------------------------------------ */
// ChangeItem.cpp
#include "ChangeItem.h"
#include "errors.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <limits>
#include <cstring>
#include "UserInterface.h"

using namespace std;
fstream changeItemFile;
int nextChangeID = 1;
ChangeItem ItemOnScreen[20];

/*===========================================================*/  
ChangeItem::ChangeItem() :  product(),
                            description(""),
                            changeID(),
                            priority(),
                            status("FRESH"),
                            anticipatedReleaseID("") {
}
/*===========================================================*/  
bool ChangeItem::initChangeItem() {
    openChangeItemFile("ChangeItem.dat");
    if (changeItemFile.is_open()) {
    } else {
        cout << "Failed to open the file: ChangeItem.dat\n";
    }
    return changeItemFile.is_open();
}
/*===========================================================*/  
void ChangeItem::addChangeItem(Product inputProduct) {
    inputDescription();
    inputPriority();
    sprintf(changeID, "%d", nextChangeID);
    nextChangeID++;
    int choice;
    std::cout << "\nIs the following information correct:\n";
    std::cout << "Product: " << inputProduct.name << "\n";
    std::cout << "Description: " << description << "\n\n";
    std::cout << "1) Confirm\n0) Cancel\nType your selection and press ENTER: ";
    std::cin >> choice;

    if (choice == 1) {
        strncpy(product, inputProduct.name, sizeof(product) - 1);
        product[sizeof(product) - 1] = '\0';
        writeChangeItem();
        cout << "Change Item created, continuing create a new request operation.\n";
    } else if (choice == 0) {
        //std::cout << "Operation cancelled, returning to Main Menu.\n";
        throw ERROR_message("Operation cancelled."); 
    } else {
        ERROR_invalidSelection();
    }
}
/*===========================================================*/  
string ChangeItem::inputDescription() {
// asks user to input a description then sets the description value to input.

    cout << "Please enter a brief description:\n(1-30 characters)" << endl;
    string userInputDescription; // temp char name to test data range
    do {
        getline(cin, userInputDescription);
        //cin.ignore(numeric_limits<streamsize>::max(), '\n');
        //cin.getline(userInputDescription, sizeof(userInputDescription));
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        if (userInputDescription.length() < 1 || userInputDescription.length() > 30) {
            ERROR_invalidDataRange();
            cout << "Please enter a brief description:\n(1-30 characters)" << endl;
            // Use getline to read the full line for description
        }
    } while (userInputDescription.length() < 1 || userInputDescription.length() > 30);

    strcpy(description, userInputDescription.c_str());// copy to Requester name if valid.
    return userInputDescription;
}
/*===========================================================*/  
string ChangeItem::inputPriority() {
    // std::string choice;
    // std::cout << "\nPlease select a Priority (1-5, 5 being the highest):\n";
    // std::cout << "1) 1\n";
    // std::cout << "2) 2\n";
    // std::cout << "3) 3\n";
    // std::cout << "4) 4\n";
    // std::cout << "5) 5\n";
    
    // std::cout << "Type your selection and press ENTER: ";
    // std::cin >> choice;
    // if (choice.length() == 1 && isdigit(choice[0])) {
    //     strncpy(priority, choice.c_str(), sizeof(priority) - 1);
    //     priority[sizeof(priority) - 1] = '\0';

    // } else {
    //     std::cout << "ERROR: Invalid data range.\n";
    // }
    // return choice;
    string choice;
    
    bool priorityValid = false;
    while (!priorityValid) {
        cout << "\nPlease select a Priority (1-5, 5 being the highest):\n";
        cout << "1) 1\n";
        cout << "2) 2\n";
        cout << "3) 3\n";
        cout << "4) 4\n";
        cout << "5) 5\n";

        cout << "Type your selection and press ENTER: ";
        cin >> choice;

        if (choice.length() == 1 && isdigit(choice[0])) {
            int num = choice[0] - '0';
            if (num >= 1 && num <= 5) {
                strncpy(priority, choice.c_str(), sizeof(priority) - 1);
                priority[sizeof(priority) - 1] = '\0';
                priorityValid = true;
                return choice;
            }
            else {
                priorityValid = false;
                ERROR_invalidDataRange();
            }
        }
        else {
            priorityValid = false;
            ERROR_invalidDataFormat();
        }
    } 
    return choice;
}
/*===========================================================*/  
void ChangeItem::modStatus(const char* changeID) {
    int distInFile = 0;
    ChangeItem cur;
    changeItemFile.seekg(0, ios::beg);
    while (!changeItemFile.eof()){
        changeItemFile.read(reinterpret_cast<char*>(&cur), sizeof(ChangeItem));   
        if (strcmp(cur.changeID, changeID) == 0){
            break;
        }          
        distInFile++;
    }
    int choice = 0;
    std::cout << "\n------Modify Existing: Change Item------\n";
    std::cout << "Please select a new Status:\n";
    std::cout << "1) In-Progress\n";
    std::cout << "2) Cancelled\n";
    std::cout << "3) Done\n";
    while (choice < 1 || choice > 3) {
        std::cout << "Type your selection and press ENTER: ";
        std::cin >> choice;
        if (choice < 1 || choice > 3) {
            std::cout << "ERROR: Invalid choice. Please select a valid status (1-3).\n";
        }
    }
    changeItemFile.seekg(0, ios::beg);
    switch (choice) {
    case 1:
        strncpy(cur.status, "IN-PROGRESS", sizeof(status));
        changeItemFile.seekg(distInFile * sizeof(ChangeItem));  
        changeItemFile.write(reinterpret_cast<const char*>(&cur), sizeof(ChangeItem));
        cout << "Status updated, returning to the previous menu.\n\n";
        break;
    case 2:
        strncpy(cur.status, "CANCELLED", sizeof(status));
        changeItemFile.seekg(distInFile * sizeof(ChangeItem));  
        changeItemFile.write(reinterpret_cast<const char*>(&cur), sizeof(ChangeItem));
        cout << "Status updated, returning to the previous menu.\n\n";
        break;
    case 3:
        strncpy(cur.status, "DONE", sizeof(status));
        changeItemFile.seekg(distInFile * sizeof(ChangeItem));  
        changeItemFile.write(reinterpret_cast<const char*>(&cur), sizeof(ChangeItem));
        cout << "Status updated, returning to the previous menu.\n\n";
        break;
    default: 
        break;
    }
}
/*===========================================================*/  
void ChangeItem::modDescription(const char* changeID) {
    int distInFile = 0;
    ChangeItem cur;
    changeItemFile.seekg(0, ios::beg);
    while (!changeItemFile.eof()){
        changeItemFile.read(reinterpret_cast<char*>(&cur), sizeof(ChangeItem));   
        if (strcmp(cur.changeID, changeID) == 0){
            break;
        }          
        distInFile++;
    }

    cout << "\n";
    cin.ignore();
    string newDescription = inputDescription();
    
    std::cout << "\nIs the following information correct:\n";
    cout << "New Description: " << description << endl;
  //  std::cout << newDescription;
    std::cout << "\n1) Confirm\n";
    std::cout << "0) Cancel\n";
    std::cout << "Type your selection and press ENTER: ";

    int choice;
    std::cin >> choice;

    if (choice == 1) {
        strncpy(cur.description, newDescription.c_str(), sizeof(cur.description) - 1);
        cur.description[sizeof(cur.description) - 1] = '\0';  // Ensure null-termination
        changeItemFile.seekg(distInFile * sizeof(ChangeItem));  
        changeItemFile.write(reinterpret_cast<const char*>(&cur), sizeof(ChangeItem));
        cout << "\nDescription updated, returning to the previous menu.\n\n";
    } else {
        std::cout << "\nOperation cancelled, returning the previous menu.\n\n";
    }
}
/*===========================================================*/  
// Modify anticipated release ID
void ChangeItem::modAnticipatedRel(const char* changeID) {
    int distInFile = 0;
    ChangeItem cur;
    changeItemFile.seekg(0, ios::beg);
    while (!changeItemFile.eof()){
        changeItemFile.read(reinterpret_cast<char*>(&cur), sizeof(ChangeItem));   
        if (strcmp(cur.changeID, changeID) == 0){
            break;
        }          
        distInFile++;
    }
    cout << "\n------Modify Existing: Change Item------\n";
    // std::cout << "Please enter Anticipated Release ID:\n";
    // std::cout << "(1-13 characters)\n";
    // std::cin.ignore();
    // std::cin.getline(cur.anticipatedReleaseID, sizeof(anticipatedReleaseID));
    ProductRelease modRelease;
    modRelease = modRelease.selectProductRel(cur.product);
    
    strncpy(cur.anticipatedReleaseID, modRelease.releaseID, sizeof(cur.anticipatedReleaseID) - 1);

    std::cout << "Is the following information correct:\n";
    std::cout << "Anticipated Release ID: " << cur.anticipatedReleaseID << "\n\n";
    std::cout << "1) Confirm\n";
    std::cout << "0) Cancel\n";
    std::cout << "Type your selection and press ENTER: ";

    int choice;
    std::cin >> choice;

    if (choice == 1) {
        changeItemFile.seekg(distInFile * sizeof(ChangeItem));  
        changeItemFile.write(reinterpret_cast<const char*>(&cur), sizeof(ChangeItem));
        cout << "\nAnticipated Release ID updated, returning to the previous menu.\n\n";
    } else {
        std::cout << "\nOperation cancelled, returning to the previous menu.\n\n";
    }
}
/*===========================================================*/  
void ChangeItem::modPriority(const char* changeID) {
    int distInFile = 0;
    ChangeItem cur;
    changeItemFile.seekg(0, ios::beg);
    while (!changeItemFile.eof()){
        changeItemFile.read(reinterpret_cast<char*>(&cur), sizeof(ChangeItem));   
        if (strcmp(cur.changeID, changeID) == 0){
            break;
        }          
        distInFile++;
    }
    cout << "\n------Modify Existing: Change Item------";
    string pri = inputPriority();
    strncpy(cur.priority, pri.c_str(), sizeof(priority));
    changeItemFile.seekg(distInFile * sizeof(ChangeItem));  
    changeItemFile.write(reinterpret_cast<const char*>(&cur), sizeof(ChangeItem));

    std::cout << "Priority updated, returning to the previous menu.\n\n";
}
/*===========================================================*/  
void ChangeItem::assess() {
    ChangeItem assessedChangeItem;

    cout << "------Assess Change Item------" << endl;
    assessedChangeItem = modSelectChangeItem(true, false, false, false, false);
    int distInFile = 0;
    ChangeItem cur;
    changeItemFile.seekg(0, ios::beg);
    while (!changeItemFile.eof()){
        changeItemFile.read(reinterpret_cast<char*>(&cur), sizeof(ChangeItem));   
        if (strcmp(cur.changeID, assessedChangeItem.changeID) == 0){
            break;
        }          
        distInFile++;
    }

    cout << "------Assess Change Item------" << endl;
    cout << "Product: " << assessedChangeItem.product << "\n"
         << "Description: " << assessedChangeItem.description << "\n"
         << "Change ID: " << assessedChangeItem.changeID << "\n"
         << "Priority: " << assessedChangeItem.priority << "\n"
         << "Status: " << assessedChangeItem.status << "\n"
         << "Anticipated Fix Release ID: " << assessedChangeItem.anticipatedReleaseID
         << "\n-----------------------------" << endl;

    cout << "Please select an option:\n"
         << "1) Assess\n"
         << "2) Cancel\n"
         << "B) Previous Menu\n"
         << "Type your selection and press ENTER: ";

    char assessedSelection;

    ProductRelease anticipatedFixID;
    Product fixIdProduct(assessedChangeItem.product);

    do {
        cin >> assessedSelection;
        switch(assessedSelection) {
            case '1':
                cout << "---------------Assess Change Item---------------" << endl;
                strncpy(assessedChangeItem.status, "ASSESSED", sizeof(status));

                strncpy(assessedChangeItem.anticipatedReleaseID,
                        anticipatedFixID.selectProductRel(fixIdProduct).releaseID,
                        sizeof(anticipatedFixID.releaseID));
                
                changeItemFile.seekg(distInFile * sizeof(ChangeItem));  
                changeItemFile.write(reinterpret_cast<const char*>(&assessedChangeItem),
                                     sizeof(ChangeItem));
                cout << "Anticipated Release ID updated." << endl;

                //assessedChangeItem.status = "ASSESSED";
                break;
            case '2':
                strncpy(assessedChangeItem.status, "CANCELLED", sizeof(status));
                changeItemFile.seekg(distInFile * sizeof(ChangeItem));  
                changeItemFile.write(reinterpret_cast<const char*>(&assessedChangeItem),
                                     sizeof(ChangeItem));

                cout << "Assess Change Item cancelled." << endl;
                //assessedChangeItem.status = "CANCELLED";
                break;           
            case 'B':
                break;
            default:
                ERROR_invalidSelection();
                cin.clear();
                cin.ignore(100, '\n');
                break;
        }
        break;
    } while(assessedSelection != 'B'); 
}
/*===========================================================*/  
void ChangeItem::closeChangeItemFile() {
    if (changeItemFile.is_open()) {
        changeItemFile.close();
    }
}
/*===========================================================*/  
ChangeItem ChangeItem::selectChangeItem(const Product product) {
    changeItemFile.seekg(0, ios::beg);
    return getNext(product);
}
/*===========================================================*/  
ChangeItem ChangeItem::modSelectChangeItem(bool fresh, bool assessed, bool in_progress,
                                           bool cancelled, bool done){

    ChangeItem cur;
    int setCounter = 0;
    int numOnScreen = 0;
    string choice = "S";
    cout << "== N for the next 20 items ==\n"
        << "== P for the previous 20 items ==\n";

    cout << "\nPlease select a Change Item\n";

    while (choice == "P" || choice == "N" || choice == "S") {
        if (changeItemFile.is_open()) {
            if (choice == "P" && setCounter > 0) {
                setCounter--;
            } else if (choice == "N") {
                setCounter++;
            }
            else if(choice=="B"){
                break;
            }
            // else if(choice=="0"){
            //     activateUI();
            // }
            changeItemFile.clear();
            changeItemFile.seekg((setCounter * 20) * sizeof(ChangeItem));
            numOnScreen = 0;

            while (numOnScreen < 20) {
                changeItemFile.read((char*)&cur, sizeof(ChangeItem));

                if (changeItemFile.eof()) {
                    changeItemFile.clear();
                    break;
                }
                if ((fresh && strcmp(cur.status,"FRESH") == 0) ||
                    (assessed && strcmp(cur.status,"ASSESSED") == 0) ||
                    (in_progress && strcmp(cur.status,"IN-PROGRESS") == 0) ||
                    (cancelled && strcmp(cur.status,"CANCELLED") == 0) ||
                    (done && strcmp(cur.status,"DONE") == 0)) {

                    std::cout << (numOnScreen + 1) << ") " << cur.description << "\n";
                    ItemOnScreen[numOnScreen] = cur;
                    numOnScreen++;
                }
            }
        }
        std::cout << "Type your selection and press ENTER: ";
        //cin.ignore();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear the input buffer

        cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear the input buffer

        std::cout << endl;
    }

    // if (choice == "0") {
    //     activateUI();
    // }

    for (unsigned int curLetter = 0; curLetter < choice.length(); curLetter++){
        if (!isdigit(choice[curLetter])) {
            std::cout << "ERROR: Invalid data range.\n\n";
            return modSelectChangeItem(fresh, assessed, in_progress, cancelled, done);
        }
    }
    int selection = stoi(choice);

    if (0 < selection && selection <= numOnScreen) {
        return ItemOnScreen[selection - 1];
    } else {
        std::cout << "ERROR: Invalid data range.\n\n";
        return modSelectChangeItem(fresh, assessed, in_progress, cancelled, done);
    }      
    return ChangeItem();
}
/*===========================================================*/  
ChangeItem ChangeItem::createSelectChangeItem(Product product){
    changeItemFile.seekg(0, ios::beg);
    return createGetNext(product);
}
/*===========================================================*/  
void ChangeItem::viewChangeItem(ChangeItem item){
    cout << "-----------Query: Change Item-----------" << endl;
    cout << "Product: " << item.product << endl;
    cout << "Description: " << item.description << endl;
    cout << "Change ID: " << item.changeID << endl;
    cout << "Priority: " << item.priority << endl;
    cout << "Status: " << item.status << endl;
    cout << "Anticipated Fix Release ID: " << item.anticipatedReleaseID << endl;
}
/*===========================================================*/  
ChangeItem ChangeItem::getNext(const Product product) {
    ChangeItem cur;
    int setCounter = 0;
    int numOnScreen = 0;
    string choice = "S";
    
    while (choice == "P" || choice == "N" || choice == "S") {
    //cin.ignore();
        
            cout << "== P for the previous 20 items ==\n"
                 << "== N for the next 20 items ==\n";

            cout <<"\nPlease select a Change Item:\n";
            if (changeItemFile.is_open()) {
            changeItemFile.clear();
            changeItemFile.seekg((setCounter * 20) * sizeof(ChangeItem));  
            numOnScreen = 0;

            while (numOnScreen < 20 ) {
                changeItemFile.read(reinterpret_cast<char*>(&cur), sizeof(ChangeItem));                
                if (changeItemFile.eof()) { // Check if we read past the EOF
                    changeItemFile.clear();  // Clear the EOF flag
                    break;
                }  
                // Print release ID read to screen if it belongs to the correct product
                if (strcmp(cur.product, product.name) == 0){ 
                std::cout << (numOnScreen + 1) << ") " << cur.description << "\n";
                ItemOnScreen[numOnScreen] = cur;
                numOnScreen++;
                }
            }
            std::cout << "Type your selection and press ENTER: ";
            cin.ignore();
            std::getline(std::cin, choice);
            std::cout << std::endl;
            if (choice == "P") {
                if (setCounter <= 0){
                    cout << "Already on the first menu." << endl;
                }
                setCounter--;
            }
            else if (choice == "N") {
                setCounter++;
            }
            else if(choice=="0"){
                activateUI();
            }
            else {
                    
                int selection = std::stoi(choice);
                if (0 < selection && selection <= numOnScreen) {
                    return ItemOnScreen[selection - 1];
                } else {
                    std::cout << "ERROR: Invalid data range.\n\n";
                }
            }
        }
    }

    return ChangeItem();
}
/*===========================================================*/  
bool ChangeItem::openChangeItemFile(const std::string& filename) {
    // Try to open the file with the desired flags
    changeItemFile.open(filename, ios::in | ios::out | ios::binary | ios::ate);
    if (!changeItemFile.is_open()) {
        // If it fails, open the file with std::ios::out to create it
        std::ofstream outfile(filename, ios::out | ios::binary);
        if (!outfile.is_open()) {
            std::cerr << "Failed to create file: " << filename << std::endl;
            return false;
        }
        // Close the output file
        outfile.close();
        // Try opening the file again with the desired flags
        changeItemFile.open(filename, ios::in | ios::out | ios::binary | ios::ate);
        if (!changeItemFile.is_open()) {
            std::cerr << "Failed to open file after creating it: " << filename << endl;
            return false;
        }
    }
    return true;
}
/*===========================================================*/  
bool ChangeItem::writeChangeItem() {
    if (!changeItemFile.is_open()) {
        std::cerr << "File is not open for writing." << std::endl;
        return false;
    }

    changeItemFile.clear();
    changeItemFile.seekg(0, std::ios::beg);

    ChangeItem currentItem;
        changeItemFile.clear();
        changeItemFile.seekp(0, std::ios::end);

    changeItemFile.write(reinterpret_cast<const char*>(this), sizeof(ChangeItem));
    if (changeItemFile.fail()) {
        std::cerr << "Error writing ChangeItem to file." << std::endl;
        return false;
    }

    changeItemFile.flush();
    return true;
}
/*===========================================================*/  
ChangeItem ChangeItem::operator=(ChangeItem other) {
    if (this != &other) {
        strncpy(product, other.product, sizeof(product) - 1);
        product[sizeof(product) - 1] = '\0';
        strncpy(changeID, other.changeID, sizeof(changeID) - 1);
        changeID[sizeof(changeID) - 1] = '\0';
        strncpy(description, other.description, sizeof(description) - 1);
        description[sizeof(description) - 1] = '\0';
        strncpy(priority, other.priority, sizeof(priority) - 1);
        priority[sizeof(priority) - 1] = '\0';
        //status = other.status;
        strncpy(status, other.status, sizeof(status));
        strncpy(anticipatedReleaseID,
                other.anticipatedReleaseID,
                sizeof(anticipatedReleaseID) - 1);

        anticipatedReleaseID[sizeof(anticipatedReleaseID) - 1] = '\0';
    }
    return *this;
}
/*===========================================================*/ 
ChangeItem ChangeItem::createGetNext(const Product product) {
    ChangeItem cur;
    int setCounter = 0;
    int numOnScreen = 0;
    string choice = "S";
    
    while (choice == "P" || choice == "N" || choice == "S") {
    //cin.ignore();
        
            cout << "== P for the previous 20 items ==\n"
                 << "== N for the next 20 items ==\n";

            cout <<"\nPlease select a Change Item\n";
            if (changeItemFile.is_open()) {
            changeItemFile.clear();
            changeItemFile.seekg((setCounter * 20) * sizeof(ChangeItem));  
            numOnScreen = 0;

            while (numOnScreen < 20 ) {
                changeItemFile.read(reinterpret_cast<char*>(&cur), sizeof(ChangeItem));                
                if (changeItemFile.eof()) { // Check if we read past the EOF
                    changeItemFile.clear();  // Clear the EOF flag
                    break;
                }  
                // Print release ID read to screen if it belongs to the correct product
                if (strcmp(cur.product, product.name) == 0){ 
                std::cout << (numOnScreen + 1) << ") " << cur.description << "\n";
                ItemOnScreen[numOnScreen] = cur;
                numOnScreen++;
                }
            }
            std::cout << "C) Create a new Change Item" << endl;
            std::cout << "Type your selection and press ENTER: ";
            cin.ignore();
            std::getline(std::cin, choice);
            std::cout << std::endl;
            if (choice == "P") {
                if (setCounter <= 0){
                    cout << "too low" << endl;
                }
                setCounter--;
            }
            else if (choice == "C") {
                try{
                    addChangeItem(product);
                }
                // if operation is cancelled.
                catch(const ERROR_message& e){
                    cerr << e.what() << endl;
                    throw ERROR_message("Returning to selecting a Change Item.\n"); 
                }
            } 
            else if (choice == "N") {
                setCounter++;
            }
            else {
                    
                int selection = std::stoi(choice);
                if (0 < selection && selection <= numOnScreen) {
                    return ItemOnScreen[selection - 1];
                } else {
                    std::cout << "ERROR: Invalid data range.\n\n";
                }
            }
        }
    }
    return ChangeItem();
    }
/*===========================================================*/  