/*
 * RelationSDN.h
 *
 *  Created on: 12/03/2010
 *      Author: Gustavo
 */

#ifndef RELATIONSDN_H_
#define RELATIONSDN_H_

#include "SimilarityMatrix.h"
#include "NnList.h"
#include "Similarity.h"

/**
 *  @author Gustavo Rodrigues
 *  @since 12/03/10
 *  @version 2.0
 */

/** This class stores an object in which the similarity is generated from this
 * similarity matrix and is created from the list of nearest neighbors. */
class RelationSDN {

private:
	SimilarityMatrix objSimilarityMatrix; ///< object similarity Matrix
	NnList objNnList; ///< object nearest neighbor list
	Similarity *objSimilarity; ///< pointer measure of similarity
public:
	RelationSDN();
	RelationSDN(SimilarityMatrix objASimilarityMatrix, NnList objANnList, Similarity *pAObjSimilarity);
	virtual ~RelationSDN();

	/** Return object similarity Matrix */
	/** @param Don't have  */
	/** @return Similarity Matrix */
	SimilarityMatrix getSimilarityMatrix();

	/** Return pointer measure similarity */
	/** @param Don't have  */
	/** @return Pointer Similarity */
	Similarity* getSimilarity();


	/** Return nearest neighbor list */
	/** @param Don't have  */
	/** @return Object NnList */
	NnList getNnList();


	/** Set object Similarity Matrix */
	/** @param Matrix map */
	/** @return Don't have */
	void setSimilarityMatrix(map<string, map <string, double> > mapObjMap);


	/** Set measure similarity */
	/** @param Pointer similarity */
	/** @return Don't have */
	void setSimilarity(Similarity *pObjSimilarity);


	/** Set nearest neighbor list */
	/** @param Matrix map */
	/** @return Don't have*/
	void setNnList(map<string, map <string, double> > mapObjMap);
};

#endif /* RELATIONSDN_H_ */
