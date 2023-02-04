#include<iostream>
using namespace std;

template<class T>
class sorting
{
    int n;
    int i,j;
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
            cout<<"Enter "<<n<<" elements "<<endl;
                for(int i =1;i<=n;i++)
                    cin>>arr[i];
        }

        void display()
        {
            cout<<"Elements after sortinf are "<<endl;
            for(i=1;i<=n;i++)
                cout<<arr[i];
        }

        void insertion_sort()
        {
            int key;
            for(i=2;i<=n;i++)
            {
                key=arr[i];
                for(j=i-1;j>=1&&arr[j]>key;j--)
                    arr[j+1]=arr[j];

                arr[j+1]=key;
            }
        }
};

int main()
{
    sorting<int> s;
    s.read();
    cout<<"Elements before sorting"<<endl;
    s.insertion_sort();
    cout<<"Elements after sorting"<<endl;
    s.display();

    return 0;
}