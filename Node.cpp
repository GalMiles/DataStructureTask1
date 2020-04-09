/*
#include "Node.h"


Node::Node(const ItemType& data)
{
	this->data = data;
	next = nullptr;
}
Node::Node(const ItemType& data, Node*next)
{
	this->data = data;
	this->next = next;
}
void Node::insertAfter(Node* newnode)
{
	newnode->next = this->next;
	this->next = newnode;
}
Node*Node::DeleteAfter(void)
{
	Node*temp = next;
	if (this->next == nullptr)
		return nullptr;

	next = temp->next;
	return temp;
}
*/