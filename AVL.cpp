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


void AVL::llRotation(Node* n){
    Node* l = n ->left;
    l->parent= n->parent;
  
    if(n->parent && n == n->parent->left) n->parent->left = l;
    if(n->parent && n == n->parent->right) n->parent->right = l;
  
    n->left = l->right;
    if(l->right) l->right->parent = n;
    
    l->right = n;
    n->parent = l;

    if(n == root) root = l;
}

void AVL::rrRotation(Node* n){
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
    rrRotation(n->left);
    llRotation(n);
   if(n == root) root = n -> parent;
}

void AVL::rlRotation(Node* n){
    llRotation(n->right);
    rrRotation(n);
    if(n == root) root = n ->parent;
    
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

void AVL::remove(int value){
    Node* itr = BST::remove(value);
    if(!itr) return;
    while(itr){
        int heightDifference = heightOfTree(itr->left) - heightOfTree(itr->right);
        if(heightDifference < -1){
            if(heightOfTree(itr->right->left) - heightOfTree(itr->right->right) >0){
                rlRotation(itr);
            }else{
                rrRotation(itr);
            }
        }else if (heightDifference > 1){
            if(heightOfTree(itr->left->left) - heightOfTree(itr->left->right) > 0){
                llRotation(itr);
            }else{
                lrRotation(itr);
            }
        }   
        itr = itr->parent;
    }
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
        if(token == "print,"){
           b.print();
           continue;
       }

       if(token == "print"){
           getline(ss, token, ' ');
           if(token == "bfs" || token == "bfs,"){
               b.printBfs();
           }else{
               b.print();
           }
       }
    }
    return 0;
}
