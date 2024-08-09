// ScenarioControl.cpp;
/*------------------------------------------------------------
Revision History:
Rev. 3 - 2024/07/30 Final updates, error handling by JK, Shiny
Rev. 2 - 2024/07/15 implemented initControl by JK
Rev. 1 - 2024/06/29 Original by Shiny Kumarapeli
--------------------------------------------------------------
Implementation for scenario control. Calls the functions of
various different modules for each use case. Is the central control
module.
------------------------------------------------------------*/

#include "ScenarioControl.h"

#include <iomanip>      // for setw (setting width)
#include <iostream>
#include <string>
#include <fstream>
#include "UserInterface.h"

using namespace std;



//===========================================================*/
void initControl(){
  Requester inRequester;
  ChangeRequest inChangeRequest;
  Product inProduct;
  ProductRelease inProductRel;
  ChangeItem inChangeItem;

  inRequester.initReq();
  inChangeRequest.initChangeRequest();
  inProduct.initProduct();
  inProductRel.initProductRel();
  inChangeItem.initChangeItem();
}

/*=============================================================*/  
void createRequester(){
  Requester newRequester;
  // newRequester.inputPhone();
  // newRequester.inputName();
  // newRequester.inputEmail();
  // newRequester.inputDept();    // COMMENTED OUT BECAUSE ADD REQUESTER ALREADY HAS
  cout << "------Create New: Requester------" << endl;
  newRequester.addRequester();
}
/*=============================================================*/  
void createRequest(){
  cout << "------Create New: Request------" << endl;        
  // initialising a requester object to store selected requester
  Requester requestRequester; 
  requestRequester = requestRequester.selectRequester(); // selecting requester

  cout << "------Create New: Request------" << endl; 
  Product requestProduct;  // initialising a product object to store selected product
  requestProduct = requestProduct.selectProduct();   // selecting product

  // initialising a product release object to store selected product release
  ProductRelease requestProductRel;
  // selecting product release
  cout << "------Create New: Request------" << endl; 
  requestProductRel = requestProductRel.selectProductRel(requestProduct);

  ChangeItem requestChangeItem;
  // selecting Change Item
  bool changeSELECTED = false;
  do {
    try {
      cout << "\n------Create New: Request------" << endl; 
      requestChangeItem = requestChangeItem.createSelectChangeItem(requestProduct);     
      changeSELECTED = true;
    }
    catch(const ERROR_message& e){
        cerr << e.what() << endl;
        changeSELECTED = false;
    }
  } while (!changeSELECTED);
  
  // regular constructing (NEEDS CONSTRUCTOR)
    // = ChangeRequest(requestRequester, requestProductRel, requestChangeID);
  ChangeRequest newChangeRequest;

  //newChangeRequest.inputChangeRequest();
  cout << "\n------Create New: Request------" << endl; 
  newChangeRequest.addChangeRequest(requestRequester.email,
                                    requestProductRel.releaseID,
                                    requestChangeItem.changeID);
}
/*=============================================================*/  
void createProduct(){
  Product newProduct;               // create default Product

  try{                              // will ask user to input name
    newProduct.addProduct();  
  }
  // if the product name already exists, a keyUniqueness error is caught
  catch(const ERROR_message& e) {   
    cerr << e.what() << endl;

    cout << "Going back to main menu." << endl;
  }
}
/*=============================================================*/ 
void createProductRel(){
  Product relProduct;
  cout << "------Create New: Product Release------" << endl;
  relProduct = relProduct.selectProduct();

  ProductRelease newProductRel;                // create a new product release object
  // set the product selecting when adding a product
  newProductRel.addProductRelease(relProduct); 
}
/*=============================================================*/
// this gets called by selectChangeItem

// void createChangeItem(Product newProductCI, ProductRelease newProductReleaseCI){    
//     ChangeItem newChangeItem;

//     //newChangeItem.inputDescription();
//     //newChangeItem.inputPriority();
//     newChangeItem.addChangeItem(newProductCI, newProductReleaseCI);

       // set product of new changeitem to be product chosen 
//     //newChangeItem.product = newProductCI.name;   
       // set product of new changeitem to be product chosen
//     //newChangeItem.anticipatedReleaseID = newProductReleaseCI.releaseID;   
// }

