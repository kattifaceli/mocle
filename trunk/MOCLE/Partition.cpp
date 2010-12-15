/*
 * Partition.cpp
 *
 *  Created on: 09/02/2010
 *      Author: Valter
 */

#include "Partition.h"

Partition::Partition(string sAPathPartition, string sANamePartition) {
	sPathPartition = sAPathPartition;
	sNamePartition = sANamePartition;
	loadPartition();
}

Partition::~Partition() {}

void Partition::calculateCentroid(DataSet *pAObjDataSet) {
	for (int i = 0; i < (int)vectorObjCluster.size(); i++)
		vectorObjCluster[i].calculateCentroid(pAObjDataSet);
}

vector<string> Partition::getObjectsInCluster(int ClusterLabel){
	return vectorObjCluster[ClusterLabel].getVectorObjects();
}

vector<double> Partition::getCentroidInCluster(int ClusterLabel){
	return vectorObjCluster[ClusterLabel].getVectorCentroids();
}

vector<Partition::Cluster> Partition::getVectorObjCluster(){
	return vectorObjCluster;
}

int Partition::getLabelClusterOf(string sAObject){
	vector<string>::iterator itVectorObjects;
	vector<string> vectorObjectsOnCluster;
	itCluster it;

	for(it = begin(); it != end(); ++it){
		vectorObjectsOnCluster = it->getVectorObjects();

		for(itVectorObjects = vectorObjectsOnCluster.begin(); itVectorObjects != vectorObjectsOnCluster.end(); itVectorObjects++){

			if( (*itVectorObjects) == sAObject){
				return it->getLabel();
			}
		}
	}
	return -1; //VERIFICAR SE A CONSTANTE DE ERRO SERA -1
}

void Partition::loadPartition() {
	Partition::Cluster *pObCluster;
	string sTemp;
	string sObject;
	string sPath = sPathPartition + sNamePartition;
	int iCluster;
	int i;

	ifstream in(sPath.c_str());

	// define what gonna be the tokenizer character
	char_separator<char> sep("\t");

	while (getline(in, sTemp)) {

		// tokenize the string sTemp that's the line read in the file informed in 'pathAPartition'
		tokenizer<char_separator<char> > tokens(sTemp, sep);

		for (tokenizer<char_separator<char> >::iterator itTokens = tokens.begin(); itTokens != tokens.end(); ++itTokens) {

			// putting the ID of the element in the memory
			// mapVector[sIndexLine].push_back(dNumber);
			sObject = *itTokens;
			++itTokens;

			(istringstream(*itTokens) >> iCluster);
			mapObjects[sObject] = iCluster;

			i = 0;
			while (i < (int)vectorObjCluster.size() && (int)vectorObjCluster[i].getLabel()!= iCluster) {
				i++;
			}

			if (i == (int)vectorObjCluster.size()) {
				pObCluster = new Cluster(iCluster, sObject);
				vectorObjCluster.push_back(*pObCluster);
				delete pObCluster;
			} else
				vectorObjCluster[i].addObject(sObject);
		}
	}

	iNumObjects = mapObjects.size();
	iNumClusters =  vectorObjCluster.size();

}

void Partition::showCentroids(){

	vector<double> vectorCentroid;
	vector<double>::iterator itVectorCentroid;

	for (int i = 0; i < iNumClusters; i++){

		 vectorCentroid = vectorObjCluster[i].getVectorCentroids();

		for (itVectorCentroid = vectorCentroid.begin(); itVectorCentroid != vectorCentroid.end(); ++itVectorCentroid){
			cout << "Cluster (" << i << ") | Centroid >> " << *itVectorCentroid << endl;
		}
	}

}

void Partition::writePartition() {

	string sFolder;
	string sNamePartition;

	cout << "Inform the name of the folder that you want save your partition" << endl;
	cout << ">> ";
	cin >> sFolder;

	// # ficando o caminho para a nova pasta do tipo da partition
	cout << "New folder in : " << sPathPartition + sFolder << endl;

	//fs::path pathPartition(sFolder);

	// # criando o diretório especificado pelo usuário
	fs::create_directories(sPathPartition+sFolder);

	cout << "Inform the name of the file that gonna be your partition" << endl;
	cout << ">> ";
	cin >> sNamePartition;

	string sPath = sPathPartition + sFolder + "/" + sNamePartition + ".clu";

	cout << "sPath no partition >> " << sPath;

	ofstream out(sPath.c_str());

	map <string, int>::iterator itMapObjects;

	for(itMapObjects = mapObjects.begin(); itMapObjects != mapObjects.end(); ++itMapObjects){
		out << itMapObjects->first << "\t" << itMapObjects->second << "\n";
	}

	out.close();
}


Partition::Cluster & Partition::getCluster(int iPos) {
	return vectorObjCluster[iPos];
}

int Partition::getNumClusters() {
	return iNumClusters;
}

int Partition::getNumObjects() {
	return iNumObjects;
}

map<string, int> Partition::getMObjects(){
	return mapObjects;
}

vector<Partition::Cluster> Partition::getVObjects(){
	return vectorObjCluster;
}

