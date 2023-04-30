#include <iostream>
#include <stdlib.h>
using namespace std;
template <class t>
class chain;
template <class t>
class node
{
    t data;
    node<t> *next;
    friend chain<t>;

public:
    node(t x)
    {
        data = x;
        next = NULL;
    }
};
template <class t>
class chain
{
    node<t> *first;

public:
    chain()
    {
        first = NULL;
    }
    bool isempty();
    void insertatbeg(t);
    void insertatend(t);
    void insertatpos(t, int);
    void display();
    t delfrombeg();
    t delfromend();
    t delfrompos(int);
    int count();
    t find(int);
    int search(t);
    void reverse();
    void sort();
    ~chain();
};
template <class T>
bool chain<T>::isempty()
{
    if (first == NULL)
        return true;
    else 
        retutn false;
}
template <class t>
void chain<t>::insertatbeg(t x)
{
    node<t> *nn = new node<t>(x); // create a new node and store data
    nn->next = first;             // link first node after newq node
    first = nn;                   // make nn as first node
}
template <class t>
void chain<t>::insertatend(t x)
{
    node<t> *nn = new node<t>(x); // create a new node and store data
    if (first == NULL)            // if list is empty
        first = nn;               // make new node as first node
    else
    {
        node<t> *cur = first; // begin at first node
        while (cur->next)     // move till last node , when cur->next becomes NULL
            cur = cur->next;  // move cur to its next node
        cur->next = nn;       // link nn after last node
    }
}
template <class t>
void chain<t>::insertatpos(t x, int pos)
{
    node<t> *nn = new node<t>(x);
    node<t> *cur = first;
    if (pos == 1) // to insert at first position
    {
        nn->next = first; // or call insertatbeg(x)
        first = nn;
    }
    else // to insert at any other position
    {
        int i;
        for (i = 1; i < pos - 1 && cur->next; i++) // move cur till position-1 node
            cur = cur->next;
        if (cur != NULL) /eppudu/ if(cur), to check valid position or not
        {
            nn->next = cur->next; // link cur node's next node to nn
            cur->next = nn;       // link nn after cur node
        }
        else
        {
            cout << "invalid position,can't insert\n";
        }
    }
    DEPARTMENT OF COMPUTER SCIENCE AND ENGINEERING, MVSREC(A)
}
template <class t>
void chain<t>::display()
{
    if (!isempty()) // if list is not empty
    {
        for (node<t> *cur = first; cur != NULL; cur = cur->next) // move current to each node in the
            list from first node
                    cout
                << cur->data << "\t"; // print the data in cur node
        cout << endl;
    }
    else
    {
        cout << "chain is empty\n";
    }
}
template <class t>
int chain<t>::count()
{
    int c = 0;
    if (!isempty()) // if list is not empty
    {
        for (node<t> *cur = first; cur; cur = cur->next) // traverse each node till the end
            c++;                                         // count the node
    }
    return c;
}
template <class t>
t chain<t>::delfrombeg()
{
    if (!isempty()) // if list is not empty
    {
        node<t> *cur = first; // store first node address in cur
        t x = cur->data;      // take the data that is being deleted into x
        first = first->next;  // move first to first node's next node
        delete cur;           // delete the node
        return x;             // return the deleted data
    }
    else // if the list is empty
    {
        cout << "empty chain,cant delete\n";
        return 0;
    }
}
template <class t>
t chain<t>::delfromend()
{
    if (!isempty()) // if the list is not empty
    {
        node<t> *prev, *cur;
        pg.37 DEPARTMENT OF COMPUTER SCIENCE AND ENGINEERING, MVSREC(A)
                                                                  pg.38 t x;
        for (cur = first; cur->next != NULL; cur = cur->next) // traverse till last node
            prev = cur;                                       // prev is deleting node's previous node, cur is deleting node
        if (first->next == NULL)                              // if there is only one node
            first = NULL;                                     // make the list empty
        else                                                  // otherwise
            prev->next = NULL;                                // make last but one's node next as NULL, so as to delete last node
        x = cur->data;                                        // store deleting node's data in x
        delete cur;                                           // delete the node
        return x;                                             // return the deleted value
    }
    else // if list is empty
    {
        cout << "empty chain,cant delete\n";
        return (0);
    }
}
template <class t>
t chain<t>::delfrompos(int pos)
{
    if (first) // if the list is not empty
    {
        node<t> *prev, *cur;
        t x;
        if (pos == 1) // if given position is 1
        {
            cur = first;         // make cur to point to first node
            first = first->next; // make 2nd node as first node
        }
        else // if position is other than 1
        {
            int i = 1;                                                      // to count the nodes
            for (cur = first; i < pos && cur != NULL; cur = cur->next, i++) // begin at first node, traverse till
                                                                            // pos-1 node
                prev = cur;                                                 // prev is deleting node's previous node, cur is deleting node
            if (cur)                                                        // if cur is not NULL, given pos is valid
                prev->next = cur->next;                                     // link previous node to deleting node's next node
            else
            {
                cout << "invalid position,can't delete\n";
                return 0;
            }
        }
        x = cur->data; // store deleting data in x
        delete cur;    // delete the node
        return x;
    }
    cout << "chain is empty,can't delete\n";
    return 0;
}

