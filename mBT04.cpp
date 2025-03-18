#include "GioPhutGiay.h"

int main(){
    int cnt = 9 ; 
    while( cnt < 15 ){
        cout<<"====== Truong hop thu: "<<cnt+1<<" ======\n" ;
        GioPhutGiay t1 ; 
        t1.Nhap() ; 
        cout<<" Thoi diem sau 1 giay  "; t1.Xuat();
        cout<<" la: ";t1.TinhCongThemMotGiay().Xuat() ; 
        cout<<endl;
        cnt++;
    }
    return 0 ; 
}