/*
#include "Stack.h"
#include <iostream>

using namespace std;

Stack::Stack()
{
	this->top = nullptr;
}
Stack::~Stack()
{
	makeEmpty();
}
void Stack::makeEmpty()
{
	Node *temp;
	while (this->top != nullptr)
	{
		temp = this->top;
		this->top = this->top->next;
		delete temp;
	}
}

bool Stack::isEmpty(void)
{
	return (this->top == nullptr);
}
void Stack::push(const ItemType& toAdd)
{
	this->top = new Node(toAdd, this->top);
}
const ItemType Stack::pop(void)
{
	if (isEmpty())
	{
		ItemType p = 0;
		cout << "Stack Is Empty";
		return p;////
	}
		
	else
	{
		Node* temp = this->top;
		ItemType p = this->top->data;
		this->top = this->top->next;
		delete temp;
		return p;
	}
}

*/