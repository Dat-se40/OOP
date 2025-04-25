#include "BatDongSan.h"
#include <cstdlib> // Cho rand()
#include <ctime>   // Cho time()
#include <sstream> // Cho stringstream
#include <iomanip> // Cho setprecision và fixed

// Hàm để tạo ngày ngẫu nhiên, có thể là tháng 12/2024 hoặc không
string taoNgayNgauNhien() {
    int day = 1 + rand() % 28;
    int month = 1 + rand() % 12;
    int year = 2023 + rand() % 3; // 2023, 2024, hoặc 2025
    
    // 30% khả năng là tháng 12/2024
    if (rand() % 100 < 30) {
        month = 12;
        year = 2024;
    }
    
    stringstream ss;
    ss << (day < 10 ? "0" : "") << day << "/"
       << (month < 10 ? "0" : "") << month << "/"
       << year;
    return ss.str();
}

// Hàm định dạng số tiền thành chuỗi có dấu phân cách hàng nghìn
string formatMoney(double amount) {
    stringstream ss;
    ss << fixed << setprecision(0) << amount; // Không hiển thị phần thập phân
    string str = ss.str();
    
    int insertPosition = str.length() - 3;
    while (insertPosition > 0) {
        str.insert(insertPosition, ",");
        insertPosition -= 3;
    }
    
    return str + " VND";
}

// Hàm tạo mã giao dịch ngẫu nhiên
string taoMaGiaoDichNgauNhien(string prefix) {
    return prefix + to_string(100000 + rand() % 900000);
}

// Hàm tạo ngẫu nhiên cho GiaoDichChungCu
GiaoDichChungCu taoGiaoDichChungCuNgauNhien() {
    string ngay = taoNgayNgauNhien();
    string ma = taoMaGiaoDichNgauNhien("CC");
    double donGia = 10000000 + rand() % 20000000; // 10-30 triệu/m²
    double dienTich = 40 + rand() % 120; // 40-160m²
    string maCan = "CAN" + to_string(100 + rand() % 900);
    int tang = 1 + rand() % 25; // 1-25 tầng
    
    GiaoDichChungCu gd(ngay, ma, donGia, dienTich, maCan, tang);
    gd.TinhThanhTien();
    return gd;
}

// Hàm tạo ngẫu nhiên cho GiaoDichNhaPho
GiaoDichNhaPho taoGiaoDichNhaPhongNgauNhien() {
    string ngay = taoNgayNgauNhien();
    string ma = taoMaGiaoDichNgauNhien("NP");
    double donGia = 15000000 + rand() % 35000000; // 15-50 triệu/m²
    double dienTich = 80 + rand() % 220; // 80-300m²
    
    vector<string> diaChiMau = {
        "123 Nguyen Trai, Q1", "456 Le Loi, Q5", "789 Tran Hung Dao, Q3",
        "101 Nguyen Hue, Q1", "202 Le Duan, Q1", "303 Vo Van Tan, Q3",
        "404 Dien Bien Phu, Binh Thanh", "505 Nguyen Thi Minh Khai, Q3"
    };
    string diaChi = diaChiMau[rand() % diaChiMau.size()];
    
    // Chọn loại nhà ngẫu nhiên từ vector có sẵng
    string loaiNha = cacLoaiNha[rand() % cacLoaiNha.size()];
    
    GiaoDichNhaPho gd(ngay, ma, donGia, dienTich, diaChi, loaiNha);
    gd.TinhThanhTien();
    return gd;
}

// Hàm tạo ngẫu nhiên cho GiaoDichhDat
GiaoDichhDat taoGiaoDichDatNgauNhien() {
    string ngay = taoNgayNgauNhien();
    string ma = taoMaGiaoDichNgauNhien("DT");
    double donGia = 5000000 + rand() % 15000000; // 5-20 triệu/m²
    double dienTich = 100 + rand() % 1000; // 100-1100m²
    char loaiDat = cacLoaiDat[rand() % cacLoaiDat.size()];
    
    GiaoDichhDat gd(ngay, ma, donGia, dienTich, loaiDat);
    gd.TinhThanhTien();
    return gd;
}

bool checkNgay(string day){ //DD/12/2024
    string pattern = "YY/12/2024";
    for(int i = 3 ; i < pattern.length() ; i++ ){
        if(day[i] != pattern[i] ) return false ; 
    }
    return true;
}

