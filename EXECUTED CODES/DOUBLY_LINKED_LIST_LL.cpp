// Doubly Linked List.
#include <iostream>
#include <stdlib.h>
using namespace std;
template <class T>
class dll;
template <class T>
class node
{
    T data;
    node<T> *next, *prev;

public:
    node(T x)
    {
        data = x;
        next = prev = NULL;
    }
    friend dll<T>;
};
template <class T>
class dll
{
protected:
    int ls;
    node<T> *first, *last;

public:
    dll()
    {
        cout << "Double Linked List constructor\n";
        first = last = NULL;
        ls = 0;
    }
    bool isempty()
    {
        return ls == 0;
    }
    int size()
    {
        return ls;
    }
    void insertatbeg(T x);
    void insertatend(T x);
    void insertatpos(T, int);
    T delfrombeg();
    T delfromend();
    T delfrompos(int);
    T find(int);
    int forwardsearch(T);
    int backwardsearch(T);
    int count();
    void display();
    void reverse();
};
template <class T>
void dll<T>::insertatbeg(T x)
{
    node<T> *nn = new node<T>(x);
    if (last == NULL)
        last = nn;
    else
    {
        nn->next = first;
        first->prev = nn;
    }
    first = nn;
    ls++;
}
template <class T>
void dll<T>::insertatend(T x)
{
    node<T> *nn = new node<T>(x);
    if (first == NULL)
        first = nn;
    else
    {
        nn->prev = last;
        last->next = nn;
    }
    last = nn;
    ls++;
}
template <class T>
void dll<T>::insertatpos(T x, int pos)
{
    if (pos < 1 || pos > ls + 1)
    {
        cout << "Invalid pos!!\n";
        return;
    }
    node<T> *nn = new node<T>(x);
    if (pos == 1) // Insert at beginning
    {
        if (first == NULL)
            last = nn;
        else
        {
            nn->next = first;
            first->prev = nn;
        }
        first = nn;
    }
    else if (pos == ls + 1) // Insert at End
    {
        last->next = nn;
        nn->prev = last;
        last = nn;
    }
    else // Insert at the pos
    {
        node<T> *cur;
        if (pos <= ls / 2) // Insert in the left half of List
        {
            cur = first;
            for (int i = 1; i < pos - 1; i++)
                cur = cur->next;
        }
        else // Insert in the right half of List
        {
            cur = last;
            for (int i = ls; i > pos - 1; i--)
                cur = cur->prev;
        }
        nn->next = cur->next;
        nn->prev = cur;
        nn->next->prev = nn;
        cur->next = nn;
    }
    ls++;
}
template <class T>
void dll<T>::display()
{
    cout << "List : \n";
    node<T> *cur;
    for (cur = first; cur != NULL; cur = cur->next)
    {
        cout << cur->data << "\t";
    }
    cout << endl;
}
template <class T>
T dll<T>::delfrombeg()
{
    if (first == NULL)
    {
        cout << "list is empty, can't ddatate\n";
        return 0;
    }
    node<T> *del = first;
    if (first == last)
        first = last = NULL;
    else
    {
        first = first->next;
        first->prev = NULL;
    }
    T x = del->data;
    delete del;
    ls--;
    return x;
}
template <class T>
T dll<T>::delfromend()
{
    if (last == NULL)
    {
        cout << "list is empty, can't ddatate\n";
        return 0;
    }
    node<T> *del = last;
    if (first == last)
        first = last = NULL;
    else
    {
        last = last->prev;
        last->next = NULL;
    }
    T x = del->data;
    delete del;
    ls--;
    return x;
}
template <class T>
T dll<T>::delfrompos(int pos)
{
    node<T> *del;
    if (pos < 1 || pos > ls)
    {
        cout << "Invalid pos!!\n";
        return 0;
    }
    if (pos == 1) // Delete from beginning
    {
        del = first;
        first = first->next;
        if (first == NULL)
            last = NULL;
        else
            first->prev = NULL;
    }
    else if (pos == ls) // Delete from ending
    {
        del = last;
        last = last->prev;
        last->next = NULL;
    }
    else // Delete from pos
    {
        node<T> *cur;
        if (pos <= ls / 2) // Delete from Left half of List
        {
            cur = first;
            for (int i = 1; i < pos - 1; i++) // move till pos-1 node
                cur = cur->next;              // deleting node is cur node's next node
            del = cur->next;
            cur->next = del->next;
            del->next->prev = cur;
        }
        else // Delete from Right half of List
        {
            cur = last;
            for (int i = ls; i > pos + 1; i--) // move till pos+1 node
                cur = cur->prev;               // deleting node is cur node's previous node
            del = cur->prev;
            cur->prev = del->prev;
            del->prev->next = cur;
        }
    }
    T x = del->data;
    delete del;
    ls--;
    return x;
}
template <class T>
int dll<T>::count()
{
    int c = 0;
    node<T> *cur = first;
    while (cur)
    {
        c++;
        cur = cur->next;
    }
    return c;
}
template <class T>
T dll<T>::find(int pos)
{
    if (pos > 0 && pos <= ls)
    {
        node<T> *curr;
        if (pos <= ls / 2) // Search in the Left half of List
        {
            curr = first;
            for (int i = 1; i <= pos; i++)
                curr = curr->next;
            return curr->data;
        }
        else // Search in the Right half of List
        {
            curr = last;
            for (int i = ls; i >= pos; i--)
                curr = curr->prev;
            return curr->data;
        }
    }
    else
        return 0;
}
template <class T>
int dll<T>::forwardsearch(T x)
{
    int pos = 1;
    node<T> *curr;
    curr = first;
    while (curr != NULL && curr->data != x)
    {
        curr = curr->next;
        pos++;
    }
    if (curr == NULL)
        return 0;
    else
        return pos;
}
template <class T>
int dll<T>::backwardsearch(T x)
{

    int pos = ls;
    node<T> *curr;
    curr = last;
    while (curr != NULL && curr->data != x)
    {
        curr = curr->prev;
        pos--;
    }
    if (curr == NULL)
        return 0;
    else
        return pos;
}
template <class T>
void dll<T>::reverse()
{
    if (first) // if list is not empty
    {
        node<T> *temp = 0, *cur = first; // first node prev is 0, cur points to first node
        while (cur)                      // if current node is not NULL
        {
            node<T> *p = temp; // take temp node into p
            temp = cur;        // take cur node into temp
            cur = cur->next;   // move cur to next node
            temp->next = p;    // make a reverse link
            if (p)
                p->prev = temp;
        }
        last = first;
        first = temp; // make first to point to the last node
    }
}
int main()
{
    dll<int> s1;
    int c, d, p;
    while (1)
    {
        cout << "MENU\t1.insert at begining\t2.insert at end\t3.insert at requird position\t";
        cout << "4.del from begining\t5.del from end\t6.del from position\t7.display\t";
        cout << "8.count no of nodes\t9.forward search\t10.backward search\t11. find\t12.reverse\t13.exit\nenter your choice\n";
        cin >> c;
        switch (c)
        {
        case 1:
            cout << "enter data\n";
            cin >> d;
            s1.insertatbeg(d);
            break;
        case 2:
            cout << "enter data\n";
            cin >> d;

            s1.insertatend(d);
            break;
        case 3:
            cout << "enter data and positon\n";
            cin >> d >> p;
            s1.insertatpos(d, p);
            break;
        case 4:
            d = s1.delfrombeg();
            if (d)
                cout << "the deleted data is" << d << endl;
            break;
        case 5:
            d = s1.delfromend();
            if (d)
                cout << "the deleted data is" << d << endl;
            break;
        case 6:
            cout << "enter the position to be deleted\n";
            cin >> c;
            d = s1.delfrompos(c);
            if (d)
                cout << "deleted element is: " << d << endl;
            break;
        case 7:
            s1.display();
            break;
        case 8:
            d = s1.count();
            cout << "the numbr of nodes are" << d << endl;
            break;
        case 9:
            cout << "enter the element to search: ";
            cin >> d;
            p = s1.forwardsearch(d);
            if (p)
                cout << "element is at position: " << p << endl;
            else
                cout << "element NOT found\n";
            break;
        case 10:
            cout << "enter the element to search: ";
            cin >> d;
            p = s1.backwardsearch(d);
            if (p)
                cout << "element is at position: " << p << endl;
            else
                cout << "element NOT found\n";
            break;
        case 11:
            cout << "enter the position to find the element: ";
            cin >> p;
            d = s1.find(p);
            if (p)
                cout << "element at position: " << p << "is: " << d << endl;
            else
                cout << "Invalid position\n";
            break;
        case 12:
            s1.reverse();
            break;
        case 13:
            exit(0);
        }
    }
    return 0;
}