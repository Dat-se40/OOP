#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;

const string specialSymbol = "~!@#$%^&*(){}|;'<,./\\-_+=";

class Date {
private:
    int day;
    int month;
    int year;
    int limit_day;

public:
    Date() {}

    bool isLeapYear() {
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }

    void CalcLimitDay() {
        if (month == 1 || month == 3 || month == 5 || month == 7 ||
            month == 8 || month == 10 || month == 12) {
            limit_day = 31;
        } else if (month == 2) {
            limit_day = isLeapYear() ? 29 : 28;
        } else {
            limit_day = 30;
        }
    }

    friend istream &operator>>(istream &in, Date &d1) {
        cout << "Nhap nam: ";
        in >> d1.year;
        if (in.fail()) {
            in.clear();
            in.ignore(numeric_limits<streamsize>::max(), '\n');
            d1.year = 2025; // Default value
            cout << "Nam khong hop le. Da dat mac dinh la 2025.\n";
        }

        do {
            cout << "Nhap thang: ";
            in >> d1.month;
            if (in.fail()) {
                in.clear();
                in.ignore(numeric_limits<streamsize>::max(), '\n');
                d1.month = 1; // Default value
                cout << "Thang khong hop le. Da dat mac dinh la 1.\n";
            }
        } while (d1.month < 1 || d1.month > 12);

        d1.CalcLimitDay();

        do {
            cout << "Nhap ngay: ";
            in >> d1.day;
            if (in.fail()) {
                in.clear();
                in.ignore(numeric_limits<streamsize>::max(), '\n');
                d1.day = 1;
                cout << "Ngay khong hop le. Da dat mac dinh la 1.\n";
            }
        } while (d1.day < 1 || d1.day > d1.limit_day);

        in.ignore(numeric_limits<streamsize>::max(), '\n'); // Xóa bộ đệm
        return in;
    }

    friend ostream &operator<<(ostream &out, const Date &d1) {
        out << d1.month << "/" << d1.day << "/" << d1.year;
        return out;
    }

    bool operator<(const Date &operand) const {
        if (year != operand.year) return year < operand.year;
        if (month != operand.month) return month < operand.month;
        return day < operand.day;
    }
};

class flight {
private:
    string code;
    Date FlightDate;
    string destination;
    string origin;
    string time;

public:
    friend class AirLineManager;

    flight() {
        code = "";
        destination = "";
        origin = "";
        time = "";
    }
    void SetFlight() {
        EnterCode();
        cout<<"Nhap noi xuat phat: ";
        EnterPlace(origin);
        cout<<"Nhap noi den: ";   
        EnterPlace(destination);
        EnterTime();
        cout << "Nhap ngay bay: \n";
        cin >> FlightDate;
    }
    void EnterCode(){
        bool isVail ;
        do {
            cout << "Nhap ma chuyen bay: ";
            getline(cin, code);
            isVail = true ; 
            if (code.length() > 5) {
                cout << "Ma chuyen bay phai co 5 ky tu. Moi nhap lai.\n";
                isVail = false;
            }else if (code.find_first_of(specialSymbol) != string::npos) {
                cout << "Ma chuyen bay khong duoc chua ky tu dac biet. Moi nhap lai.\n";
                isVail = false;
            } else {
                for( int i = 0 ; i < code.length() ; i++){
                    if( isspace(code[i]) ){
                        cout << "Ma chuyen bay khong duoc chua khoang trang. Moi nhap lai.\n";
                        isVail = false;
                        break;
                    }
                }
            }
        } while (!isVail);
    }
    
   void EnterPlace( string& s){
        bool isVail  ;
        do {
            getline(cin,s);
            isVail = true ; 

            if(s.length() > 20 || s.length() < 3){
                cout << "Ten dia diem phai tu 3 den 20 ky tu. Moi nhap lai.\n";
                isVail = false;
            }else {
                for ( int i = 0  ; i < s.length() ; i++){
                    if( isdigit(s[i]) || specialSymbol.find(s[i]) != string::npos){
                        cout << "Ten dia diem khong duoc co so hoac ki tu dac biet. Moi nhap lai.\n";
                        isVail = false;
                        break;
                    }
                }
            }
            
        }while(!isVail);
   }
    
    void EnterTime() {
        do {
            cout << "Nhap thoi gian bay (HH:MM): ";
            getline(cin, time);
            bool formatValid = (time.length() == 5 && time[2] == ':' &&
                               isdigit(time[0]) && isdigit(time[1]) &&
                               isdigit(time[3]) && isdigit(time[4]));

            if (!formatValid || time < "00:00" || time > "23:59") {
                cout << "Thoi gian khong hop le. Moi nhap lai \n";
            } else {
                break;
            }
        } while (true);
    }

    void GetInfor() const {
        cout << "Ma chuyen bay: " << code << endl;
        cout << time << " - Ngay bay: " << FlightDate << endl;
        cout << "Xuat Phat tu: " << origin << " -> " << destination << endl;
    }

    int ConvertTimeToMinutes() const {
        int hh = stoi(time.substr(0, 2));  // Lấy giờ
        int mm = stoi(time.substr(3, 2));  // Lấy phút
        return hh * 60 + mm;  // Tổng số phút
    }

