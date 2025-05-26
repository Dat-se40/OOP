#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<limits> 
using namespace std ; 

class KhachHang{
protected: 
    string _ten ; 
    int _soLuong ;
    double _donGia ;
    const double _vat = 0.1; 
    double _thanhTien ; 
public:
    KhachHang( string ten = "" , int soLg = 0  , float dG = 0 ) ; 
    virtual void NhapThongTin(fstream& reader) ; 
    virtual void XuatThongTin( fstream& writer) ; 
    virtual void TinhThanhTien() = 0 ; 
    double GetThanhTien() ; 
};
class KHBinhThuong : public KhachHang{
public : 
    KHBinhThuong(string ten = "" , int soLg = 0  , float dG = 0 );
    void TinhThanhTien() override; 
};
class KHThanhVien: public KhachHang{
private : 
    int _soNamThanThiet ; 
    double _phanTramKhuyenMai ;
public: 
    KHThanhVien(string ten = "" , int soLg = 0  , float dG = 0, int soNam = 0 );
    void TinhPhanTramKhuyenMai() ;
    void NhapThongTin( fstream& reader)  ; 
    void TinhThanhTien() override; 
};
class KHDacBiet : public KhachHang{
public : 
    KHDacBiet(string ten = "" , int soLg = 0  , float dG = 0) ; 
    void TinhThanhTien() override ;  
};