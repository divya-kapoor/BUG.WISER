// ReportControl.h
/*------------------------------------------------------------
Revision History:
Rev. 2 - 2024/07/15 changed the parameters by JK
Rev. 1 - 2024/06/30 Original by Shiny Kumarapeli
--------------------------------------------------------------
This module is used as scenario control for the user scenarios of printing reports
------------------------------------------------------------*/
#ifndef REPORT_CONTROL_H
#define REPORT_CONTROL_H

#include "ChangeItem.h"
#include "Requester.h"
#include "ChangeRequest.h"
/*==========================================================*/
void printListChangeItems();
/*------------------------------------------------------------
  Displays the list of active Change Items.
=============================================================*/  
void printListRequesters(ChangeItem implementedChangeItem); // in
/*------------------------------------------------------------
  Displays the list of Requesters that need to be informed about a Change Item.
=============================================================*/  

#endif  // REPORT_CONTROL_H
