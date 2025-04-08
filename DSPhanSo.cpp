#include "DSPhanSo.h"
// ====== Hàm hổ trợ ====== //
int gcd(int a, int b)
{// Hàm tìm ước chung lớn nhất
    a = abs(a);// Xử lí cho cả số âm
    b = abs(b);
    
    if (a == 0) return b;
    if (b == 0) return a;
    
    while (b != 0)// Thuật toán Euclid
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
bool laSoNguyenTo(int n) {
    if (n < 2) return false;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return false;
    }
    return true;
}
//======= Class Phan So ======== //
PhanSo::PhanSo(int t = 0, int m = 1) : iTu(t), iMau(m) {
    if (m == 0) {// Constructor có đối mặt định
        cout << "Loi: Mau so khong the bang 0. Tu dong gan mau = 1.\n";
        iMau = 1;
    }
}
void PhanSo::Nhap(){
    cout<<"Nhap tu so: ";
    cin>>iTu ; 

    do{
        cout<<"Nhap mau so:";
        cin>>iMau;
    }while( iMau == 0 );

}
void PhanSo:: Xuat(){ 
    if ( iTu == 0 ) {// Đưa về đúng định dạng
        cout<<"0";
        return;
    }else if( iMau == 1){
        cout<<iTu;
        return ;  
    }else if( iMau < 0 && iTu > 0 ){
        iMau *= -1; 
        iTu *= -1;
    }else if(iTu == iMau){
        cout<<1;
        return;
    }
    cout<<iTu<<"/"<<iMau; 
}
PhanSo PhanSo::Tong(PhanSo a){// Cộng 2 phân số
    return PhanSo( a.iTu*iMau + iTu*a.iMau, iMau*a.iMau );
}

int PhanSo::SoSanh( PhanSo a) const {
    double deci1 = double(iTu)/iMau ; //Chuyển sang số thập phân
    double deci2 = double( a.iTu) / a.iMau ; 
    if ( deci1 == deci2 ) return 0 ;
    if ( deci1 > deci2 ) return 1 ;
    return -1 ;    
}
void PhanSo:: RutGon(){
    int UocChung = gcd ( iTu , iMau );
    iTu /= UocChung ; 
    iMau /= UocChung ; 
}
PhanSo DSPhanSo::TimPhanSoTuNguyenToMax() {
    if (DanhSach.empty()) return PhanSo(0, 1);

    PhanSo maxPS(0, 1);
    int maxTu = -1;

    for (const auto& ps : DanhSach) {
        if ( laSoNguyenTo(ps.GetTu() ) && ps.GetTu() > maxTu) {
            maxTu = ps.GetTu();
            maxPS = ps;
        }
    }

    if (maxTu == -1) {
        cout << "Khong co phan so nao co tu la so nguyen to!" << endl;
        return PhanSo(0, 1);
    }

    return maxPS;
}
int PhanSo::GetTu() const {  return iTu; }
// ====== Class Danh sach phan so ======  //
void DSPhanSo::NhapDS(){
    cout<<"Nhap so luong phan tu: ";
    cin>>soPhanTu ; 
    for ( int i = 0 ; i < soPhanTu ; i++){
        PhanSo a(0,1) ; 
        cout<<"Nhap phan so thu "<<i+1<<endl ; 
        a.Nhap() ; 
        DanhSach.push_back(a);
    }
}
void DSPhanSo::XuatDS(){
    for ( int i = 0 ; i < soPhanTu ; i++){
        DanhSach[i].Xuat() ;
        cout<<" "; 
    }
}
PhanSo DSPhanSo::TimPhanSoMin(){// Tim phan so nho nhat
    if ( DanhSach.empty()) return PhanSo(0,1);
    PhanSo PSmin( DanhSach[0]);
   for ( int i = 0 ;  i < soPhanTu ; i++){
        if ( PSmin.SoSanh(  DanhSach[i] )  == 1 )   PSmin = DanhSach[i];
   }
   return PSmin ; 
}
PhanSo DSPhanSo::TimPhanSoMax(){ // tim phan so lon nhat
    if ( DanhSach.empty()) return PhanSo(0,1);
    PhanSo PSmax( DanhSach[0]);
    for ( int i = 0 ;  i < soPhanTu ; i++){
        if ( PSmax.SoSanh(  DanhSach[i] )  == -1 )   PSmax = DanhSach[i];
    }
    return PSmax ; 
}

void DSPhanSo::SapXepTangDan(){
    sort(DanhSach.begin(), DanhSach.end(), [](const PhanSo &a, const PhanSo &b) {
        return a.SoSanh(b) == -1; // Nếu a < b thì trả về true để giữ thứ tự
    });
}

void DSPhanSo::SapXepGiamDan(){
    sort(DanhSach.begin(), DanhSach.end(), [](const PhanSo &a, const PhanSo &b) {
        return a.SoSanh(b) == 1; // Nếu a > b thì trả về true để giữ thứ tự
    });
}

PhanSo DSPhanSo::TongPhanSo(){
    PhanSo tong(0,1) ; 
    for ( int i = 0 ; i < soPhanTu ; i++  ){
        tong = tong.Tong(DanhSach[i]);
    }
    return tong ; 
}
