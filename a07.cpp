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
	void read();
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
void Column::read(){
	cout<<"\nIdentifier: ";
	cin>>identifier;
	cout<<"\nScope: ";
	cin>>scope;
	cout<<"\nType: ";
	cin>>type;
	cout<<"\nValue: ";
	cin>>value;
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
	int h(string);
	void print();
	bool isFull(){return n==MAX-1;}
	bool insertWithoutReplacement(Column);
	bool insertWithReplacement(Column);
	int searchEntry(string,int);
	int getEmptyLocation(int);
	int locateStart(int);
	bool isBlank(int);
	bool deleteEntry(string,int);
	void menu();
};

void Table::print(){
	//cout<<"\nScope\tType\tIdentifier\tVlaue\t\tChain";
	for(int i=0;i<MAX;i++){
		cout<<"\n"<<i;
		cout<<"\t"<<row[i].scope;
		cout<<"\t"<<row[i].type;
		cout<<"\t"<<row[i].identifier;
		cout<<"\t"<<row[i].value;
		cout<<"\t"<<row[i].chain;
	}
}

int Table::getEmptyLocation(int id){
	int count=0;
	for(int i=id;count<MAX;i=(i+1)%MAX){
		if(row[i].identifier.length()==0)
			return i;
	}
}

bool Table::isBlank(int i){
	return (row[i].identifier.length()==0 and row[i].type.length()==0);
}

int Table::h(string identifier){
	if(identifier.length()==0)
		return -1;
	int sum=0;
	for(int i=0;i<identifier.length();i++)
		sum=sum+identifier[i];
	return sum%MAX;
}

int Table::locateStart(int id){
	int count=0,i;
	for(i=id;count<MAX;i=(i+1)%MAX){
		if(id==h(row[i].identifier) and row[i].identifier.length()!=0)
			break;
		count++;
	}
	bool found=false;
	while(found==false){
		found=true;
		for(int j=0;j<MAX;j++){
			if(row[j].chain==i){
				i=j;
				found=false;
			}
		}
	}
	return i;
}

bool Table::insertWithoutReplacement(Column data){
	if(this->isFull())
		return false;
	int count=0;
	int id=h(data.identifier);
	int loc=getEmptyLocation(id);
	for(int i=id;count<MAX;i=(i+1)%MAX){
		if(id==h(row[i].identifier)){
			int j=i;
			while(row[j].chain!=-1)
				j=row[j].chain;
			row[j].chain=loc;
			break;
		}
		count++;
	}
	row[loc]=data;
	n++;
	return true;
}

bool Table::insertWithReplacement(Column data){
	if(this->isFull())
		return false;
	int id=h(data.identifier);
	int loc=getEmptyLocation(id);
	if(h(row[id].identifier)==id||loc==id){
		insertWithoutReplacement(data);
		return true;
	}
	Column temp=row[id];
	int i=0;
	for(i=0;i<MAX;i++){
		if(id==row[i].chain)
			break;
	}
	row[i].chain=loc;
	row[loc]=temp;
	Column deAllocate;
	deAllocate.type="DEL";
	row[id]=deAllocate;
	n--;
	insertWithoutReplacement(data);
	return true;
}

int Table::searchEntry(string identifier,int scope){
	int id=h(identifier);
	if(isBlank(id)){
		return -1;
	}
	int i=locateStart(id);
	while(true){
		if(row[i].identifier==identifier&&row[i].scope==scope){
			row[i].print();
			return i;
		}
		if(row[i].chain==-1)
			break;
		else
			i=row[i].chain;
	}
	return -1;
}

bool Table::deleteEntry(string identifier,int scope){
	int id=h(identifier);
	if(isBlank(id)){
		return false;
	}
	Column deAllocate;
	deAllocate.type="DEL";
	int start=locateStart(id);
	int i,j=-1;
	for(i=start;i!=-1;i=row[i].chain){
		if(row[i].identifier==identifier&&row[i].scope==scope)
			break;
		j=i;
	}
	if(i==-1){
		return false;
	}
	if(j==-1){
		row[i]=deAllocate;
		n--;
		return true;
	}
	row[j].chain=row[i].chain;
	row[i]=deAllocate;
	n--;
	return true;
}
void Table::menu(){
	cout<<"\n------------------------------------------------------";
	cout<<"\n           OPTION INDEX";
	cout<<"\nPress 1  : Declare Identifier";
	cout<<"\nPress 2  : Search Identifier";
	cout<<"\nPress 3  : Delete Identifier";
	cout<<"\nPress 4  : Modify Attributes";
	cout<<"\nPress 5  : Print Symbol Table";
	cout<<"\nPress 99 : Display Option Index";
	cout<<"\n------------------------------------------------------";
}
int main() {
	int replacement=0;
	while(replacement!=1 and replacement!=2){
		cout<<"\nChoose Insertion Method.";
		cout<<"\n1. With Replacement";
		cout<<"\n2. Without Replacement";
		cout<<"\nEnter Choice: ";
		cin>>replacement;
	}
	if (replacement==2)
		replacement=0;

	int choice;
	Table container;
	Column entry;
	string identifier,type,value;
	int scope,index;
	bool flag;

	container.menu();
	cout<<"\n\nEnter Choice: ";
	cin>>choice;

	while(choice){
		switch(choice){
		case 1:	entry.read();
				if(replacement)
					container.insertWithReplacement(entry);
				else
					container.insertWithoutReplacement(entry);
				break;

		case 2:	cout<<"\nEnter Identifier to Search: ";
				cin>>identifier;
				cout<<"\nEnter Scope: ";
				cin>>scope;
				index=container.searchEntry(identifier,scope);
				if(index!=-1)
					cout<<"\n"<<identifier<<" found at index: "<<index;
				else
					cout<<"\n"<<identifier<<" not Found!";
				break;

		case 3:	cout<<"\nEnter Identifier to Search: ";
				cin>>identifier;
				cout<<"\nEnter Scope: ";
				cin>>scope;
				flag=container.deleteEntry(identifier,scope);
				if(flag==true)
					cout<<"\n"<<identifier<<" Deleted Successfully!";
				else
					cout<<"\n"<<identifier<<" not Found!";
				break;

		case 5:	container.print();
				break;

		case 99: container.menu();
					break;

		default:cout<<"\nInvalid Choice! Please, Try Again.";
		}
		cout<<"\n\nEnter Choice: ";
		cin>>choice;
	}
	cout<<"\nEND...";
	return 0;
}
