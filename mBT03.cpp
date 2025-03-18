#include "SoPhuc.h" 

int main(){
    int cnt = 0 ; 
    while( cnt < 10 ){
        cout<<"====== Truong hop thu: "<<cnt+1<<" ======\n" ;
        SoPhuc p1, p2;
        cout<<"Nhap so phuc thu nhat: \n"; p1.Nhap() ; 
        cout<<"Nhap so phuc thu hai:\n"; p2.Nhap() ;

        cout<<"Tong: " ; p1.Tong(p2).Xuat() ;
        cout<<"Hieu: " ; p1.Hieu(p2).Xuat() ; 
        cout<<"Tich: " ; p1.Tich(p2).Xuat() ; 
        cout<<"Thuong: ";p1.Thuong(p2).Xuat() ;

        cnt++;
    }
}