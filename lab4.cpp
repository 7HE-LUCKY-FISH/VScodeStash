#include "linkedlist.h"
#include "linkedlist.cpp"
#include <iostream>
using namespace std;


int main() {
    srand(static_cast<unsigned>(time(0))); 
    LinkedList list1, list2;
    int commonData = rand() % 100;
    list1.insertion(commonData, 1);
    list2.insertion(commonData, 1);

    for (int i = 0; i < 5; ++i) {
        list1.insertion(rand() % 100, i + 2); 
        list2.insertion(rand() % 100, i + 2);
    }

    cout << "List 1 before merge:" <<endl;
    list1.display();
    cout << "List 2 before merge:" << endl;
    list2.display();

    list1.merge(list1.head, list2.head);

    cout << "List 1 after merge:" << endl;
    list1.display();
    list1.deleteDuplicates(list1.head);

    cout << "List 1 after deleting duplicates:" << endl;
    list1.display();

    return 0;
}