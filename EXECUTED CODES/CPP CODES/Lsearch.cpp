#include <iostream>
using namespace std;
template <class t>
class searching
{
    t *a;
    int n;

public:
    searching()
    {
        cout << "enter no.of array elements: ";
        cin >> n;
        a = new t[n];
    }
    void read();
    void display();
    int linearsearch(t);
};
template <class t>
void searching<t>::read()
{
    cout << "enter " << n << "elements\n";
    for (int i = 0; i < n; i++)
        cin >> a[i];
}
template <class t>
void searching<t>::display()
{
    cout << "Array elements\n";
    for (int i = 0; i < n; i++)
        cout << a[i] << "\t";
    cout << "\n";
}
template <class t>
int searching<t>::linearsearch(t key)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (key == a[i])
            break;
    }
    if (i == n)
        return -1;
    else
        return i + 1;
}
nt main()
{
    searching<int> s;
    int key;
    s.read();
    s.display();
    cout << "enter key element\n";
    cin >> key;
    int x = s.linearsearch(key);
    if (x == -1)
        cout << "element not found\n";
    else
        cout << "element found at position " << x << endl;
    return 0;
}