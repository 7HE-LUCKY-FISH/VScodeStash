#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    srand(static_cast<unsigned int>(time(nullptr)));
    map<string, string> stateCapitalMap;
    ifstream file("states.txt");
    if (!file)
    {
        cerr << "Error opening file states.txt\n";
        return 1;
    }
    string line;
    while (getline(file, line))
    {
        size_t pos = line.find(',');
        if (pos != string::npos)
        {
            string state = line.substr(0, pos);
            string capital = line.substr(pos + 1);
            stateCapitalMap[state] = capital;
        }
    }
    file.close();

    while (true)
    {
        cout << "Type the capital of the given state. Type 'exit' to quit." << endl;

        auto it = stateCapitalMap.begin();
        advance(it, rand() % stateCapitalMap.size());
        string state = it->first;
        string capital = it->second;

        string userAnswer;
        cout << "What is the capital of " << state << "? ";
        getline(cin, userAnswer);

        if (userAnswer == "exit")
        {
            cout << "Exiting the quiz." << endl;
            break;
        }
        else if (userAnswer == capital)
        {
            cout << "Correct. The capital of " << state << " is " << capital << "." << endl;
        }
        else
        {
            cout << "Incorrect. The capital of " << state << " is " << capital << "." << endl;
        }
    }

    return 0;
}