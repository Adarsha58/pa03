#include "BST.h"
#include <sstream>
#include <iostream>
using namespace std; 

int main(int argc, char** argv){
    BST b; 
    if(argc !=2){
        cerr << "Not a valid Inupt"<<endl;
    }
    string input = argv[1];
    istringstream ss(input);
    string token;
    while(std::getline(ss, token, ' ')) {
       if(token == "insert"){
           getline(ss,token,' ');
           int i = stoi(token);
           b.insert(i);
           continue; 
       } 
       if(token == "access"){
           getline(ss,token,' ');
           int i = stoi(token);
           b.lookup(i);
           continue;
       }
       if(token == "delete"){
           getline(ss,token,' ');
           int i = stoi(token);
           b.remove(i);
           continue;
       }
       if(token == "print," || token == "print"){
           b.print();
           continue;
       }
       if(token == "print bfs," || token == "print bfs"){
           b.printBsf();
           continue;
       }
    }
    return 0;
}