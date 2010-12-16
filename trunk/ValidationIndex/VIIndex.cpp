#include "VIIndex.h"
#include "../Partition.h"
#include "../InformationTheory.h"
#include "../Exception.h"

/* Implementation of both inherited methods */

double VIIndex::calculate(Partition &objPartition1, Partition &objPartition2)
{

	return enthropy(objPartition1) + enthropy(objPartition2) - 2*mutualInformation(objPartition1, objPartition2);

}

double VIIndex::calculate(Partition *pPartition, RelationSDN *pRelation, DataSet *pDataset){

}
