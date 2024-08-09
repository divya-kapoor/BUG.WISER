// DONE DO NOT MODIFY
// UserInterface.cpp
/*------------------------------------------------------------
Revision History:
Rev. 3 - 2024/07/30 Fixed some cout inconsistensies by JK
Rev. 2 - 2024/07/14 Fixed minor inconsistencies and added backMenu() by JK
Rev. 1 - 2024/06/29 Original by Jae Hee Kim
--------------------------------------------------------------
Displays and activates the main menu and its connected submenus
as well as additional menus that appear on the user interface.
-------------------------------------------------------------*/
#include "UserInterface.h"      // header file for this module
#include "errors.h"
#include "stdio.h"
#include <string>
#include <iostream>

using namespace std;
/*===========================================================*/
void activateUI() {
/* activates the user interface by booting up the main menu,
 ...and using a switch case to trigger different menu options */

    // initalising a variable to hold the selection of user from main menu
    int uiSelection; 

    /* this loop wil continue displaying the Main Menu and prompt the user
      ...for an input until they choose to quit the program */
    do {                    
        uiSelection = mainMenu();

        switch(uiSelection) {
            case 1:
                menuCreateNew();
                break;
            case 2:
                menuModifyExisting();
                break;
            case 3:
                menuAssess();
                break;
            case 4:
                menuQuery();
                break;
            case 5:
                menuPrintReport();
                break;
            case 0:
                // exit the main menu loop so main can shutdown
                cout << "Exiting Program" << endl;     
                break;
            default:
                // outputs an error message stating an invalid user selection
                ERROR_invalidSelection();               
                break;
        }
    } while(uiSelection != 0);
}
/*===========================================================*/
void backMenu() {
// displays the small menu that appears that only gives the option to return to main menu
    
    char backMenuSelection;       // variable to hold the user selection

    do {
        cout << "B) Return to the previous menu." << endl;
        cout << "Type your selection and press ENTER: ";

       
        cin >> backMenuSelection;        // takes user input
        
            switch(backMenuSelection) {
                case 'B':
                    break;
                default:
                    ERROR_invalidSelection();
                    break;
            }
        } while(backMenuSelection != 'B');
}
/*===========================================================*/
int mainMenu() {
// display texts for the main menu and takes in the user selection then returns

    // initalising a variable to hold the selection of user from main menu
    int mainSelection;

    cout << "=======Main Menu=======" << endl;
    cout << "1) Create New" << endl;
    cout << "2) Modify Existing" << endl;
    cout << "3) Assess" << endl;
    cout << "4) Query" << endl;
    cout << "5) Print Report" << endl;
    cout << "0) Quit" << endl;
    cout << "Type your selection and press ENTER: ";

    cin >> mainSelection;       // takes user input
    cout << endl;

    return mainSelection;
}
/*===========================================================*/
void menuCreateNew() {
/* create new submenu, takes in user selection and activates the
    ...scenario control function for the submenu selection */

    char createNewSelection;            // variable to hold the user selection

    do{ 
        cout << "\n------Create New:------" << endl;                            
        cout << "1) Request" << endl;
        cout << "2) Requester" << endl;
        cout << "3) Product" << endl;
        cout << "4) Product Release" << endl;
        cout << "B) Previous Menu" << endl;
        cout << "Type your selection and press ENTER: ";

        cin >> createNewSelection;       // takes user input
        cout << endl;

        switch(createNewSelection) {     // each switch case calls the scenario control
            case '1':
                createRequest(); 
                break;
            case '2':
                createRequester();
                break;
            case '3':
                createProduct();
                break;
            case '4':
                createProductRel();
                break;                
            case 'B':
                // Break out of switch case which will default back to the main menu loop
                break;                      
            default:   // default case will output an error for invalid selection
                ERROR_invalidSelection();
                break;
        }
    } while(createNewSelection != 'B'); 
}
/*===========================================================*/    
void menuModifyExisting() {
// 
    char modifySelection;       // variable to hold the user selection
                             
    do{
        cout << "------Modify Existing:------" << endl;
        cout << "1) Change Item" << endl;
        cout << "B) Previous Menu" << endl;
        cout << "Type your selection and press ENTER: ";
    
        cin >> modifySelection;       // takes user input
        cout << endl;

        switch(modifySelection){
            case '1':
                cout << "------Modify Existing:------" << endl;
                modifyChangeItem();
                break;
            case 'B':
                break;
            default:
                ERROR_invalidSelection();
                break;
        }
    } while(modifySelection != 'B');
}
/*===========================================================*/
void menuAssess() {
// displays the Assess Change Item menu header then calls scenario control.

    assessChangeItem();
}
/*===========================================================*/
void menuQuery() {
// displays the Query menu then asks the user for their selection

    char querySelection; // variable to hold the user selection
 	
    do{
        cout << "-------Query for: -------" << endl;  
        cout << "1) Change Item" << endl;
        cout << "B) Previous Menu" << endl;
        cout << "Type your selection and press ENTER: ";

        cin >> querySelection;       // takes user input
        cout << endl;

        switch(querySelection) {
            case '1':
                queryChangeItem();
                cout << "----------------------------------------\n";
                backMenu();
                break;
            case 'B':
                break;
            default:
                ERROR_invalidSelection();
                break;
        }
    } while(querySelection != 'B');
}
/*===========================================================*/
void menuPrintReport() {
/* displays the Print Report menu then prompts the user
    ...for a selection for which report they would like to see. */
    
    char printSelection;    // variable to hold the user selection
  
    do {
        cout << "----------Print Report----------" << endl;
        cout << "Please select the type of report you would like to print." << endl;
        cout << "1) List of all active Change Items" << endl;
        cout << "2) List of all Requesters to be Informed" << endl;
        cout << "B) Previous Menu" << endl;
        cout << "Type your selection and press ENTER: ";

        cin >> printSelection;       // takes user input
        cout << endl;

        switch(printSelection) {
            case '1':
                reportChangeItem();

                backMenu();     // end of list, print the menu options to go back
                break;
            case '2':
                reportRequesters();

                backMenu();     // end of list, print the menu options to go back
                break;
             case 'B':
                break;
             default:
                ERROR_invalidSelection();
                break;
        }
    } while(printSelection != 'B');
}
/*===========================================================*/
