#include <iostream>
using namespace std;

struct PhanSo
{
    int tuSo, mauSo;

    PhanSo(int tu, int mau) : tuSo(tu), mauSo(mau) {}
    PhanSo() {}
    friend istream &operator>>(istream &in, PhanSo &x)
    { // Nhập phân số , dùng nạp chồng toán tử
        in >> x.tuSo >> x.mauSo;
        if (x.mauSo == 0)
        {
            cout << "Mau so khong the bang 0, vui long nhap lai" << endl;
            in >> x.tuSo >> x.mauSo;
        }
        return in;
    }

    friend ostream &operator<<(ostream &out, const PhanSo &x)
    { // Xuất phân số
        PhanSo temp = x;

        if (temp.tuSo == 0)
        {
            out << 0;
            return out;
        }

        if (temp.mauSo == 1)
        {
            out << temp.tuSo;
            return out;
        }

        out << temp.tuSo << "/" << temp.mauSo << " ";
        return out;
    }
    // Phep Cong
    PhanSo operator+(const PhanSo &operand) const
    {
        PhanSo result(tuSo * operand.mauSo + mauSo * operand.tuSo, mauSo * operand.mauSo);
        return result;
    }
    // Trừ
    PhanSo operator-(const PhanSo &operand) const
    {
        PhanSo result(tuSo * operand.mauSo - mauSo * operand.tuSo, mauSo * operand.mauSo);
        return result;
    }
    // Nhân
    PhanSo operator*(const PhanSo &operand) const
    {
        PhanSo result(tuSo * operand.tuSo, mauSo * operand.mauSo);
        return result;
    }
    // Chia
    PhanSo operator/(const PhanSo &operand) const
    {

        if (operand.tuSo == 0)
        {
            cout << "Loi: Khong the chia cho 0" << endl;
            return PhanSo(0, 1);
        }
        PhanSo result(tuSo * operand.mauSo,
                      mauSo * operand.tuSo);
        return result;
    }
};

int main()
{

    PhanSo p1, p2;
    int cnt = 1;

    cout << "Nhap phan sp thu 1: ";
    cin >> p1;
    cout << "Nhap phan so thu 2: ";
    cin >> p2;

    cout << p1 << " + " << p2 << " = " << p1 + p2 << endl;
    cout << p1 << " - " << p2 << " = " << p1 - p2 << endl;
    cout << p1 << " * " << p2 << " = " << p1 * p2 << endl;
    cout << p1 << " / " << p2 << " = " << p1 / p2 << endl;

    system("pause");
    return 0;
}
