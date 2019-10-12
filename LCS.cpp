#include<iostream> 
#include<cstdlib>
#include<cstring>
#include<time.h>
using namespace std; 
  
void findlcs( char *X, char *Y, int m, int n ) 
{ 
   int L[m+1][n+1]; 
  
   for (int i=0; i<=m; i++) 
   { 
     for (int j=0; j<=n; j++) 
     { 
       if (i == 0 || j == 0) 
         L[i][j] = 0; 
       else if (X[i-1] == Y[j-1]) 
         L[i][j] = L[i-1][j-1] + 1; 
       else
         L[i][j] = max(L[i-1][j], L[i][j-1]); 
     } 
   } 
  
   int index = L[m][n]; 
  
   char lcs[index+1]; 
   lcs[index] = '\0'; 
  
   int i = m, j = n; 
   while (i > 0 && j > 0) 
   { 
      
      if (X[i-1] == Y[j-1]) 
      { 
          lcs[index-1] = X[i-1]; 
          i--; j--; index--;      
      } 
  
      else if (L[i-1][j] > L[i][j-1]) 
         i--; 
      else	
         j--; 
   } 
  
   cout << "\nLCS of " << X << " and " << Y << " is " << lcs<<endl; 
} 
  
int main() 
{ 
	clock_t start, end;
	char X[10],Y[10];
	cout<<"Enter Sequences: "<<endl; 
	cin>>X>>Y; 
	int m = strlen(X); 
	int n = strlen(Y);
	start=clock();
	findlcs(X, Y, m, n);
	end=clock();
	float exe=float(end-start)/CLOCKS_PER_SEC;
	cout<<"\nTime in sec: "<<exe<<endl;
 	return 0; 
} 

/* 
 Enter Sequences: 
abcbdab
bdcaba

LCS of abcbdab and bdcaba is bdab

Time in sec: 3e-05

 */
