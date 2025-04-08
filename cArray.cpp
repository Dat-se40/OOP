#include "cArray.h"

int SoUoc[MAX + 2] = {0};

void XuLiUoc(int n) {  
    for (int i = 0; i <= n; i++) SoUoc[i] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j += i) {
            SoUoc[j]++;
        }
    }
}

int TaoSoNgauNhien(int nn, int ln) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(nn, ln);
    return dis(gen);
}
//============ Merge Sort =====///
void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1, n2 = right - mid;
    vector<int> leftArr(n1), rightArr(n2);

    for (int i = 0; i < n1; i++) leftArr[i] = arr[left + i];
    for (int i = 0; i < n2; i++) rightArr[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        arr[k++] = (leftArr[i] <= rightArr[j]) ? leftArr[i++] : rightArr[j++];
    }
    while (i < n1) arr[k++] = leftArr[i++];
    while (j < n2) arr[k++] = rightArr[j++];
}

void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}
// ======= Class cArrau =======
cArray::cArray() {
    SoLuongPhanTu = 0;
}

void cArray::TaoMangNgauNhien() {
    SoLuongPhanTu = TaoSoNgauNhien(1, 20);
    myArray.clear();
    for (int i = 0; i < SoLuongPhanTu; i++) {
        myArray.push_back(TaoSoNgauNhien(-MAX, MAX));
    }
}

void cArray::XuatMang() {
    for (int x : myArray) cout << x << " ";
}

bool cArray::MangTangDan() {
    for (size_t i = 1; i < myArray.size(); i++) {
        if (myArray[i] < myArray[i - 1]) return false;
    }
    return true;
}

int cArray::SoleNhoNhat() {
    int NhoNhat = NOTFOUND;
    bool found = false ; 
    for (int x : myArray) {
        if (x % 2 != 0) {
            if (!found || x < NhoNhat) {
                NhoNhat = x;
                found = true;
            }
        }
    }
    return found ? NhoNhat : NOTFOUND;
}

int cArray::SoNguyenToLonNhat() {
    int LonNhat = -1 ;
    for (int x : myArray) {
        if ( x < 0) continue; 
        if (x > 0 && SoUoc[x] == 2 && x > LonNhat) LonNhat = x;
    }
    return (SoUoc[LonNhat] == 2 || LonNhat > 0 ) ? LonNhat : NOTFOUND;
}

void cArray::SapXep() {
    mergeSort(myArray, 0, myArray.size() - 1);
}
