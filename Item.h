#ifndef _Item_H
#define _Item_H
#include "ListNode.h"
class Item
{

public:
	Item();
	Item(ListNode* data, ListNode* myAddress, int serverNumber);
	~Item();
	void setData(ListNode* data);
	ListNode* getData();
	int getServerNum();
	void operator=(const Item& other);
	ListNode* getMyAddress();

private:
	ListNode* data;
	ListNode* myAddress;
	int serverNumber;


};

#endif

