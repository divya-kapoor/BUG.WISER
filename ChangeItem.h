// ChangeItem.h
/*------------------------------------------------------------
Revision History:
Rev 4 - 2024/07/30 formatted into coding conventions, added some descriptions by JK
Rev 3 - 2024/07/15 moved data members to public, got rid of get functions
                   changed selectChangeItem to modSelectChangeItem, by JK
Rev 2 - 2024/07/15 added some member variables by JK
Rev 1 - 2024/06/30 Original by Divya Kapoor
------------------------------------------------------------------
This module defines the ChangeItem class which includes attributes like
priority, description, status, and anticipated release ID, and methods for
initializing,modifying, assessing, and managing these change items.
-----------------------------------------------------------------*/

#ifndef CHANGEITEM_H
#define CHANGEITEM_H

#include "Product.h"
#include "ProductRelease.h"

#include <string> 
using namespace std;


extern std::fstream changeItemFile;

class ChangeItem {
public:
    char product[11];
    char description[31];
    char changeID[10];
    char priority[2];
    char status[15];
    char anticipatedReleaseID[9];

    /*===========================================================*/
    ChangeItem();
    /*------------------------------------------------------------
       constructor
    =============================================================*/
    bool initChangeItem();
    /*------------------------------------------------------------
       Initializes the change item by opening/creating the file.
    =============================================================*/
    void addChangeItem(Product newProductCI);
    /*------------------------------------------------------------
       adds a change item to the file.
    =============================================================*/
    void createChangeID();
    /*------------------------------------------------------------
       automatically creates a new change ID for the request.
    =============================================================*/
    string inputPriority();
    /*------------------------------------------------------------
       Prompts the user to input the priority and stores it.
    =============================================================*/
    string inputDescription();
    /*------------------------------------------------------------
       Prompts the user to input the description and stores it.
    =============================================================*/
    void modStatus(const char* changeID);
    /*------------------------------------------------------------
       Prompts the user to modify the status and stores it.
    =============================================================*/
    void modDescription(const char* changeID);
    /*------------------------------------------------------------
       Prompts the user to modify the description and stores it.
    =============================================================*/
    void modAnticipatedRel(const char* changeID);
    /*------------------------------------------------------------
       Prompts the user to modify the anticipated release ID and stores it.
    =============================================================*/
    void modPriority(const char* changeID);
    /*------------------------------------------------------------
       Prompts the user to modify the priority and stores it.
    =============================================================*/
    void assess();
    /*------------------------------------------------------------
       used to assess change items.
    =============================================================*/
    void closeChangeItemFile();
    /*------------------------------------------------------------
       closes the change item file.
    =============================================================*/
    ChangeItem selectChangeItem(const Product product);
    /*------------------------------------------------------------
       display a select change item menu, read and display change items from file
       prompt the user for their choice and return the selected ChangeItem object.
    =============================================================*/
    ChangeItem createSelectChangeItem(const Product product);
    /*------------------------------------------------------------
       same as selectChangeItem, but used to call createGetNext
    =============================================================*/
    ChangeItem modSelectChangeItem(bool fresh,
                                   bool assessed,
                                   bool in_progress,
                                   bool cancelled,
                                   bool done);
    /*------------------------------------------------------------
       select a change item based on it's state
    =============================================================*/
    ChangeItem querySelectChangeItem(Product product);
    /*------------------------------------------------------------
       select a change Item when searching for one
    =============================================================*/
    void viewChangeItem(ChangeItem item);
    /*------------------------------------------------------------
       used to display the information of a Change Item
    =============================================================*/
    ChangeItem operator=(const ChangeItem );
    /*------------------------------------------------------------
       overloaded operator
    =============================================================*/
    bool writeChangeItem();
    /*------------------------------------------------------------
      Writes the change item details to the file, returns whether the
      operation was successful.
    =============================================================*/

private:
    /*===========================================================*/
    bool openChangeItemFile(const string& filename);  // The name of the file
                                                      //to write to (in)     
    /*------------------------------------------------------------
     Opens the change item file, returns whether the operation was successful.
    =============================================================*/
    void seekToBeginningOfFile();
    /*------------------------------------------------------------
     Seeks to the beginning of the change item file.
    =============================================================*/
    ChangeItem getNext(const Product product); // retrieve the change item (out)
    /*------------------------------------------------------------
     Retrieves the next change item from the file and stores it in changeItemObj.
    =============================================================*/
    ChangeItem createGetNext(const Product product); // retrieve the change item (out)
    /*------------------------------------------------------------
     Retrieves the next change item from the file and stores it in changeItemObj.
     Same as getNext, but used when the option to create a Change Item is available.
    =============================================================*/
};

#endif // CHANGEITEM_H
