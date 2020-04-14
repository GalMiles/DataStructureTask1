#include "List.h"

List::List(int headList, int headFree, int size, int realSize)
{
	this->headList = headList;
	this->headFree = headFree;
	this->size = size;
	this->realSize = realSize;

	this->arr = new ListNode[size];
	for (int i = 0; i < size; i++)
		if (i == size - 1)
			this->arr[i].setNext(-1);
		else
			this->arr[i].setNext(i + 1);
}

List::List(const List& other)//copy c'tor
{
	this->size = other.size;
	this->arr = new ListNode[this->size];
	for (int i = 0; i < this->size; i++)//copy arr
	{
		this->arr[i] = other.arr[i];//we need to do opeartor= for listNode
	}

	this->headFree = other.headFree;
	this->headList = other.headList;
	this->realSize = other.realSize;
}

List::List(List&& other)//move c'tor
{
	*this = move(other);
}

List::~List()//d'tor
{
	delete[] arr;

}

List List::makeEmpty()
{
	return(List(-1, 0, 0));
}

bool List::isEmpty()
{
	if (this->headList == -1)//empty list
		return true;
	else
		return false;
}

void List::insertNode(ListNode& node, int index)
{
	this->realSize++;
	int locNew;
	locNew = this->headFree;
	this->headFree = arr[headFree].getNext();
	arr[locNew] = node; //operator= for listNode require
	arr[locNew].setNext(arr[index].getNext());
	arr[index].setNext(locNew);
}

void List::deleteNode(int index)
{
	this->realSize--;
	int locFree;
	locFree = arr[index].getNext();
	arr[index].setNext(arr[locFree].getNext());
	arr[locFree].setNext(headFree);
	headFree = locFree;
}
void List::printList()
{
	for (int i = 0; i < this->realSize; i++)
	{
		arr[i].printNode();//using printNode method
	}
}

int List::findTailIndex()
{
	int index = 0;
	ListNode currentNodeInList;//temp node for return if empty
	if (this->isEmpty())
	{
		index = 0;
		return index;
	}
	currentNodeInList = arr[this->headList];
	while (currentNodeInList.getNext() != -1)
	{
		index = currentNodeInList.getNext();
		currentNodeInList = arr[currentNodeInList.getNext()];
	}

	return index;
}



void List::operator=(const List& other)
{
	headFree = other.headFree;
	headList = other.headList;
	size = other.size;
	realSize = other.realSize;
	delete[] this->arr;

	this->arr = new ListNode[size];
	for (int i = 0; i < size; i++)
	{
		arr[i] = other.arr[i];
	}
}

void List::setHeadList(int newHead)
{
	this->headList = newHead;
}

void List::setHeadFree(int newHeadFree)
{

}

int List::getRealSize()
{
	return this->realSize;
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

void List::setRealSize(int realSize)
{
	realSize = realSize;
}


bool List::ifExistedAndTail(int data, int& index)
{
	index = 0;
	ListNode currentNodeInList;//temp node for return if empty
	if (this->isEmpty())
	{
		index = 0;
		return true;
	}
	currentNodeInList = arr[this->headList];
	while (currentNodeInList.getNext() != -1)
	{
		if (currentNodeInList.getData() == data)//already exist return false
			return false;
		index = currentNodeInList.getNext();
		currentNodeInList = arr[currentNodeInList.getNext()];
	}
	if (currentNodeInList.getData() == data)//check if the data to add is same as tail and already exist return false
		return false;
	return true;
}
