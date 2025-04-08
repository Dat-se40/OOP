#pragma once
#include <iostream>
#include <vector>
#include <random>

#define MAX 10000       // Giới hạn số có thể tạo 
#define NOTFOUND MAX+2  // Giá trị không tìm thấy

using namespace std;

void XuLiUoc(int n); // Tạo bảng đánh dấu số nguyên tố
int TaoSoNgauNhien(int nn, int ln); // Tạo số ngẫu nhiên

void merge(vector<int>& arr, int left, int mid, int right);
void mergeSort(vector<int>& arr, int left, int right);

class cArray {
    int SoLuongPhanTu;
    vector<int> myArray;

public:
    cArray();
    void TaoMangNgauNhien();
    void XuatMang();
    bool MangTangDan();
    int SoleNhoNhat();
    int SoNguyenToLonNhat();
    void SapXep();
};
