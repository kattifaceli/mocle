/*
 * NMIndex.h
 *
 *  Created on: ??/??/2010
 *      Author: ???
 */

#include "NMIIndex.h"

/* Implementation of both inherited methods */
double NMIIndex::calculate(Partition &objPartition1, Partition &objPartition2)
{

	return  mutualInformation(objPartition1, objPartition2)/sqrt(enthropy(objPartition1)*enthropy(objPartition2));

}

/* This method is to be used in internal validation measures, since NMI isn't an internal validation measure
    the call of this method will throw an exception */
double NMIIndex::calculate(Partition *pPartition, RelationSDN *pRelation, DataSet *pDataset){

}
