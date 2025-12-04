#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<fstream>
using namespace std;

unordered_map<char, vector<string>> firstSets;

void findFirst(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Error: Could not open file " << filename << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        if (line.size() < 3) continue; 
        
        char nonTerminal = line[0]; 
        size_t pos = line.find("->"); // pos tells where "->" is located
        // if not found Position of '->': 18446744073709551615 which is not in line
        cout<<"Position of '->': "<<pos<<endl;
        if (pos == string::npos) continue; // string::npos tells that "->" is not found

       
        string rhs = line.substr(pos + 2);

        if (rhs.empty()) continue;

        char firstSymbol = rhs[0];

        if (firstSymbol >= 'A' && firstSymbol <= 'Z') {
            firstSets[nonTerminal].push_back("First(" + string(1, firstSymbol) + ")");
        }
        else if (firstSymbol >= 'a' && firstSymbol <= 'z') {
            firstSets[nonTerminal].push_back(string(1, firstSymbol));
        }
        else {
            firstSets[nonTerminal].push_back(string(1, firstSymbol));
        }
    }

    // Display results
    cout << "\nComputed First Sets:\n";
    for (auto &entry : firstSets) {
        cout << "First(" << entry.first << ") = { ";
        for (auto &val : entry.second) {
            cout << val << " ";
        }
        cout << "}\n";
    }

    file.close();
}

int main(){
    string filename;
    cout << "Enter the filename: ";
    cin >> filename;

    findFirst(filename);
    return 0;
}
