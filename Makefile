all: bst avl

bst: BST.o	
	g++ BST.o -o bst

avl: AVL.o BST.o
	g++ AVL.o BST.o -o avl

clean: 
	rm bst avl *.o