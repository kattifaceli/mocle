/*
 * Deviation.cpp
 *
 *  Created on: 12/03/2010
 *      Author: Gustavo
 */

#include "Deviation.h"


Deviation::Deviation() { }

Deviation::~Deviation() { }

double Deviation::calculate(Partition *pAPartition, RelationSDN *pARelation, DataSet *pADataset){

	double dDev = 0;

    vector<string>::iterator itObjectsCluster;

    map<string, vector<double> >::iterator itMapVector;
// colocar algo como:    itDataSet itMapVector; // - katti

    map<string, vector<double> > mapVector = pADataset->getMapVector();
	Similarity *similarity = pARelation->getSimilarity();

	//walk all cluster from partition
// nesse for, usar o itCluster
// for (itCluster it = pPartition.begin(); it != ....
	for(int i = 0; i < (int)pAPartition->getVectorObjCluster().size(); i++){

		vector<double> centroid = pAPartition->getCentroidInCluster((pAPartition->getVectorObjCluster()[i]).getLabel());
		vector<string> objectsCluster = pAPartition->getObjectsInCluster( (pAPartition->getVectorObjCluster()[i]).getLabel());

		/// calculate the summed distances for each pattern of a cluster
	 	for(itObjectsCluster = objectsCluster.begin(); itObjectsCluster != objectsCluster.end(); itObjectsCluster++){
			itMapVector = mapVector.find((*itObjectsCluster));
			dDev += similarity->calculate(itMapVector->second, centroid);
		}

	}
	return dDev;
}

double Deviation::calculate(Partition &objPartition1, Partition &objPartition2){

}
