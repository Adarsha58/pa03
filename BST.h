struct Node{
    int value; 
    Node* parent;
    Node* left;
    Node* right;
    Node(int v, Node* p, Node* l, Node* r): value(v), parent(p), left(l), right(r) {}
};

class BST{    
    protected:
        Node* root; 
        Node* access(int);
        void preOrder();
        void inOrder();
        void postOrder();
    public:
        ~BST();
        BST(): root(0) {}
        void clear(Node*);
        Node* insert(int);
        void lookup(int);
        Node* remove(int);
        void print();
        void printBfs();
};