#include<iostream>
#include<chrono>
using namespace std;
using namespace std::chrono;

void dfs(int v, int visited[], int adj[][10], int n)
{
	visited[v]=1;
	for(int i=1;i<=n;i++)
	{
		if(adj[v-1][i-1]==1 && visited[i]==0)
		{
			cout<<v<<" -> "<<i<<endl;
			dfs(i,visited,adj,n);
		}
	}
}

int main()
{
	int n,i,j;
	int visited[10]={0};
	int adj[10][10];
	cout<<"Enter no. of vertices: ";
	cin>>n;
	cout<<"\nEnter Adjecency matrix: ";
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			cin>>adj[i][j];
			
	auto start = high_resolution_clock::now();
	
	dfs(1,visited,adj,n);
	
	for(i=1;i<=n;i++)
		if(visited[i]==0)
			dfs(i,visited,adj,n);
			
	auto stop = high_resolution_clock::now();
	std::chrono::duration<double, std::milli> fp_ms = stop - start;
	cout<<"\ntime in milliseconds: "<<fp_ms.count()<<endl;
}
