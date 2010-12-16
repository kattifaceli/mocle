/*
 * RelationSDN.cpp
 *
 *  Created on: 12/03/2010
 *      Author: Gustavo
 */

#include "RelationSDN.h"

RelationSDN::RelationSDN() {
	// TODO Auto-generated constructor stub
}

RelationSDN::~RelationSDN() {
	// TODO Auto-generated destructor stub
}

RelationSDN::RelationSDN(SimilarityMatrix objASimilarityMatrix, NnList objANnList, Similarity *pAObjSimilarity){
	objSimilarityMatrix = objASimilarityMatrix;
	objNnList = objANnList;
	objSimilarity = pAObjSimilarity;
}

SimilarityMatrix RelationSDN::getSimilarityMatrix(){
	return objSimilarityMatrix;
}


Similarity* RelationSDN::getSimilarity(){
	return objSimilarity;
}

NnList RelationSDN::getNnList(){
	return objNnList;
}

void RelationSDN::setSimilarityMatrix(map<string, map <string, double> > mapObjMap){
	objSimilarityMatrix.setMatrix(mapObjMap);
}

void RelationSDN::setSimilarity(Similarity *pAObjSimilarity){
	objSimilarity = pAObjSimilarity;
}

void RelationSDN::setNnList(map<string, map <string, double> > mapObjMap){
	objNnList.setNnList(mapObjMap);
}

