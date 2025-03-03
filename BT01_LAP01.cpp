#include<iostream>
using namespace std ;

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

struct PhanSo
{
    int tuSo, mauSo;

    PhanSo(int tu, int mau) {// Khởi tạo constructor
        tuSo = tu;
        if (mau == 0) {
            cout << "Mau so khong the bang 0" << endl;
            exit(1); 
        }
        mauSo = mau;
    }

    PhanSo() : tuSo(0), mauSo(1) {} // Construct mặc định = 0 

    ~PhanSo(){} //Destructor
//Câu 1 : 
    PhanSo rutgon()
    {
       
        if (tuSo == 0) {
            mauSo = 1; 
            return *this;
        }
        
        int sochia = gcd(tuSo, mauSo);
        tuSo /= sochia;
        mauSo /= sochia;
        return *this;
    }

    PhanSo fomat()
    {  
        if (tuSo == 0) {
            mauSo = 1;
            return *this;
        }
        // Nếu cả tử và mẫu đều âm thì chuyển thành phân số dương
        if (tuSo < 0 && mauSo < 0)
        {
            tuSo = abs(tuSo);
            mauSo = abs(mauSo);
        }// Xử lí các trường hợp như tử dương , âm chuyên thành tử âm mẫu dương
        else if (mauSo < 0)
        {
            tuSo = -tuSo;
            mauSo = abs(mauSo);
        }
        return this->rutgon();
    }

    friend istream &operator>>(istream &in, PhanSo &x)
    { //Nhập , sử dụng nạp chồng toán tử
        in >> x.tuSo >> x.mauSo;
        if (x.mauSo == 0) // Nếu mẫu bằng 0 
        {
            cout << "Mau so khong the bang 0, vui long nhap lai" << endl;
            in>>x.tuSo>>x.mauSo;
        }
        return in;
    }

    friend ostream &operator<<(ostream &out, const PhanSo &x)
    {   
        PhanSo temp = x;
        temp.fomat(); 
        
        if (temp.tuSo == 0) {
            out << 0;
            return out;
        }else if(temp.mauSo == 1){ // Nếu mẫu bằng 1 , chỉ in tử số
            out<<temp.tuSo<<" ";
        }else{
            out<<temp.tuSo<<"/"<<temp.mauSo<<" ";
        }

        return out ; 
    }
};
int main(){
    PhanSo p1 , p2 ; 
    cin>>p1>>p2;
    cout<<p1<<p2;

    system("pause");
}
