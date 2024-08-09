// ScenarioControl.h
/*------------------------------------------------------------
Revision History:
Rev. 2 - 2024/07/14 Included errors.h by JK
Rev. 1 - 2024/06/30 Original by Shiny Kumarapeli
--------------------------------------------------------------
This module is used as scenario control for the user scenarios of:
    creating a requester
    creating a change request
    creating a product
    creating a product release
    creating a change item
    assessing and modifying change items
    query change item
------------------------------------------------------------*/
#ifndef SCENARIO_CONTROL_H
#define SCENARIO_CONTROL_H

#include "errors.h"     // handle errors
#include "ReportControl.h"
#include "Requester.h"
#include "Product.h"
#include "ProductRelease.h"
#include "ChangeRequest.h"
#include "ReportControl.h"
using namespace std;

//===========================================================*/
void initControl();
/*------------------------------------------------------------
  Called by startup() to initialise all the other modules.
=============================================================*/  
void createRequester();
/*------------------------------------------------------------
  Triggers the scenario of creating a requester.
=============================================================*/  
void createRequest();
/*------------------------------------------------------------
  Triggers the scenario of creating a request.
=============================================================*/  
void createProduct();
/*------------------------------------------------------------
  Triggers the scenario of creating a product.
=============================================================*/
void createProductRel();
/*------------------------------------------------------------
  Triggers the scenario of creating a product release.
=============================================================*/
void createChangeItem();
/*------------------------------------------------------------
  Triggers the scenario of creating a change item.
=============================================================*/
void modifyChangeItem();
/*------------------------------------------------------------
  Triggers the scenario of modifying a change item.
=============================================================*/
void assessChangeItem();
/*------------------------------------------------------------
  Triggers the scenario of assessing a change item.
=============================================================*/
void queryChangeItem();
/*------------------------------------------------------------
  Triggers the scenario of querying a change item.
=============================================================*/
void reportChangeItem();
/*------------------------------------------------------------
  Triggers the scenario of displaying reports.
=============================================================*/
void reportRequesters();
/*------------------------------------------------------------
  Triggers the scenario of displaying reports.
=============================================================*/

#endif
