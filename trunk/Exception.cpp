/*
 * Euclidean.h
 *
 *  Created on: 27/02/2010
 *      Author: Vinicius Lopes
 */

#include"Exception.h"


/* Implementation of Exception methods */

Exception::Exception() : cErrorMessage("Invalid Method Called"){}

void Exception::showError(){
    cout << cErrorMessage << endl;
}

