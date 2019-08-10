#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
	int a[10],n,i,b=0;
	cout<<"Enter number of elements: ";
	cin>>n;
	cout<<"\nEnter elements: ";
	for(i=0;i<n;i++)
	{
		cin>>a[i];
		if(a[i]>b)
			b=a[i];
	}
	cout<<"\nLargest number: "<<b;
	return 0;
}
