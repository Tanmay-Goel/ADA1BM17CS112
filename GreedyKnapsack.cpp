#include <iostream>
using namespace std;

void fracKnap(int w[],int v[],int n,int c){
	double p[n],x[n];
	for(int i=0;i<n;i++){
		p[i]=double(v[i])/w[i];
		x[i]=0;
	}
	
	double k=0,max,frac;
	int s,cnt=0;
	while(k<c && cnt<n){
		max=0;
		for(int i=0;i<n;i++){
			if(max<=p[i] && x[i]==0){
				max=p[i];s=i;
			}
		}
		if(w[s]+k<=c){
			k+=w[s];
			x[s]=1;
		}
		else{
			frac=(c-k)/w[s];
			x[s]=frac;
			k+=(c-k);
		}
		cnt++;
	}
	
	double q=0;
	cout<<"\nItems : ";
	for(int i=0;i<n;i++){
		if(x[i]>0){
			if(x[i]!=1)
				cout<<x[i]<<" of ";
			cout<<"item "<<i+1<<"\t";
			q+=x[i]*v[i];
		}
	}
	cout<<"\nProfit = "<<q<<endl;
}

int main(){
	int n,c;
	cout<<"Enter no. of items : ";
	cin>>n;
	int w[n],v[n];
	cout<<"Enter weight and value of items :\n";
	for(int i=0;i<n;i++)
		cin>>w[i]>>v[i];
	cout<<"Enter capacity : ";
	cin>>c;
	fracKnap(w,v,n,c);
}
/*
Enter no. of items : 5
Enter weight and value of items :
10 20
20 30
30 66
40 40
50 60
Enter capacity : 100

Items : item 1	item 2	item 3	0.8 of item 5	
Profit = 164
*/