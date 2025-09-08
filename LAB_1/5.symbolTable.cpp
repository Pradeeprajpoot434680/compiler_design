#include<iostream>
#include<string>
#include<unordered_map>
#include<vector>
using namespace std;

struct symbolEntry {
    string type;
    string scope;
};


unordered_map<string, symbolEntry> symbolTable;

void insert(){
    string name, type;
    string scope;
    cout<<"Enter the variable name (valid name): ";
    cin>>name;
    cout<<"Enter the variable type (enter valid type): ";
    cin>>type;
    if(type != "int" && type != "float" && type != "char" && type != "double" && type != "void" && type != "long" && type != "short" && type != "bool"){
        cout<<"Error: Invalid variable type. Please enter 'int', 'float', or 'char'."<<endl;
        return;
    }
    cout<<"Enter the scope level (global/local): ";
    cin>>scope;
    if(scope != "global" && scope != "local"){
        cout<<"Error: Invalid scope level. Please enter 'global' or 'local'."<<endl;
        return;
    }
    if(type != "int" && type != "float" && type != "char" && type != "double" && type != "void" && type != "long" && type != "short" && type != "bool"){
        cout<<"Error: Invalid variable type. Please enter 'int', 'float', or 'char'."<<endl;
        return;
    }
    

    if(symbolTable.find(name) != symbolTable.end()){
        cout<<"Error: Variable "<<name<<" already exists in the symbol table."<<endl;
        return;
    }

    symbolTable[name] = {type, scope};
    cout<<"Inserted "<<name<<" into symbol table."<<endl;
}

void deleteEntry(){
    string name;
    cout<<"Enter the variable name to delete: ";
    cin>>name;

    if(symbolTable.find(name) == symbolTable.end()){
        cout<<"Error: Variable "<<name<<" not found in the symbol table."<<endl;
        return;
    }

    symbolTable.erase(name);
    cout<<"Deleted "<<name<<" from symbol table."<<endl;
}

void displayTable(){
    cout<<"Symbol Table Contents:"<<endl;
    cout<<"*******************Symbol Table ********************"<<endl;
    for(const auto& entry : symbolTable){
        cout<<"Name: "<<entry.first<<", Type: "<<entry.second.type<<", Scope: "<<entry.second.scope<<endl;
    }
    cout<<"***************************************************"<<endl;
}
int main(){
    int choice;
    while(1){
        cout<<"Enter 1 to add an Entry in Symbol Table: "<<endl;
        cout<<"Enter 2 to delete an Entry from symbol table: "<<endl;
        cout<<"Enter 3 to display the symbol table content: "<<endl;
        cout<<"4 for Exit: "<<endl;
        cin>>choice;

        if(choice == 1){
            insert();
        }
        else if( choice == 2){
            deleteEntry();
        }
        else if( choice == 3){
            displayTable();
        }
        else {
            break;
        }
    }
   

    return 0;
}
