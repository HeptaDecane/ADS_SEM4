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
public:
	Tree();
	void insert(char[],string);
	void callInorder();
	void callReverseInorder();
	void updateMeaning(char[],string);
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
		else if(strcmp(keyword,p->keyword)>0)
			p=p->right;
		else
			p=p->left;
	}
}
int main(){
	Tree dictionary;
	dictionary.insert("helo","Arter");
	dictionary.insert("aelo","Arsdter");
	dictionary.callInorder();
	dictionary.callReverseInorder();
	return 0;
}







