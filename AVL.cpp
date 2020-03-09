#include "AVL.h"
#include <iostream>
#include <sstream>
using namespace std;

int AVL::heightOfTree(Node* n){
    if(!n) return 0;
    int l = heightOfTree(n->left);
    int r = heightOfTree(n->right);
    int max = (l > r) ? l : r;
    return 1 + max;

}

void AVL::balance(Node*){
    cout<< "Balance Needed"<<endl;
}

void AVL::llRotation(Node* n){
    cout<< "llrotation"<<endl;
    Node* l = n ->left;
    l->parent= n->parent;
  
    if(n->parent && n == n->parent->left) n->parent->left = l;
    if(n->parent && n == n->parent->left) n->parent->left = l;
  
    n->left = l->right;
    if(l->right) l->right->parent = n;
    
    l->right = n;
    n->parent = l;

    if(n == root) root = l;
}

void AVL::rrRotation(Node* n){
    cout<< "rrRotation"<<endl;
    Node* r = n->right; 
    r->parent = n->parent;

    if(n->parent && n == n->parent->left) n->parent->left = r;
    if(n->parent && n == n->parent->right) n->parent->right = r;

    n->right = r->left;
    if(r->left) r->left->parent = n;

    r->left = n;
    n->parent = r;

    if(n == root) root = r; 
}

void AVL::lrRotation(Node* n){
    cout<< "lrRotation"<<endl; 
    rrRotation(n->left);
    llRotation(n);
}

void AVL::rlRotation(Node* n){
    cout<< "rlRotation"<<endl;
    llRotation(n->right);
    rrRotation(n);
}

void AVL::insert(int value){
    Node* itr = BST::insert(value); //this is the node which is just inserted to BST
    if(!itr) {
        return;
    }
    string rotation = "";
    while(itr){
        int heightDifference = heightOfTree(itr->left) - heightOfTree(itr->right);
        if(heightDifference > 1 || heightDifference < -1){
            string tmp = rotation.substr(rotation.length()-2, 2);
            cout<< "string = "<< tmp<<endl;
            if(tmp.compare("ll") == 0){
                llRotation(itr);
            }else if(tmp.compare("rr") == 0){
                rrRotation(itr);
            }else if(tmp.compare("lr") == 0){
                rlRotation(itr);
            }else{
                lrRotation(itr);
            }
            return;
        }
        
        if(itr->parent && itr == itr->parent->left) rotation = rotation + "l";
        if(itr->parent && itr == itr->parent->right) rotation = rotation + "r";

        itr = itr->parent; 
    }
}

void AVL::remove(int){
    //stub
}

int main(int argc, char** argv){
    AVL b; 
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
    }
    return 0;
}