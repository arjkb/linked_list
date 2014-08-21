/*
	Program to implement a linked list

	SECOND ATTEMPT

	420H14 -- Arjun Krishna Babu
*/

#include<iostream>
using namespace std;

struct Node	{
	int data;
	Node *next;
};

class LinkList	{
private:
		Node *A;	//pointer to the head of the link-list
public:
	LinkList()	{
		A = NULL;
	}

	void insBeg(int d)	{
	
		if(A == NULL)	{	//if the list is empty
			Node *temp = new Node();
			temp->data = d;
			temp->next = NULL;
			A = temp;
		}
		else	{
			Node *temp = new Node();
			temp->data = d;
			temp->next = A;
			A = temp;
		}
	}

	void traverse()	{
		Node *temp = A;
		while(temp->next != NULL)	{
			cout<<" "<<temp->data;
			temp = temp->next;
		}
	}
};

int main()	{

	LinkList L;
	int choice;
	int num;
	do	{
		cout<<"\n 1: Insert into beginning";
		cout<<"\n 2: Delete from end";
		cout<<"\n 9: Traverse";
		cout<<"\n 0: EXIT";
		cout<<"\n Enter Your Choice: "; cin>>choice;

		switch(choice)	{
			case 1: cout<<"\n Enter element to insert into the beginning of link-list: ";
					cin>>num;
					L.insBeg(num);
					break;
			case 9: cout<<"\n Elements in the link-list: "; L.traverse();
					break;
			case 0: cout<<"\n Program under development!";
					break;
		   default: cout<<"\n ERROR! Invalid Choice!";
		   			break;
		}
	}while(choice != 0);
   cout<<"\n\n";
   return 0;
}
