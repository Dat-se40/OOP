#include "DSPhanSo.h"

int main()
{
    int cnt = 0;
    while (cnt <= 10)
    {
        cout << "\n===== Truong hop thu " << cnt + 1 << " ======\n";
        DSPhanSo l1;
        l1.NhapDS();

        cout << "Phan so nho nhat: ";
        l1.TimPhanSoMin().Xuat();
        cout << "\nPhan so lon nhat: ";
        l1.TimPhanSoMax().Xuat();
        cout << "\nTong cac phan so trong danh sach: ";
        l1.TongPhanSo().Xuat();
        cout << "\nPhan so co phan tu la so nguyen lon nhat:";
        l1.TimPhanSoTuNguyenToMax().Xuat();
        cout << "\nDanh sach sau khi sap xep theo thu tu tang dan : ";
        l1.SapXepTangDan();
        l1.XuatDS();
        cout << "\nDanh sach sau khi sap xep theo thu tu giam dan : ";
        l1.SapXepGiamDan();
        l1.XuatDS();
        cnt++;
    }

    return 0;
}