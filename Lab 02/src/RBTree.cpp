#include <RBTree.h>

// Constructor RBTree
RBTree::RBTree() 
{
    
    tamanho = 0;
    NIL = new Node();
    NIL->cor = BLACK;
    // NIL->fdir = NIL->fesq = NIL->pai = nullptr;

    raiz = NIL;
}

//Destructor RBTree
RBTree::~RBTree() 
{
    auxDelete(raiz);
    delete (NIL);
}

// Rebalanceia a árvore rotacionando para a esquerda
void RBTree::RBrotacaoEsq(Node *X)  
{
    Node *y;
    y = X->fdir;
    X->fdir = y->fesq;
    if (y->fesq != NIL)
    {
        y->fesq->pai = X;
    }
    y->pai = X->pai;
    if(X->pai == NIL)
    {
        raiz = y;
    }
    else
    {
        if(X == X->pai->fesq)
        {
            X->pai->fesq = y;
        }
        else
        {
            X->pai->fdir = y;
        }
    }
    y->fesq = X;
    X->pai = y;
}

// Rebalanceia a árvore rotacionando para a direita
void RBTree::RBrotacaoDir(Node *X) 
{
    Node *y;
    y = X->fesq;
    X->fesq = y->fdir;
    if (y->fdir != NIL)
    {
        y->fdir->pai = X;
    }
    y->pai = X->pai;
    if(X->pai == NIL)
    {
        raiz = y;
    }
    else
    {
        if(X == X->pai->fdir)
        {
            X->pai->fdir = y;
        }
        else
        {
            X->pai->fesq = y;
        }
    }
    y->fdir = X;
    X->pai = y;
}

// adds new element to the index.
void RBTree::Insert(double key, long idx)
{
    Node *z = new Node();
    Node *x = raiz;
    Node *y = NIL;
    
    // Preenche o novo nó
    z->cor = RED;
    z->fesq = z->fdir = NIL;
    z->chave = key;
    z->elemento = idx;

    // Função implementada com base no pseudocódigo do livro do Cormen
    while (x != NIL)
    {
        y = x;
        if(z->chave < x->chave)
        {
            x = x->fesq;
        }
        else x = x->fdir;
    }
    z->pai = y;
    if (y == NIL)
    {
        raiz = z;
    }
    else
    {
        if (z->chave < y->chave)
        {
            y->fesq = z;
        }
        else y->fdir = z;
    }

    // Rebalanceia a árvore após a inserção. Função implementada com base no pseudocódigo do livro do Cormen
    while (z->pai->cor == RED)
    {
        if(z->pai == z->pai->pai->fesq)
        {
            y = z->pai->pai->fdir;
            if(y->cor == RED) 
            {
                z->pai->cor = BLACK;
                y->cor = BLACK;
                z->pai->pai->cor = RED;
                z = z->pai->pai;
            }
            else
            {
                if(z == z->pai->fdir)
                {
                    z = z->pai;
                    RBrotacaoEsq(z);
                }
                z->pai->cor = BLACK;
                z->pai->pai->cor = RED;
                RBrotacaoDir(z->pai->pai);
            }
        }
        else
        {
            y = z->pai->pai->fesq;
            if (y->cor == RED)
            {
                z->pai->cor = BLACK;
                y->cor = BLACK;
                z->pai->pai->cor = RED;
                z = z->pai->pai;
            }
            else
            {
                if (z == z->pai->fesq)
                {
                    z = z->pai;
                    RBrotacaoDir(z);
                }
                z->pai->cor = BLACK;
                z->pai->pai->cor = RED;
                RBrotacaoEsq(z->pai->pai);
            }
        }
    }
    raiz->cor = BLACK;
    tamanho++; 
}

void RBTree::findRange(std::vector<long> &res, double first, double last)
{
    findRangeinOrder(raiz, res, first, last);
}

// Função recursiva que percorre a árvore InOrder e, se a chave do nó visitado está dentro do intervalo, adiciona-se o elemento ao vetor.
void RBTree::findRangeinOrder(Node *x, std::vector<long> &res, double first, double last)
{
    if (x == NIL)
        return;

    if (first < x->chave)
        findRangeinOrder(x->fesq, res, first, last);

    if (first <= x->chave && x->chave <= last)
        res.push_back(x->elemento);

    if (x->chave < last)
        findRangeinOrder(x->fdir, res, first, last);
}

/// returns the number of elements in the index
long RBTree::size() 
{
    return tamanho;
}

// Função auxiliar para remover a árvore e usar o Destructor.uma função que cabe destaque
void RBTree::auxDelete(Node *R)  
{
    if(R != NIL)
    {
        auxDelete(R->fesq);
        auxDelete(R->fdir);
        delete (R);
    }
}