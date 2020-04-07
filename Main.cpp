#include "List.h"
#include <iostream>
#include <vector>
using namespace std;
void FindAccessibleHelper(vector<List*> listOfServers, List& serverToShow, int serverToCheck);
void FindAccessibleRec(vector<List*> listOfServers, int serverToCheck, List& lstToReturn);
vector<List*> getInput(int& numOfServers);
void makeLst(vector<List*>& vectorOfList, int linkedSerever);
#define WHITE true
#define BLACK false

int main()
{
	int serverToCheck,numOfServers;
	vector<List*> serverList = getInput(numOfServers);
	List serverToShow(-1, 0, serverList.size(), WHITE);
	cout << "insert server to get linked pc's " << endl;
	cin >> serverToCheck;
	FindAccessibleHelper(serverList,serverToShow,serverToCheck);
	serverToShow.printList();

	return 0;
}

vector<List*> getInput(int& numOfServers)
{
	List* newlst;
	int linkedServerNum;
	vector<List*> lstOfVectorsToReturn;
	cout << "please enter num of servers" << endl;
	cin >> numOfServers;//size
	cout << "please enter number of linked servers" << endl;
	cin >> linkedServerNum;//couple amount
	for (int i = 0; i < numOfServers; i++)
	{
		newlst = new List(-1, 0, numOfServers, WHITE);
		lstOfVectorsToReturn.push_back(newlst);
	}
	makeLst(lstOfVectorsToReturn, linkedServerNum);
	return lstOfVectorsToReturn;
}

void makeLst(vector<List*>& vectorOfList, int linkedSerever)
{
	for (int i = 0; i < linkedSerever; i++)
	{
		int servNum, pcToConnect,index;
		cout << "enter server number " << endl;
		cin >> servNum;
		cout << "enter pc number to connect " << endl;
		cin >> pcToConnect;
		index = vectorOfList[servNum]->findTailIndex();
		if (vectorOfList[servNum]->isEmpty())//if list empty insert to head
		{
			ListNode nodeToAdd(pcToConnect, 1);//first node in list will be in place 0 in array and need to point to one before updated to -1
			vectorOfList[servNum]->setHeadList(0);//new head is zero
			vectorOfList[servNum]->insertNode(nodeToAdd, index);//insert node
			vectorOfList[servNum]->getArr()[0].setNext(-1);//node is now head and tail so update to -1
		}
		else
		{
			ListNode nodeToAdd(pcToConnect,-1);//node will be added to tail
			vectorOfList[servNum]->insertNode(nodeToAdd, index);//insert after
		}
	}
}

void FindAccessibleHelper(vector<List*> listOfServers,List& serverToShow,int serverToCheck)
{
	FindAccessibleRec(listOfServers, serverToCheck,serverToShow);
}


void FindAccessibleRec(vector<List*> listOfServers, int serverToCheck, List& lstToReturn)
{
	int size;
	List* currList = listOfServers[serverToCheck];
	currList->setColor(BLACK);
	int index;
	size = currList->getRealSize();
	for (int i = 0; i < size; i++)
	{
		ListNode serverToAdd(currList->getArr()[i].getData(), 1);
		if (lstToReturn.isEmpty())
		{
			lstToReturn.setHeadList(0);
			lstToReturn.insertNode(serverToAdd, 0);
			lstToReturn.getArr()[0].setNext(-1);
		}
		else
		{
			index = lstToReturn.findTailIndex();
			serverToAdd.setNext(-1);
			lstToReturn.insertNode(serverToAdd, index);
		}
		int numOfServer = serverToAdd.getData();
		if (listOfServers[numOfServer]->getColor() == WHITE)
			FindAccessibleRec(listOfServers, numOfServer, lstToReturn);
	}
}



