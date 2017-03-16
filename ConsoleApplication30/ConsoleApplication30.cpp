// ConsoleApplication30.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;


class TicketGen
{
protected:
	int ID;
	int ticket;
	int getPriority;
	string userName, getType, getDescription, getImpact, Ticket_ID, TicketStatus, Priority;
public:	

	TicketGen() {};
	TicketGen(string t, string a, string c, string i)
	{
		userName = t; getType = a;
		getImpact = c; getDescription = i;

	}
	virtual void Display() = 0;
	virtual void CaptureData() {};
	virtual string SetStatus(string a) = 0;
	virtual string GetInformation(string a) = 0;
};

class Ticket : public TicketGen
{
public:
	Ticket() {};
	Ticket(string t, string a, string c, string i, string e) : TicketGen(t, a, c, i)
	{
	}
	void Display();
	void CaptureData();
	string SetStatus(string a);
	string GetInformation(string a);
};

void Ticket::CaptureData()
{
	
	cout << "UserName: ";
	getline(cin, userName);
	cout << endl << "What type of issue is this? (S)erver, (A)pplication, a(C)cess" << endl;
	getline(cin, getType);
	cout << endl << "How many users does this impact?";
	getline(cin, getImpact);
	cout << "Enter a description of this issue: " << endl;
	getline(cin, getDescription);
	cout << endl << "How many users does this impact" << endl;
	cin >> getPriority;
		if ((getPriority > 25) && (getPriority < 50)) {
			Priority = "Medium";
		}
		else if ((getPriority >= 50) && (getPriority <= 100)) {
			Priority = "High";
		}
		else { Priority = "Low"; }
	
}
string Ticket::SetStatus(string a)
{
	TicketStatus = a;
	return TicketStatus;
}
string Ticket::GetInformation(string a)
{
	TicketStatus = a;
	return TicketStatus;
}

void Ticket::Display()
{
	cout << "Customers Full Name: " << userName << endl;
	cout << "Service Issue: " << getType << endl;
	cout << "How many users impacted: " << getImpact << endl;
	cout << "Description: " << endl;
	cout << getDescription << endl << endl;
	cout << "Ticket Status: " << Priority << endl;

}

int main()
{
	TicketGen **tlist;
	int count=100;
	char ptype;
	bool isOver = false;

	

	tlist = new TicketGen*[count];

	for (int i = 0; i < count; i++)
	{
		
			tlist[i] = new Ticket();
			

		tlist[i]->CaptureData();
		tlist[i]->SetStatus("Open");
		tlist[0]->SetStatus("Closed");
		cout << endl << "Do you wish to enter another ticket? (Y)es / (N)" << endl;
		cin >> ptype;
			if (toupper(ptype) == 'Y')
			{ continue;	}
			else if (toupper(ptype) == 'N')
			{
				count = i + 1;
				isOver = true;
				break;
			}
	}
	if (isOver == true) {
		
	}


	for (int i = 0; i < count; i++)
	{
		cout << "Ticket ID: " << i+0001 << endl;
		tlist[i]->Display();
		cout << endl;
	}
	
	for (int i = 0; i < count; i++)
	{
		delete tlist[i];
	}
	delete tlist;

	return 0;
}
