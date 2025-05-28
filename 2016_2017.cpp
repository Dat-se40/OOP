#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Cong
{
protected:
    string _loaiCong;
    string _nguoiGacCong;

public:
    Cong(string loai = "", string ngGac = "") : _loaiCong(loai), _nguoiGacCong(ngGac) {}
    virtual bool XetQuaCong(float &chiSo){return true;};
    virtual void NhapThongTin(){};
    virtual string GetLoaiCong()
    {
        return _loaiCong;
    }
};

class CongGiaoThuong : public Cong
{
private:
    float _donGia;
    int _soHang;

public:
    CongGiaoThuong(string loai = "Giao Thuong", string ngGac = "Ten Lai Buon",
                   float donGia = 0, int soHang = 0) : Cong(loai, ngGac), _donGia(donGia), _soHang(soHang) {}
    bool XetQuaCong(float &chiSo) override
    {
        float giaGiaoDich = _donGia * _soHang;
        if (giaGiaoDich > chiSo)
            return false;
        else
        {
            chiSo -= giaGiaoDich;
            return true;
        }
    }
    void NhapThongTin() override
    {
        cout << "Nhap don gia: ";
        cin >> _donGia;
        cout << "Nhap so luong hang hoa :";
        cin >> _soHang;
    }
};
class CongHocThuat : public Cong
{
private:
    float _triTue;

public:
    CongHocThuat(string loai = "Hoc Thuat ", string ngGac = "Nha Hien Triet",
                 float triTue = 0) : Cong(loai, ngGac), _triTue(triTue) {}
    bool XetQuaCong(float &chiSo) override
    {
        return chiSo > _triTue;
    }
    void NhapThongTin() override
    {
        cout << "Nhap chi so tri tue: ";
        cin >> _triTue;
    }
};
class CongSucManh : public Cong
{
private:
    float _sucManh;

public:
    CongSucManh(string loai = "Suc Manh", string ngGac = "Nha Hien Triet",
                float sucManh = 0) : Cong(loai, ngGac), _sucManh(sucManh) {}
    bool XetQuaCong(float &chiSo) override
    {
        if (_sucManh > chiSo)
            return false;
        else
        {
            chiSo -= _sucManh;
            return true;
        }
    }
    void NhapThongTin() override
    {
        cout << "Nhap chi so suc manh: ";
        cin >> _sucManh;
    }
};
class GameControl
{
private:
    int _soCong;
    vector<Cong *> _lauDai;
    float _sucManh_HoangTu;
    float _soTien_HoangTu;
    float _triTue_HoangTu;
    void NhapThongTinLauDai(){
        cout<<"====== Nhap thong tin cac cong ======= \n";
        cout<<"Nhap so cong: "; cin>>_soCong ; 
        _lauDai.resize(_soCong);
        for( int i =0 ; i < _soCong ; i++){
            cout<<"* Nhap thong tin cong thu: "<<i+1<<" *\n";
            if( i %2 == 0 ){
                _lauDai[i] = new CongGiaoThuong() ; 
            }else if ( i %3 == 0 ){
                _lauDai[i] = new CongHocThuat() ; 
            }else{
                _lauDai[i] = new CongSucManh() ;
            }
            cout<<"   |Cong "<<_lauDai[i]->GetLoaiCong()<<"|\n";
            _lauDai[i]->NhapThongTin() ; 
        }
    }
    void NhapThongTinHoangTu(){
        cout<<"====== Nhap chi so cua Hoang Tu ======= \n";
        cout<<"Nhap chi so suc manh: " ; cin>>_sucManh_HoangTu ; 
        cout<<"Nhap chi so tri tue: "; cin>>_triTue_HoangTu ; 
        cout<<"Nhap so tien hien co: "; cin>>_soTien_HoangTu ; 
    }
    void XuatThongTinHoangTu(){
        cout<<"====== Thong tin cua Hoang Tu ======= \n";
        cout<<"1. Suc manh: "<<_sucManh_HoangTu<<endl ; 
        cout<<"2. Tri tue: "<<_triTue_HoangTu<<endl;  
        cout<<"3. So Tien: "<<_soTien_HoangTu<<endl ; 
    }
    bool VuotCong(Cong* congDangXet){
        string loaiCong = congDangXet->GetLoaiCong(); 
        if( loaiCong == "Giao Thuong"){
            return congDangXet->XetQuaCong(_soTien_HoangTu);
        }else if ( loaiCong == "Suc Manh"){
            return congDangXet->XetQuaCong(_sucManh_HoangTu);
        }else if ( loaiCong == "Hoc Thuat"){
            return congDangXet->XetQuaCong(_triTue_HoangTu);
        }
        return true ;
    }
    bool VuotLauDai(){
        for( int i = 0 ; i < _soCong ; i++){
            if ( VuotCong(_lauDai[i]) == false ) return false ; 
        }
        return true  ;
    }
public:
    void Run(){
        NhapThongTinLauDai() ; 
        NhapThongTinHoangTu() ; 
        cout<<"============================\n";
        if( VuotLauDai() ){
            cout<<"> Giai cuu cong thanh cong <\n";
            XuatThongTinHoangTu() ; 
        }else{
            cout<<"> Hoang tu da that bai <\n";
        }
        cout<<"============================\n";
    }
};
int main()
{
    GameControl testGame ; 
    testGame.Run() ;
    system("pause");
    return 0 ; 
}
