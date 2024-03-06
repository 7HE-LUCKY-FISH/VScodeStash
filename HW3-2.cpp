#include <map>
#include <iostream>
#include <string>
using namespace std;
int main(){
    map<string,string> instructormap;
    instructormap["CS101"] = "Haynes";
    instructormap["CS102"] = "Alvarado";
    instructormap["CS103"] = "Rich";
    instructormap["NT110"] = "Burke";
    instructormap["CM241"] ="Lee";
    map<string,string> timemap;
    timemap["CS101"] = "8:00a.m.";
    timemap["CS102"] ="9:00a.m.";
    timemap["CS103"] ="10:00a.m.";
    timemap["NT110"]="11:00a.m.";
    timemap["CM241"]="1:00p.m.";
    map<string,int> roomNumber {
    {"CS101", 3004}, {"CS102", 4501},{"CS103",6755},{"NT110",1244} ,{"CM241",1411}
    };


    string user_input;
    cout<<"Enter class name: ";
    cin>> user_input;
    auto roomIter = roomNumber.find(user_input);
    auto instructorIter = instructormap.find(user_input);
    auto timeIter = timemap.find(user_input);
    if (roomIter != roomNumber.end() && instructorIter != instructormap.end() && timeIter != timemap.end()) {
        cout << "Room Number: " << roomIter->second << endl;
        cout << "Instructor: " << instructorIter->second << endl;
        cout << "Time: " << timeIter->second << endl;
    } else {
        cout << "Class not found." << endl;
    }

    return 0;
}