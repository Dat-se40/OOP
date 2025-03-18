
#pragma once
#include<iostream>

using namespace std; 

class NgayThangNam{
private: 
    int iNgay ; 
    int iThang ; 
    int iNam ; 
    int iGioiHanNgay;
public: 
    void Nhap();
    void Xuat();
    NgayThangNam NgayThangNamTiepTheo();
    bool KiemTraNamNhuan();
    void TinhGioiHanNgay();
};
