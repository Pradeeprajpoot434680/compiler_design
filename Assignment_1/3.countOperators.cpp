//Count total no of operators in a file (taking file from user).

#include <iostream>
#include <fstream>
#include <string>
#include<vector>
#include <unordered_map>        

using namespace std;

unordered_map<string, bool> Operators = {
    {"+", 1}, {"-", 1}, {"*", 1}, {"/", 1}, {"%", 1},
    {"++", 1}, {"--", 1}, {"=", 1}, {"+=", 1}, {"-=", 1},
    {"*=", 1}, {"/=", 1}, {"%=", 1}, {"==", 1}, {"!=", 1},
    {"<", 1}, {">", 1}, {"<=", 1}, {">=", 1}, {"&&", 1},
    {"||", 1}, {"!", 1}
};

int main() {
    string filename;
    cout << "Enter the path of the file: ";
    cin >> filename;

    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Error opening file!" << endl;
        return 1;       
    }
    vector<string>oper;
    int count = 0;  

    string word;
    while (file >> word) {
        // Check if the word is an operator
        if (Operators.find(word) != Operators.end()) {
            count++;        
            oper.push_back(word); // Store the operator
        }
    }   
    file.close();
    cout << "Total number of operators: " << count << endl;
    cout << "Operators found in the file:" << endl;

    for(int i=0; i<oper.size(); i++) {
        cout << oper[i] << endl;
    }
    return 0;
}
