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

	CODER: Arjun Krishna Babu
	DATE : 21 - September - 2014
*/

#include<iostream>

#define PRINT_EMPTY_ERROR cerr<<"\n ERROR: Empty Linked List!";

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
	void insTail(int elem);
	void insHead(int elem);
	void insAfter(int elem, int pos);
	void delTail();
	void delHead();
	void delElem(int elem);
	bool search(int elem);
	void traverse();
};

int main()	{
	
	CircleLink CL;
	
	int choice;
	int num, pos;
	do
	{
		cout<<"\n 1. Insert to tail";
		cout<<"\n 2. Insert to head";
	 	cout<<"\n 3. Insert after an element";
		cout<<"\n";
		cout<<"\n 4. Delete tail";
		cout<<"\n 5. Delete head";
		cout<<"\n 6. Delete a particular node";
		cout<<"\n";
		cout<<"\n 7. Search";	
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
			case 3: cout<<"\n Eneter element to insert: ";
					cin>>num;
					cout<<"\n After which element should this node be inserted: ";
					cin>>pos;
					CL.insAfter(num, pos);
					break;
			case 4: CL.delTail();
					break;
			case 5: CL.delHead();
					break;
			case 6: cout<<"\n Enter the element you wish to delete: ";
					cin>>num;
					CL.delElem(num);
					break;
			case 7: cout<<"\n Enter an element to seach in the linked list: ";
					cin>>num;
					if( CL.search(num) )
						cout<<"\n Element FOUND!";
					else
						cout<<"\n Element NOT FOUND!";
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

void CircleLink::insAfter(int d, int pos)	{
	Node *temp = new Node(d);
	Node *loc = tail;
	bool found = false;
	
	if( isEmpty() )	{
		PRINT_EMPTY_ERROR;
		return;
	}
	
	do {
		if( loc->getData() == pos )	{
			found = true;
			if( loc == tail )	{
				temp->setNext( tail->getNext() );
				tail->setNext(temp);
				tail = temp;
			}
			else {
				temp->setNext( loc->getNext() );
				loc->setNext(temp);
			}
		  break;
		}
		else
			loc = loc->getNext();
	} while ( loc != tail );
	if( !found )
		cerr<<"\n ERROR: "<<pos<<" not in linked list!";
}

void CircleLink::delTail()	{
	
	Node *temp;	//stores address of node to be deleted
	Node *loc;	

	if( isEmpty() )	{
		PRINT_EMPTY_ERROR;
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
		
		while( loc->getNext() != tail )		//traverse to node right before tail
			loc = loc->getNext();

		loc->setNext( tail->getNext() );	//make it point to start node
		tail = loc; 
		
		cout<<"\n Deleting Element: "<<temp->getData();		
		delete temp;	
	}
}

void CircleLink::delHead()	{
	Node *temp;
	
	if( isEmpty() )	{
		PRINT_EMPTY_ERROR;
	}
	else if( tail->getNext() == tail )	{
		temp = tail;
		cout<<"\n Deleting Element: "<<temp->getData();
		tail = NULL;
		delete temp;
	}
	else {  
		temp = tail->getNext();
		tail->setNext( temp->getNext() );
		cout<<"\n Deleting Element: "<<temp->getData();
		delete temp;
	}
}

void CircleLink::delElem(int d)	{
	Node *temp;
	Node *loc;

	bool found = false;
	
	temp = tail->getNext();
	loc = tail;
	
	do {
		if( temp->getData() == d )	{
			found = true;
			if( temp == tail )
				delTail();
			
			else if( temp == tail->getNext() )
				delHead();
				
			else {
				loc->setNext( temp->getNext() );
				delete temp;
			}
			
			break;	// (a possibly faster alternative would be to use 'return')
		}
		
		else {
			loc  = temp;
			temp = temp->getNext();
		}
	} while ( temp != tail->getNext());
	
	if( !found )
		cerr<<"\n ERROR: Element not in linked list!";
}
		

bool CircleLink::search(int key)	{
	Node *temp;
	
	if( isEmpty() )
		return false;
	else {
		temp = tail;
		do {
			if( temp->getData() == key )	
				return true;
			else
				temp = temp->getNext();
		} while ( temp != tail );
	}
	
	return false;	//control reaches here only if the element is not in the list	
}
	
void CircleLink::traverse()	{
	if( isEmpty() )	{
		PRINT_EMPTY_ERROR;
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
