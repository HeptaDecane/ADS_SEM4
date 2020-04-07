#include<iostream>
using namespace std;
#include"sets.h"

template<typename T>
SetNode<T>::SetNode(){
	link = NULL;
}

template<typename T>
SetNode<T>::SetNode(T data){
	this->data=data;
	link=NULL;
}

template<typename T>
Set<T>::Set(){
	start=NULL;
}

template<typename T>
void Set<T>::print(){
	if(start == NULL){
		cout<<"\n{ # }";
		return;
	}
	SetNode<T> *p = NULL;
	cout<<"\n{ ";
	for(p=start; p!=NULL; p=p->link)
		cout<<p->data<<", ";
	cout<<"\b\b }";
	return;
}

template<typename T>
bool Set<T>::contains(T data){
	SetNode<T> *p;
	for(p=start; p!=NULL; p=p->link){
		if(p->data==data)
			return true;
	}
	return false;
}

template<typename T>
void Set<T>::add(T data){
	if(contains(data)==true)
		return;
	
	SetNode<T> *temp=new SetNode<T>(data);
	temp->link=start;
	start=temp;
	return;
}

template<typename T>
bool Set<T>::remove(T data){
	SetNode<T> *p=NULL;
	SetNode<T> *q=NULL;
	for(p=start; p!=NULL; p=p->link){
		if(p->data==data)
			break;
		q=p;
	}
	
	if(p==NULL)
		return false;
	
	if(q==NULL)
		start=start->link;
	else
		q->link=p->link;
	
	delete p;
	return true;
}

template<typename T>
int Set<T>::size(){
	SetNode<T> *p=NULL;
	int count=0;
	for(p=start; p!=NULL; p=p->link, count++);
	return count;
}




















