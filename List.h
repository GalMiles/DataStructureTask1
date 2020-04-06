#ifndef __List_H
#define __List_H

#define WHITE true
#define BLACK false
#include "ListNode.h"

class List {
public:
	bool isEmpty();
	bool getColor();
	int getSize();
	int getHead();
	ListNode* getArr();
	void insertNode(ListNode node, int index);
	void deleteNode(int index);
	void printList();
	void setColor(bool color);
	List makeEmpty();
	List();
	List(int maxSizeOfList, int headList = 0, int headFree = 0, int size = 0, bool color = WHITE);
	
private:
	ListNode* arr;
	int headList;
	int headFree;
	int size;
	bool color;
};
#endif

