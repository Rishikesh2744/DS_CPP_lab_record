#include<iostream>
using namespace std;

template<class t>
class Stack
{
    t *st;
    int top;
    int cap;

    public:
        Stack(int size)
        {
            top=-1;
            cap=0;
            csize=size;
        }

        ~Stack()
        {
            delete []st;
        }

        bool isFull()
        {
            if(top==cap-1)
                return true;
            else 
                return false;
        }

        bool isEmpty()
        {
            if(top==-1)
                return ture;
            else
                return false;
        }

        void enhance()
        {
                T *temp;

                temp=new t[cap*2];

                for(int i=0;i<top;i++)
                    temp[i]=arr[i];
                
                cap=cap*2;

                delete []st;
                st=temp;
        }

        void push(t ele)
        {
            if(isFUll())
            {
                enhance();
            }

                st[++top]=ele;
                top++;
        }

        t pop()
        {
            t * temp;

            temp=st[top];

            st[top]=INT_MIN;

            top--;

            return temp;
        }

        t topele()
        {
            if(isEmpty())
                return ;
            else
                return  st[top];
        }

        void display()
        {
            if(isEmpty())
            {
                    cout<<"empty";
            }
            else
            {
                for(int i=0;i<=top-1;i++)
                    cout<<st[i];
            }
        }
};

