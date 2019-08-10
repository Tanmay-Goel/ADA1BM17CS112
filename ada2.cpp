#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
	int a[10],i,n,key,t,b[10],j=0,cnt;
	cout<<"Enter test cases: ";
	cin>>t;
	cnt=t;
	for(i=0;i<t;i++)
		b[i]=-1;
	while(t>0)
	{
		cout<<"\nEnter size and search element: ";
		cin>>n>>key;
		cout<<"\nEnter elements: ";
		for(i=0;i<n;i++)
		{
			cin>>a[i];
			if(a[i]==key)
				b[j]=1;
		}
		t--;
		j++;
		for(i=0;i<n;i++)
			a[i]=0;
	}
	cout<<"\nResult:\n";
	for(i=0;i<cnt;i++)
		cout<<b[i]<<"\n";
	return 0;
}
