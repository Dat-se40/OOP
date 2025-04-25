#include "GiaoDich.h"
// ====== Class GiaoDich ===== //
GiaoDich::GiaoDich(string d, string ma, float don, int so)
    : ngayGiaoDich(d), maGiaoDich(ma), donGia(don), soLuong(so), thanhTien(0) {}
float GiaoDich::GetThanhTien()
{
    return thanhTien;
}
void GiaoDich::TinhThanhTien()
{
    thanhTien = soLuong * donGia;
}
void GiaoDich::NhapThongTin()
{
    cout << "Nhap ma giao dich:";
    getline(cin, maGiaoDich);
    cout << "Ngay giao dich: ";
    getline(cin, ngayGiaoDich);
    cout << "Nhap so luong giao dich: ";
    cin >> soLuong;
    cout << "Nhap so don giao moi giao dich: ";
    cin >> donGia;
    TinhThanhTien();
}
void GiaoDich::XuatThongTin()
{
    cout << "Giao dich duoc thu hien vao ngay " << ngayGiaoDich << "\n";
    cout << "Ma giao dich: " << maGiaoDich << ", don gia moi lan giao dich: " << donGia;
    cout << ", so luong cac giao dich: " << soLuong << "\n";
}
// ===== GiaoDichTienTe ===== = //
GiaoDichTienTe::GiaoDichTienTe(string d , string ma  , float don , int so ,string loai,float tigia): 
    GiaoDich(d,ma,don,so) , loai(loai) ,tiGia(tigia) {}
void GiaoDichTienTe::NhapThongTin()
{
    GiaoDich::NhapThongTin();
    int choose;
    do
    {
        cout << "Chon loai tien te : 1-VietNam , 2-USD , 3-Euro. ";
        cin >> choose;
    } while (choose <= 0 || choose > 3);
    loai = loaiTienTe[choose - 1];
    tiGia = tiGiaTienTe[choose - 1];
}
void GiaoDichTienTe::XuatThongTin()
{
    GiaoDich::XuatThongTin();
    cout << "Loai tien te: " << loai << ", ti gia: " << tiGia<<endl;
    cout <<"Gia tri giao dich (Thanh Tien): "<<thanhTien<<"\n" ;  
}
void GiaoDichTienTe::TinhThanhTien()
{
    GiaoDich::TinhThanhTien();
    if (loai != loaiTienTe[0])
    {
        thanhTien *= tiGia;
    }
}
string GiaoDichTienTe::GetLoaiTien(){
    return loai ; 
}
// ===== GiaoDichVang ===== //
GiaoDichVang::GiaoDichVang(string d, string ma, float don, int so ,string loai ):
    GiaoDich(d,ma,don,so) , loaiVang(loai) {}
void GiaoDichVang::NhapThongTin(){
    GiaoDich::NhapThongTin();
    cout<<"Nhap loai vang: " ; 
    cin>>loaiVang ; 
}
void GiaoDichVang::XuatThongTin(){
    GiaoDich::XuatThongTin() ; 
    cout<<"Loai vang dung de giao dich: "<<loaiVang<<"\n";
    cout <<"Gia tri giao dich (Thanh Tien): "<<thanhTien<<"\n" ;  
}
