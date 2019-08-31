#include<iostream>
#include<chrono>
using namespace std;
using namespace std::chrono;
int partition(int a[],int low,int high)
{
	int i, j;
	int pivot=a[low];
	i=low+1;
	j=high;
	while(1)
	{
		while(a[i]<=pivot && i<=high)
			i++;
		while(a[j]>pivot && j>=low)
			j--;
		if(i<j)
		{
		a[i]=a[i]+a[j];
			a[j]=a[i]-a[j];
			a[i]=a[i]-a[j];
		}
		else
		{
			a[low]=a[j];
			a[j]=pivot;
			return j;
		}
	}
}


void quicksort(int a[], int low, int high)
{
	if(low<high)
	{
		int pivot=partition(a, low, high);
		quicksort(a,low,pivot-1);
		quicksort(a,pivot+1,high);
	}
}

int main()
{
	int n, a[10],i,low,high;
	cout<<"Enter size: ";
	cin>>n;
	cout<<"Enter array: ";
	for(i=0;i<n;i++)
		cin>>a[i];
	
	low=0;
	high=n-1;
	
	auto start = high_resolution_clock::now();
	quicksort(a,low,high);
	auto stop = high_resolution_clock::now();
	
	cout<<"sorted array: ";
	for(i=0;i<n;i++)
		cout<<a[i]<<" ";
	std::chrono::duration<double, std::milli> fp_ms = stop - start;
	
	cout<<"\ntime in milliseconds: "<<fp_ms.count()<<endl; 
	
	return 0;
 }