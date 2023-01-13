#include<iostream>
using namespace std;

template<class T>
class queue
{
    T *q;
    int front;
    int rear;
    int capacity;
    public:
        queue(int max);
        ~queue();
        bool isEmpty();
        bool isFull();
        void enhance();
        void display();
        void push(T ele);
        T pop();  
        T frontele();
        T rearele();   
};

template<class T>
queue<T>::queue(int max)
{
    capacity=max;
    if(capacity<1)
    {
        cout<<"capacity must be >=1\n"<<endl;
        exit(0);
    }

    q=new T[capacity];

    front=rear=-1;
}

template <class T>
queue<T>::~queue()
{
    delete q[];
    front=rear=INT_MIN;
}

template <class T>
bool queue<T>::isEmpty()
{
    if(front==-1 && rear==-1)
        return true;
    else
        return false;
}

template <class T>
bool queue<T>::isFull()
{
    if(rear==capacity-1)
        return true;
    else
        return false;
}

template <class T>
void queue<T>::enhance()
{
    T *temp;
    temp=new T[2*capacity];

    for(int i=front;i<=rear;i++)
        temp[i]=q[i];
    
    delete []q;
    capacity=2*capacity;
    q=temp;
    cout<<"Q size is doubled\n"<<endl;
}

template <class T>
void queue<T>::display()
{
    if(isEmpty())
        cout<<"Q is empty"<<endl;
    else
    {
        for(int i=front;i<=rear;i++)
            cout<<q[i]<<" ";
        
        cout<<endl;
    }
}

template <class T>
void queue<T>::push(T ele)
{
    if(isFull())
        enhance();
    if(front==-1)
        front=0;
    else if(front>0)
    {
        for(int i=front;i<=rear;i++)
            q[i-1]=q[i];

        front--;
        rear--;
    }
    q[++rear]=ele;
    rear++;

    cout<<"element is inserted"<<endl;
}

template<class T> 
T queue<T>::pop()
{
    if(isEmpty())
    {
        cout<<"Q is empty"<<endl;
        return 0;
    }
    T *temp;
    temp=q[front];
    if(front==rear)
        front=rear=-1;
    else
        front++;
    return temp;
}

template <class T>
T queue<T>::frontele()
{
    if(isEmpty())
    {
            cout<<"Q is empty"<<endl;
            return 0;
    }
    else
    {
            return q[front];
    }

}

template <class T>
T queue<T>::rearele()
{
    if(isEmpty())
    {
        cout<<"q is empty"<<endl;
        return 0;
    }
    else
        return q[rear];
}
