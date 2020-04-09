/*
#ifndef _L_N
#define _L_N
#define ItemType int
class Node {
private:
	ItemType data;
	Node*next;
public:
	Node(const ItemType&point);
	Node(const ItemType&data, Node*ptr = nullptr);
	~Node();
	void insertAfter(Node*newnode);
	Node*DeleteAfter(void);
	friend class Stack;
};
#endif // !_L_N
*/