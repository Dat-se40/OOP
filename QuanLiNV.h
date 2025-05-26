#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class NhanVien
{
protected:
    string _maNhanVien;
    string _hoTen;
    string _soDienThoai;
    string _email;
    double _luongCoBan;
    double _luong;

public:
    NhanVien(string ma = "", string ten = "" , string phone = "" , string mail ="", double luongCB = 0) ; 
    virtual void NhapThongTin();
    virtual void XuatThongTin();
    virtual void TinhTienLuong();
    double GetTienLuong();
};
class Coder : public NhanVien
{
private:
    double _soGioLamThem;

public:
    Coder(string ma = "", string ten = "" , string phone = "" , 
    string mail ="", double luongCB = 0, double gioLam = 0 ) ; 
    void NhapThongTin();
    void XuatThongTin();
    void TinhTienLuong() override;
};
class Tester : public NhanVien
{
private:
    int _soLoiTimDuoc;
public:
    Tester(string ma = "", string ten = "" , string phone = "" , 
    string mail ="", double luongCB = 0, double soLoi = 0 ) ; 
    void NhapThongTin();
    void XuatThongTin();
    void TinhTienLuong() override;
};
