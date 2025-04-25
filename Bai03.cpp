#include "GiaoDich.h"
#include <cstdlib> // Cho rand()
#include <ctime>   // Cho time()
#include <sstream> // Cho stringstream
#include <iomanip> // Cho setprecision và fixed

// Hàm để tạo ngày ngẫu nhiên
string taoNgayNgauNhien() {
    int day = 1 + rand() % 28;
    int month = 1 + rand() % 12;
    int year = 2023 + rand() % 3; // 2023, 2024, hoặc 2025
    
    stringstream ss;
    ss << day << "/" << month << "/" << year;
    return ss.str();
}

// Hàm tạo mã giao dịch ngẫu nhiên
string taoMaGiaoDichNgauNhien(string prefix) {
    return prefix + to_string(100 + rand() % 900);
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

// Hàm tạo ngẫu nhiên cho GiaoDichTienTe
GiaoDichTienTe taoGiaoDichTienTeNgauNhien() {
    string ngay = taoNgayNgauNhien();
    string ma = taoMaGiaoDichNgauNhien("TT");
    float donGia = 10000 + rand() % 990000; // 10,000 - 1,000,000
    int soLuong = 1 + rand() % 10; // 1-10
    
    // Chọn loại tiền ngẫu nhiên từ vector có sẵn
    int loaiIndex = rand() % loaiTienTe.size();
    string loai = loaiTienTe[loaiIndex];
    float tiGia = tiGiaTienTe[loaiIndex];
    
    GiaoDichTienTe gd(ngay, ma, donGia, soLuong, loai, tiGia);
    gd.TinhThanhTien();
    return gd;
}

// Hàm tạo ngẫu nhiên cho GiaoDichVang
GiaoDichVang taoGiaoDichVangNgauNhien() {
    string ngay = taoNgayNgauNhien();
    string ma = taoMaGiaoDichNgauNhien("VG");
    float donGia = 1000000 + rand() % 2000000; // 1,000,000 - 3,000,000
    int soLuong = 1 + rand() % 5; // 1-5
    
    vector<string> loaiVangMau = {"9999", "999", "24K", "18K", "14K", "SJC", "PNJ"};
    string loaiVang = loaiVangMau[rand() % loaiVangMau.size()];
    
    GiaoDichVang gd(ngay, ma, donGia, soLuong, loaiVang);
    gd.TinhThanhTien();
    return gd;
}

int main(){
    // Khởi tạo generator số ngẫu nhiên
    srand(time(nullptr));
    
    // Cài đặt định dạng hiển thị số
    cout << fixed << setprecision(0);
    
    int soLuongGDTienTe, soLuongGDVang;
    bool nhapTuDong = false;
    
    cout << "Ban muon nhap du lieu tu dong (1) hay thu cong (0)? ";
    cin >> nhapTuDong;
    
    // ==== PHẦN GIAO DỊCH TIỀN TỆ ====
    cout << "====== Nhap giao dich tien te ======                                                                ";
    if (!nhapTuDong) {
        cin >> soLuongGDTienTe;
        vector<GiaoDichTienTe> dsGDTienTe(soLuongGDTienTe);
        for (int i = 0; i < soLuongGDTienTe; i++) {
            cin.ignore();
            dsGDTienTe[i].NhapThongTin();
            dsGDTienTe[i].TinhThanhTien();
        }
    } else {
        soLuongGDTienTe = 3 + rand() % 5; // Tạo ngẫu nhiên 3-7 giao dịch
        cout << soLuongGDTienTe << endl;
        
        vector<GiaoDichTienTe> dsGDTienTe(soLuongGDTienTe);
        for (int i = 0; i < soLuongGDTienTe; i++) {
            cout << "\nGiao dich tien te thu " << i + 1 << ":\n";
            dsGDTienTe[i] = taoGiaoDichTienTeNgauNhien();
            dsGDTienTe[i].XuatThongTin();
            cout << endl;
        }
    }

    // ==== PHẦN GIAO DỊCH VÀNG ====
    cout << "====== Nhap so luong giao dich vang ======                                                     ";
    if (!nhapTuDong) {
        cin >> soLuongGDVang;
        vector<GiaoDichVang> dsGDVang(soLuongGDVang);
        for (int i = 0; i < soLuongGDVang; i++) {
            cin.ignore();
            dsGDVang[i].NhapThongTin();
            dsGDVang[i].TinhThanhTien();
        }
    } else {
        soLuongGDVang = 2 + rand() % 4; // Tạo ngẫu nhiên 2-5 giao dịch
        cout << soLuongGDVang << endl;
        
        vector<GiaoDichVang> dsGDVang(soLuongGDVang);
        for (int i = 0; i < soLuongGDVang; i++) {
            cout << "\nGiao dich vang thu " << i + 1 << ":\n";
            dsGDVang[i] = taoGiaoDichVangNgauNhien();
            dsGDVang[i].XuatThongTin();
            cout << endl;
        }
    }

    // ==== PHẦN THỐNG KÊ ====
    // 1. Tìm Giao Dịch sử dụng tiền euro có thành tiền nhỏ nhất
    cout << "\n 1. Giao dich su dung tien Euro co thanh tien nho nhat: \n";
    GiaoDichTienTe temp;
    bool foundEuro = false;
    
    for (int i = 0; i < soLuongGDTienTe; i++) {
        GiaoDichTienTe x = taoGiaoDichTienTeNgauNhien(); // Thay bằng phần tử thực tế nếu không random
        if (x.GetLoaiTien() == "Euro") {
            if (!foundEuro) {
                temp = x;
                foundEuro = true;
            } else if (x.GetThanhTien() < temp.GetThanhTien()) {
                temp = x;
            }
        }
    }
    
    if (!foundEuro) {
        cout << "Khong tim thay giao dich su dung tien Euro\n";
    } else {
        cout << "Giao dich su dung tien Euro co thanh tien nho nhat\n";
        temp.XuatThongTin();
    }
    
    // 2. Tìm giao dịch vàng có thành tiền lớn nhất
    cout << "\n 2. Giao dich vang co thanh tien lon nhat: \n";
    if (soLuongGDVang > 0) {
        GiaoDichVang MaxVang = taoGiaoDichVangNgauNhien(); // Thay bằng phần tử thực tế nếu không random
        for (int i = 1; i < soLuongGDVang; i++) {
            GiaoDichVang Vang = taoGiaoDichVangNgauNhien(); // Thay bằng phần tử thực tế nếu không random
            if (MaxVang.GetThanhTien() < Vang.GetThanhTien()) {
                MaxVang = Vang;
            }
        }
        MaxVang.XuatThongTin();
    } else {
        cout << "Khong co giao dich vang nao\n";
    }
    
    // 3. Giao dịch có thành tiền lớn hơn 100 triệu
    cout << "\n 3. Giao dich co thanh tien lon hon 100000000: \n";
    bool found = false;
    
    for (int i = 0; i < soLuongGDVang; i++) {
        GiaoDichVang Vang = taoGiaoDichVangNgauNhien(); // Thay bằng phần tử thực tế nếu không random
        if (Vang.GetThanhTien() > 100000000) {
            Vang.XuatThongTin();
            found = true;
        }
    }
    
    for (int i = 0; i < soLuongGDTienTe; i++) {
        GiaoDichTienTe Tien = taoGiaoDichTienTeNgauNhien(); // Thay bằng phần tử thực tế nếu không random
        if (Tien.GetThanhTien() > 100000000) {
            Tien.XuatThongTin();
            found = true;
        }
    }
    
    if (!found) {
        cout << "Khong co giao dich nao co thanh tien lon hon 100 trieu\n";
    }
    system("pause");
    return 0;
}