/*
	FILE: linklistclass.cpp
	--------------------------------------------------------------------
	Program to implement a link-list using class for Node and LinkList
		1. Insert at beginning
		2. Insert at end
		3. Insert after specific element
		
		4. Delete from beginning
		5. Delete specific node
		6. Delete from end

		8. Search
		9. Traverse
		0. EXIT
	------------------------------------------		
	|	CODER	: Arjun Krishna Babu		 |
	|	DATE	: 20 - August - 2014		 |
	|										 |
	|	COMPILER	: G++					 |
	|	OS			: Ubuntu 12.04 LTS		 |
	|	PROCESSOR	: 4th gen. Intel Core i5 |
	------------------------------------------	
*/
#include<iostream>

using namespace std;

class Node	{
private:
	int data;
	Node *next;
public:
	Node(): next(NULL)	{ }			//constructor to initialize next address to NULL

	/* setter and getter for data */
	void setData(int);
	int getData();
	
	/*	setter and getter for link */
	void setNext(Node *A);
	Node* getNext();
};

class LinkList	{
private:
	Node *head;		//keeps track of beginning of node
public:
	LinkList(): head(NULL) { }	//constructor to intialize current address to NULL
	
	void insBeg(int);
	void insEnd(int);
	void insAfter(int after, int item);
	
	void delBeg();
	void delNode(int item);		//deletes node containing specified item
	void delEnd();
	
	bool search(int);
	void traverse();	
};

int main()	{
	LinkList L;
	int choice = 0;
	int num, pos;
	do	{
		cout<<"\n [LINKED LIST OPERATIONS]\n";
		cout<<"\n 1: Insert at beginning";
		cout<<"\n 2: Insert at end";
		cout<<"\n 3: Insert after specific element";

		cout<<"\n 4: Delete from beginning";
		cout<<"\n 5: Delete specific node";
		cout<<"\n 6. Delete from end";

		cout<<"\n 8: Search";
		cout<<"\n 9: Traverse";
		cout<<"\n 0: EXIT";
		cout<<"\n\n Enter Your Choice: ";
			cin>>choice;
		switch(choice)	{
			case 1: cout<<"\n Enter an element to insert into beginning of the linked list: ";
					cin>>num;
					L.insBeg(num);
					break;
			case 2: cout<<"\n Enter an element to insert into end of the linked list: ";
					cin>>num;
					L.insEnd(num);
					break;
			case 3: cout<<"\n Enter the element to insert: ";
					cin>>num;
					cout<<"\n After which element should "<<num<<" be inserted: ";
					cin>>pos;
					L.insAfter(pos, num);
					break;
			case 4: L.delBeg();
					break;
			case 5: cout<<"\n Enter the element to be deleted: ";
					cin>>num;
					L.delNode(num);
					break;
			case 6: L.delEnd();
					break;
			case 8: cout<<"\n Enter element to search for in the list: ";
					cin>>num;
					if( L.search(num) )
						cout<<"\n Element found!";
					else
						cout<<"\n Element not found!";
					break;
			case 9: cout<<"\n Elements in the linked list: "; L.traverse();
					break;
			case 0: cout<<"\n Program under development by Arjun Krishna Babu";
					cout<<"\n https://github.com/arjunkbabu/linked_list";
					break;
		   default: cout<<"\n ERROR: Invalid Choice!";
		  			break;
		}

		cout<<"\n\n";
	}while(choice != 0);

   cout<<"\n\n";
   return 0;
}
/*** MEMBER FUNCTION DEFINITIONS ***/

/*** NODE CLASS FUNCTION DEFINITIONS: */
void Node::setData(int d)	{
	data = d;
}

int Node::getData()	{
	return data;
}

void Node::setNext(Node *A)	{
	next = A;
}

Node* Node::getNext()	{
	return next;
}
/*	*	*	*	*	*	*	*	*	*/

/*** LINKLIST CLASS FUNCTION DEFINITONS: */
void LinkList::insBeg(int dd)	{
	Node *temp = new Node();	//creates a new node
	temp->setData(dd);			//sets value to the new node

	if(head == NULL)	{	//if the link-list is empty
//		temp->setNext(NULL);
		head = temp;
	}
	else	{
		temp->setNext(head);	//make the newly-created node point to the existing head
		head = temp;
	}
}

void LinkList::insEnd(int dd)	{
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

void LinkList::insAfter(int after, int dd)	{
	Node *temp = new Node();
	temp->setData(dd);

	Node *loc = head;

	bool found = false;

	while(loc != NULL)	{

		if(loc->getData() == after)	{
			temp->setNext( loc->getNext() );
			loc->setNext(temp);
			found = true;
			break;
		}
		else
			loc = loc->getNext();
	}
	if(!found)	{
		cout<<"\n ERROR: Cannot find "<<after<<" in the linked list";
		cout<<"\n No changes have been made to the linked list";
	}
}

void LinkList::delBeg()	{
	Node *temp;
	
	if(head == NULL)	{
		cout<<" ERROR: Cannot delete empty linked list";
	}
	else	{
		temp = head;
		cout<<"\n Deleting element: "<<temp->getData()<<"\n\n";
		head = head->getNext();	//make head point to the next element in the linked list
		delete temp;
	}
}

void LinkList::delNode(int dd)	{
	Node *loc = head;
	Node *prev;
	if( head->getData() == dd )	{	//if node to be deleted is the first node
		head = head->getNext();
		delete loc;
		return;
	}

	else	{
		prev = head;
		loc = head->getNext();
		while(loc != NULL)	{
			if( loc->getData() == dd )	{
				prev->setNext( loc->getNext() );	//set next address of pevious node to next address of node to be deleted
				delete loc;							//deallocate memory
				break;
			}
			else	{
				loc   = loc->getNext();
				prev  = prev->getNext();
			}
		} //end of while()
	}
}

void LinkList::delEnd()	{
	Node *temp;
	Node *prev;
	if(head == NULL)	{
		cout<<"\n ERROR: Cannot delete empty linked list";
	}

	else if(head->getNext() == NULL)	{	//if only one element exists in the linked list
		temp = head;
		head = NULL;
		delete temp;		//free the allocated memory
	}
	else	{
		temp = head->getNext();
		prev = head;

		while( temp->getNext() != NULL)	{ //traverse to the end of the linked list
			temp = temp->getNext();
			prev = prev->getNext();
		}
		prev->setNext(temp->getNext());
			
		cout<<"\n Deleting element: "<<temp->getData();
		delete temp;		//free the allocated memory
	}
}

bool LinkList::search(int item)	{
	Node *temp = head;

	while(temp != NULL)	{
		if(temp->getData() == item)	{
			return true;
		}
		else
			temp = temp->getNext();
	}
	
	return false;		//control reaches here only after finishing while loop (==> element absent in list)
}

void LinkList::traverse()	{
	Node *loc = head;
	if(head == NULL)	{
		cout<<" ERROR: EMPTY LIST!\n";
		return;
	}

	while(loc != NULL)	{			
		cout<<"-->"<<(loc->getData());
		loc = loc->getNext();
	}
	cout<<"\n\n";
}
