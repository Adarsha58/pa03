all: bst avl

bst: BST.o	
	g++ BST.o -o bst

avl: BST.o
	g++ BST.o -o avl

clean: 
	rm prog1.out *.o