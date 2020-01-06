#include "bits/stdc++.h"
using namespace std;
#define MAX 50

class Node{
private:
	char keyword[MAX];
	string meaning;
	Node *left;
	Node *right;
public:
	Node();
	Node(char[],string);
	friend class Tree;
};
Node::Node(){
	this->keyword[0]='\0';
	this->meaning[0]='\0';
	left=NULL;
	right=NULL;
}
Node::Node(char keyword[MAX],string meaning){
	strcpy(this->keyword,keyword);
	this->meaning=meaning;
	left=NULL;
	right=NULL;
}


class Tree{
private:
	Node *root;
	void inorder(Node*);
	void reverseInorder(Node*);
	Node* setEqual(Node*,Node*);
public:
	Tree();
	void insert(char[],string);
	void callInorder();
	void callReverseInorder();
	void updateMeaning(char[],string);
	void operator =(Tree&);
	void callDeleteNode(char[]);
	Node *deleteNode(Node*,char[]);
	void menu();
};
Tree::Tree(){
	root=NULL;
}
void Tree::insert(char keyword[MAX],string meaning){
	Node *temp=new Node(keyword,meaning);
	if(root==NULL){
		root=temp;
		cout<<"\n"<<keyword<<" Added to Dictionary!";
		return;
	}
	Node *p=root;
	while(true){
		if(strcmp(temp->keyword,p->keyword)<0)
			if(p->left==NULL){
				p->left=temp;
				cout<<"\n"<<keyword<<" Added to Dictionary!";
				return;
			}
			else
				p=p->left;
		else if(strcmp(temp->keyword,p->keyword)>0)
			if(p->right==NULL){
				p->right=temp;
				cout<<"\n"<<keyword<<" Added to Dictionary!";
				return;				
			}
			else
				p=p->right;
		else{
			cout<<"\n"<<keyword<<" Exists in Dictionary, Try Edit!";
			return;
		}
	}
}
void Tree::callInorder(){
	cout<<"\n      DICTIONARY\n**********************";
	if(root==NULL){
		cout<<"\nDictionary is Empty!";
		return;
	}
	inorder(this->root);
	return;
}
void Tree::inorder(Node *p){
	if(p!=NULL){
		inorder(p->left);
		cout<<"\n=> "<<p->keyword<<": "<<p->meaning<<"\n";
		inorder(p->right);
	}
	return;
}
void Tree::callReverseInorder(){
	cout<<"\n      DICTIONARY\n**********************";
	if(root==NULL){
		cout<<"\nDictionary is Empty!";
		return;
	}
	reverseInorder(this->root);
	return;
}
void Tree::reverseInorder(Node *p){
	if(p!=NULL){
		reverseInorder(p->right);
		cout<<"\n=> "<<p->keyword<<": "<<p->meaning<<"\n";
		reverseInorder(p->left);
	}
	return;
}
void Tree::updateMeaning(char keyword[MAX],string meaning){
	if(root==NULL){
		cout<<"\nDictionary is Empty!";
		return;
	}
	Node *p=this->root;
	while(p!=NULL){
		if(strcmp(keyword,p->keyword)==0){
			p->meaning=meaning;
			cout<<"\n"<<keyword<<" Successfully Updated!";
			return;
		}
		else if(strcmp(keyword,p->keyword)<0)
			p=p->left;
		else
			p=p->right;
	}
	cout<<"\n"<<keyword<<" Doesn't Exists in Dictionary!\nTry Insert.";
}
void Tree::operator =(Tree &t){
	this->root=setEqual(t.root,this->root);
}
Node* Tree::setEqual(Node *original,Node *copy){
	if(original==NULL)
		copy=NULL;
	else{
		copy=new Node;
		strcpy(copy->keyword,original->keyword);
		copy->meaning=original->meaning;
		copy->left=setEqual(original->left,copy->left);
		copy->right=setEqual(original->right,copy->right);
	}
	return copy;
}
void Tree::callDeleteNode(char keyword[MAX]){
	root=deleteNode(root,keyword);
}
Node* Tree::deleteNode(Node *p,char keyword[MAX]){
	if(p==NULL){
		cout<<"\n"<<keyword<<" Not Found";
		return NULL;
	}
	if(strcmp(keyword,p->keyword)<0){
		p->left=deleteNode(p->left,keyword);
		return p;
	}
	else if(strcmp(keyword,p->keyword)>0){
		p->right=deleteNode(p->right,keyword);
		return p;
	}
	//Node to be Deleted is Reached (data==p->data)
	cout<<"\n"<<keyword<<" Deleted";
	//If p has NO or only ONE child
	if(p->left==NULL){
		Node *temp=p->right;
		delete p;
		return temp;
	}
	else if(p->right==NULL){
		Node *temp=p->left;
		delete p;
		return temp;
	}
	//If p has two children
	else{
		Node *ancestor=p->right;
		Node *successor=p->right;
		while(successor->left!=NULL){
			ancestor=successor;
			successor=successor->left;
		}
		if(ancestor==successor)
			p->right=NULL;
		strcpy(p->keyword,successor->keyword);
		p->meaning=successor->meaning;
		ancestor->left=successor->right;
		delete successor;
		return p;
	}
}
void Tree::menu(){
	cout<<"\n------------------------------------------------------";
	cout<<"\n           OPTION INDEX";
	cout<<"\nPress 1  : Add Keyword into Dictionary";
	cout<<"\nPress 2  : Display Dictionary (Ascending)";
	cout<<"\nPress 3  : Display Dictionary (Descending)";
	cout<<"\nPress 4  : Create Copy of Main Dictionary";
	cout<<"\nPress 5  : Display Copied Dictionary (Ascending)";
	cout<<"\nPress 6  : Update Meaning of Existing Keyword";
	cout<<"\nPress 7  : Delete Existing Keyword";
	cout<<"\nPress 99 : Display Option Index";
	cout<<"\n------------------------------------------------------";
}

int main(){
	Tree dictionary;
	Tree cc;
	int choice;
	char keyword[MAX];
	string meaning;
	cc.menu();
	while(choice){
		cout<<"\nEnter Choice [99-Option Index | 0-Exit]: ";
		cin>>choice;
		switch(choice){
			case 1:	cout<<"\nEnter Keyword: ";
					cin>>keyword;
					cout<<"\nProvide Meaning: ";
					cin.ignore();
					getline(cin,meaning);
					dictionary.insert(keyword,meaning);
					break;
			case 2: dictionary.callInorder();
					break;
			case 3: dictionary.callReverseInorder();
					break;
			case 4: cout<<"\nMain Tree Copied!";
					cc=dictionary;
					break;
			case 5: cc.callInorder();
					break;
			case 6: cout<<"\nEnter Keyword: ";
					cin>>keyword;
					cout<<"\nProvide New Meaning: ";
					cin.ignore();
					getline(cin,meaning);
					dictionary.updateMeaning(keyword,meaning);
					break;
			case 7: cout<<"\nEnter The Keyword to be Deleted: ";
					cin>>keyword;
					dictionary.callDeleteNode(keyword);
					break;
			case 99:cc.menu();
					break;
			default:cout<<"\nEnter Valid Choice";
		}
	}
	return 0;
}
