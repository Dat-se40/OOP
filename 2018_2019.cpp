#include <iostream>
#include <string>
#include <vector>

using namespace std;
class YeuTo
{
protected:
    float chiSo;
    string muc;
    char ten;

public:
    YeuTo(float c = 0, string m = " ", char t = ' ') : chiSo(c), muc(m), ten(t) {}
    void Nhap()
    {
        cout << ten << " : ";
        cin >> chiSo;
    }
    void Xuat()
    {
        cout << ten << ": " << chiSo << " ";
    }
    void TinhMuc()
    {
        if (chiSo >= 70)
            muc = "cao";
        else if (chiSo <= 30)
            muc = "thap";
        else
            muc = "Khong xac dinh ";
    }
    virtual string NhanDanhGia() = 0;

    string GetMuc() { return muc; }
    char GetTen() { return ten; }
    float GetChiSo() { return chiSo; }
};
class O : public YeuTo
{
public:
    O() : YeuTo(0, " ", 'O') {}

    string NhanDanhGia()
    {
        YeuTo::TinhMuc();
        if (muc == "cao")
            return "Y tuong moi me, thich tu do ";
        else if (muc == "thap")
            return "Kha bao thu";
        return muc;
    }
};
class C : public YeuTo
{
public:
    C() : YeuTo(0, " ", 'C') {}

    string NhanDanhGia()
    {
        YeuTo::TinhMuc();
        if (muc == "cao")
            return "Cham chi, chiu ap luc tot ";
        else if (muc == "thap")
            return "Thieu ki luat va tot chuc ";
        return muc;
    }
};
class E : public YeuTo
{
public:
    E() : YeuTo(0, " ", 'E') {}

    string NhanDanhGia()
    {
        YeuTo::TinhMuc();
        if (muc == "cao")
            return "Nhiet tinh,giao tiep tot ";
        else if (muc == "thap")
            return "Ngai giao tiep, khong thich noi bat ";
        return muc;
    }
};
class A : public YeuTo
{
public:
    A() : YeuTo(0, " ", 'A') {}

    string NhanDanhGia()
    {
        YeuTo::TinhMuc();
        if (muc == "cao"){
             return "Co mo,dong cam ";
        }
        else if (muc == "thap")
            return "Dat loi ich len hang dau,canh tranh cao ";
        return muc;
    }
};
class N : public YeuTo
{
public:
    N() : YeuTo(0, " ", 'N') {}

    string NhanDanhGia()
    {
        YeuTo::TinhMuc();
        if (muc == "cao")
            return "Thuong co cam xuc tieu cuc ";
        else if (muc == "thap")
            return "Kiem soat duoc cam xuc ";
        return muc;
    }
};
class Nguoi
{
private:
    YeuTo *ocean[5] = {NULL, NULL, NULL, NULL, NULL};
    bool coNguyCo;

public:
    Nguoi() : coNguyCo(false)
    {
        ocean[0] = new O();
        ocean[1] = new C();
        ocean[2] = new E();
        ocean[3] = new A();
        ocean[4] = new N();
    }
    void Nhap()
    {
        for (int i = 0; i < 5; i++)
        {
            ocean[i]->Nhap() ; 
        }
    }
    void Xuat()
    {
        for (int i = 0; i < 5; i++)
        {
            ocean[i]->Xuat();
            cout << ocean[i]->NhanDanhGia() << " \n";
        }
    }
    void XetNguyCo(){
        for (int i = 0; i < 5; i++)
        {
            ocean[i]->TinhMuc() ; 
        }
        coNguyCo = ocean[1]->GetMuc() == "thap" 
                    && ocean[4]->GetMuc() == "cao" && ocean[2]->GetMuc() == "thap";
    }
    bool NguyCo(){ return coNguyCo ; }
    ~Nguoi(){
        for(YeuTo* yt : ocean ){
            delete yt ; 
        }
    }
};
class DanhSach{
private: 
    vector<Nguoi> ds ; 
    int soLuong; 
public: 
    DanhSach() : ds({}) , soLuong(0) {}

    void NhapDS(){
        cout<<"-> Nhap so luong danh sach ";
        cin>>soLuong ;
        ds.resize(soLuong);
        for( int i = 0 ; i <soLuong ; i++){
            cout<<"--> Nhap thong tin nguoi thu "<<i<<"\n";
            ds[i].Nhap();
        }
    }
    Nguoi TruyCap(int x) {
        if ( x < 0 || x >= soLuong) return Nguoi() ; 
        else{
            return ds[x];
        }
    }
    void DanhSachNguoiCoNguyCo(){
        for(int i = 0 ; i < soLuong ; i++){
            ds[i].XetNguyCo() ; 
            if ( ds[i].NguyCo() ){
                cout<<"Nguoi thu "<<i<<"\n";
                ds[i].Xuat() ; 
            }
        }
    }

};
int main()
{   
    DanhSach l1 ; 
    l1.NhapDS() ; 
    l1.TruyCap(0).Xuat();
    l1.DanhSachNguoiCoNguyCo() ; 
    return 0;
}