#include "bits/stdc++.h"
using namespace std;
#define TAB 8

class Node{
	int data;
	Node *left;
	Node *right;
public:
	Node(int);
	friend class Tree;
	friend class Stack;
};

Node::Node(int data){
	this->data=data;
	left=NULL;
	right=NULL;
}
class Tree{
private:
	Node *root;
public:
	Tree();
	void insert(int);
	
	void callDisplay2D();
	void display2D(Node*,int);
	
	//Method 1: using printGivenLevel();
	void printLevelOrder();
	int height(Node*);
	void printGivenLevel(Node*,int);
	
	//Method 2: using queue
	void queueLevelOrder();
};

Tree::Tree(){
	root=NULL;
}

void Tree::insert(int data){
	Node *temp=new Node(data);
	if(root==NULL){
		root=temp;
		cout<<"\n"<<data<<" has been Set as Root Node";
		return;
	}
	Node *p=root;
	while(true){
		if(p->data>temp->data)
			if(p->left==NULL){
				p->left=temp;
				cout<<"\n"<<data<<" Inserted";
				return;
			}
			else
				p=p->left;
		else if(p->data<temp->data)
			if(p->right==NULL){
				p->right=temp;
				cout<<"\n"<<data<<" Inserted";
				return;
			}
			else
				p=p->right;
		else{
			cout<<"\n"<<data<<" already exists in BST";
			return;
		}
	}
}

void Tree::printLevelOrder(){
	int h=height(this->root);
	for(int i=1;i<=h;i++){
		cout<<"\n";
		printGivenLevel(this->root,i);
	}
}
int Tree::height(Node *p){
	if(p==NULL)
		return 0;
	int leftHeight=height(p->left);
	int rightHeight=height(p->right);
	return max(leftHeight,rightHeight)+1;
}
void Tree::printGivenLevel(Node *p,int level){
	if(p==NULL)
		return;
	if(level==1)
		cout<<p->data<<" ";
	else if(level>1){
		printGivenLevel(p->left,level-1);
		printGivenLevel(p->right,level-1);
	}
}


void Tree::queueLevelOrder(){
	if(root==NULL)
		return;
	queue<Node*> queue;
	queue.push(root);
	Node *p;
	while(!queue.empty()){
		p=queue.front();
		cout<<p->data<<" ";
		queue.pop();
		if(p->left!=NULL)
			queue.push(p->left);
		if(p->right!=NULL)
			queue.push(p->right);
	}
}
void Tree::callDisplay2D(){
	if(root==NULL){
		cout<<"ROOT->NULL";
		return;
	}
	display2D(root,0);
}
//Works as Reverse Inorder
void Tree::display2D(Node *p,int space){
	if(p==NULL)
		return;
	space+=TAB;	
	display2D(p->right,space);
	
	cout<<"\n";
	for(int i=TAB;i<space;i++)cout<<" ";
	cout<<p->data<<"\n";
	
	display2D(p->left,space);
}


int main(){
	int elements[]={50,20,70,60,80,10,30,5,15,25,35};
	int n=sizeof(elements)/sizeof(int);
	Tree container;
	
	for(int i=0;i<n;i++)container.insert(elements[i]);
	
	cout<<"\n";
	container.callDisplay2D();
	cout<<"\n";
	
	cout<<"\n\nLevel Order Search [using printGivenLevel()]";
	container.printLevelOrder();
	
	cout<<"\n\nLevel Order Search [using queue]\n";
	container.queueLevelOrder();
	
	return 0;
}
//44 , 17 , 88 , 32 , 28 , 29 , 65 , 97 , 54 , 82 , 76 , 80 , 78
