#pragma once
#include <iostream>

class iterators
{
public:
	virtual int next() = 0;//to the next element
	virtual bool has_next() = 0;// check the unknown elements
};