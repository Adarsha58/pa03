#include "BST.h"
#include <string>
class AVL: public BST{
    private:
        int heightOfTree(Node*);
        void balance(Node*);
        void llRotation(Node*);
        void rrRotation(Node*);
        void lrRotation(Node*);
        void rlRotation(Node*);
    
    public:
        AVL():BST() {}
        void insert(int);
        void remove(int);
};