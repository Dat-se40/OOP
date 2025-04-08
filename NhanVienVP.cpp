#include "NhanVienVP.h"

// ======================== Class ThoiGian ========================
ThoiGian::ThoiGian() : ngay(0), thang(0), nam(0) {}

ThoiGian::ThoiGian(int d, int m, int y) : ngay(d), thang(m), nam(y) {}

void ThoiGian::SetTime() {
    cout << "Nhap ngay: "; cin >> ngay;
    cout << "Nhap thang: "; cin >> thang;
    cout << "Nhap nam: "; cin >> nam;
}

int ThoiGian::GetNam() {
    return nam;
}

void ThoiGian::PrintTime() {
    cout << ngay << "/" << thang << "/" << nam;
}

// ======================== Class NhanVienVP ========================
NhanVienVP::NhanVienVP() : maSo(""), hoTen(""), luong(0) {}

NhanVienVP::NhanVienVP(string m, string t, double l) : maSo(m), hoTen(t), luong(l) {}

void NhanVienVP::SetMaSo(string m) { maSo = m; }

void NhanVienVP::SetMaSo() { getline(cin, maSo); }

void NhanVienVP::SetHoten(string m) { hoTen = m; }

void NhanVienVP::SetHoTen() { getline(cin, hoTen); }

void NhanVienVP::SetLuong(double l) { luong = l; }

void NhanVienVP::SetLuong() {
    cin >> luong;
    cin.ignore();
}
void NhanVienVP::SetNgaySinh(ThoiGian d){
    this->ngaySinh = d ; 
}

void NhanVienVP::SetThongTin() {
    cout << "Ten nhan vien: "; SetHoTen();
    cout << "Ma so nhan vien: "; SetMaSo();
    cout << "Nhap ngay sinh cua nhan vien:\n";
    ngaySinh.SetTime();
    cout << "So tien luong: "; SetLuong();
}

string NhanVienVP::GetMaSo() { return maSo; }

string NhanVienVP::GetHoTen() { return hoTen; }

double NhanVienVP::GetLuong() { return luong; }

void NhanVienVP::GetThongTin() {
    cout << "Ten nhan vien: " << hoTen;
    cout << "\nMa so nhan vien: " << maSo;
    cout << "\nNgay sinh cua nhan vien: "; ngaySinh.PrintTime();
    cout << "\nSo tien luong: " << luong << endl;
}

ThoiGian NhanVienVP::GetNgaySinh() { return ngaySinh; }

// ======= Class QuanLiNhanVien ========= ///
QuanLiNhanVien::QuanLiNhanVien() : soLuongNV(0), tongTienLuong(0) {}

void QuanLiNhanVien::SetSoLuongNV(int n) { soLuongNV = n; }

void QuanLiNhanVien::SetSoLuongNV() {
    cout << "Nhap so luong nhan vien: ";
    cin >> soLuongNV;
    cin.ignore();
}

void QuanLiNhanVien::SetDanhSach() {
    for (int i = 0; i < soLuongNV; i++) {
        cout << "Thong tin nhan vien thu " << i + 1 << endl;
        NhanVienVP tamthoi;
        tamthoi.SetThongTin();
        danhSach.push_back(tamthoi);
    }
}

void QuanLiNhanVien::SetTongTienLuong() {
    for (auto a : danhSach) {
        tongTienLuong += a.GetLuong();
    }
}

int QuanLiNhanVien::GetSoLuongNhanVien() { return soLuongNV; }

int QuanLiNhanVien::GetTongTienLuong() { return tongTienLuong; }

vector<NhanVienVP> QuanLiNhanVien::GetDanhSach() { return danhSach; }

void QuanLiNhanVien::InDanhSach() {
    for (int i = 0; i < soLuongNV; i++) {
        danhSach[i].GetThongTin();
    }
}
// Tìm người lón tuổi nhất
int QuanLiNhanVien::NguoiLonTuoiNhat() {
    int vitri = 0;
    int LonTuoi = danhSach[0].GetNgaySinh().GetNam();
    for (int i = 0; i < soLuongNV; i++) {
        if (LonTuoi > danhSach[i].GetNgaySinh().GetNam()) {
            LonTuoi = danhSach[i].GetNgaySinh().GetNam();
            vitri = i;
        }
    }
    return vitri;
}
// Sắp xét theo lương
void QuanLiNhanVien::SapXepTheoLuong() {
    sort(danhSach.begin(), danhSach.end(), [](NhanVienVP &a, NhanVienVP &b) {
        return a.GetLuong() < b.GetLuong();
    });
}
// Tìm lương cao nhất
int QuanLiNhanVien::LuongCaoNhat() {
    if (danhSach.empty()) return -1;
    SapXepTheoLuong();
    return danhSach.size() - 1;
}
// Hàm dủng để truy cập lòng thành viên của danh sách
NhanVienVP QuanLiNhanVien::TruyCapDanhSach(int n) {
    if (n < 0 || n >= soLuongNV) return NhanVienVP();
    return danhSach[n];
}
void QuanLiNhanVien::FakeRandomData(int n) {// Hàm tạo random các thông tin nhân viên
    vector<string> ho = {"Nguyen", "Tran", "Le", "Pham", "Hoang", "Huynh", "Vo"};
    vector<string> dem = {"Van", "Thi", "Minh", "Duc", "Gia", "Tan", "Tien"};
    vector<string> ten = {"An", "Binh", "Cuong", "Dung", "Hieu", "Linh", "Nga", "Tuan", "Trang", "Yen", "Dat", "Nhi", "Quynh"};

    srand(time(nullptr)); // random seed 1 lần là đủ
    danhSach.clear();
    soLuongNV = n;

    for (int i = 0; i < n; i++) {
        string ma = "VP" + to_string(i + 1);
        string hoTen = ho[rand() % ho.size()] + " " + dem[rand() % dem.size()] + " " + ten[rand() % ten.size()];
        
        int ngay = rand() % 28 + 1;
        int thang = rand() % 12 + 1;
        int nam = rand() % 20 + 1980; // 1980 - 1999
        ThoiGian ngaySinh(ngay, thang, nam);

        double luong = rand() % 100001 + 50000 - rand()%20; // từ 50000 đến 150000

        NhanVienVP nv(ma, hoTen, luong);
        // Gán ngày sinh
        *(NhanVienVP*)&nv = NhanVienVP(ma, hoTen, luong); // dùng cast để tránh cần sửa constructor

        // Gán ngày sinh bằng cách tạm thêm setter nếu bạn thích
        nv.SetNgaySinh( ThoiGian(ngay,thang,nam)) ;

        danhSach.push_back(nv);
    }

    SetTongTienLuong(); // Đừng quên tính tổng lương!
}
