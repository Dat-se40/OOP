#ifndef NHANVIENSX_H
#define NHANVIENSX_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class ThoiGian {// Class phụ sử dụng để tính ngày
private:
    int ngay, thang, nam;

public:
    ThoiGian();
    ThoiGian(int d, int m, int y);
    
    int GetNam();
    void SetTime();
    void PrintTime();
};

class NhanVienSX { // Class Nhân Viên Sản Xuất
private:
    string maSo, hoTen;
    ThoiGian ngaySinh;
    int soSanPham;
    double giaTien, luong;

public:
    NhanVienSX();
    NhanVienSX(string t, string m, ThoiGian tm, int s, double g);

    void SetThongTin();
    void SetLuong();
    string GetMaSo();
    string GetHoTen();
    ThoiGian GetNgaySinh();
    int GetSoSanPham();
    int GetGiaSanPham();
    double GetLuong();
    
    void GetThongTin();
};

class QuanLiNhanVien { // Class quản lí danh sách nhân viên SX
private:
    int soLuongNV;
    vector<NhanVienSX> danhSach;
    double tongTienLuong;

public:
    QuanLiNhanVien();

    void SetSoLuongNV();
    void SetDanhSach();
    void SetTongTienLuong();
    
    int GetSoLuongNhanVien();
    int GetTongTienLuong();
    vector<NhanVienSX> GetDanhSach();
    
    void InDanhSach();
    int NguoiLonTuoiNhat();
    void SapXepTheoLuong();
    int LuongCaoNhat();
    NhanVienSX TruyCapDanhSach(int n);
    void FakeRandomData(int n);
    void Run();
};

#endif
