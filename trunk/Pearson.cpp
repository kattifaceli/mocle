/*
 * Pearson.cpp
 *
 *  Created on: 27/02/2010
 *      Author: Valter
 */

#include "Pearson.h"

Pearson::Pearson() {
	// TODO Auto-generated constructor stub
}

Pearson::~Pearson() {
	// TODO Auto-generated destructor stub
}

double Pearson::calculate(const vector<double> &vectorPattern_1, const vector<double> &vectorPattern_2) {

	int i, iSize;
	double dCorrelation = 0;
	double dAverage1 = 0, dAverage2 = 0, dS1 = 0, dS2 = 0, dS3 = 0;

	iSize = vectorPattern_1.size();
	if (iSize != (int)vectorPattern_2.size()) {
		cout << "Patterns should have the same size." << std::endl;
		return -1;
	}

	// calculate the dAverage of each pattern
	for (i = 0; i < iSize; i++) {
		dAverage1 += vectorPattern_1[i];
		dAverage2 += vectorPattern_2[i];
	}

	dAverage1 /= iSize;
	dAverage2 /= iSize;

	for (i = 0; i < iSize; i++) {
		dS1 += (vectorPattern_1[i] - dAverage1) * (vectorPattern_2[i] - dAverage2);
		dS2 += (vectorPattern_1[i] - dAverage1) * (vectorPattern_1[i] - dAverage1);
		dS3 += (vectorPattern_2[i] - dAverage2) * (vectorPattern_2[i] - dAverage2);
	}

	if (dS2 * dS3 == 0) {
		dCorrelation = 0;
	} else {
		dCorrelation = (dS1 / (sqrt(dS2 * dS3)));
	}

	return dCorrelation;

}
