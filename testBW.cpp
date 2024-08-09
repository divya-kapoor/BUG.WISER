#include "ScenarioControl.h"
#include "Utility.h"
#include <iostream>
#include <cstring>


using namespace std;

int main(){
     flushFiles();
     populateFiles();
     startup();
     Product prod;
     Requester req;
     ChangeItem item;
  
     strncpy(prod.name, "Product0", sizeof(prod.name) - 1);
     strncpy(item.changeID, "10000", sizeof(item.changeID) - 1);
     ProductRelease p;
     //p.selectProductRel(prod);
     //req.selectRequester();
     printListRequesters(item);
     cout << "Helloo" << endl;
     shutdown();
     //printListChangeItems();
// }
/*
bool areProductsEqual(const Product& p1, const Product& p2) {
    return std::strcmp(p1.name, p2.name) == 0;
}

void printProduct(const Product& p) {
    std::cout << "Product Name: " << p.name << "\n";
}

void testProductSelection(const std::string& filename) {
    Product product;
    Product selectedProduct;

    std::cout << "Testing product selection...\n";
    productFile.open(filename, std::ios::in | std::ios::out | std::ios::binary);
    if (!productFile.is_open()) {
        std::cerr << "Failed to open file for reading.\n";
        return;
    }

    selectedProduct = product.selectProduct();
    printProduct(selectedProduct);

    productFile.close();
}

int main() {
    const std::string filename = "ProductTest.dat";

    // Create and write 40 test products to the file
    {
        std::ofstream outFile(filename, std::ios::binary | std::ios::out);
        if (!outFile.is_open()) {
            std::cerr << "Failed to open file for writing.\n";
            return 1;
        }

        for (int i = 0; i < 40; ++i) {
            Product p;
            std::snprintf(p.name, sizeof(p.name), "Product%02d", i + 1);
            outFile.write(reinterpret_cast<const char*>(&p), sizeof(Product));
        }

        outFile.close();
    }

    // Test product selection
    testProductSelection(filename);

    return 0;*/
}
