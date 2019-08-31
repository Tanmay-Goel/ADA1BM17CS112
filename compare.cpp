#include<iostream>
#include<chrono>
using namespace std;
using namespace std::chrono;

int bubble()
{
    int count=0;
    int a[10], n, k, i,j,c=0,temp;
	bool swapped;
	cout<<"Enter size: ";
	cin>>n;
	cout<<"\nEnter array: ";
	for(i=0;i<n;i++)
		cin>>a[i];


	auto start = high_resolution_clock::now();


		for(i=0;i<n-1;i++)
		{
			for(j=0;j<n-1-i;j++)
			{
				swapped=false;
				if(a[j+1]<a[j])
				{
					count++;
					temp=a[j];
					a[j]=a[j+1];
					a[j+1]=temp;
					swapped=true;
				}
			}
			c++;
			if(swapped==false)
				{ count++; break; }
		}

		for(i=0;i<n;i++)
			cout<<a[i]<<" ";

	auto stop = high_resolution_clock::now();

	std::chrono::duration<double, std::milli> fp_ms = stop - start;

	cout<<"\ntime in milliseconds: "<<fp_ms.count()<<endl;

	return count;
}
int selection()
{

	int count=0;
	int a[10], n, k, i,j,temp,min,c=0;
	cout<<"Enter size: ";
	cin>>n;
	cout<<"\nEnter array: ";
	for(i=0;i<n;i++)
		cin>>a[i];

	auto start = high_resolution_clock::now();
	for(i=0;i<n-1;i++)
	 {
		min=i;
		for(j=i+1;j<n;j++)
		{
			if(a[j]<a[min])
				{min=j; count++}
		}

			temp=a[min];
			a[min]=a[i];
			a[i]=temp;

     }

	auto stop = high_resolution_clock::now();

	std::chrono::duration<double, std::milli> fp_ms = stop - start;

	cout<<"\ntime in milliseconds: "<<fp_ms.count()<<endl;

	return count;

}
int o=0;

void merge(int arr[], int low, int mid, int high)
{
    int i, j, k;
    int n1 = mid - low + 1;
    int n2 =  high - mid;


    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[low + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1+ j];

    i = 0;
    j = 0;
    k = low;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            o++;
            arr[k] = L[i];
            i++;
        }
        else
        {
            o++;
            arr[k] = R[j];
            j++;
        }
        k++;
    }


    while (i < n1)
    {
        o++;
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        o++;
        arr[k] = R[j];
        j++;
        k++;
    }
}


void mergeSort(int arr[], int low, int high)
{

    if (low < high)
    {
        o++;
        int mid = low+(high - low)/2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid+1, high);
		merge(arr, low, mid, high);
    }
}

void mergesorting()
{
  int arr[10],i,j,high,low,n;
	cout<<"Enter no of elements:";
	cin>>n;
	low=0;
	high=n-1;
	cout<<"Enter elements:";
	for(i =0;i<n;i++)
		cin>>arr[i];
	auto start = high_resolution_clock::now();
	mergeSort(arr, low, high);
	auto stop = high_resolution_clock::now();

	cout<<"sorted array: ";
	for(i=0;i<n;i++)
		cout<<a[i]<<" ";
	std::chrono::duration<double, std::milli> fp_ms = stop - start;

	cout<<"\ntime in milliseconds: "<<fp_ms.count()<<endl;

}


int main()
{
	int c1,c2,c3;

	c1=bubble();
	c2=selection();
	c3=o;

	cout<<"NO. of comparisons:\nBubble: "<<c1<<"\nSelection: "<<c2<<"\nMerge: "<<c3;

	return 0;
}
