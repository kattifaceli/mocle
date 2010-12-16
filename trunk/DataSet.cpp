/*
 * DataSet.cpp
 *
 *  Created on: 01/02/2010
 *      Author: Valter
 */

#include "DataSet.h"

DataSet::DataSet(string sPathADataSet, string sANameDataSet) {
	string sFormat;

	sPathToDataSet = sPathADataSet;
	sNameDataSet = sANameDataSet;

	// this field the user define the intern format from the dataset
	// # estender para csv, excel, e outros tipos existentes

	//	cout << "Inform the intern format from the dataset" << endl;
	//	cout << ">> ";
	//	cin >> sFormat;

	// # aqui chamar o método que irá 'mapear' o dataset dependendo do formato interno fornecido pelo usuário
	// # para não ter de ficar fornecendo em todo teste
	sFormat = "tabulate";
	if (sFormat == "tabulate")
		tabulateMappingDataSet();
}

DataSet::~DataSet() {}

vector <string> DataSet::getVElements(){
	return vectorElements;
}

RelationSDN* DataSet::getRelation(int iAPosRelation){
	return vectorRelations[iAPosRelation];
}

void DataSet::addNewRelationSDN( Similarity *pAObjSimilarity){
	RelationSDN *newRelation= new RelationSDN();

	map<string, map <string, double> > mapMatrix = generateMatrix(pAObjSimilarity);
	newRelation->setSimilarityMatrix(mapMatrix);
	newRelation->setNnList(mapMatrix);
	newRelation->setSimilarity(pAObjSimilarity);

	vectorRelations.push_back(newRelation);

}

map<string, map <string, double> > DataSet::generateMatrix(Similarity *pAObjSimilarity){
	double dResult;

	map<string, map <string, double> > mapMatrix;

	itDataSet itMapElement_1, itMapElement_2;

	for (vector<string>::iterator itVectorElement_1 = vectorElements.begin(); itVectorElement_1 != vectorElements.end(); ++itVectorElement_1){
		// receiving the map <Key, vector<double> > , where Key is from type string
		itMapElement_1 = mapObjects.find(*itVectorElement_1);

		for (vector<string>::iterator itVectorElement_2 = vectorElements.begin(); itVectorElement_2 != vectorElements.end(); ++itVectorElement_2){
			// receiving the map <Key, vector<double> > , where Key is from type string
			itMapElement_2 = mapObjects.find(*itVectorElement_2);

			dResult = pAObjSimilarity->calculate(itMapElement_1->second, itMapElement_2->second);
			mapMatrix[*itVectorElement_1][*itVectorElement_2] = dResult;

		}
	}

	return mapMatrix;

}

void DataSet::tabulateMappingDataSet() {
	string sPathDataSet = sPathToDataSet + sNameDataSet;
	string sIndexLine; // Take the 'index' to recognize the line of the data in the file of interest
	string sTemp;      // A temporaty variable to receive the line from the file
	double dNumber;	   // dNumber, in a double take itTokens from the file of interest


	cout << "sPathDataSet >> " << sPathDataSet;
	ifstream in(sPathDataSet.c_str());

	// taking the first line of file
	getline( in, sTemp );

	// define the separator to tokenize the string sTemp
	char_separator<char> sep("\t");

	while (	getline( in, sTemp ) ) {

		// define the tokenize
		tokenizer<char_separator<char> > tokens(sTemp, sep);

		// saving the first element of each line in map<string, > and the other element int map< ,vector<double>>
		for (tokenizer<char_separator<char> >::iterator itTokens = tokens.begin(); itTokens	!= tokens.end(); ++itTokens) {
			if (itTokens == tokens.begin()) {
				sIndexLine = *itTokens;
				vectorElements.push_back(sIndexLine);
			} else {
				// converting the string readed from file to double
				(istringstream(*itTokens) >> dNumber);
				mapObjects[sIndexLine].push_back(dNumber);
			}
		}
	}

	map<string, vector<double> >::iterator itMapVector = mapObjects.begin();
	iNumObjects = mapObjects.size();
	iNumFeatures = itMapVector->second.size();

	in.close();
}


int DataSet::getNumberOfFeature(){
	return iNumFeatures;
}

int DataSet::getNumberOfObjects(){
	return iNumObjects;
}

fs::path DataSet::getPathToDataSet(){
	return sPathToDataSet;
}

map<string, vector<double> > DataSet::getMapVector(){
	return mapObjects;
}

void DataSet::setNameDataSet(string sANameDataSet){
	sNameDataSet = sANameDataSet;
}

string DataSet::getNameDataSet(){
	return sNameDataSet;
}
