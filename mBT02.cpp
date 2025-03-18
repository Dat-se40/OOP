#include "PhanSo.h"

int main(){
    int cnt = 0 ; 
    while( cnt < 10 ){
        cout<<"====== Truong hop thu: "<<cnt+1<<" ======\n" ;
        PhanSo p1, p2;
        cout<<"Nhap phan so thu nhat: \n"; p1.Nhap() ; 
        cout<<"Nhap phan so thu hai:\n"; p2.Nhap() ;

        cout<<"Phan so thu nhat sau khi rut gon: " ;p1.RutGon(); p1.Xuat(); 
        cout<<"Phan so thu hai sau khi rut gon: ";p2.RutGon(); p2.Xuat();

        cout<<"Tong: " ; p1.Tong(p2).Xuat() ;
        cout<<"Hieu: " ; p1.Hieu(p2).Xuat() ; 
        cout<<"Tich: " ; p1.Tich(p2).Xuat() ; 
        cout<<"Thuong: ";p1.Thuong(p2).Xuat() ;
        int n = p1.SoSanh(p2);
        if( n == 1 ) {
            cout<<"Phan so thu nhat lon hon phan so thu hai\n";
        }else if ( n ==0 ){
            cout<<"Phan so thu nhat bang hon phan so thu hai\n";
        }else if( n == - 1){
            cout<<"Phan so thu nhat be hon phan so thu hai\n";
        }
        cnt++;
    }
}