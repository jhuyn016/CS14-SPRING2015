#ifndef __TWOSTACKFIXED__
#define __TWOSTACKEDFIXED__

#include <iostream>
#include <cstdlib>

using namespace std;

class TwoStackedFixed {
    
    private:
    int *arr1;
    int sz; //size
    int top1; //top of 1st stack
    int top2; //top of 2nd
    int max;
    
    public:
    TwoStackedFixed(int size, int maxtop)
    :sz(size), max(maxtop)
    {
        arr1 = new int[size];
        top1 = -1;
        top2 = size;
    }
    
    template <typename T>
    void pushStack1(T value)
    {
        //checks if uno space
        if(top1 < top2 - 1)
        {
            top1++;
            arr1[top1] = value;
        }
        else
        {
            cout << "stack1 full " << endl;
            exit(1);
        } 
    }
    
    template <typename T>
    void pushStack2(T value)
    {
        //checks if uno space
        if(top1 < top2 - 1)
        {
            top2--;
            arr1[top2] = value;
        }
        else
        {
            cout << "stack2 full " << endl;
            exit(1);
        } 
    }
    
    template <typename T>
    T popStack1()
    {
        if(top1 >= 0)
        {
            int x = arr1[top1];
            top1--;
            return x;
        }
        else
        {
            cout << "Empty " << endl;
            exit(1);
        }
    }
    
    template <typename T>
    T popStack2()
    {
        if(top2 < sz)
        {
            int x = arr1[top2];
            top2++;
            return x;
        }
        else
        {
            cout << "Empty " << endl;
            exit(1);
        }
    }
    
    
    private:
    bool isFullStack1()
    {
        return ((top1 >= top2 - 1) || (top1 < max));
    }
    
    bool isFullStack2()
    {
        return (top2 <= sz);
    }
    
    bool isEmptyStack1()
    {
        return (top1 == -1);
    }
    
    bool isEmptyStack2()
    {
        return (top2 == sz);
    }
    
};
#endif