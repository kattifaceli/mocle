/*
 * NnList.h
 *
 *  Created on: 12/03/2010
 *      Author: Gustavo
 */

#ifndef NNLIST_H_
#define NNLIST_H_

#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

/**
 *  @author Gustavo Rodrigues
 *  @since 12/03/10
 *  @version 2.0
 */

/** This class stores the nearest neighbors of all objects in the dataset according to  similarity and distance matrix of similarity */
class NnList {

private:
	vector <pair<string, vector<string> > > vectorNnList; ///< vector contain all objects with your's nearest neighbor

public:
	/** Does nothing */
	/** @param Don't have any parameter */
	NnList();
	virtual ~NnList();

	/** Set entire nearest neighbor list from dataset */
	/** @param Matrix map  */
	/** @return Don't have */
	void setNnList(map<string, map <string, double> > mapAObMap);

	/** Return the nearest neighbor list */
	/** @param Don't have  */
	/** @return Nearest neighbor list*/
	vector <pair<string, vector<string> > > getNnList();

	/** Return the nearest neighbor list of object sRotuloOBject */
	/** @param Rotulo of object  */
	/** @return Nearest neighbor list*/
	vector<string> getNnList(string sRotuloObject);
};

#endif /* NNLIST_H_ */
