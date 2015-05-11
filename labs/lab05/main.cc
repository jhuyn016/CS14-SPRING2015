#include "lab5.h"


int main()
{
    BST<int> tree1;
    tree1.insert(50);
    tree1.insert(20);
    tree1.insert(10);
    tree1.insert(40);
    tree1.insert(35);
    tree1.insert(45);
    tree1.insert(60);
    tree1.insert(70);
    tree1.minCover2();
    tree1.displayMinCover();
}