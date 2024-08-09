// errors.h
/*------------------------------------------------------------
Revision History:
Rev. 1 - 2024/07/14 Original by Jae Hee Kim
--------------------------------------------------------------
This module is used to define common error messages.
This way, messages do not have to be repeated.
------------------------------------------------------------*/
#ifndef ERRORS_H
#define ERRORS_H


#include <stdexcept> // For std::logic_error
#include <string>    // For std::string

/*===========================================================*/  
class ERROR_message : public std::logic_error {

   public:
      // Constructor
      ERROR_message(const std::string& message = "");
}; 
/*------------------------------------------------------------
General error message class to throw errors
=============================================================*/ 
void ERROR_invalidSelection();
/*------------------------------------------------------------
Tells the user that an invalid selection has been chosen.
=============================================================*/  
void ERROR_invalidDataRange();
/*------------------------------------------------------------
Tells the user that their input has an invalid data range.
=============================================================*/  
void ERROR_invalidDataFormat();
/*------------------------------------------------------------
Tells the user that their input does not follow the correct format.
=============================================================*/
void ERROR_keyUniqueness();
/*------------------------------------------------------------
Tells the user that their input is not unique
=============================================================*/

#endif // ERRORS_H