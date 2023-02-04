#include <iostream>
#include <stdlib.h>
using namespace std;
template <class t>
class stack;
template <class t>
class node
{
    t data;
    node<t> *link;
    friend stack<t>;

public:
    node(t x)
    {
        data = x;
        link = NULL;
    }
};
template <class t>
class stack
{
    node<t> *top;

public:
    stack()
    {
        top = NULL;
    }
    void push(t);
    t pop();
    void display();
    t topmost();
    ~stack();
};
template <class t>
void stack<t>::push(t x)
{
    node<t> *nn = new node<t>(x);
    if (top)
        nn->link = top;
    top = nn;
}
template <class t>
t stack<t>::pop()
{
    if (top)
    {
        node<t> *tmp = top;
        top = top->link;
        t x = tmp->data;
        delete tmp;
        return x;
    }
    return 0;
}
template <class t>
void stack<t>::display()
{
    if (top)
    {
        node<t> *tmp = top;
        while (tmp)
        {
            cout << tmp->data << endl;
            tmp = tmp->link;
        }
    }
    else
        cout << "stack underflow\n";
}
template <class t>
t stack<t>::topmost()
{
    if (top)
        return top->data;
    return 0;
}
template <class t>
stack<t>::~stack()
{
    while (top)
    {
        node<t> *cur = top;
        top = top->link;
        delete cur;
    }
}
int main()
{
    stack<int> s;
    int c, d;
    while (1)
    {
        cout << "MENU\n1.push 2.pop 3.display 4.top element 5.exit\n";
        cout << "SELECT YOUR OPTION : ";
        cin >>c;
        switch (c)
        {
        case 1:
        cout<< "enter data\n";
            cin >> d;
            s.push(d);
            break;
        case 2:
            d = s.pop();
            if (d != 0)
                cout << "the popped data is " << d << endl;
            else
                cout << "stack underflow\n";
            break;
        case 3:
            cout << "the contents of stack are\n";
            s.display();
            break;
        case 4:
            d = s.topmost();
            if (d)
                cout << "top element is : " << d << endl;
            else
                cout << "stack underflow\n";
            break;
        case 5:
            exit(0);
        }
    }
    return 0;
}