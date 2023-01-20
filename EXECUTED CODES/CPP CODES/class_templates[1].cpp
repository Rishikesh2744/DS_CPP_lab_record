//class templates
#include<iostream>
using namespace std;

template<class T>
class Max
{
	T x,y;
	public:
		void read();
		T getMax();
};

template<class T>
void Max<T>::read()
{
	cout<<"enter 2 values:"<<endl;
	cin>>x>>y;
}

template<class T>
T Max<T>::getMax()
{
	if(x>y)
		return x;
	else return y;
}

int main()
{
	Max<int>iMax;
	int a;

	Max<float>fMax;
	float b;

	Max<char>cMax;
	char c;

	cout<<"enter integers:"<<endl;
	iMax.read();
	a=iMax.getMax();

	cout<<"maximum is:"<<a<<endl;
	cout<<"enter floats:"<<endl;
	fMax.read();
	b=fMax.getMax();

	cout<<"maximum is:"<<b<<endl;
	cout<<"enter characters:"<<endl;
	cMax.read();
	c=cMax.getMax();
	
	cout<<"maximum is:"<<c<<endl;

	return 0;
	
}
