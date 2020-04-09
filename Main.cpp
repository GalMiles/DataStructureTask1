#include "List.h"
#include <iostream>
#include <vector>

using namespace std;

void FindAccessibleRec(vector<List> listOfServers, int serverToCheck, List& lstToReturn);
vector<List> getInput(int& numOfServers);
void makeLst(vector<List>& vectorOfList, int linkedSerever);
#define WHITE true
#define BLACK false

int main()
{
	int serverToCheck,numOfServers;
	vector<List> serverList = getInput(numOfServers);
	cout << "insert server to get linked pc's " << endl;
	cin >> serverToCheck;
	FindAccessibleRec(serverList, serverToCheck, serverList[serverToCheck - 1]);
	serverList[serverToCheck - 1].printList();


	return 0;
}

vector<List> getInput(int& numOfServers)
{
	List newlst;
	int linkedServerNum;
	vector<List> lstOfVectorsToReturn;
	cout << "please enter num of servers" << endl;
	cin >> numOfServers;//size
	cout << "please enter number of linked servers" << endl;
	cin >> linkedServerNum;//couple amount
	for (int i = 0; i < numOfServers; i++)
	{
		newlst = List(-1, 0, numOfServers, WHITE, 0);
		lstOfVectorsToReturn.push_back(newlst);
	}
	makeLst(lstOfVectorsToReturn, linkedServerNum);
	return lstOfVectorsToReturn;
}

void makeLst(vector<List>& vectorOfList, int linkedSerever)
{
	for (int i = 0; i < linkedSerever; i++)
	{
		int servNum, pcToConnect,index;
		cout << "enter server number " << endl;
		cin >> servNum;
		cout << "enter pc number to connect " << endl;
		cin >> pcToConnect;
		index = vectorOfList[servNum-1].findTailIndex();
		if (vectorOfList[servNum-1].isEmpty())//if list empty insert to head
		{
			ListNode nodeToAdd(pcToConnect, 1);//first node in list will be in place 0 in array and need to point to one before updated to -1
			vectorOfList[servNum-1].setHeadList(0);//new head is zero
			vectorOfList[servNum-1].insertNode(nodeToAdd, index);//insert node
			vectorOfList[servNum-1].getArr()[0].setNext(-1);//node is now head and tail so update to -1
		}
		else
		{
			ListNode nodeToAdd(pcToConnect,-1);//node will be added to tail
			vectorOfList[servNum-1].insertNode(nodeToAdd, index);//insert after
		}
	}
}
/*
void FindAccessibleHelper(vector<List> listOfServers,List& serverToShow,int serverToCheck)
{
	FindAccessibleRec(listOfServers, serverToCheck,serverToShow);
}

*/

void FindAccessibleRec(vector<List> listOfServers, int serverToCheck, List& lstToReturn)
{
	int size,index,head;
	int serverToCheckMinusOne = serverToCheck - 1;
	listOfServers[serverToCheckMinusOne].setColor(BLACK);
	head = listOfServers[serverToCheckMinusOne].getHead();
	size = listOfServers[serverToCheckMinusOne].getRealSize();
	ListNode currentNodeInList = listOfServers[serverToCheckMinusOne].getArr()[head];
	for (int i = 0; i < size; i++)
	{
		int dataToAdd = currentNodeInList.getData();
		ListNode serverToAdd(dataToAdd, 1);
		/*x
		if (lstToReturn.isEmpty())
		{
			lstToReturn.setHeadList(0);
			lstToReturn.insertNode(serverToAdd, 0);
			lstToReturn.getArr()[0].setNext(-1);
		}
		else
		{
		*/
		if (lstToReturn.ifExistedAndTail(dataToAdd, index))//check if node already exist if not will return the tail index
		{
			index = lstToReturn.findTailIndex();
			serverToAdd.setNext(-1);
			lstToReturn.insertNode(serverToAdd, index);
		}
		//}
		int numOfServer = dataToAdd;
		if (listOfServers[numOfServer - 1].getColor() == WHITE)
			FindAccessibleRec(listOfServers, numOfServer, lstToReturn);
		currentNodeInList = listOfServers[serverToCheckMinusOne].getArr()[currentNodeInList.getNext()];
	}
}



