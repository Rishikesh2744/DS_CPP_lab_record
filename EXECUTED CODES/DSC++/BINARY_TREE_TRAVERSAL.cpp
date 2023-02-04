#include <iostream>
using namespace std;
// INCLUDING QUEUE CLASS HERE
template <class t>
class Q_linked;
template <class t>
class node
{
    t data;
    node<t> *link;

public:
    node(t x)
    {
        data = x;
        link = NULL;
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
        rear->link = nn;
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
        front = front->link;
        if (front == NULL)
            rear = NULL;
        delete tmp;
        return x;
    }
}
template <class T>
class treenode
{
    T element;
    treenode<T> *left, *right;

public:
    treenode()
    {
        left = right = NULL;
    }
    treenode(T e)
    {
        element = e;
        left = right = NULL;
    }
    treenode(T e, treenode<T> *lc, treenode<T> *rc)
    {
        element = e;
        left = lc;
        right = rc;
    }
    // declaring non memeber functions as friend
    template <class p>
    friend void inorder(treenode<p> *);
    template <class p>
    friend void preorder(treenode<p> *);
    template <class p>
    friend void postorder(treenode<p> *);
    template <class p>
    friend void levelorder(treenode<p> *);
    template <class p>
    friend void visit(treenode<p> *);
};
template <class T>
void visit(treenode<T> *x)
{
    cout << x->element << ' ';
}
template <class T>
void preorder(treenode<T> *t)
{
    if (t != NULL)
    {
        visit(t);
        preorder(t->left);  // do left subtree
        preorder(t->right); // do right subtree
    }
}
template <class T>
void inorder(treenode<T> *t)
{
    if (t != NULL)
    {
        inorder(t->left);  // do left subtree
        visit(t);          // visit tree root
        inorder(t->right); // do right subtree
    }
}
template <class T>
void postorder(treenode<T> *t)
{
    if (t != NULL)
    {
        postorder(t->left);  // do left subtree
        postorder(t->right); // do right subtree
        visit(t);            // visit tree root
    }
}
template <class T>
void levelorder(treenode<T> *t)
{
    Q_linked<treenode<T> *> q;
    while (t != NULL)
    {
        visit(t); // visit t
        // put it's children on queue
        if (t->left != NULL)  // there is left child
            q.push(t->left);  // push the left child ptr
        if (t->right != NULL) // there is right child
            q.push(t->right); // push the right child ptr
        // get next node to visit
        if (!q.isempty())
        {
            t = q.pop();
        }
        else
            return;
    }
}
int main(void)
{
    treenode<int> *n1, *n2, *n3, *n4, *n5;
    n1 = new treenode<int>(24);
    n2 = new treenode<int>(15);
    n3 = new treenode<int>(42, n1, n2);
    n4 = new treenode<int>(53);
    n5 = new treenode<int>(17, n3, n4);
    cout << "Inorder sequence is ";
    inorder(n5);
    cout << endl;
    cout << "Preorder sequence is ";
    preorder(n5);
    cout << endl;
    cout << "Postorder sequence is ";
    postorder(n5);
    cout << endl;
    cout << "Level order sequence is ";
    levelorder(n5);
}
/*
output :
Inorder sequenceis24 42 15 17 53
Preordersequenceis17 42 24 15 53
Postorder sequenceis24 15 42 53 17
Level order sequenceis17 42 53 24 15
*/