// Course:  CS213 - Programming II  - 2018
// Title:   Assignment II - Task 3
// purpose: Add and Sub Big decimal integer numbers
// Author:  Kerolos Farah Adeeb 20170201 / Kareem Ahmed Eltamsah 20170195
// Date:    30 October 2018
// Version: 1.0


#include <iostream>
#include "bigInt.hpp"
using namespace std;


int main()
{
    string x,y;//numbers
    char choose;
    while (true)
    {
        cout << "What do you want to do" << endl;
        cout << "1- X+Y\n2- X-Y\n0- Exit the program" << endl;
        cin >> choose;
        if (choose=='1')
        {
            getX_Y(x,y);
            cout << x << endl << y << endl;
            if (x[0]=='-' && y[0]=='-')//in case that (-x)+(-y)
            {
                x.erase(0,1);
                y.erase(0,1);
                BigDecimalInt n1(x);
                BigDecimalInt n2(y);
                cout << "-" << n1+n2 << endl;//-x+-y == -(x+y)
            }
            else if (x[0]=='-' && y[0]!='-')//in case that (-x)+(y)
            {
                x.erase(0,1);
                BigDecimalInt n1(x);
                BigDecimalInt n2(y);
                cout << n2-n1 << endl;//-x+y == y-x

            }
            else if (x[0]!='-' && y[0]=='-')//in case that (x)+(-y)
            {
                y.erase(0,1);
                BigDecimalInt n1(x);
                BigDecimalInt n2(y);
                cout << n1-n2 << endl;//x+-y == x-y
            }
            else//the default case that x+y
            {
                BigDecimalInt n1(x);
                BigDecimalInt n2(y);
                cout << n1+n2 << endl;
            }
        }
        else if (choose=='2')
        {
            getX_Y(x,y);
            cout << x << endl << y << endl;
            if (x[0]=='-' && y[0]=='-')//in case that (-x)-(-y)
            {
                x.erase(0,1);
                y.erase(0,1);
                BigDecimalInt n1(x);
                BigDecimalInt n2(y);
                cout << n2-n1 << endl;//-x--y == -x+y == y-x
            }
            else if (x[0]=='-' && y[0]!='-')//in case that (-x)-(y)
            {
                x.erase(0,1);
                BigDecimalInt n1(x);
                BigDecimalInt n2(y);
                cout << "-" << n1+n2 << endl;//-x-y == -(x+y)

            }
            else if (x[0]!='-' && y[0]=='-')//in case that (x)-(-y)
            {
                y.erase(0,1);
                BigDecimalInt n1(x);
                BigDecimalInt n2(y);
                cout << n1+n2 << endl;//x--y == x+y
            }
            else//The default case that (x)-(y)
            {
                BigDecimalInt n1(x);
                BigDecimalInt n2(y);
                cout << n1-n2 << endl;
            }
        }
        else if (choose=='0')
            return 0;
        else
        {
            cout << "Please choose from 1,2 or 0 only" << endl;
            cin >> choose;
        }
    }
    return 0;
}
