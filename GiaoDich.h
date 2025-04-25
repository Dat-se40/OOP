#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;
class GiaoDich
{
protected:
    string ngayGiaoDich;
    string maGiaoDich;
    float donGia;
    int soLuong;
    float thanhTien;

public:
    GiaoDich(string d = " " , string ma = " " , float don = 0  , int so = 0);
    float GetThanhTien();
    void TinhThanhTien();
    void NhapThongTin();
    void XuatThongTin();
};

class GiaoDichVang : public GiaoDich
{
private:
    string loaiVang;
public:
    GiaoDichVang(string d = " " , string ma = " " , float don = 0  , int so = 0,string loai= " ");
    void NhapThongTin();
    void XuatThongTin();
};
const vector<string> loaiTienTe = {"VietNam", "USD", "Euro"};
const vector<float>  tiGiaTienTe = {1,30000,26000};
class GiaoDichTienTe : public GiaoDich
{
private:
    string loai;
    float tiGia;
public:
    GiaoDichTienTe(string d = " " , string ma = " " , float don = 0  , int so = 0, string loai= " ", float tigia = 0 );
    void NhapThongTin() ; 
    void XuatThongTin();
    void TinhThanhTien();
    string GetLoaiTien();
};