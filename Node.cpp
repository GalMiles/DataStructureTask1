
#include "Node.h"


Node::Node(const Item& item)
{
	this->data = data;
	next = nullptr;
}
Node::Node(const Item& data, Node* next)
{
	this->data = data;
	this->next = next;
}
Node::Node(const Node& other)
{
	this->data = other.data;
	this->next = other.next;
}

Node::~Node()
{
	
}
void Node::insertAfter(Node* newnode)
{
	newnode->next = this->next;
	this->next = newnode;
}
Node*Node::DeleteAfter(void)
{
	Node* temp = next;
	if (this->next == nullptr)
		return nullptr;

	next = temp->next;
	return temp;
}
