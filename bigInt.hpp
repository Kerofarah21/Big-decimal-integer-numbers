/*
 * File: bigInt.hpp
 * ---------------
 * This file has the definition of class BigDecimalInt
 *
 * Author:  Kerolos Farah Adeeb / Kareem Ahmed Eltamsah
 * Version: 1.0
 * Date:    30 Oct. 2018
 */

#ifndef _bigInt_hpp
#define _bigInt_hpp

#include <iostream>

class BigDecimalInt
{
private:
    std::string num,newNum;
    int z,k;
    bool overload;
public:
    // Constructor inputs the Big Decimal integer number
    BigDecimalInt(std::string newNum);
    // overload operator + that add two Big Decimal integer number
    BigDecimalInt operator+ (BigDecimalInt anotherDec);
    // overload operator - that sub two Big Decimal integer number
    BigDecimalInt operator- (BigDecimalInt anotherDec);
    // overload operator << that return the Big Decimal integer number
    friend std::ostream& operator<< (std::ostream& out , BigDecimalInt BDI);
};

std::ostream& operator<< (std::ostream& out , BigDecimalInt BDI);
// function check that the elements of the string are all numbers
bool isValid(std::string s);
void getX_Y(std::string& x , std::string& y);
#endif // _bigInt_hpp
