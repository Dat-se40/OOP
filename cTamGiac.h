#pragma once

#include "Diem.h"

#include <string>

class TamGiac

{

private:

	Diem A, B, C;

public:

	TamGiac();

	TamGiac(Diem a, Diem b, Diem c);

	void Nhap();

	void Xuat() const;

	string KiemTraLoai() const;

	double TinhChuVi() const;

	double TinhDienTich() const;

	void TinhTien(double x, double y);

	void PhongTo(double scale);

	void Quay(double theta);

};