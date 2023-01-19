#include<iostream>
using namespace std;

template<class T>
class cirq
{
    T *cirq;
    int front,rear,capacity;
    public:
    cirq(int max)
    {
        capacity=max;
        if(capacity<1)
        {
            cout<<"Capacity must be >+1\n";
            exit(0);
        }
        cirq=new T[capacity];
        front=rear=0;
    }
    ~cirq();
    bool isEmpty();
    void push(T ele);
    void display();
    void enhance();
    T pop();
    T frontele();
    T rearele();
};

template <class T>
cirq<T>::~cirq()
{
    delete []cirq;
}

template <class T>
bool cirq<T>::isEmpty()
{
    if(front==rear)
        return true;
    else    
        return false;
}

template <class T>
void cirq<T>::push(T ele)
{
    if(front==(rear+1)%capacity)
    {
        enhance();
    }
    rear=(rear+1)%capacity;
}

template <class T>
void cirq<T>::display()
{
    if(isEmpty())
    {
        cout<<"Circular Queue is Empty";
    }
    else
    {
        for(int i=(front+1);front!=rear;i=(i+1)%capacity)
            cout<<cirq[i];
        cout<<cirq[rear]<<"\t"<<endl;
    }
}

template <class T>
void cirq<T>::enhance()
{
    T *temp;
    temp=new T[capacity*2];

    for (int i=front; front!=rear;i++)
    {
        front=(front+1)%capacity;
        temp[i]=cirq[front];
    }

    delete []cirq;
    cirq=temp;
    front=0;
    rear=capacity-1;
    
    
}
