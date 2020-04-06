#ifndef __List_H
#define __List_H
#include "ListNode.h"

#define WHITE true
#define BLACK false


class List {
public:
	bool isEmpty();
	void insertNode(ListNode node, int index);
	void deleteNode(int index);
	void printList();
	List makeEmpty();
	List();

private:
	ListNode *arr;
	int headList;
	int headFree;
	int size;
	bool color;
};
#endif

