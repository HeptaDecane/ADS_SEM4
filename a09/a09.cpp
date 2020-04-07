
#include"sets.cpp"


int main(){
	Set<int> a;
	a.print();
	a.add(5);
	a.add(6);
	a.add(7);
	a.print();
	a.remove(6);
	a.print();
	a.add(10);
	a.print();
	cout<<"\n"<<a.contains(10);
	cout<<"\n"<<a.contains(7);
	cout<<"\n"<<a.contains(5);
	cout<<"\n"<<a.contains(6);
	cout<<"\n"<<a.contains(8);
	cout<<"\n"<<a.size();
	return 0;
}
