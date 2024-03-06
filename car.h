#ifndef Car_h
#define Car_h
#include <string>
using namespace std;
class Car
{
private:
    int year;
    string model;

public:
    Car()
    {
        year = 0;
        model = "No Model";
    }
    Car(int y, string m)
    {
        year = y;
        model = m;
    }
    bool operator==(const Car &c) const
    {
        if (year == c.year && model == c.model)
            return true;
        return false;
    }
    bool operator<(const Car &c) const {
        // You can define the comparison logic based on your requirements.
        // For example, compare first based on year, and then on model if the years are equal.
        if (year < c.year)
            return true;
        else if (year == c.year)
            return model < c.model;
        else
            return false;
    }
    friend ostream& operator<<(ostream& os, const Car& c);
};
#endif /* Car_h */
// Define the overloaded << operator
ostream& operator<<(ostream& os, const Car& c) {
    os << "Year: " << c.year << ", Model: " << c.model;
    return os;
}