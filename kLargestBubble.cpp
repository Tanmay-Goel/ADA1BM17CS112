#include<iostream>
#include<chrono>
using namespace std;
using namespace std::chrono;
int main()
{
	int a[10], n, k, i,j,c=0,temp;
	bool swapped;
	cout<<"Enter size: ";
	cin>>n;
	cout<<"\nEnter array: ";
	for(i=0;i<n;i++)
		cin>>a[i];
	cout<<"\nEnter k: ";
	cin>>k;
	
	auto start = high_resolution_clock::now();
	
	if(k>0 && k<=n)
	{
		for(i=0;i<n-1;i++)
		{
			for(j=0;j<n-1-i;j++)
			{
				swapped=false;
				if(a[j+1]<a[j])
				{
					temp=a[j];
					a[j]=a[j+1];
					a[j+1]=temp;
					swapped=true;
				}
			}
			c++;
			if(c==k)
				break;
			if(swapped==false)
				break;
		}
		cout<<endl<<k<<" largest elements: ";
		for(i=n-k;i<n;i++)
			cout<<a[i]<<" ";
	}
	else
		cout<<"\nInvalid input";
	auto stop = high_resolution_clock::now();
	
	std::chrono::duration<double, std::milli> fp_ms = stop - start;
	
	cout<<"\ntime in milliseconds: "<<fp_ms.count()<<endl; 
	
	return 0;
}
