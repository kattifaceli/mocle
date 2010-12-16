/*
 * CRIndex.h
 *
 *  Created on: ??/??/2010
 *      Author: ???
 */

#ifndef __CR_INDEX_H__
#define __CR_INDEX_H__

#include <algorithm>
#include <vector>
#include <iostream>

#include "../ValidationIndex.h"
#include "../Partition.h"
#include "../Exception.h"

class CRIndex : ValidationIndex {
  public:
        virtual double calculate(Partition &objPartition1, Partition &objPartition2);
        virtual double calculate(Partition *pPartition, RelationSDN *pRelation, DataSet *pDataset);
};

#endif
