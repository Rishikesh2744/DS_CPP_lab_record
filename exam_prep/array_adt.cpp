#include<iostream>
using namespace std;

template<class t>
class Array
{
    int cap;
    int csize;

    public:
        Array(int size)
        {
            cap=size;
            csize=0;

            arr=new t[cap];
        }

        ~Array()
        {
            delete []arr;

            cap=0;
            csize=0;
        }

        void enhance()
        {
            t temp=new t[cap*2];

            for(int i=0;i<csize;i++)
                temp[i]=arr[i];

            cap=cap*2;

            delete []arr;
        }

        void isFull()
        {
            if(csize=cap)
                return true;
            else 
                return false;
        }

        void isEmpty()
        {
            if(csize=0)
                return true;
            else
                return false;
        }

        void insert_at_end(t ele)
        {
            t data=ele;

            if(isFull)
                enhance();
            
            arr[csize+1]=data;

            csize++
        }

        void insert_at_pos(t ele,int index)
        {
            t data=ele;

            if(isFull)
                enhance();

            if(index<0||index>capacity)
            {
                return ;
            }

            for(int i=csize-1;i>=index;i--)
                arr[i+1]=arr[i];
            
            arr[index]=data;

            csize++
        }

        t deletefromend()
        {
            t *temp;
            if(isEmpty())
                return ;
            else
            {
                temp=arr[csize-1];

                arr[size-1]=INT_MIN;
                csize--;
                return temp;
            }
        }

        t deletefrompos(int index)
        {

            if(isEmpty())
            {
                return ;
            }
            else
            {
                t *temp;

                temp=arr[index];

                for(int i=index+1;i<csize;i++)
                    arr[i-1]arr[i];
                
                arr[csize]=INT_MIN;

                csize--;

                return temp;
            }
        }

        void display()
        {
            if(isEmpty())
                return ;
            else
            {
            for(int i=0;i<csize;i++)
                cout<<arr[i];
            }
        }
};
