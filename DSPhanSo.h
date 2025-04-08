#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int gcd(int a, int b);
bool laSoNguyenTo(int n);
class PhanSo
{
private:
    int iTu;
    int iMau;

public:
    PhanSo() {}
    PhanSo(int t, int m);
    void Nhap();
    void Xuat();
    void RutGon();
    PhanSo Tong(PhanSo a);
    int SoSanh(PhanSo a) const; // tra ve be hon
    int GetTu() const;
};
class DSPhanSo
{
private:
    int soPhanTu;
    vector<PhanSo> DanhSach;
public:
    void NhapDS();
    void XuatDS();
    PhanSo TimPhanSoMin();
    PhanSo TimPhanSoMax();
    PhanSo TongPhanSo();
    void SapXepTangDan();
    void SapXepGiamDan();
    PhanSo TimPhanSoTuNguyenToMax();
};