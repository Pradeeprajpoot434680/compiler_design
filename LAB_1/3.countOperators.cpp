#include<iostream>
#include<string>
#include<fstream>
#include<unordered_map>
#include<vector>
using namespace std;

vector<string> operators = {
    "+", "-", "*", "/", "%", "++", "--",
    "=", "+=", "-=", "*=", "/=", "%=",
    "==", "!=", ">", "<", ">=", "<=",
    "&&", "||", "!", "&", "|", "^", "~",
    "<<", ">>", ">>=", "<<=", "&=", "|=", "^=",
    "?", ":", "->", ".", ".*", "->*"
};

bool isOperator(string op)
{
    for(int i=0; i<operators.size(); i++)
    {
        if(op == operators[i])
        {
            return true;
        }
    }
    return false;
}

int main(){
    string filename;
    cout<<"Enter the filename:";
    cin>>filename;
    unordered_map<string, int> operatorCount;
    ifstream file(filename);
    if(!file.is_open()){
        cout<<"Error while file opening";
        return 1;
    }

    string op;
    while(file >> op)
    {
        if(isOperator(op))
        {
            operatorCount[op]++;
        }
    }

    cout << "Operator count:" << endl;
    for(const auto& pair : operatorCount)
    {
        cout << pair.first << ": " << pair.second << endl;
    }

    return 0;
}