#include<iostream>
using namespace std;

template<class T>
class SLL;

template<class T>
class node
{
    T *data;
    node<T> *next;

    friend class SLL;
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

        void insertatbeg(T ele)
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
            cout<<"Node inserted"<<endl;
        }

        void insetatend(T ele)
        {
            node<T> nn=new node<T>;
            nn->data=ele;
            nn->next=NULL;

            node<T> *cur=first;

            if(first==NULL)
            {
                first=nn;
            }
            else{
                while(cur->next!=NULL)
                    cur=cur->next;
                cur->next=nn;
            }
            cout<<"Node Inserted"<<endl;
        }

        void insertatpos(T ele,int index)
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
                for(int i=1;i<index && cur->next;i++)
                    cur=cur->next;

                if(i=index-1)
                {
                    nn->next=cur->next;
                    cur->>
                }
            }
        }
};
