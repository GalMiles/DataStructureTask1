#ifndef __ListNode_H
#define __ListNode_H

#include <iostream>
#include <string.h>
#include "PC.h"

#pragma warning(disable: 4996)

using namespace std;


class ListNode {
public:
	ListNode(PC* data, int next);//c'tor
	ListNode(const ListNode& other);//copy c'tor
	~ListNode();//d'tor
	gffgfggd

private:
	PC *data;
	int next;
};

#endif
