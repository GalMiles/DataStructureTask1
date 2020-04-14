#include "Item.h"

Item::Item()
{
}

Item::Item(ListNode* data, ListNode* myAddress, int serverNumber) : data(data), myAddress(myAddress),serverNumber(serverNumber)
{

}
Item::Item(const Item& other)
{
	setData(other.data);
	setMyAddress(other.myAddress);
	this->serverNumber = other.serverNumber;
}

Item::~Item()
{
}

void Item::setData(ListNode* data)
{
	this->data = data;
}

void Item::setMyAddress(ListNode* myAddress)
{
	this->myAddress = myAddress;
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
