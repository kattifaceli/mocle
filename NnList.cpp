/*
 * NnList.cpp
 *
 *  Created on: 12/03/2010
 *      Author: Gustavo
 */

#include "NnList.h"

NnList::NnList() {
	// TODO Auto-generated constructor stub
}

NnList::~NnList() {
	// TODO Auto-generated destructor stub
}

vector <pair<string, vector<string> > > NnList::getNnList(){
	return vectorNnList;
}

void NnList::setNnList(map<string, map <string, double> > mapAObjMap){
	map<string, map <string, double> >::iterator itMap;
	map<string,double> mapElementsAux;
	map<string,double>::iterator itMapElementsAux;

	//walk similarity matrix
	for(itMap = mapAObjMap.begin(); itMap != mapAObjMap.end(); itMap++ ){
		mapElementsAux = (itMap->second);

		//Getting line with all objects and yours values
		vector<pair<double,string> >vectorTemp;
		for(itMapElementsAux = mapElementsAux.begin(); itMapElementsAux != mapElementsAux.end(); itMapElementsAux++){
			pair<double,string> pairAux;
			pairAux.first = itMapElementsAux->second;
			pairAux.second = itMapElementsAux->first;
			vectorTemp.push_back(pairAux);
		}

		sort(vectorTemp.begin(), vectorTemp.end());
		vector<pair<double,string> >::iterator itVectorTemp;
		vector<string> vectorNeighbors;
		for(itVectorTemp = vectorTemp.begin(); itVectorTemp != vectorTemp.end(); itVectorTemp++){
			vectorNeighbors.push_back(itVectorTemp->second);
		}
		pair<string, vector<string> > pairAuxNnList;
		pairAuxNnList.first = itMap->first;
		pairAuxNnList.second = vectorNeighbors;
		vectorNnList.push_back(pairAuxNnList);
	}
}


vector<string> NnList::getNnList(string sRotuloObject){
	vector <pair<string, vector<string> > >::iterator itNnList;
	itNnList = vectorNnList.begin();
	while( itNnList != vectorNnList.end() && itNnList->first != sRotuloObject){
		itNnList++;
	}

	return itNnList->second;

}