    static bool CompareFlight(const flight &a, const flight &b) {
        if (a.FlightDate < b.FlightDate) return true;
        if (b.FlightDate < a.FlightDate) return false;
        return (a.ConvertTimeToMinutes() < b.ConvertTimeToMinutes());
    }
};

class AirLineManager {
private:
    int Number_Flight;
    vector<flight> schedule;

public:
    void SetSchedule() {
        cout << "Nhap so luong chuyen bay: ";
        cin >> Number_Flight;

        if (cin.fail() || Number_Flight <= 0) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            Number_Flight = 1;
            cout << "So luong chuyen bay khong hop le! Da dat la 1.\n";
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        for (int i = 0; i < Number_Flight; i++) {
            cout << "\n=== Nhap thong tin chuyen bay thu " << i + 1 << " ===\n";
            flight temp;
            temp.SetFlight();
            schedule.push_back(temp);
        }
    }

    void DisplaySchedule() {
        cout << "\n====== Bang thong tin lich bay ======\n";
        if (schedule.empty()) {
            cout << "Chua co chuyen bay nao!\n";
            return;
        }

        for (int i = 0; i < schedule.size(); i++) {
            cout << "\n--- Thong tin chuyen bay thu " << i + 1 << " ---\n";
            schedule[i].GetInfor();
        }
    }

    vector<flight> Search() {// Tìm kiếm theo danh sách 
        vector<flight> ans;
        string key;
        cout << "Nhap tu khoa tim kiem: ";
        getline(cin, key);

        if (key.empty()) {
            cout << "Tu khoa tim kiem khong duoc de trong!\n";
            return ans;
        }

        transform(key.begin(), key.end(), key.begin(), ::tolower);
        for (auto &f : schedule) {
            if (MatchesSearchKey(f, key)) ans.push_back(f);
        }

        return ans;
    }
    // Tìm kiếm chuyến bay phù hợp với từ khóa theo mã chuyến bay, nơi đi, nơi đến
    bool MatchesSearchKey(const flight &f, const string &key) {
        vector<string> domain = {f.code, f.destination, f.origin};
        for (string temp : domain) {
            transform(temp.begin(), temp.end(), temp.begin  (), ::tolower);
            if (temp.find(key) != string::npos) return true;
        }
        return false;
    }
    // In ra các danh sách chuyến bay phù hợp
    void DisplaySearchResults(const vector<flight> &results) {
        if (results.empty()) {
            cout << "Khong tim thay chuyen bay nao phu hop!\n";
            return;
        }
        cout << "\n====== Ket qua tim kiem ======\n";
        for (int i = 0; i < results.size(); i++) {
            cout << "\n--- Chuyen bay tim thay " << i + 1 << " ---\n";
            results[i].GetInfor();
        }
    }

    void SortFlights() {
        if (schedule.empty()) {
            cout << "Chua co chuyen bay nao de sap xep!\n";
            return;
        }
        stable_sort(schedule.begin(), schedule.end(), flight::CompareFlight);
        cout << "\n=== Da sap xep lich bay theo ngay va gio ===\n";
    }
    // Các chuyến bay trong 1 ngày được chọn và 1 địa điểm được chọn
    void DisplayFlightsFromOriginOnDate() {
        if (schedule.empty()) {
            cout << "Chua co chuyen bay nao trong lich trinh!\n";
            return;
        }

        string originSearch;
        cout << "Nhap noi xuat phat can tim: ";
        getline(cin, originSearch);

        Date searchDate;
        cout << "Nhap ngay can tim:\n";
        cin >> searchDate;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        vector<flight> filteredFlights;
        for (const auto &f : schedule) {
            if (f.origin == originSearch && !(searchDate < f.FlightDate) && !(f.FlightDate < searchDate)) {
                filteredFlights.push_back(f);
            }
        }

        if (filteredFlights.empty()) {
            cout << "Khong co chuyen bay nao tu " << originSearch << " vao ngay " << searchDate << ".\n";
            return;
        }

        cout << "\nDanh sach cac chuyen bay xuat phat tu " << originSearch << " vao ngay " << searchDate << ":\n";
        for (const auto &f : filteredFlights) {
            f.GetInfor();
        }
    }

    void CountFlightsBetweenLocations() {// Tất cả chuyến bay đi cùng 1 nơi đến cùng 1 nơi
        if (schedule.empty()) {
            cout << "Chua co chuyen bay nao trong lich trinh!\n";
            return;
        }

        string start, destination;
        cout << "Nhap noi xuat phat: ";
        getline(cin, start);
        cout << "Nhap noi den: ";
        getline(cin, destination);

        int count = count_if(schedule.begin(), schedule.end(), [&](const flight &f) {
            return f.origin == start && f.destination == destination;
        });

        cout << "So luong chuyen bay tu " << start << " den " << destination << " la: " << count << ".\n";
    }
};

int main() {
    flight a1 ;
    AirLineManager VietNamAirLine;
    VietNamAirLine.SetSchedule();
    VietNamAirLine.SortFlights();
    VietNamAirLine.DisplaySchedule();
    VietNamAirLine.Search();
    VietNamAirLine.DisplaySearchResults(VietNamAirLine.Search());
    system("pause");
    return 0;
}