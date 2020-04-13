#include "Item.h"

Item::Item()
{
}

Item::Item(ListNode* data,ListNode* myAddress, int serverNumber)
{
	this->data = data;
	this->myAddress = myAddress;
	this->serverNumber = serverNumber;
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


void Item::operator=(const Item& other)
{
	this->myAddress = other.myAddress;
	this->data = other.data;
	this->serverNumber = other.serverNumber;
}

ListNode * Item::getMyAddress()
{
	return this->myAddress;
}
