

#ifndef _S_H
#define _S_H
#include "Node.h"

class Stack {
private:
	Node* top;

public:
	Stack();
	~Stack();
	void makeEmpty(void);
	bool isEmpty(void);
	void push(const Item& data);
	const Item pop();
};
#endif 
