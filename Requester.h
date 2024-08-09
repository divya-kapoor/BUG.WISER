// Requester.h
/*------------------------------------------------------------
Revision History:
Rev. 2 - 2024/07/15 changed parameters, functions types, data members,
                    removed functions by JK
Rev. 1 - 2024/06/30 Original by Divya Kapoor
------------------------------------------------------------------
This module defines the “Requester” class, which handles the details
related to individuals who make requests in the BugWiser Tracking System.
This includes attributes for personal and contact information, and
methods for managing these requester details.
-----------------------------------------------------------------*/

#ifndef REQUESTER_H
#define REQUESTER_H

#include <string>

using namespace std;


extern std::fstream requesterFile;

class Requester {
public:

    char name[31];
    char phone[12];
    char email[25];
    char dept[13];

    Requester();

    /*===========================================================*/   
    bool initReq();                
    /*------------------------------------------------------------
     Tries to open a file with a specific name, creates a new file if
     it doesn't exist, returns if successful.
    =============================================================*/ 
    void inputName();            
    /*------------------------------------------------------------
     Prompts the user to input a name, then sets the name to the
     inputted name
    =============================================================*/ 
    void inputPhone();           
    /*------------------------------------------------------------
     Prompts the user to input a phone number, then sets the phone to
     the inputted phone number.
    =============================================================*/ 
    string inputEmail();           
    /*------------------------------------------------------------
     Prompts the user to input an email address, then sets the email
     to the inputted email.
    =============================================================*/ 
    void inputDept();            
    /*------------------------------------------------------------
     Prompts the user to input a department and sets dept to the
    inputted department.
    =============================================================*/ 
    Requester selectRequester();
    /*------------------------------------------------------------
     display a select requester menu, read and display requesters from file
     prompt the user for their choice and RETURN the selected Requester object.
    =============================================================*/ 
    bool addRequester();
    /*------------------------------------------------------------
     Asks the user for confirmation of the inputted 
     requester details (data members). If yes, add to the file.
    =============================================================*/ 
    void closeRequesterFile();     
    /*------------------------------------------------------------
     Closes the requester file.
    ===========================================================*/
    bool writeRequester();
    /*------------------------------------------------------------
     Writes the requester details to the file, returns whether the
     operation was successful.
    =============================================================*/  

private:

    /*===========================================================*/
    bool openRequesterFile(const string &filename); // The name of the file 
                                                    //to be opened (in)     
    /*------------------------------------------------------------
     Opens the requester file, returns whether the operation was successful.
    =============================================================*/ 
    Requester getNext();
    /*------------------------------------------------------------
     Retrieves the next requester from the file
    =============================================================*/ 
};

#endif // REQUESTER_H
