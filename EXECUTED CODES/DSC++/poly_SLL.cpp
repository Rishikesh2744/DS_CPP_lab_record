#include <iostream>
#include <cmath>
using namespace std;
class poly;
class nzterm
{
    double coeff; // coefficient
    int exp;      // exponent
    nzterm *next;
    friend poly;

public:
    nzterm(double x, int y)
    {
        coeff = x;
        exp = y;
        next = NULL;
    }
};
class poly
{
    nzterm *first;

public:
    poly() // creates an empty polynomial
    {
        first = NULL;
    }
    void append(nzterm *);
    void create();
    void display();
    double eval(double);
    void add(poly &, poly &);
    void multiply(poly &, poly &);
};
void poly::append(nzterm *nn)
{
    nzterm *cur;
    if (first == NULL) // polyomial is empty
        first = nn;
    else
    {
        cur = first;
        while (cur->next != NULL)
            cur = cur->next;
        cur->next = nn;
    }
}
void poly::create()
{

    nzterm *nn;
    double coef;
    int pow;
    cout << "enter the coefficient value and power value in decreasing order of power and enter coeff value 0 to terminate\n";
    cin >> coef;
    while (coef != 0)
    {
        cin >> pow;
        nn = new nzterm(coef, pow);
        append(nn); // inserts a nzterm at end
        cin >> coef;
    }
}
void poly::display()
{
    nzterm *cur;
    if (first == NULL)
        cout << "no polynomial created\n";
    else
    {
        cur = first;
        while (cur)
        {
            cout << cur->coeff << "x^" << cur->exp;
            if (cur->next != NULL)
                if (cur->next->coeff > 0)
                    cout << "+";
            cur = cur->next;
        }
        cout << endl;
    }
}
double poly::eval(double x) // evaluation of a polynomial for a given value of variable
{
    double sum = 0;
    nzterm *cur;
    cur = first;
    while (cur != NULL)
    {
        sum += cur->coeff * pow(x, cur->exp);
        cur = cur->next;
    }
    return sum;
}
void poly::add(poly &a, poly &b)
{
    nzterm *t1, *t2, *nn;
    double sum;
    t1 = a.first; // adressof first nzterm in pol 1
    t2 = b.first; // address of first nzterm in pol 2
    while (t1 != NULL && t2 != NULL)
    {
        if (t1->exp > t2->exp) // the power in first pol term > than power in second pol term
        {
            nn = new nzterm(t1->coeff, t1->exp);
            append(nn);
            t1 = t1->next;
        }
        else if (t1->exp < t2->exp) // the power in second pol term > than power in first pol term
        {
            nn = new nzterm(t2->coeff, t2->exp);
            append(nn); // term is added to result
            t2 = t2->next;
        }
        else // the powers in both terms are equal
        {
            sum = t1->coeff + t2->coeff; // add coefficients
            if (sum == 0)                // move to the next terms in pols
            {
                t1 = t1->next;
                t2 = t2->next;
            }
            else
            {
                nn = new nzterm(sum, t1->exp);
                nn->next = NULL;
                append(nn);
                t1 = t1->next;
                t2 = t2->next;
            }
        }
    }                  // end of while
    while (t1 != NULL) // is there any term in pol1
    {
        nn = new nzterm(t1->coeff, t1->exp);
        append(nn);
        t1 = t1->next;
    }
    while (t2 != NULL) // is there any term in pol2
    {
        nn = new nzterm(t2->coeff, t2->exp);
        append(nn);
        t2 = t2->next;
    }
}
void poly::multiply(poly &a, poly &b)
{
    nzterm *t1 = a.first;
    nzterm *t2 = b.first;
    nzterm *nn;
    while (t1 != NULL) // take each term in the first polyomial
    {
        poly temp, res;
        while (t2 != NULL) // multiply with all the terms in the second polynomial
        {
            nn = new nzterm(t1->coeff * t2->coeff, t1->exp + t2->exp);
            temp.append(nn);
            t2 = t2->next;
        }
        t2 = b.first;
        res.add(*this, temp);
        *this = res;
        t1 = t1->next;
    }
}
int main()
{
    poly p1, p2, p3, p4;
    int x;
    p1.create();
    p2.create();
    cout << "First polynomial is\n";
    p1.display();
    cout << "Second polynomial is\n";
    p2.display();
    p3.add(p1, p2);
    cout << "sum of given polynomials is:\n ";
    p3.display();
    p4.multiply(p1, p2);
    cout << "Product of given polynomials is:\n";
    p4.display();
    cout << "enter x value for polynomial evaluation\n";
    cin >> x;
    cout << "result of first polynomial: " << p1.eval(x) << endl;
}