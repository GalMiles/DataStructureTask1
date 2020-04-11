#include "List.h"
#include <iostream>
#include <vector>
#include "Stack.h"


using namespace std;
void FindAccessibleVersion1(vector<List>& listOfServers, int serverToCheck, int size);
void FindAccessibleStack(vector<List>& listOfServers, int serverToCheck, List& lstToReturn, bool* colorsArr);
void FindAccessibleRec(vector<List>& listOfServers, int serverToCheck, List& lstToReturn, bool* colorsArr);
vector<List> getInput(int& numOfServers);
void makeLst(vector<List>& vectorOfList, int linkedSerever, int numOfServer);
void makeColors(bool* colorsArr, int size);
int isPositive(int num);
int isServerValid(int num, int numOfServer);
int isPcValid(int num, int numOfServer, vector<List> listOfServers, int servNum);

#define WHITE true
#define BLACK false

int main()
{
	int serverToCheck, numOfServers;
	vector<List> serverList = getInput(numOfServers);
	cout << "insert server to get linked pc's " << endl;
	cin >> serverToCheck;

	FindAccessibleVersion1(serverList, serverToCheck, numOfServers);
	cout << "The server's group is:" << serverToCheck << " ";
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

	cout << "please enter num of servers" << endl;
	cin >> numToCheck;
	numOfServers = isPositive(numToCheck);//size
	cout << "please enter number of linked servers" << endl;
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

		cout << "enter server number " << endl;
		cin >> numToCheck;
		servNum = isServerValid(numToCheck, numOfServer);

		cout << "enter pc number to connect " << endl;
		cin >> numToCheck;
		pcToConnect = isPcValid(numToCheck, numOfServer, vectorOfList, servNum);

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

void FindAccessibleVersion1(vector<List>& listOfServers, int serverToCheck, int size)
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
	//FindAccessibleRec(listOfServers, serverToCheck, lstToReturn, colorsArr);
	FindAccessibleStack(listOfServers, serverToCheck, lstToReturn, colorsArr);
	listOfServers[serverToCheck - 1] = lstToReturn;
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
	Stack s;
	Item tempItem;
	int index,tempNum,nextLoc;
	int serverToCheckMinusOne = serverToCheck - 1;
	int returnFromRec = 0;
	int size = listOfServers[serverToCheckMinusOne].getRealSize();
	int head = listOfServers[serverToCheckMinusOne].getHead();
	ListNode* currentNodeInList = &(listOfServers[serverToCheckMinusOne].getArr()[head]);
	int numOfNodesInList = listOfServers[serverToCheckMinusOne].getRealSize();
	Item curr(currentNodeInList,serverToCheckMinusOne,numOfNodesInList);
	s.push(curr);
	while (!s.isEmpty())
	{
		if (returnFromRec)
		{
			curr = s.pop();
			currentNodeInList = curr.getData();
			if (currentNodeInList->getNext() != -1)
			{
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
		if (curr.getNodesInList() == 0 || listOfServers[nextLoc].getRealSize() == 0)
		{
			colorsArr[nextLoc] = BLACK;
			returnFromRec = 1;
		}
		tempNum = curr.getNodesInList() - 1;
		curr.setNodesInList(tempNum);
		if(colorsArr[nextLoc] == WHITE)
		{
			numOfNodesInList = listOfServers[nextLoc].getRealSize();
			head = listOfServers[nextLoc].getHead();
			currentNodeInList = &listOfServers[nextLoc].getArr()[head];
			Item tempItem(currentNodeInList, nextLoc, numOfNodesInList);
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

int isServerValid(int num, int numOfServer)
{
	while (num <= 0 || num > numOfServer)
	{
		cout << "This number is not vaild. Please enter another server number" << endl;
		cin >> num;
	}//numer is in the right range

	return num;
}

int isPcValid(int num, int numOfServer, vector<List> listOfServers, int servNum)
{
	int index = 0;
	while (num <= 0 || num > numOfServer || !(listOfServers[servNum - 1].ifExistedAndTail(num, index)) || !(listOfServers[num - 1].ifExistedAndTail(servNum, index)))
	{
		cout << "This number is not vaild. Please enter another pc number" << endl;
		cin >> num;
	}//numer is valid

	return num;

}


