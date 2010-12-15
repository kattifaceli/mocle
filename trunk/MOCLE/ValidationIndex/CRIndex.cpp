/*
 * CRIndex.cpp
 *
 *  Created on: ??/??/2010
 *      Author: ???
 */

#include "CRIndex.h"

/* Implementation of both inherited methods */
double CRIndex::calculate(Partition &objPartition1, Partition &objPartition2){

	int iNObjects;
    int i, j;
	double dCr = 0;
    double dT1, dT2, dT3, dT4, dT5;

    vector<string>::iterator itPartition1, itPartition2;

    int contingencyTable[objPartition1.getNumClusters()][objPartition2.getNumClusters()];
    int mSomaPartition1[objPartition1.getNumClusters()], mSomaPartition2[objPartition2.getNumClusters()];

    dT1 = dT2 = dT3 = dT4 = dT5 = 0;

    for (i = 0; i < objPartition1.getNumClusters(); i++){
        for (j = 0; j < objPartition2.getNumClusters(); j++){
            contingencyTable[i][j] = 0;
        }
    }

    for (i = 0; i < objPartition1.getNumClusters(); i++){
        mSomaPartition1[i] = 0;
    }

    for (j = 0; j < objPartition2.getNumClusters(); j++){
        mSomaPartition2[j] = 0;
    }

   for (i = 0; i < objPartition1.getNumClusters(); i++){
      for (j = 0; j < objPartition2.getNumClusters(); j++){
         for (itPartition1 = objPartition1.getCluster(i).objectsItBegin(); itPartition1 != objPartition1.getCluster(i).objectsItEnd(); itPartition1++){

		 itPartition2 = find(objPartition2.getCluster(j).objectsItBegin(), objPartition2.getCluster(j).objectsItEnd(), *itPartition1);
            if(itPartition2 != objPartition2.getCluster(j).objectsItEnd())
		    contingencyTable[i][j]++;
         }
      }
   }

    for (i = 0; i < objPartition1.getNumClusters(); i++){
        for (j = 0; j < objPartition2.getNumClusters(); j++){
            mSomaPartition1[i] += contingencyTable[i][j];
        }
    }

    for (j = 0; j < objPartition2.getNumClusters(); j++){
        for (i = 0; i < objPartition1.getNumClusters(); i++){
            mSomaPartition2[j] += contingencyTable[i][j];
        }
    }

    for (i = 0; i < objPartition1.getNumClusters(); i++){
        for (j = 0; j < objPartition2.getNumClusters(); j++){
            dT1 += (contingencyTable[i][j] * contingencyTable[i][j] - contingencyTable[i][j])/2;
        }
    }

    for (i = 0; i < objPartition1.getNumClusters(); i++){
        dT2 += (mSomaPartition1[i] * mSomaPartition1[i] - mSomaPartition1[i]) / 2;
    }

    for (j = 0; j < objPartition2.getNumClusters(); j++){
       dT3 += (mSomaPartition2[j] * mSomaPartition2[j] - mSomaPartition2[j]) / 2;
    }

    iNObjects = objPartition2.getNumObjects();
    dT4 = (iNObjects * iNObjects - iNObjects) / 2;
    dT5 = (dT2 * dT3) / dT4;
    dCr = (dT1 - dT5) / ( (dT2 + dT3) / 2 - dT5);

    return dCr;

}

/* This method is to be used in internal validation measures, since CR isn't an internal validation measure
    the call of this method will throw an exception */
double CRIndex::calculate(Partition *pPartition, RelationSDN *pRelation, DataSet *pDataset){

}
