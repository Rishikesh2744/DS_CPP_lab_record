#include<iostream>
using namespace std;

template<class T>
class DLL;

template<class T>
class node
{
    T data;
    node<t> *prev,*next;

    friend class DLL<T>;

    public:
        node(T ele)
        {
            T data=ele;
            prev=next=NULL;
        }
};

template<class T>
class DLL
{
    int ls;
    node<t> *first,*last;

    public:
        DLL()
        {
            first=lat=NULL;
            ls=0;
        }

        bool isEmpty()
        {
            if(first==NULL && last==NULL)
                return true;
            else 
                return false;
        }

        int count()
        {
            return ls;
        }

        void insertatbeg(T ele)
        {
            node<T> *nn=new node<T>(ele);
            if(isEmpty())
            {
                first=last=nn;
            }
            else
            {
                nn->next=first;
                first->prev=nn;
                first=nn;
            }
            ls++;
                cout<<"\n Node Inserted"<<endl;
        }

        void insertatend(T ele)
        {
            node<T> *nn=new node<T>(ele);

            if(isEmpty)
            {
                first=last=nn;
            }
            else
            {
                nn->prev=last;
                last->next=nn;
                last=nn;
            }
            ls++;

                cout<<"\n Node Inserted"<<endl;
        }

        T delfrombeg()
        {
            if(isEmpty())
            {
                cout<<"Empty list"<<endl;
                return 0;
            }

            node<T> *cur=first;

            T temp=cur->data;

            if(first==last)
            {
                first=last=NULL;
            }
            else
            {
                first=first->next;
                first->prev=NULL;
            }

            delete cur;
            ls--;
            return temp;
        }

        T delfromend()
        {
                if(isEmpty())
                {
                    cout<<"Empty List"<<endl;
                    return 0;
                }

                node<T> *cur=last;

                if(first==last)
                {
                    fisrt=last=NULL;
                }
                else
                {
                    last=last->prev;
                    last->next=NULL;
                }

                delete cur--;
                ls--;

                return temp;
        }

        void display()
        {
            if(isEmpty())
            {
                cout<<"Empty chain";
                return;
            }
            
            for(node<T> *cur=first;cur!=NULL;cur=cur->next)
            {
                cout<<cur->data<<" "<<endl;
            }
        }
};
