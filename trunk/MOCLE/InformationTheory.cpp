#include"InformationTheory.h"

/* Implementation of methods in InformationTheory class */
double InformationTheory::enthropy(Partition &objPartition) {
	double dSummation = 0;
	double dStore;

	for (int iClusterPosition = 0; iClusterPosition	< objPartition.getNumClusters(); iClusterPosition++) {

		dStore = objPartition.getCluster(iClusterPosition).getNumberOfObjects()	/ static_cast<double> (objPartition.getNumObjects());

		dStore *= log10(dStore);

		dSummation += dStore;
	}

	return -dSummation;
}

double InformationTheory::intersection(Partition &objPartition1, Partition &objPartition2, int iClusterPosition1, int iClusterPosition2) {
	int iCounter = 0;
	vector<string>::iterator itVectorPartition1;
	vector<string>::iterator itVectorPartition2;

	for (itVectorPartition1	= objPartition1.getCluster(iClusterPosition1).objectsItBegin(); itVectorPartition1 != objPartition1.getCluster(iClusterPosition1).objectsItEnd(); itVectorPartition1++) {
		for (itVectorPartition2 = objPartition2.getCluster(iClusterPosition2).objectsItBegin(); itVectorPartition2 != objPartition2.getCluster(iClusterPosition2).objectsItEnd(); itVectorPartition2++) {
			if (*itVectorPartition1 == *itVectorPartition2)
				iCounter++;
		}
	}
	return iCounter / static_cast<double> (objPartition1.getNumObjects());
}

double InformationTheory::mutualInformation(Partition &objPartition1, Partition &objPartition2) {
	double dSummation = 0;
	double dStore = 0, dProbabilityPartition1 = 0, dProbabilityPartition2 = 0;

	for (int iClusterPosition1 = 0; iClusterPosition1 < objPartition1.getNumClusters(); iClusterPosition1++) {

		for (int iClusterPosition2 = 0; iClusterPosition2 < objPartition2.getNumClusters(); iClusterPosition2++) {

			dStore = intersection(objPartition1, objPartition2, iClusterPosition1, iClusterPosition2);

			dProbabilityPartition1 = objPartition1.getCluster(iClusterPosition1).getNumberOfObjects() / static_cast<double> (objPartition1.getNumObjects());

			dProbabilityPartition2 = objPartition2.getCluster(iClusterPosition2).getNumberOfObjects() / static_cast<double> (objPartition2.getNumObjects());

			if (dStore / static_cast<double> (dProbabilityPartition1 * dProbabilityPartition2) != 0) {
				dStore *= log10(dStore / static_cast<double> ((dProbabilityPartition1 * dProbabilityPartition2)));
				dSummation += dStore;
			}
		}
	}

	return dSummation;

}
