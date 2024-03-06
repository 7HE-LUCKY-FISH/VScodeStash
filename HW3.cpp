#include <iostream>
#include <fstream>
#include <sstream>
#include <set>
#include <cctype>
#include <string>
using namespace std;

string cleanWord(const string& word) {
    string cleaned;
    for (char ch : word) {
        if (isalpha(ch)) {
            cleaned += tolower(ch);
        }
    }
    return cleaned;
}
int main() {
    ifstream inputFile("words.txt");
    if (!inputFile.is_open()) {
        cerr << "Error opening file: "<< endl;
        return 1;  
    }
    set<string> uniqueWords;
    string line;

    //while (getline(inputFile, line)) {
    //    uniqueWords.insert(cleanWord(line));
    //}
    while (inputFile >> line) {
        uniqueWords.insert(cleanWord(line));
    }
    inputFile.close();

    cout << "Unique Words:" << endl;
    for (const auto& uniqueWord : uniqueWords) {
        cout << uniqueWord << endl;
    }
    /*
    set<string>::iterator it;

    for (it= uniqueWords.begin(); it != uniqueWords.end(); it++){
        cout<<*it<<endl;
    } 
    */
    return 0;  
}