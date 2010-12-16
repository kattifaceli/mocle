/*
 * Silhouette.h
 *
 *  Created on: 22/03/2010
 *      Author: Gustavo
 */

#ifndef SILHOUETTE_H_
#define SILHOUETTE_H_

#include "Deviation.h"
#include "../ValidationIndex.h"

/**
 *  @author Gustavo Rodrigues
 *  @since 22/03/10
 *  @version 2.0
 */

/* Gustavo, colocar um breve comentário sobre o que a silhouette faz */
/* Colacar um comentário mais detalhado sobre o que faz a silhoutte e porque ela herda da ValidationIndex */
class Silhouette: public ValidationIndex {
public:
	Silhouette();
	virtual ~Silhouette();

	/** Return value of silhouette from parameter partition*/
	/** @param Partition, RelationSDN and DataSet */
	/** @return Value silhouette*/
	virtual double calculate(Partition *pAPartition, RelationSDN *pARelation, DataSet *pADataset);

	/** Does nothing */
	virtual double calculate(Partition &objPartition1, Partition &objPartition2);
};

#endif /* SILHOUETTE_H_ */
