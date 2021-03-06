#ifndef __ListNode_H
#define __ListNode_H

#include <iostream>
#include <string.h>

#pragma warning(disable: 4996)

using namespace std;


class ListNode {
public:
	ListNode();
	ListNode(int data, int next);//c'tor
	ListNode(const ListNode& other);//copy c'tor
	~ListNode();//d'tor
	int getData();
	int getNext();
	void setData(int data);
	void setNext(int next);
	void printNode();
	void operator=(const ListNode& other);

private:
	int data;
	int next;
};

#endif
