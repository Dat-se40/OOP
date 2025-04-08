#include "Diem.h"

#include "cTamGiac.h"

int main()
{

		Diem a;

		a.Nhap();

		Diem b(3, 4);

		double kc = a.KhoangCach(b);

		cout <<"Khoang cach giua 2 diem";
		a.Xuat() ; 
		cout<<" va ";
		b.Xuat() ; 
		cout<<": "<<kc<<endl;

		TamGiac tg;

		tg.Nhap();

		tg.Xuat();

		tg.TinhTien(1, 2);

		tg.Xuat();

		tg.PhongTo(2);

		tg.Xuat();

		tg.Quay(90);

		tg.Xuat();

		cout<<"Day la tam giac "<<tg.KiemTraLoai()<<endl ;
		cout<<"Chu vi tam giac: "<<tg.TinhChuVi()<<endl ; 
		cout<<"Dien tich tam giac: "<<tg.TinhDienTich()<<endl ; 

	return 0;
}