#include "hash.h"

// LOOK FOR THE COMMENTS IN THE .H 
// TO UNDERSTAND WHAT EACH FUNCTION MUST DO

Hash::Hash(int tablesize, int (*hf) (std::string) ) { //O construtor recebe como parâmetro um int e um ponteiro de função, cujo parâmetro é uma string.
    // CONSTRUTOR
    _hash_func = hf; //O construtor está inicializando o ponteiro de função _hash_func já declarado em Private. Essa função provavelmente será chamada na main
    _table.resize(tablesize); //O construtor está redimensionando a table já declarada em Private
}

int Hash::add(std::string str, int &collisions) {  // Repetições não são permitidas!

    int bucket = hash(str);
    collisions = 0;

    for(auto cont = _table[bucket].begin(); cont !=_table[bucket].end(); ++cont)
    {
        collisions++;
        if ( *cont == str) // ou poderíamos declarar if ( Hash::contains(str, collisions))
        { 
            return 0;
        }
    }
    _table[bucket].push_front(str);
    
    return 1;

} //add

int Hash::remove(std::string str, int &collisions) { 
    
    int bucket = hash(str);
    collisions = 0;
    for( auto posic = _table[bucket].begin(); posic != _table[bucket].end(); ++posic) 
    {
        collisions++;
        if (*posic == str) 
        {
            _table[bucket].remove(str);
            return 1;
        }
    }

    return 0; 
}//remove


int Hash::hash(std::string str) {  
    
    return _hash_func(str); // Está retornando o índice do bucket
    
}//hash
    
int Hash::contains(std::string str, int &collisions) { 

    collisions = 0;
    int bucket = hash(str);
    for (auto cont = _table[bucket].begin(); cont != _table[bucket].end(); ++cont)
    {
        collisions++;
        if ( *cont == str)
        {
            return 1;
        }
    }
    return 0;
    
}//contains


int Hash::worst_case()
{
    
    int i = 0;
    int collisions = 0;
    int aux;

    for (auto cont1 = _table.begin(); cont1 != _table.end(); ++cont1, i++)
    {
            aux = 0;
            for (auto cont2 = _table[i].begin(); cont2 != _table[i].end(); ++cont2, aux++)
            {
            }
            if ( aux > collisions)
            {
                collisions = aux;
            }
    }

    return collisions;
    
}//worst_case

int Hash::size()
{
    
    int i = 0;
    int tam = 0;
    int aux;
    for (auto cont1 = _table.begin(); cont1 != _table.end(); ++cont1, i++)
    {
            aux = 0;
            for (auto cont2 = _table[i].begin(); cont2 != _table[i].end(); ++cont2, aux++)
            {
            }
            tam += aux;
    }

    return tam;
    
}//size

