#include<bits/stdc++.h>
using namespace std;

int Partition(int a[],int start,int last)
{
	int pivot=a[last];
	int i=start-1;
	for(int j=start;j<=last-1;j++)
	{
		if(a[j]<pivot)
		{
			i++;
			swap(a[i],a[j]);
		}
	}
	swap(a[i+1],a[last]);
	return (i+1);
}

int randomize_partition(int a[],int start,int last)
{
	int random= start +(rand()%(last-start+1));
	swap(a[last],a[random]);
	return Partition(a,start,last);
}

int randomize_selection(int a[],int start,int last,int i)
{
	if(start==last)
		return a[start];
	int q=randomize_partition(a,start,last);
	int k=q-start+1;
	if(i==k)
		return a[q];
	else if(i<k)
		return randomize_selection(a,start,q-1,i);
	else
		return randomize_selection(a,q+1,last,i-k);
}

int main()
{
	int n,p;
	cout<<"Enter the size of the array"<<endl;
	cin>>n;
	int *a=new int[n];
	cout<<"Enter the elements"<<endl;
	for(int i=0;i<n;i++)
		cin>>a[i];
	cout<<"Enter the value of i to check ith smallest element"<<endl;
	cin>>p;
	if(p<0 || p>n)
	{
		cout<<"Invalid position"<<endl;
		return -1;
	}
	cout<<"Array "<<endl;
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
	int result=randomize_selection(a,0,n-1,p);
	cout<<p<<"th smallest element in the array : "<<result;
	return 0;

}
