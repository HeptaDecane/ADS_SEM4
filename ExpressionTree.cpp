#include<bits/stdc++.h>
using namespace std;
#define TAB 8

/***************************************************************************************************/

int precedence(char c){
	if(c=='*'||c=='/')
		return 2;
	else if(c=='+'||c=='-')
		return 1;
	else
	
		return 0;
}
bool isOperator(char c){
	if(c=='*'||c=='/'||c=='+'||c=='-')
		return true;
	else
		return false;
}

/***************************************************************************************************/

string infixToPostfix(string infix){
	stack<char> stack;
	stack.push('(');
	infix+=')';
	string postfix;
	for(int i=0;i<infix.length();i++){
		if( (infix[i]>='a' && infix[i]<='z') || (infix[i]>='A' && infix[i]<='Z') )
			postfix+=infix[i];
		else if(infix[i]=='(')
			stack.push('(');
		else if(isOperator(infix[i])==true){
			while( precedence(infix[i]) <= precedence(stack.top()) ){
				postfix+=stack.top();
				stack.pop();
			}
			stack.push(infix[i]);
		}
		else if(infix[i]==')'){
			while(stack.top()!='('){
				postfix+=stack.top();
				stack.pop();
			}
			if(stack.top()=='(')
				stack.pop();
		}
		else
			return "\0";
	}
	if(!stack.empty())
		return "\0";
	else
		return postfix;
}

/***************************************************************************************************/

class Node{
private:
	char value;
	Node *left;
	Node *right;
public:
	Node(char value){
		this->value=value;
		left=NULL;
		right=NULL;
	}
	friend class Tree;
};

/***************************************************************************************************/

class Tree{
private:
	Node *root;
	float evaluate(Node*);
public:
	Tree();
	void construct(string);
	float callEvaluate();
	void callDisplay2D();
	void display2D(Node*,int);
};
Tree::Tree(){
	root=NULL;
}
void Tree::construct(string postfix){
	stack<Node*> stack;
	Node *p,*q;
	for(int i=0;i<postfix.length();i++){
		if(isOperator(postfix[i])==false){
			root=new Node(postfix[i]);
			stack.push(root);
		}
		else{
			root=new Node(postfix[i]);
			
			p=stack.top();
			stack.pop();
			q=stack.top();
			stack.pop();
			
			root->right=p;
			root->left=q;
			
			stack.push(root);
		}
	}
	root=stack.top();
	stack.pop();
}
float Tree::callEvaluate(){
	return(evaluate(root));
}
float Tree::evaluate(Node *root){
	float leftValue,rightValue,temp;
	if(root==NULL)
		return 0;
	if(root->left==NULL&&root->right==NULL){
		cout<<"\nEnter the Value for "<<root->value<<": ";
		cin>>temp;
		return temp;
	}
	leftValue=evaluate(root->left);
	rightValue=evaluate(root->right);
	
	if(root->value=='+')	return leftValue+rightValue;
	if(root->value=='-')	return leftValue-rightValue;
	if(root->value=='*')	return leftValue*rightValue;
	if(root->value=='/')	return leftValue/rightValue;
}
void Tree::callDisplay2D(){
	if(root==NULL){
		cout<<"ROOT->NULL";
		return;
	}
	display2D(root,0);
}
//Works as Reverse Inorder
void Tree::display2D(Node *p,int space){
	if(p==NULL)
		return;
	space+=TAB;	
	display2D(p->right,space);
	
	cout<<"\n";
	for(int i=TAB;i<space;i++)cout<<" ";
	cout<<p->value<<"\n";
	
	display2D(p->left,space);
}

/***************************************************************************************************/

int main(){
    string infix;
    cout<<"\nEnter Infix Expression: ";
    cin>>infix;
    cout<<"\nPostfix Expression: ";
    string postfix=infixToPostfix(infix); 
    cout<<postfix<<"\n";
    
    Tree expression;
    expression.construct(postfix);
    
    cout<<"\nExpression Tree: ";
    expression.callDisplay2D();
    
    float value=expression.callEvaluate();
    cout<<"\n"<<infix<<" = "<<value<<"\n";
    return 0;
}
