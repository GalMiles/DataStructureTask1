#include "List.h"
#include <iostream>
#include <vector>
#include "Stack.h"

using namespace std;
void FindAccessibleRecHelper(vector<List>& listOfServers, int serverToCheck, int size);
void FindAccessibleStackHelper(vector<List>& listOfServers, int serverToCheck, int size);
void FindAccessibleStack(vector<List>& listOfServers, int serverToCheck, List& lstToReturn, bool* colorsArr);
void FindAccessibleRec(vector<List>& listOfServers, int serverToCheck, List& lstToReturn, bool* colorsArr);
vector<List> getInput(int& numOfServers);
void makeLst(vector<List>& vectorOfList, int linkedSerever, int numOfServer);
void makeColors(bool* colorsArr, int size);
int isPositive(int num);
bool isServerValid(int num, int numOfServer);
bool isPcValid(int num, int numOfServer, vector<List> listOfServers, int servNum);

#define WHITE true
#define BLACK false

int main()
{
	int serverToCheck, numOfServers, numToCheck;
	vector<List> serverList = getInput(numOfServers);//get input from user, making the server list and connection between each server
	List copy(-1, 0, numOfServers, 0);//copy the wanted list before changing in recursive function

									  //cout << "insert server to get linked pc's " << endl;
	cin >> numToCheck;
	if (isServerValid(numToCheck, numOfServers))
		serverToCheck = numToCheck;
	else
	{
		cout << "no such computer " << numToCheck << endl;
		exit(-1);
	}

	copy = serverList[serverToCheck - 1];//copy the list before the change

	FindAccessibleRecHelper(serverList, serverToCheck, numOfServers);
	//cout << "The server's group is:";
	cout << serverToCheck << " ";
	serverList[serverToCheck - 1].printList();
	cout << endl;

	serverList[serverToCheck - 1] = copy;//return the original input list before change for the second function
	FindAccessibleStackHelper(serverList, serverToCheck, numOfServers);
	//cout << "The server's group is:" ;
	cout << serverToCheck << " ";
	serverList[serverToCheck - 1].printList();
	cout << endl;

	return 0;
}

vector<List> getInput(int& numOfServers)
{
	List newlst;
	int linkedServerNum;
	int numToCheck;
	vector<List> lstOfVectorsToReturn;

	//cout << "please enter num of servers" << endl;
	cin >> numToCheck;
	numOfServers = isPositive(numToCheck);//size
										  //cout << "please enter number of linked servers" << endl;
	cin >> numToCheck;
	linkedServerNum = isPositive(numToCheck);//copule amount

	for (int i = 0; i < numOfServers; i++)
	{
		newlst = List(-1, 0, numOfServers, 0);
		lstOfVectorsToReturn.push_back(newlst);
	}
	makeLst(lstOfVectorsToReturn, linkedServerNum, numOfServers);
	return lstOfVectorsToReturn;
}

void makeLst(vector<List>& vectorOfList, int linkedSerever, int numOfServer)
{
	for (int i = 0; i < linkedSerever; i++)
	{
		int servNum = 0, pcToConnect = 0, index;
		int numToCheck;

		//cout << "enter server number " << endl;
		cin >> numToCheck;

		if (isServerValid(numToCheck, numOfServer))
			servNum = numToCheck;
		else
		{
			cout << "no such computer " << numToCheck << endl;
			exit(-1);
		}


		//cout << "enter pc number to connect " << endl;
		cin >> numToCheck;

		if (isPcValid(numToCheck, numOfServer, vectorOfList, servNum))
			pcToConnect = numToCheck;

		else
		{
			cout << "no such computer " << numToCheck << endl;
			exit(-1);
		}


		index = vectorOfList[servNum - 1].findTailIndex();
		if (vectorOfList[servNum - 1].isEmpty())//if list empty insert to head
		{
			ListNode nodeToAdd(pcToConnect, 1);//first node in list will be in place 0 in array and need to point to one before updated to -1
			vectorOfList[servNum - 1].setHeadList(0);//new head is zero
			vectorOfList[servNum - 1].insertNode(nodeToAdd, index);//insert node
			vectorOfList[servNum - 1].getArr()[0].setNext(-1);//node is now head and tail so update to -1
		}
		else
		{
			ListNode nodeToAdd(pcToConnect, -1);//node will be added to tail
			vectorOfList[servNum - 1].insertNode(nodeToAdd, index);//insert after
		}
	}
}
void FindAccessibleRecHelper(vector<List>& listOfServers, int serverToCheck, int size)//make the list to return,colors arr,and put the first node of the list to return and calling findAc rec version
{
	int head = listOfServers[serverToCheck - 1].getHead();
	int headData = listOfServers[serverToCheck - 1].getArr()[head].getData();
	bool* colorsArr = new bool[size];
	makeColors(colorsArr, size);
	List lstToReturn(-1, 0, size, 0);
	ListNode currentNodeInList(headData, 1);
	lstToReturn.setHeadList(0);
	lstToReturn.insertNode(currentNodeInList, 0);
	lstToReturn.getArr()[0].setNext(-1);
	FindAccessibleRec(listOfServers, serverToCheck, lstToReturn, colorsArr);
	listOfServers[serverToCheck - 1] = lstToReturn;
	delete[] colorsArr;
}

