#ifndef __List_H
#define __List_H

#define WHITE true
#define BLACK false
#include "ListNode.h"

class List {
public:
	List(int headList = -1, int headFree = 0, int size = 0, bool color = WHITE, int realSize = 0); // c'tor
	List(const List& other);//copy c'tor
	List(List&& other);//move c'tor
	~List();//d'tor

	List makeEmpty();
	bool isEmpty();
	void insertNode(ListNode& node, int index);
	void deleteNode(int index);
	void printList();
	int findTailIndex();
	bool getColor();
	int getSize();
	int getHead();
	ListNode* getArr();
	void setColor(bool color);
	void operator=(const List& other);
	void setHeadList(int newHead);
	void setHeadFree(int newHeadFree);
	void setRealSize(int realSize);
	int getRealSize();



private:
	int headList;
	int headFree;
	int size;
	bool color;
	int realSize;
	ListNode* arr;
};
#endif

