#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>

using namespace std;

vector<string> keywords = {
    "auto", "break", "case", "char", "const", "continue", "default", "do",
    "double", "else", "enum", "extern", "float", "for", "goto", "if",
    "int", "long", "register", "return", "short", "signed", "sizeof",
    "static", "struct", "switch", "typedef", "union", "unsigned",
    "void", "volatile", "while"
};


bool isKeyword(const string& word) 
{
    for (const string& keyword : keywords) {
        if (word == keyword) {
            return true;
        }
    }
    return false;
}


int main(){
    string word;
    cout<<"Enter a word: ";
    cin>>word;
    if(isKeyword(word)){
        cout<<word<<" is a keyword."<<endl;
    }else{
        cout<<word<<" is not a keyword."<<endl;
    }
    return 0;
}