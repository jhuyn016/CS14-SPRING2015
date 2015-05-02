#include "lab4.h"
#include <cstdlib>





int main(int argc, char * argv[])
{
    if(argc != 2)
    {
        cout << "Error " << endl;
        return 0;
    }
    int x = atoi(argv[1]);
    cout << "testing preorder " << endl;
    coPrime(2, 1, x);
    
    cout << endl;
    
    cout << "testing postorder " << endl;
    coPrime2(2, 1, x);
    
    cout << endl;
}