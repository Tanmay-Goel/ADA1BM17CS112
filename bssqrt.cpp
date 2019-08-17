#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

int main(int argc, char **argv)
{
	
	double dur=0.0;
	int num, end, beg, mid;
	cout<<"Enter a number: ";
	cin>>num;
	beg=0;
	end=num;
	
	auto start = high_resolution_clock::now();
	while(beg<=end)
	{
		mid=(beg+end)/2;
		if(mid*mid==num)
			{
				break;
			}
		else if(mid*mid>num)
		{
			end=mid-1;
		}
		else
		{
			beg=mid+1;
		}
	}
	auto stop = high_resolution_clock::now();
	
	if(mid*mid>num)
	{
		mid--;
	}
	std::chrono::duration<double, std::milli> fp_ms = stop - start;
	
	cout<<"\nSqrt: "<<mid;
	
	cout<<"\ntime in milliseconds: "<<fp_ms.count()<<endl; 
	return 0;
}
