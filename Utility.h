// DONE DO NOT MODIFY
// Utility.h
/*------------------------------------------------------------
Revision History:
Rev. 3 - 2024/07/25 flushFiles(), populateFiles() by Shiny Kumarapeli
Rev. 2 - 2024/07/14 Updated comments by Jae Hee Kim
Rev. 1 - 2024/06/29 Original by Jae Hee Kim
--------------------------------------------------------------
This utility file contains utility functions that affect the
overall program and not just one object class/module.
------------------------------------------------------------*/
#ifndef UTILITY_H
#define UTILITY_H

#include "ScenarioControl.h"    // access to call
/*===========================================================*/
void startup ();    
/*------------------------------------------------------------
  This function will initialise the program by opening up all files.
=============================================================*/    
void shutdown ();
/*------------------------------------------------------------
  This function is used to help shutdown the program. It will
  close all open files and release any memory if used.
=============================================================*/
bool flushFiles ();
/*------------------------------------------------------------
  This function is used to help avoid any data loss or corruption.
  returns if the flush was a success or failure.
=============================================================*/  
bool populateFiles ();
/*------------------------------------------------------------
  This function is used to help avoid any data loss or corruption.
  returns if the flush was a success or failure.
=============================================================*/  

#endif  // UTILITY_H

