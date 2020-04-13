
#ifndef _L_N
#define _L_N
#include "Item.h"

class Node{

public:
	Node(const Item& item);
	Node(const Item&data, Node* ptr=nullptr);
	Node(const Node& other);
	~Node();
	void insertAfter(Node* newnode);
	Node*DeleteAfter(void);
	friend class Stack;

private:
	Item data;
	Node* next;

};
#endif // !_L_N