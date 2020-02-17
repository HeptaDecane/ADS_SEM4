//============================================================================
// Name        : a03.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
class Node{
	int data;
	Node* left;
	Node *right;
	bool leftTag;
	bool rightTag;
	/*
	  	  tag=false ===> thread
		  tag=true  ===> branch
	*/
public:
	Node();
	Node(int);
	friend class TBT;
};
Node:: Node(){
	data=0;
	left=NULL;
	right=NULL;
	leftTag=false;
	rightTag=false;
}
Node::Node(int data){
	this->data=data;
	left=NULL;
	right=NULL;
	leftTag=false;
	rightTag=false;
}

class TBT{
	Node *root;
public:
	TBT();
	bool insert(int);
	void inorder();
	void preorder();
	void inorderRecursive(Node*);
	void callInorderRecursive();
	void preorderRecursive(Node*);
	void callPreorderRecursive();
	void menu();
};
TBT::TBT(){
	root=new Node(-1);

	root->leftTag=false;
	root->left=root;

	root->rightTag=false;
	root->right=root;
}
bool TBT::insert(int data){
	Node *temp=new Node(data);
	if(root->right==root and root->left==root){
		root->leftTag=true;
		root->left=temp;

		temp->leftTag=false;
		temp->left=root;

		temp->rightTag=false;
		temp->right=root;

		cout<<"\n"<<data<<" set as root";
		return true;
	}
	char pos;
	Node *p=root->left;
	bool currentLeft,currentRight;
	while(true){
		cout<<"\nChoose [L/R] of "<<p->data<<": ";
		cin>>pos;
		if(pos=='l' or pos=='L'){
			if(p->leftTag==false){
				currentLeft=true;
				currentRight=false;
				break;
			}
			else
				p=p->left;
		}
		else{
			if(p->rightTag==false){
				currentLeft=false;
				currentRight=true;
				break;
			}
			else
				p=p->right;
		}
	}
	if(currentRight){
		temp->rightTag=p->rightTag;
		temp->right=p->right;

		p->rightTag=true;
		p->right=temp;

		temp->leftTag=false;
		temp->left=p;

		cout<<"\n"<<data<<" inserted! ";
		return true;
	}
	else if(currentLeft){
		temp->leftTag=p->leftTag;
		temp->left=p->left;

		p->leftTag=true;
		p->left=temp;

		temp->rightTag=false;
		temp->right=p;
		cout<<"\n"<<data<<" inserted! ";
		return true;
	}
	else{
		cout<<"\nError While insertion!";
		return false;
	}
}

void TBT::callInorderRecursive(){
	if(root->right==root and root->left==root){
		cout<<"Tree is Empty!";
		return;
	}
	cout<<"\n";
	inorderRecursive(root->left);
}
void TBT::inorderRecursive(Node* p){
	if(p->leftTag)
		inorderRecursive(p->left);
	cout<<p->data<<" ";
	if(p->rightTag)
		inorderRecursive(p->right);
}

void TBT::callPreorderRecursive(){
	if(root->right==root and root->left==root){
		cout<<"Tree is Empty!";
		return;
	}
	cout<<"\n";
	preorderRecursive(root->left);
}
void TBT::preorderRecursive(Node* p){
	cout<<p->data<<" ";
	if(p->leftTag)
		preorderRecursive(p->left);
	if(p->rightTag)
		preorderRecursive(p->right);
}

void TBT::inorder(){
	if(root->right==root and root->left==root){
		cout<<"Tree is Empty!";
		return;
	}
	cout<<"\n";
	Node *p=root->left;
	while(p!=root){
		while(p->leftTag){
			p=p->left;
		}
		cout<<p->data<<" ";
		if(p->rightTag)
			p=p->right;
		else{
			if(p->right!=root){
				p=p->right;
				cout<<p->data<<" ";
			}
			p=p->right;
		}
	}
}

void TBT::preorder(){
	if(root->right==root and root->left==root){
		cout<<"Tree is Empty!";
		return;
	}
	cout<<"\n";
	Node *p=root->left;
	while(p!=root){
		while(p->leftTag){
			cout<<p->data<<" ";
			p=p->left;
		}
		cout<<p->data<<" ";
		if(p->rightTag)
			p=p->right;
		else{
			if(p->right!=root)
				p=p->right;
			p=p->right;
		}
	}
}
void TBT::menu(){
	cout<<"\n---------------OPTIONS---------------";
	cout<<"\nPress 1: Insert Data ";
	cout<<"\nPress 2: In-order Traversal";
	cout<<"\nPress 3: Pre-order Traversal";
	cout<<"\n-------------------------------------";
}

//int main() {
//	TBT container;
//	int arr[7]={1,2,3,4,5,6,7};
//	for(int i=0;i<7;i++)
//		container.insert(arr[i]);
//	container.callInorderRecursive();
//	container.inorder();
//	container.callPreorderRecursive();
//	container.preorder();
//	return 0;
//}

int main(){
	int data;
	TBT container;
	while(true){
		cout<<"\n\nEnter Data [Press -1 to exit]: ";
		cin>>data;
		if(data==-1)
			break;
		container.insert(data);
	}
	cout<<"\nInorder: ";
	container.inorder();

	cout<<"\nPreorder: ";
	container.preorder();
}


