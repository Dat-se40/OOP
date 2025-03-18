#include "PhanSo.h"

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
        cout<<"0\n";
        return;
    }else if( iMau == 1){
        cout<<iTu<<endl;
        return ;  
    }else if( iMau < 0 && iTu > 0 ){
        iMau *= -1; 
        iTu *= -1;
    }else if(iTu == iMau){
        cout<<1<<endl;
        return;
    }

    cout<<iTu<<"/"<<iMau;
    cout<<endl;
     
}
PhanSo PhanSo::Tong(PhanSo a){// Cộng 2 phân số
    return PhanSo( a.iTu*iMau + iTu*a.iMau, iMau*a.iMau );
}

PhanSo PhanSo::Hieu(PhanSo a){//Trừ 2 phân số
    return PhanSo( a.iTu*iMau - iTu*a.iMau , iMau*a.iMau );
}

PhanSo PhanSo::Tich(PhanSo a){//Nhân 2 phân số
    return PhanSo( a.iTu*iTu, iMau*a.iMau );
}

PhanSo PhanSo::Thuong(PhanSo a){// Chia 2 phân số
    if(a.iTu == 0){// Kiểm tra phân số chia có bằng 0 
        cout<<"Khong the chia cho";
        return a;
    }
    return PhanSo( iTu*a.iMau , iMau*a.iTu );
}

int PhanSo::SoSanh( PhanSo a){
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
