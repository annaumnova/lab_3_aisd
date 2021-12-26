#include <iostream>
#include <stdexcept>
#include "iterators.h"
#include "queue.h"
#include "stack.h"

class BinaryTreeSearch
{
private:
	class tree_elements//class of tree elements (leaves)
	{
	public:
		int data_element;//the information part
		tree_elements* left_elements;//the pointer to the left undertree
		tree_elements* right_elements;//the pointer to the right undertree

		tree_elements(int data)//constructor
		{
			left_elements = NULL;
			right_elements = NULL;
			data_element = data;
		}
		//tree_elements(){};
	};
	tree_elements* root_of_tree;//the root of tree (the beginning)
	//tree_elements* current_root = 0;
	size_t size_tree;//the size of tree (height)

public:
	BinaryTreeSearch()//constructor
	{
		root_of_tree = NULL;
		size_tree = 0;
	}
	BinaryTreeSearch(int key)//constructor
	{
		root_of_tree = new tree_elements(key);
		size_tree = 1;
	}
	~BinaryTreeSearch()//destructor
	{
		delete_tree(root_of_tree);
	}

	void delete_tree(tree_elements* current)//for destructor
	{
		if (current)
		{
			delete_tree(current->left_elements);//left undertree
			delete_tree(current->right_elements);//right undertree
			delete current;
		}
	}
	size_t get_size() const//size
	{
		if (size_tree >= 0)
			return size_tree;
		else throw std::logic_error("Index is out of range");
	}
	bool isEmpty()
	{
		return get_size() == 0;
	}
	void print()//print all tree
	{
		print_tree(root_of_tree);
		std::cout << std::endl;
	}
	void print_tree(tree_elements* current)//print elements
	{
		if (current)//pointer==nullptr???
		{
			print_tree(current->left_elements);//the left
			std::cout << current->data_element << " ";
			print_tree(current->right_elements);//the right
		}
	}

	//methods
	bool contains(int key)//search the element of tree with key
	{
		tree_elements* current = root_of_tree;//the first element
		while (current && current->data_element != key)//passing the tree starting with root
		{
			if (current->data_element > key)//go to the left
				current = current->left_elements;
			else
				current = current->right_elements;//to the right
		}
		return current != NULL;//if it found
	}

	void insert(int key)//add in tree with key
	{
		tree_elements* current = root_of_tree;
		while (current && current->data_element != key)
		{
			if (current->data_element > key && current->left_elements == NULL)//to left
			{
				current->left_elements = new tree_elements(key);
				++size_tree;
				return;
			}
			if (current->data_element < key && current->right_elements == NULL)//to right
			{
				current->right_elements = new tree_elements(key);
				++size_tree;
				return;
			}
			if (current->data_element > key)//if it has "children"
				current = current->left_elements;
			else
				current = current->right_elements;
		}
	}

	void remove(int key)//delete the element with key
	{
		if (get_size() > 0)
		{
			tree_elements* current = root_of_tree;
			tree_elements* parent = NULL;

			while (current && current->data_element != key)
			{
				parent = current;
				if (current->data_element > key)
					current = current->left_elements;
				else
					current = current->right_elements;
			}
			if (!current) return;
			if (current->left_elements == NULL)//if it hasn't got the left undertree take the right undertree
			{
				if (parent && parent->left_elements == current)
					parent->left_elements = current->right_elements;
				if (parent && parent->right_elements == current)
					parent->right_elements = current->right_elements;
				--size_tree;
				delete current;
				return;
			}
			if (current->right_elements == NULL)//take the left undertree
			{
				if (parent && parent->left_elements == current)
					parent->left_elements = current->left_elements;
				if (parent && parent->right_elements == current)
					parent->right_elements = current->left_elements;
				--size_tree;
				delete current;
				return;
			}
			tree_elements* replace = current->right_elements;//it has 2 children, replace the element
			while (replace->left_elements)
				replace = replace->left_elements;
			int replace_value = replace->data_element;
			remove(replace_value);
			current->data_element = replace_value;
		}
	}

	//iterators
	/*iterators* create_dft_iterator();
	iterators* create_bft_iterator();

	//Breadth first traversal
	class bftIterator :public iterators
	{
	private: 
		tree_elements* current;
		tree_elements* root;
		queue list_queue;
		bool check = false;
	public:
		bftIterator(tree_elements* root_curr)//constructor
		{
			current = root;
			list_queue.push(current->data_element);
		}
		bool has_next() override;
		int next() override;
	};

	//Depth first traversal
	class dftIterator : public iterators
	{
	private:
		tree_elements* current;
		tree_elements* root;
		stack list_stack;
		bool check = false;
	public:
		dftIterator(tree_elements* root)//constructor
		{
			current = root;
			list_stack.push_back(current->data_element);
		}
		bool has_next() override;
		int next() override;
	};*/
};

/*
//Breadth first traversal
iterators* BinaryTreeSearch::create_bft_iterator()
{
	return new bftIterator(root_of_tree);
}
int BinaryTreeSearch::bftIterator::next()
{
	if (!has_next())
	{
		throw std::out_of_range("No more elements");
	}
	else 
	{
		int temp = list_queue.top();
		if (check) 
		{
			root = current;
			check = true;
		}
		current = root;

		while (current->data_element != temp)
		{
			if (temp < current->data_element)//to left
				current = current->left_elements;
			if (temp > current->data_element)//to right
				current = current->right_elements;
		}
	if (current->left_elements != NULL)//if not empty undertree
		list_queue.push(current->left_elements->data_element);
	if (current->right_elements != NULL)
		list_queue.push(current->right_elements->data_element);
		return temp;
	}
}
bool BinaryTreeSearch::bftIterator::has_next() 
{
	return !list_queue.isEmpty();
}*/

/*
//Depth first traversal
iterators* BinaryTreeSearch::create_dft_iterator()
{
	return new dftIterator(root_of_tree);
}
int BinaryTreeSearch::dftIterator::next()
{
	if (!has_next())
	{
		throw std::out_of_range("No more elements");
	}
	else
	{
		int temp = list_stack.taketop();
		if (check)
		{
			root = current;
			check = true;
		}
		current = root;

		while (current->data_element != temp)
		{
			if (temp < current->data_element)//to left
				current = current->left_elements;
			if (temp > current->data_element)//to right
				current = current->right_elements;
		}
		if (current->left_elements != NULL)//if not empty undertree
			list_stack.push_back(current->left_elements->data_element);
		if (current->right_elements != NULL)
			list_stack.push_back(current->right_elements->data_element);
		return temp;
	}
}
bool BinaryTreeSearch::dftIterator::has_next()
{
	return !list_stack.isEmpty();
}*/