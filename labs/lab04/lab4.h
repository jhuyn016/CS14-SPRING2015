#ifndef __LAB04__
#define __LAB04__

#include <iostream>


using namespace std;

void coPrime(int m, int n, int x) //m = 1st n = 2nd x = max
{
    if(x > m + n)
    {
        
        cout << m << ' ' << n << endl;
    }
    else
    {
        return;
    }
    coPrime(2 * m - n, m, x);
    coPrime(2 * m + n, m, x);
    coPrime(m + (2 * n), n, x);
    
    if(m == 2)
    {
        coPrime(3, 1, x);
    }
    
}

void coPrime2(int m, int n, int x)
{
    
    if(m + n >= x)
    {
        return;
    }
    coPrime2(2 * m - n, m, x);
    coPrime2(2 * m + n, m, x);
    coPrime2(m + 2 * n, n, x);
  
  
        cout << m << ' ' << n << endl;
    
    
    if(m == 2)
    {
        coPrime2(3, 1, x);
    }
};


#endif