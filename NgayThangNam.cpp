#include "NgayThangNam.h"

void NgayThangNam:: Nhap(){
    do{//Năm phải dương 
        cout<<"Nhap nam: ";
        cin>>iNam; 
    }while( iNam <= 0) ;

    do{// Tháng từ 1 -> 12
        cout<<"Nhap thang: ";
        cin>>iThang ; 
    }while( iThang > 12 || iThang <= 0 );

    TinhGioiHanNgay() ;

    do{ //Ngày từ 1 -> giới hạn ngày của tháng
        cout<<"Nhap ngay: ";
        cin>>iNgay ;
    }while( iNgay > iGioiHanNgay || iNgay <= 0  );

}

void NgayThangNam:: Xuat(){
    cout<<iNgay<<"/"<<iThang<<"/"<<iNam ; 
}

NgayThangNam NgayThangNam:: NgayThangNamTiepTheo(){
    NgayThangNam temp(*this) ; 
    temp.iNgay++ ; 
    if( temp.iNgay > iGioiHanNgay ){// Ví dụ : 32 ngày -> 1 ngày, tháng++
        temp.iThang++;
        temp.iNgay = 1; 
        if( temp.iThang > 12){// VÍ dụ 13 tháng -> 1 tháng , năm++
            temp.iNam++;
            temp.iThang  = 1; 
        }
    }
    temp.TinhGioiHanNgay();
    
    return temp;
}

bool NgayThangNam:: KiemTraNamNhuan(){// Kiểm tra năm nhuận
    if( ( iNam % 4 == 0  && iNam % 100 != 0 ) || iNam%100 == 0  ) return true; 
    return false ; 
}

void NgayThangNam::TinhGioiHanNgay(){// Tính xem tháng đó có bao nhiêu ngày là cao nhất
    if( iThang == 1 || iThang == 3 || iThang == 5 || iThang == 7
        || iThang == 8 || iThang == 10 || iThang == 12 ) iGioiHanNgay = 31 ;
    else if( iThang == 2){
        iGioiHanNgay = ( KiemTraNamNhuan() ) ? 29 : 28 ; 
    }else{
        iGioiHanNgay = 30 ; 
    }
    
}