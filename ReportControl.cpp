// DONE DO NOT MODIFY
// ReportControl.cpp
/*------------------------------------------------------------
Revision History:
Rev. 2 - 2024/07/29 Updated alignment by Shiny Kumarapeli
Rev. 1 - 2024/07/14 Original by Shiny Kumarapeli
--------------------------------------------------------------
Uses the extern files created in the other modules to read from in order to print
Uses <iomanip> to align columns on report
-------------------------------------------------------------*/
#include "ReportControl.h"
#include "ScenarioControl.h"

#include <iomanip> // for setw (setting width)
#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;


class ChangeItem;
class Requester;
class ProductRelease;
/*===========================================================*/
void printListChangeItems(){ // in   
    ChangeItem cur;
    changeItemFile.seekg(0, ios::beg);
    // Go through each entry in the change item file 
    while (changeItemFile.read(reinterpret_cast<char*>(&cur), sizeof(ChangeItem))){
        if (changeItemFile.eof()) { // Check if we read past the EOF
            changeItemFile.clear();  // Clear the EOF flag
            break;
        } 

         // If the status of the Change Item is Fresh, Assessed, or In-Progress
         // ...print out its details
        if ((strcmp(cur.status,"FRESH") == 0)|(strcmp(cur.status,"ASSESSED") == 0)|
                                        (strcmp(cur.status,"IN-PROGRESS") == 0)){

        // formatting so that the report is properly aligned when displayed                                              
        cout << left << setw(13) << cur.product     // print product name of change item
            << left << setw(33) << cur.description  // print description
            << left << setw(13) << cur.changeID     // print Change ID
            << left << setw(12) << cur.priority     // print Priority
            << left << setw(13) << cur.status       // print status
            << left << setw(14) << cur.anticipatedReleaseID // ^ anticipated Release ID
            << endl;   
        }                              
    }  
}

/*===========================================================*/  
void printListRequesters(ChangeItem changeItem){ // in
    // Make sure to start reading from the beginning of the change request file
    ChangeRequest curChangeReq;
    changeRequestFile.seekg(0, ios::beg);   
    while (!changeRequestFile.eof()){ // Go through each entry in the change reqeust file
         // Save the request date
        changeRequestFile.read(reinterpret_cast<char*>(&curChangeReq),
                                sizeof(ChangeRequest));
        /* Check if the change id of the current request in the file matches the
            ...change id of the requested change item */
            //cout << "Current Request ID: " << curChangeReq.changeId << endl;
        if (strcmp(curChangeReq.changeId, changeItem.changeID) == 0){ 
            requesterFile.seekg(0, ios::beg); 
            Requester curRequester;
            while (!requesterFile.eof()){ // Go through each entry in the reqeuster file
                requesterFile.read(reinterpret_cast<char*>(&curRequester),
                                        sizeof(Requester));
                    if (requesterFile.eof()) { // Check if we read past the EOF
                        requesterFile.clear();  // Clear the EOF flag
                        break;
                    } 
                    //cout << "Requester rn: " << curRequester.email << endl;
    //cout << "3" << endl;
                 /* If the requester assosicated with the request in question matched
                    ...the current requester, print out their information*/
                if (strcmp(curChangeReq.requesterInfo, curRequester.email) == 0){                           
                    // print the requester's name, email and phone number
                    // PRINT
                    cout << left << setw(34) << curRequester.name  // ^requester's name
                        << left << setw(28) << curRequester.email  // ^requester's email
                        << left << setw(14) << curRequester.phone  // ^requester's phone
                        << endl;    
                } // if (strcmp(curChangeReq.requesterInfo, curRequester.email) == 0)
            } // while (!requesterFile.eof())
        } // if (curChangeReq.changeId == changeItem.changeID)
    } // while (!changeRequestFile.eof())
}
/*===========================================================*/  
