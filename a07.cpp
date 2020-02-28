#include<bits/stdc++.h>
using namespace std;
#define MAX 10

class Column{
	string identifier;
	int scope;
	string type;
	string value;
public:
	int chain;
	Column();
	Column(string,int,string,string);
	void print();
	friend class Table;
};
Column::Column(){
	identifier[0]='\0';
	scope=0;
	type[0]='\0';
	value[0]='\0';
	chain=-1;
}
Column::Column(string identifier,int scope,string type,string value){
	this->identifier=identifier;
	this->scope=scope;
	this->type=type;
	this->value=value;
	chain=-1;
}
void Column::print(){
	cout<<"\n\t| Identifier |  "<<identifier;
	if(scope==0)
		cout<<"\n\t| Scope      |  Global";
	else
		cout<<"\n\t| Scope      |  "<<scope;
	cout<<"\n\t| Type       |  "<<type;
	cout<<"\n\t| Value      |  "<<value;
}




class Table{
	Column row[MAX];
	int n;
public:
	Table(){n=0;}
	int hashFunction(string);
	void print();
	bool isFull(){n==MAX-1;}
	bool insertWithoutReplacement(Column);
	bool insertWithReplacement(Column);
}

void Table::print(){
	cout<<"\nScope\tType\tIdentifier\tVlaue\t\tChain";
	for(int i=0;i<MAX;i++){
		cout<<"\n"<<row[i].scope;
		cout<<"\t"<<row[i].type;
		cout<<"\t"<<row[i].identifier;
		cout<<"\t"<<row[i].value;
		cout<<"\t\t"<<row[i].chain;
	}
}


int Table::hashFunction(string identifier){
	int sum=0;
	for(int i=0;i<identifier.length();i++)
		sum=sum+identifier[i];
	return sum%MAX;
}

bool Table::insertWithoutReplacement(Column data){
	if(this->isFull())
		return false;
	int id=hashFunction(data.identifier);
	if(row[id].identifier.length()==0){
		row[id]=data;
		return true;
	}
	if(hash==hashFunction(row[id].identifier)){
		int i=id;
		while(row[i].chain!=-1){
			i=row[i]
		}
	}
}
