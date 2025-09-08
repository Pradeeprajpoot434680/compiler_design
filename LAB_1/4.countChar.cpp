#include<iostream>
#include<string>
#include<vector>
#include<fstream>
using namespace std;

vector<int> charCount(256, 0);

int main(){
    
    string filename;
    cout<<"Enter the filename:";
    cin>>filename;
    ifstream file(filename);
    if(!file.is_open()){
        cout<<"Error while file opening";
        return 1;
    }

    char ch;
    while(file.get(ch))
    {
        charCount[ch]++;
    }

    for(int i = 0; i < 256; i++)
    {
        if(charCount[i] > 0)
        {
            cout << "Character '" << char(i) << "' : " << charCount[i] << endl;
        }
    }

    return 0;
}

