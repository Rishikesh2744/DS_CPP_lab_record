#include<iostream>
#include<math.h>
#include<stdlib.h>
using namespace std;

template <class T>
class stack 
{
    T *st;
    int top,cap;
    public:

    stack(int size) 
    {
        cap=size;
        if(cap<1) 
        {
            cout<<"capacity must be >=1\n";
            exit(0);
        }
            st=new T[cap];
            top=-1;
    }

    ~stack()
    {
        delete[]st;
    }

    void enhancecapacity() 
    {
        T *tmp=new T[cap*2];

        for(int i;i<=top;i++)
            tmp[i]=st[i];

        delete []st;

        cap=cap*2;
        st=tmp;

        cout<<"stack size is doubled\n";
    }

    void push(T x)
    {
        if(top==cap-1)
            enhancecapacity();

        st[++top]=x;
    }

    T pop()
    {
        if(top==-1)
            return -1;

        T x=st[top];
        top--;

        return x;
    }
};

void eval(char *b) 
{
    int i=0,p1,p2,p3;

    stack<int> s1(20);

        while(b[i]!='\0')
        {
            if(b[i]>='0' && b[i]<='9')
                s1.push(b[i]-48);
            else 
            {
                p1=s1.pop();
                p2=s1.pop();
            switch(b[i]) 
            {
                case '^':p3=pow(p2,p1);
                s1.push(p3);
                break;

                case '+':p3=p2+p1;
                s1.push(p3);
                break;

                case'-':p3=p2-p1;
                s1.push(p3);
                break;

                case '*':p3=p1*p2;
                s1.push(p3);
                break;

                case '/':p3=p2/p1;
                s1.push(p3);
                break;
            }
        }

        i++;
    }
    cout<<endl<<"result :"<<s1.pop()<<endl;
}

int main()
{
    char p[20];

    cout<<"enter the postfix expression"<<endl;
    cin>>p;

    eval(p);
    
    return 0;
}