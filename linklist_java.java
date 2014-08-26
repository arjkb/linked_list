/*
	Program to implement a linked list in Java.

	326H14 -- Arjun Krishna Babu
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

	public void dispAll()	{
		Node temp;

		temp = head;

		while( temp != null )	{
			System.out.print("-->" + temp.getData() );
			temp = temp.getNext();
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
				case 9: SOP("\n Elements of linked list: ");
						L.dispAll();
						break;
				case 0: SOP("\n Program under development by Arjun Krishna Babu");
						break;
			   default: SOP("\n Invalid Choice!");
			}

			SOP("\n\n");
		} while( choice != 0 );
	}
}
