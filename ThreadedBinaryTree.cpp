#include "bits/stdc++.h"
using namespace std;

class Node{
private:
	int data;
	Node *left,*right;
	bool leftTag,rightTag;	
	/*
		tag=false => Thread
		tag=true => Child
	*/
public:
	Node(int);
	friend class ThreadedBinaryTree;
};
Node::Node(int data){
	this->data=data;
	left=NULL;
	right=NULL;
	leftTag=false;
	rightTag=false;
}

class ThreadedBinaryTree{
private:
	Node *root;
public:
	ThreadedBinaryTree();
	void insert(int);
	void callInorder();
	void inorder(Node*);
	void deleteNode(int);
	void noBranch(Node*,Node*);
	void oneBranch(Node*,Node*);
	void twoBranch(Node*,Node*);
	Node* inPred(Node*);
	Node* inSucc(Node*);
};
ThreadedBinaryTree::ThreadedBinaryTree(){
	root=new Node(0);
	root->left=root;
	root->right=root;
}
void ThreadedBinaryTree::insert(int data){
	Node *temp=new Node(data);
	if(root->left==root&&root->right==root){
		root->leftTag=true;
		root->left=temp;
		
		temp->left=root;
		temp->right=root;
		cout<<"\n"<<data<<" Set as Root";
		return;
	}
	Node *p=root->left;
	bool currentLeft,currentRight;
	while(true){
		if(temp->data<p->data){
			if(p->leftTag==false){
				currentLeft=true;
				currentRight=false;
				break;
			}
			else
				p=p->left;
		}
		else if(temp->data>p->data){
			if(p->rightTag==false){
				currentLeft=false;
				currentRight=true;
				break;
			}
			else
				p=p->right;
		}
		else{
			cout<<"\n"<<data<<" Already Exists in Tree!";
			return;
		}
	}
	if(currentLeft){
		temp->leftTag=p->leftTag;
		temp->left=p->left;
		
		p->leftTag=true;
		p->left=temp;
		
		temp->rightTag=false;
		temp->right=p;
	}
	else if(currentRight){
		temp->rightTag=p->rightTag;
		temp->right=p->right;
		
		p->rightTag=true;
		p->right=temp;
		
		temp->leftTag=false;
		temp->left=p;
	}
	else
		cout<<"\nError While insertion";
	cout<<"\n"<<data<<" Inserted into Tree";
}
void ThreadedBinaryTree::callInorder(){
	if(root->right==root&&root->left==root){
		cout<<"\nTree is Empty!";
		return;
	}
	inorder(root->left);
}
void ThreadedBinaryTree::inorder(Node* p){
	if(p==root)
		return;
	if(p->leftTag)
		inorder(p->left);
		
	cout<<p->data<<" ";
	
	if(p->rightTag)
		inorder(p->right);
}
Node* ThreadedBinaryTree::inPred(Node *p){
	if(p->leftTag==false)
		return p->left;
	p=p->left;
	while(p->rightTag!=false)
		p=p->right;
	return p;
}
Node* ThreadedBinaryTree::inSucc(Node *p){
	if(p->rightTag==false)
		return p->right;
	p=p->right;
	while(p->leftTag!=false)
		p=p->left;
	return p;
}
void ThreadedBinaryTree::noBranch(Node *p,Node *q){
	if(p==root->left){
		root->left=root;
		root->leftTag=false;
	}
	else if(q==p->left){
		p->leftTag=false;
		p->left=q->left;
	}
	else{
		p->rightTag=false;
		p->right=q->right;
	}
	delete q;
	return;
}
void ThreadedBinaryTree::oneBranch(Node *p,Node *q){
	Node *next;
	if(q->leftTag)
		next=q->left;
	else
		next=q->right;
	if(p=NULL)
		root=next;
	else if(q==p->left)
		p->left=next;
	else
		p->right=next;
	Node *succ=inSucc(q);
	Node *pred=inPred(q);
	if(q->leftTag)
		pred->right=succ;
	else if(q->rightTag)
		succ->left=pred;
	delete q;
}
void ThreadedBinaryTree::twoBranch(Node *p,Node *q){
	Node *parsucc=q;
	Node *succ=p->right;
	while(succ->leftTag!=false){
		parsucc=succ;
		succ=succ->left;
	}
	q->data=succ->data;
	if(succ->leftTag==false&&succ->rightTag==false)
		noBranch(parsucc,succ);
	else
		oneBranch(parsucc,succ);
}
void ThreadedBinaryTree::deleteNode(int data){
	Node *q=root->left;
	Node *p=NULL;
	bool found=false;
	while(true){
		if(q->data==data){
			found=true;
			break;
		}
		p=q;
		if(data<q->data){
			if(q->leftTag)
				q=q->left;
			else
				break;
		}
		else{
			if(q->rightTag)
				q=q->right;
			else
				break;
		}
	}
	if(!found){
		cout<<"\n"<<data<<" Not Present in Tree";
		return;
	}
	if(q->leftTag==true && q->rightTag==true)
		twoBranch(p,q);
	else if(q->leftTag==true)
		oneBranch(p,q);
	else if(q->rightTag==true)
		oneBranch(p,q);
	else
		noBranch(p,q);
	return;
}
int main(){
	int elements[]={50,20,70,60,80,10,30,5,15,25,35};
	int n=sizeof(elements)/sizeof(int);
	ThreadedBinaryTree container;
	
	for(int i=0;i<n;i++)container.insert(elements[i]);
	cout<<"\nInorder: ";
	container.callInorder();
	cout<<"\n";
	container.deleteNode(80);
	cout<<"\nInorder: ";
	container.callInorder();
	cout<<"\n";
	return 0;
}


















