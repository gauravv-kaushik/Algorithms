#include<iostream>
using namespace std;

void bucketsort(int a[],int n)
{
	int max=a[0];

	for(int i=0;i<n;i++)
	{
		if(a[i]>max)
			max=a[i];
	}

	int bucket[max];

	for(int i=0;i<=max;i++)
		bucket[i]=0;

	for(int i=0;i<n;i++)
		bucket[a[i]]++;

	for(int i=0,j=0;i<=max;i++)
	{
		while(bucket[i]>0)
		{
			a[j++]=i;
			bucket[i]--;
		}

	}
}

void print(int a[],int n)
{
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<endl;
}

int main()
{
	int n=5;
	int a[]={4,6,1,8,3};
	print(a,n);
	bucketsort(a,n);
	print(a,n);

}