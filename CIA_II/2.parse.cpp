// # Question 2: Implement Parsing Algorithms
#include <iostream>
#include <string>
using namespace std;

string input;
int i = 0;

void E();
void T();
void F();

void error() {
    cout << "Error in parsing!" << endl;
    exit(0);
}

void F() {
    if (input[i] == '(') {
        i++;
        E();
        if (input[i] == ')') i++;
        else error();
    } else if (isalpha(input[i])) {
        i++;
    } else {
        error();
    }
}

void T() {
    F();
    while (input[i] == '*') {
        i++;
        F();
    }
}

void E() {
    T();
    while (input[i] == '+') {
        i++;
        T();
    }
}

int main() {
    cout << "Enter expression: ";
    cin >> input;
    input += "$"; // End marker

    E();

    if (input[i] == '$')
        cout << "Parsing successful!" << endl;
    else
        error();
}
