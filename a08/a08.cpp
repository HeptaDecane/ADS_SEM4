#include<bits/stdc++.h>
#include"BST.cpp"
using namespace std;

class Optimal{
private:
	int n;
	int *key,*frequency;
	int **cost;
	int **root;
public:
	Optimal(int);
	void read();
	void printTables();
	int sum(int,int);
	void generateTables();
	void insert(int,int,BST&);
};
Optimal::Optimal(int n){
	this->n=n;
	key=new int[n+1];
	frequency=new int[n+1];
	
	cost=new int*[n+1];
	root=new int*[n+1];
	
	for(int i=0;i<=n;i++){
		cost[i]=new int[n+1];
		root[i]=new int[n+1];
	}
}
void Optimal::printTables(){
	cout<<"\nk(i):\t";
	for(int i=1;i<=n;i++)
		cout<<key[i]<<"\t";
		
	cout<<"\nf(i):\t";
	for(int i=1;i<=n;i++)
		cout<<frequency[i]<<"\t";
	cout<<"\n";
	
	cout<<"\nCost Matrix:\n";
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
			cout<<cost[i][j]<<"\t";
		cout<<"\n";
	}
	
	cout<<"\nRoot Matrix:\n";
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
				cout<<root[i][j]<<"\t";
		cout<<"\n";
	}
	
	cout<<"\nOptimal Cost: "<<cost[1][n]<<"\n";
}

void Optimal::read(){
	cout<<"\nEnter Key <space> Frequency:\n";
	for(int i=1;i<=n;i++)
		cin>>key[i]>>frequency[i];
	cout<<"\n";
}

int Optimal::sum(int i,int j){
	int result=0;
	for(int k=i;k<=j;k++)
		result=result+frequency[k];
	return result;
}

void Optimal::generateTables(){
	for(int i=1;i<=n;i++){
		cost[i][i]=frequency[i];
		root[i][i]=i;
	}
		
	for(int l=2;l<=n;l++){
		for(int i=1;i<=n-l+1;i++){
			int j=i+l-1;
			cost[i][j]=INT_MAX;
			for(int r=i;r<=j;r++){
				int w1,w2,c;
				
				(i>r-1)? w1=0 : w1=cost[i][r-1];	
				
				(r+1>j)? w2=0 : w2=cost[r+1][j];
						
				c=sum(i,j)+w1+w2;
				
				if(c<cost[i][j]){
					cost[i][j]=c;
					root[i][j]=r;
				}
			}	
		}
	}
}

void Optimal::insert(int i,int j,BST& container){
	if(i>j)
		return;
		
	int index=root[i][j];
	container.insert(key[index]);
	this->insert(i,index-1,container);
	this->insert(index+1,j,container);
}

int main(){
	int n;
	cout<<"Enter No. of Keys: ";
	cin>>n;
	
	Optimal optimize(n);
	BST container;
	
	optimize.read();
	optimize.generateTables();
	optimize.printTables();
	optimize.insert(1,n,container);
	
	cout<<"\nTree:\n";
	container.print();
	
	return 0;
}







