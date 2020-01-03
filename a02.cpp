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
			case 7: cout<<"\nWork In Progress! ";
					break;
			case 99:cc.menu();
					break;
			default:cout<<"\nEnter Valid Choice";
		}
	}
	return 0;
}

/*
#include <iostream.h>
#include<conio.h>
#include <string.h>
#define MAX 10
class node
{
private:
 char keyword[MAX];
 char meaning[MAX];
 node *left;
 node *right;
public:
 node();
 node(char [],char []);
 friend class BST;
};
node::node()
{
 keyword[0] = '\0';
 meaning[0] = '\0';
 left = NULL;
 right = NULL;
}
node::node(char key[],char mean[])
{
 strcpy(keyword,key);
 strcpy(meaning,mean);
 left = NULL;
 right = NULL;
}
class BST
{
private:
 node *root;
 void inorder(node *root);
 void inorderrev(node *root);
 node * insert(node * root,node *);
 node* search(char key[]);
 node * remove(node *root,char key[]);
public:
 BST();
 void update(char []);
 void recInsert(char [] , char[]);
 node *search(node *, char []);
 void find(char key[]);
 void printAscending();
 void printDescending();
 void removeword(char val[]);
};
BST::BST()
{
 root = NULL;
}
void BST::recInsert(char k[], char m[])
{
 node *newnd=new node(k,m);
 root = insert(root,newnd);
}
node * BST::insert(node * root,node *newnd)
{
 if(root==NULL)
  root = newnd;
 else if (strcmp(newnd->keyword, root->keyword)<0)
  root->left=insert(root->left,newnd);
 else if (strcmp(newnd->keyword, root->keyword)>0)
  root->right=insert(root->right,newnd);
 else
  cout<<"\nDuplicate value";
 return root;
}

node * BST::remove(node *root,char key[])
{
 if(root==NULL)
  return NULL;
 else if (strcmp(key,root->keyword)<0)
  root->left=remove(root->left,key);
 else if (strcmp(key,root->keyword)>0)
  root->right=remove(root->right,key);
 else
 {
  if(root->right!=NULL)
  {
   node *in_succ = root->right;
   while(in_succ->left!=NULL)
   {
    in_succ = in_succ->left;
   }

   strcpy(root->keyword,in_succ->keyword);
   strcpy(root->meaning,in_succ->meaning);
   root->right=remove(root->right,in_succ->keyword);
  }
  else
   return root->left;
 }
 return root;
}
void BST::removeword(char val[])
{
 remove(root,val);
}
void BST::update(char k[])
{
 node *tempnd;
 tempnd = search(k);
 if(tempnd == NULL)
  cout<<"\nWord not present for Update:";
 else
 {
  cout<<"\nEnter new meaning for this word";
  cin>>tempnd->meaning;
 }
}
 node *BST::search(char val[])
 {
 node *tempnd=root;
 tempnd=search(tempnd,val);
 return tempnd;
 }
 node *BST::search(node *tempnd, char k[])
 {
 if(tempnd!= NULL)
 {
  if(strcmp(k,tempnd->keyword)==0)
   return tempnd;
  else if(strcmp(k, tempnd->keyword)<0)
   search(tempnd->left, k);
  else
   search(tempnd->right, k);
 }//if
 else
  return NULL; //not found
}
void BST::find(char val[])
{
 node *tempnd;
 tempnd=search(val);
 if (tempnd == NULL)
 {
  cout<<endl<<"Not found\n";
 }
 else
 {
  cout<<endl<<"Found...";
  cout<<"\nMeaning is "<<tempnd->meaning;
 }
}//find
void BST::inorder(node *root)
{
 if(root!= NULL)
 {
  inorder(root->left);
  cout<<"\n"<<root->keyword<<":"<<root->meaning;
  inorder(root->right);
 }
}
void BST::inorderrev(node *root)
{
 if(root!= NULL)
 {
  inorderrev(root->right);
  cout<<"\n"<<root->keyword<<":"<<root->meaning;
  inorderrev(root->left);
 }
}
void BST::printAscending()
{
 inorder(root);
}
void BST::printDescending()
{
 inorderrev(root);
}
int menu()
{
 int choice;
 cout<<"\nD I C T I O N A R Y A P P L I C A T I O N";
 cout<<"\n\t1. Insert ";
 cout<<"\n\t2. Update ";
 cout<<"\n\t3. Delete ";
 cout<<"\n\t4. Print Ascending ";
 cout<<"\n\t5. Print Descending";
 cout<<"\n\t6. Find ";
 cout<<"\n\t7. Exit ";
 cout<<"\nEnter your Choice \t";
 cin>>choice;
 return choice;
}//menu

void main()
{
 BST t;
 char k[MAX],m[MAX];
 clrscr();
 char keyword[40];
 int n,choice;
 while(1)
 {
  choice=menu();;
  switch(choice)
  {
  case 1: cout<<"\nHow many values to insert";
   cin>>n;
   for(int i=0;i<n;i++)
   {
    cout<<"\nEnter new Keyword :";
    cin>>k;
    cout<<"\nEnter meaning of "<<keyword<<" : ";
    cin>>m;
    t.recInsert(k,m);
   }
   break;
  case 2: cout<<"\nEnter keyword to be found:";
   cin>>k;
   t.update(k);
   break;
  case 3: cout<<"Enter the keyword :";
   cin>>keyword;
   t.removeword(keyword);
   break;
  case 4: cout<<"\nPrint Dictionary in Ascending Order: ";
   t.printAscending();
   break;
  case 5: cout<<"\nPrint Dictionary in Descending Order: ";
   t.printDescending();
   break;
  case 6: cout<<"Enter the keyword :";
   cin>>keyword;
   t.find(keyword);
   break;
  case 7: cout <<"\nProgram ending....\n";
   getch();
   return;
  default: cout <<"\nEnter correct choice...\n";
  }//switch
 }//while
}//main
*/











