/*
 * Euclidean.h
 *
 *  Created on: 27/02/2010
 *      Author: Vinicius Lopes
 */

#ifndef __EXCEPTION_H__
#define __EXCEPTION_H__

#include<iostream>

using namespace std;

/**
 *  @author Vinicius Lopes
 *  @since 27/02/10
 *  @version 1.0
 */

/// Exception class throwed by the calculate method with one parameter of VI, NMI and CR classes
/** All the exception that occured in MOCLE is gonna be treated in this class*/
class Exception {
 public:
		/** Does nothing */
        Exception();

        /** Calculate the distance euclidean */
    	/** @return the distance euclidean beween the dois pattern passed to the method  */
        void showError();

 private:
        const char *cErrorMessage;

};

#endif
