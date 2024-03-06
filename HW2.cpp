#include <iostream>
using namespace std;
#include "linkedlistType.h"
#include "car.h"
 int main() {
    // Example usage with int
    cout<<"Copy List"<<endl;
    unorderedLinkedList<int> intList;
    intList.display(); // Output: (empty)

    intList.insert(10);
    intList.insert(20);
    intList.insert(30);
    intList.display(); // Output: 30 20 10

    // Copy constructor usage with int
    unorderedLinkedList<int> copiedIntList(intList);
    copiedIntList.deleteNodeWithSmallestInfo();
    copiedIntList.display();

    cout<<"Ordered double list. "<<endl;
    OrderedLinkedList<double> doubleList;
    doubleList.insert(10.5);
    doubleList.insert(5.3);
    doubleList.insert(20.1);
    doubleList.insert(5.3);
    doubleList.display(); // Output: 10 5 20 3

    // Delete node with smallest info
    doubleList.deleteSmallest();
    doubleList.display();
    cout<<"Element is: "<<doubleList.getkelement(2)<<endl;

    cout<<"Char list"<<endl;
    unorderedLinkedList<char> charList;

    charList.insert('A');
    charList.insert('B');
    charList.insert('C');
    charList.insert('B');
    charList.insert('D');
    charList.display();
    charList.deleteAllOccurrences('B');
    cout << "List after deleting all occurrences of B: ";
    charList.display();


    cout<<"Delete at point"<<endl;
    unorderedLinkedList<int> listdelete;
    listdelete.insert(10);
    listdelete.insert(20);
    listdelete.insert(30);
    
    listdelete.deleteAt(1);
    listdelete.display();
    cout<<"Object list"<<endl;
    unorderedLinkedList<Car> carList;
    Car car1(2009, "Jeep");
    Car car2(2020, "Toyota");
    Car car3(2005, "Honda");
    Car car4(2019, "Jeep");

    carList.insert(car1);
    carList.insert(car2);
    carList.insert(car3);
    carList.insert(car4);

    carList.deleteSmallest();

    //carList.deleteAt(1);
    carList.display();
    return 0;
}