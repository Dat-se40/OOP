#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class KyHieu
{
protected:
    float _truongDo;

public:
    KyHieu(float td = 0);
    void nhapTruongDo();
    virtual void nhap() = 0;
    virtual void xuat() = 0;
    virtual char nhanCaoDo() = 0;
    virtual ~KyHieu() {} 
};

class NotNhac : public KyHieu
{
    char _caoDo;
    inline static unordered_map<char, int> g_stt = { // Ở đây
        {'C', 0}, {'D', 1}, {'E', 2}, {'F', 3}, {'G', 4}, {'A', 5}, {'B', 6}
    };
public:
    NotNhac(char cd = ' ', float td = 0);
    void nhap();
    void xuat();
    char nhanCaoDo();
    bool operator<(KyHieu *other);
};
class NotLang : public KyHieu
{
public:
    NotLang(float td = 0);
    void nhap();
    void xuat();

    char nhanCaoDo();
};
class BanNhac
{
private:
    vector<KyHieu *> _banNhac;
    void NhapDonKyHieu();
    void SoanBanNhac();
    void XuatBanNhac();
    void demNotLang();
    vector<KyHieu *> notCaoNhat();

public:
    BanNhac();
    void run();
    ~BanNhac();
};
int main()
{
    BanNhac bestoVen ;
    bestoVen.run();
    system("pause");
    return 0;
}

KyHieu::KyHieu(float td) : _truongDo(td) {}
void KyHieu::nhapTruongDo()
{
    cout << "Tron(4) , Not trang(2), Den(1) , Moc don(0.5) , Moc kep(0,25) , Moc tam(0,125) , Moc tu (0.0625)\n";
    cin >> _truongDo;
}

NotNhac::NotNhac(char cd, float td) : _caoDo(cd), KyHieu(td) {}

void NotNhac::nhap()
{
    cin >> _caoDo >> _truongDo;
}
void NotNhac::xuat()
{
    cout << _caoDo << _truongDo << " ";
}
char NotNhac::nhanCaoDo() { return _caoDo; }
bool NotNhac::operator<(KyHieu *other)
{
    NotNhac *nn = dynamic_cast<NotNhac *>(other);
    if (nn)
        return g_stt[_caoDo] < g_stt[nn->nhanCaoDo()];
    return false;
}
NotLang::NotLang(float td) : KyHieu(td) {}

void NotLang::nhap()
{
    cout << _truongDo;
}
void NotLang::xuat()
{
    cout << 'Z' << _truongDo << " ";
}
char NotLang::nhanCaoDo() { return 'Z'; }

BanNhac::BanNhac() { _banNhac = {}; }
void BanNhac::NhapDonKyHieu()
{
    cout << "Do(C) , Re(D) , Mi(E) , Fa(F) , Sol(G) , La(A) , Si(B) , Lang(Z)\n";
    char luaChon;
    cin >> luaChon;
    KyHieu *moiVo = nullptr;
    if (luaChon == 'Z')
        moiVo = new NotLang;
    else
        moiVo = new NotNhac(luaChon);
    moiVo->nhapTruongDo();
    _banNhac.push_back(moiVo);
}
void BanNhac::SoanBanNhac()
{
    int n;
    cout << "So luong not nhac ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        NhapDonKyHieu();
    }
}
void BanNhac::XuatBanNhac()
{
    cout << "Ban nhac : ";
    for (int i = 0; i < _banNhac.size(); i++)
    {
        _banNhac[i]->xuat();
    }
}
void BanNhac::demNotLang()
{
    int cnt = 0;
    for (int i = 0; i < _banNhac.size(); i++)
    {
        if (_banNhac[i]->nhanCaoDo() == 'Z')
            cnt++;
    }
    cout << "-> Ban nhac co " << cnt << " not lang \n";
}
vector<KyHieu *> BanNhac::notCaoNhat()
{
    vector<KyHieu *> ketQua;
    KyHieu *KH = new NotNhac('C', 0.0625);
    for (auto k : _banNhac)
    {
        if (k->nhanCaoDo() != 'Z' && KH < k)
            KH = k;
    }
    for (auto k : _banNhac)
    {
        if (k->nhanCaoDo() != 'Z' && k->nhanCaoDo() == KH->nhanCaoDo())
            ketQua.push_back(k);
    }
    return ketQua;
}
void BanNhac::run()
{
    SoanBanNhac();
    if (_banNhac.size() != 0  )
    {
        demNotLang(); 
        cout<<"Not co cao dong cao nhat: ";
        vector<KyHieu*> kq =  notCaoNhat() ;
        for ( KyHieu* k : kq) k->xuat() ;
    }
}
BanNhac::~BanNhac(){
    for (int i =0 ; i < _banNhac.size() ; i++){
        delete _banNhac[i];
    }
    _banNhac.clear() ;
}