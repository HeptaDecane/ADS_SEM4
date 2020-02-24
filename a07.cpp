//============================================================================
// Name        : Assignment7.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
// https://github.com/trusktr/gedit-color-schemes.git
//============================================================================

#include <bits/stdc++.h>
using namespace std;
int hash(string s);
class node{
	string iden;
	string attr;
	int chain;
public:
	node()
{
		iden="\0";
		attr="\0";
		chain=-1;
}
	friend class symbolTable;
};
class symbolTable{
	node G[30];
public:
	symbolTable()
{

}
	void create(int flag);
	int insertwith(int i,string s);
	int insertwithout(int i,string s);
	void display();
	int find(string s);
};
void symbolTable::create(int flag)
{
	string s,s1;
	cout<<"Keep entering identifiers and value\n";
	while(1)
	{
		cout<<"Enter identifier: ";
		cin>>s;
		if(s=="-1")
			break;
		transform(s.begin(),s.end(),s.begin(),::toupper);
		int i=hash(s);
		if(flag==1)
			i=insertwithout(i,s);
		if(flag==2)
			i=insertwith(i,s);
		cout<<"Enter attribute: ";
		cin>>s1;
		transform(s1.begin(),s1.end(),s1.begin(),::toupper);
		G[i].attr=s1;
	}
}
int symbolTable::insertwithout(int i,string s)
{
	if(G[i].iden=="\0")
	{
		G[i].iden=s;
		return i;
	}
	int j=hash(G[i].iden);
	if(i==j)
	{
		int k=i;
		while(G[k].chain!=-1)
			k=G[k].chain;
		int l=k;
		while(G[l].iden!="\0")
			l=(l+1)%30;
		G[l].iden=s;
		G[k].chain=l;
		return l;
	}
	int k=j;
	do{
		int m=hash(G[k].iden);
		if(i==m)
		{
			break;
		}
		k=(k+1)%30;
	}while(k!=j);
	if(k==j)
	{
		while(G[k].iden!="\0")
			k=(k+1)%30;
		G[k].iden=s;
		return k;
	}
	else
	{
		int l=k;
		while(G[l].chain!=-1)
			l=G[l].chain;
		while(G[l].iden!="\0")
			l=(l+1)%30;
		G[l].iden=s;
		G[k].chain=l;
		return l;
	}
}
int symbolTable::insertwith(int i,string s)
{
	if(G[i].iden=="\0")
	{
		G[i].iden=s;
		return i;
	}
	int j=hash(G[i].iden);
	if(i==j)
	{
		int k=j;
		while(G[k].chain!=-1)
			k=G[k].chain;
		int l=k;
		while(G[l].iden!="\0")
			l=(l+1)%30;
		G[l].iden=s;
		G[k].chain=l;
		return l;
	}
	if(G[j].chain==-1)
	{
		int k=j;
		while(G[k].iden!="\0")
			k=(k+1)%30;
		G[k].iden=G[i].iden;
		G[k].attr=G[i].attr;
		G[i].iden=s;
		return i;
	}
	G[j].chain=G[i].chain;
	while(G[j].chain!=-1)
		j=G[j].chain;
	int k=j;
	while(G[k].iden!="\0")
		k=(k+1)%30;
	G[k].iden=G[i].iden;
	G[k].attr=G[i].attr;
	G[j].chain=k;
	G[i].iden=s;
	G[i].chain=-1;
	return i;
}
void symbolTable::display()
{
	cout<<"Index\tIden\tAttr\tChain\n";
	for(int i=0;i<30;i++)
	{
		if(G[i].iden!="\0")
		{
			cout<<i<<"\t"<<G[i].iden<<"\t"<<G[i].attr<<"\t"<<G[i].chain<<endl;
		}
	}
}
int symbolTable::find(string s)
{
	int i=hash(s);
	int k=i;
	if(i!=hash(G[i].iden))
	{
	do{
		int j=hash(G[k].iden);
		if(i==j)
			break;
		k=(k+1)%30;
	}while(k!=i);
	}
	else
	{
		k=i;
	}
	do
	{
		if(G[k].iden==s)
		{
			cout<<"Identifier found\n";
			return k;
		}
		k=G[k].chain;
	}while(G[k].chain!=-1);
	cout<<"Not found\n";
	return -1;
}
int hash(string s)
{
	return (((int)s[0]-65)%30);
}
int main() {
	symbolTable s;
	string s1,s2;
	int choice,c; 
	do{
		cout<<"Menu\n1.Create\n2.Display\n3.Insert\n4.Find\n";
		cin>>choice;
		switch(choice){
		case 1:
			cout<<"1.Without Replacement\n2.With replacement\n";
			cin>>c;
			s.create(c);
			break;
		case 2:
			s.display();
			break;
		case 3:
			cout<<"Enter Identifier to insert:";
			cin>>s1;
			cout<<"1.Without Replacement\n2.With Replacement\n";
			cin>>c;
			int i;
			i=hash(s);
			if(c==1)
				i=insertwithout(i,s1);
			else
				i=insertwith(i,s1);
			cout<<"Enter attribute:";
			cin>>s2;

		}
	}
	s.create(2);
	s.display();
	cout<<s.find("B");
	return 0;
}
