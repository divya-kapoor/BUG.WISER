// Product.h
/*------------------------------------------------------------
Revision History:
Rev. 3 - 2024/07/29 Added a constructor by Jae Hee
Rev. 2 - 2024/07/14 Shiny Kumarapeli
    Moved name to be a public member and from string to char
    Changed inputProductName from returning bool to returning void
    Changed addProduct from returning void to returning bool
    Changed selectProduct from returning bool to returning Product
    Removed the function closeProduct()
    Changed getNext from returning bool to returning Product
Rev. 1 - 2024/06/30 Original by Liza Awwad
----------------------------------------------------------
This module is used to manage products. It provides functionality for 
initializing, inputting names, adding, selecting, and closing products.
----------------------------------------------------------*/

#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>

using namespace std;


// Declare external file stream to handle product file operations
extern std::fstream productFile; 

class Product {
public:
    char name[11];
    /*===========================================================*/ 
    Product();
    /*------------------------------------------------------------
    Default constructor for product.
    =============================================================*/ 
    Product(const char* productName);   // in; will set the productname 
    /*------------------------------------------------------------
    Constructor for product.
    =============================================================*/ 
    bool initProduct();
    /*------------------------------------------------------------
    This function will initialize the product process
    =============================================================*/  
    string inputProductName();
    /*------------------------------------------------------------
    This function will input a new product name
    =============================================================*/  
    bool addProduct();
    /*------------------------------------------------------------
    This function will add a new product to the system
    =============================================================*/  
    Product selectProduct();
    /*------------------------------------------------------------
    This function will select an existing product
    =============================================================*/
    void closeProductFile();
    /*------------------------------------------------------------
    This function will close the file for products
    =============================================================*/ 

private:
    /*===========================================================*/ 
    void openProductFile(const string &filename);
    /*------------------------------------------------------------
    This function will open the file for products
    =============================================================*/  
    void writeProduct();
    /*------------------------------------------------------------
    =============================================================*/  
    void seekToBeginningOfFile();
    /*------------------------------------------------------------
    This function will seek to the beginning of the product file
    =============================================================*/  
    Product getNext();
    /*------------------------------------------------------------
    This function will retrieve the next product from the file
    =============================================================*/  

     /*This function will add the file for change requests
    =============================================================*/  
    //void addProduct(ProductRelease productRelease);
};

#endif // PRODUCT_H
