#pragma once 

#include<iostream>
using namespace std ;

int gcd(int a, int b);
class PhanSo{
private: 
    int iTu; 
    int iMau ;
public: 
    PhanSo(){}
    PhanSo( int t , int m );
    void Nhap();
    void Xuat(); 
    void RutGon();
    PhanSo Tong(PhanSo a );
    PhanSo Hieu( PhanSo a);
    PhanSo Tich( PhanSo a );
    PhanSo Thuong( PhanSo a);
    int SoSanh( PhanSo a); // tra ve be hon
};