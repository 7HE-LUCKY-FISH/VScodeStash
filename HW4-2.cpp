// This program tests various operations of a linked stack
#include <iostream>
#include "linkedStack.h"
using namespace std;
void testCopy(linkedStackType<int> OStack);
int main()
{
    linkedStackType<int> stack;
    linkedStackType<int> otherStack;
    linkedStackType<int> newStack;
    // Add elements into stack
    stack.push(28);
    stack.push(94);
    stack.push(37);
    // Use the assignment operator to copy the elements
    // of stack into newStack
    newStack = stack;
    cout << "After the assignment operator, newStack: "
         << endl;
    // Output the elements of newStack
    while (!newStack.isEmptyStack())
    {
        cout << newStack.top() << endl;
        newStack.pop();
    }
    // Use the assignment operator to copy the elements
    // of stack into otherStack
    otherStack = stack;
    cout << "Testing the copy constructor." << endl;
    testCopy(otherStack);
    cout << "After the copy constructor, otherStack: " << endl;
    while (!otherStack.isEmptyStack())
    {
        cout << otherStack.top() << endl;
        otherStack.pop();
    }

    linkedStackType<int> myStack;
    linkedStackType<int> reversedStack;
    
    for (int i = 1; i <= 5; ++i) {
        myStack.push(i);
    }
    
   myStack.push(677);
   myStack.push(245);
   myStack.push(353);
    myStack.reverseStack(reversedStack);
    cout<<"Normal Stack"<<endl;
    while(!myStack.isEmptyStack()){
        cout<<myStack.top()<<" ";
        myStack.pop();
    }

    cout << "\nReversed Stack: "<<endl;
    while (!reversedStack.isEmptyStack()) {
    cout << reversedStack.top() << " ";
        reversedStack.pop();
    }
    
    return 0;
}
void testCopy(linkedStackType<int> OStack)
{
    cout << "Stack in the function testCopy:" << endl;
    while (!OStack.isEmptyStack())
    {
        cout << OStack.top() << endl;
        OStack.pop();
    }
}