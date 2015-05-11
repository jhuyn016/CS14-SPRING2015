// Jaymond Huynh
// 861102072
// 5/5/15
#ifndef BST_H
#define BST_H
#include <cassert>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <map>
#include <list>
#include <math.h>

using namespace std;

#define nil 0

// #define Value int // restore for testing.
template < typename Value >
class BST {
    class Node { // binary tree node
    public:
        Value value;
        Node* left;
        Node* right;
      
        bool selected;
        
        Node( const Value v = Value() )
        : value(v), left(nil), right(nil)
        {}

        Value& content() { return value; }
        bool isInternal() { return left != nil && right != nil; }
        bool isExternal() { return left != nil || right != nil; }
        bool isLeaf() { return left == nil && right == nil; }

        int height() 
        {
            // returns the height of the subtree rooted at this node
            int left1 = 0;
            int right1 = 0;
            if(left != NULL)
            {
                left1 = left->height();
            }
            if(right != NULL)
            {
                right1 = right->height();
            }
            if(left1 > right1)
            {
                return left1 + 1;
            }
            else
            {
                return right1 + 1;
            }
            
        }
        
        int size() 
        {
            // returns the size of the subtree rooted at this node,
            if(this == NULL)
            {
                return 0;
            }
            return 1 + this->left->size() + this->right->size();
            
        }
        
        //search helper
        bool search1(Value x)
        {
            if(x == value)
            {
                return true;
            }
            else if(x < value)
            {
                if(left == NULL)
                {
                    return false;
                }
                else
                {
                    return left->search1(x);
                }
            }
            else if(x > value)
            {
                if(right == NULL)
                {
                    return false;
                }
                else
                {
                    return right->search1(x);
                }
                
            }
            return false;
        }
        
        void minCover()
        {
            if(this == nil)
            {
                return;
            }
            if(this == nil)
            {
                return;
            }
            left->minCover();
            right->minCover();
            if(left != nil)
            {
                if(left->isLeaf() || (left->selected == false))
                {
                    selected = true;
                    return;
                }
            }
            if(right != nil)
            {
                if(right->isLeaf() || (right->selected == false))
                {
                    selected = true;
                    return;
                }
            }
        }
        
        int inCover()
        {
            if(this == nil)
            {
                return 0;
            }
            int x = 0;
            x = x + left->inCover();
            if(selected == true)
            {
                cout << this->value << ' ';
                x++;
            }
            x = x + right->inCover();
            return x;
        }

    }; // end class Node

    //const Node* nil; // later nil will point to a sentinel node.
    int count;
    Node* root;
    
    public:
    int size() 
    {
        //FIX
        // size of the overall tree.
        cout << "HIHIHIIHIHIHI ";
        if(root == NULL)
        {
             return 1;
             cout << "HIHIHIHIHIHIHIHIHI";
        }
        else
        {
            int leftSub = root->left->size();
            int rightSub = root->right->size();
            return;
        }
    }
    bool empty() { return size() == 0; }
    
    
    void print_node( const Node* n ) 
    {
        if(n == NULL)
        {
            return;
        }
        print(n->left);
        cout << n->value << endl;
        print(n->right);
        
        
    }
    bool search ( Value x ) 
    {
        //search for a Value in the BST and return true iff it was found.
        if(root == NULL)
        {
            return false;
        }
        else
        {
            return root->search1(x);
        }

    }
    void preorder() const 
    {
        // Traverse and print the tree one Value per line in preorder.
        preorder(root); //root 1st then left parents n children then right side
    }
    void postorder() const 
    {
        // Traverse and print the tree one Value per line in postorder.
        //start very left, prints children 1st then parents then goes to right side root (last)
        postorder(root);
    }
    void inorder() const 
    {
        // Traverse and print the tree one Value per line in inorder.
        //in order starts from very left child then parent (left to right print) then root(middle) then right side
        inorder(root);
    }
    Value& operator[] (int n) 
    {
        // returns reference to the value field of the n-th Node.
        //helper
        //return find(root, n);
    }
    

    
    BST() 
    : count(0), root(nil) {}

    void insert( Value X ) { root = insert( X, root ); }
    
    Node* insert( Value X, Node* T ) 
    {
        // The normal binary-tree insertion procedure ...
        if ( T == nil ) 
        {
            T = new Node( X ); // the only place that T gets updated.
        } 
        else if ( X < T->value ) 
        {
            T->left = insert( X, T->left );
        }
        else if ( X > T->value ) 
        {
            T->right = insert( X, T->right );
        } 
        else 
        {
            T->value = X;
        }
        // later, rebalancing code will be installed here
        return T;
    }

void remove( Value X ) { root = remove( X, root ); }

Node* remove( Value X, Node*& T ) 
{
    // The normal binary-tree removal procedure ...
    // Weiss’s code is faster but way more intricate.
    if ( T != nil ) 
    {
        if ( X > T->value ) 
        {
            T->right = remove( X, T->right );
        } 
        else if ( X < T->value ) 
        {
            T->left = remove( X, T->left );
        } 
        else 
        { // X == T->value
            if ( T->right != nil ) 
            {
                Node* x = T->right;
                while ( x->left != nil ) x = x->left;
                T->value = x->value; // successor’s value
                T->right = remove( T->value, T->right );
            } 
            else if ( T->left != nil ) 
            {
                Node* x = T->left;
                while ( x->right != nil ) x = x->right;
                T->value = x->value; // predecessor’s value
                T->left = remove( T->value, T->left );
            } 
            else 
            { // *T is external
                delete T;
                T = nil; // the only updating of T
            }
        }
    }
    // later, rebalancing code will be installed here
    return T;
}

void minCover2()
{
    root->minCover();
}

void displayMinCover()
{
    int x;
    x = root->inCover();
    cout << endl << x << endl;
}


void okay( ) { okay( root ); }

void okay( Node* T ) 
{
    // diagnostic code can be installed here
    return;
}


private:
//pre order helper X in ALL IS THE ROOT
void preorder(Node *x) const
{
    if(x == nil)
    {
        return;
    }
    cout << x->value << ' ';
    preorder(x->left);
    preorder(x->right);
}

//post order helper
void postorder(Node *x) const
{
    if(x == nil)
    {
        return;
    }
    postorder(x->left);
    postorder(x->right);
    cout << x->value << ' ';
}

void inorder(Node *x) const
{
    if(x == nil)
    {
        return;
    }
    inorder(x->left);
    cout << x->value << ' ';
    inorder(x->right);
}

int find(Node *x, int n) //x root, n = num
{
    find(x->left, n);
    --n;
    if(n == 0)
    {
        return x->value;
    }
    find(x->right, n);
    return -1;
}
}; //  end ofBST
#endif
