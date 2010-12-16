/*
 * Connectivity.cpp
 *
 *  Created on: 12/03/2010
 *      Author: Gustavo
 */

#include "Connectivity.h"

Connectivity::Connectivity(float fASizeNn) {
	fSizeNn = fASizeNn;
}

Connectivity::~Connectivity() {
}

double Connectivity::calculate(Partition *pAPartition, RelationSDN *pARelation,	DataSet *pADataSet) {

	int iNPat = pADataSet->getNumberOfObjects();
	float fNn = ceil(iNPat * fSizeNn);
	int iNNearestNeighbors = int(fNn);
	double dSomaNN;
	double conn = 0;

	vector<string>::iterator itVectorElements;

	//Walk on all objects in dataset
	for (itVectorElements = pADataSet->getVectorElementsBegin(); itVectorElements	!= pADataSet->getVectorElementsEnd(); itVectorElements++) {

		dSomaNN = 0;

		//Find all nearest neighbors of itVectorElements
		vector<string> vectorNnListOfVElement = pARelation->getNnList().getNnList((*itVectorElements));

		for (int j = 0; j < iNNearestNeighbors; j++) {
			string sJNeighbors = vectorNnListOfVElement[j];

			//if object itVectorElements and J-Nearest Neighbor don't have same cluster
			if (pAPartition->getLabelClusterOf((*itVectorElements))
					!= pAPartition->getLabelClusterOf(sJNeighbors)) {
				dSomaNN += 1.0 / (j + 1);
			}
		}
		conn += dSomaNN;
	}
	return conn;
}

double Connectivity::calculate(Partition &objPartition1, Partition &objPartition2) {

}
