/*

	Program to implement a link-list using class for Node and LinkList
	
	420H14 -- Arjun Krishna Babu
*/
#include<iostream>
using namespace std;

class Node	{
private:
	int data;
	Node *next;
public:
	Node()	{
		next = NULL;
	}
	/* setter and getter for data */
	void setData(int d)	{
		data = d;
	}

	int getData()	{
		return data;
	}

	/*	setter and getter for link */
	void setNext(Node *A)	{
		next = A;
	}
	Node * getNext()	{
		return next;
	}
};

class LinkList	{
private:
	Node *head;		//keeps track of beginning of node
public:
	LinkList()	{
		head = NULL;	//very imp. Ensures list is initially empty
	}
	void insBeg(int dd)	{
		Node *temp = new Node();	//creates a new noce
		temp->setData(dd);			//sets value to the new node

		if(head == NULL)	{	//if the link-list is empty
//			temp->setNext(NULL);
			head = temp;
		}
		else	{
			temp->setNext(head);	//make the newly-created node point to the existing head
			head = temp;
		}
	}

	void insEnd(int dd)	{
		Node *temp = new Node();
		temp->setData(dd);
		temp->setNext(NULL);
		
		Node *loc;

		if(head == NULL)	{
			head = temp;
		}

		else	{
			loc = head;

			while(loc->getNext() != NULL)	{	//loop to traverse to the last node in the list
				loc = loc->getNext();
			}
		
			loc->setNext(temp); 		//make loc(last node) point to the newly created node
		}
	}

	void traverse()	{
		Node *loc = head;

		while(loc != NULL)	{			
			cout<<"-->"<<(loc->getData());
			loc = loc->getNext();
		}

		cout<<"\n 
	}

};

int main()	{
	LinkList L;
	int choice = 0;
	int num;
	do	{
		cout<<"\n 1: Insert into beginning";
		cout<<"\n 2: Insert into end";
		cout<<"\n 9: Traverse";
		cout<<"\n 0: EXIT";
		cout<<"\n Enter Your Choice: ";
			cin>>choice;
		switch(choice)	{
			case 1: cout<<"\n Enter an element to insert into beginning of the linked list: ";
					cin>>num;
					L.insBeg(num);
					break;
			case 2: cout<<"\n Enter an element to insert into beginning of the linked list: ";
					cin>>num;
					L.insEnd(num);
					break;
			case 9: cout<<"\n Elements in the linked list: "; L.traverse();
					break;
			case 0: cout<<"\n Program under development!";
					break;
		   default: cout<<"\n ERROR: Invalid Choice!";
		  			break;
		}
	}while(choice != 0);

   cout<<"\n\n";
   return 0;
}
