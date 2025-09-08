#include<iostream>
#include<string>
#include<algorithm>
#include<unordered_map>
using namespace std;

unordered_map<string, bool> Keywords = {
    {"auto", 1}, {"break", 1}, {"case", 1}, {"char", 1}, {"const", 1},
    {"continue", 1}, {"default", 1}, {"do", 1}, {"double", 1}, {"else", 1},
    {"enum", 1}, {"extern", 1}, {"float", 1}, {"for", 1}, {"goto", 1},
    {"if", 1}, {"inline", 1}, {"int", 1}, {"long", 1}, {"register", 1},
    {"return", 1}, {"short", 1}, {"signed", 1}, {"sizeof", 1},
    {"static", 1}, {"struct", 1}, {"switch", 1}, {"typedef", 1},
    {"union", 1}, {"unsigned", 1}, {"void", 1}, {"volatile", 1},
    {"while", 1}
};
int main(){
    string input;
    cout << "Enter a C++ keyword: ";
    cin >> input;


    for(int i=0; i<input.length(); i++)
    {
        if(input[i] <='Z' && input[i] >='A')
        {
            input[i] = input[i] + 32; // Convert uppercase to lowercase 
        }
    }
    cout << "Checking for keyword: " << input << endl;
    if(Keywords.find(input) != Keywords.end()){
        cout << input << " is  a keyword"<< endl;
    } else {
        cout << input << " is not a keyword" << endl;
    }
    return 0;

}