int main() {
    // Khởi tạo generator số ngẫu nhiên
    srand(time(nullptr));
    
    // Cài đặt định dạng hiển thị số
    cout << fixed << setprecision(0);
    
    // === Phần Chung cư ===
    cout << "===== DANH SACH CHUNG CU ====== \n";
    int soNhaChungCu = 3 + rand() % 5; // Tạo ngẫu nhiên 3-7 giao dịch
    cout << "So giao dich chung cu: " << soNhaChungCu << "\n\n";
    
    vector<GiaoDichChungCu> dsGDChungCu(soNhaChungCu);
    double tongTien = 0;
    
    for (int i = 0; i < soNhaChungCu; i++) {
        cout << "Giao dich chung cu thu " << i + 1 << ":\n";
        dsGDChungCu[i] = taoGiaoDichChungCuNgauNhien();
        dsGDChungCu[i].XuatThongTin();
        cout << "\nThanh tien: " << formatMoney(dsGDChungCu[i].GetThanhTien()) << "\n\n";
        tongTien += dsGDChungCu[i].GetThanhTien();
    }
    
    // Tổng giá trị trung bình
    cout << "Tong gia tri trung binh cua chung cu: " << formatMoney(tongTien / soNhaChungCu) << "\n\n";
    
    // === Phần Nhà phố ===
    cout << "===== DANH SACH NHA PHO ====== \n";
    int soNhaPho = 3 + rand() % 4; // Tạo ngẫu nhiên 3-6 giao dịch
    cout << "So giao dich nha pho: " << soNhaPho << "\n\n";
    
    vector<GiaoDichNhaPho> dsGDNhaPho(soNhaPho);
    for (int i = 0; i < soNhaPho; i++) {
        cout << "Giao dich nha pho thu " << i + 1 << ":\n";
        dsGDNhaPho[i] = taoGiaoDichNhaPhongNgauNhien();
        dsGDNhaPho[i].XuatThongTin();
        cout << "\nThanh tien: " << formatMoney(dsGDNhaPho[i].GetThanhTien()) << "\n\n";
    }
    
    // === Phần Đất ===
    cout << "===== DANH SACH NHA DAT ====== \n";
    int soGDDat = 2 + rand() % 4; // Tạo ngẫu nhiên 2-5 giao dịch
    cout << "So giao dich dat: " << soGDDat << "\n\n";
    
    vector<GiaoDichhDat> dsGDDat(soGDDat);
    for (int i = 0; i < soGDDat; i++) {
        cout << "Giao dich dat thu " << i + 1 << ":\n";
        dsGDDat[i] = taoGiaoDichDatNgauNhien();
        dsGDDat[i].XuatThongTin();
        cout << "\nThanh tien: " << formatMoney(dsGDDat[i].GetThanhTien()) << "\n\n";
    }
    
    // === Xuất thông tin phân tích ===
    cout << "\n===== THONG KE =====\n";
    
    // Tìm nhà phố có thành tiền lớn nhất
    if(soNhaPho > 0) {
        cout << "NHA PHO CO THANH TIEN LON NHAT:\n";
        GiaoDichNhaPho maxTien = dsGDNhaPho[0];
        for (GiaoDichNhaPho candi : dsGDNhaPho) {
            if (maxTien.GetThanhTien() < candi.GetThanhTien()) {
                maxTien = candi;
            }
        }
        maxTien.XuatThongTin();
        cout << "\nThanh tien: " << formatMoney(maxTien.GetThanhTien()) << "\n\n";
    }
    
    // Tìm giao dịch trong tháng 12 năm 2024
    cout << "GIAO DICH TRONG THANG 12 NAM 2024:\n";
    bool found = false;
    
    for (auto& candi : dsGDChungCu) {
        if (checkNgay(candi.GetNgayGiaoDich())) {
            cout << "\n- Chung cu:\n";
            candi.XuatThongTin();
            cout << "\nThanh tien: " << formatMoney(candi.GetThanhTien()) << "\n";
            found = true;
        }
    }
    
    for (auto& candi : dsGDNhaPho) {
        if (checkNgay(candi.GetNgayGiaoDich())) {
            cout << "\n- Nha pho:\n";
            candi.XuatThongTin();
            cout << "\nThanh tien: " << formatMoney(candi.GetThanhTien()) << "\n";
            found = true;
        }
    }
    
    for (auto& candi : dsGDDat) {
        if (checkNgay(candi.GetNgayGiaoDich())) {
            cout << "\n- Dat:\n";
            candi.XuatThongTin();
            cout << "\nThanh tien: " << formatMoney(candi.GetThanhTien()) << "\n";
            found = true;
        }
    }
    
    if (!found) {
        cout << "Khong tim thay giao dich nao trong thang 12/2024\n";
    }
    system("pause");
    return 0;
}