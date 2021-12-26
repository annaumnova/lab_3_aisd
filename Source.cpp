//binary search tree
#include <iostream>
#include <stdio.h>
#include "Binary_tree_search.h"
#include "iterators.h"
int main()
{
	std::cout << "tree: " << std::endl;
	BinaryTreeSearch tree(8);
	
//	std::cout << tree.contains(4) << std::endl;
	tree.insert(9);
	//tree.insert(8);
	//tree.insert(7);
	//tree.remove(9);
	//tree.insert(99);
	
	
	tree.insert(5);
	tree.print();

/*
		iterators* bft_iterator = tree.create_bft_iterator();
		std::cout << "in width :"<<std::endl;
		while (bft_iterator->has_next())
			std::cout << bft_iterator->next() << ' ';
		std::cout << std::endl;

		iterators* dft_iterator = tree.create_dft_iterator();
		std::cout << "in depth: "<<std::endl;
		while (dft_iterator->has_next())
			std::cout << dft_iterator->next() << ' ';
		std::cout << std::endl;
	*/
	return 0;
}