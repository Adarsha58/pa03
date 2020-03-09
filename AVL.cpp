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

int main(){
    AVL a; 
    a.insert(5);
    a.insert(3);
    a.insert(8);
    a.insert(2);
    a.insert(4);
    a.insert(7);
    a.insert(11);
    a.insert(1);
    a.insert(6);
    a.insert(10);
    a.insert(12);
    a.insert(9);
    a.remove(4);
    a.print();
}