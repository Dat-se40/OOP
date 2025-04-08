#include "NhanVienSX.h"

// ====== Class ThoiGian ======== //
ThoiGian::ThoiGian() : ngay(0), thang(0), nam(0) {}
ThoiGian::ThoiGian(int d, int m, int y) : ngay(d), thang(m), nam(y) {}

int ThoiGian::GetNam() { return nam; }
void ThoiGian::SetTime() {
    cout << "Nhap ngay: "; cin >> ngay;
    cout << "Nhap thang: "; cin >> thang;
    cout << "Nhap nam: "; cin >> nam;
}
void ThoiGian::PrintTime() { cout << ngay << "/" << thang << "/" << nam; }

// ===== Class NhanVienSX ===== //
NhanVienSX::NhanVienSX() : maSo(""), hoTen(""), soSanPham(0), giaTien(0), luong(0) {}

NhanVienSX::NhanVienSX(string t, string m, ThoiGian tm, int s, double g) 
    : hoTen(t), maSo(m), ngaySinh(tm), soSanPham(s), giaTien(g) {}

void NhanVienSX::SetThongTin() {
    cout << "Ten nhan vien: "; cin.ignore(); getline(cin, hoTen);
    cout << "Ma so nhan vien: "; getline(cin, maSo);
    cout << "Nhap ngay sinh cua nhan vien:\n"; ngaySinh.SetTime();
    cout << "Nhap so luong san pham da gia cong: "; cin >> soSanPham;
    cout << "Gia thanh 1 san pham: "; cin >> giaTien;
    SetLuong();
}

void NhanVienSX::SetLuong() { luong = soSanPham * giaTien; }
//Các hàm get , set 
string NhanVienSX::GetMaSo() { return maSo; }
string NhanVienSX::GetHoTen() { return hoTen; }
ThoiGian NhanVienSX::GetNgaySinh() { return ngaySinh; }
int NhanVienSX::GetSoSanPham() { return soSanPham; }
int NhanVienSX::GetGiaSanPham() { return giaTien; }
double NhanVienSX::GetLuong() { return luong; }

void NhanVienSX::GetThongTin() {
    cout << "Ten nhan vien: " << hoTen
         << "\nMa so nhan vien: " << maSo
         << "\nNgay sinh: "; ngaySinh.PrintTime();
    cout << "\nSo san pham: " << soSanPham
         << "\nGia san pham: " << giaTien
         << "\nLuong: " << luong << endl;
}

// ===== class QuanLiNhanVien ====== //
QuanLiNhanVien::QuanLiNhanVien() : soLuongNV(0), tongTienLuong(0) {}

void QuanLiNhanVien::SetSoLuongNV() {
    cout << "Nhap so luong nhan vien: "; cin >> soLuongNV;
}

void QuanLiNhanVien::SetDanhSach() {
    danhSach.clear();
    for (int i = 0; i < soLuongNV; i++) {
        cout << "Thong tin nhan vien thu " << i + 1 << ":\n";
        NhanVienSX nv;
        nv.SetThongTin();
        danhSach.push_back(nv);
    }
}

void QuanLiNhanVien::SetTongTienLuong() {
    tongTienLuong = 0;
    for (auto &nv : danhSach) {
        tongTienLuong += nv.GetLuong();
    }
}

int QuanLiNhanVien::GetSoLuongNhanVien() { return soLuongNV; }
int QuanLiNhanVien::GetTongTienLuong() { return tongTienLuong; }
vector<NhanVienSX> QuanLiNhanVien::GetDanhSach() { return danhSach; }

void QuanLiNhanVien::InDanhSach() {
    for (auto &nv : danhSach) nv.GetThongTin();
}
// Tìm người lón tuổi nhất
int QuanLiNhanVien::NguoiLonTuoiNhat() {
    int vitri = 0, namMax = danhSach[0].GetNgaySinh().GetNam();
    for (int i = 1; i < danhSach.size(); i++) {
        if (danhSach[i].GetNgaySinh().GetNam() < namMax) {
            namMax = danhSach[i].GetNgaySinh().GetNam();
            vitri = i;
        }
    }
    return vitri;
}
// Sắp xét theo lương
void QuanLiNhanVien::SapXepTheoLuong() {
    sort(danhSach.begin(), danhSach.end(), 
         [](NhanVienSX &a, NhanVienSX &b) { return a.GetLuong() < b.GetLuong(); });
}
// Tìm lương cao nhất
int QuanLiNhanVien::LuongCaoNhat() {
    SapXepTheoLuong();
    return danhSach.size() - 1;
}
// Hàm dủng để truy cập lòng thành viên của danh sách
NhanVienSX QuanLiNhanVien::TruyCapDanhSach(int n) {
    return (n >= 0 && n < soLuongNV) ? danhSach[n] : NhanVienSX();
}
// Menu chọn chức năng 
void QuanLiNhanVien::Run() {
    int n = 0;
    while (n != 5) {
        cout << "\n===== Menu =====\n"
             << "1. Nhap danh sach\n"
             << "2. In danh sach\n"
             << "3. Sap xep theo luong\n"
             << "4. Nhan vien co luong cao nhat\n"
             << "5. Thoat\n"
             << "Nhap lua chon: ";
        cin >> n;

        switch (n) {
        case 1: SetSoLuongNV(); SetDanhSach(); break;
        case 2: InDanhSach(); break;
        case 3: SapXepTheoLuong(); break;
        case 4: danhSach[LuongCaoNhat()].GetThongTin(); break;
        }
    }
}
void QuanLiNhanVien::FakeRandomData(int n) {// Hàm tạo random các thông tin nhân viên
    vector<string> ho = {"Nguyen", "Tran", "Le", "Pham", "Hoang", "Huynh", "Vo"};
    vector<string> dem = {"Van", "Thi", "Minh", "Duc", "Gia", "Tan", "Tien"};
    vector<string> ten = {"An", "Binh", "Cuong", "Dung", "Hieu", "Linh", "Nga", "Tuan", "Trang", "Yen", "Dat", "Nhi", "Quynh"};

    srand(time(nullptr)); // random seed 1 lần là đủ
    danhSach.clear();
    soLuongNV = n;

    for (int i = 0; i < n; i++) {
        string ma = "SX" + to_string(i + 1);
        string hoTen = ho[rand() % ho.size()] + " " + dem[rand() % dem.size()] + " " + ten[rand() % ten.size()];
        
        int ngay = rand() % 28 + 1;
        int thang = rand() % 12 + 1;
        int nam = rand() % 20 + 1980; // 1980 - 1999
        ThoiGian ngaySinh(ngay, thang, nam);

        int soSanPham = rand()%20  + rand()%40 + 5 ; 
        int cost = rand()%10000 + 2000 ; 
        NhanVienSX nv(hoTen,ma,ngaySinh,soSanPham,cost);
        nv.SetLuong();

        danhSach.push_back(nv);
    }

    SetTongTienLuong(); // Đừng quên tính tổng lương!
}
