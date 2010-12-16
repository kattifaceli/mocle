/*
 * Pearson.h
 *
 *  Created on: 27/02/2010
 *      Author: Valter
 */

#ifndef PEARSON_H_
#define PEARSON_H_

#include "Similarity.h"

/// Responsible to calculate the pearson correlation coefficient
/** Responsible to calculate the pearson correlation coefficient, this is made in calculate method */
class Pearson:public Similarity {
public:
	Pearson();
	virtual ~Pearson();

	/** Calculate the pearson correlation coefficient. */
	/** @return the pearson correlation coefficient */
	double calculate(const vector<double> &vectorPattern_1, const vector<double> &vectorPattern_2);


};

#endif /* PEARSON_H_ */
