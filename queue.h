#pragma once
#include <iostream>
class queue
{
private:
	class elements_queue
	{
	public:
		int element;
		elements_queue* next;
		elements_queue(int element)//constructor
		{
			element = 0;
			this->element = element;
			next = NULL;
		}
	};
	elements_queue* first_element;
	elements_queue* last_element;
	int size_of_queue;

public:
	queue()//constructor
	{
		last_element = NULL;
		first_element = NULL;
		size_of_queue = 0;
	}
	~queue()//destructor 
	{
		while (size_of_queue > 0)
			top();
	}
	
	bool isEmpty()//check the emptiness
	{
		return (size_of_queue == 0);
	}
	
	size_t getsize()//the size of the queue 
	{
		return size_of_queue;
	}
	
	void push(int current)//add the last element 
	{
		if (size_of_queue == 0)
			last_element = first_element = new elements_queue(current);
		else
			last_element = last_element->next = new elements_queue(current);
		size_of_queue++;
	}
	
	int top()//return and delete the last element (top)
	{
		if (isEmpty())
			throw std::out_of_range("Empty!");
		else 
		{
			int top = first_element->element;
			elements_queue* buffer = first_element->next;
			delete first_element;
			first_element = buffer;
			size_of_queue--;
			return top;
		}
	}
};