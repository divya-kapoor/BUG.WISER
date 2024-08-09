// DONE DO NOT MODIFY
// ProductRelease.h
/*------------------------------------------------------------
Revision History:
Rev. 2 = 2024/07/13 Shiny Kumarapeli
    Changed productInfo to mainProduct
    Moved mainProduct, releaseDate, and relaseID to the public section.
    Changed inputProductRel from returning char to return void.
    Removed closeProductRel function
    Added operator overloader
    Changed selectProductRel() from returning bool to returning ProductRelease
    Moved closeReleaseFile() function in public members
    Removed writeRelease() parameters
    Changed getNext to take Product as a parameter
Rev. 1 - 2024/06/30 Original by Liza Awwad
--------------------------------------------------------------
This module is used to manage product releases. It provides functionality for 
initializing, inputting, adding, selecting, and closing product releases.
------------------------------------------------------------*/
#ifndef PRODUCT_RELEASE_H
#define PRODUCT_RELEASE_H

#include "Product.h"
#include <fstream>

// External file to allow the printing of data if needed
extern std::fstream productReleaseFile; 
    /*===========================================================*/
class ProductRelease {
public:
    Product mainProduct;
    char releaseDate[11];
  //  char releaseID[13];     // i think this needs to be 9
    char releaseID[9];    
    /*===========================================================*/
    bool initProductRel();
    /*------------------------------------------------------------
      Initializes the product release process.
    =============================================================*/  
    void inputReleaseID();
    /*------------------------------------------------------------
      Inputs a new product release.
    =============================================================*/  
    void inputReleaseDate();
    /*------------------------------------------------------------
      Inputs a new product release.
    =============================================================*/  
    void addProductRelease(Product product);
    /*------------------------------------------------------------
      Adds a new product release to the system.
      - product: The product to be associated with the release (in).
    =============================================================*/  
    ProductRelease selectProductRel(const Product product);
    /*------------------------------------------------------------
      Selects an existing product release.
    =============================================================*/  
    void closeReleaseFile();
    /*------------------------------------------------------------
      Closes the file for product releases.
    =============================================================*/ 
    ProductRelease operator=(const ProductRelease &);
    /*------------------------------------------------------------
      Operator overloader to set elements in array to ProductRelease types
    =============================================================*/ 
private:
    /*=============================================================*/ 
    void openReleaseFile(const string &filename);
    /*------------------------------------------------------------
      Opens the file for product releases.
      - filename: The name of the file to open (in).
    =============================================================*/  
    void writeRelease();
    /*------------------------------------------------------------
      Writes a product release to the file.
      - releaseObject: The release object to write (in).
    =============================================================*/  
    ProductRelease getNext(const Product product);
    /*------------------------------------------------------------
      Retrieves the next product release from the file.
      - releaseObj: The release object to store the next release (out).
    =============================================================*/   
};

#endif // PRODUCT_RELEASE_H
