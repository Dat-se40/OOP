#include "KhachHang.h"

//============ class KhachHang ======== .// 
KhachHang::KhachHang( string ten , int soLg, float dG  ) :
    _ten(ten), _soLuong(soLg) , _donGia(dG)   {}
    
void KhachHang::NhapThongTin(fstream& reader){
    // Sử dụng ignore với số lượng ký tự lớn và delimiter là '\n'
    reader.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(reader, _ten);
    reader >> _soLuong; 
    reader >> _donGia;  
}

void KhachHang::XuatThongTin(fstream& writer){
    writer<<"Ten khach hang: "<<_ten<<endl; 
    writer<<"-> So tien phai tra: "<<_thanhTien<<endl ; 
}

double KhachHang::GetThanhTien(){
    return _thanhTien ; 
}

//========= class KHBthg ======= //
KHBinhThuong::KHBinhThuong(string ten , int soLg, float dG ) : 
    KhachHang(ten,soLg,dG) {}
    
void KHBinhThuong::TinhThanhTien(){
    _thanhTien = _soLuong*_donGia*(1+ _vat); 
} 

//======= class KHThanhVien =========== //
KHThanhVien::KHThanhVien(string ten , int soLg, float dG , int soNam):
    KhachHang(ten,soLg,dG) , _soNamThanThiet(soNam){}
    
void KHThanhVien::NhapThongTin(fstream& reader){
    KhachHang::NhapThongTin(reader);
    reader >> _soNamThanThiet;
}

void KHThanhVien::TinhPhanTramKhuyenMai(){
    _phanTramKhuyenMai = max(_soNamThanThiet*0.05 , 0.5);
}

void KHThanhVien::TinhThanhTien(){
    this->TinhPhanTramKhuyenMai();
    _thanhTien = _soLuong*_donGia*(1+ _vat)*(1- _phanTramKhuyenMai); 
}

//==== class KHDacbiet ======= //
KHDacBiet::KHDacBiet(string ten , int soLg, float dG ) : 
    KhachHang(ten,soLg,dG) {}
    
void KHDacBiet::TinhThanhTien(){
    _thanhTien = _soLuong*_donGia*0.5*(1+ _vat); 
}