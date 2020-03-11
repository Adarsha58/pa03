#include "BST.h"
#include <iostream>
#include <stack>
#include <vector>
using namespace std; 

BST:: ~BST(){
    clear(root);
}

void BST:: clear(Node* n){
    if(!n) return;
    clear(n->left);
    clear(n->right);
    delete n;
}

Node* BST:: insert(int value){
    Node* n = new Node(value, NULL, NULL, NULL); 
    if(!root){
        root = n; 
        cout<< "Element inserted"<<endl; 
        return root; 
    }

    if(access(value)){
            cout<< "Element already present"<<endl;
            delete n;
            return NULL; 
    }

    Node* itr = root;
    //finding the right position for the iterator
    while(itr-> left || itr->right){
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
    return n;
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

Node* BST:: remove(int value){
    Node* tmp = access(value); //this is the node to be deleted
    if(!tmp){
        cout<< "Element not found"<<endl; 
        return NULL; 
    }
    Node* parent = tmp->parent;
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
        return parent; 
    }
    //one children - right child exist 
    if(!tmp->left && tmp->right){
        if(tmp == root){
            root = tmp->right;
            parent = root; 
        }else if(tmp == tmp->parent->left){ //if it is left child
            tmp->parent->left = tmp->right;
            tmp->right->parent = tmp->parent;
        }else{
            tmp->parent->right = tmp->right; //if the node to be deleted is right child
            tmp->right->parent = tmp->right; 
        }
        delete tmp; 
        return parent; 
    }   
    //one children - left child exist
    if(tmp->left && !tmp->right){
        if(tmp == root){
            root = tmp ->left;
            parent = root;  
        }else if(tmp == tmp->parent->left){ //if it is left child
            tmp->parent->left = tmp->left;
            tmp->left->parent = tmp->parent;
        }else{
            tmp->parent->right = tmp->left; //if the node to be deleted is right child
            tmp->left->parent = tmp->parent;
        }
        delete tmp; 
        return parent;
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
        return tmp;
    }
    return parent;
}

void BST:: preOrder(){
    if(!root){
        cout<< "Empty tree"<<endl;
        return;
    }
    stack<Node*> s;
    s.push(root);
    while(!s.empty()){
        cout<< s.top()->value<< " ";
        Node* tmp = s.top();
        s.pop();
        if(tmp->right) s.push(tmp->right);
        if(tmp->left) s.push(tmp->left);
    }
    cout<<endl;
}

void BST::inOrder(){
    if(!root){
        return;
    }
    Node* max = root; 
    while(max->right){
        max = max->right;
    }

    Node* min = root;
    while(min->left){
        min = min->left;
    }

    while(min != max){
        cout<< min->value <<" ";
        if(min->right){
            min = min->right;
            while(min->left){
                min = min ->left;
            }
        }else{
            while(min->parent && min->parent->value < min->value){
                min = min->parent;
            }
            min = min->parent;
        }
    }
    cout<< max->value<< " "<<endl;

}

void BST::postOrder(){
    if(!root){
        return;
    }
    stack<Node*> s1, s2;
    s1.push(root);
    while(!s1.empty()){
        Node* tmp = s1.top();
        s1.pop();
        s2.push(tmp);
        if(tmp->left) s1.push(tmp->left);
        if(tmp->right) s1.push(tmp->right);
    }
    while(!s2.empty()){
        cout<< s2.top()->value<< " ";
        s2.pop();
    }
    cout<<endl;
}

void BST:: print(){
    preOrder();
    inOrder();
    postOrder();
}

//uses stack and vector
void BST:: printBfs(){
    if(!root){
        cout<< "Empty Tree"<<endl;
        return;
    }
    stack<Node*> s;
    vector<Node*> v;
    s.push(root);
    v.push_back(root);
    int start = 0;
    while(!s.empty()){
        while(!s.empty()){
            Node* tmp = s.top();
            if(tmp->left) v.push_back(tmp->left);
            if(tmp->right) v.push_back(tmp->right);
            s.pop();
            start++;
        }
        for(int i = v.size() -1; i >= start; i--){
            s.push(v[i]);
        }
    }

    for(int i = 0; i < v.size(); i++){
        cout<< v[i]->value << " ";
    }
    cout<< endl;
}
