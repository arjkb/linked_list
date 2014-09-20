/*
	FILE: circular_linklist.cpp
	----------------------------
	
	Program to implement a circular linked list with the following functions
	* Insertion to tail
	* Insertion to head
	* Insert after a particular node
	* Deletion from tail
	* Deletion from head
	* Delete a particular node
	* Search for an element
	* Traversal

	720I14 -- Arjun Krishna Babu
*/

#include<iostream>

using namespace std;

class Node	{
	int data;
	Node* next;
public:	
	Node()	{
		next = NULL;
	}
	Node(int d)	{
		data = d;
		next = NULL;
	}
	
	void  setData(int);
	int   getData();
	void  setNext(Node *);
	Node* getNext();
};

class CircleLink	{
	Node *tail;
protected:
	bool isEmpty();
public:
	CircleLink()	{
		tail = NULL;
	}
	void insTail(int);
	void insHead(int);
	void delTail();
	void traverse();
};

int main()	{
	
	CircleLink CL;
	
	int choice;
	int num;
	do
	{
		cout<<"\n 1. Insert to tail";
		cout<<"\n 2. Insert to head";
	
//	 	cout<<"\n 3. Insert after an element";
	
		cout<<"\n 4. Delete tail";
	/*
		cout<<"\n 5. Delete head";
		cout<<"\n 6. Delete a particular node";
		cout<<"\n 7. Search";
	*/	
		cout<<"\n 9. Traverse";
		cout<<"\n 0. EXIT";
		cout<<"\n Enter Your Choice: ";
		cin>>choice;
		
		switch(choice)	{
			case 1: cout<<"\n Enter element to insert to tail: ";
					cin>>num;
					CL.insTail(num);
					break;
			case 2: cout<<"\n Enter element to insert to head: ";
					cin>>num;
					CL.insHead(num);
					break;
			case 4: CL.delTail();
					break;
			case 9: CL.traverse();
					break;
			case 0: cout<<"\n Program under development!";
					cout<<"\n Thank You For Using This Program!";
					break;
		   default: cout<<"\n ERROR: Invalid Choice!";
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
int Node::getData()	{
	return data;
}
void Node::setNext(Node* A)	{
	next = A;
}
Node* Node::getNext()	{
	return next;
}

bool CircleLink::isEmpty()	{
	return (tail == NULL)? true: false;
}

void CircleLink::insTail(int d)	{
	Node *temp = new Node(d);
	
	if( isEmpty() )	{
		temp->setNext(temp);
		tail = temp;
	}
	else {
		temp->setNext( tail->getNext() );  //make new node point to existing starting node
		tail->setNext( temp );			   //make new node the next node after existing tail
		tail = temp;	
	}

}

void CircleLink::insHead(int d)	{
	Node *temp = new Node(d);		//initialize a new node with the data

	if( isEmpty() )	{
		temp->setNext(temp);
		tail = temp;
	}
	else {
		temp->setNext( tail->getNext() );
		tail->setNext( temp );	
	}
}

void CircleLink::delTail()	{
	
	Node *temp;	//stores address of node to be deleted
	Node *loc;	

	if( isEmpty() )	{
		cerr<<"\n ERROR: Empty Linked List!";
	}
	else if( tail->getNext() == tail )	{	//if there is only one node
		temp = tail;
		cout<<"\n Deleting Element: "<<temp->getData();
		tail = NULL;
		delete temp;
	}
	else {
		temp = tail;
		loc = tail->getNext();
		
		while( loc->getNext() != tail )	//traverse to node right before tail
			loc = loc->getNext();

		loc->setNext( tail->getNext() );	//make it point to start node
		tail = loc; 
				
		delete temp;	
	}
}
	
void CircleLink::traverse()	{
	if( isEmpty() )	{
		cerr<<"\n ERROR: Empty Linked List!";
	}
	else {
		
		Node *temp = tail->getNext();
		
		do {
			cout<<"-->"<<temp->getData();
			temp = temp->getNext();	
		} while ( temp != tail->getNext() );
		
		cout<<"<-- TAIL";
	}
}
