#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;
template<class t>
class stack
{
int top,cap;
t *st;
public:
stack(int n)
{
    cap=n;
    if(cap<1)
    {
        cout<<"capacity must be greater than 1\n";
        exit(0);
    }
    st=new t[cap];
    top=-1;
}
void enhance()
{
    t * temp=new t[2*cap];
    for(int i=0;i<=top;i++)
     temp[i]=st[i];
    delete[] st;
    cap=2*cap;
    st=temp;
}
void push(t x)
{
    if(isfull())
    {
        enhance();
    }
    st[++top]=x;
       
}
t pop()
{
    if(isempty())
      cout<<"\n Stack is empty\n";
    t temp;
    temp=st[top];
    top--;
    return temp;
}
t topelement()
{
    if(isempty())
      cout<<"\n Stack is empty\n";
    else
    {
        return st[top];
    }
}
bool isempty()
{
    if(top==-1)
      return true;
    else
      return false;
}
bool isfull()
{
    if(top==cap-1)
      return true;
    else
      return false;
}
};
int priority(char k)
{
    switch(k)
    {
        case '^': return 5;
        case '*':
        case '/':return 4;
        case '+':
        case '-':return 3;
        case '(':return 2;
        case ')':return 1;
    }
    return 0;
}
void convert(char *a)
{
    int i,j=0,len;
    stack<char> st(20);
    len=strlen(a);
    char b[len];
    for(i=0;i<len;i++)
    {
        char ch=a[i];
        if(isalnum(ch))
          b[j++]=ch;
        else if(ch=='(')
          st.push(ch);
        else if(ch==')')
        {
            while(st.topelement()!='(')
               b[j++]=st.pop();
            st.pop();   
        }
        else
        {
            while(priority(ch)<=priority(st.topelement()))
              b[j++]=st.pop();
            st.push(ch);
        }
        }
        while(!st.isempty())
          b[j++]=st.pop();
        b[j]='\0';
        cout<<"Postfix Expression: "<<b<<endl;
}
int main()
{
    char p[20];
    cout<<"Enter infix expression:\n";
    cin>>p;
    convert(p);
    return 0;
}


