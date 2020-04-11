
#ifndef _L_N
#define _L_N
#include "Item.h"

class Node{
private:
	Item data;
	Node* next;
public:
	Node(const Item& item);
	Node(const Item&data, Node*ptr = nullptr);
	~Node();
	void insertAfter(Node*newnode);
	Node*DeleteAfter(void);
	friend class Stack;

};
#endif // !_L_N