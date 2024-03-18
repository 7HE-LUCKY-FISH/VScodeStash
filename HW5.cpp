#include <iostream>
using namespace std;

void printSpaces(int space) {
    if (space == 0)
        return;
    cout << " ";
    printSpaces(space - 1);
}

void printStars(int stars) {
    if (stars == 0)
        return;
    cout << "* ";
    printStars(stars - 1);
}

void printDiamond(int n, int currRow) {
    if (currRow > n){ 
        return;
    }
    printSpaces(n - currRow);
    printStars(currRow);
    cout << endl; 
    /*
    if (currRow == n) {
        printDiamond(n - 1, currRow + 1);
    } else {
        printDiamond(n, currRow + 1);
    }
    */
   printDiamond(n, currRow+1);
    if (currRow < n) {
        printSpaces(n - currRow);
        printStars(currRow);
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Enter the number of rows for the diamond's half: ";
    cin >> n;
    printDiamond(n, 1);
    return 0;
}