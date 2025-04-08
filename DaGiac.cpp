#include "DaGiac.h"
#include <iostream>
#include <cmath>
using namespace std;

// Constructor mặc định
DaGiac::DaGiac() {
    n = 0;
    ds = nullptr;
}

// Constructor với số đỉnh cho trước
DaGiac::DaGiac(int soDinh) {
    n = soDinh;
    ds = new Diem[n];
}

// Destructor: giải phóng bộ nhớ
DaGiac::~DaGiac() {
    delete[] ds;
}

// Nhập các đỉnh của đa giác
void DaGiac::Nhap() {
    cout << "Nhap so dinh cua da giac: ";
    cin >> n;
    ds = new Diem[n]; // Cấp phát động mảng điểm

    for (int i = 0; i < n; ++i) {
        cout << "Nhap dinh thu " << i + 1 << ":\n";
        ds[i].Nhap();
    }
}

// Xuất các đỉnh
void DaGiac::Xuat() const {
    cout << "Da giac co " << n << " dinh: ";
    for (int i = 0; i < n; ++i) {
        ds[i].Xuat();
        if (i != n - 1) cout << ", ";
    }
    cout << endl;
}

// Tính chu vi bằng tổng khoảng cách giữa các đỉnh liên tiếp và khép kín
double DaGiac::TinhChuVi() const {
    double chuVi = 0;
    for (int i = 0; i < n; ++i) {
        chuVi += ds[i].KhoangCach(ds[(i + 1) % n]); // %n để nối kín đa giác
    }
    return chuVi;
}

// Tịnh tiến tất cả các đỉnh
void DaGiac::TinhTien(double x, double y) {
    for (int i = 0; i < n; ++i)
        ds[i].TinhTien(x, y);
}

// Phóng to hoặc thu nhỏ các đỉnh
void DaGiac::PhongToThuNho(double scale) {
    for (int i = 0; i < n; ++i)
        ds[i].PhongToThuNho(scale);
}

// Quay các đỉnh quanh gốc tọa độ
void DaGiac::Quay(double theta) {
    for (int i = 0; i < n; ++i)
        ds[i].Quay(theta);
}
