#include <iostream> 
#include <list>

using namespace std;

template <typename T>
void mergeList(list<T> &p, list<T> &q)
{
    typename list<T>::const_iterator start = p.begin();
    typename list<T>::const_iterator end = p.end();
    typename list<T>::iterator it = q.begin();
    for (typename list<T>::const_iterator i = p.begin(), end = p.end(); i != end; i++) 
    {
        q.insert(it, *i);
        ++it;
    }
    for (typename list<T>::const_iterator i = q.begin(), end = q.end(); i != end; ++i) 
    {
        cout << *i << endl;
    }
}

template <typename T>
void mergeSortList(list<T> &p, list<T> &q)
{
    typename list<T>::iterator it = p.begin(); //1st
    typename list<T>::iterator its = q.begin(); //2nd
    
    while(it != p.end() && its != q.end())
    {
        if(*it <= *its)
        {
            q.insert(its, *it); //its is pointing to 1st item in 2nd linked list
            it++; //iterate through 1st linked list
        }
        else
        {
            its++; //iterate through 2nd
        }
    }
    

    //for the extras on the back of the 1st linked list
    if(it != p.end())
    {
        for(; it != p.end(); it++)
        {
            q.push_back(*it);
        }
    }
    
    

    
    //cout << p.size() << endl;
    for (typename list<T>::const_iterator i = q.begin(), end = q.end(); i != end; ++i) 
    {
        cout << *i << endl;
    }
}

template <typename T>
void rotate(list<T> &p, T a)
{
    //a = 3
    typename list<T>::iterator it = p.begin();
    typename list<T>::iterator temp;
    int cnt = 0;
    // for(int i = 0; i < a; i++)
    // {
    //     it++; //now iterator it = 2 (total of 3 doe) 
    // }
    //cout << *it << endl;
    while(cnt != a)
    {
        p.push_back(*it); //it = 0 *it = 12
        temp = it;
        it++;
        p.erase(temp);
        cnt++;
    }
    //cout << p.size();
    for (typename list<T>::const_iterator i = p.begin(), end = p.end(); i != end; ++i) 
    {
        cout << *i << endl;
    }
}

int main() 
{
    //PART1
    cout << "~~~~~PART1~~~~~~~~" << endl;
    list<int> L;
    list<int> L2;
    list<double> L3;
    list<double> L4;
    list<string> L5;
    list<string> L6;
    L3.push_back(1.9);
    L3.push_back(3.8);
    L4.push_back(2.9);
    L4.push_back(9.8);
    
    
    L.push_back(12);
    L.push_back(3);
    L.push_back(56);
    L.push_back(5);
    L2.push_back(45);
    L2.push_back(66);
    L2.push_back(2);
    
    
    L5.push_back("hello");
    L5.push_back("kitty");
    L6.push_back("puppyfat");
    L6.push_back("cat");
    
    
    mergeList(L, L2);
    cout << endl;
    mergeList(L3, L4);
    cout << endl;
    mergeList(L5, L6);
    cout << endl;
    
    //PART2
    cout << "~~~~~PART2~~~~~~~~" << endl;
    list<int> L7;
    list<int> L8;
    
    L7.push_back(3);
    L7.push_back(5);
    L7.push_back(12);
    L7.push_back(56);
    L8.push_back(2);
    L8.push_back(45);
    L8.push_back(66);
    
    mergeSortList(L7, L8);
    
    //PART3 
    cout << "~~~~~PART3~~~~~~~~" << endl;
    list<int> L9;
    
    L9.push_back(3);
    L9.push_back(5);
    L9.push_back(15);
    L9.push_back(20);
    L9.push_back(40);
    L9.push_back(60);
    

    rotate(L9, 3);
    
    
    return 0;
}