//Count total no. of keywords in a file (taking file from user)
#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include<vector>
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
    
    string filename;
    vector<string>allKeywords;
    //enter the path of the file and read the file
    cout << "Enter the path of the file: ";
    cin >> filename;
    ifstream file(filename);
    if (!file.is_open()) 
    {
        cout << "Error opening file!" << endl;      
        return 1;
    }
    string word;
    int count = 0;
    while (file >> word) 
    {
        for (char &c : word) 
        {         
            if (c >= 'A' && c <= 'Z') 
            {
                c += 32; 
            }
        }
        // Check if the word is a keyword
        if (Keywords.find(word) != Keywords.end()) 
        {
            count++;    
            allKeywords.push_back(word); // Store the keyword
        }
    }
    file.close();   

    for(int i=0; i<allKeywords.size(); i++)
    {
        cout << allKeywords[i] << endl;
    }
    return 0;
}