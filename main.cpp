#include<bits/stdc++.h>
#include"a07.cpp"
using namespace std;

int main(){
	Table container;
	Column c0("(",0,"int","0");
	Column c1(")",0,"int","0");
	Column c2(",",0,"int","0");
	Column c3("3",0,"int","0");
	Column c4("@",0,"int","0");
	Column c5("Y",0,"int","0");
	Column c6("=",0,"int","0");
	Column c7("!",0,"int","0");
	Column c8("G",0,"int","0");
	container.insertWithoutReplacement(c0);
	container.insertWithoutReplacement(c1);
	container.insertWithoutReplacement(c2);
	container.insertWithoutReplacement(c3);
	container.insertWithoutReplacement(c4);
	container.insertWithoutReplacement(c5);
	container.insertWithoutReplacement(c6);
	container.insertWithoutReplacement(c7);
	container.print();
	container.deleteEntry(")",0);
	container.insertWithoutReplacement(c8);
	cout<<"\n\n";
	container.print();
	container.searchEntry("=",0);
	return 0;
}
