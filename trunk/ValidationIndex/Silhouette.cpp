/*
 * Silhouette.cpp
 *
 *  Created on: 22/03/2010
 *      Author: Gustavo
 */

#include "Silhouette.h"

Silhouette::Silhouette() {
	// TODO Auto-generated constructor stub
}

Silhouette::~Silhouette() {
	// TODO Auto-generated destructor stub
}

double Silhouette::calculate(Partition *pAPartition, RelationSDN *pARelation, DataSet *pADataset){

	//Declaration variables used by Silhouette
	double silhouette = 0;
	Similarity *pObjSimilarity = pARelation->getSimilarity();
	vector<string>::iterator itVectorObjectsOnCluster;
	map<string, vector<double> >::iterator itMapVector1;
	map<string, vector<double> >::iterator itMapVector2;

	//Inicialization of function a(xi)
	//<Cluster Label, <Object, distance value from all objects of same cluster> >
	map<int, vector <pair<string, double> > > aXi;

	//Walk vector of all clusters
	for(int i = 0; i < (int)pAPartition->getVectorObjCluster().size(); i++){
		//For each object of cluster, calculate distance with other objects  from same cluster
		vector<string> vObjects = pAPartition->getObjectsInCluster( pAPartition->getVectorObjCluster()[i].getLabel());
		vector <pair<string, double> > vectorAuxObject; //<rotule object, average (di)similarity from others objects from same cluster>

		//Walk each object of cluster
		for(itVectorObjectsOnCluster = vObjects.begin(); itVectorObjectsOnCluster != vObjects.end(); itVectorObjectsOnCluster++){

			itMapVector1 = pADataset->getMapObjects().find( (*itVectorObjectsOnCluster) ); //Find value attributes from objects of Cluster itMapObCluster

			double result = 0;
			vector<string>::iterator itVectorObjectsOnCluster2;

			//walk other objects from same cluster with itVObjects
			for(itVectorObjectsOnCluster2 = vObjects.begin(); itVectorObjectsOnCluster2 != vObjects.end(); itVectorObjectsOnCluster2++){

				if( (*itVectorObjectsOnCluster2) != (*itVectorObjectsOnCluster) ){ //check if don't are same object
					itMapVector2 = pADataset->getMapObjects().find( (*itVectorObjectsOnCluster2) ); //find value attributes from objects distinct of same Cluster
					result += pObjSimilarity->calculate(itMapVector1->second, itMapVector2->second);
				}
			}

			pair<string, double> pairAux; //<rotule object, average (di)similarity from others objects from same cluster>
			pairAux.first = (*itVectorObjectsOnCluster);
			pairAux.second = result / vObjects.size(); //average (size Cluster) (di)similarity
			vectorAuxObject.push_back(pairAux);
		}

		//<Cluster label < vector<rotule object, distance from others objects from same cluster> >
		pair<int, vector <pair<string, double> > > auxPairMap;
		auxPairMap.first = pAPartition->getVectorObjCluster()[i].getLabel();
		auxPairMap.second = vectorAuxObject;
		aXi.insert(auxPairMap);
	}

	//Inicialization of function a(xi)
	//<Cluster Label, <Object, value less distance from all objects of distinct cluster> >
	map<int, vector <pair<string, double> > > bXi;

	//Walk vector of all clusters
	for(int i = 0; i < (int)pAPartition->getVectorObjCluster().size(); i++){
		//For each object of cluster, calculate distance with other objects from other cluster

		vector<string> vObjects = pAPartition->getObjectsInCluster( pAPartition->getVectorObjCluster()[i].getLabel() );
		vector <pair<string, double> > vectorAuxObject;

		//Walk each object of cluster itMapObCluster
		for(itVectorObjectsOnCluster = vObjects.begin(); itVectorObjectsOnCluster != vObjects.end(); itVectorObjectsOnCluster++){
			itMapVector1 = pADataset->getMapObjects().find( (*itVectorObjectsOnCluster) );

			double less, result = 0;
			vector<string>::iterator itVectorObjectsOnCluster2;

			//Walk others Clusters
			for(int j = 0; j < (int)pAPartition->getVectorObjCluster().size(); j++){

				//if is calculated from same cluster
				if(pAPartition->getVectorObjCluster()[i].getLabel() != pAPartition->getVectorObjCluster()[j].getLabel()){
					vector<string> vObjects2 = pAPartition->getObjectsInCluster( pAPartition->getVectorObjCluster()[j].getLabel());

					//calculated distance from all objects other clusters
					for(itVectorObjectsOnCluster2 = vObjects2.begin(); itVectorObjectsOnCluster2 != vObjects2.end(); itVectorObjectsOnCluster2++){

						itMapVector2 = pADataset->getMapObjects().find( (*itVectorObjectsOnCluster2) );

						if(itVectorObjectsOnCluster2 == vObjects2.begin()){ //first object from vObjects
							less = pObjSimilarity->calculate(itMapVector1->second, itMapVector2->second);
						}else{
							result = pObjSimilarity->calculate(itMapVector1->second, itMapVector2->second);
							if(result < less){
								less = result;
							}
						}
					}
				}
			}

			pair<string, double> pairAux;
			pairAux.first = (*itVectorObjectsOnCluster);
			pairAux.second = less / vObjects.size();
			vectorAuxObject.push_back(pairAux);
		}

		pair<int, vector <pair<string, double> > > auxPairMap;
		auxPairMap.first = pAPartition->getVectorObjCluster()[i].getLabel();
		auxPairMap.second = vectorAuxObject;
		bXi.insert(auxPairMap);
	}

	//Cluster label, <object, silhouette object>
	map<int, vector<pair<string, double> > >sXi;

	map<int, vector <pair<string, double> > >::iterator itAXi;
	map<int, vector <pair<string, double> > >::iterator itBXi = bXi.begin();

	//Walk result of a(xi) together results of b(xi)
	for(itAXi = aXi.begin(); itAXi != aXi.end(); itAXi++){
		vector<pair<string, double> > auxVectorSXi;

		vector<pair<string, double> > vectorObjectsAXi = itAXi->second;
		vector<pair<string, double> > vectorObjectsBXi = itBXi->second;
		vector<pair<string, double> >::iterator itVectorObjectsAXi;
		vector<pair<string, double> >::iterator itVectorObjectsBXi = vectorObjectsBXi.begin();

		//Walk objects from a(xi) with objects b(xi)
		for(itVectorObjectsAXi = vectorObjectsAXi.begin(); itVectorObjectsAXi != vectorObjectsAXi.end(); itVectorObjectsAXi++){

			double sXi;
			//TRECHO PARA  VERIFICAR!!!
			if(itVectorObjectsAXi->second < itVectorObjectsBXi->second){
				sXi = 1 - (itVectorObjectsAXi->second / itVectorObjectsBXi->second);
			}else{
				if(itVectorObjectsAXi->second == itVectorObjectsBXi->second){
					sXi = 0;
				}else{
					sXi = (itVectorObjectsBXi->second / itVectorObjectsAXi->second ) - 1;
				}
			}

			itVectorObjectsBXi++;

			//<rotule object, value silhouette>
			pair<string, double> auxSXi;
			auxSXi.first = itVectorObjectsAXi->first;
			auxSXi.second = sXi;
			auxVectorSXi.push_back(auxSXi);
		}

		itBXi++;

		//<Cluster label, < rotule object, value silhouette> >
		pair<int, vector<pair<string, double> > > newMapSXi;
		newMapSXi.first = itAXi->first;
		newMapSXi.second = auxVectorSXi;
		sXi.insert(newMapSXi);
	}


	//<Cluster label, silhouette average this cluster>
	vector<pair<int, double> > valueSilClusters;
	map<int, vector<pair<string, double> > >::iterator itSXi;

	//Walk on s(xi) results
	for(itSXi = sXi.begin(); itSXi != sXi.end(); itSXi++){
		vector<pair<string, double> >::iterator itAuxSxi;
		double resultCluster = 0;

		for(itAuxSxi = itSXi->second.begin(); itAuxSxi != itSXi->second.end(); itAuxSxi++){
			resultCluster += itAuxSxi->second;
		}

		resultCluster = resultCluster / itSXi->second.size();

		//<Cluster label, silhouette average this cluster>
		pair<int, double> auxValueSilClusters;
		auxValueSilClusters.first = itSXi->first;
		auxValueSilClusters.second = resultCluster;

		valueSilClusters.push_back(auxValueSilClusters);
	}

	vector<pair<int, double> >::iterator itValueSilClusters;
	for(itValueSilClusters = valueSilClusters.begin(); itValueSilClusters != valueSilClusters.end(); itValueSilClusters++){
		silhouette += itValueSilClusters->second;
	}

	return silhouette / valueSilClusters.size();
	//# VERIFICAR SE EH DIVIDIDO PELO NUMERO DE CLUSTERS!

}

double Silhouette::calculate(Partition &obPartition1, Partition &obPartition2){

}

