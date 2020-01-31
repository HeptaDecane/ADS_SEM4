#include<bits/stdc++.h>
using namespace std;

class Graph{
	int **matrix;
	int n;
public:
	Graph(int);
	void printMatrix();
	void setMatrix();
	void addEdge(int,int,int);
	void primsMST(int);
	void printMST(int*,int);
	int minKey(int*,bool*);
	void menu();
};

Graph::Graph(int n){
	this->n=n;
	
	matrix=new int *[n];
	
	for(int i=0;i<n;i++)
		matrix[i]=new int[n];
	
}

void Graph::setMatrix(){
	matrix[0][1]=matrix[1][0]=2;		//	0  2  0  6  0
	matrix[0][3]=matrix[3][0]=6;		//	2  0  3  8  5 
	matrix[1][2]=matrix[2][1]=3;		//	0  3  0  0  7 
	matrix[1][3]=matrix[3][1]=8;		//	6  8  0  0  9 
	matrix[1][4]=matrix[4][1]=5;		//	0  5  7  9  0
	matrix[2][4]=matrix[4][2]=7;		//1 0 1 2 1 0 3 6 1 1 2 3 1 1 3 8 1 1 4 5 1 2 4 7 1 3 4 9
	matrix[3][4]=matrix[4][3]=9;
}

void Graph::addEdge(int u,int v,int weight){
	matrix[u][v]=weight;
	matrix[v][u]=weight;
}

void Graph::printMatrix(){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<matrix[i][j]<<" ";
		}
		cout<<"\n";
	}
}

/**************************************************************************************************/

void Graph::primsMST(int start=0){
	int *edge=new int[n];
	int *key=new int[n];
	bool *mstSet=new bool[n];
	
	for(int i=0;i<n;i++){
		edge[i]=-1;
		key[i]=INT_MAX;
		mstSet[i]=false;
	}
	key[start]=0;
	edge[start]=-1;
	
	for(int i=0;i<n;i++){
		int current=minKey(key,mstSet);
		mstSet[current]=true;
		for(int j=0;j<n;j++){
			if(matrix[current][j]&&mstSet[j]==false&&matrix[current][j]<key[j]){
				edge[j]=current;
				key[j]=matrix[current][j];
			}
		}
	}
	this->printMST(edge,start);
}

int Graph::minKey(int *key,bool *mstSet){
	int min=INT_MAX;
	int index;
	for(int i=0;i<n;i++){
		if(mstSet[i]==false&&key[i]<min){
			min=key[i];
			index=i;
		}
	}
	return index;
}

void Graph::printMST(int *edge,int start){
	int sum=0;
	cout<<"\nEdges \t Weight\n";  
	for(int i=0;i<n;i++){
		if(i==start)	continue;
		cout<<edge[i]<<" - "<<i<<"\t "<<matrix[i][edge[i]]<<"\n";
		sum=sum+matrix[i][edge[i]];
	}
	cout<<"Optimal Connection Cost: "<<sum<<"\n";
}

/**************************************************************************************************/

void Graph::menu(){
	cout<<"\n--------------------------OPTION INDEX--------------------------";
	cout<<"\nPress 1: Add/Update Connection Charges (Add Edge) ";
	cout<<"\nPress 2: Display Adjacency Matrix";
	cout<<"\nPress 3: Find Optimal Connection and cost";
	cout<<"\n----------------------------------------------------------------";
}

int main(){
	int n,u,v;
	int choice;
	int cost;
	Graph *network;
	cout<<"\nEnter Total No. of Offices: ";
	cin>>n;
	network=new Graph(n);
	cout<<"\nAdded Offices with label 0 to "<<n-1<<" in the Graph!\n";
	network->menu();
	cout<<"\nEnter Choice [0-Exit]: ";
	cin>>choice;
	while(choice){
		switch(choice){
			case 1:	cout<<"\nEnter 1st Office Label: ";cin>>u;
					cout<<"\nEnter 2nd Office Label: ";cin>>v;
					cout<<"\nEnter Connection Cost: ";cin>>cost;
					network->addEdge(u,v,cost);
					cout<<"\nConnected Labels: "<<u<<" - "<<v<<"\n";
					break;
			case 2: cout<<"\nAdjacency Matrix: \n";
					network->printMatrix();
					break;
			case 3: cout<<"Enter Starting Office Label: ";cin>>u;
					cout<<"\nOptimal Connection: \n";
					network->primsMST(u);
					break;
			default:cout<<"\nInvalid Choice, Please Try Again!";
		}
		network->menu();
		cout<<"\nEnter Choice [0-Exit]: ";
		cin>>choice;
	}	
	return 0;
}
