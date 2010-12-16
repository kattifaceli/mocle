#ifndef __INFORMATION_THEORY_H__
#define __INFORMATION_THEORY_H__


#include"Partition.h"

/**
 *  @author Vinicius
 *  @since ??/??/??
 *  @version 2.0
 */

/* Vinicius, colocar um breve comentário sobre o que a information_theory faz */
/* Colacar um comentário mais detalhado sobre o que faz a information_theory */
/* This class contains methods to be used in external validation measures based on Information Theory */
class InformationTheory {

    protected:
              double enthropy(Partition &objPartition);
              double mutualInformation(Partition &objPartition1, Partition &objPartition2);
    private:
              double intersection(Partition &objPartition1, Partition &objPartition2, int iClusterPosition1, int iClusterPosition2);

};



#endif
