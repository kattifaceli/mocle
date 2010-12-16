/*
 * Similarities.h
 *
 *  Created on: 01/02/2010
 *      Author: Valter
 */

#ifndef SIMILARITY_H_
#define SIMILARITY_H_

#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

/**
 *  @author Valter Henrique
 *  @since 01/02/10
 *  @version 2.0
 */

/// Responsible by management the measures of similarity
/** Responsible by management the measures of similarity, for example: Eucleadean Distance and Correlation Pearson */
class Similarity {
public:
	Similarity();
	virtual ~Similarity();

	/** Each similarity class has the method 'calculate' that calculates the measures of similarity especific to that purpose*/
	virtual double calculate(const vector<double> &vectorPattern_1, const vector<double> &vectorPattern_2) = 0;
};


#endif /* SIMILARITY_H_ */
