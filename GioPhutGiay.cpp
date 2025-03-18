#include "GioPhutGiay.h"

void GioPhutGiay::Nhap(){
    do{//Kiểm tra giờ không âm
        cout<<"Nhap so gio: ";
        cin>>iGio ; 
    }while( iGio < 0 );

    do{// Kiểm tra phút 
        cout<<"Nhap so phut: ";
        cin>>iPhut;
    }while( iPhut < 0 || iPhut >= 60 );

    do{// Kiểm tra giây
        cout<<"Nhap so giay: ";
        cin>>iGiay ; 
    }while( iGiay < 0 || iGiay >= 60 );
}
void GioPhutGiay::Xuat(){
    cout<<iGio<<"gio"<<iPhut<<"phut"<<iGiay<<"giay";
}
GioPhutGiay GioPhutGiay::TinhCongThemMotGiay(){
    GioPhutGiay temp(*this) ; 
    temp.iGiay++ ;
    if ( temp.iGiay == 60){// Sang phút tiếp theo
        temp.iPhut++ ; 
        temp.iGiay = 0 ; 
        if ( temp.iPhut == 60){// Sang giờ tiếp theo
            temp.iPhut = 0 ; 
            temp.iGio++ ; 
        }
    }
    return temp ;
}