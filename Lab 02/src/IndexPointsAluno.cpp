
#include <IndexPointsAluno.h>

/// returns the number of elements in the index
long IndexPointsAluno::size()
{
    return arvore.size();
}

/// adds new element to the index.
void IndexPointsAluno::add(double key, long idx)
{
    arvore.Insert(key, idx);
}

// Insere no vetor uma série de elementos baseados num intervalo válido de chaves
void IndexPointsAluno::find(std::vector<long> &res, double first, double last)
{
    res.clear();
    arvore.findRange(res, first, last);
}