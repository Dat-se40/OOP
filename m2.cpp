#include "DaGiac.h"

int main(){

    int cnt = 0 ; 
    while( cnt <= 10){
        cout<<"===== Truong hop thu "<<cnt+1<<" ======\n";
        DaGiac test ;

        test.Nhap() ; 
        test.Xuat() ; 
        cout<<"Chu vi cua da giac nay la: "<<test.TinhChuVi()<<endl ;

        test.PhongToThuNho(10);
        test.Xuat() ; 

        test.Quay(3.14) ;
        test.Xuat() ; 

        test.TinhTien(2,3) ; 
        test.Xuat() ;

        cnt++;
    }

    return 0 ; 
}