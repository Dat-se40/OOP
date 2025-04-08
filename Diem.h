// Lớp Điểm

#pragma once

#include <iostream>
#include <cmath>
using namespace std;



class Diem

{

protected:

	double dx, dy;

public:

	Diem();

	Diem(double x, double y);

	void Nhap();

	void Xuat() const;

	double KhoangCach(const Diem& d) const;

	void TinhTien(double x, double y);

	void PhongToThuNho(double scale);

	void Quay(double theta);

};