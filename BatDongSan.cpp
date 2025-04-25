#include "BatDongSan.h"
//====== class GiaoDich =====//
GiaoDich::GiaoDich(string d , string m , double dg , double dt ): 
    ngayGiaoDich(d), maGiaoDich(m) , donGia(dg) , dienTich(dt) {}

void GiaoDich::NhapThongTin(){
    cout << "Nhap ma giao dich:";
    getline(cin, maGiaoDich);
    cout << "Ngay giao dich: ";
    getline(cin, ngayGiaoDich);
    cout << "Nhap so don giao moi giao dich cho moi met vuong mat ban: ";
    cin >> donGia;
    cout <<" Nhap tong dien tich giao dich: ";
    cin >> dienTich ;
}
void GiaoDich::XuatThongTin(){
    cout << "Giao dich duoc thu hien vao ngay " << ngayGiaoDich << "\n";
    cout << "Ma giao dich: " << maGiaoDich << ", don gia moi lan giao dich: " << donGia<<endl;
    cout <<"Tong dien tich mat ban "<<dienTich<<"\n" ; 
}
void GiaoDich::TinhThanhTien(){
    thanhTien = dienTich*donGia ; 
}
double GiaoDich::GetThanhTien(){
    return thanhTien ; 
}
string GiaoDich::GetNgayGiaoDich(){
    return this->ngayGiaoDich;
}
//====== Class GiaoDichDat ====== //
GiaoDichhDat::GiaoDichhDat(string d, string m , double dg , double dt, char t)
:GiaoDich(d,m,dg,dt), loaiDat(t){}
void GiaoDichhDat::NhapThongTin(){
    GiaoDich::NhapThongTin() ; 
    int choose ; 
    do{
        cout<<"Nhap loai dat( 1.A - 2.B - 3.C): ";
        cin>>choose ; 
    }while(choose < 1 || choose > 3);
    loaiDat = cacLoaiDat[choose-1];
}
void GiaoDichhDat::TinhThanhTien(){
    GiaoDich::TinhThanhTien();
    if( loaiDat = 'A') thanhTien *= 0.5 ;
}
void GiaoDichhDat::XuatThongTin(){
    GiaoDich::XuatThongTin() ; 
    cout<<"\nDat thuoc loai: "<<loaiDat<<", co tong gia tri: "<<thanhTien<<endl ; 
}
// ====== GiaoDichNha ======= ///
GiaoDichNhaPho::GiaoDichNhaPho(string d , string m , double dg,double dt , string address , string type)
        :GiaoDich(d,m,dg,dt), diaChi(address) , loaiNha(type){}
void GiaoDichNhaPho::NhapThongTin(){
    GiaoDich::NhapThongTin() ;
    cout<<"Nhap dia chi nha";
    cin>>diaChi ; 

    int choose ; 
    do{
        cout<<"Nhap loai nha( 1.Thuong - 2.Cao Cap): ";
        cin>>choose ; 
    }while(choose < 1 || choose > 2);
    loaiNha = cacLoaiNha[choose-1];
}
void GiaoDichNhaPho::XuatThongTin(){
    GiaoDich::XuatThongTin() ; 
    cout<<"Nha loai "<<loaiNha<<", dia chi hien tai: "<<diaChi<<"\n";
}
void GiaoDichNhaPho::TinhThanhTien(){
    GiaoDich::TinhThanhTien() ;
    if( loaiNha == "Thuong") thanhTien = thanhTien*0.9 ; 
}
// ====== Class GiaoDichChungCu ======= ///
GiaoDichChungCu::GiaoDichChungCu(string d , string m ,double dg ,double dt  , string mc  , int pos )
        :GiaoDich(d,m,dg,dt),maCan(mc),viTriTang(pos){}
void GiaoDichChungCu::NhapThongTin(){
    GiaoDich::NhapThongTin() ; 
    cout<<"Ma can nha: "; 
    cin>>maCan ; 
    cout<<"Nha o tang nao: ";
    cin>>viTriTang ;    
}
void GiaoDichChungCu::XuatThongTin(){
    GiaoDich::XuatThongTin() ; 
    cout<<" ma can: "<<maCan<<", nha o tang "<<viTriTang<<"\n";
}
void GiaoDichChungCu::TinhThanhTien(){
    GiaoDich::TinhThanhTien();
    if ( viTriTang == 1) thanhTien*=2 ; 
    else if ( thanhTien >= 15) thanhTien *=1.2 ; 
}