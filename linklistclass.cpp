/*

	Program to implement a link-list using class for Node and LinkList
		1. Insert into beginning
		2. Insert into end
		3. Insert after specific element
		
		4. Delete from beginning
		5. Delete from end

		8. Search
		9. Traverse
		0. EXIT
			
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
		Node *temp = new Node();	//creates a new node
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

	void delBeg()	{
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

	void delEnd()	{

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

	bool search(int item)	{
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

	void traverse()	{
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

};

int main()	{
	LinkList L;
	int choice = 0;
	int num;
	do	{
		cout<<"\n 1: Insert into beginning";
		cout<<"\n 2: Insert into end";

		cout<<"\n 4: Delete from beginning";
		cout<<"\n 5. Delete from end";

		cout<<"\n 8: Search";
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
			case 4: L.delBeg();
					break;
			case 5: L.delEnd();
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
			case 0: cout<<"\n Program under development by Arjun K. Babu";
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
