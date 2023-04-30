#include<iostream>
using namespace std;

template<class t>
class q
{
    t *q;

    int fron=rear=-1;

    int cap;

    public:
        
        q(int size)
        {
            cap=size;

            q=new t[cap];
        }

        ~q()
        {
            delete []q;
            cap=0;
            front=rear=-1;
        }

        bool isEmpty()
        {
            if(front==rear==-1)
                return true;
            else 
                return false;
        }

        bool isFull()
        {
            if(rear==cap-1 && front==0)
                return true;
            else 
                return false;
        }

        void enqueue()

        t queue()
        {
            if
        }
};
