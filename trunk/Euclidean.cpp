/*
 * Euclidean.cpp
 *
 *  Created on: 27/02/2010
 *      Author: Valter
 */

#include "Euclidean.h"

Euclidean::Euclidean() {}

Euclidean::~Euclidean() {}

// this method calculates the eucledean distance from the elements informed in the dataset
double Euclidean::calculate(const vector<double> &vectorAPattern_1, const vector<double> &vectorAPattern_2){

	double dDistance = 0;

	if (vectorAPattern_1.size() != vectorAPattern_2.size()) {
		cout << "Patterns should have the same size." << endl;
		return -1;
	}

	for (int i = 0; i < (int)vectorAPattern_1.size(); i++) {
		dDistance += (vectorAPattern_1[i] - vectorAPattern_2[i]) * (vectorAPattern_1[i] - vectorAPattern_2[i]);
	}

	dDistance = sqrt(dDistance);

	return dDistance;

}
