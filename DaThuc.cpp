#include "DaThuc.h"
//=================== Class HangTu ===================//
ostream& operator<<( ostream &out , const HangTu &h){
    if( h.iHeSo == 0 ){// Nạp chồng toán tử xuất
        out<<"  ";
        return out ; 
    }
    else if ( h.iHeSo > 0 ) out<<" +"<<h.iHeSo; 
    else if ( h.iHeSo < 0 ) out<<" "<<h.iHeSo;

    if( h.iBac !=0 ) cout<<"x^"<<h.iBac;
    return out;
}
HangTu::HangTu(float h , int b): iHeSo(h) , iBac(b) {}
//=================== Class  DaThuc ===================//
void DaThuc::TinhGiaTri(){ // tính giá trị tại x0
    cout<<"Nhap gia tri x0: ";
    cin>>x0; 
    for( int i = 0 ; i <= iBacCaoNhat ; i++ ){
        iGiaTri  += iHam[i].iHeSo*pow(x0,float(i) );
    }
}
double DaThuc::NhanGiaTri(){ return iGiaTri ;}
void DaThuc::NhapDaThuc(){ //Nhập 1 da thức theo thứ tự bật tăng dần 
    cout<<"Nhap bac cao nhat: ";
    cin>>iBacCaoNhat;
    for( int i = 0 ; i <= iBacCaoNhat ; i++){
        cout<<"Nhap he so cua hang tu bac "<<i<<" : ";
        float heSo ; 
        cin>>heSo; 
        iHam.push_back( HangTu(heSo,i) ) ;
    }
}

void DaThuc::XuatDaThuc(){ //xuất 1 da thức theo thứ tự bật giảm dần
    if( iHam.empty() ) return ; 
    cout<<"f(x) = " ;
    cout<<iHam[iBacCaoNhat].iHeSo<<"x^"<<iHam[iBacCaoNhat].iBac;
    for( int i = iBacCaoNhat -1 ; i >= 0 ; i--){
        cout<<iHam[i];
    }
}
DaThuc DaThuc::operator-(const DaThuc other) const{ // Nạp chồng toán tử trừ
    DaThuc KetQua ; // Để trả về hiệu 2 đa thức
    KetQua.iBacCaoNhat = max( iBacCaoNhat , other.iBacCaoNhat);
    int i = 0 , j = 0 , k = 0 ; 
    while ( k <= KetQua.iBacCaoNhat ){
        float a  = ( i <=iBacCaoNhat) ?  iHam[i].iHeSo : 0 ;
        float b = ( j <= other.iBacCaoNhat) ? other.iHam[j].iHeSo : 0 ;
        KetQua.iHam.push_back( HangTu(a-b,k));
        i++ ; k++ ; j++;
    }
    return KetQua ;
}
DaThuc DaThuc::operator+( const DaThuc other) const{// Nạp chồng toán tử cộng
    DaThuc KetQua ; // Để trả về tổng 2 đa thức
    KetQua.iBacCaoNhat = max( iBacCaoNhat , other.iBacCaoNhat);
    int i = 0 , j = 0 , k = 0 ; 
    while ( k <= KetQua.iBacCaoNhat ){
        float a  = ( i <=iBacCaoNhat) ?  iHam[i].iHeSo : 0 ;
        float b = ( j <= other.iBacCaoNhat) ? other.iHam[j].iHeSo : 0 ;
        KetQua.iHam.push_back( HangTu(a+b,k));
        i++ ; k++ ; j++;
    }
    return KetQua ;
}