#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>

using namespace std;

class ThoiGian {
private:
    int ngay, thang, nam;
public:
    ThoiGian();
    ThoiGian(int d, int m, int y);
    void SetTime();
    int GetNam();
    void PrintTime();
};

class NhanVienVP {
private:
    string maSo, hoTen;
    ThoiGian ngaySinh;
    double luong;
public:
    NhanVienVP();
    NhanVienVP(string m, string t, double l);
    void SetMaSo(string m);
    void SetMaSo();
    void SetHoten(string m);
    void SetHoTen();
    void SetNgaySinh(ThoiGian d);
    void SetLuong(double l);
    void SetLuong();
    void SetThongTin();
    string GetMaSo();
    string GetHoTen();
    double GetLuong();
    void GetThongTin();
    ThoiGian GetNgaySinh();

};

class QuanLiNhanVien {
private:
    int soLuongNV;
    vector<NhanVienVP> danhSach;
    double tongTienLuong;
public:
    QuanLiNhanVien();
    void SetSoLuongNV(int n);
    void SetSoLuongNV();
    void SetDanhSach();
    void SetTongTienLuong();
    int GetSoLuongNhanVien();
    int GetTongTienLuong();
    vector<NhanVienVP> GetDanhSach();
    void InDanhSach();
    int NguoiLonTuoiNhat();
    void SapXepTheoLuong();
    int LuongCaoNhat();
    NhanVienVP TruyCapDanhSach(int n);
    void FakeRandomData(int n);
    //void Run();
};
