//
//  upDate.hpp
//  CECS282_Program4
//
//  Created by Jasmin Agustin on 3/14/17.
//  Copyright © 2017 Jasmin Agustin. All rights reserved.
//

#ifndef upDate_hpp
#define upDate_hpp

#include <iostream>
using namespace std;

int Greg2Julian(int M, int D, int Y);
void Julian2Greg(int JD, int & M, int & D, int & Y);

class upDate{
    
private:
    int *dptr;
    static int count;
    
public:
    upDate();//default constructor
    upDate(int M, int D, int Y);//overload constructor
    ~upDate();//destructor
    void setDate(int M, int D, int Y);
    int getMonth();
    int getDay();
    int getYear();
    string getMonthName();
    
    void incrDate(int x);
    upDate operator+(int x);//D1+4
    friend upDate operator+(int x, upDate D);//4+D1
    upDate operator++(int x);//D1++
    upDate operator++();//++D1
    
    void decrDate(int x);
    int operator-(upDate D);//D1-D2
    upDate operator-(int x);//D1-4
    upDate operator--(int x);//D1--
    upDate operator--();//--D1
    
    void operator=(const upDate & D);//D1 = D2
    bool operator==(upDate D);//D1 == D2
    bool operator<(upDate D);//D1 < D2
    bool operator>(upDate D);//D1 > D2
    int julian();
    upDate(const upDate & D);//copy constructor
    static int getDateCount();//return number of objects
    friend ostream & operator<<(ostream & out, upDate D);//output objects in main
    
    bool isLeapYear();
    int daysInMonth(int M);
};

#endif
