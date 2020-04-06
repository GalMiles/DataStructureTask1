#include "List.h"

void List::setColor(bool color)
{
	this->color = color;
}

List::List(int maxSizeOfList, int headList = 0, int headFree = 0, int size = 0, bool color = WHITE)
{
	this->arr = new ListNode[maxSizeOfList];
}

bool List::getColor()
{
	if (this->color == WHITE)
	{
		return true;
	}
	return false;
}

int List::getSize()
{
	return this->size;
}

int List::getHead()
{
	return this->headList;
}

ListNode* List::getArr()
{
	return this->arr;
}
