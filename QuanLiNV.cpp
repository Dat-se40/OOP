#include "QuanLiNV.h"
#include <ctime> 
#include <iomanip>
#include <sstream>

string formatMoney(double amount)
{// Fomat lai tien VND
    stringstream ss;
    ss << fixed << setprecision(0) << amount; // Không hiển thị phần thập phân
    string str = ss.str();

    // Hien thi du cai chung so
    int insertPosition = str.length() - 3;
    while (insertPosition > 0)
    {
        str.insert(insertPosition, ",");
        insertPosition -= 3;
    }
    return str + " VND";
}

// ====== Nhan Vien ====== //
NhanVien::NhanVien(string ma, string ten, string phone, string mail, double luongCB) : _maNhanVien(ma), _hoTen(ten), _soDienThoai(phone), _email(mail), _luongCoBan(luongCB)
{
    _luong = 0;
}

void NhanVien::NhapThongTin()
{
    cout << "Nhap ma nhan vien:";
    cin >> _maNhanVien;
    cout << "Nhap ho va ten:";
    cin.ignore();
    getline(cin, _hoTen);
    cout << "Nhap so dien thoai: ";
    cin >> _soDienThoai;
    cout << "Nhap email cua nhan vien: ";
    cin >> _email;
    cout << "Nhap luong co ban: ";
    cin >> _luongCoBan;
}
void NhanVien::XuatThongTin()
{
    cout << "nhan vien: " << _hoTen << ", ma nhan vien: " << _maNhanVien << "\n";
    cout << "Thong tin lien lac: " << _soDienThoai << ", mail: " << _email << "\n";
}
double NhanVien::GetTienLuong()
{
    return _luong;
}
void NhanVien::TinhTienLuong() {}
// ====== coder ====== //
Coder::Coder(string ma, string ten, string phone,
             string mail, double luongCB, double gioLam) : NhanVien(ma, ten, phone, mail, luongCB), _soGioLamThem(gioLam)
{
    TinhTienLuong();
}
void Coder::NhapThongTin()
{
    NhanVien::NhapThongTin();
    cout << "Nhap so gio da lam them: ";
    cin >> _soGioLamThem;
    TinhTienLuong();
    cin.ignore();
}
void Coder::XuatThongTin()
{
    cout << "Vi tri [Coder], ";
    NhanVien::XuatThongTin();
    cout << "So gio da lam them " << _soGioLamThem;
    cout << ", luong hien tai: " << formatMoney(_luong) << "\n";
}
void Coder::TinhTienLuong()
{
    _luong = _luongCoBan + _soGioLamThem * 200000;
}
//==== Class Tester ==== //
Tester::Tester(string ma, string ten, string phone,
               string mail, double luongCB, double soLoi) : NhanVien(ma, ten, phone, mail, luongCB), _soLoiTimDuoc(soLoi)
{
    TinhTienLuong();
}
void Tester::NhapThongTin()
{
    NhanVien::NhapThongTin();
    cout << "Nhan so loi da tim duoc: ";
    cin >> _soLoiTimDuoc;
    TinhTienLuong();
    cin.ignore();
}
void Tester::XuatThongTin()
{
    cout << "Vi tri [Tester], ";
    NhanVien::XuatThongTin();
    cout << "Da tim duoc: " << _soLoiTimDuoc << ", tien luong hien tai: " << formatMoney(_luong) << "\n";
}
void Tester::TinhTienLuong()
{
    _luong = _luongCoBan + _soLoiTimDuoc * 50000;
}