// ChangeRequest.h
/*------------------------------------------------------------
Revision History:
Rev. 3 - 2024/07/18 Shiny Kumarapeli
    Changed string dateOfRequest to char requestDate[11]
    Changed Product productInfo to ProductRelease productReleaseInfo
    Changed Requester requesterInfo to char RequesterInfo[25]
    Moved requestDate, changeId, priorit, requesterInfo, and productReleaseInfo to public
    Changed selectChangeRequest() from returning bool to returning ChangeRequest
    Added an opperator overloader to set array elements as ChangeRequests
Rev. 2 - 2024/07/18 Original by Liza Awwad
    Added default constructer
    Added parameterized constructor
    Changed inputChageRequest from returning bool to returning string
Rev. 1 - 2024/06/30 Original by Liza Awwad
--------------------------------------------------------------
This module is used to manage change requests. It provides functionality for 
initializing and processing change requests.
------------------------------------------------------------*/

#ifndef CHANGE_REQUEST_H
#define CHANGE_REQUEST_H

#include <cstddef>
#include <string>
#include <fstream>
#include <vector>
#include <ostream>


extern std::fstream changeRequestFile;

class ChangeRequest {
public:
    char requestDate[11];
    char changeId[10]; 
    char priority[2];  
    char requesterInfo[25]; 
    char productReleaseInfo[13];
    std::fstream outFile;

    ChangeRequest();
    /*------------------------------------------------------------
      Constructor
    =============================================================*/

    ChangeRequest(const ChangeRequest& other);
    /*------------------------------------------------------------
      Copy constructor that initializes a new ChangeRequest object
      as a copy of an existing ChangeRequest object.
    =============================================================*/

    bool initChangeRequest();
    /*------------------------------------------------------------
      Initializes the change request process.
    =============================================================*/
    void inputChangeRequest();
    /*------------------------------------------------------------
      Inputs a new change request.
    =============================================================*/
    ChangeRequest selectChangeRequest(const std::vector<ChangeRequest> &changeRequest);
    /*------------------------------------------------------------
      Selects an existing change request.
    =============================================================*/  
    void addChangeRequest(const std::string& requesterEmai,
                          const char* productReleaseInfoInput, 
                          const char* changeItem);
    /*------------------------------------------------------------
      Adds a new change request to the system.
      - requester: The requester associated with the change request (in).
      - dateOfRequest: The date the change request was made (in).
      - product: The product associated with the change request (in).
      - productRelease: The product release associated with the change request (in).
      - changeItem: The change item associated with the change request (in).
    =============================================================*/  

    ChangeRequest getNext(const ChangeRequest changeRequest); 
    /*------------------------------------------------------------
      Retrieves the next change request from the file.
      - requestObj: The request object to store the next request (out).
    =============================================================*/  

   void writeRequest(const ChangeRequest& requestObject);
    /*------------------------------------------------------------
      Writes a change request to the file.
      - requestObject: The change request object to write (in).
    =============================================================*/  

    void closeRequestFile();
    /*------------------------------------------------------------
      Closes the file for change requests.
    =============================================================*/  

    ChangeRequest& operator=(const ChangeRequest& other);
    /*------------------------------------------------------------
    Assignment Operator that assigns the values from one 
    ChangeRequest object to another.
  =============================================================*/

    void openRequestFile(const std::string &filename);
    /*------------------------------------------------------------
    Method that opens the specified file for writing and reading the change 
    request data.
    =============================================================*/


};
    void printChangeRequest(const ChangeRequest& cr);
    /*------------------------------------------------------------
      Marks the change request as closed by setting the isClosed 
      flag to true.
    =============================================================*/

#endif // CHANGE_REQUEST_H

