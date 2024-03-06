#include "car.h"
#include "arraylistType.h"
using namespace std;
int main()
{

    arrayListType<Car> carList(10);
    Car car1(2009, "Jeep");
    Car car2(2020, "Toyota");
    Car car3(2005, "Honda");
    Car car4(2019, "Jeep");

    carList.insertEnd(car1);
    carList.insertEnd(car2);
    carList.insertEnd(car3);
    carList.insertEnd(car4);

    int year;
    string model;
    cout << "Enter year of the car: ";
    cin >> year;
    cout << "Enter model of the car: ";
    cin >> model;
    // Example car to search for
    Car searchCar(year, model);
    int index = carList.sequentialSearch(searchCar);

    if (index != -1)
    {
        cout << "Car found at index: " << index << endl;
    }
    else
    {
        cout << "Car not found in the list." << endl;
    }

    arrayListType<int> intList(5); // Create a list for integers with a max size of 5

    // Insert integers
    intList.insertEnd(10);
    intList.insertEnd(20);
    intList.insertEnd(30);
    intList.insertEnd(40);
    intList.insertEnd(50);

    cout << "Integer List: ";
    intList.print(); // Print the integer list

    // Search for an integer
    int searchInt = 30;
    int intLocation = intList.sequentialSearch(searchInt);
    if (intLocation != -1)
    {
        cout << "Integer " << searchInt << " found at location: " << intLocation << endl;
    }
    else
    {
        cout << "Integer " << searchInt << " not found in the list." << endl;
    }

    // Test case for doubles
    arrayListType<double> doubleList(5); // Create a list for doubles with a max size of 5

    // Insert doubles
    doubleList.insertEnd(10.1);
    doubleList.insertEnd(20.2);
    doubleList.insertEnd(30.3);
    doubleList.insertEnd(40.4);
    doubleList.insertEnd(50.5);

    cout << "Double List: \n";
    doubleList.print(); // Print the double list

    // Search for a double
    double searchDouble = 30.3;
    int doubleLocation = doubleList.sequentialSearch(searchDouble);
    if (doubleLocation != -1)
    {
        cout << "Double " << searchDouble << " found at location: " << doubleLocation << endl;
    }
    else
    {
        cout << "Double " << searchDouble << " not found in the list." << endl;
    }
    return 0;
}
