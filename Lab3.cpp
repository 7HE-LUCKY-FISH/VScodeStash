#include "Node.cpp"
#include "Node.h"
#include <iostream>
using namespace std;


int main() {
    LinkedList list;
    LinkedList testlist;
    list.deleteNode(1);
    list.append(1);
    list.append(2);
    list.prepend(5);
    list.prepend(0);
    list.display(); // Should display: 0 1 2

    if(list.search(2)) {
        cout << "Found 2 in the list." << endl;
    }

 
    list.display(); // Should display: 0 2
    list.insertAfter(0,4);
    list.display();

    int userinput;
    for(int i =0;i<5;i++){
        cout<<"Enter a int: ";
        cin>>userinput;
        testlist.append(userinput);
    }
    testlist.display();
    int repapp;
    cout<<"Enter a number to preappend: ";
    cin>>repapp;
    testlist.prepend(repapp);
    testlist.display();

    int searchint;
    cout<<"Enter a number to search: ";
    cin>>searchint;
    if(testlist.search(searchint)){
        cout<<"Item was found. "<<endl;
    }

    return 0;
}