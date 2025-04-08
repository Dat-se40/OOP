#include "cTamGiac.h"



TamGiac::TamGiac() {};



TamGiac::TamGiac(Diem a, Diem b, Diem c) {

	A = a;

	B = b;

	C = c;

};



void TamGiac::Nhap() {

	cout << "Nhap diem A:\n"; A.Nhap();

	cout << "Nhap diem B:\n"; B.Nhap();

	cout << "Nhap diem C:\n"; C.Nhap();

};



void TamGiac::Xuat() const {

	cout << "Tam giac co cac dinh: ";

	A.Xuat(); cout << ", ";

	B.Xuat(); cout << ", ";

	C.Xuat(); cout << endl;

};



string TamGiac::KiemTraLoai() const {

    double a = B.KhoangCach(C);

    double b = A.KhoangCach(C);

    double c = A.KhoangCach(B);



    if (a + b <= c || a + c <= b || b + c <= a)

        return "Khong phai tam giac";



    if (a == b && b == c)

        return "Tam giac deu";

    if (a == b || b == c || a == c)

        return (a * a + b * b == c * c || a * a + c * c == b * b || b * b + c * c == a * a)

        ? "Tam giac vuong can" : "Tam giac can";

    if (a * a + b * b == c * c || a * a + c * c == b * b || b * b + c * c == a * a)

        return "Tam giac vuong";



    return "Tam giac thuong";

};



double TamGiac::TinhChuVi() const {

    return A.KhoangCach(B) + B.KhoangCach(C) + C.KhoangCach(A);

};



double TamGiac::TinhDienTich() const {

    double a = B.KhoangCach(C);

    double b = A.KhoangCach(C);

    double c = A.KhoangCach(B);

    double p = (a + b + c) / 2;

    return sqrt(p * (p - a) * (p - b) * (p - c));

};



void TamGiac::TinhTien(double x, double y) {

    A.TinhTien(x, y);

    B.TinhTien(x, y);

    C.TinhTien(x, y);

};



void TamGiac::PhongTo(double scale) {

    A.PhongToThuNho(scale);

    B.PhongToThuNho(scale);

    C.PhongToThuNho(scale);

};



void TamGiac::Quay(double theta) {

    A.Quay(theta);

    B.Quay(theta);

    C.Quay(theta);

};