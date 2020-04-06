#include "List.h"
#include "PC.h"
#include <iostream>
#include <vector>
using namespace std;

#define WHITE true
#define BLACK false


int main()
{
	List serverToShow;
	int serverToCheck,numOfServers;
	vector<List*> serverList = getInput(numOfServers);
	bool* boolArr = new bool(numOfServers);
	cout << "insert server to get linked pc's " << endl;
	cin >> serverToCheck;
	serverToShow = FindAccessibleHelper(serverList, serverToCheck);
	serverToShow.printList();


	return 0;
}

vector<List*> getInput(int& numOfServers)
{
	List* newlst;
	int linkedServerNum;
	vector<List*> lstOfVectorsToReturn;
	cout << "please enter num of servers" << endl;
	cin >> numOfServers;
	cout << "please enter number of linked servers" << endl;
	cin >> linkedServerNum;
	for (int i = 0; i < numOfServers; i++)
		newlst = new List(numOfServers);
		lstOfVectorsToReturn.push_back(newlst);
	makeLst(lstOfVectorsToReturn, linkedServerNum);
	return lstOfVectorsToReturn;
}

List* makeLst(vector<List*>& lst, int linkedSerever)
{
	for (int i = 0; i < linkedSerever; i++)
	{
		int servNum, pcToConnect;
		cout << "enter server number " << endl;
		cin >> servNum;
		cout << "enter pc number to connect " << endl;
		cin >> pcToConnect;
		lst[servNum]->insertNode(pcToConnect);
	}
}

List FindAccessibleHelper(vector<List*> listOfServers,int serverToCheck)
{
	List serverToShow;
	serverToShow.makeEmpty();
	FindAccessibleRec(listOfServers, serverToCheck, serverToShow);
	return serverToShow;
}

void FindAccessibleRec(vector<List*> listOfServers, int serverToCheck,List& lstToReturn)
{
	List* currList = listOfServers[serverToCheck];
	currList->setColor(BLACK);
	int head = currList->getHead();
	ListNode currServerToAdd = currList->getArr()[head];
	for (int i = 0; i < currList->getSize(); i++)
	{ 
		int numOfServer = currServerToAdd.getData();
		lstToReturn.insertNode(currServerToAdd);
		if (listOfServers[numOfServer]->getColor == WHITE)
			FindAccessibleRec(listOfServers, numOfServer, lstToReturn);
		numOfServer = currList->getArr()->getNext();
		currServerToAdd = currList->getArr()[numOfServer];
	}
}




