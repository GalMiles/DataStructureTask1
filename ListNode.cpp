#include "ListNode.h"

ListNode::ListNode(int data, int next): data(data), next(next)
{

}

ListNode::ListNode(const ListNode& other)
{

}

ListNode::~ListNode()
{

}

int ListNode::getData()
{
	return this->data;
}

int ListNode::getNext()
{
	return this->next;
}


void ListNode::setNext(int next)
{
	this->next = next;
}

void ListNode::printNode()
{
	cout << "data: " << this->data << endl;

}

