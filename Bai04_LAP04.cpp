#include "QuanLiNV.h"
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

// ==== Hàm hỗ trợ tạo thông tin ngẫu nhiên ====
string TaoTenNgauNhien()
{
    vector<string> ho = {"Nguyen", "Tran", "Le", "Pham", "Hoang"};
    vector<string> ten = {"An", "Binh", "Chi", "Dung", "Hanh", "Khanh"};
    return ho[rand() % ho.size()] + " " + ten[rand() % ten.size()];
}

string TaoSoDienThoai()
{
    string sdt = "0";
    for (int i = 0; i < 9; ++i) sdt += to_string(rand() % 10);
    return sdt;
}

string TaoEmail(const string& ten)
{
    string email = ten;
    for (char& c : email) if (c == ' ') c = '.';
    return email + "@gmail.com";
}

// ==== Hàm nhập danh sách nhân viên ngẫu nhiên ====
void NhapNgauNhienNhanVien(vector<NhanVien*>& ds, int soLuong)
{
    srand(time(0));
    for (int i = 0; i < soLuong; ++i)
    {
        string ma = "NV" + to_string(100 + i);
        string ten = TaoTenNgauNhien();
        string phone = TaoSoDienThoai();
        string email = TaoEmail(ten);
        double luongCB = 5000000 + rand() % 5000001;

        if (rand() % 2 == 0) // Coder
        {
            double gio = 10 + rand() % 21;
            ds.push_back(new Coder(ma, ten, phone, email, luongCB, gio));
        }
        else // Tester
        {
            int soLoi = 5 + rand() % 16;
            ds.push_back(new Tester(ma, ten, phone, email, luongCB, soLoi));
        }
    }
}

// ==== MAIN ====
int main()
{
    vector<NhanVien*> dsNhanVien;
    int soLuong = rand() % 3 + 1 ; // Random từ 5–10 nhân viên

    cout << "===== NHAP DANH SACH NHAN VIEN (NGAU NHIEN) =====\n";
    NhapNgauNhienNhanVien(dsNhanVien, soLuong);

    cout << "\n===== DANH SACH NHAN VIEN =====\n";
    for (NhanVien* nv : dsNhanVien)
    {
        nv->XuatThongTin();
        cout << "---------------------------------\n";
    }

    // ==== 1. DANH SACH CO LUONG THAP HON TRUNG BINH ====
    double tongLuong = 0;
    for (NhanVien* nv : dsNhanVien)
        tongLuong += nv->GetTienLuong();
    double luongTB = tongLuong / dsNhanVien.size();

    cout << "\n[1] Danh sach nhan vien co luong thap hon trung binh (" << fixed << setprecision(0) << luongTB << " VND):\n";
    for (NhanVien* nv : dsNhanVien)
    {
        if (nv->GetTienLuong() < luongTB)
        {
            nv->XuatThongTin();
            cout << "---------------------------------\n";
        }
    }

    // ==== 2. NHAN VIEN CO LUONG CAO NHAT ====
    double maxLuong = dsNhanVien[0]->GetTienLuong();
    for (NhanVien* nv : dsNhanVien)
        if (nv->GetTienLuong() > maxLuong)
            maxLuong = nv->GetTienLuong();

    cout << "\n[2] Danh sach nhan vien co luong cao nhat (" << fixed << setprecision(0) << maxLuong << " VND):\n";
    for (NhanVien* nv : dsNhanVien)
    {
        if (nv->GetTienLuong() == maxLuong)
        {
            nv->XuatThongTin();
            cout << "---------------------------------\n";
        }
    }

    // ==== 3. NHAN VIEN CO LUONG THAP NHAT ====
    double minLuong = dsNhanVien[0]->GetTienLuong();
    for (NhanVien* nv : dsNhanVien)
        if (nv->GetTienLuong() < minLuong)
            minLuong = nv->GetTienLuong();

    cout << "\n[3] Danh sach nhan vien co luong thap nhat (" << fixed << setprecision(0) << minLuong << " VND):\n";
    for (NhanVien* nv : dsNhanVien)
    {
        if (nv->GetTienLuong() == minLuong)
        {
            nv->XuatThongTin();
            cout << "---------------------------------\n";
        }
    }

    // ==== GIẢI PHÓNG BỘ NHỚ ====
    for (NhanVien* nv : dsNhanVien)
        delete nv;
    system("pause");
    return 0;
}
