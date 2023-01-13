#include<iostream>
using namespace std;

template<class T>
class Stack
{
    T *st;
    int top;
    int cap;

    public:
        Stack();
        ~Stack();
        bool isEmpty();
        bool isFull();
        void display();
        void push(T ele);
        T pop();
        T topele();
        void enhance();
};

template <class T>
Stack<T>::Stack()
{
    cout<<"enter Initial size of Stack: ";
    cin>>cap;
    st=new T[cap];
    top=-1;
}

template <class T>
Stack<T>::~Stack()
{
    delete st[];
}

template <class T>
bool Stack<T>::isEmpty()
{
    if(top==-1)
        return true;
    else
        return false;
}

template <class T>
bool Stack<T>::isFull()
{
    if(top==cap-1)
        return true;
    else 
        return false;
}

template <class T>
void Stack<T>::display()
{
    if(isEmpty())
        cout<<"Stack is underflow";
    else
    {
        for(int i=0;i<=top;i++)
            cout<<st[i]<<"  ";

        cout<<endl;
    }
}

template <class T>
void Stack<T>::push(T ele)
{
    if(isFull())
        enhance();
    st[++top]=ele;
    top++;
    cout<<"Element Inserted"<<endl;
}

template <class T>
T Stack<T>::pop()
{
    if(isEmpty())
    {
        cout<<"Stack is underflow";
        return;
    }
    else
    {
        T *temp;
        temp=st[top];
        top--;
        return temp;
    }
}

template <class T>
T Stack<T>::topele()
{
    if(isEmpty())
    {
        cout<<"Stack is underflow";
        return;
    }
    else
    {
        return st[top];
    }
}

template <class T>
void Stack<T>::enhance()
{
    T *temp;
    temp=new T[cap*2];

    for(int i=0;i<=top;i++)
        temp[i]=st[i];
    
    cap=2*cap;
    
    delete st[];
    st=temp;
}

int main()
{
    Stack<int>st1;
    int x,ele,top;
    int temp1;
    cout<<"\nMenu:\n1.Push\n2.Pop\n3.Display Topmost element\n4.Display stack elements"<<endl;

    while(1)
    {
        cout<<"Enter your choice of operation: ";
        cin>>x;
        switch (x)
        {
        case 1:
            cout<<"Enter a Element: ";
            cin>>ele;
            st1.push(ele);
            break;
        case 2: 
            temp1=st1.pop();
            cout<<"Deleted element: "<<temp1<<endl;
            break;
        
        case 3:
            temp1=st1.topele();
            cout<<"Topmost element is: "<<temp1<<endl;
            break;
        
        case 4:
            st1.display();
            break;

        default:
            exit(1);
        }
    }
}