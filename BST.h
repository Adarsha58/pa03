struct Node{
    int value; 
    Node* parent;
    Node* left;
    Node* right;
    Node(int v, Node* p, Node* l, Node* r): value(v), parent(p), left(l), right(r) {}
};

class BST{    
    private:
        Node* root; 
        Node* access(int);
        void preOrder();
        void inOrder();
        void postOrder();
    public: 
        BST(): root(0) {}
        void insert(int);
        void lookup(int);
        void remove(int);
        void print();
        void printBsf();
};