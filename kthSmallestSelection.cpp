#include<iostream>
#include<chrono>
using namespace std;
using namespace std::chrono;
int main()
{
	int a[10], n, k, i,j,temp,min,c=0;
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
		min=i;
		for(j=i+1;j<n;j++)
		{
			if(a[j]<a[min])
				min=j;
		}
		c++;
		if(c<k)
		{
			temp=a[min];
			a[min]=a[i];
			a[i]=temp;
		}
	else
		break;
     }
	cout<<endl<<k<<"th smallest element: "<<a[min];
	}

	else
		cout<<"\nInvalid input";
	auto stop = high_resolution_clock::now();
	
	std::chrono::duration<double, std::milli> fp_ms = stop - start;
	
	cout<<"\ntime in milliseconds: "<<fp_ms.count()<<endl; 
	
	return 0;
}
