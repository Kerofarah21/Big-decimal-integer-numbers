/*
 * File: bigInt.cpp
 * ---------------
 * This file has the implementation of class BigDecimalInt
 * defined in bigInt.hpp
 *
 * Author:  Kerolos Farah Adeeb / Kareem Ahmed Eltamsah
 * Version: 1.0
 * Date:    30 Oct. 2018
 */

#include <iostream>
#include "bigInt.hpp"
using namespace std;

BigDecimalInt::BigDecimalInt(std::string newNum)
{
    num = newNum;
}

BigDecimalInt BigDecimalInt::operator+ (BigDecimalInt anotherDec)
{
    BigDecimalInt newDec("1");
    newNum.erase();
    overload = false;
    z = num.length() - anotherDec.num.length();
    if (z<0)
    {
        z*=-1;
        for (int i=1 ; i<=z ; i++)
        {
            newNum+="0";
        }
        newNum+=num;
        z = newNum.length() - anotherDec.num.length();
    }
    else
        newNum+=num;
    for (int i=newNum.length()-1 ; i>=z ; i--)
    {
        if ((int(newNum[i])-48+int(anotherDec.num[i-z])-48)<10)
            newNum[i] = char((int(newNum[i])-48+int(anotherDec.num[i-z])-48)+48);
        else if ((int(newNum[i])-48+int(anotherDec.num[i-z])-48)>9)
        {
            newNum[i] = char((int(newNum[i])-48+int(anotherDec.num[i-z])-48)-10+48);
            if (i==0)
            {
                overload=true;
                break;
            }
            int index=i;
            if (int(newNum[index-1]+1)-48<10)
                newNum[index-1]+=1;
            else
            {
                while (int(newNum[index-1]+1)-48>9)
                {
                    newNum[index-1]='0';
                    index--;
                    if (index==0)
                    {
                        overload=true;
                        break;
                    }
                }
                if (index!=0)
                    newNum[index-1]+=1;
            }
        }
    }
    if (overload)
    {
        newDec.num+=newNum;
        return newDec;
    }
    else
        return newNum;
}
BigDecimalInt BigDecimalInt::operator- (BigDecimalInt anotherDec)
{
    BigDecimalInt newDec("-");
    newNum.erase();
    overload = false;

    z = num.length() - anotherDec.num.length();
    if (z<0 || z==0)
    {
        if (z<0)
        {
            swap(num,anotherDec.num);
            overload=true;
            newNum=num;
            z = newNum.length() - anotherDec.num.length();
        }
        else if (z==0)
        {
            for (int i=0 ; i<num.length() ; i++)
            {
                if (num[i]<anotherDec.num[i])
                {
                    swap(num,anotherDec.num);
                    overload=true;
                    newNum=num;
                    break;
                }
                else if (num[i]>anotherDec.num[i])
                {
                    newNum=num;
                    break;
                }
                else
                    continue;
            }
            newNum=num;
        }
    }
    else
        newNum=num;
    for (int i=newNum.length()-1 ; i>=z ; i--)
    {
        if ((int(newNum[i])-48)-(int(anotherDec.num[i-z])-48)>=0)
            newNum[i] = char((int(newNum[i])-48)-(int(anotherDec.num[i-z])-48)+48);
        else if ((int(newNum[i])-48)-(int(anotherDec.num[i-z])-48)<0)
        {
            newNum[i] = char((int(newNum[i])-48)-(int(anotherDec.num[i-z])-48)+10+48);
            if (i==0)
            {
                overload=true;
                break;
            }
            int index=i;
            if (int(newNum[index-1]-1)-48>=0)
                newNum[index-1]-=1;
            else
            {
                while (int(newNum[index-1]-1)-48<0)
                {
                    newNum[index-1]='9';
                    index--;
                    if (index==0)
                    {
                        overload=true;
                        break;
                    }
                }
                if (index!=0)
                    newNum[index-1]-=1;
            }
        }
    }
    while (newNum[0]=='0' && newNum.length()!=1)
        newNum.erase(0,1);
    if (overload)
    {
        newDec.num+=newNum;
        return newDec;
    }
    else
        return newNum;
}
std::ostream& operator<< (std::ostream& out , BigDecimalInt BDI)
{
    for (int i=0 ; i<BDI.num.length() ; i++)
        out << BDI.num[i];
    return out;
}

bool isValid(std::string s)
{
    bool x=false;
    for (int i=0 ; i<s.length() ; i++)
    {
        if ((int(s[i])>=48 && int(s[i])<=57) || (int(s[0]==45) && i==0))
        {
            x=true;
        }
        else
        {
            x=false;
            break;
        }
    }
    return x;
}
void getX_Y(std::string& x , std::string& y)
{
    cout << "Enter X: ";
    cin >> x;
    while (isValid(x)==false)
    {
        cout << "Enter a valid number (ONLY number and \"-\" sign" << endl;
        cout << "Enter X: ";
        cin >> x;
    }
    cout << "Enter Y: ";
    cin >> y;
    while (isValid(y)==false)
    {
        cout << "Enter a valid number (ONLY number and \"-\" sign" << endl;
        cout << "Enter Y: ";
        cin >> y;
    }
}
