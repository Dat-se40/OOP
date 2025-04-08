#include "DaThuc.h"

int main()
{
    int cnt = 0 ; 
    while (cnt <= 10)
    {
        cout << "\n===== Truong hop thu " << cnt + 1 << " ======\n";
        DaThuc a, b;
        cout << "Nhap da thuc thu nhat: \n";
        a.NhapDaThuc();
        a.TinhGiaTri();
        cout<<"Ket qua: " <<a.NhanGiaTri()<<endl;
        cout << "Nhap da thuc thu hai: \n";
        b.NhapDaThuc();

        DaThuc c(a + b), d(a - b);
        cout << "Tong cua hai da thuc: ";
        c.XuatDaThuc();
        cout << "\nHieu cua hai da thuc: ";
        d.XuatDaThuc();

        cnt++;
    }

    system("pause");
    return 0;
}