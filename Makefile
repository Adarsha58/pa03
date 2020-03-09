all: avl

#bst: AVL.o	
#	g++ AVL.o -o bst

avl: AVL.o BST.o
	g++ AVL.o BST.o -o avl

clean: 
	rm bst avl *.o
