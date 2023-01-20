#include<iostream>
using namespace std;

int main()
{
	int **a;

	int row,col,i,j;
	cout<<"enter no. of rows:"<<endl;
	cin>>row;
	cout<<"enter no. of cols:"<<endl;
	cin>>col;

	a=new int *[row];

	for(i=0;i<row;i++)
	{
		a[i]=new int[col];
	}

	cout<<"enter "<<row*col<<" elements:"<<endl;

	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			cout<<"enter "<<i+1<<" row "<<j+1<<" col element:"<<endl;
			cin>>a[i][j];
		}
	}

	cout<<"array:"<<endl;

	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}

	for(i=0;i<row;i++)
	{
		delete[] a[i];
	}

	delete []a;
	
	return 0;
}
