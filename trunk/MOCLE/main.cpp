/*
 * main.cpp
 *
 *  Created on: 03/11/2009
 *      Author: Valter
 */

#include <boost/filesystem.hpp>

#include <iostream>

#include "DataSet.h"
#include "Euclidean.h"
#include "NnList.h"
#include "Partition.h"
#include "Pearson.h"
#include "RelationSDN.h"
#include "Similarity.h"
#include "ValidationIndex.h"
#include "ValidationIndex/Connectivity.h"
#include "ValidationIndex/CRIndex.h"
#include "ValidationIndex/Deviation.h"
#include "ValidationIndex/NMIIndex.h"
#include "ValidationIndex/Silhouette.h"
#include "ValidationIndex/VIIndex.h"

namespace fs = boost::filesystem;
using namespace std;

/** @mainpage MOCLE
 *
 * \section intro_sec Introduction
 *
 * A brief introduction about MOCLE system.
 *
 * \section install_sec Installation
 *
 * \subsection step1 Step 1: How install MOCLE
 *
 * What do to install and use MOCLE ..
 *
 * \author Katti Facelli
 *
 *
 */

int main() {

	string sDataSet;

	// user will define the file (dataset) that will be processed by MOCLE
	//	cout << "Inform the name of the dataset" << endl;
	//	cout << ">> ";
	//	cin >> sDataSet;

	// # o usuário irá definir o dataset a ser processado pelo MOCLE
	string sPathDataSet = "/home/Valter/Dropbox/Workspace/Iniciação Científica/Valter/Dataset/";

	// # apagar esta atribuição, e descomentar as acima, deixando assim apenas para não ter de digitar toda vez
	sDataSet = "simpsons.txt";
	//sPathDataSet += sDataSet;

	// creating a path to the dataset
	fs::path pathDataSet(sPathDataSet+sDataSet);

	// checking if the path and the file exist
	bool pathExist = fs::exists(pathDataSet);

	// if exist then the system can continue with the process
	DataSet *pObjDataSet;
	if (pathExist == true) {

		pObjDataSet = new DataSet(sPathDataSet, sDataSet);

		cout << " -- DataSet -- " << endl;
		cout << "Number of objects in dataset " << pObjDataSet->getNumberOfObjects() << endl;
		cout << "Number of feature in dataset " << pObjDataSet->getNumberOfFeature() << endl;

		Similarity *pEuclidean = new Euclidean();
		Similarity *pPearson = new Pearson();

		pObjDataSet->addNewRelationSDN(pEuclidean);
		pObjDataSet->addNewRelationSDN(pPearson);

	// if don't exist the informed path or file
	} else
		cout << "The informed path to the DATASET don't exist!" << endl << "Please, check your dataset path." << endl;


	// Testing the partitions
	string sPartition;

	// user will define the partition that he want it to be processed by MOCLE
	//	cout << "Inform the partition" << endl;
	//	cout << ">> ";
	//	cin >> sPartition;

	// user will define the path to the partition
	string sPathPartition = "/home/Valter/Dropbox/Workspace/Iniciação Científica/Valter/Partition/";

	// # pode apagar a atribuição abaixo, sendo a mesma apenas para não ter repetição na entrada dos dados
	sPartition = "simpsons.clu";
	//sPathPartition += sPartition;

	fs::path pathPartition(sPathPartition + sPartition);

	// checking if the path and the file exist
	pathExist = fs::exists(pathPartition);

	// is not possible a calculate a centroid without a dataset, so we gonna calculate the centroid
	if (pathExist == true) {
		Partition *pObjPartition = new Partition(sPathPartition, sPartition);

		cout << endl << " -- Partition -- " << endl;
		cout << "Number of objects in partition: " << pObjPartition->getNumObjects() << endl;
		cout << "Number of clusters in partition: " << pObjPartition->getNumClusters() << endl;

	//	pObjPartition->generateRandomPartition(pObjDataSet);
	//	pObjPartition->generatePartitionGroupCluster(pObjDataSet);
	//	pObjPartition->writePartition();
	//	pObjPartition->calcCentroid(pObjDataSet);

		pObjPartition->calculateCentroid(pObjDataSet);
		
		cout << endl << " -- Clusters -- " << endl;
		pObjPartition->showCentroids();

		cout << endl << "Label dos cluster >> ";
		pObjPartition->printClusterLabels();

		//# aqui estou chamando o método para exibir os rótulos dos clusters utilizando o iterator que adaptamos
		cout << endl << "My iterator >> " ;
		pObjPartition->printClusters();

		cout << endl << " -- Measures of internal validation -- " << endl << endl;
		double dResult = 0;
		Deviation objDeviation;
		Connectivity objConnectivity(0.05);
		Silhouette objSilhouette;

		cout << " --> Euclidean: " << endl;
		RelationSDN *pRelationEuclidean = pObjDataSet->getRelation(0);

		dResult = objDeviation.calculate(pObjPartition,pRelationEuclidean,pObjDataSet);
		cout << "  Deviation: " << dResult << endl;

		dResult = objConnectivity.calculate(pObjPartition,pRelationEuclidean,pObjDataSet);
		cout << "  Connectivity: " << dResult << endl;

		dResult = objSilhouette.calculate(pObjPartition,pRelationEuclidean,pObjDataSet);
		cout << "  Silhouette: " << dResult << endl << endl;

		cout << " --> Pearson: " << endl;
		RelationSDN *pRelationPearson = pObjDataSet->getRelation(1);

		dResult = objDeviation.calculate(pObjPartition,pRelationPearson,pObjDataSet);
		cout << "  Deviation: " << dResult << endl;

		dResult = objConnectivity.calculate(pObjPartition,pRelationPearson,pObjDataSet);
		cout << "  Connectivity: " << dResult << endl;

		dResult = objSilhouette.calculate(pObjPartition,pRelationPearson,pObjDataSet);
		cout << "  Silhouette: " << dResult << endl << endl;

		string sPartition1 = "teste100_K10_0.clu";
		string sPartition2 = "teste100_K10_20.clu";

		fs::path pathPartition1(sPathPartition + sPartition1);
		fs::path pathPartition2(sPathPartition + sPartition2);

		pathExist = fs::exists(pathPartition1);

		if (pathExist) {
			pathExist = fs::exists(pathPartition2);
			if (pathExist) {

				cout << " ** Path da partition >> " << pathPartition2.directory_string() << endl;
				
				Partition objPartition1(sPathPartition, sPartition1);
				Partition objPartition2(sPathPartition, sPartition2);

				CRIndex obCRIndex;
				VIIndex obVIIndex;
				NMIIndex obNMIIndex;

				cout << endl << " -- Measures of external validation -- "<< endl << endl;
				cout << "CRIndex: " << obCRIndex.calculate(objPartition1, objPartition2) << endl;
				cout << "VIIndex: " << obVIIndex.calculate(objPartition1, objPartition2) << endl;
				cout << "NMIIndex: " << obNMIIndex.calculate(objPartition1, objPartition2) << endl;
				cin.get();

			}
		}

	} else
		cout << "The informed path to the PARTITION don't exist " << endl << "Please, check the partion path." << endl;


	return 0;
}

