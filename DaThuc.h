#pragma once
#include<iostream>
#include<vector>
#include<cmath>
using namespace std; 

class HangTu{ // Hạng tử dùng để bổ trợ cho DaThuc
    float iHeSo ; 
    int iBac ; 
    friend class DaThuc;
public:
    HangTu(){}
    HangTu( float h , int b );
    friend ostream& operator<<(ostream &out , const HangTu &h);
};
class DaThuc{
    int iBacCaoNhat; 
    vector<HangTu> iHam ; 
    double iGiaTri;
    float x0 ; 
public: 
    DaThuc(): iBacCaoNhat(0) , iGiaTri(0) , x0(0) {}

    void NhapDaThuc(); // Xuất đa thức
    void XuatDaThuc(); // Nhập đa thức
    void TinhGiaTri(); // Tính giá trị f(x0)
    double NhanGiaTri(); // Trả về giá trị f(x0)

    DaThuc operator+( const DaThuc other) const;// Phép cộng 2 đa thức
    DaThuc operator-(const DaThuc other) const;// Phép trừ 2 đa thức

};


