#ifndef LAB1_HASH_H
#define LAB1_HASH_H
// DONT KNOW WHAT IS THIS #ifndef stuff? see:
// https://en.wikipedia.org/wiki/Include_guard

#include <vector>
#include <forward_list>
#include <string>
#include <cassert>
#include <iostream>

/*
 * for didactical purposes every method is public, it is more transparent than usual  
 * the method hash could be private
 * and the worst_case method usually do not exist. 
 */
class Hash {
    
public:
    
    /// construct hashtable with size and hashfunction
    Hash(int tablesize,int (*hf) (std::string) ) ; //Construtor Hash


    
    /**
     * \brief return the hash of a string (a integer from 0 to tablesize-1)
     * \par THIS FUNCTION COULD BE PRIVATE, BUT WE WANT IT TO BE TRANSPARENT
     */
    int hash(std::string str) ; // Método hash


    
    /**
     * \brief checks if hashtable contains a string 
     * \par collisions: how many strings were accessed to determine if the string was already in the hashtable
     * \return 1 if hashtable contains str, 0 otherwise.
     */
    int contains(std::string str, int &collisions); // Método contains



    /**
     * \brief adds a string to the hashtable (repetitions are not allowed)
     * \par collisions: how many strings were accessed to determine if the string was already in the hashtable
     * \returns 1 if string was not found and added; 0 if string was found and therefore nothing new was added.
     */
    int add(std::string str, int &collisions) ; // Método add


    
    /**
     * \brief the size of the largest list in the hashtable, i.e, the worst case for a search.
     * \par this is obviously O(n), as it has to check every list. This method is not usual, it is here  only for didactical purposes.
     */
    int worst_case(); // Método worst_case


    
    /**
     * \returns the total number of strings contained in the hash table.
     */
    int size(); // Método size


    
    /**
     * \brief removes a string from the hashtable (repetitions are not allowed, so there is no need of searching for duplicates)
     * \par str: the string to be removed
     * \par collisions: how many strings were accessed to determine if the string was already in the hashtable
     * \returns 1 if string was found and removed; 0 if string was not found
     */
    int remove(std::string str, int &collisions) ; // Método remove
    

private:
    
    // note that I named the class attributes with a '_' prefix (just a naming convention)
    
    int (*_hash_func) (std::string); /// ponteiro para uma função que recebe uma string como argumento
    
    /// nice teacher already tells you which stl classes to use
    std::vector<std::forward_list<std::string>> _table; /// vector of [single linked lists of [strings]]
    // and std::string is a specialized std::vector for char (it is not just std::vector<char>, it is a specialized subclass with specific string operations).
    // but it still could be said that _table is: 
    // vector of [single linked lists of [vector of char] ]
    

};//class



#endif
