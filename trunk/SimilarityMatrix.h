/*
 * SimilarityMatrix.h
 *
 *  Created on: 10/02/2010
 *      Author: Valter
 */

#ifndef SIMILARITYMATRIX_H_
#define SIMILARITYMATRIX_H_

#include <boost/filesystem.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/tokenizer.hpp>

#include <fstream>
#include <iostream>
#include <map>
#include <string>

using namespace std;

/**
 *  @author Katti Facelli
 *  @since 10/02/10
 *  @version 1.0
 */

/// Generates the matrix of similarity
/** Generates the matrix of similarity */
class SimilarityMatrix {

private:
	map<string, map <string, double> > mapMatrix; ///< will receive the matrix of similarity

	/* Vinicius, comentar o que os atributos irão receber*/
	map<string, map <string, double> > mapEuclidean;
	map<string, map <string, double> > mapPearson;

public:
	SimilarityMatrix();
	virtual ~SimilarityMatrix();

	/** Return the similarity matrix */
	/** @param Don't have  */
	/** @return Similarity matrix*/
	map<string, map <string, double> > getMatrix();

	/** Set similarity matrix */
	/** @param Matrix map  */
	/** @return Don't have */
	void setMatrix(map<string, map <string, double> > mapAObjMap);

	/* Vinicius */
	map<string, map <string, double> > getEuclideanMatrix();
	map<string, map <string, double> > getPearsonMatrix();

	void setEuclideanMatrix(map<string, map <string, double> > mapAEuclidean);
	void setPearsonMatrix(map<string, map <string, double> > mapAPearson);

};

#endif /* SIMILARITYMATRIX_H_ */
