#include<iostream>
#include<vector>
#include<unordered_map>
#include<fstream>
#include<string>
using namespace std;


vector<string> keywords = {
    "auto", "break", "case", "char", "const", "continue", "default", "do",
    "double", "else", "enum", "extern", "float", "for", "goto", "if",
    "int", "long", "register", "return", "short", "signed", "sizeof",
    "static", "struct", "switch", "typedef", "union", "unsigned",
    "void", "volatile", "while"
};  

bool isKeyword(string word){
    for (const string& keyword : keywords) {
        if (word == keyword) {
            return true;
        }
    }
    return false;
}
int main(){
    unordered_map<string,int>freq;
    string filename;
    cout<<"Enter the file name:";
    cin>>filename;

    ifstream file(filename);

    if (!file.is_open()){
        cerr << "Error: Could not open file " << filename << endl;
        return 1;
    }

    string words;
    while(file >> words){
        if(isKeyword(words)){
            freq[words]++;
        }
    }

    for(auto it:freq){
        cout<<it.first<<"  freq is => "<< it.second<<endl;
    }

    return 0;
}


