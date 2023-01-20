#include<iostream>
using namespace std;

template <class T>
T add(T &a,T &b)
{
	T result=a+b;
	return result;
}

int main()
{
	int a=2,b=5;
	float m=2.2,n=5.7;
	cout<<"sum1:"<<add(a,b)<<endl;
	cout<<"sum2:"<<add(m,n)<<endl;
}
