#ifndef __List_H
#define __List_H

#define WHITE true
#define BLACK false
#include "ListNode.h"

class List {
public:
	List(int headList = 0, int headFree = 0, int size = 0, bool color = WHITE); // c'tor
	List(const List& other);//copy c'tor
	~List();//d'tor

	List makeEmpty();
	bool isEmpty();
	void insertNode(ListNode node, int index);
	void deleteNode(int index);
	void printList();

	bool getColor();
	int getSize();
	int getHead();
	ListNode* getArr();
	void setColor(bool color);

private:
	ListNode* arr;
	int headList;
	int headFree;
	int size;
	bool color;
};
#endif

