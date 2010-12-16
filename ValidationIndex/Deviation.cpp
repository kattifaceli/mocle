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

	Similarity *pSimilarity = pARelation->getSimilarity();

	//walk all cluster from partition
	int iSize = (int)pAPartition->getVectorObjCluster().size();
	for(int i = 0; i < iSize ; i++){

		vector<double> centroid = pAPartition->getCentroidInCluster((pAPartition->getVectorObjCluster()[i]).getLabel());
		vector<string> objectsCluster = pAPartition->getObjectsInCluster( (pAPartition->getVectorObjCluster()[i]).getLabel());

		/// calculate the summed distances for each pattern of a cluster
	 	for(itObjectsCluster = objectsCluster.begin(); itObjectsCluster != objectsCluster.end(); itObjectsCluster++){
	 	    itMapVector = pADataset->mapObjects.find((*itObjectsCluster)); // # acessando diretamente a estrutura mapObjects da classe DataSet
			dDev += pSimilarity->calculate(itMapVector->second, centroid);
		}

	}
	return dDev;
}

double Deviation::calculate(Partition &objPartition1, Partition &objPartition2){

}
