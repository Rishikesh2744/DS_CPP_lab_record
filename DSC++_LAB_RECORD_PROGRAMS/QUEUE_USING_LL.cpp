#include<iostream
using namespace std;

template<class T>
class Q_linked;

template<class T>
class node
{
    T data;
    node<T> *next;

    public:
        node(T ele)
        {
                data=ele;
                node<T> *next=NULL;
        }
    
    friend class Q_linked;
}

template<class T>
class Q_linked()
{
    node<T> *front,*rear;

    public:
        Q_linked()
        {
            front=rear=NULL;
        }

        bool isEmpty()
        {
            if(front==NULL && rear=NULL)
                return true;
            else   
                return false;
        }

        void enqueue()
        {
            node<T> *nn=new node<T>(ele);

           if(isEmpty())
           {
                front=rear=nn;
           }
           else
           {
                rear->next=nn;
                rear=nn;
           }

           cout<<"Node Inserted"<<endl;
        }
}