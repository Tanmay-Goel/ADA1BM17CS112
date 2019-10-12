#include <iostream>
#include <time.h>
using namespace std;

int max(int a, int b) { return (a > b) ? a : b; } 
  
void knapSack(int W, int wt[], int val[], int n) 
{ 
    int i, j; 
    int K[n + 1][W + 1]; 
  
    for (i = 0; i <= n; i++) { 
        for (j = 0; j <= W; j++) { 
            if (i == 0 || j == 0) 
                K[i][j] = 0; 
            else if (wt[i - 1] <= j) 
                K[i][j] = max(val[i-1] + K[i-1][j-wt[i-1]], K[i-1][j]); 
            else
                K[i][j] = K[i-1][j]; 
        } 
    } 
  
    int res = K[n][W];  
    cout<<"Optimal Value: "<<res<<endl;   
	cout<<"Weights: "; 
    j = W; 
    for (i = n; i > 0 && res > 0; i--) { 
          
        if (res == K[i-1][j])  
            continue;         
        else { 
  
            printf("%d ", wt[i-1]); 
              
            res = res-val[i-1]; 
            j=j-wt[i-1]; 
        } 
    }
    cout<<endl;  
} 
   
int main() 
{ 
	clock_t start, end;
	int val[10],wt[10],W,i,n;
	cout<<"Enter no. of items: ";
	cin>>n;
	cout<<"\nEnter weight and value of items: ";
	for(i=0;i<n;i++)
		cin>>wt[i]>>val[i];
	 
	cout<<"\nEnter capacity: ";
	cin>>W;
	start=clock();
	knapSack(W, wt, val, n); 
	end=clock();
	float exe=float(end-start)/CLOCKS_PER_SEC;
	cout<<"\nTime in sec: "<<exe<<endl;
	return 0; 
} 
/*

Enter no. of items: 4

Enter weight and value of items: 2 12
1 10
3 20
2 15

Enter capacity: 5
Optimal Value: 37
Weights: 2 1 2 

Time in sec: 6e-05

*/