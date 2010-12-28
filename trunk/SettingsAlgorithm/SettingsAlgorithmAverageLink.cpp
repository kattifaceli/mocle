/*
 * SettingsAlgorithmAverageLink.cpp
 *
 *  Created on: 16/12/2010
  *      Author: Gustavo Henrique Rodrigues Pinto Tomas
 */

#include "SettingsAlgorithmAverageLink.h"

SettingsAlgorithmAverageLink::SettingsAlgorithmAverageLink(int iAK) {
	// TODO Auto-generated constructor stub
	this->iK = iAK;
}

SettingsAlgorithmAverageLink::~SettingsAlgorithmAverageLink() {
	// TODO Auto-generated destructor stub
}

int SettingsAlgorithmAverageLink::getK() {
	// TODO Auto-generated destructor stub
	return this->iK;
}

void SettingsAlgorithmAverageLink::setK(int iAK) {
	// TODO Auto-generated destructor stub
	this->iK = iAK;
}
