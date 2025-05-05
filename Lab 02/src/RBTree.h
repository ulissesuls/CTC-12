#include <vector>
#include <string>
#include <iostream>
#include <stdio.h>

enum{BLACK, RED};

typedef struct Node Node;

struct Node
    {
        int cor;
        double chave;
        long elemento;
        Node *pai, *fesq, *fdir; 
    };

class RBTree {
    
public:

    //construtor
    RBTree();

    //Destrutor
    ~RBTree();

    // Insere um elemento e rebalanceia a árvore
    void Insert(double key, long idx);

    //Tamanho da árvore no momento
    long size();

    //Preenche um vetor com as chaves de first até last
    void findRange(std::vector<long> &res, double first, double last);

    // Função recursiva para auxiliar o preenchimento do vetor
    void findRangeinOrder(Node *x, std::vector<long> &res, double first, double last);
 
    
private: 

    Node *raiz;
    Node *NIL;
    long tamanho;

    void RBrotacaoEsq(Node *X);

    void RBrotacaoDir(Node *X);

    void auxDelete(Node *R);
    
};//class
