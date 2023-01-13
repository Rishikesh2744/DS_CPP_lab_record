#include<iostream>
using namespace std;

template<class T>
class Array
{
    int capacity;
    int cur_size;

    public:
        Array(int size);
        ~Array();
        void Enhance();
        bool ifFull();
        bool isEmpty();
        void InsertAtEnd(T ele);
        void InsertAtPos(T ele,int index);
        T DeleteFromEnd();
        T DeleteFromPos(int index);
        void Display();
};

template <class T>
Array<T>::Array(int size)
{
    int capacity=size;
    int cur_size=0;

    arr=new T[capacity];
}

template <class T>
Array<T>::~Array()
{
    delete arr[];
    capacity=0;
    cur_size=0;
}

template <class T>
void Array<T>::Enhance()
{
    T *temp;
    temp=new T[capacity*2];

    for(int i=0;i<=cur_size;i++);
        temp[i]=arr[i];

    delete []arr;
    arr=temp;

    capacity=capacity*2;
}

template <class T>
bool Array<T>::ifFull()
{
    if(cur_size=capacity)
        return true;
    else
        return false;
}

template <class T>
bool Array<T>::isEmpty()
{
    if(cur_size==0)
        return true;
    else
        return false;
}

template <class T>
void Array<T>::InsertAtEnd(T ele)
{
    if(isFull())
        Enhance();
    arr[cur_size]=ele;
    cur_size++;
    cout<<"Inserted element at the end"<<endl;
}

template <class T>
void Array<T>::InsertAtPos(T ele,int index)
{
    if(isFull())
        Enhance();
    if(index<0||index>capacity)
    {    
        cout<<"Invalid Index";
        return 0;
    }
    else
    {
        for(int i=cur_size-1;i>=index;i--)
            arr[i+1]=arr[i];
    
         arr[index]=ele;

        cur_size++;
        cout<<"Inserted element at "<<index<<endl;
    }
}

template <class T>
T Array<T>::DeleteFromEnd()
{
    if(isEmpty())
    {    
        cout<<"Array is Empty"<<endl;
        return 0;
    }
    else
    {
        T *temp;
        temp=arr[cur_size];
        arr[cur_size]=INT_MIN;
        cur_size--;
        return temp;
    }
}

template <class T>
T Array<T>::DeleteFromPos(int index)
{
    if(isEmpty())
    {       cout<<"Array is Empty"<<endl;
            return 0;
    }
    else
    {
        if(index<0||index>capacity)
        {    
            cout<<"Invalid Index";
            return 0;
        }
        else
        {
            T *temp;
            temp=arr[index];

            for(int i=index+1;i<=cur_size;i++)
                arr[i-1]=arr[i];
        
            arr[cur_size]=INT_MIN;
            cur_size--;

        return temp;
        }
    }
}

template <class T>
void Array<T>::Display()
{
    if(isEmpty())
    {
        cout<<"Array is Empty"<<endl;
    }
    else
    {
        for(int i=0;i<cur_size;i++)
        {
            cout<<arr[i];
        }

        cout<<endl;
    }
}

int main()
{
    Array<int>arr1(5);

    int index,x,ele,temp1;

    while(1)
    {
        cout<<"Menu\n1.Insert at the end\n 2.Insert at an index\n 3.Delete at the end\n 4.Delete from an index\n 5.Display array\n ";
        switch (x)
        {
        case 1:
            cout<<"Enter element :";
            cin>>ele;
            arr1.InsertAtEnd(ele);
            break;
        
        default:
            break;
        }
    }
}