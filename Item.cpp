#include "Item.h"

Item::Item()
{
}

Item::Item(ListNode* data, int serverNumber,int nodesInList): data(data), serverNumber(serverNumber), nodesInList(nodesInList)
{

}

Item::~Item()
{
}

void Item::setData(ListNode* data)
{
	this->data = data;
}



ListNode* Item::getData()
{
	return this->data;
}

int Item::getServerNum()
{
	return this->serverNumber;
}

int Item::getNodesInList()
{
	return this->nodesInList;
}

void Item::setNodesInList(int num)
{
	this->nodesInList = num;
}


void Item::operator=(const Item& other)
{
	this->data = new ListNode;
	this->data = other.data;
	this->serverNumber = other.serverNumber;
	this->nodesInList = other.nodesInList;
}