void FindAccessibleStackHelper(vector<List>& listOfServers, int serverToCheck, int size)//make the list to return,colors arr,and put the first node of the list to return and calling findAc stack version
{
	int head = listOfServers[serverToCheck - 1].getHead();
	int headData = listOfServers[serverToCheck - 1].getArr()[head].getData();
	bool* colorsArr = new bool[size];
	makeColors(colorsArr, size);
	List lstToReturn(-1, 0, size, 0);
	ListNode currentNodeInList(headData, 1);
	lstToReturn.setHeadList(0);
	lstToReturn.insertNode(currentNodeInList, 0);
	lstToReturn.getArr()[0].setNext(-1);
	FindAccessibleStack(listOfServers, serverToCheck, lstToReturn, colorsArr);
	listOfServers[serverToCheck - 1] = lstToReturn;

	delete[] colorsArr;
}



void FindAccessibleRec(vector<List>& listOfServers, int serverToCheck, List& lstToReturn, bool* colorsArr)
{
	int size, index, head;
	int serverToCheckMinusOne = serverToCheck - 1;
	colorsArr[serverToCheckMinusOne] = BLACK;
	head = listOfServers[serverToCheckMinusOne].getHead();
	size = listOfServers[serverToCheckMinusOne].getRealSize();
	ListNode currentNodeInList = listOfServers[serverToCheckMinusOne].getArr()[head];
	for (int i = 0; i < size; i++)
	{
		int dataToAdd = currentNodeInList.getData();
		ListNode serverToAdd(dataToAdd, 1);
		if (lstToReturn.ifExistedAndTail(dataToAdd, index))//check if node already exist if not will return the tail index
		{
			index = lstToReturn.findTailIndex();
			serverToAdd.setNext(-1);
			lstToReturn.insertNode(serverToAdd, index);
		}
		int numOfServer = dataToAdd;
		if (colorsArr[numOfServer - 1] == WHITE)
			FindAccessibleRec(listOfServers, numOfServer, lstToReturn, colorsArr);

		currentNodeInList = listOfServers[serverToCheckMinusOne].getArr()[currentNodeInList.getNext()];
	}
}

void FindAccessibleStack(vector<List>& listOfServers, int serverToCheck, List& lstToReturn, bool* colorsArr)
{
	//5 5 1 4 2 4 3 2 3 5 4 5 1
	Stack s;
	Item tempItem;
	ListNode* tempListNode = nullptr;
	int index, tempNum, nextLoc;
	int serverToCheckMinusOne = serverToCheck - 1;
	int returnFromRec = 0;
	int size = listOfServers[serverToCheckMinusOne].getRealSize();
	int head = listOfServers[serverToCheckMinusOne].getHead();
	ListNode* currentNodeInList = &(listOfServers[serverToCheckMinusOne].getArr()[head]);//saving the address of the first listNode
	Item curr(nullptr, currentNodeInList, serverToCheckMinusOne);//creating item object
	s.push(curr);//to stack

	while (!s.isEmpty())
	{

		if (returnFromRec)//indicates we need to come back from rec
		{
			curr = s.pop();
			currentNodeInList = curr.getMyAddress();
			if (currentNodeInList->getNext() != -1)
			{
				if (s.isEmpty() && colorsArr[curr.getServerNum()] == WHITE)//if not finish all the nodes in a list and stack is empty put again the last curr for keep moving on the list
					s.push(curr);
				tempListNode = currentNodeInList;
				currentNodeInList = &(listOfServers[curr.getServerNum()].getArr()[currentNodeInList->getNext()]);
				returnFromRec = 0;
			}
			else
				returnFromRec = 1;
		}

		int dataToAdd = currentNodeInList->getData();
		ListNode serverToAdd(dataToAdd, 1);
		if (lstToReturn.ifExistedAndTail(dataToAdd, index))//check if node already exist if not will return the tail index
		{
			index = lstToReturn.findTailIndex();
			serverToAdd.setNext(-1);
			lstToReturn.insertNode(serverToAdd, index);
		}
		nextLoc = dataToAdd - 1;

		if (currentNodeInList->getNext() == -1) //check if list of current server is empty after this node if yes added and mark as black
		{
			colorsArr[curr.getServerNum()] = BLACK;
			returnFromRec = 1;
		}
		if (listOfServers[nextLoc].getRealSize() == 0)
		{
			colorsArr[nextLoc] = BLACK;
			returnFromRec = 1;
		}
		if (colorsArr[curr.getServerNum()] == WHITE && colorsArr[nextLoc] == BLACK)
		{
			Item tempItem(tempListNode, currentNodeInList, curr.getServerNum());
			curr = tempItem;
			s.push(curr);
			returnFromRec = 1;
		}
		if (colorsArr[nextLoc] == WHITE)
		{
			head = listOfServers[nextLoc].getHead();
			tempListNode = currentNodeInList;
			currentNodeInList = &listOfServers[nextLoc].getArr()[head];
			Item tempItem(tempListNode, currentNodeInList, nextLoc);
			curr = tempItem;
			s.push(curr);
			returnFromRec = 0;
		}
	}
}
void makeColors(bool* colorsArr, int size)
{
	for (int i = 0; i < size; i++)
		colorsArr[i] = WHITE;
}

int isPositive(int num)
{
	while (num <= 0)
	{
		cout << "Numer must be positive!" << endl;
		cout << "Please enter num of servers" << endl;
		cin >> num;
	}
	return num;//when num is positive
}

bool isServerValid(int num, int numOfServer)
{
	if (num <= 0 || num > numOfServer)
	{
		return false;
	}

	return true;
}

bool isPcValid(int num, int numOfServer, vector<List> listOfServers, int servNum)
{
	int index = 0;

	if (num <= 0 || num > numOfServer || !(listOfServers[servNum - 1].ifExistedAndTail(num, index)))
	{
		return false;
	}
	return true;
}


