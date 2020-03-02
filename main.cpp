#include<bits/stdc++.h>
#include"a07.cpp"
using namespace std;

int main(){
	Table container;
	Column c0(")",0,"int","0");//131
	Column c1("3",0,"int","0");//21
	Column c2("=",0,"int","0");//31
	Column c3(",",0,"int","0");//4
	Column c4("7",0,"int","0");//5
	Column c5("H",0,"int","0");//2
	Column c6("=",0,"int","0");
	Column c7("!",0,"int","0");
	Column c8("G",0,"int","0");
	container.insertWithReplacement(c0);
	container.insertWithReplacement(c1);
	container.insertWithReplacement(c2);
	container.insertWithReplacement(c3);
	container.insertWithReplacement(c4);
	container.print();
	cout<<"\n";
	container.insertWithReplacement(c5);
	container.print();
	cout<<"\n";
	return 0;
}
