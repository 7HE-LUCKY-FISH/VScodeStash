#include <iostream>
#include <vector>
#include <stack>
#include "myStack.h"
//#include "stackADT.h"
using namespace std;
void testCopyConstructor(stackType<int> otherStack);
int main()
{
    stackType<int> stack(50);
    stackType<int> copyStack(50);
    stackType<int> dummyStack(100);
    stack.initializeStack();
    stack.push(85);
    stack.push(28);
    stack.push(56);
    copyStack = stack; // copy stack into copyStack
    cout << "The elements of copyStack: ";
    while (!copyStack.isEmptyStack()) // print copyStack
    {
        cout << copyStack.top() << " ";
        copyStack.pop();
    }
    cout << endl;
    copyStack = stack;
    testCopyConstructor(stack); // test the copy constructor
    if (!stack.isEmptyStack())
        cout << "The original stack is not empty." << endl
             << "The top element of the original stack: "
             << copyStack.top() << endl;
    dummyStack = stack; // copy stack into dummyStack
    cout << "The elements of dummyStack: ";
    while (!dummyStack.isEmptyStack()) // print dummyStack
    {
        cout << dummyStack.top() << " ";
        dummyStack.pop();
    }

    //testing reversed stack
    stackType<int> myStack;
    stackType<int> reversedStack;
    for (int i = 1; i <= 5; ++i) {
        myStack.push(i);
    }
    

    
    myStack.reverseStack(reversedStack);
    cout<<"\nNormal Stack"<<endl;
    while(!myStack.isEmptyStack()){
        cout<<myStack.top()<<" ";
        myStack.pop();
    }

    cout << "\nReversed Stack: "<<endl;
    while (!reversedStack.isEmptyStack()) {
    cout << reversedStack.top() << " ";
        reversedStack.pop();
    }


    cout << endl;
    return 0;
}
void testCopyConstructor(stackType<int> otherStack)
{
    if (!otherStack.isEmptyStack())
        cout << "otherStack is not empty." << endl
             << "The top element of otherStack: "
             << otherStack.top() << endl;
}
