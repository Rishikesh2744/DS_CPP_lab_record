#include<iostream>
using namespace std;

template<class T>
class stack
{
	T *s;
	int cap;
	int top;
	public:
		stack();
		void display();
		void push(T ele);
		T pop();
		T topele();
		void enhance();
		bool isEmpty();
		bool isFull();
};

template<class T>
stack<T>::stack()
{
	cout<<"enter size of array:";
	cin>>cap;
	s=new T[cap];
	top=-1;
}

template<class T>
void stack<T>::display()
{
	if (top==-1)
	cout<<"stack is empty"<<endl;
	else
	{
		cout<<"elements in stack are:"<<endl;
		for(int i=top-1;i>=0;i--)
		{
			cout<<s[i]<<endl;
		}
	}
}

template<class T>
void stack<T>::push(T ele)
{
	if(isFull())
	enhance();
	else
	{
		top++;
		s[top]=ele;
		cout<<"element successfully inserted"<<endl;
	}
}

template<class T>
T stack<T>::pop()
{
	if(isEmpty())
		cout<<"stack is empty"<<endl;
	else
	{
		T temp;
		temp=s[top];
		top--;
		return temp;
	}
}

template<class T>
T stack<T>::topele()
{
	cout<<s[top];
}

template<class T>
void stack<T>::enhance()
{
	T *t;
	t=new T[2*cap];
	for(int i=0;i<top;i++)
	{
		t[i]=s[i];
	}
	delete []s;
	cap=2*cap;
	s=t;
}

template<class T>
bool stack<T>::isEmpty()
{
	if (top==-1)
	return true;
	else
	return false;
}

template<class T>
bool stack<T>::isFull()
{
	if(top==cap-1)
	return true;
	else
	return false;
}

int main()
{
	stack<int> s1;
	int top,ele,d,x;
	cout<<"\nMENU:\n1.Push\n2.Pop\n3.Display Top ele\n4.Display stack"<<endl;	
	while(1)
	{
		cout<<"enter your choice:"<<endl;
		cin>>x;
		switch(x)
			{
				case 1:cout<<"enter element:"<<endl;
					   cin>>ele;
					   s1.push(ele);
					   break;
				case 2:d=s1.pop();
					   cout<<d<<"is removed from the stack"<<endl;
					   break;
			    case 3:cout<<"top element is:"<<s1.topele()<<endl;
			    	   break;
			    case 4:s1.display();
			    	   break;
			    case 5:exit(0);
					   
			}
	}
	return 0;
}