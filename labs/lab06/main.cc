// Jaymond Huynh
// 861102072
// 5/15/15
#include "selectionsort.h"
#include <list>



int main() {
    
    //part1
    list<int> list1;
    list1.push_back(2);
    list1.push_back(4);
    list1.push_back(5);
    list1.push_back(1);
    list1.push_back(8);
    list1.push_back(9);
    cout << "pre: ";
    print1(list1);
    selectionsort(list1);
    cout << endl;
    cout << "post: ";
    print1(list1);
    cout << endl;
    
    
    //part 2
    list<int> list2;
    cout << "pre: ";
    print1(list2);
    selectionsort(list2);
    cout << endl;
    cout << "post: ";
    print1(list2);
    cout << endl;
    
    
    //part3
    list<pair<int, int> > list3;
    list3.push_back(make_pair(1, 2));
    list3.push_back(make_pair(3, -1));
    list3.push_back(make_pair(-1, 3));
    list3.push_back(make_pair(0, 0));
    list3.push_back(make_pair(2, 3));
    list3.push_back(make_pair(1, 2));
    list3.push_back(make_pair(1, -2));
    list3.push_back(make_pair(8, 10));
    cout << "pre: ";
    print2(list3);
    selectionsort(list3);
    cout << endl;
    cout << "post: ";
    print2(list3);
    cout << endl;
    cout << "0 copies and 18 moves " << endl;
    
    //part4
    list<pair<int, int> > list4;
    list4.push_back(make_pair(10, 2));
    list4.push_back(make_pair(-3, -1));
    list4.push_back(make_pair(-8, 0));
    list4.push_back(make_pair(1, 1));
    list4.push_back(make_pair(1, 1));
    list4.push_back(make_pair(0, 0));
    list4.push_back(make_pair(10, 2));
    list4.push_back(make_pair(5, 5));
    list4.push_back(make_pair(5, -5));
    list4.push_back(make_pair(0, 0));
    list4.push_back(make_pair(10, 2));
    cout << "pre: ";
    print2(list4);
    selectionsort(list4);
    cout << endl;
    cout << "post: ";
    print2(list4);
    cout << endl;
    cout << "0 copies and 15 moves " << endl;
    
    //part5
    list<pair<int, int> > list5;
    list5.push_back(make_pair(-1, 3));
    list5.push_back(make_pair(0, 0));
    list5.push_back(make_pair(1, -2));
    list5.push_back(make_pair(1, 2));
    list5.push_back(make_pair(1, 2));
    list5.push_back(make_pair(2, 3));
    list5.push_back(make_pair(3, -1));
    list5.push_back(make_pair(8, 10));
    cout << "pre: ";
    print2(list5);
    selectionsort(list5);
    cout << endl;
    cout << "post: ";
    print2(list5);
    cout << endl;
    cout << "0 copies and 0 moves " << endl;

    cout << endl; 
    cout << endl;

    //stable testing
    list<int> list6;
    list6.push_back(2);
    list6.push_back(3);
    list6.push_back(1);
    list6.push_back(1);
    cout << "pre: ";
    print1(list6);
    selectionsort(list6);
    cout << endl;
    cout << "post: ";
    print1(list6);
    cout << endl;
}