template<class t>
t chain<t>::find(int pos)
{
    node<t> *cur = first; // begin at first node
    if (cur != NULL)      // if current node is not NULL
    {
        for (int i = 1; i < pos && cur != NULL; i++) // traverse till given pos node
            cur = cur->next;
        if (cur) // if cur is not NULL , its a valid position
        {
            t x = cur->data; // store the pos node data in x
            return (x);      // return the data
        }
    }
    cout << "invalid positon\n";
    return (0);
}
template <class t>
int chain<t>::search(t key)
{
    int c = 0;            // to count the nodes
    node<t> *cur = first; // start at first node
    while (cur != NULL)   // if cur node is not NULL
    {
        c++;                  // count the node
        if (cur->data == key) // check if the data matches with key
            return (c);       // return the position of the node
        else                  // otherwise
            cur = cur->next;  // move to next node
    }
    cout << "no such data\n";
    return (0);
}
template <class t>
void chain<t>::reverse()
{
    if (first) // if list is not empty
    {
        node<t> *prev = 0, *cur = first; // first node prev is 0, cur points to first node
        while (cur)                      // if current node is not NULL
        {
            node<t> *p = prev; // take prev node into p
            prev = cur;        // take cur node into prev
            cur = cur->next;   // move cur to next node
            prev->next = p;    // make a reverse link
        }
        first = prev; // make first to point to the last node
    }
}
template <class t>
void chain<t>::sort()
{
    if (first)
    {
        node<t> *cur, *prev, *stop = 0;
        while (stop != first)
        {
            cur = first, prev = 0;
            while (cur && cur->next != stop)
            {
                prev = cur;
                cur = cur->next;
                if (prev->data > cur->data)
                {
                    t tmp = prev->data;
                    prev->data = cur->data;
                    cur->data = tmp;
                }
            }
            stop = cur;
        }
    }
    else
        cout << "empty list\n";
}
template <class t>
chain<t>::~chain()
{
    for (node<t> *cur = first; cur; cur = cur->next) // start at first node
    {
        first = first->next; // move first to next node
        delete cur;          // delete the node
        cur = first;         // point cur to first node
    }
}
int main()
{
    chain<int> s1;
    int c, d, p;
    while (1)
    {
        cout << "MENU\t1.insert at begining\t2.insert at end\t3.insert at requird position\t";
        cout << "4.del from begining\t5.del from end\t6.del from position\t7.display\t";
        cout << "8.count no of nodes\t9.reverse\t10.find\t11.search\t12.sort\t13.exit\nSELECT\n";
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
            else
                cout << "list is empty\n";
            break;
        case 5:
            d = s1.delfromend();
            if (d)
                cout << "the deleted data is" << d << endl;
            else
                cout << "list is empty\n";
            break;
        case 6:
            cout << "enter the position to be deleted\n";
            cin >> c;
            d = s1.delfrompos(c);
            if (d)
                cout << "deleted element is: " << d << endl;
            else
                cout << "invalid position\n";
            break;
        case 7:
            s1.display();
            break;
        case 8:
            d = s1.count();
            cout << "the numbr of nodes are" << d << endl;
            break;
        case 9:
            s1.reverse();
            break;
        case 10:
            cout << "enter the location\n";
            cin >> c;
            d = s1.find(c);
            if (d)

                cout << "the value at given position is" << d << endl;
            break;
        case 11:
            cout << "enter the data to be searched\n";
            cin >> d;
            c = s1.search(d);
            if (c)
                cout << "the data is at position" << c << endl;
            break;
        case 12:
            s1.sort();
            break;
        case 13:
            exit(0);
        }
    }
    return 0;
}