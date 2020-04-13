#include "Item.h"

Item::Item()
{
}

Item::Item(ListNode* data,ListNode* myAddress, int serverNumber) : data(data), myAddress(myAddress), serverNumber(serverNumber)
{

}

Item::~Item()
{
	delete this->data;
	delete this->myAddress;

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


void Item::operator=(const Item& other)
{
	this->data = new ListNode;
	this->myAddress = new ListNode;
	this->myAddress = other.myAddress;
	this->data = other.data;
	this->serverNumber = other.serverNumber;
}

ListNode * Item::getMyAddress()
{
	return this->myAddress;
}
