#pragma once
class stack
{
private:
	class Element
	{
	public:
		int data;//inf part
		Element* previous;//pointer to the previous element
		Element(int inf)//constructor
		{
			this->data = inf;
			previous = NULL;
		}
	};
	Element* top_element;//pointer to the top (last element)
	size_t size;
public:
	stack()//constructor
	{
		top_element = NULL;
		size = 0;
	}
	~stack()//destructor
	{
		while (!isEmpty())
			taketop();
	}
	
	bool isEmpty()//check the emptiness
	{
		return (size == 0);
	}
	
	size_t getSize()//get size
	{
		return size;
	}
	
	void push_back(int value)//add to the end
	{
		Element* buffer = top_element;
		top_element = new Element(value);
		top_element->previous = buffer;
		size++;
	}
	
	int taketop()//return the last node of the stack and delete them
	{
		if (isEmpty())
			throw std::out_of_range("Empty!");
		else 
		{
			int last_element = top_element->data;
			Element* buffer = top_element->previous;
			delete top_element;
			top_element = buffer;
			size--;
			return last_element;
		}
	}
};