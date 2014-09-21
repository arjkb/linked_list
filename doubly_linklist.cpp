/*
	FILE: doubly_linklist.cpp
	--------------------------
	Implementation of a doubly linked list with the following functionalities:
	* Insertion to head
	* Insertion to tail
	* Insert after a particular element
	* Deletion fron head
	* Deletion from tail
	* Delete a particular element
	* Search
	* In order traversal
	* Reverse order traversal
	
	121I14 -- Arjun Krishna Babu	
*/

#include<iostream>
#define PRINT_EMPTY_ERROR cerr<<"\n ERROR: Empty Linked List!";

using namespace std;

class Node	{
	int data;
	Node* next;
	Node* prev;
public:
	Node()	{
		next = NULL;
	}
	Node(int d)	{			//constructor to initialize a node with a value
		data = d;
		next = NULL;
		prev = NULL;
	}
	
	void  setData(int);
	int   getData();
	void  setNext(Node *);
	Node* getNext();
	void  setPrev(Node *);
	Node* getPrev();
};

class DoubleLinkList	{
	Node *head;
	
	bool isEmpty()	{
		return (head == NULL)? true: false;
	}
	
public:
	DoubleLinkList()	{
		head = NULL;
		
	}
	
	void insHead(int);
	void insTail(int);
	
	bool search(int);
	
	void traverse_inorder();
	void traverse_revorder();
};

int main()	{
	
	DoubleLinkList DL;
	
	int choice;
	int num;
	
	do {
		cout<<"\n [DOUBLY LINKED LIST IMPLEMENTATION]";
		cout<<"\n 1. Insert to head";
		cout<<"\n 2. Insert to tail";
		cout<<"\n 7. Search";
		cout<<"\n 8. In-order traversal";
		cout<<"\n 9. Reverse-order traversal";
		cout<<"\n 0. EXIT";
		cout<<"\n Enter Your Choice: ";
		cin>>choice;
		switch(choice)	{
			case 1: cout<<"\n Enter element to insert to head: ";
					cin>>num;
					DL.insHead(num);
					break;
			case 2: cout<<"\n Enter element to insert to tail: ";
					cin>>num;
					DL.insTail(num);
					break;
			case 7: cout<<"\n Enter element to search: ";
					cin>>num;
					if( DL.search(num) )	
						cout<<"\n Element FOUND!";
					else
						cout<<"\n Element NOT FOUND!";
					break;
			case 8: cout<<"\n Elements of linked list: \n\t";
					DL.traverse_inorder();
					break;
			case 9: cout<<"\n Element of linked list (in reverse order): \n\t";
					DL.traverse_revorder();
					break;
			case 0: cout<<"\n Program under development!";
					cout<<"\n Thank You For Using This Program!";
					break;
		   default: cerr<<"\n ERROR: Invalid Choice!";
					break;
		}
		cout<<"\n\n";				
	} while ( choice != 0 );
  return 0;		
}
/*** MEMBER FUNCTION DEFINITIONS ***/
void Node::setData(int d)	{
	data = d;
}
int  Node::getData()	{
	return data;
}

void Node::setNext(Node *A)	{
	next = A;
}
Node* Node::getNext()	{
	return next;
}

void Node::setPrev(Node *A)	{
	prev = A;
}
Node* Node::getPrev()	{
	return prev;
}

void DoubleLinkList::insHead(int d)	{
	Node *temp = new Node(d);
	
	if( isEmpty() )	{
		head = temp;
	}
	else {
		temp->setNext( head );
		head->setPrev( temp );		
		head = temp;
	}
}

void DoubleLinkList::insTail(int d)	{
	Node *temp = new Node(d);
	Node *loc = head; 
	
	if( isEmpty() )	{
		PRINT_EMPTY_ERROR;
		return;
	}
	
	while( loc->getNext() != NULL )		//traverse to last node
		loc = loc->getNext();
	
	loc->setNext( temp );
	temp->setPrev(loc);
}

bool DoubleLinkList::search(int key)	{
	Node *temp = head;

	while( temp != NULL )	{
			if( temp->getData() == key )
				return true;
			else
				temp = temp->getNext();
	}
	
	return false;		//control reaches here only if the key was not found in the list
}
	
void DoubleLinkList::traverse_inorder()	{
	Node *temp = head;
	
	if( isEmpty() ) {
		PRINT_EMPTY_ERROR;
		return;
	}
	
	cout<<" NULL ";
	while( temp != NULL )	{
		cout<<" <--> "<<temp->getData();
		temp = temp->getNext();
	}
	cout<<" <--> NULL ";
}

void DoubleLinkList::traverse_revorder()	{
	Node *temp = head;

	if( isEmpty() ) {
		PRINT_EMPTY_ERROR;
		return;
	}
	
	cout<<" NULL ";
	while( temp->getNext() != NULL )	//traverse to last node
		temp = temp->getNext();
	
	while( temp != NULL)	{
		cout<<" <--> "<<temp->getData();
		temp = temp->getPrev();
	}
	cout<<" <--> NULL ";
}
