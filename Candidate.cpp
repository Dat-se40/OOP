#include "Candidate.h"

// ===== cCandidate ===== //
cCandidate::cCandidate() : Ma(""), Ten(""), Ngay(0), Thang(0), Nam(0), Toan(0), Van(0), Anh(0) {}

cCandidate::cCandidate(string ma, string ten, int ngay, int thang, int nam, double toan, double van, double anh) 
    : Ma(ma), Ten(ten), Ngay(ngay), Thang(thang), Nam(nam), Toan(toan), Van(van), Anh(anh) {}

void cCandidate::Nhap() {
    cout << "Nhap ma: "; cin >> Ma;
    cin.ignore();
    cout << "Nhap ten: "; getline(cin, Ten);
    cout << "Nhap ngay thang nam sinh (dd mm yyyy): ";
    cin >> Ngay >> Thang >> Nam;
    cout << "Nhap diem Toan, Van, Anh: ";
    cin >> Toan >> Van >> Anh;
}

void cCandidate::Xuat() const {
    cout << "Ma: " << Ma << ", Ten: " << Ten
         << ", Ngay sinh: " << Ngay << "/" << Thang << "/" << Nam
         << ", Tong diem: " << TongDiem() << endl;
}

double cCandidate::TongDiem() const {
    return Toan + Van + Anh;
}

// ===== cListCandidate ===== //
void cListCandidate::NhapDS(int n) {
    danhSach.resize(n);
    for (int i = 0; i < n; i++) {
        cout << "\nNhap thi sinh thu " << i + 1 << ":\n";
        danhSach[i].Nhap();
    }
}

void cListCandidate::XuatDSTren15() const {
    cout << "\nDanh sach thi sinh co tong diem > 15:\n";
    for (const auto &ts : danhSach) {
        if (ts.TongDiem() > 15) {
            ts.Xuat();
        }
    }
}

cCandidate cListCandidate::TimThiSinhCaoNhat() const { // Dựa trên tổng điểmm
    return *max_element(danhSach.begin(), danhSach.end(), [](const cCandidate &a, const cCandidate &b) {
        return a.TongDiem() < b.TongDiem();
    });
}

void cListCandidate::SapXepGiamDan() { // Sắp xếp theo điểm 
    sort(danhSach.begin(), danhSach.end(), [](const cCandidate &a, const cCandidate &b) {
        return a.TongDiem() > b.TongDiem();
    });
}

void cListCandidate::XuatDS() const {
    cout << "\nDanh sach thi sinh:\n";
    for (const auto &ts : danhSach) {
        ts.Xuat();
    }
}
void cListCandidate::FakeRandomData(int n) {
    vector<string> ho = {"Nguyen", "Tran", "Le", "Pham", "Hoang","Huynh","Vo"};
    vector<string> dem = {"Van", "Thi", "Minh", "Duc", "Gia","Tan","Tien"};
    vector<string> ten = {"An", "Binh", "Cuong", "Dung", "Hieu", "Linh", "Nga", "Tuan", "Trang", "Yen","Dat","Nhi","Quynh"};

    srand(time(nullptr)); // Khởi tạo seed cho random

    danhSach.clear();
    for (int i = 0; i < n; i++) {
        string ma = "TS" + to_string(i + 1);
        string hoTen = ho[rand() % ho.size()] + " " + dem[rand() % dem.size()] + " " + ten[rand() % ten.size()];

        int ngay = rand() % 28 + 1;
        int thang = rand() % 12 + 1;
        int nam = rand() % 6 + 2000; // 2000 - 2004

        double toan = (rand() % 101) / 10.0; // từ 0.0 đến 10.0
        double van = (rand() % 101) / 10.0;
        double anh = (rand() % 101) / 10.0;

        danhSach.emplace_back(ma, hoTen, ngay, thang, nam, toan, van, anh);
    }
}