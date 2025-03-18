#include "NgayThangNam.h"

int main(){
    int cnt = 0 ; 
    while( cnt < 10 ){
        cout<<"====== Truong hop thu: "<<cnt+1<<" ======\n" ;
        NgayThangNam d1 ;
        d1.Nhap() ;
        cout<<"Ngay hien tai la: ";
        d1.Xuat();
        cout<<"\nNgay tiep theo la: ";
        d1.NgayThangNamTiepTheo().Xuat() ;
        cout<<endl;
        cnt++;
    }
   
    return 0 ; 
}