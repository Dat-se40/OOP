#include<iostream>
using namespace std;
double sin( double x , unsigned int n ){

    double tu  =  x ;
    long long int mau = 1 ; 
    double sinx = tu/mau ; 
    int dau = -1 ;
    for ( int i  = 1 ; i <= n ; i++){
        tu = tu*x*x; // x^(2i + 1)
        mau = mau*(2*i)*(2*i + 1);  //(2i+1)!
        sinx += dau*(tu/mau); // Cộng dồn vào sinx
        dau *= -1; // Đổi dấu
    }
    return sinx;
};
int main(){

    double x ;
    int n ;
    cin>>x>>n ; 
    cout<<sin(x,n);

    return 0;
}
