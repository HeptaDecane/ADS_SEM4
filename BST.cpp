#include "bits/stdc++.h"
using namespace std;

class Node{
	int data;
	Node *left;
	Node *right;
public:
	Node(int);
	friend class BST;
	friend class Stack;
};

Node::Node(int data){
	this->data=data;
	left=NULL;
	right=NULL;
}

class BST{
private:
	Node *root;
	void traverseInorderRecursive(Node *);
	void traversePreorderRecursive(Node *);
	void traversePostorderRecursive(Node *);
	bool compare(Node*,Node*);
	void eraseRecursive(Node*);
	void printInternalNodes(Node*);
	void printLeafNodes(Node*);
	Node* setEqual(Node*,Node*);
	Node* deleteNode(Node*,int);

public:
	BST();
	void insert(int);
	void callInorderRecursive();
	void callPreorderRecursive();
	void callPostorderRecursive();
	void inorderIterative();
	void preorderIterative();
	void postorderIterative();
	bool isEqual(BST);
	Node *search(int);
	void callErase();
	void callPrintInternalNodes();
	void callPrintLeafNodes();
	void operator =(BST&);
	void callDeleteNode(int);
	void menu();
};


BST::BST(){
	root=NULL;
}


void BST::insert(int data){
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


void BST::callInorderRecursive(){
	if(root==NULL){
		cout<<"\nBST is Empty!";
		return;
	}
	cout<<"\n";
	traverseInorderRecursive(root);
}
void BST::traverseInorderRecursive(Node *p){
	if(p!=NULL){
		traverseInorderRecursive(p->left);
		cout<<p->data<<" ";
		traverseInorderRecursive(p->right);
	}
	return;
}


void BST::inorderIterative(){
	if(root==NULL){
		cout<<"\nBST is Empty!";
		return;
	}
	cout<<"\n";
	Node *p=root;
	stack<Node*> stack;
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


void BST::callPreorderRecursive(){
	if(root==NULL){
		cout<<"\nBST is Empty!";
		return;
	}
	cout<<"\n";
	traversePreorderRecursive(root);
}
void BST::traversePreorderRecursive(Node *p){
	if(p!=NULL){
		cout<<p->data<<" ";
		traversePreorderRecursive(p->left);
		traversePreorderRecursive(p->right);
	}
	return;
}


void BST::preorderIterative(){
	if(root==NULL){
		cout<<"\nBST is Empty!";
		return;
	}
	cout<<"\n";
	Node *p=root;
	stack<Node*> stack;
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


void BST::callPostorderRecursive(){
	if(root==NULL){
		cout<<"\nBST is Empty!";
		return;
	}
	cout<<"\n";
	traversePostorderRecursive(root);
}
void BST::traversePostorderRecursive(Node *p){
	if(p!=NULL){
		traversePostorderRecursive(p->left);
		traversePostorderRecursive(p->right);
		cout<<p->data<<" ";
	}
}


void BST::postorderIterative(){
	if(root==NULL){
		cout<<"\nBST is Empty!";
		return;
	}
	Node *p=root;
	stack<Node*> stack;
	while(true){
		while(p!=NULL){
			stack.push(p);
			stack.push(p);
			p=p->left;
		}
		if(stack.empty())
			return;
		p=stack.top();
		stack.pop();
		if(stack.top()==p)
			p=p->right;
		else{
			cout<<p->data<<" ";
			p=NULL;
		}
	}
}


Node* BST::search(int data){
	if(this->root==NULL){
		cout<<"\n"<<data<<" Not Found";
		return NULL;
	}
	Node *p=this->root;
	while(p!=NULL){
		if(data>p->data)
			p=p->right;
		else if(data<p->data)
			p=p->left;
		else{
			cout<<"\n"<<data<<" Found";
			return p;
		}
	}
	cout<<"\n"<<data<<" Not Found";
	return NULL;
}


bool BST::isEqual(BST T){
	if (compare(this->root,T.root))
		return true;
	else
		return false;

}
bool BST::compare(Node*p,Node*q){
	if(p==NULL&&q==NULL)
		return true;
	else if(p==NULL&&q!=NULL)
		return false;
	else if(p!=NULL&&q==NULL)
		return false;
	else{
		if(p->data==q->data&&compare(p->left,q->left)&&compare(p->right,q->right))
			return true;
		else
			return false;
	}
}


void BST::callErase(){
	if(root==NULL)
		return;
	else
		eraseRecursive(root);
		root=NULL;
}
void BST::eraseRecursive(Node *p){
	if(p==NULL)
		return;;
	eraseRecursive(p->left);
	eraseRecursive(p->right);
	p->left=NULL;
	p->right=NULL;
	delete p->right;
	delete p->left;
	return;
}


void BST::callPrintLeafNodes(){
	printLeafNodes(this->root);
}
void BST::printLeafNodes(Node *p){
	if(p==NULL)
		return;
	if(p->left==NULL&&p->right==NULL){
		cout<<p->data<<" ";
		return;
	}
	printLeafNodes(p->left);
	printLeafNodes(p->right);
}


void BST::callPrintInternalNodes(){
	printInternalNodes(this->root);
}
void BST::printInternalNodes(Node *p){
	if(p==NULL)
		return;
	if(p->left!=NULL||p->right!=NULL)
		cout<<p->data<<" ";
	printInternalNodes(p->left);
	printInternalNodes(p->right);
}


void BST::operator =(BST &t){
	this->root=setEqual(t.root,this->root);
}
Node* BST::setEqual(Node *original,Node *copy){
	if(original==NULL)
		copy=NULL;
	else{
		copy=new Node(0);
		copy->data=original->data;
		copy->left=setEqual(original->left,copy->left);
		copy->right=setEqual(original->right,copy->right);
	}
	return copy;
}

void BST::callDeleteNode(int data){
	root=deleteNode(root,data);
}
Node* BST::deleteNode(Node *p,int data){
	if(p==NULL){
		cout<<"\n"<<data<<" Not Found";
		return NULL;
	}
	if(data<p->data){
		p->left=deleteNode(p->left,data);
		return p;
	}
	else if(data>p->data){
		p->right=deleteNode(p->right,data);
		return p;
	}
	//Node to be Deleted is Reached (data==p->data)
	cout<<"\n"<<data<<" Deleted";
	//If p has NO or only ONE child
	if(p->left==NULL){
		Node *temp=p->right;
		delete p;
		return temp;
	}
	else if(p->right==NULL){
		Node *temp=p->left;
		delete p;
		return p;
	}
	//If p has two children
	else{
		Node *ancestor=p->right;
		Node *successor=p->right;
		while(successor->left!=NULL){
			ancestor=successor;
			successor=successor->right;
		}
		p->data=successor->data;
		ancestor->left=successor->right;
		delete successor;
		return p;
	}
}

void BST::menu(){
	cout<<"\n------------------------------------------------------";
	cout<<"\n           OPTION INDEX";
	cout<<"\nPress 1  : Enter Data into BST";
	cout<<"\nPress 2  : In-order Recursive";
	cout<<"\nPress 3  : Pre-order Recursive";
	cout<<"\nPress 4  : Post-order Recursive";
	cout<<"\nPress 5  : In-order Iterative";
	cout<<"\nPress 6  : Pre-order Iterative";
	cout<<"\nPress 7  : Post-order Iterative";
	cout<<"\nPress 8  : Search Node";
	cout<<"\nPress 9  : Delete a Node from BST";
	cout<<"\nPress 10  : Compare BST 1 and BST 2";
	cout<<"\nPress 11 : Erase All Nodes Of Selected BST";
	cout<<"\nPress 12 : Print Leaf Nodes";
	cout<<"\nPress 13 : Print Internal Nodes";
	cout<<"\nPress 14 : Assign Other BST to Selected BST";
	cout<<"\nPress 15 : Select [BST 1 | BST 2]";
	cout<<"\nPress 99 : Display Option Index";
	cout<<"\n------------------------------------------------------";
}
/**************************************************************************************************/

int main(){
	BST t1,t2;
	BST *t=&t1;
	int choice=1;
	int data;
	int selected=0;
	t->menu();
	while(choice){
		switch(choice){
			case 1:	cout<<"\nEnter Data Element(BST 1): ";
					cin>>data;
					t->insert(data);
					break;
			case 2: cout<<"\nInorder Traversal(Recursive) : ";
					t->callInorderRecursive();
					break;
			case 3: cout<<"\nPreorder Traversal(Recursive) : ";
					t->callPreorderRecursive();
					break;
			case 4: cout<<"\nPostorder Traversal(Recursive) : ";
					t->callPostorderRecursive();
					break;
			case 5: cout<<"\nInorder Traversal(Iterative) : ";
					t->inorderIterative();
					break;
			case 6: cout<<"\nPreorder Traversal(Iterative) : ";
					t->preorderIterative();
					break;
			case 7: cout<<"\nPostorder Traversal(Iterative) : ";
					t->postorderIterative();
					break;
			case 8: cout<<"\nEnter Data to be Searched: ";
					cin>>data;
					t->search(data);
					break;
			case 9: cout<<"\nEnter The Node to be Deleted: ";
					cin>>data;
					t->callDeleteNode(data);
					break;
			case 10: if(selected)
						if(t->isEqual(t1))
							cout<<"\n BST 1 and BST 2 are identical";
						else
							cout<<"\n BST 1 and BST 2 are NOT identical";
					else
						if(t->isEqual(t2))
							cout<<"\nBST 1 and BST 2 are identical";
						else
							cout<<"\nBST 1 and BST 2 are NOT identical";
					break;
			case 11:cout<<"\nBST Erased!";
					t->callErase();
					break;
			case 12:cout<<"\nLeaf Nodes: ";
					t->callPrintLeafNodes();
					break;
			case 13:cout<<"\nInternal Nodes: ";
					t->callPrintInternalNodes();
					break;
			case 14:if(selected){
						t2=t1;
						cout<<"Assigned BST 1 to BST 2";
					}
					else{
						t1=t2;
						cout<<"Assigned BST 2 to BST 1";
					}
					break;
			case 15:cout<<"\nPress: 0 for BST 1\nPress: 1 for BST 2\nEnter Choice: ";
					cin>>selected;
					if(selected)
						t=&t2;
					else
						t=&t1;
					break;
			case 99:t->menu();
					break;
			default:cout<<"\nEnter Valid Choice";
		}
		cout<<"\nEnter Choice [99-Option Index | 0-Exit]: ";
		cin>>choice;
	}
	return 0;
}
//44 1 17 1 88 1 32 1 28 1 29 1 65 1 97 1 54 1 82 1 76 1 80 1 78
