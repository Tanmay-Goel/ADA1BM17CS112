#include<iostream>
#include<chrono>
using namespace std;
using namespace std::chrono;

void merge(int b[], int p, int c[], int q, int a[])
{
	int i=0,j=0,k=0;
	while(i<p && j<q)
	{
		if(b[i]<=c[i])
		{
			a[k]=b[i];
			i++;
		}
		else
		{
			a[k]=c[j];
			j++;
		}
		k++;
	}
	if(i==p)
	{
		for(int t=j;t<q;t++)
		{
			a[k]=c[t];
			k++;
		}
	}
	else if(j==q)
	{
		for(int t=i;t<p;t++)
		{
			a[k]=b[t];
			k++;
		}
	}
}

void mergesort(int a[], int n)
{
	int x=n/2,y=n/2;
	if(n%2==1)
		y++;
	int b[x], c[y],i,j;
	if(n>1)
	{
		for(i=0;i<x;i++)
			b[i]=a[i];
		for(j=0;j<y;j++,i++)
			c[j]=a[i];
		mergesort(b,x);
		mergesort(c,y);
		merge(b,x,c,y,a);
	}
}
int main()
{
	int n, a[10],i;
	cout<<"Enter size: ";
	cin>>n;
	cout<<"Enter array: ";
	for(i=0;i<n;i++)
		cin>>a[i];
		
	auto start = high_resolution_clock::now();
	mergesort(a,n);
	auto stop = high_resolution_clock::now();
	
	cout<<"sorted array: ";
	for(i=0;i<n;i++)
		cout<<a[i]<<" ";
	std::chrono::duration<double, std::milli> fp_ms = stop - start;
	
	cout<<"\ntime in milliseconds: "<<fp_ms.count()<<endl; 
	
	return 0;
 }