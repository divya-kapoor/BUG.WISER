// main.cpp;
/*------------------------------------------------------------
Revision History:
Rev. 3 - 2024/07/29 added populateFiles() and flushFiles() by Shiny
Rev. 2 - 2024/07/18 added more details in coding convention by Jae Hee Kim
Rev. 1 - 2024/06/29 Original by Jae Hee Kim
--------------------------------------------------------------
This module is the main.cpp for our bug tracking system "BugWiser".
It starts our system and activates the UI menu loops then shutsdown.
------------------------------------------------------------*/
#include "UserInterface.h"      // to begin the user interface/main menu loop
#include "Utility.h"            // to call startup and shutdown processess
/*===========================================================*/
int main(){
    flushFiles();
    populateFiles();

    startup();          // starts the program up

    activateUI();       // opens the main menu loop

    shutdown();		// shuts down the program when finished.

    return 0;
}


/*==========OUR CODING CONVENTIONS==========*/

//  Each .cpp and .h file begins with a long comment header with the following format:
//      *note, these headers do not begin with a tab or any spaces. Tabs 
//       ...here are just for the neatness of coding conventions.
        
        // Module.h                                                              
        /*------------------------------------------------------------
        Revision History:
        Rev. 2 - 2024/07/03 comment here
        Rev. 1 - 2024/06/29 Original by Editor Name
        --------------------------------------------------------------
        Insert description here
        -------------------------------------------------------------*/
//      #includes are written here

// this is for .cpp implementation functions
        /*===========================================================*/        
//      void function(string parameter1, int parameter2) {                     
        // comment explanation for code 
//      }
        /*===========================================================*/
    
        // these are for header files
        /*===========================================================*/        
//      void function();                                                       
        /*------------------------------------------------------------
        description, what it does, how to use it, what its restrictions are
        =============================================================*/  
//      void function(
//          string parameter1       //  parameter explanation (in/out)
//      );
        /*------------------------------------------------------------
        description, what it does, how to use it, what its restrictions are
        =============================================================*/
/* // Constant variables will be named in ALL CAPS    
    Constants:..........................CAPITALIZE_VARIABLE  
// First word will be be lower case, all subsequent words in the
  ...variable will start with an uppercase        
    Variable and function names:........lowercaseUpperUpper          
                                ........ERROR_errorDescription     
// Error functions will begin in all CAPS followed by the error  
    Spacing:............................list = (one, two, three)     // SPACE BETWEEN
            ............................a >= c           // SPACE NEXT TO VARIABLES
            ............................function() {     // parentheses next to function 
                                                          ...name no space with a space
                                                          ...before first curly bracket
                                        }
            ............................line 1
                                            line2       // 4 character spacing (or 1 tab)                          
    If and Else Statements:.............if() {
                                        }      // NO SPACE between if and else statements
                                        else() {
                                        }
*/ 
