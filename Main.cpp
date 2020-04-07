#include "List.h"
#include <iostream>
#include <vector>
using namespace std;
List FindAccessibleHelper(vector<List*> listOfServers, int serverToCheck);
void FindAccessibleRec(vector<List*> listOfServers, int serverToCheck, List& lstToReturn);
vector<List*> getInput(int& numOfServers);
void makeLst(vector<List*>& vectorOfList, int linkedSerever);
#define WHITE true
#define BLACK false

int main()
{
	List serverToShow;
	int serverToCheck,numOfServers;
	vector<List*> serverList = getInput(numOfServers);
	cout << "insert server to get linked pc's " << endl;
	cin >> serverToCheck;
	serverToShow = FindAccessibleHelper(serverList, serverToCheck);
	//serverToShow.printList();


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
		newlst = new List[numOfServers];
		lstOfVectorsToReturn.push_back(newlst);
	}
	makeLst(lstOfVectorsToReturn, linkedServerNum);
	return lstOfVectorsToReturn;
}

void makeLst(vector<List*>& vectorOfList, int linkedSerever)
{
	for (int i = 0; i < linkedSerever; i++)
	{
		ListNode nodeTOAddAfter;
		int servNum, pcToConnect,index;
		cout << "enter server number " << endl;
		cin >> servNum;
		cout << "enter pc number to connect " << endl;
		cin >> pcToConnect;
		nodeTOAddAfter = vectorOfList[servNum]->findTail(index);
		if (nodeTOAddAfter.getData() == 0)
		{
			nodeTOAddAfter.setNext(-1);
			nodeTOAddAfter.setData(pcToConnect);
		}
		vectorOfList[servNum]->insertNode(nodeTOAddAfter,index);
	}
}

List FindAccessibleHelper(vector<List*> listOfServers,int serverToCheck)
{
	List serverToShow;
	serverToShow.makeEmpty();
	FindAccessibleRec(listOfServers, serverToCheck,serverToShow);
	return serverToShow;
}


void FindAccessibleRec(vector<List*> listOfServers, int serverToCheck,List& lstToReturn)
{
	List* currList = listOfServers[serverToCheck];
	currList->setColor(BLACK);
	int head = currList->getHead();
	ListNode tail;
	int index;
	ListNode currServerToAdd = currList->getArr()[head];
	for (int i = 0; i < currList->getSize(); i++)
	{ 
		int numOfServer = currServerToAdd.getData();
		tail = lstToReturn.findTail(index);
		lstToReturn.insertNode(tail,index);
		if (listOfServers[numOfServer]->getColor() == WHITE)
			FindAccessibleRec(listOfServers, numOfServer, lstToReturn);
		numOfServer = currList->getArr()->getNext();
		currServerToAdd = currList->getArr()[numOfServer];
	}
}




