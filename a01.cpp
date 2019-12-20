#include<bits/stdc++.h>
using namespace std;
class Node{
	int data;
	Node *left;
	Node *right;
public:
	Node(int);
	friend class Tree;
};
Node::Node(int data){
	this->data=data;
	left=NULL;
	right=NULL;
}
class Tree{
	Node *root;
public:
	Tree();
	void insert(int);
	void searchTreeInsert(int);
	void passInorderRecursive();
	void traverseInorderRecursive(Node *);
	void passPreorderRecursive();
	void traversePreorderRecursive(Node *);
	void passPostorderRecursive();
	void traversePostorderRecursive(Node *);
	void inorderIterative();
	void preorderIterative();
	void postorderIterative();
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
	char pos;
	while(true){
		cout<<"\nChoose L/R of "<<p->data<<": ";
		cin>>pos;
		if(pos=='l'||pos=='L')
			if(p->left==NULL){
				p->left=temp;
				cout<<"\n"<<data<<" Inserted into Tree";
				return;
			}
			else
				p=p->left;
		else
			if(p->right==NULL){
				p->right=temp;
				cout<<"\n"<<data<<" Inserted into Tree";
				return;
				
			}
			else
				p=p->right;
	}
}
void Tree::passInorderRecursive(){
	if(root==NULL){
		cout<<"\nTree is Empty!";
		return;
	}
	cout<<"\n";
	traverseInorderRecursive(root);
}
void Tree::traverseInorderRecursive(Node *p){
	if(p!=NULL){
		traverseInorderRecursive(p->left);
		cout<<p->data<<" ";
		traverseInorderRecursive(p->right);
	}
	return;
}
int main(){
	Tree container;
	container.insert(12);
	container.insert(13);
	container.insert(14);
	container.insert(15);
	container.insert(16);
	container.insert(17);
	container.passInorderRecursive();
	return 0;
}












