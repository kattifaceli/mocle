/*
 * KMeans.cpp
 *
 *  Created on: 16/12/2010
 *      Author: Gustavo Henrique Rodrigues Pinto Tomas
 */

#include "KMeans.h"

KMeans::KMeans() {
	// TODO Auto-generated constructor stub

}

KMeans::~KMeans() {
	// TODO Auto-generated destructor stub
}

Partition KMeans::run(SettingsAlgorithm *pASettingsAlgorithms, DataSet *pADataSet, Similarity *pASimilarity){

	//Declaration variables used by KMeans
	int changed = 0; //flag that indicates whether there was a change in the centroids of clusters
	int clusterObject; //Indicate Which object belongs to this cluster
	int iNumFeatures = pADataSet->getNumberOfFeature();

	map<string, vector<double> > objObjectsDataSet = pADataSet->getMapVector();
	map<string, vector<double> >::iterator itObjects;
	Partition::itCluster itCluster;

	SettingsAlgorithmKMeans *pSettingsAlgorithmKMeans = dynamic_cast <SettingsAlgorithmKMeans*> (pASettingsAlgorithms);

	if (pSettingsAlgorithmKMeans == NULL){
		cout << "erro no cast" << endl;
		//Lançar excecao!
	}

	Partition *pPartitionKmeans = new Partition("KMeans", pSettingsAlgorithmKMeans->getK(), iNumFeatures);

	do{
		changed = 0;

		//traversing all objects in the dataset
		for (itObjects = objObjectsDataSet.begin(); itObjects != objObjectsDataSet.end(); itObjects++){
			double minDistance = DISTANCE;
			clusterObject = -2;

			//calculate the distance of the cluster centroids of all this object
			for(itCluster = pPartitionKmeans->begin(); itCluster != pPartitionKmeans->end(); itCluster++){
				double distance = pASimilarity->calculate(itObjects->second, itCluster->getVectorCentroids() );

				if(distance < minDistance){
					minDistance = distance;
					clusterObject = itCluster->getLabel();
				}
			}

			//case have this object changed cluster
			if(clusterObject != pPartitionKmeans->getLabelClusterObjet(itObjects->first)){
				pPartitionKmeans->exchangeObject(itObjects->first, clusterObject);
				changed = 1;
			}
		}

		pPartitionKmeans->calculateCentroid(pADataSet);
	} while (changed );

	pPartitionKmeans->calculateNumberOfObjectsPartition();
	return *pPartitionKmeans;
}
