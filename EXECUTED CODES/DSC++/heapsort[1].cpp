#include<iostream>
using namespace std;
template<class t>
class heapsort
{
	public:
		void accept(t[],t);
		void heap(t[],t);
		void adjust(t[],t,t);
		void display(t[],t);
};
template<class t>
void heapsort<t>::accept(t a[],t n)
{
	cout<<"\n Enter the elements of the array:\n";
	for(t i=0;i<n;i++)
		cin>>a[i];
}
template<class t>
void heapsort<t>::heap(t a[],t n)
{
	t i,temp;
	for(i=n-1;i>=0;i--)
		adjust(a,i,n);
	for(i=n-1;i>=1;i--)
	{
		temp=a[i];
		a[i]=a[0];
		a[0]=temp;
		adjust(a,0,i);
	}
}
template<class t>
void heapsort<t>::adjust(t a[],t i,t n)
{
	t j;
	j=(2*i)+1;
	while(j<=n-1)
	{
		if(j<n-1)
		{
			if(a[j]<a[j+1])
				j++;
		}
		if(a[i]<a[j])
		{
			t temp=a[i];
			a[i]=a[j];
			a[j]=temp;
		}
		i=j;
		j=(2*i)+1;
	}
}
template<class t>
void heapsort<t>::display(t a[],t n)
{
	cout<<"\n Elements after sorting: \n";
	for(t i=0;i<n;i++)
		cout<<a[i]<<"\t";
}
int main()
{
	int a[15],n;
	heapsort<int>h;
	cout<<"\nEnter the size of the array:\n";
	cin>>n;
	h.accept(a,n);
	h.heap(a,n);
	h.display(a,n);
	return 0;
}