// in this method in generated a random partition, don't follow any standard
void Partition::generateRandomPartition(DataSet *pAObjDataSet) {

	time_t rawtime;
	struct tm * timeinfo;
	time (&rawtime);
	timeinfo = localtime(&rawtime);

	string sMonth = boost::lexical_cast<string>(timeinfo->tm_mon+1);
	string sDay   = boost::lexical_cast<string>(timeinfo->tm_mday);
	string sYear  = boost::lexical_cast<string>(1900 + timeinfo->tm_year);

	string sHour   = boost::lexical_cast<string>(timeinfo->tm_hour);
	string sMinute = boost::lexical_cast<string>(timeinfo->tm_min);
	string sSecond = boost::lexical_cast<string>(timeinfo->tm_sec);

	string sFolder = sDay + "|" + sMonth + "|" + sYear + " " + sHour + ":" + sMinute + ":" + sSecond;
	string sName;

	int iObjects = pAObjDataSet->getNumberOfObjects();
	int iNumClusters = -1;

	fs::create_directories(sPathPartition + sFolder);

	cout << "Inform the NAME of the new partition" << endl;
	cout << ">> ";
	cin >> sName;

	/*
	while (iObjects <= 0 ){
		cout << "Inform the number of OBJECTS that you want in the new partition" << endl;
		cout << ">> ";
		cin >> iObjects;
	}
	*/

	while (iNumClusters <= 0){
		cout << "Inform the number of CLUSTERS that you want in the new partition" << endl;
		cout << ">> ";
		cin >> iNumClusters;
	}

	string sNewPartition = sPathPartition + sFolder + "/" + sName + ".clu";

	ofstream out( sNewPartition.c_str());

	for(int i = 0; i < iObjects; i++)	{
		out << "Element" << "\t" << rand()%iNumClusters + 1 << endl;
	}

	out.close();

}

void Partition::generatePartitionGroupCluster(DataSet *pAObjDataSet) {

	time_t rawtime;
	struct tm * timeinfo;
	time (&rawtime);
	timeinfo = localtime(&rawtime);

	string sMonth = boost::lexical_cast<string>(timeinfo->tm_mon+1);
	string sDay =   boost::lexical_cast<string>(timeinfo->tm_mday);
	string sYear =  boost::lexical_cast<string>(1900 + timeinfo->tm_year);

	string sHour =   boost::lexical_cast<string>(timeinfo->tm_hour);
	string sMinute = boost::lexical_cast<string>(timeinfo->tm_min);
	string sSecond = boost::lexical_cast<string>(timeinfo->tm_sec);

	string sFolder = sDay + "|" + sMonth + "|" + sYear + " " + sHour + ":" + sMinute + ":" + sSecond;
	string sName;

	int iObjects;
	int iNumClusters;
	int iCont = 0;
	int iCluster = 1;

	fs::create_directories(sPathPartition + sFolder);

	cout << "Provide the NAME of the new partition" << endl;
	cout << ">> ";
	cin >> sName;

	cout << "Provide the number of OBJECTS that you want in the new partition" << endl;
	cout << ">> ";
	cin >> iObjects;

	cout << "Provide the number of CLUSTERS that you want in the new partition" << endl;
	cout << ">> ";
	cin >> iNumClusters;


	string sNewPartition = sPathPartition + sFolder + "/" + sName + ".clu";

	ofstream out( sNewPartition.c_str());

	for(int i = 1; i <= iObjects; i++){
		if (iCont == (iObjects / iNumClusters)){
			iCluster++;
			iCont = 0;
		}
		iCont++;
		out << i << '\t' << iCluster << endl;
	}

	out.close();

}

// # ambos os métodos printClusterLabels e printClusters fazem a mesma coisa, porém nota-se a simplificação de implementação de um método para o outro
void Partition::printClusterLabels(){

	for (vector<Partition::Cluster>::iterator itVectorObjCluster = vectorObjCluster.begin(); itVectorObjCluster != vectorObjCluster.end(); ++ itVectorObjCluster){
		cout << itVectorObjCluster->getLabel() << ", ";
	}
}

// # ambos os métodos printClusterLabels e printClusters fazem a mesma coisa, porém nota-se a simplificação de implementação de um método para o outro
void Partition::printClusters(){
	itCluster it;

	for (it = begin(); it != end(); ++ it){
		cout << it->getLabel() << ", ";
	}

}

/******************
	Cluster
******************/

Partition::Cluster::Cluster(){}

Partition::Cluster::Cluster(int iACluster, string sAID) {
	iLabel = iACluster;
	vectorObjects.push_back(sAID);
}

vector<string> Partition::Cluster::getVectorObjects(){
	return vectorObjects;
}

void Partition::Cluster::addObject(string sAID) {
	vectorObjects.push_back(sAID);
}

void Partition::Cluster::calculateCentroid(DataSet *pAObjDataSet) {
	double dSum = 0;
	int iNumFeatures = pAObjDataSet->getNumberOfFeature();

	vector<double> vectorAtributes;

	// a mapVector that will receive the mapVector from DataSet
	map<string, vector<double> > mapVector;
	mapVector = pAObjDataSet->getMapVector();

	// analyzing all that are a feature and adding their respective values and dividing by the number of elements that are in the same cluster, and storing this value vector of centroids, which have the values of the centroids
	for (int i = 0; i < iNumFeatures; i++) {
		for (int j = 0; j < (int)vectorObjects.size(); j++) {
			vectorAtributes = mapVector.find(vectorObjects.at(j))->second;
			dSum += vectorAtributes.at(i);
		}
		vectorCentroid.push_back(dSum / vectorObjects.size());

		// zeroing to sum the next feature
		dSum = 0;
	}
}

int Partition::Cluster::getLabel() {
	return iLabel;
}

int Partition::Cluster::getNumberOfObjects() {
	return vectorObjects.size();
}

vector<double> Partition::Cluster::getVectorCentroids(){
	return vectorCentroid;
}

vector<string>::iterator Partition::Cluster::objectsItBegin() {
	return vectorObjects.begin();
}

vector<string>::iterator Partition::Cluster::objectsItEnd() {
	return vectorObjects.end();
}
