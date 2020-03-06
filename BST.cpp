#include "BST.h"
#include <iostream>
#include <stack>
using namespace std; 

void BST:: insert(int value){
    Node* n = new Node(value, NULL, NULL, NULL); 
    if(!root){
        root = n; 
        return; 
    }
    Node* itr = root;
    //finding the right position for the iterator
    while(itr-> left || itr->right){
        if(itr->value == value){
            cout<< "Element already present"<<endl;
            return; 
        }
        if(itr->value < value && itr->right) {
            itr = itr-> right;
        }else if(itr->value > value && itr->left){
            itr = itr-> left;
        }else{
            break;
        }
    }
    if(value > itr->value){
        itr->right = n; 
        n->parent = itr; 
    }else if(value < itr->value){
        itr->left = n; 
        n->parent = itr; 
    }
    cout<< "Element inserted"<<endl; 
}

Node* BST:: access(int value){
    Node* tmp = root; 
    while(tmp){
        if(tmp->value == value){
            return tmp; 
        }
        if(tmp->value > value){
            tmp = tmp->left; 
        }else{
            tmp = tmp->right;
        }
    }
    return NULL; 
}

void BST:: lookup(int value){
    if(access(value)){
        cout<< "Element accessed"<<endl;
    }else{
        cout<< "Element not found"<< endl;
    }
}

void BST:: remove(int value){
    Node* tmp = access(value); //this is the node to be deleted
    if(!tmp){
        cout<< "Element not found"<<endl; 
        return; 
    }
    cout<< "Element deleted"<<endl;
    //no children
    if(!tmp->left && !tmp->right){
        if(root == tmp){
            root = NULL;
        }else if(tmp == tmp->parent->left){ //if it is left child
            tmp->parent->left = NULL;
        }else{
            tmp->parent->right = NULL; //if the node to be deleted is right child
        }
        delete tmp; 
        return; 
    }
    //one children - right child exist 
    if(!tmp->left && tmp->right){
        if(tmp == root){
            root = tmp->right;
        }else if(tmp == tmp->parent->left){ //if it is left child
            tmp->parent->left = tmp->right;
            tmp->right->parent = tmp->parent;
        }else{
            tmp->parent->right = tmp->right; //if the node to be deleted is right child
            tmp->right->parent = tmp->right; 
        }
        delete tmp; 
        return; 
    }   
    //one children - left child exist
    if(tmp->left && !tmp->right){
        cout<< "Left child case"<< endl;
        if(tmp == root){
            root = tmp ->left; 
        }else if(tmp == tmp->parent->left){ //if it is left child
            tmp->parent->left = tmp->left;
            tmp->left->parent = tmp->parent;
        }else{
            tmp->parent->right = tmp->left; //if the node to be deleted is right child
            tmp->left->parent = tmp->parent;
        }
        delete tmp; 
        return;
    }  
    //two children - replace with the successor
    if(tmp->left && tmp->right){
        //find successor node first
        Node* succesor = tmp->right;
        while(succesor->left){
            succesor = succesor->left; 
        }        
        tmp->value = succesor->value; //replacing the vlaue of the succesor to the node to be deleted
        if(succesor == succesor->parent->left){ //if it is left child
            if(!succesor->right){
               succesor->parent->left = NULL;
            }else if(succesor->right){
                succesor->parent->left = succesor->right; 
                succesor->right->parent = succesor->parent;
            }
        }else{
            if(!succesor->right){
                succesor->parent->right = NULL; //if the successor is right child
            }else if(succesor->right){
                succesor->parent->right = succesor->right; 
                succesor->right->parent = succesor->parent;
            }
        }
        delete succesor;
        return;
    }
}

void BST:: preOrder(){
    stack<Node*> s;
    s.push(root);
    while(!s.empty()){
        cout<< s.top()->value<< " ";
        Node* tmp = s.top();
        s.pop();
        if(tmp->right) s.push(tmp->right);
        if(tmp->left) s.push(tmp->left);
    }
}

void BST::inOrder(){
    if(!root){
        cout<< "";
        return;
    }
    stack<Node*> s; 
    s.push(root);
    int i =0;
    while(i!=2){
        Node* tmp = s.top();
        while(tmp->left){
            s.push(tmp->left);
            tmp = tmp->left;
        }
        cout<< s.top()->value<< " ";
        s.pop();
        if(tmp->right) s.push(tmp->right);
        i++;
    }
}


void BST:: print(){
    preOrder();
    cout<< endl;
    inOrder();
}

void BST:: printBsf(){

}

int main(){
    
    BST b;
    b.insert(20);
    b.insert(10);
    b.insert(30);
    b.insert(5);
    b.insert(15);
    b.insert(25);
    b.insert(35);
    b.insert(4);
    b.insert(11);
    b.insert(22);
    b.insert(27);
    b.insert(40);
    b.print();

}