#include<bits/stdc++.h>
using namespace std;


template<class T>
class QueueNode{
	T data;
	QueueNode<T> *link;
public:
	QueueNode();
	QueueNode(T);
	
	template <class U> 
	friend class Queue;
};

template<typename T>
QueueNode<T>::QueueNode(){
	link=NULL;
}
template<typename T>
QueueNode<T>::QueueNode(T data){
	this->data=data;
	link=NULL;
}

/**************************************************************************************************/

template<class T>
class Queue{
	QueueNode<T>* start;
	QueueNode<T>* end;
public:
	Queue();
	void push(T);
	void pop();
	T front();
	bool empty();
};

template<typename T>
Queue<T>::Queue(){
	start=NULL;
	end=NULL;
}

template<typename T>
void Queue<T>::push(T data){
	QueueNode<T>* temp=new QueueNode<T>(data);
	if(start==NULL){
		start=temp;
		end=temp;
		return;
	}
	end->link=temp;
	end=end->link;
	return;
}

template<typename T>
void Queue<T>::pop(){
	QueueNode<T> *temp;
	if(start==NULL)	return;
	else if(start==end){
		temp=start;
		start=NULL;
		end=NULL;
		delete temp;
		return;
	}
	temp=start;
	start=start->link;
	temp->link=NULL;
	delete temp;
	return;
}

template<typename T>
T Queue<T>::front(){
	return start->data;
}

template<typename T>
bool Queue<T>::empty(){
	return start==NULL;
}
