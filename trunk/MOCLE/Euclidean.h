/*
 * Euclidean.h
 *
 *  Created on: 27/02/2010
 *      Author: Valter
 */

#ifndef EUCLIDEAN_H_
#define EUCLIDEAN_H_

#include "Similarity.h"

/**
 *  @author Valter Henrique
 *  @since 27/02/10
 *  @version 2.0
 */

/// This class is necessary to calculate the euclidean distance
/** This class is necessary to calculate the euclidean distance, this is made by method calculate */
class Euclidean:public Similarity {
public:
	Euclidean();
	virtual ~Euclidean();

	/** Calculate the distance euclidean */
	/** @return the distance euclidean beween the dois pattern passed to the method  */
	double calculate(const vector<double> &vectorAPattern_1, const vector<double> &vectorAPattern_2);
};

#endif /* EUCLIDEAN_H_ */
