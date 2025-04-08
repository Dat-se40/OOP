#include "cArray.h"

int main()
{
    XuLiUoc(MAX); // Tạo bảng số nguyên tố trước khi xử lý

    int cnt =11;
    while (cnt <= 20)
    {
        cout << "\n===== Truong hop thu " << cnt + 1 << " ======\n";
        cArray test1;
        test1.TaoMangNgauNhien();

        cout << "Mang ngau nhien: ";
        test1.XuatMang();
        if (test1.MangTangDan())
            cout << "\nMang co thu tu tang dan";
        else
            cout << "\nMang khong co thu tu tang dan";
        cout << "\nMang sau khi sap xep: ";
        test1.SapXep();
        test1.XuatMang();
        int a = test1.SoleNhoNhat();
        if (a != NOTFOUND)
            cout << "\nSo le nho nhat trong mang: " << a;
        else
            cout << "\nKhong tim thay so le.";

        int b = test1.SoNguyenToLonNhat();
        if (b != NOTFOUND)
            cout << "\nSo nguyen to lon nhat trong mang: " << b;
        else
            cout << "\nKhong tim thay so nguyen to.";
        cnt++;
    }
    system("pause");
    return 0;
}
