// Jaymond Huynh
// 861102072
// 5/15/15
#ifndef __SELECTIONSORT__
#define __SELECTIONSORT__

#include <iostream>
#include <utility>
#include <list>

using namespace std;

template <typename L>
void selectionsort(L &l)
{
    typename L::iterator minIt;
    typename L::iterator its;  
  
    for(typename L::iterator it = l.begin(); it != l.end(); ++it)
    {
        minIt = it; // pos0
        its = it; //pos0 
        ++its;  //pos1
        for(; its != l.end(); ++its)
        {
            if(*its < *minIt)//pos1 < pos0
            {
                minIt = its; //if yes then put pos
            }
        }       
        std::swap(*it, *minIt); //swap em 
        
    }


}

template <typename L>
void print1(L &l)
{
    for(typename L::iterator it = l.begin(); it != l.end(); ++it)
    {
        cout << *it << ' ';
    }
}



template <typename L>
void print2(L &l)
{
    for(typename L::iterator it = l.begin(); it != l.end(); ++it)
    {
        cout << '(' << it->first << ", " << it->second << ") ";
    }
}











#endif