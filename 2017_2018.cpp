#include <iostream>
#include <vector>

using namespace std;
class NhomMau
{
protected:
    char Rh;

public:
    NhomMau() : Rh(' ') {}
    void Nhap()
    {
        cout << "Nhap Rh: (+)  hoac (-): ";
        cin >> Rh;
    }
    virtual void Xuat()
    {
        cout << Rh << endl;
    }
    char LayRh() { return Rh; };

    virtual char PhanLoai() = 0;
    virtual bool KiemTraChaMe(NhomMau *, NhomMau *) = 0;
    virtual bool NhanMau(NhomMau *) = 0;
    bool HopQuyLuat(NhomMau *cha, NhomMau *me)
    {
        return KiemTraChaMe(cha, me) &&KiemTraChaMe(me,cha);
    }
};
class A : public NhomMau
{
public:
    char PhanLoai() { return 'A'; }
    void Xuat()
    {
        cout << 'A' << Rh;
    }
    bool KiemTraChaMe(NhomMau *cha, NhomMau *me)
    { // phai co chung A trong mau
        char MauC = cha->PhanLoai();
        char MauM = me->PhanLoai();
        if (MauC == 'O' && MauM == 'B' ||
            MauM == 'O' && MauC == 'B')
            return false;
        return true;
    }
    bool NhanMau(NhomMau *nguoiCho)
    {
        char RhCho = nguoiCho->LayRh();
        char MauCho = nguoiCho->PhanLoai();
        if (Rh = '-')
        {
            return (RhCho == '-' && MauCho == 'O' ||
                    RhCho == '-' && MauCho == 'A');
        }
        else
        {
            return (MauCho == 'A' || MauCho == 'O');
        }
        return false;
    }
};
class B : public NhomMau
{
public:
    char PhanLoai() { return 'B'; }
    void Xuat()
    {
        cout << 'B' << Rh;
    }
    bool KiemTraChaMe(NhomMau *cha, NhomMau *me)
    { // Phai co chu B trong mau
        char MauC = cha->PhanLoai();
        char MauM = me->PhanLoai();
        if (MauC == 'O' && MauM == 'A' ||
            MauM == 'O' && MauC == 'A')
            return false;
        return true;
    }
    bool NhanMau(NhomMau *nguoiCho)
    {
        char RhCho = nguoiCho->LayRh();
        char MauCho = nguoiCho->PhanLoai();
        if (Rh = '-')
        {
            return (RhCho == '-' && MauCho == 'O' ||
                    RhCho == '-' && MauCho == 'B');
        }
        else
        {
            return (MauCho == 'B' || MauCho == 'O');
        }
        return false;
    }
};
class AB : public NhomMau
{ // C dai dien cho AB
public:
    char PhanLoai() { return 'C'; }
    void Xuat()
    {
        cout << "AB" << Rh;
    }
    bool KiemTraChaMe(NhomMau *cha, NhomMau *me)
    { // Du 2 chu AB
        char MauC = cha->PhanLoai();
        char MauM = me->PhanLoai();
        // AB khong sinh ra tu cho me co cung A hoac B hoac 1 trong 2 truong la 0
        if (MauC == MauM && MauC != 'C' || MauC == 'O' || MauM == 'O')
            return false;
        return true;
    }
    bool NhanMau(NhomMau *nguoiCho)
    {
        char RhCho = nguoiCho->LayRh();
        char MauCho = nguoiCho->PhanLoai();
        if (Rh = '-')
        {
            return RhCho == '-';
        }
        else
        {
            return true;
        }
    }
};
class O : public NhomMau
{
public:
    char PhanLoai() { return 'O'; }
    void Xuat()
    {
        cout << 'O' << Rh;
    }
    bool KiemTraChaMe(NhomMau *cha, NhomMau *me)
    { // cung chu khac AB
        char MauC = cha->PhanLoai();
        char MauM = me->PhanLoai();
        if (MauC == 'C' || MauM == 'C')
            return false;
        return true;
    }
    bool NhanMau(NhomMau *nguoiCho)
    {
        char RhCho = nguoiCho->LayRh();
        char MauCho = nguoiCho->PhanLoai();
        if (Rh = '-')
        {
            return (RhCho == '-' && MauCho == 'O');
        }
        else
        {
            return MauCho == 'O';
        }
        return false;
    }
};
NhomMau *NhapMau()
{
    cout << "Nhap nhom mau: A - B - C - AB(C): ";
    char mau;
    cin >> mau;
    NhomMau *MauMoi = NULL;
    if (mau == 'A')
    {
        MauMoi = new A();
    }
    else if (mau == 'B')
    {
        MauMoi = new B();
    }
    else if (mau == 'O')
    {
        MauMoi = new O();
    }
    else if (mau == 'C')
    {
        MauMoi = new AB();
    }
    MauMoi->Nhap();
    return MauMoi;
}

class DSXetNghiem
{
private:
    vector<NhomMau *> DS;

public:
    DSXetNghiem() : DS({}) {}
    void NhapDanhSach()
    {
        cout << "Nhap so luong nguoi trong danh sach:";
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cout << "\nSTT. " << i + 1 << ": ";
            DS.push_back(NhapMau());
        }
    }
    void XuatDanhSach()
    {
        cout << "Danh sach mau hien tai: ";
        for (NhomMau *a : DS)
        {
            a->Xuat();
            cout << "\n";
        }
    }
    NhomMau *truyCap(int i)
    {
        if (i < 0 || i >= DS.size())
            return NULL;
        else
            return DS[i];
    }
    void DanhSachNguoiCho(NhomMau *nguoiNhan)
    {
        if (nguoiNhan == NULL)
            return;
        for (NhomMau *a : DS)
        {
            if ( a == nguoiNhan) continue;
            if (nguoiNhan->NhanMau(a))
            {
                a->Xuat();
                cout << endl;
            }
        }
    }
};
int main()
{
    DSXetNghiem clinic;
    clinic.NhapDanhSach();
    int m,n,p,q ; 
    cout<<"Nhap chi so cha,me,con: ";
    cin>>m>>n>>p;
    if ( clinic.truyCap(p)->HopQuyLuat(clinic.truyCap(m),clinic.truyCap(n) ) ) {
        cout<< "Hop le\n";
    }else {
        cout<<"Khong hop le\n";
    }
    cout<<"Nhap chi so nguoi nhan: ";
    cin>>q ; 
    clinic.DanhSachNguoiCho(clinic.truyCap(q));

    system("pause");
    return 0 ;

}