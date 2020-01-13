//============================================================================
// Name        : a04.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "bits/stdc++.h"
using namespace std;
#define MAX 100
class Node{
	string city;
	float cost;
	Node* link;
public:
	Node(string,float);
	friend class List;
	friend class Graph;
};
Node::Node(string city,float cost){
	this->city=city;
	this->cost=cost;
	link=NULL;
}
class List{
	Node* start;
public:
	List();
	void insert(string,float);
	bool deleteNode(string);
	void erase();
	void display();
	friend class Graph;
};
List::List(){
	start=NULL;
}
void List::insert(string city,float cost){
	Node *temp=new Node(city,cost);
	if(start==NULL){
		start=temp;
		return;
	}
	Node *p;
	for(p=start;p->link!=NULL;p=p->link)
	p->link=temp;
}
bool List::deleteNode(string city){
	Node *p=start;
	Node *q=start->link;
	for(q=start->link;q!=NULL;q=q->link){
		if(q->city==city)
			break;
		p=q;
	}
	if(q==NULL)	return false;
	p->link=q->link;
	delete q;
	return true;
}
void List::erase(){
	Node *p=start;
	Node *temp=NULL;
	while(p!=NULL){
		temp=p;
		p=p->link;
		temp->link=NULL;
		delete temp;
	}
}
void List::display(){
	for(Node *p=start;p!=NULL;p=p->link)
		cout<<"|"<<p->city<<"|"<<p->cost<<"|----";
	cout<<"X";
}
class Graph{
	List array[MAX];
	int count;
public:
	Graph();
	bool addVertex(string);
	void addEdge(string,string,float);
	bool deleteVertex(string);
	bool deleteEdge(string,string);
	void display();
};
Graph::Graph(){
	count=0;
}
bool Graph::addVertex(string city){
	for(int i=0;i<count;i++)
		if (array[i].start->city==city){
			cout<<"\n"<<city<<" Already Exists in Graph!";
			return false;
		}
	array[count].insert(city,0);
	count++;
	return true;
}
void Graph::display(){
	for(int i=0;i<count;i++){
		cout<<"\n";
		array[i].display();
	}
}
int main() {
	Graph flights;
	flights.addVertex("Pune");
	flights.addVertex("Mumbai");
	flights.addVertex("Nashik");
	flights.display();
	return 0;
}
