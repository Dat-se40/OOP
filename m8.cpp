#include "NhanVienSX.h"

int main() {
    srand(time(NULL)); // Đặt 1 lần là đủ

    for (int cnt = 1; cnt <= 10; cnt++) {
        cout << "\n===== Truong hop thu " << cnt << " ======\n";
        QuanLiNhanVien VCB;
        VCB.FakeRandomData(rand() % 5 + 3); // random từ 3 đến 7 nhân viên

        cout << "Tong luong nhan vien: " << VCB.GetTongTienLuong() << endl;
        
        VCB.SapXepTheoLuong();
        cout << "Danh sach da duoc sap xep theo luong: \n";
        VCB.InDanhSach();

        cout << "\n== Nhan vien luong cao nhat ==\n";
        VCB.TruyCapDanhSach(VCB.LuongCaoNhat()).GetThongTin();

        cout << "\n== Nhan vien lon tuoi nhat ==\n";
        VCB.TruyCapDanhSach(VCB.NguoiLonTuoiNhat()).GetThongTin();
    }

    system("pause");
    return 0;
}
