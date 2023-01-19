#include<iostream>
using namespace std;

template<class T>
class sorting
{
    int n;
    T *arr;
    public:
        sorting()
        {
            cout<<"size"<<endl;
            cin>>n;
            arr=new int[n];
        }

        void read()
        {
            cout<<"enter "<<n<<"elements"<<endl;
                for(int i =1;i<=n;i++)
                    cin>>arr[i];
        }

        void display()
        {
            cout<<"elements after sortinf are "<<endl;
            for(int i=1;i<=n;i++)
                cout<<arr[i];
        }

        void insertion_sort()
        {
            int key;
            for(int i=2;i<=n;i++)
            {
                key=arr[i];
                for(int j=i-1;j>=1&&arr[j]>key;j--)
                    arr[j+1]=arr[j];

                arr[j+1]=key;
            }
        }
};

int main()
{
    sorting<int> s;
    s.read();
    cout<<"\n Elements before sorting"<<endl;
    s.insertion_sort();
    cout<<"\n Elements after sorting"<<endl;
    s.display();

    return 0;
}