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
    int binarysearch(t);
};
template <class t>
void searching<t>::read()
{
    cout << "enter " << n << "elements in ascending order\n";
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
int searching<t>::binarysearch(t key)
{
    int low = 0, high = n - 1, mid;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (key == a[mid])
            break;
        else if (key < a[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    if (low > high)
        return -1;
    else
        return mid + 1;
}
int main()
{
    searching<int> s;
    int key, x;
    s.read();
    s.display();
    cout << "enter key element to be searched\n";
    cin >> key;
    x = s.binarysearch(key);
    if (x == -1)
        cout << "element not found\n";
    else
        cout << "element found at position" << x << endl;
    return 0;
}