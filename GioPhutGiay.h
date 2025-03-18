#pragma once 

#include<iostream>
using namespace std ; 

class GioPhutGiay{
private: 
    int iGio ; 
    int iPhut ;
    int iGiay ;
public: 
    void Nhap();
    void Xuat();
    GioPhutGiay TinhCongThemMotGiay();
};