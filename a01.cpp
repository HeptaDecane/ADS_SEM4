#include<bits/stdc++.h>
#include"Stack.cpp"		//paste Stack.cpp from repository into the Directory of this src file
#define MAX 256
using namespace std;

/**************************************************************************************************/
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
/**************************************************************************************************/


class Tree{
private:
	Node *root;
	void traverseInorderRecursive(Node *);
	void traversePreorderRecursive(Node *);
	void traversePostorderRecursive(Node *);
	void mirror(Node *);
	bool compare(Node*,Node*);
	void eraseRecursive(Node*);
	void printInternalNodes(Node*);
	void printLeafNodes(Node*);
	Node* setEqual(Node*,Node*);

public:
	Tree();
	void insert(int);
	void insertBst(int);
	void callInorderRecursive();
	void callPreorderRecursive();
	void callPostorderRecursive();
	void inorderIterative();
	void preorderIterative();
	void postorderIterative();
	void callMirror();
	bool isEqual(Tree);
	void callErase();
	void callPrintInternalNodes();
	void callPrintLeafNodes();
	void operator =(Tree&);
	void menu();
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


void Tree::insertBst(int data){
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


void Tree::callInorderRecursive(){
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
	Stack<Node*> stack;
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


void Tree::callPreorderRecursive(){
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
	Stack<Node*> stack;
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


void Tree::callPostorderRecursive(){
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
	Stack<Node*> stack1,stack2;
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


void Tree::callMirror(){
	if(root==NULL)
		return;
	mirror(root);
}
void Tree::mirror(Node *p){
	if(p==NULL)
		return;
	Node *temp;
	mirror(p->left);
	mirror(p->right);
	temp=p->left;
	p->left=p->right;
	p->right=temp;
	return;
}


bool Tree::isEqual(Tree T){
	if (compare(this->root,T.root))
		return true;
	else
		return false;

}
bool Tree::compare(Node*p,Node*q){
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


void Tree::callErase(){
	if(root==NULL)
		return;
	else
		eraseRecursive(root);
		root=NULL;
}
void Tree::eraseRecursive(Node *p){
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


void Tree::callPrintLeafNodes(){
	printLeafNodes(this->root);
}
void Tree::printLeafNodes(Node *p){
	if(p==NULL)
		return;
	if(p->left==NULL&&p->right==NULL){
		cout<<p->data<<" ";
		return;
	}
	printLeafNodes(p->left);
	printLeafNodes(p->right);
}


void Tree::callPrintInternalNodes(){
	printInternalNodes(this->root);
}
void Tree::printInternalNodes(Node *p){
	if(p==NULL)
		return;
	if(p->left!=NULL||p->right!=NULL)
		cout<<p->data<<" ";
	printInternalNodes(p->left);
	printInternalNodes(p->right);
}


void Tree::operator =(Tree &t){
	this->root=setEqual(t.root,this->root);
}
Node* Tree::setEqual(Node *original,Node *copy){
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


void Tree::menu(){
	cout<<"\n------------------------------------------------------";
	cout<<"\n           OPTION INDEX";
	cout<<"\nPress 1  : Enter Data into Tree";
	cout<<"\nPress 2  : In-order Recursive";
	cout<<"\nPress 3  : Pre-order Recursive";
	cout<<"\nPress 4  : Post-order Recursive";
	cout<<"\nPress 5  : In-order Iterative";
	cout<<"\nPress 6  : Pre-order Iterative";
	cout<<"\nPress 7  : Post-order Iterative";
	cout<<"\nPress 8  : Mirror the Existing Tree";
	cout<<"\nPress 9  : Compare Tree 1 and Tree 2";
	cout<<"\nPress 10 : Erase All Nodes Of Selected Tree";
	cout<<"\nPress 11 : Print Leaf Nodes";
	cout<<"\nPress 12 : Print Internal Nodes";
	cout<<"\nPress 13 : Assign Other Tree to Selected Tree";
	cout<<"\nPress 14 : Select [Tree 1 | Tree 2]";
	cout<<"\nPress 99 : Display Option Index";
	cout<<"\n------------------------------------------------------";
}
/**************************************************************************************************/

int main(){
	Tree t1,t2;
	Tree *t=&t1;
	int choice=1;
	int data;
	int bst=0;
	int selected=0;
	cout<<"\nPress 0 : Simple Binary Tree\nPress 1: Binary Search Tree\nEnter Choice: ";
	cin>>bst;
	while(choice){
		switch(choice){
			case 1:	cout<<"\nEnter Data Element(Tree 1): ";
					cin>>data;
					if(bst)
						t->insertBst(data);
					else
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
			case 8: cout<<"\nMirrored The Existing tree!";
					break;
			case 9: if(selected)
						if(t->isEqual(t1))
							cout<<"\n Tree 1 and Tree 2 are identical";
						else
							cout<<"\n Tree 1 and Tree 2 are NOT identical";
					else
						if(t->isEqual(t2))
							cout<<"\nTree 1 and Tree 2 are identical";
						else
							cout<<"\nTree 1 and Tree 2 are NOT identical";
					break;
			case 10:cout<<"\nTree Erased!";
					break;
			case 11:cout<<"\nLeaf Nodes: ";
					t->callPrintLeafNodes();
					break;
			case 12:cout<<"\nInternal Nodes: ";
					t->callPrintInternalNodes();
					break;
			case 13:if(selected){
						t2=t1;
						cout<<"Assigned Tree 1 to Tree 2";
					}
					else{
						t1=t2;
						cout<<"Assigned Tree 2 to Tree 1";
					}
					break;
			case 14:cout<<"\nPress: 0 for Tree 1\nPress: 1 for Tree 2\nEnter Choice: ";
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
