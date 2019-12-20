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
void Tree::inorderIterative(){
	if(root==NULL){
		cout<<"\nTree is Empty!";
		return;		
	}
	cout<<"\n";
	Node *p=root;
	stack<Node *> stack;
	while(p!=NULL||!stack.empty()){
		while(p!=NULL){
			stack.push(p);
			p=p->left;
		}
		p=stack.top();
		stack.pop();
		cout<<p->data<<" ";
		p=p->right;
	}

}
void Tree::passPreorderRecursive(){
	if(root==NULL){
		cout<<"\nTree is Empty!";
		return;
	}
	cout<<"\n";
	traversePreorderRecursive(root);
}
void Tree::traversePreorderRecursive(Node *p){
	if(p!=NULL){
		cout<<p->data<<" ";
		traversePreorderRecursive(p->left);
		traversePreorderRecursive(p->right);
	}
	return;
}
void Tree::preorderIterative(){
	if(root==NULL){
		cout<<"\nTree is Empty!";
		return;		
	}
	cout<<"\n";
	Node *p=root;
	stack<Node *> stack;
	while(p!=NULL||!stack.empty()){
		while(p!=NULL){
			cout<<p->data<<" ";
			stack.push(p);
			p=p->left;
		}
		p=stack.top();
		stack.pop();
		p=p->right;
	}
}
void Tree::passPostorderRecursive(){
	if(root==NULL){
		cout<<"\nTree is Empty!";
		return;
	}
	cout<<"\n";
	traversePostorderRecursive(root);
}
void Tree::traversePostorderRecursive(Node *p){
	if(p!=NULL){
		traversePostorderRecursive(p->left);
		traversePostorderRecursive(p->right);
		cout<<p->data<<" ";
	}
}
void Tree::postorderIterative(){
	if(root==NULL){
		cout<<"\nTree is Empty!";
		return;		
	}
	cout<<"\n";
	stack<Node *> stack1,stack2;
	Node *p=root;
	stack1.push(p);
	while(!stack1.empty()){
		p=stack1.top();
		stack1.pop();
		stack2.push(p);
		if(p->left!=NULL)
			stack1.push(p->left);
		if(p->right!=NULL)
			stack1.push(p->right);
	}
	while(!stack2.empty()){
		p=stack2.top();
		stack2.pop();
		cout<<p->data<<" ";
	}
}
int main(){
	Tree container;
	container.insert(1);
	container.insert(2);
	container.insert(3);
	container.insert(4);
	container.insert(5);
	container.insert(6);
	container.insert(7);
	//container.insert(26);
	container.passInorderRecursive();
	container.inorderIterative();
	container.passPreorderRecursive();
	container.preorderIterative();
	container.passPostorderRecursive();
	container.postorderIterative();
	return 0;
}












