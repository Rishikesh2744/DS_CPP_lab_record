#include <iostream>
#include <stdlib.h>
using namespace std;
template <class t>
class Q_linked;
template <class t>
class node
{
    t data;
    node<t> *next;

public:
    node(t x)
    {
        data = x;
        next = NULL;
    }
    friend Q_linked<t>;
};
template <class t>
class Q_linked
{
    node<t> *front, *rear;

public:
    Q_linked()
    {
        front = rear = NULL;
    }
    bool isempty();
    void push(t);
    t pop();
    void display();
    t frontele();
    t rearele();
    ~Q_linked();
};
template <class t>
bool Q_linked<t>::isempty()
{
    if (front == NULL && rear == NULL)
        return true;
    return false;
}
template <class t>
void Q_linked<t>::push(t x)
{
    node<t> *nn = new node<t>(x);
    if (isempty())
        front = rear = nn;
    else
    {
        rear->next = nn;
        rear = nn;
    }
}
template <class t>
t Q_linked<t>::pop()
{
    if (isempty())
        return 0;
    else
    {
        node<t> *tmp = front;
        t x = tmp->data;
        front = front->next;
        if (front == NULL)
            rear = NULL;
        delete tmp;
        return x;
    }
}
template <class t>
void Q_linked<t>::display()
{
    if (isempty())
    {
        cout << "empty Q\n";
        return;
    }
    cout << "the contents of queue are\n";
    for (node<t> *cur = front; cur; cur = cur->next)
        cout << cur->data << "\t";
    cout << endl;
}
template <class t>
t Q_linked<t>::frontele()
{
    if (isempty())
        return 0;
    return front->data;
}
template <class t>
t Q_linked<t>::rearele()
{
    if (isempty())
        return 0;
    return rear->data;
}
template <class t>
Q_linked<t>::~Q_linked()
{
    while (front)
    {
        node<t> *cur = front;
        front = front->next;
        delete cur;
    }
    rear = NULL;
}
int main()
{
    Q_linked<int> c1;
    int c, d;
    while (1)
    {
        cout << "MENU\n1.push 2.pop 3.display 4.frontele 5.rearele 6.exit\n";
        cout << "SELECT YOUR OPTION: ";
        cin >> c;
        switch (c)
        {
        case 1:
            cout << "enter data\n";
            cin >> d;
            c1.push(d);
            break;
        case 2:
            d = c1.pop();
            if (d != 0)
                cout << "the popped data is " << d << endl;
            else
                cout << "empty queue\n";
            break;
        case 3:
            c1.display();
            break;
        case 4:
            d = c1.frontele();
            if (d)
                cout << "front element is : " << d << endl;
            else
                cout << "q underflow\n";
            break;
        case 5:
            d = c1.rearele();
            if (d)
                cout << "rear element is :" << d << endl;
            else
                cout << "q underflow\n";
            break;
        case 6:
            exit(0);
        }
    }
    return 0;
}