#ifndef CANDIDATE_H
#define CANDIDATE_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>


using namespace std;

class cCandidate {
private:
    string Ma, Ten;
    int Ngay, Thang, Nam;
    double Toan, Van, Anh;

public:
    cCandidate();
    cCandidate(string ma, string ten, int ngay, int thang, int nam,
         double toan, double van, double anh);

    void Nhap();
    void Xuat() const;
    double TongDiem() const;
    
    friend class cListCandidate;
};

class cListCandidate {
private:
    vector<cCandidate> danhSach;

public:
    void NhapDS(int n);
    void XuatDSTren15() const;
    cCandidate TimThiSinhCaoNhat() const;
    void SapXepGiamDan();
    void XuatDS() const;
    void FakeRandomData(int n);
};

#endif
