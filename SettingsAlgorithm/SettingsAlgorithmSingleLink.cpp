/*
 * SettingsAlgorithmSingleLink.cpp
 *
 *  Created on: 16/12/2010
  *      Author: Gustavo Henrique Rodrigues Pinto Tomas
 */

#include "SettingsAlgorithmSingleLink.h"

SettingsAlgorithmSingleLink::SettingsAlgorithmSingleLink(int iAK) {
	// TODO Auto-generated constructor stub
	this->iK = iAK;
}

SettingsAlgorithmSingleLink::~SettingsAlgorithmSingleLink() {
	// TODO Auto-generated destructor stub
}

int SettingsAlgorithmSingleLink::getK() {
	// TODO Auto-generated destructor stub
	return this->iK;
}

void SettingsAlgorithmSingleLink::setK(int iAK) {
	// TODO Auto-generated destructor stub
	this->iK = iAK;
}
