// UserInterface.h
/*------------------------------------------------------------
Revision History:
Rev. 2 - 2024/07/15 Added backMenuPrintReports () by JK
Rev. 1 - 2024/06/29 Original by Jae Hee Kim
--------------------------------------------------------------
Displays and activates the main menu and its connected submenus
as well as additional menus that appear on the user interface.
------------------------------------------------------------*/
#ifndef USER_INTERFACE_H
#define USER_INTERFACE_H

#include "errors.h"             // to ouput error messages 
#include "ScenarioControl.h"
/*===========================================================*/
void activateUI();    
/*------------------------------------------------------------
  Activates the user interface by starting up the Main Menu Loop.
=============================================================*/       
int mainMenu();
/*------------------------------------------------------------
  Displays the Main Menu and returns user selection.
=============================================================*/   
void menuCreateNew();
/*------------------------------------------------------------
  Displays the Create New sub menu and activates its switch cases,
  asking the user for their selection
=============================================================*/       
void menuModifyExisting();
/*------------------------------------------------------------
  Displays the Modify Existing sub menu and activates its switch cases,
  asking the user for their selection
=============================================================*/   
void menuAssess();
/*------------------------------------------------------------
  Displays the Assess sub menu and activates its switch cases,
  asking the user for their selection
=============================================================*/   
void menuQuery();
/*------------------------------------------------------------
  Displays the Query sub menu and activates its switch cases,
  asking the user for their  selection
=============================================================*/ 
void backMenuPrintReports();
/*------------------------------------------------------------
  Displays the menu that appears after a report is displayed
=============================================================*/ 
void menuPrintReport();
/*------------------------------------------------------------
  Displays the Print Report sub menu and activates its switch cases,
  asking the user for their selection
=============================================================*/   

#endif  // USER_INTERFACE_H

