#include<iostream>
using namespace std;

class A
{
    public:
        void display1()
        {
            cout<<"Hello ";
        }
};

class B:public A
{
   public:
        void display2()
        {
            cout<<"World ";
        } 
};

class C:public A
{
   public:
        void display3()
        {
            cout<<"people ";
        } 
};

int main()
{
    B b1;
    C c1;
    b1.display1();
    b1.display2();
    c1.display1();
    c1.display3();
    return 0;
}