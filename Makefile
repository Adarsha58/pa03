all: avl bst

bst: BST.o BSTMain.o
	g++ BST.o  BSTMain.o -o bst

avl: AVL.o BST.o
	g++ AVL.o BST.o -o avl

clean: 
	rm bst avl *.o
