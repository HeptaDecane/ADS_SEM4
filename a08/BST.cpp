#include<bits/stdc++.h>
using namespace std;

class Node{
private:
	int data;
	Node *left;
	Node *right;
public:
	Node(int);
	friend class BST;
};

Node::Node(int data){
	this->data=data;
	left=NULL;
	right=NULL;
}

class BST{
private:
	Node *root;
	void display2D(string,Node*,bool);
public:
	BST();
	bool insert(int);
	void print();
};

BST::BST(){
	root=NULL;
}

bool BST::insert(int data){
	Node *temp=new Node(data);
	if(root==NULL){
		root=temp;
		return true;
	}
	Node *p=root;
	while(true){
		if(temp->data < p->data){
			if(p->left == NULL){
				p->left=temp;
				return true;
			}
			p=p->left;
		}
		else if(temp->data > p->data){
			if(p->right == NULL){
				p->right=temp;
				return true;
			}
			p=p->right;
		}
		else
			return false;
	}
}

void BST::print(){
	if(root==NULL)
		return;
	display2D("",root,false);
}
//Works as Reverse Inorder
void BST::display2D(string prefix,Node *p,bool isLeft){
	if(p==NULL)
		return;
	cout<<prefix;
	cout<<(isLeft ? "├──" : "└──");
	cout<<p->data<<"\n";
	display2D(prefix+(isLeft ? "│   " : "    "),p->right,true);
	display2D(prefix+(isLeft ? "│   " : "    "),p->left,false);
}




// ├── └── │




