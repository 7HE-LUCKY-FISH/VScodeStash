#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

bool checkpallen(const string &str, int s, int t){
    if (s==t){
        return true;
    }
    if(str[s] != str[t]){
        return false;
    }
    if(s<t){
        return checkpallen(str, s+1, t-1);
    }
    return true;
}
bool ispallen(const string &str){
    int n = str.length();
    if(n==0){
        return true;
    }
    return checkpallen(str, 0, n - 1);
}
string cleanString(const string& input) {
    string cleaned;
    for (char c : input) {
        if (isalnum(c)) { 
            cleaned += tolower(c); 
        }
    }
    return cleaned;
}

int main(){
    const int MAX_LENGTH = 100; 
    char str[MAX_LENGTH];
    cout << "Enter a string: ";
    cin.getline(str, MAX_LENGTH);
    //char str[]= "madam";
    string input(str);
    string cleanedInput = cleanString(input);

    if (ispallen(cleanedInput)){
    cout << "Yes, it is a palindrome";
    }else{
    cout << "Not a palindrome";
    }
    return 0;
}