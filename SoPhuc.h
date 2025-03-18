#pragma once 

#include<iostream>
using namespace std ; 

class SoPhuc{
private: 
    float iAo ;
    float iThuc ; 
public:
    SoPhuc(){}
    SoPhuc( float u , float v) ;

    void Nhap();
    void Xuat();
    SoPhuc Tong(SoPhuc a);
    SoPhuc Hieu(SoPhuc a);
    SoPhuc Tich(SoPhuc a);
    SoPhuc Thuong(SoPhuc a);
};