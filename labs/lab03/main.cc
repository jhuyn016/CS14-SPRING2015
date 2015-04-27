#include "TwoStackFixed.h"






int main()
{
    
    TwoStackedFixed ts(5, 4);
    ts.pushStack1(5);
    ts.pushStack2(10);
    ts.pushStack2(15);
    ts.pushStack1(11);
    ts.pushStack2(7);
    
    // cout << "Popped element from stack1 is " << ts.popStack1();
    // ts.pushStack2(40);
    // cout << "\nPopped element from stack2 is " << ts.popStack2();
    return 0;
}