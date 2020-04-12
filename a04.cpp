//============================================================================
// Name        : a04.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <bits/stdc++.h>
#include "Queue.cpp"	//paste Queue.cpp from repository into the Directory of this src file
using namespace std;
#define MAX 100

class Node{
	string city;
	float cost;
	int label;
	Node* link;
public:
	Node();
	Node(string,float,int);
	friend class List;
	friend class Graph;
};
Node::Node(){
	this->city="\0";
	this->cost=0;
	this->label=-1;
	link=NULL;
}
Node::Node(string city,float cost, int label){
	this->city=city;
	this->cost=cost;
	this->label=label;
	link=NULL;
}

class List{
	Node* start;
public:
	List();
	void insert(string,float,int);
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
void List::insert(string city,float cost,int label){
	Node *temp=new Node(city,cost,label);
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
		cout<<"|"<<p->city<<"|"<<p->cost<<"|"<<p->label<<"|----";
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
	void traverseBFS(string);
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
	array[count].insert(city,0,count);
	count++;
	return true;
}
void Graph::addEdge(string source,string destination,float cost){
	int i,j,label;
	for(i=0;i<count;i++){
		if(array[i].start->city==source)
			break;
	}
	for(j=0;j<count;j++){
		if(array[j].start->city==destination){
			label=array[j].start->label;
			break;
		}
	}
	if(i==count||j==count||i==j){
		cout<<"\nInvalid Source and/or Destination";
		return;
	}
	array[i].insert(destination,cost,label);
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
void Graph::traverseBFS(string city){
	int i,label;
	Node *p=NULL;
	for(i=0;i<count;i++){
		if(array[i].start->city==city){
			p=array[i].start;
			break;
		}
	}
	if(i==count){
		cout<<"\nCity: "<<city<<" Doesn't Exist!";
		return;
	}
	Queue<Node*> q;
	bool visited[count];
	for(int i=0;i<count;i++)
		visited[i]=false;

	q.push(p);
	while(q.empty()==false){
		p=q.front();
		q.pop();

		label=p->label;
		visited[label]=true;
		p=array[label].start;
		cout<<p->city<<" ";

		for(Node *ptr=p->link;ptr!=NULL;ptr=ptr->link){
			if(!visited[ptr->label]){
				q.push(ptr);
				visited[ptr->label]=true;
			}
		}
	}
}
void Graph::menu(){
	cout<<"\n--------------------------OPTION INDEX--------------------------";
	cout<<"\nPress 1: Add City in DataBase (Add Vertex in Graph)";
	cout<<"\nPress 2: Connect Two Cities (Add Edge in Graph)";
	cout<<"\nPress 3: Display Adjacency List:";
	cout<<"\nPress 4: DisConnect Two Cities (Delete Edge from Graph)";
	cout<<"\nPress 5: Delete City from DataBase (Delete Vertex from Graph)";
	cout<<"\nPress 6: Out-Going Traffic (Out-Degree)";
	cout<<"\nPress 7: In-Coming Traffic (In-Degree)";
	cout<<"\nPress 8: Traversal";
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
			case 3: flights.display();
					break;
			case 4:	cout<<"\nEnter Source City: ";cin>>source;
					cout<<"\nEnter Destination City: ";cin>>destination;
					flights.deleteEdge(source,destination);
					break;
			case 5: cout<<"\nEnter City to be Deleted: ";cin>>city;
					flights.deleteVertex(city);
					break;
			case 6: cout<<"\nEnter City: ";cin>>city;
					cout<<"\nOut-Going Traffic: "<<flights.outDegree(city);
					break;
			case 7: cout<<"\nEnter City: ";cin>>city;
					cout<<"\nIn-Coming Traffic: "<<flights.inDegree(city);
					break;
			case 8: cout<<"\nEnter City to Start Traversal: ";
					cin>>city;
					flights.traverseBFS(city);
					break;
			case 99:flights.menu();
					break;
			default:cout<<"\nInvalid Choice!";
			}
			cout<<"\nEnter Choice [99-INDEX|0-EXIT]: ";
			cin>>choice;
		}
		cout<<"\nEND";
}
/*

1 1 1 2 1 3 2 1 2 0 2 2 3 0

1 1 1 2 1 3 1 4 1 5 1 6 1 7 1 8 1 9 2 1 2 0 2 1 3 0 2 2 4 0 2 2 5 0 2 3 1 0 2 3 5 0 2 4 6 0 2 4 7 0 2 4 2 0 2 5 2 0 2 5 3 0 2 5 8 0 2 6 4 0 2 6 9 0 2 7 4 0 2 8 5 0 2 9 6 0

*/
