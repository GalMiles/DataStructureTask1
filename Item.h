#ifndef _Item_H
#define _Item_H
#include "ListNode.h"
class Item
{
private:
	ListNode* data;
	ListNode* myAddress;
	int serverNumber;
	int nodesInList;
public:
	Item();
	Item(ListNode* data,ListNode* myAddress,int serverNumber,int nodesInList);
	~Item();
	void setData(ListNode* data);
	ListNode* getData();
	int getServerNum();
	int getNodesInList();
	void setNodesInList(int num);
	void operator=(const Item& other);
	ListNode* getMyAddress();
};

#endif