/*=============================================================*/
void modifyChangeItem(){
  ChangeItem modChangeItem;

  void modStatus(ChangeItem &changeItemObj);

  modChangeItem = modChangeItem.modSelectChangeItem(false, true, true, false, false);
  // MODIFY EXISITING MENU FOR CHANGE ITEM
  cout << "\n------Modify Existing: Change Item-----\n"
       << "Description: " << modChangeItem.description << "\n"
       << "Change ID: " << modChangeItem.changeID << "\n"
       << "Priority: " << modChangeItem.priority << "\n"
       << "Status: " << modChangeItem.status << "\n"
       << "Anticipated Release ID: " << modChangeItem.anticipatedReleaseID << "\n"
       << "\n"
       << "Please select an attribute to modify\n"
       << "1) Description\n"
       << "2) Status\n"
       << "3) Priority\n"
       << "4) Anticipated Release ID\n"
       << "B) Previous Menu\n"
       << "Type your selection and press ENTER: ";

  char modAttributeSelection;

  do{
    //cin.ignore();
    cin >> modAttributeSelection;

    switch (modAttributeSelection){
      case '1':   // modify description
        modChangeItem.modDescription(modChangeItem.changeID);
        break;
      case '2':   // modify status
        modChangeItem.modStatus(modChangeItem.changeID);
        break;
      case '3':   // modify priority
        modChangeItem.modPriority(modChangeItem.changeID);
        break;
      case '4':   // modify anticipated release ID
        modChangeItem.modAnticipatedRel(modChangeItem.changeID);
        break;
      case '0':   // main menu
        //activateUI();
        break;
      case 'B':  // back to last menu
        break;
      default:
        ERROR_invalidSelection();
        break;
    }
    break;
  } while (modAttributeSelection != 'B');
}
/*=============================================================*/
void assessChangeItem(){
// Acesses the assess function for ChangeItem

  ChangeItem assessedChangeItem;
  assessedChangeItem.assess();
}
/*=============================================================*/
void queryChangeItem(){
// query for a change item.
  cout << "------Query: Change Item------" << endl;
  // filter first to a particular product on product list
  Product queryItemProduct;          // get a product to search for change item
  queryItemProduct = queryItemProduct.selectProduct();  // select product.

  ChangeItem queChangeItem;                       // get a ChangeItem
  // select change item to view
  queChangeItem = queChangeItem.selectChangeItem(queryItemProduct); 
  queChangeItem.viewChangeItem(queChangeItem);   // prints outs the selected changeItem.
}

/*=============================================================*/
void reportChangeItem(){  // report1
  // A list of all active change items will be displayed (fresh, Assessed, in-progress)

  // header for the print report
  cout << "-------------------------------------Print Report: Active Change Items"
       << "-------------------------------------" << endl;
      // LEFT aligned:  
  cout << left << setw(13) << "Product:"       // can be 8 chars long+3 for spacing
        << left << setw(33) << "Description:"  // can be 30 chars long + 3 for spacing
        << left << setw(13) << "Change ID:"    // can be 6 digits long + 3 for spacing
        << left << setw(12) << "Priority:"     // can be 1 digit long + 3 for spacing
        << left << setw(13) << "State:"        // no more than 13 characters long
        << left << setw(14) << "Anticipated Release ID:" << endl << endl;  

  printListChangeItems(); // calling function to print out whole list
  cout << "-------------------------------------------"
       << "----------------------------------------------------------------\n";
}
/*=============================================================*/
void reportRequesters(){  // report2

  // Prompt the user to select a product using selectProduct().
  Product reportProduct;
  cout << "-----Print Report: Requesters to be Informed-----" << endl;
  reportProduct = reportProduct.selectProduct();

  // Prompt the user to select a release from the list of release for that product
  ProductRelease reportRelease;
  cout << "-----Print Report: Requesters to be Informed-----" << endl;
  reportRelease = reportRelease.selectProductRel(reportProduct);
  // Prompt the user to select a change item using selectChangeItem().
  ChangeItem implemChangeItem;
  cout << "-----Print Report: Requesters to be Informed-----" << endl;
  implemChangeItem = implemChangeItem.selectChangeItem(reportProduct);

  // ONE TIME HEADERS FOR THE PRINT REPORT LIST
  // header for the print report
  cout << "--------------------Print Report: Requesters to be Informed"
       << "--------------------" << endl;
  
  // Change ID:      Description:                        Released in:  
  cout << left << setw(16) << "Change ID:"               // can be 6 characters long + 10
        << left << setw(36) << "Description:"            // can be 30 characters long + 6
        << left << setw(12) << "Released In:" << endl;   // can be 8 characters long + 4

  // dddddd          xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx      xxxxxxxx       
  cout << left << setw(16) << implemChangeItem.changeID             // print Change ID
        << left << setw(36) << implemChangeItem.description         // print description
        << left << setw(12) << implemChangeItem.anticipatedReleaseID << endl << endl;

  // Requester:                        Email of Requester:         Phone Number: 
  cout << left << setw(34) << "Requester:"               // can be 30 characters long + 4
        << left << setw(28) << "Email of Requester:"     // can be 24 characters long + 4
        << left << setw(14) << "Phone Number:" << endl;  // can be 11 characters long + 3
  
  printListRequesters(implemChangeItem);
  cout << "------------------------------------------"
       << "-------------------------------------\n";
}
/*=============================================================*/
void closeAll(){
// closes all opened files in the system
  Requester shutRequester;
  ChangeRequest shutChangeRequest;
  Product shutProduct;
  ProductRelease shutProductRel;
  ChangeItem shutChangeItem;

  shutRequester.closeRequesterFile();
  shutChangeRequest.closeRequestFile();
  shutProduct.closeProductFile();
  shutProductRel.closeReleaseFile();
  shutChangeItem.closeChangeItemFile();
}
/*=============================================================*/
void deleteAllFiles();
/*=============================================================*/