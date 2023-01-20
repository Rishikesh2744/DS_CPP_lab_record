#include<iostream>
using namespace std;

template<class t>
class stack;

template<class T>
class node
{
    T *data;
    node<t> *next;

    public:
        node(T ele)
        {
            data=ele;
            node<T> *next=NULL;
        }

    friend class stack;
};

template<class t>
class stack
{
    node<t> *top;

    public:
        stack()
        {
            top=NULL;
        }

        void push(T ele)
        {
            node<T> *nn=new node<T>(ele);

            if(top!=NULL)
            {
                nn->next=top;
            }
            top=nn;
        }

        T pop()
        {
            
            if(top!=NULL)
            {
                node<T> *temp=top;
                top=top->next;
                T x=temp->data;

                delete temp;
                return x;
            }
            return 0;
        }

        void display()
        {
            if(top!=NULL)
            {
                for(node<T> *cur=temp;cur;cur=cur->next)
                {
                    cout<<cur->data<<"   ";
                }
            }
            else
            {
                    cout<<"stack is underflow";
            }
        }

        T topele()
        {
            if(top!=NULL)
                    return top->data;
            return 0;
        }
};
