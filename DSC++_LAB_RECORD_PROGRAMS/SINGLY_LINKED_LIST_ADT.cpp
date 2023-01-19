#include<iostream>
using namespace std;

template<class T>
class SLL;

template<class T>
class node
{
    T data;
    node<T> *next;

    friend class SLL<T>
};

template<class T>
class SLL
{
    node<T> *first;

    public:
        SLL()
        {
            first=NULL;
        }

        void insertatbeg(T ele);
        void insertatend(T ele);
        void insertatpos(T ele,int index);
        T delfrombeg();
        T delfromend();
        T delfrompos(int index);
        void display();
        int count();
        void reverse();
        T find(int index);
        int search(T ele);
        void sort();
};

template <class T>
void SLL<T>::insertatbeg(T ele)
{
    node<T> *nn=new node<T>;
    nn->data=ele;
    nn->next=NULL;        

    if(first==NULL)
    {
        first=nn;
    }
    else
    {
        nn->next=first;
        firt=nn;
    }
    cout<<"Node Inserted\n"
}

template <class T>
void SLL<T>::insertatend(T ele)
{
    node<T> *nn=new node<T>;

    nn->data=ele;
    nn->next=NULL;

    node<T> *cur=first;
    
    if(first=NULL)
    {
          first=nn;
    }
    else
    {
        while(cur->!=NULL)
            cur=cur->next;
        cur->next=nn;
    }
    cout<<"Node Inserted"<<cout;
}

template <class T>
void SLL<T>::insertatpos(T ele, int index)
{
    node<T> *nn=new node<T>;
    nn->data=ele;
    nn->next=NULL;

    node<T> *cur=first;

    if(pos==1)
    {
        nn->next=first;
        first=nn;
    }
    else
    {
        for(int i=1;i<index-1&&cur->next;i++)
            cur=cur->next;
        
        if(i=index-1)
        {
            nn->next=cur->next;
            cur->next=nn;
        }
        else
        {
            
        }
    }
}
