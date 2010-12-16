/*
 * SimilarityMatrix.cpp
 *
 *  Created on: 10/02/2010
 *      Author: Valter
 */
#include "SimilarityMatrix.h"

SimilarityMatrix::SimilarityMatrix() {}

SimilarityMatrix::~SimilarityMatrix() {}

map<string, map <string, double> > SimilarityMatrix::getMatrix(){
	return mapMatrix;
}
void SimilarityMatrix::setMatrix(map<string, map <string, double> > mapAObjMap){
	map<string, map <string, double> >::iterator itMap;

	for(itMap = mapAObjMap.begin(); itMap != mapAObjMap.end(); itMap++ ){
		pair<string, map<string, double> > pairAux;
		pairAux.first = itMap->first;
		pairAux.second = itMap->second;
		mapMatrix.insert(pairAux);
	}
}

map<string, map <string, double> > SimilarityMatrix::getEuclideanMatrix(){
	return mapEuclidean;
}

map<string, map <string, double> > SimilarityMatrix::getPearsonMatrix(){
	return mapPearson;
}

void SimilarityMatrix::setEuclideanMatrix(map<string, map <string, double> > mapAEuclidean){
	mapEuclidean = mapAEuclidean;
}
void SimilarityMatrix::setPearsonMatrix(map<string, map <string, double> > mapAPearson){
	mapPearson = mapAPearson;
}
