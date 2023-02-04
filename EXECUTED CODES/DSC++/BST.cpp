#include <iostream>
#include <stdlib.h>
using namespace std;
template <class t>
class bst;
template <class t>
class node
{
    t element;
    node<t> *left, *right;
    node()
    {
        left = right = NULL;
    }
    node(t x)
    {
        element = x;
        left = right = NULL;
    }
    node(t x, node<t> *l, node<t> *r)
    {
        element = x;
        left = l;
        right = r;
    }
    friend bst<t>;
};
template <class t>
class bst
{
    node<t> *root;

public:
    bst()
    {
        root = NULL;
    }
    void insert(t);
    int search(t);
    void del(t);
    void inorderoutput();
    void inorder(node<t> *);
    void visit(node<t> *x);
};
template <class t>
int bst<t>::search(t key)
{
    node<t> *curr = root;
    while (curr != NULL)
        {
            if (key < curr->element)
                curr = curr->left;
            else if (key > curr->element)
                curr = curr->right;
            else
                return 1;
        }
    return 0;
}
template <class t>
void bst<t>::insert(t key)
{
    node<t> *curr = root, *parent = NULL;
    // to find the posion to insert new element
    while (curr != NULL)
    {
        parent = curr;
        if (key < curr->element)
            curr = curr->left;
        else if (key > curr->element)
            curr = curr->right;
        else
        {
            cout << "key already exists in the tree\n";
            return;
        }
    }
    node<t> *nn = new node<t>(key);
    if (root != NULL) // BST not empty
        if (key < parent->element)
            parent->left = nn;
        else
            parent->right = nn;
    else // BST is empty
        root = nn;
    cout << key << " key inserted successfully\n";
}
template <class t>
void bst<t>::del(t key)
{
    bool found = false;
    if (root == NULL)
    {
        cout << "tree is empty\n";
        return;
    }
    node<t> *curr, *parent = NULL;
    curr = root;
    while (curr != NULL) // to move to every node
    {
        if (curr->element == key)
        {
            found = true;
            break;
        }
        else
        {
            parent = curr;
            if (key > curr->element)
                curr = curr->right;
            else
                curr = curr->left;
        }
    }
    if (curr != NULL) // the key is found
    {
        if (curr->left == NULL && curr->right == NULL) // node has no childern
        {
            if (parent->left == curr) // is the deleeting node is left child of parent
                parent->left = NULL;
            else // is the deleting node is right child of parent
                parent->right = NULL;
            delete curr; // deallocating memory of deleting node
            cout << "key is deleted\n";
            return;
        }
        else if ((curr->left == NULL && curr->right != NULL) || (curr->left != NULL && curr -> right ==NULL)) // Node has single child
        {
            if (curr->left == NULL && curr->right != NULL) // Node has right child
            {
                if (parent->left == curr)
                {
                    parent->left = curr->right;
                    delete curr;
                }
                else // cur node is right child of its parent
                {
                    parent->right = curr->right;
                    delete curr;
                }
            }
            else // Node has Left child
            {
                if (parent->left == curr)
                    {
                        parent->left = curr->left;
                        delete curr;
                    }
                else
                {
                    parent->right = curr->left;
                    delete curr;
                }
            }
            cout << "key is deleted\n";
            return;
        }
        if (curr->left != NULL && curr->right != NULL) // Node has two childern
        {                                              // replacing deleting node value with smallest value in the right subtree
            node<t> *rchild;
            rchild = curr->right;
            if (rchild->left == NULL && rchild->right == NULL) // the deleting node right child is a leaf
            {
                curr->element = rchild->element;
                delete rchild;
                curr->right = NULL;
            }
            else // the deleting node right child is not a leaf
            {
                if (rchild->left != NULL) // then search for min ele in left subtree
                {
                    node<t> *lcurr, *lcurrp;
                    lcurrp = rchild;
                    lcurr = rchild->left;
                    while (lcurr->left != NULL)
                    {
                        lcurrp = lcurr;
                        lcurr = lcurr->left;
                    }
                    curr->element = lcurr->element; // replace del node value with min value
                    lcurrp->left = lcurr->right;
                    delete lcurr;
                }
                else // no left subtree for del node's right child, right child value is the min
                {
                    node<t> *temp;
                    temp = rchild;
                    curr->element = temp->element;
                    curr->right = temp->right;
                    delete temp;
                }
            }
            cout << "key is deleted\n";
            return;
        }
    }
    else
        cout << "key not found\n";
}
template <class t>
void bst<t>::inorderoutput()
{
    inorder(root);
    cout << endl;
}
template <class t>
void bst<t>::inorder(node<t> *root)
{
    if (root != NULL)
    {
        inorder(root->left); // traverse left sub tree in inorder
        visit(root);
        inorder(root->right); // traverse left sub tree in inorder
    }
}
template <class t>
void bst<t>::visit(node<t> *x)
{
    cout << x->element << "->";
}
int main()
{
    bst<int> y;
    int n;
    int key, ch;
    cout << "menu\n 1.insert 2. erase 3.search 4.inorder traversal 5.exit\n";
    cin >> ch;
    while (ch < 5)
    {
        switch (ch)
        {
        case 1:
            cout << "enter key\n";
            cin >> key;
            y.insert(key);
            break;
        case 2:
            cout << "enter key\n";
            cin >> key;

            y.del(key);
        case 3:
            cout << "enter key\n";
            cin >> key;
            n = y.search(key);
            if (n == 0)
                cout << "key not found\n";
            else
                cout << "key found\n";
            break;
        case 4:
            cout << "element in inorder:\n";
            y.inorderoutput();
            break;
        default:
            exit(0);
        }
        cout << "menu\n 1.insert 2. erase 3.search 4.order 5.exit\n";
        cout << "enter your choice : ";
        cin >> ch;
    }
    return 0;
}
/*
Output:
menu
1.insert 2. erase 3.search 4.inorder traversal 5.exit
1
enter key
45
45 key inserted successfully

menu
1.insert 2. erase 3.search 4.order 5.exit
enter your choice : 1
enter key
67
67 key inserted successfully

menu
1.insert 2. erase 3.search 4.order 5.exit
enter your choice : 1
enter key
23
23 key inserted successfully

menu
1.insert 2. erase 3.search 4.order 5.exit
enter your choice : 1
enter key
43
43 key inserted successfully

menu
1.insert 2. erase 3.search 4.order 5.exit
enter your choice : 1
enter key
6
6 key inserted successfully
menu
1.insert 2. erase 3.search 4.order 5.exit
enter your choice : 4
element in inorder:
6->23->43->45->67->
menu
1.insert 2. erase 3.search 4.order 5.exit
enter your choice : 2
enter key
6
key is deleted
menu
1.insert 2. erase 3.search 4.order 5.exit
enter your choice : 4
element in inorder:
23->43->45->67->
menu
1.insert 2. erase 3.search 4.order 5.exit
enter your choice : 3
enter key
43
key found
menu
1.insert 2. erase 3.search 4.order 5.exit
enter your choice : 2
enter key
45
key is deleted
menu
1.insert 2. erase 3.search 4.order 5.exit
enter your choice : 4
element in inorder:
23->43->67->
menu
1.insert 2. erase 3.search 4.order 5.exit
enter your choice : 5*/