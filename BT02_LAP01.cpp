#include <iostream>
using namespace std;

struct PhanSo
{
    int tuSo, mauSo;

    friend istream &operator>>(istream &in, PhanSo &x)
    {// Nhập phân số , dùng nạp chồng toán tử
        in >> x.tuSo >> x.mauSo;
        if (x.mauSo == 0)
        {
            cout << "Mau so khong the bang 0, vui long nhap lai" << endl;
            in>>x.tuSo>>x.mauSo;
        }
        return in;
    }

    friend ostream &operator<<(ostream &out, const PhanSo &x)
    {   // Xuất phân số
        PhanSo temp = x;

        if (temp.tuSo == 0) {
            out << 0;
            return out;
        }
        
        if (temp.mauSo == 1) {
            out << temp.tuSo;
            return out;
        }
        
        out << temp.tuSo << "/" << temp.mauSo<< " ";
        return out;
    }
};
PhanSo Max(PhanSo a, PhanSo b){
    double val_a = double(a.tuSo)/a.mauSo; // Chuyển phân số sá
    double val_b = double(b.tuSo)/b.mauSo;
    return (val_a >= val_b) ? a : b;
} 

int main(){

    PhanSo p1, p2;

    cout << "Nhap phan sp thu 1: ";
    cin >> p1;
    cout << "Nhap phan so thu 2: ";
    cin >> p2;

    cout<<"Phan so voi nhat giua s"<<p1<<" va "<<p2<<" la "<< Max(p1,p2);
    return 0 ; 
}
