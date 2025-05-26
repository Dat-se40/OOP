#include "KhachHang.h"

int main() {
    fstream reader;
    fstream writer;

    // Mở file
    reader.open("D:\\second\\OOP\\LAP5\\input.txt");
    writer.open("D:\\second\\OOP\\LAP5\\output.txt");

    int soLuong_KHBinhThuong = 0, soLuong_KHBThanhVien = 0, soLuong_KHDacBiet = 0;
    double loiNhuan = 0;

    // Đọc số lượng từng loại khách hàng
    reader >> soLuong_KHBinhThuong >> soLuong_KHBThanhVien >> soLuong_KHDacBiet;
    int tongSoluong = soLuong_KHBinhThuong + soLuong_KHBThanhVien + soLuong_KHDacBiet;

    vector<KhachHang*> danhSach(tongSoluong, nullptr);

    // Đọc thông tin từng khách hàng từ file
    for (int i = 0; i < tongSoluong; i++) {
        if (i < soLuong_KHBinhThuong) {
            danhSach[i] = new KHBinhThuong();
        }
        else if (i < soLuong_KHBinhThuong + soLuong_KHBThanhVien) {
            danhSach[i] = new KHThanhVien();
        }
        else {
            danhSach[i] = new KHDacBiet();
        }
        danhSach[i]->NhapThongTin(reader);
    }
    reader.close();

    writer << soLuong_KHBinhThuong << " " << soLuong_KHBThanhVien << " " << soLuong_KHDacBiet << "\n";

    // Tính toán và ghi kết quả
    for (int i = 0; i < tongSoluong; i++) {
        danhSach[i]->TinhThanhTien();
        loiNhuan += danhSach[i]->GetThanhTien();
        danhSach[i]->XuatThongTin(writer);
    }
    writer << "| Tong so tien cong ty thu duoc " << loiNhuan << " |\n";
    return 0;
}
