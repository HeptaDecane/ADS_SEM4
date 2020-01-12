#include<bits/stdc++.h>
using namespace std;

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
	Node *root;
	
}

/***************************************************************************************************/

int main(){
    string infix;
    cout<<"\nEnter Infix Expression: ";
    cin>>infix;
    cout<<"\nPostfix Expression: ";
    string post=infixToPostfix(infix); 
    cout<<post<<"\n";
    return 0;
}
