#ifndef CES12_ALUNOINDEXPOINTS_H
#define CES12_ALUNOINDEXPOINTS_H

#include <vector>
#include <map>
#include <IndexPointsAbstract.h>
#include <RBTree.h>

class IndexPointsAluno : public IndexPointsAbstract {
    
public:
    
    long size() ;
        
    void add (double key, long idx ) ;
    
    void find(std::vector<long> &res, double first, double last ) ; 
    
private: 
    
    // Instancia um objeto por meio do construtor
    RBTree arvore;
    
};//class


#endif
