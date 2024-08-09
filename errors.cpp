// errors.cpp
/*------------------------------------------------------------
Revision History:
Rev. 2 - 2024/07/30 edited error_message to only contain meesage by Jae Hee Kim
Rev. 1 - 2024/07/14 Original by Jae Hee Kim
--------------------------------------------------------------
This module is the implementations of errors.h
Includes heavily repeated error warnings.
-------------------------------------------------------------*/
#include "errors.h"
#include <iostream>

using namespace std;
/*===========================================================*/
ERROR_message::ERROR_message(const string& message): 
logic_error(message) {}  
//logic_error("ERROR: " + message) {}  
/*===========================================================*/
void ERROR_invalidSelection(){
// will output the error message of an invalid selection
    cout << "\nERROR: Invalid selection. The option you entered does not exist."
         << "\nPlease select a valid option." << endl;
}
/*===========================================================*/
void ERROR_invalidDataRange(){
// will output the error message of an invalid 
    cout << "ERROR: Invalid data range. Please stay within the character range.\n"
         << endl;
}
/*===========================================================*/
void ERROR_invalidDataFormat(){
// will output the error message of an invalid 
    cout << "ERROR: Invalid data format. Please follow the correct format.\n" << endl;
}
/*===========================================================*/
void ERROR_keyUniqueness(){
// will output the error message of an invalid 
    throw ERROR_message("Already Exists.");
}
/*===========================================================*/