#include<iostream>
using namespace std;

template<class T>
class SLL;

template<class T>
class node
{
    T data;
    node<T> *next;

    friend class SLL<T>;
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

        ~SLL()
        {
            for(node<T> *cur=first;cur;cur=cur->next)
            {
                first=first->next;
                delete cur;
                cur=first;
            }
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
        first=nn;
    }
    cout<<"Node Inserted\n";
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
        while(cur->next!=NULL)
            cur=cur->next;
        cur->next=nn;
    }
    cout<<"Node Inserted"<<endl;
}

template <class T>
void SLL<T>::insertatpos(T ele, int index)
{
    node<T> *nn=new node<T>;
    nn->data=ele;
    nn->next=NULL;

    node<T> *cur=first;

    if(index==1)
    {
        nn->next=first;
        first=nn;
    }
    else
    {
        int i;
        for( i=1;i<index-1&&cur->next;i++)
            cur=cur->next;
        
        if(i=index-1)
        {
            nn->next=cur->next;
            cur->next=nn;
        }
        else
        {
            cout<<"Invalid Index Position"<<endl;
            return;
        }
    }
    cout<<"Node Inserted"<<endl;
}

template <class T>
T SLL<T>::delfrombeg()
{
    if(first!=NULL)
    {
        node<T> *cur=first;
        T temp=cur->data;

        first=first->next;

        delete cur;
        return temp;
    }
    else
    {
        cout<<"empty chain,can't delete"<<endl;
        return 0;
    }
}

template <class T>
T SLL<T>::delfromend()
{
    if(first!=NULL)
    {
        node<T> *prev;
        T temp;
        node<T> *cur=first;
        while(cur->next!=NULL)
        {
            prev=cur;
            cur=cur->next;
        }
        
        temp=cur->data;

        if(first->next==NULL)
        {
            first=NULL;
        }
        else
        {
            prev->next=NULL;
        }

        delete cur;
        return temp;
    }
    else
    {
        cout<<"empty chain,can't be deleted"<<endl;
        return 0;
    }
}

template <class T>
void SLL<T>::display()
{ 
    if(first!=NULL)
    {
        for(node<T> *cur=first;cur;cur=cur->next)
        {
            cout<<cur->data<<"  ";
        }
        cout<<endl;
    }
    else
    {
        cout<<"\nList is empty";
    }
}

template<class T>
T SLL<T>::delfrompos(int index)
{
    node<T> *cur=first,*prev;
    if(first!=NULL)
    {
        
        T temp;

        if(index==1)
        {
            cur=first;
            first=first->next;
        }
        else
        {
            for(int i=1;i<index&&(cur!=NULL);cur=cur->next,i++)
                prev=cur;
        }

        if(cur!=NULL)
            prev->next=cur->next;
        else
        {
            cout<<"Invalid postion,cant delete";
            return 0;
        }
    }
    T temp=cur->data;
    delete cur;
    return temp;
}
