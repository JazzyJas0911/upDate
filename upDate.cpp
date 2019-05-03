//
//  upDate.cpp
//  CECS282_Program4
//
//  Created by Jasmin Agustin on 3/14/17.
//  Copyright © 2017 Jasmin Agustin. All rights reserved.
//

#include "upDate.hpp"

#include <iostream>
using namespace std;

int upDate:: count = 0;

int Greg2Julian(int M, int D, int Y){
    int I = Y;
    int J = M;
    int K = D;
    
    int JD = K-32075+1461*(I+4800+(J-14)/12)/4+367*(J-2-(J-14)/12*12)/12-3*((I+4900+(J-14)/12)/100)/4;
    
    return JD;
}

void Julian2Greg(int JD, int & M, int & D, int & Y){
    int L = JD+68569;
    int N = 4*L/146097;
    L = L-(146097*N+3)/4;
    int I = 4000*(L+1)/1461001;
    L = L-1461*I/4+31;
    int J = 80*L/2447;
    int K = L-2447*J/80;
    L = J/11;
    J = J+2-12*L;
    I = 100*(N-49)+I+L;
    
    Y = I;
    M = J;
    D = K;
}



upDate:: upDate(){
    dptr = new int [3];
    dptr[0] = 5;
    dptr[1] = 11;
    dptr[2] = 1959;
    count++;
}

upDate:: upDate(int M, int D, int Y){
    dptr = new int [3];
    if((M > 0 && M < 13) && (D > 0 && D <= daysInMonth(M)) && (Y > 0 && Y < 32768)){
        dptr[0] = M;
        dptr[1] = D;
        dptr[2] = Y;
    }
    else{
        dptr[0] = 5;
        dptr[1] = 11;
        dptr[2] = 1959;
    }
    count++;
}

upDate:: ~upDate(){
    delete []dptr;
    count--;
}

void upDate:: setDate(int M, int D, int Y){
    dptr = new int [3];
    dptr[0] = M;
    dptr[1] = D;
    dptr[2] = Y;
    count++;
}

int upDate:: getMonth(){
    return dptr[0];
}

int upDate:: getDay(){
    return dptr[1];
}

int upDate:: getYear(){
    return dptr[2];
}

string upDate:: getMonthName(){
    string months[13] = {"error", "January", "Feburary", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"};
    return months[dptr[0]];
}



void upDate:: incrDate(int x){
    int nDays = x;
    int dateG2J = Greg2Julian(dptr[0], dptr[1], dptr[2]);
    int incrementDate = dateG2J + nDays;
    int m, d, y;
    Julian2Greg(incrementDate, m, d, y);
    dptr[0] = m;
    dptr[1] = d;
    dptr[2] = y;
}

upDate upDate:: operator+(int x){
    upDate temp(*this);
    temp.incrDate(x);
    return temp;
}

upDate operator+(int x, upDate D){
    D.incrDate(x);
    return D;
}

upDate upDate:: operator++(int x){
    upDate temp(*this);
    incrDate(1);
    return temp;
}

upDate upDate:: operator++(){
    upDate temp(*this);
    incrDate(1);
    return *this;
}



void upDate:: decrDate(int x){
    int nDays = x;
    int dateG2J = Greg2Julian(dptr[0], dptr[1], dptr[2]);
    int decrementDate = dateG2J - nDays;
    int m, d, y;
    Julian2Greg(decrementDate, m, d, y);
    dptr[0] = m;
    dptr[1] = d;
    dptr[2] = y;
}

int upDate:: operator-(upDate D){
    int JD1 = Greg2Julian(dptr[0], dptr[1], dptr[2]);
    int JD2 = Greg2Julian(D.getMonth(), D.getDay(), D.getYear());
    int nDaysBetween = JD1 - JD2;
    return nDaysBetween;
}

upDate upDate:: operator-(int x){
    upDate temp(*this);
    temp.decrDate(x);
    return temp;
}

upDate upDate:: operator--(int x){
    upDate temp(*this);
    decrDate(1);
    return temp;
}

upDate upDate:: operator--(){
    upDate temp(*this);
    decrDate(1);
    return *this;
}



void upDate:: operator=(const upDate & D){
    dptr = new int [3];
    dptr[0] = D.dptr[0];
    dptr[1] = D.dptr[1];
    dptr[2] = D.dptr[2];
}

bool upDate:: operator==(upDate D){
    if((dptr[0] == D.dptr[0]) && (dptr[1] == D.dptr[1]) && (dptr[2] == D.dptr[2]))
        return true;
    else
        return false;
}

bool upDate:: operator<(upDate D){
    if((dptr[2] < D.dptr[2]) || ((dptr[2] == D.dptr[2])&&(dptr[0] < D.dptr[0]))
       || ((dptr[2] == D.dptr[2])&&(dptr[0] == D.dptr[0])&&(dptr[1] < D.dptr[1])))
        return true;
    else
        return false;
}

bool upDate:: operator>(upDate D){
    if((dptr[2] > D.dptr[2]) || ((dptr[2] == D.dptr[2])&&(dptr[0] > D.dptr[0]))
       || ((dptr[2] == D.dptr[2])&&(dptr[0] == D.dptr[0])&&(dptr[1] > D.dptr[1])))
        return true;
    else
        return false;
}

int upDate:: julian(){
    int J = dptr[0];
    int K = dptr[1];
    int I = dptr[2];
        
    int JD = K-32075+1461*(I+4800+(J-14)/12)/4+367*(J-2-(J-14)/12*12)/12-3*((I+4900+(J-14)/12)/100)/4;
    
    return JD;
}

upDate:: upDate(const upDate & D){
    dptr = new int [3];
    dptr[0] = D.dptr[0];
    dptr[1] = D.dptr[1];
    dptr[2] = D.dptr[2];
    count++;
}

int upDate:: getDateCount(){
    return count;
}

ostream & operator<<(ostream & out, upDate D){
    out << D.dptr[0] << "/" << D.dptr[1] << "/" << D.dptr[2];
    return out;
}



bool upDate:: isLeapYear(){
    if(dptr[2] % 400 == 0)
        return true;
    else if(dptr[2] % 100 == 0)
        return false;
    else if(dptr[2] % 4 == 0)
        return true;
    else
        return false;
}

int upDate:: daysInMonth(int M){
    int nDays[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(isLeapYear() == true)
        nDays[2] = 29;
    return nDays[M];
}
