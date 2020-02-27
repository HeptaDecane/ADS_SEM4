#include<bits/stdc++.h>
using namespace std;
#define MAX 29

/**************************************************************************************************/

class Node{
	string identifier;
	int scope;
	string type;
	string value;
	Node *link;
public:
	Node();
	Node(string,int,string,string);
	void print();
	friend class List;
	friend class Table;
};


Node::Node(){
	this->identifier[0]='\0';
	this->scope=0;
	this->type[0]='\0';
	this->value[0]='\0';
	link=NULL;
}


Node::Node(string identifier, int scope, string type, string value){
	this->identifier=identifier;
	this->scope=scope;
	this->type=type;
	this->value=value;
	link=NULL;
}


void Node::print(){
	cout<<"\n\t| Identifier |  "<<identifier;
	if(scope==0)
		cout<<"\n\t| Scope      |  Global";
	else
		cout<<"\n\t| Scope      |  "<<scope;
	cout<<"\n\t| Type       |  "<<type;
	cout<<"\n\t| Value      |  "<<value;
}

/**************************************************************************************************/

class List{
	Node *start;
public:
	List(){start=NULL;}
	void pushFront(string,int,string,string);
	void pushFront(Node*);
	void pushBack(string,int,string,string);
	void pushBack(Node*);
	Node* popFront();
	bool deleteNode(string,int);
	void print();
	bool searchNode(string);
	bool declared(string,int);
	friend class Table;
};


void List::pushFront(string identifier,int scope,string type,string value){
	Node* temp=new Node(identifier,scope,type,value);
	temp->link=start;
	start=temp;
	return;
}


void List::pushFront(Node *temp){
	temp->link=start;
	start=temp;
	return;
}


void List::pushBack(string identifier,int scope,string type,string value){
	Node *temp=new Node(identifier,scope,type,value);
	if(start==NULL){
		start=temp;
		return;
	}
	Node *p=start;
	for(p=start;p->link!=NULL;p=p->link);
	p->link=temp;
	return;
}


void List::pushBack(Node *temp){
	if(start==NULL){
		start=temp;
		return;
	}
	Node *p=start;
	for(p=start;p->link!=NULL;p=p->link);
	p->link=temp;
	return;
}


Node* List::popFront(){
	Node *p=start;
	start=start->link;
	p->link=NULL;
	return p;
}


void List::print(){
	for(Node* p=start;p!=NULL;p=p->link)
		p->print();
}


bool List::searchNode(string identifier){
	bool flag=false;
	for(Node *p=start;p!=NULL;p=p->link){
		if(p->identifier==identifier){
			p->print();
			cout<<"\n";
			flag=true;
		}
	}
	return flag;
}


bool List::declared(string identifier,int scope){
	for(Node *p=start;p!=NULL;p=p->link){
		if(p->identifier==identifier&&p->scope==scope)
			return true;
	}
	return false;	
}


bool List::deleteNode(string identifier,int scope){
	if(start==NULL)
		return false;
	Node *p=NULL;
	Node *q=start;
	for(q=start;q!=NULL;q=q->link){
		if(q->identifier==identifier&&q->scope==scope)
			break;
		p=q;
	}
	if(q==NULL)
		return false;
	else if(p==NULL){
		p=start;
		start=start->link;
		p->link=NULL;
		delete p;
		return true;
	}
	else{
		p->link=q->link;
		q->link=NULL;
		delete q;
		return true;
	}
}

/**************************************************************************************************/

class Table{
	List row[MAX];
public:
	void insertWithReplacement(string,int,string,string);
	void insertWithoutReplacement(string,int,string,string);
	void searchIdentifier(string);
	void deleteIdentifier(string,int);
	bool modifyIdentifier(string,int,string,string);
	int hashFunction(string identifier);
};
int Table::hashFunction(string identifier){
	int sum=0;
	for(int i=0;i<identifier.length();i++)
		sum=sum+identifier;
		
	return sum%MAX;
}
void Table::insertWithoutReplacement(string identifier,int scope,string type,string value){
	Node *data=new Node(identifier,scope,type,value);
	int index=hashFunction(identifier);
	row[index].pushBack(data);
}






























