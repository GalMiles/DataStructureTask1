#include "ListNode.h"

ListNode::ListNode()
{
	this->next = -1;
}

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

void ListNode::setData(int data)
{
	this->data = data;
}


void ListNode::setNext(int next)
{
	this->next = next;
}

void ListNode::printNode()
{
	cout << "data: " << this->data << endl;
}

void ListNode::operator=(const ListNode& other)
{
	this->data = other.data;
	this->next = other.next;
}


