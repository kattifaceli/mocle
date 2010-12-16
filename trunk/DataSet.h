/*
 * DataSet.h
 *
 *  Created on: 01/02/2010
 *      Author: Valter
 */

#ifndef DATASET_H_
#define DATASET_H_

#include <boost/filesystem.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/tokenizer.hpp>

#include <fstream>
#include <iostream>
#include <string>

#include <map>
#include <utility>
#include <vector>

#include "Euclidean.h"
#include "Pearson.h"
#include "Similarity.h"
#include "RelationSDN.h"

using namespace std;
using namespace boost;
namespace fs = boost::filesystem;

/**
 *  @author Valter Henrique, Gustavo Henrique
 *  @since 01/02/10
 *  @version 2.0
 */

/// Responsible to manage the dataset file into the memory
/** Dataset class is responsible to inform the data to MOCLE */
class DataSet {

private:
	int iNumObjects; ///< the quantity of objects in the dataset
	int iNumFeatures; ///< the quantity of features in the dataset

	string sPathToDataSet;
	string sNameDataSet; ///< the name of the dataset file

	vector <string> vectorElements; ///< receive just the index of the elements in the dataset file
	vector<RelationSDN*> vectorRelations;
	vector<Similarity *> vectorObSimilarity;

public:
	map<string, vector<double> > mapObjects; ///< all the values found in the archive of interest will be put in the memory for future process

	typedef map<string, vector<double> >::iterator itDataSet;
	typedef vector <double>::iterator itObject;
	typedef vector <string>::iterator itElements;

	/** Does nothing */
	/** @param Don't have any parameter */
	DataSet();

	/** Ask to the user what kind format is the dataset then choose a specific method to pass the dataset to memory of the computer  */
	/** @param the path to the dataset in the computer */
	DataSet(string sPathADataSet, string sANameDataSet);
	virtual ~DataSet();

	/** Generate the Distance matrix get in the dataset file to the memory */
	/** @param Object similarity  */
	/** @return Matrix map  */
	map<string, map <string, double> > generateMatrix(Similarity *pAObSimilarity);

	/** Read the file passed in the argument pathADatSet and allocate in the memory */
	/** @param pathADataSet receive the path from the dataset  */
	void tabulateMappingDataSet();

	/** Returns the number of features existing in dataset*/
	/** @return iNumFeatures */
	int getNumberOfFeature();

	/** Returns the number of objects existing in dataset*/
	/** @return iNumFeatures */
	int getNumberOfObjects();

	string getNameDataSet();

	/** Returns the dataset mapped int th struct */
	/** @return pathToDataSet*/
	map<string, vector<double> > getMapVector();

	fs::path getPathToDataSet();

	/** Return pointer for vector RelationSDN*/
	/** @param Position of vector  */
	/** @return RelationSDN* */
	RelationSDN* getRelation(int iAPosRelation);

	/** Add new object RelationSDN in vectorRelations vector*/
	/** @param Object similarity  */
	/** @return Don't have */
	void addNewRelationSDN( Similarity *pAObSimilarity);

	/** Set the name of the dataset file*/
	/** @param String sANameDataset */
	/** @return Don't have */
	void setNameDataSet(string sANameDataSet);

	itDataSet getMapObjectsBegin(){
		return mapObjects.begin();
	}

	itDataSet getMapObjectsEnd(){
		return mapObjects.end();
	}

	itElements getVectorElementsBegin(){
		return vectorElements.begin();
	}

	itElements getVectorElementsEnd(){
		return vectorElements.end();
	}


};

#endif /* DATASET_H_ */
