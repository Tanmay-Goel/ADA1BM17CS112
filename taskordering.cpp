#include<iostream>
using namespace std;
using namespace std::chrono;
int toposort(int adj[][10], int visited[], int n)
{
    int count=0;
    while(count<n){
        int i,j,k=0;
        for (i=0;i<n;i++) {
            for(j=0;j<n;j++){
                if(adj[j][i]==0 && visited[i]==0){
                    k++;
                    if(k==n){
                      visited[i]=1;
                      cout<<i<<" ";
                      count++;
                }   }
            }
        }
        if(count<n)
            return 0;
        else
            return 1;
        
    }
}

int main()
{
    int adj[10][10], visited[10]={0},n,i,j,f;
    cout<<"Enter no. of tasks: ";
    cin>>n;
    cout<<"\nEnter adj matrix: "<<endl;
    for(i=0;i<n;i++){
      for(j=0;j<n;j++){
        cin>>adj[i][j];
      }
    }
    
    auto start = high_resolution_clock::now();   
    f=toposort(adj,visited,n);
    if(!f)
      cout<<"Cyclic Dependancies exists";
    auto stop = high_resolution_clock::now();
	std::chrono::duration<double, std::milli> fp_ms = stop - start;
	cout<<"\ntime in milliseconds: "<<fp_ms.count()<<endl;
}