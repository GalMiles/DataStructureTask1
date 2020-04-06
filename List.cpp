#include "List.h"

List::List(int headList,int headFree, int size, bool color):headList(headList), headFree(headFree), size(size), color(color)
{
	this->arr = new ListNode[size];
}

List::List(const List& other)//copy c'tor
{
	this->size = other.size;
	this->arr = new ListNode[this->size];
	for (int i = 0; i < this->size; i++)//copy arr
	{
		this->arr[i] = other.arr[i];//we need to do opeartor= for listNode
	}

	this->color = other.color;
	this->headFree = other.headFree;
	this->headList = other.headList;
}
List::~List()//d'tor
{
	delete arr;

}

List List:: makeEmpty()
{
	return(List(-1, 0, 0, WHITE));
}

bool List::isEmpty()
{
	if (this->headList == -1)//empty list
		return true;
	else
		return false;
}

void List::insertNode(ListNode node, int index)
{
	int locNew;
	locNew= this->headFree;
	this->headFree = arr[headFree].getNext();
	arr[locNew] = node; //operator= for listNode require
	arr[locNew].setNext(arr[index].getNext());
	arr[index].setNext(locNew);
}

void List::deleteNode(int index)
{
	int locFree;
	locFree = arr[index].getNext();
	arr[index].setNext(arr[locFree].getNext());
	arr[locFree].setNext(headFree);
	headFree = locFree;
}
void List::printList()
{
	for (int i = 0; i < size; i++)
	{
		arr[i].printNode();//using printNode method
	}
}

void List::setColor(bool color)
{
	this->color = color;
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
