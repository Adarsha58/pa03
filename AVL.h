#include "BST.h"
class AVL: public BST{
    public:
        AVL():BST() {}
        void insert(int);
        void remove(int);
}