#include<iostream>
using namespace std;

template<class T>
class Sorting
{
    int n;
    T *arr;
    public:
        Sorting()
        {
            cout<<"Size : "<<endl;
            cin>>n;
            arr=new int[n];
        }

        void read()
        {
            cout<<"enter "<<n<<"elements\n";
                for(int i=1;i<=n;i++)
                {
                    cin>>arr[i];
                }
        }

        void display()
        {
            cout<<"Elements after sorting are "<<endl;
                for(int i=1;i<=n;i++)
                    cout<<arr[i]<<"\t";
        }
}