#include "AVL.h"
#include <iostream>
#include <sstream>
using namespace std;

void AVL:insert(int value){
    Node* itr = BST::insert(value); //this is the node which is just inserted to BST
    if(!itr) return;
    
}