//============================================================================
// Name        : a06.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <bits/stdc++.h>
using namespace std;
#define MAX 4

class Dictionary{
	string word;
	string meaning;
public:
	Dictionary();
	Dictionary(string,string);
	void print();
	void read();
	friend class Hash;
};
Dictionary::Dictionary(){
	this->word[0]='\0';
	this->meaning[0]='\0';
}
Dictionary::Dictionary(string word,string meaning){
	this->word=word;
	this->meaning=meaning;
}
void Dictionary::print(){
	cout<<"\n"<<word<<": "<<meaning;
}
void Dictionary::read(){
	cout<<"\nEnter Word: ";
	cin>>word;
	cout<<"\nEnter Meaning: ";
	cin.ignore();
	getline(cin,meaning);
}
class Hash{
	Dictionary table[MAX];
public:;
	int hashFunction(Dictionary);
	bool insertWithReplacement(Dictionary);
	bool insertWithoutReplacement(Dictionary);
	void printTable();
	int searchEntry(Dictionary);
	bool deleteEntry(Dictionary);
};
int Hash::hashFunction(Dictionary entry){
	int location=0;
	for(int i=0;i<entry.word.length();i++){
		location=location+entry.word[i];
	}
	location=location%MAX;
	return location;
}
bool Hash::insertWithoutReplacement(Dictionary entry){
	int index=hashFunction(entry);
	int count=0;
	if(!table[index].word.length()){
		table[index]=entry;
		cout<<"\nInserted!";
		return true;
	}
	for(int i=index;;i++){
		if(i==MAX)	i=0;
		if(!table[i].word.length()){
			table[i]=entry;
			cout<<"\nInserted!";
			return true;
		}
		count++;
		if(count>=MAX)	break;
	}
	cout<<"\nTable Full!";
	return false;
}
void Hash::printTable(){
	cout<<"\nindex\tword\tmeaning";
	for(int i=0;i<MAX;i++){
		cout<<"\n"<<i<<"\t"<<table[i].word<<"\t"<<table[i].meaning;
	}
}
int main() {
	Dictionary obj1("Hello","1");
	Dictionary obj2("Hello","2");
	Dictionary obj3("Hello","3");
	Dictionary obj4("Hello","4");
	Dictionary obj5("Hello","5");
	Dictionary obj6("Hello","6");
	Hash obj;
	obj.insertWithoutReplacement(obj1);
	obj.insertWithoutReplacement(obj2);
	obj.insertWithoutReplacement(obj3);
	obj.insertWithoutReplacement(obj4);
	obj.insertWithoutReplacement(obj5);
	obj.insertWithoutReplacement(obj6);

	obj.printTable();
	return 0;
}
