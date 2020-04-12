
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
	Node* temp;
	while (this->top != nullptr)
	{
		temp = this->top;
		this->top = this->top->next;
		delete temp;
	}
}

bool Stack::isEmpty()
{
	return (this->top == nullptr);
}
void Stack::push(const Item& toAdd)
{
	this->top = new Node(toAdd, this->top);
}
const Item Stack::pop()
{
	if (isEmpty())
	{
		Item p(nullptr,nullptr,0,0);
		cout << "Stack Is Empty";
		return p;////
	}
		
	else
	{
		Node* temp = this->top;
		Item p = this->top->data;
		this->top = this->top->next;
		delete temp;
		return p;
	}
}