/*
//Threaded Binary Tree

public class Main {

	static Node root;
	static Node current;
	static boolean directionRight = false;
	static boolean directionLeft = false;

	public static void main(String[] args) {

		// 1 . Create the root node which is gonna hold the checking conditions

		root = new Node(999);

		root.lBit = 0;
		root.rBit = 1;
		root.left = root.right = root;

		// 2 . Condition to add new roots!

		createNode(35);
		createNode(10);
		createNode(22);
		createNode(50);
		createNode(11);

		// 3 . PreOrder, InOrder and PostOrder printing

		System.out.println("Output for recursive inOrder!");
		inOrderRecursive(root.left);
		System.out.println();

		System.out.println("Output for recursive inOrder!");
		inOrder();
		System.out.println();

	}

	public static void inOrder() {

		current = root.left;

		while (current.lBit == 1) {

			current = current.left;

		}
		
		while(current != root){
			
			System.out.print(" -> " + current.data);
			current = nextInOrder(current);
			
		}

	}

	public static Node nextInOrder(Node next) {
		
		if(next.rBit == 0){
			
			return next.right;
			
		}
		
		next = next.right;
		
		while(next.lBit == 1){
			
			next = next.left;
			
		}
		
		return next;
		
	}

	public static void inOrderRecursive(Node temp) {

		if (temp != root) {

			if (temp.lBit != 0)
				inOrderRecursive(temp.left);

			System.out.print(temp.data + " -> ");

			if (temp.rBit != 0)
				inOrderRecursive(temp.right);

		}

	}

	public static void createNode(int data) {

		Node node = new Node(data);

		if (root.left == root && root.right == root) {

			node.lBit = root.lBit;
			node.left = root.left;
			root.left = node;
			root.lBit = 1;
			node.rBit = 0;
			node.right = root;

		} else {

			current = root.left;

			while (true) {

				if (node.data < current.data) {

					if (current.lBit == 0) {

						directionLeft = true;
						directionRight = false;
						break;

					} else {

						current = current.left;

					}

				} else {

					if (current.rBit == 0) {

						directionLeft = false;
						directionRight = true;
						break;

					} else {

						current = current.right;

					}

				}

			}

			if (directionLeft) {

				node.lBit = current.lBit;
				node.left = current.left;
				current.left = node;
				current.lBit = 1;
				node.rBit = 0;
				node.right = current;

			} else if (directionRight) {

				node.rBit = current.rBit;
				node.right = current.right;
				current.right = node;
				current.rBit = 1;
				node.lBit = 0;
				node.left = current;

			} else {

				System.out.println("Program is a fail!");

			}

		}

		System.out.println("Nodes added!");

	}

}

class Node {

	int data;

	Node left;
	Node right;

	int lBit;
	int rBit;

	Node(int data) {

		this.data = data;

	}

}
*/
