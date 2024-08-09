// Utility.cpp
/*------------------------------------------------------------
Revision History:
Rev. 2 - 2024/07/25 Implemented flushFiles(), populateFiles() by Shiny Kumarapeli
Rev. 1 - 2024/07/14 Original by Jae Hee Kim
--------------------------------------------------------------
This module is the implementation of the Utility.h functions
-------------------------------------------------------------*/
#include "Utility.h"
#include <iostream>
#include <ostream>
#include <fstream>
#include <cstring>
#include <iomanip>
#include <sstream>

using namespace std;
/*===========================================================*/
void startup (){
// calls scenario control to to initialise
    initControl();
}
/*===========================================================*/
void shutdown (){
// calls scenario control to do all the shut down processess
    //closeAll();
}
/*===========================================================*/
bool flushFiles (){
    // Close any open file streams before removing files
    if (productFile.is_open()) productFile.close();
    if (productReleaseFile.is_open()) productReleaseFile.close();
    if (changeItemFile.is_open()) changeItemFile.close();
    if (changeRequestFile.is_open()) changeRequestFile.close();
    if (requesterFile.is_open()) requesterFile.close();
    if (std::remove("ProductRelease.dat") != 0) {
        std::cout << "Failed to delete file: " << "ProductRelease.dat" << std::endl;
        return false;
    }
    if (std::remove("ChangeItem.dat") != 0) {
        std::cout << "Failed to delete file: " << "ChangeItem.dat" << std::endl;
        return false;
    }
    if (std::remove("ChangeRequest.dat") != 0) {
        std::cout << "Failed to delete file: " << "ChangeRequest.dat" << std::endl;
        return false;
    }
    if (std::remove("Requester.dat") != 0) {
        std::cout << "Failed to delete file: " << "Requester.dat" << std::endl;
        return false;
    }
    if (std::remove("Product.dat") != 0) {
        std::cout << "Failed to delete file: " << "Product.dat" << std::endl;
        return false;
    }
    return true;
}
/*===========================================================*/
bool populateFiles (){
    ostringstream pRel;
    ostringstream date;
    ostringstream number;

    Product product;
    ProductRelease prodRel;
    ChangeItem changeItem;
    ChangeRequest changeReq;
    Requester req;

    productFile.open("Product.dat", ios::in | ios::out | ios::binary | ios::app);
    productReleaseFile.open("ProductRelease.dat",
                            ios::in | ios::out | ios::binary | ios::app);
    changeItemFile.open("ChangeItem.dat", ios::in | ios::out | ios::binary | ios::app);
    changeRequestFile.open("ChangeRequest.dat",
                            ios::in | ios::out | ios::binary | ios::app);
    requesterFile.open("Requester.dat", ios::in | ios::out | ios::binary | ios::app);

    //Product file
    //Prod1 
    string p1 = "Prod1";
    strncpy(product.name, p1.c_str(), sizeof(product.name) - 1);  
    if (productFile.is_open()) {
        productFile.write(reinterpret_cast<const char*>(&product), sizeof(Product));
    }

    //Prod1 20 releases, rel.1.00 - rel.1.20
    for (int j = 0; j <= 20; j++){
    pRel.str("");
    pRel.clear();
    date.str("");
    date.clear();
    pRel << "rel.1." << setfill('0') << setw(2) << j;
    date << "2001-10-" << setfill('0') << setw(2) << j;
    strncpy(prodRel.releaseID, pRel.str().c_str(), sizeof(prodRel.releaseID) - 1);
    prodRel.releaseID[sizeof(prodRel.releaseID) - 1] = '\0'; // Ensure null termination
    strncpy(prodRel.releaseDate, date.str().c_str(), sizeof(prodRel.releaseDate) - 1);
    prodRel.releaseDate[sizeof(prodRel.releaseDate) - 1] = '\0'; // Ensure null termination
    strncpy(prodRel.mainProduct.name, p1.c_str(), sizeof(prodRel.mainProduct.name) - 1);
    prodRel.mainProduct.name[sizeof(prodRel.mainProduct.name) - 1] = '\0'; // Ensure null termination
    productReleaseFile.write(reinterpret_cast<const char*>(&prodRel), sizeof(ProductRelease));
    }

    //Change Item with description "MyItemDescription"
    string desc = "MyItemDescription";
    string id = "1234";
    string pri = "1";
    string stat = "FRESH";
    strncpy(changeItem.description, desc.c_str(),sizeof(changeItem.description) - 1);
    strncpy(changeItem.product, p1.c_str(), sizeof(changeItem.product) - 1);
    strncpy(changeItem.changeID, id.c_str(), sizeof(changeItem.changeID) - 1);
    strncpy(changeItem.priority, pri.c_str(), sizeof(changeItem.priority) - 1);
    strncpy(changeItem.status, stat.c_str(), sizeof(changeItem.status));
    if (changeItemFile.is_open()) {
        changeItemFile.write(reinterpret_cast<const char*>(&changeItem),
                            sizeof(ChangeItem));
    }

    //20 Requesters and Change Requests in rel.1.10
    for (int i = 0; i <= 20; i++){
        string num = to_string(i);
        string n = "Requester" + num;
        string email = "Email@." + num;
        number.str("");
        number.clear();
        number << "250000" << setfill('0') << setw(4) << i;
        string dept = "";
        strncpy(req.name, n.c_str(), sizeof(req.name) -1);
        strncpy(req.phone, number.str().c_str(), sizeof(req.phone) - 1);
        strncpy(req.email, email.c_str(), sizeof(req.email) - 1);

        if (requesterFile.is_open()) {
            // Write the requester to the file
            requesterFile.write(reinterpret_cast<const char*>(&req),sizeof(Requester));
        }
        date.str("");
        date.clear();
        date << "2024-01-" << setfill('0') << setw(2) << num;
        string pr1 = "1";
        string p1Rel = "rel.1.10";
        strncpy(changeReq.requestDate, date.str().c_str(),
                sizeof(changeReq.requestDate) - 1);
        strncpy(changeReq.changeId, id.c_str(), sizeof(changeReq.changeId) - 1);
        strncpy(changeReq.priority, pr1.c_str(), sizeof(changeReq.priority) - 1);
        strncpy(changeReq.requesterInfo, email.c_str(),
                sizeof(changeReq.requesterInfo) - 1);
        strncpy(changeReq.productReleaseInfo, p1Rel.c_str(),
                sizeof(changeReq.productReleaseInfo) - 1);
        if (changeRequestFile.is_open()) {
        // Write each member of the change request to the file
        changeRequestFile.write(reinterpret_cast<const char*>(&changeReq),sizeof(ChangeRequest));
        }
    }

    //Prod4WinOS
    string p2 = "Prod4WinOS";
    strncpy(product.name, p2.c_str(), sizeof(product.name) - 1);
    if (productFile.is_open()) {
        // Write the product to the file
        productFile.write(reinterpret_cast<const char*>(&product), sizeof(Product));
    }
    //Prod4WinOS 2 releases
    string p2Rel = "rel.4.00";
    string p2Date = "2003-02-24";
    strncpy(prodRel.releaseID, p2Rel.c_str(), sizeof(prodRel.releaseID) - 1);
    strncpy(prodRel.releaseDate, p2Date.c_str(), sizeof(prodRel.releaseDate) - 1);
    strncpy(prodRel.mainProduct.name, p2.c_str(),sizeof(prodRel.mainProduct) - 1);
    if (productReleaseFile.is_open()) {
        productReleaseFile.write(reinterpret_cast<const char*>(&prodRel),
                                    sizeof(ProductRelease));
    }  
    p2Rel = "rel.4.01";
    p2Date = "2004-10-31";
    strncpy(prodRel.releaseID, p2Rel.c_str(), sizeof(prodRel.releaseID) - 1);
    strncpy(prodRel.releaseDate, p2Date.c_str(), sizeof(prodRel.releaseDate) - 1);
    strncpy(prodRel.mainProduct.name, p2.c_str(),sizeof(prodRel.mainProduct) - 1);
    if (productReleaseFile.is_open()) {
        productReleaseFile.write(reinterpret_cast<const char*>(&prodRel),
                                    sizeof(ProductRelease));
    } 

    //Change Item with description "123456789012345678901234567890"
    desc = "123456789012345678901234567890";
    strncpy(changeItem.description, desc.c_str(),sizeof(changeItem.description) - 1);
    strncpy(changeItem.product, p2.c_str(), sizeof(changeItem.product) - 1);
    strncpy(changeItem.changeID, "4321", sizeof(changeItem.changeID) - 1);
    strncpy(changeItem.priority, "1", sizeof(changeItem.priority) - 1);
    strncpy(changeItem.status, "DONE", sizeof(changeItem.status));
    strncpy(changeItem.anticipatedReleaseID, "rel.4.01", sizeof(changeItem.anticipatedReleaseID));
    if (changeItemFile.is_open()) {
        changeItemFile.write(reinterpret_cast<const char*>(&changeItem),
                            sizeof(ChangeItem));
    }

    //2 change requests for Prod4WinOS
    strncpy(changeReq.requestDate, date.str().c_str(),
            sizeof(changeReq.requestDate) - 1);
    strncpy(changeReq.changeId, "4321", sizeof(changeReq.changeId) - 1);
    strncpy(changeReq.priority, "1", sizeof(changeReq.priority) - 1);
    strncpy(changeReq.requesterInfo, "Email@.1",
            sizeof(changeReq.requesterInfo) - 1);
    strncpy(changeReq.productReleaseInfo, "rel.4.01",
            sizeof(changeReq.productReleaseInfo) - 1);
    if (changeRequestFile.is_open()) {
    // Write each member of the change request to the file
    changeRequestFile.write(reinterpret_cast<const char*>(&changeReq),sizeof(ChangeRequest));
    }
    strncpy(changeReq.requestDate, date.str().c_str(),
            sizeof(changeReq.requestDate) - 1);
    strncpy(changeReq.changeId, "4321", sizeof(changeReq.changeId) - 1);
    strncpy(changeReq.priority, "1", sizeof(changeReq.priority) - 1);
    strncpy(changeReq.requesterInfo, "Email@.2",
            sizeof(changeReq.requesterInfo) - 1);
    strncpy(changeReq.productReleaseInfo, "rel.4.01",
            sizeof(changeReq.productReleaseInfo) - 1);
    if (changeRequestFile.is_open()) {
    // Write each member of the change request to the file
    changeRequestFile.write(reinterpret_cast<const char*>(&changeReq),sizeof(ChangeRequest));
    }

    //20 other Products
    for (int i = 0; i < 20; i++){
        string num = to_string(i);
        string p = "Product" + num;
        strncpy(product.name, p.c_str(), sizeof(product.name) - 1);
        if (productFile.is_open()) {
            // Write the product to the file
            productFile.write(reinterpret_cast<const char*>(&product), sizeof(Product));
        }
    }

    //Change Item can be modified
    string moddescript = "stuck on mod screen";
    string modid = "12345";
    string modpri = "5";
    string modstat = "ASSESSED";
    strncpy(changeItem.description, moddescript.c_str(),sizeof(changeItem.description) - 1);
    strncpy(changeItem.product, p2.c_str(), sizeof(changeItem.product) - 1);
    strncpy(changeItem.changeID, modid.c_str(), sizeof(changeItem.changeID) - 1);
    strncpy(changeItem.priority, modpri.c_str(), sizeof(changeItem.priority) - 1);
    strncpy(changeItem.status, modstat.c_str(), sizeof(changeItem.status));
    if (changeItemFile.is_open()) {
        changeItemFile.write(reinterpret_cast<const char*>(&changeItem),
                            sizeof(ChangeItem));
    }

    //Change Item can be modified
    string mod2descript = "not loading well";
    string mod2id = "12344";
    string mod2pri = "1";
    string mod2stat = "ASSESSED";
    strncpy(changeItem.description, mod2descript.c_str(),sizeof(changeItem.description) - 1);
    strncpy(changeItem.product, p2.c_str(), sizeof(changeItem.product) - 1);
    strncpy(changeItem.changeID, mod2id.c_str(), sizeof(changeItem.changeID) - 1);
    strncpy(changeItem.priority, mod2pri.c_str(), sizeof(changeItem.priority) - 1);
    strncpy(changeItem.status, mod2stat.c_str(), sizeof(changeItem.status));
    if (changeItemFile.is_open()) {
        changeItemFile.write(reinterpret_cast<const char*>(&changeItem),
                            sizeof(ChangeItem));
    }

    //Change Item can be modified
    string mod3descript = "does not open fast";
    string mod3id = "12343";
    string mod3pri = "2";
    string mod3stat = "ASSESSED";
    strncpy(changeItem.description, mod3descript.c_str(),sizeof(changeItem.description) - 1);
    strncpy(changeItem.product, p2.c_str(), sizeof(changeItem.product) - 1);
    strncpy(changeItem.changeID, mod3id.c_str(), sizeof(changeItem.changeID) - 1);
    strncpy(changeItem.priority, mod3pri.c_str(), sizeof(changeItem.priority) - 1);
    strncpy(changeItem.status, mod3stat.c_str(), sizeof(changeItem.status));
    if (changeItemFile.is_open()) {
        changeItemFile.write(reinterpret_cast<const char*>(&changeItem),
                            sizeof(ChangeItem));
    }

    //Close all the files before starting program
    if (productFile.is_open()) productFile.close();
    if (productReleaseFile.is_open()) productReleaseFile.close();
    if (changeItemFile.is_open()) changeItemFile.close();
    if (changeRequestFile.is_open()) changeRequestFile.close();
    if (requesterFile.is_open()) requesterFile.close();

    return true;
}
/*===========================================================*/