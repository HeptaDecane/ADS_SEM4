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
	bool search(string);
	int count();
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
	for(p=start;p->link!=NULL;p=p->link);
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
int List::count(){
	int count=0;
	for(Node *p=start->link;p!=NULL;p=p->link)
		count++;
	return count;
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
bool List::search(string city){
	Node *p;
	for(p=start->link;p!=NULL;p=p->link){
		if(p->city==city)
			return true;
	}
	return false;
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
	int outDegree(string);
	int inDegree(string);
	void menu();
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
void Graph::addEdge(string source,string destination,float cost){
	int i,j;
	for(i=0;i<count;i++){
		if(array[i].start->city==source)
			break;
	}
	for(j=0;j<count;j++){
		if(array[j].start->city==destination)
			break;
	}
	if(i==count||j==count||i==j){
		cout<<"\nInvalid Source and/or Destination";
		return;
	}
	array[i].insert(destination,cost);
}
void Graph::display(){
	for(int i=0;i<count;i++){
		cout<<"\n";
		array[i].display();
	}
}
bool Graph::deleteEdge(string source,string destination){
	int i;
	for(i=0;i<count;i++){
		if(array[i].start->city==source)
			break;
	}
	if(i==count){
		cout<<"\nSource: "<<source<<" Doesn't Exist!";
		return false;
	}
	return array[i].deleteNode(destination);
}
bool Graph::deleteVertex(string city){
	int i;
	for(i=0;i<count;i++){
		if(array[i].start->city==city)
			break;
	}
	if(i==count){
		cout<<"\nCity: "<<city<<" Doesn't Exist!";
		return false;
	}
	array[i].erase();
	count--;
	for(int j=i;j<count;j++){
		array[j]=array[j+1];
	};
	for(int j=0;j<count;j++){
		array[j].deleteNode(city);
	}
	return true;
}
int Graph::outDegree(string city){
	int i;
	for(i=0;i<count;i++){
		if(array[i].start->city==city)
			break;
	}
	if(i==count){
		cout<<"\nCity: "<<city<<" Doesn't Exist!";
		return -1;
	}
	return array[i].count();
}
int Graph::inDegree(string city){
	int i,cnt=0;
	for(i=0;i<count;i++){
		if(array[i].start->city==city)
			break;
	}
	if(i==count){
		cout<<"\nCity: "<<city<<" Doesn't Exist!";
		return -1;
	}
	for(int i=0;i<count;i++){
		if(array[i].search(city)==true)
			cnt++;
	}
	return cnt;
}
void Graph::menu(){
	cout<<"\n--------------------------OPTION INDEX--------------------------";
	cout<<"\nPress 1: Add City in DataBase (Add Vertex in Graph)";
	cout<<"\nPress 2: Connect Two Cities (Add Edge in Graph)";
	cout<<"\nPress 3: DisConnect Two Cities (Delete Edge from Graph)";
	cout<<"\nPress 4: Delete City from DataBase (Delete Vertex from Graph)";
	cout<<"\nPress 5: Out-Going Traffic (Out-Degree)";
	cout<<"\nPress 6: In-Coming Traffic (In-Degree)";
	cout<<"\nPress 7: Traversal";
	cout<<"\n----------------------------------------------------------------";
}
int main(){
		Graph flights;
		string source,destination,city;
		float cost;
		int choice;
		flights.menu();
		cout<<"\nEnter Choice [99-INDEX|0-EXIT]: ";
		cin>>choice;
		while(choice){
			switch(choice){
			case 1:	cout<<"\nEnter City Name: ";cin>>city;
					flights.addVertex(city);
					break;
			case 2: cout<<"\nEnter Source City: ";cin>>source;
					cout<<"\nEnter Destination City: ";cin>>destination;
					cout<<"\nEnter Cost: ";cin>>cost;
					flights.addEdge(source,destination,cost);
					break;

			}
		}
}
//int main() {
//	Graph flights;
//	flights.addVertex("Pune");
//	flights.addVertex("Mumbai");
//	flights.addVertex("Nashik");
//	flights.addEdge("Pune","Mumbai",50);
//	flights.addEdge("Pune","Nashik",60);
//
//	flights.addEdge("Mumbai","Pune",70);
//	flights.addEdge("Mumbai","Nashik",80);
//
//	flights.addEdge("Nashik","Mumbai",85);
//	flights.addEdge("Nashik","Pune",88);
//
//	flights.display();
//	cout<<"\n"<<flights.inDegree("Pune");
//
//	return 0;
//}
