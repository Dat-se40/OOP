#include <iostream>
#include <string>
using namespace std;

int main() {
    int n, m;
    string s1, s2;

    // Nhập độ dài chuỗi
    cout << "Nhap do dai chuoi s1: ";
    cin >> n;
    cout << "Nhap do dai chuoi s2: ";
    cin >> m;

    cin.ignore(); // Bỏ qua ký tự xuống dòng trong bộ đệm

    // Nhập chuỗi s1 với giới hạn n ký tự
    cout << "Nhap chuoi s1: ";
    getline(cin, s1);
    if (s1.length() > n) s1 = s1.substr(0, n); // Giới hạn độ dài

    // Nhập chuỗi s2 với giới hạn m ký tự
    cout << "Nhap chuoi s2: ";
    getline(cin, s2);
    if (s2.length() > m) s2 = s2.substr(0, m); // Giới hạn độ dài

    
    int i = 0;
    bool found = false;
    while (i <= s1.length() - s2.length()) { 
        string temp = s1.substr(i, s2.length());
        if (s2.compare(temp) == 0) { 
            cout << i << " "; // In vị trí xuất hiện
            i += s2.length(); // Bỏ qua phần đã tìm thấy để tối ưu hơn
            found = true;
        } else {
            i++;
        }
    }

    if (!found) cout << "Khong tim thay!" << endl;
    cout << endl;

    system("pause");
    return 0;
}
