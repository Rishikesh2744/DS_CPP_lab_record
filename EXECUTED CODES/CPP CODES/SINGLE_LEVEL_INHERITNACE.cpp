#include<iostream>
using namespace std;

class A
{
    public:
        void display1()
        {
            cout<<"Hello";
        }
};

class B:public A
{
   public:
        void display2()
        {
            cout<<"World";
        } 
};

int main()
{
    B b1;
    b1.display1();
    b1.display2();
    return 0;
}