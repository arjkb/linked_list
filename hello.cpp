/*
	Program to print "Hello World, Hello Yourname!"

	521J14 -- Arjun Krishna Babu
*/

#include<iostream>
#include<cstdio>

using namespace std;

int main()	{
	char S[100];

	cout<<"\n Enter Your Name: ";
		gets(S);
	cout<<"\n Hello World, Hello "<<S<<"!";

   cout<<"\n\n";
   return 0;
}
