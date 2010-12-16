/*
 * Partition.h
 *
 *  Created on: 09/02/2010
 *      Author: Valter
 */

#ifndef PARTITION_H_
#define PARTITION_H_


#include <boost/filesystem.hpp>
#include <sstream>
#include <time.h>

#include "DataSet.h"

/**
 *  @author Valter Henrique, Vinicius Lopes, Gustavo Henrique, Katti Facelli
 *  @since 09/02/10
 *  @version 2.0
 */

/// Responsible to manage the partition file into the memory
/** Colocar um comentário mais detalhado na classe dataset */
class Partition {

private:
	/// Each element in the dataset is allocated in one cluster
	/** Colocar um comentário mais detalhado na classe partition->cluster */
	class Cluster {
	private:
		int iLabel; ///< label that indicated where is the element , in which cluster
		vector<double> vectorCentroid; ///< a vector that will receive the centroids of each cluster
		vector<string> vectorObjects; ///< a vector that will receive the objects in the dataset , the objects is the ID

	public:
		/** Does nothing */
		/** @param Don't have any parameter */
		Cluster();

		/// One constructor that will initialize the label in that the element
		Cluster(int iACluster, string sAID);

		/** Add the ID in the vector of ID */
		/** @param  string sID */
		/** @return Don't have. */
		void addObject(string sAID);

		/** Calculate the centroid of a dataset passed in the argument DataSet  */
		/** @param  */
		/** @return Don't have. */
		/** @see calcCentroid(DataSet &obADataSet, fs::path pathADataSet)*/
		void calculateCentroid(DataSet *pAObjDataSet);

		/** Returns in which cluster in allocated some ID */
		/** @param Don't have  */
		/** @return iLabel */
		int getLabel();

		/** Returns the quantity of IDs has  */
		/** @param  Don't have.*/
		/** @return Don't have. */
		int getNumberOfObjects();

		/** Returns the begin of the vector that has the ID's*/
		vector<string>::iterator objectsItBegin();

		/** Returns the end of the vector that has the ID's*/
		vector<string>::iterator objectsItEnd();

		/** Return vector of objects from cluster */
		/** @param Don't have  */
		/** @return vector<string> */
		vector<string> getVectorObjects();

		/** Return centroids calculate from cluster */
		/** @param Don't have  */
		/** @return vector<double> */
		vector<double> getVectorCentroids();

	};


	int iNumObjects; ///< the quantity of objects existing in the partition
	int iNumClusters; ///< the quantity of clustes existing in the partition
	string sPathPartition; ///< the path to the partition
	string sNamePartition; ///< the name of the partition
	

	map<string, int> mapObjects; ///< the key of the map (string) is the 'name' of the object and the value  (int) is the cluster that object belong */
	vector<Cluster> vectorObjCluster; ///< a vector of Cluster's

	fs::path pathPartition; ///< the path to the partition in the computer

	typedef vector<Cluster>::iterator itCluster;

	itCluster begin(){
		return vectorObjCluster.begin();
	}

	itCluster end(){
		return vectorObjCluster.end();
	}

public:


	/** Does nothing */
	/** @param Don't have any parameter */
	Partition(string sAPathPartition, string sANamePartition);
	virtual ~Partition();

	/** Calculate the centroid of the cluster  */
	/** @param Don't have */
	/** @see calculateCentroid(DataSet &obADataSet) */
	void calculateCentroid(DataSet *pAObjDataSet);

	/** charge to the partition in the memory, passing in the argument the path to load the partition in memory, passing as argument the path to the partition  */
	/** @param  pathAPartition */
	/** @return Don't have. */
	void loadPartition();

	/** Generates a random partition, receiving as parameter a point to the object of the dataset  */
	/** @param  *obADataSet */
	/** @return Don't have */
	void generateRandomPartition(DataSet *pAObjDataSet);

	/** Generates a random partition, grouping the objects in the same cluster,receiving as parameter a point to the object of the dataset  */
	/** @param  *obADataSet */
	/** @return Don't have */
	void generatePartitionGroupCluster(DataSet *pAObjDataSet);

	/** Print the labels of the partition  */
	void printClusterLabels();

	// # este método só foi criado para demonstrar a simplificade do iterador que adaptamos
	void printClusters();

	// # Mostra os valores do centróides de todos os clusters
	void showCentroids();

	/** write the partition in disk, passing in the argument the path where the user want to save  */
	/** @param  pathSaveIn */
	/** @return Don't have. */
	void writePartition();

	/** Returns a specific cluster passing as argument the position where he is allocated */
	/** @param int iPos */
	Cluster & getCluster(int iAPos);

	/** Returns the number of cluster existing cluster on the partition, loaded in the loadPartition()  */
	/** @param Don't have */
	/** @return iNumClusters */
	/** @see loadPartition(fs::path pathAPartition), iNumClusters */
	int getNumClusters();

	/** Returns the number of existing objects on the partition, loaded in the loadPartition()  */
	/** @param Don't have */
	/** @see loadPartition(fs::path pathAPartition) */
	int getNumObjects();

	/** Returns	mObjects */
	/** @param Don't have */
	/** @return map<string, int> mObjects */
	map<string, int> getMObjects();

	/** Returns	vectorObjects, that contains objects of cluster type */
	/** @param Don't have */
	/** @return vector<Cluster> vObCluster */
	vector<Partition::Cluster> getVObjects();

	/** Returns the cluster's label of parameter sObject   */
	/** @param sObject indicated the object label */
	/** @return Cluster's label */
	int getLabelClusterOf(string sAObject);

	/** Returns the vector all clusters of partition   */
	/** @param Don't have */
	/** @return vector<Cluster> */
	vector<Partition::Cluster> getVectorObjCluster();

	/** Returns the rotule objects in ClusterLabel*/
	/** @param Cluster Label */
	/** @return vector<string>*/
	vector<string> getObjectsInCluster(int ClusterLabel);

	/** Returns the centroid of Cluster*/
	/** @param Cluster Label */
	/** @return vector<double> */
	vector<double> getCentroidInCluster(int ClusterLabel);

};

#endif /* PARTITION_H_ */
