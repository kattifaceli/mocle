/*
 * SettingsAlgorithmCentroidLink.cpp
 *
 *  Created on: 16/12/2010
 *      Author: Gustavo Henrique Rodrigues Pinto Tomas
 */

#include "SettingsAlgorithmCentroidLink.h"

SettingsAlgorithmCentroidLink::SettingsAlgorithmCentroidLink(int iAK) {
	// TODO Auto-generated constructor stub
	this->iK = iAK;
}

SettingsAlgorithmCentroidLink::~SettingsAlgorithmCentroidLink() {
	// TODO Auto-generated destructor stub
}

int SettingsAlgorithmCentroidLink::getK() {
	// TODO Auto-generated destructor stub
	return this->iK;
}

void SettingsAlgorithmCentroidLink::setK(int iAK) {
	// TODO Auto-generated destructor stub
	this->iK = iAK;
}
