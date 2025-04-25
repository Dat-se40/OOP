#include <iostream>
#include <string>
#include <vector>
using namespace std;

class GiaoDich
{
protected:
    string ngayGiaoDich;
    string maGiaoDich;
    double donGia;
    double dienTich;
    double thanhTien;

public:
    GiaoDich(string d = " " , string m = " " , double dg = 0 , double dt = 0 );
    void NhapThongTin();
    void XuatThongTin();
    void TinhThanhTien();
    double GetThanhTien();
    string GetNgayGiaoDich();
};
const vector<char> cacLoaiDat = {'A', 'B', 'C'};

class GiaoDichhDat : public GiaoDich
{
private:
    char loaiDat;

public:

    GiaoDichhDat(string d = " " , string m = " " , double dg = 0 , double dt = 0 , char t =' ');
    void NhapThongTin();
    void XuatThongTin();
    void TinhThanhTien();
};

const vector<string> cacLoaiNha = {"Thuong","Cao Cap"};
class GiaoDichNhaPho : public GiaoDich
{
private:
    string diaChi;
    string loaiNha ; 
public:
    GiaoDichNhaPho(string d = " " , string m = " " , double dg = 0 , 
        double dt = 0 , string address =" ", string type =" ");
    void NhapThongTin();
    void XuatThongTin();
    void TinhThanhTien();
};
class GiaoDichChungCu : public GiaoDich
{
private:
    string maCan;
    int viTriTang;

public:
    GiaoDichChungCu(string d = " ", string m =" ",double dg = 0 ,
        double dt =0  , string mc =  " "  , int pos = 0 );
    void NhapThongTin();
    void XuatThongTin();
    void TinhThanhTien();
};
