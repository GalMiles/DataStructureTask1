#ifndef __List_H
#define __List_H

#include "ListNode.h"

class List {
public:
	bool isEmpty();
	void insertNode(ListNode node, int index);
	void deleteNode(int index);
	void printList();
	List makeEmpty();

private:
	ListNode *arr;
	int headList;
	int headFree;
};
#endif

