#include <iostream>
#include <forward_list>
#include <list>
#include "lab02.h"
using namespace std;








//helper
bool isPrime(int i)
{
    if(i < 2) 
    {
        return false;
    }
    if(i == 2) 
    {
        return true;
    }
    if(i % 2 == 0)
    {
        return false;
    }
    for(int j = 3; (j * j) <= i; j+= 2)
    {
        if(i % j == 0) 
        {
            return false;
        }
    }
    return true;
}

int primeCount(forward_list<int> lst)
{
    //non recursive
    int cnt = 0;
    typename::forward_list<int>::iterator it;
    for(it = lst.begin(); it != lst.end(); it++)
    {
        if(isPrime(*it))
        {
            cnt++;
        }
    }
    return cnt;
    // //FIX HOW TO INCREMEMNT THE COUNTER 
    // if(!lst.empty())
    // {
    //     return 0;
    // }
    // else
    // {
    //     if(isPrime(lst.front()))
    //     {
    //         lst.pop_front();
    //         primeCount(lst);
    //     }
    //     else
    //     {
    //         lst.pop_front();
    //     }
        
    // }
    
    // return 1;
}

//part 3 
template<typename Type>
void listCopy(forward_list <Type> L, forward_list<Type>& P ) 
{
    
    typename::forward_list<Type>::iterator it;
    typename::forward_list<Type>::iterator its = P.end();
    its++;
    for(it = L.begin(); it != L.end(); it++)
    {
        //*its = it;
    }
    
}


//part 4
template<typename Type>
void printLots(forward_list<Type> L, forward_list<int> P)
{
    
    typename::forward_list<int>::iterator it;
    typename::forward_list<Type>::iterator its; 
    for(it = P.begin(); it != P.end(); it++)
    {
        int x = *it; //1 into x
        int cnt = 0;
        for(its = L.begin(); its != L.end(); its++)
        {
            if(cnt == x)
            {
                cout << *its << ' ';
                break;
                
            }
            cnt++;
        }
    }
    cout << endl;

}





int main()
{
    //testing helper
    int n = 7;
    int j = 8;
    int i = 13;
    cout << isPrime(n);
    cout << isPrime(j);
    cout << isPrime(i);
    cout << endl;
    //testing primeCount
    forward_list<int> lst; //13,8,7
    lst.push_front(7);11
    lst.push_front(8);
    lst.push_front(13);
    cout << primeCount(lst);
    cout << endl;
    forward_list<int> lst2; //1 2 3
    
    lst2.push_front(3);
    lst2.push_front(2);
    lst2.push_front(1);
    
 
    
    
    
    printLots(lst, lst2);
    //cout << primeCount(lst);
    
    
    
    return 0;
}