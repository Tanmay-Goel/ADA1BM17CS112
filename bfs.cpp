#include<iostream>
using namespace std;
using namespace std::chrono;

int queue[10];
int front=0,rear=-1;

void enqueue(int a)
{
 queue[++rear]=a;   
}

void dequeue()
{
    cout<<queue[front++]<<" ";
}

void bfs(int k, int visited[], int adj[][10], int n, int count)
{
    int f,i;
    visited[k]=1;
    if(count==1)
      enqueue(k);
    while(front<=rear){
        f=queue[front];
        dequeue();
        for(i=0;i<n;i++){
            if(adj[f][i]==1 && visited[i]==0){
                enqueue(i);
                visited[i]=1;
                count++;
            }    
        }            
        
      if(count<n){
          f=queue[front];
          bfs(f,visited,adj,n,count);
      }  
    }
}

int main()
{
    int n,i,j,count=1;
	int visited[10]={0};
	int adj[10][10];
	cout<<"Enter no. of vertices: ";
	cin>>n;
	cout<<"\nEnter Adjecency matrix for connected graph: ";
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			cin>>adj[i][j];
			
    cout<<"\n BFS traversal: ";
    auto start = high_resolution_clock::now();
    bfs(0,visited,adj,n,count);
    auto stop = high_resolution_clock::now();
	std::chrono::duration<double, std::milli> fp_ms = stop - start;
	cout<<"\ntime in milliseconds: "<<fp_ms.count()<<endl;
    
}
