/*
	FILE: linklist_java.java
	------------------------------------------------
	Program to implement linked list in Java, 
	capable of performing the following operations:

		1. Insert to beginning
		2. Insert to end
		3. Insert after specific node

		4. Delete from beginning
		5. Delete from end
		6. Delete specific node

		7. Search
		9. Traverse
		0. EXIT
	-------------------------------------------------

	CODER	: Arjun Krishna Babu
	DATE	: 27 - August - 2014

	COMPILER	: JAVAC
	OS			: Ubuntu 12.04 LTS
	-------------------------------------------------
*/

import java.util.*;


class Node	{
	private int data;
	private Node next;

	public void setData(int dd)	{
		data = dd;
	}

	public int getData()	{
		return data;
	}

	public void setNext(Node A)	{
		next = A;
	}

	public Node getNext()	{
		return next;
	}
}

class LinkList	{
	private Node head;
	
	LinkList()	{
		head = null;
	}

	public void insBeg(int d)	{
		
		Node temp = new Node();
		temp.setData(d);
		temp.setNext(null);

		if( head == null )
			head = temp;
		else	{
			temp.setNext(head);
			head = temp;
		}
	}

	public void insEnd(int d)	{
		Node temp = new Node();
		temp.setData(d);
		temp.setNext(null);
			
		Node loc = head;

		if( head == null )	{
			head = temp;
		}
		else	{
			while( loc.getNext() != null )	{	//traverse to the last node in the list
				loc = loc.getNext();
			}
			loc.setNext(temp);
		}
	}

	public void delBeg()	{
		Node temp;

		if( head == null )	
			System.out.print("\n ERROR: Underflow!");
		else {
			temp = head;
			System.out.print("\n Deleting Element: " + temp.getData() );
			head = head.getNext();
		}
	}

	public void traverse()	{
		Node temp;
		temp = head;
		if( head == null )	
			System.out.print("\n ERROR: No elements in linked list!");
		else	{
			while( temp != null )	{
				System.out.print("-->" + temp.getData() );
				temp = temp.getNext();
			}
		}
	}
}

class linklist_java	{

	private static void SOP(String S)	{
		System.out.print(S);
	}
	public static void main(String args[])	{
		Scanner in = new Scanner(System.in);
		int choice, num;

		LinkList L = new LinkList();

		do	{
			SOP("\n [JAVA IMPLEMENTATION OF LINKED LIST]");
			SOP("\n 1. Insert into beginning");
			SOP("\n 2. Insert into end");
			SOP("\n 4. Delete from beginning");
			SOP("\n 9. Display all elements");
			SOP("\n 0. EXIT");
			SOP("\n Enter Your Choice: ");
			choice = in.nextInt();
			switch(choice)	{
				case 1: SOP("\n Enter element to insert into beginning of linked list: ");
						num = in.nextInt();
						L.insBeg(num);
						break;
				case 2: SOP("\n Enter element to insert at the end of linked list: ");
						num = in.nextInt();
						L.insEnd(num);
						break;
				case 4: L.delBeg();
						break;
				case 9: SOP("\n Elements of linked list: ");
						L.traverse();
						break;
				case 0: SOP("\n Program under development by Arjun Krishna Babu");
						SOP("\n https://github.com/arjunkbabu/linked_list");
						break;
			   default: SOP("\n Invalid Choice!");
			}

			SOP("\n\n");
		} while( choice != 0 );
	}
}
