#include "SoPhuc.h"

    SoPhuc:: SoPhuc( float u , float v) {
        iThuc = u ; 
        iAo = v; 
    }
    
    void SoPhuc::Nhap(){
        cout<<"Nhap phan thuc: "; 
        cin>>iThuc ; 
        cout<<"Nhap phan ao: ";
        cin>>iAo; 
    }
    void SoPhuc::Xuat() {// đúng định ạ a+bi
        if (iThuc == 0 && iAo == 0) {
            cout << "0";
        } else if (iThuc == 0) {
            cout << iAo << "i";
        } else if (iAo == 0) {
            cout << iThuc;
        } else {
            cout << iThuc << (iAo > 0 ? " + " : " - ") << abs(iAo) << "i";
        }
        cout << endl;
    }

    SoPhuc SoPhuc::Tong(SoPhuc a){
        return SoPhuc( a.iThuc + iThuc , a.iAo + iAo);
    }
     SoPhuc SoPhuc::Hieu(SoPhuc a){
        return  SoPhuc( -a.iThuc + iThuc , -a.iAo + iAo);
    }
    SoPhuc SoPhuc::Tich(SoPhuc a){
        return SoPhuc( a.iThuc*iThuc - a.iAo*iAo , iThuc*a.iAo + iAo*a.iThuc );
    }
    SoPhuc SoPhuc::Thuong(SoPhuc a){
        if( a.iAo == 0 && a.iThuc == 0 ){// Kiểm tra số phức chia == 0 
            cout<<"Khong thuc hien duoc phep chia cho ";
            return a;
        }

        float thuc = float( a.iThuc*iThuc + a.iAo*iAo)/(a.iThuc*a.iThuc + a.iAo*a.iAo);
        float ao = float( iThuc*a.iAo - iAo*a.iThuc)/(a.iThuc*a.iThuc + a.iAo*a.iAo);
        return SoPhuc(thuc,-1*ao);
    }