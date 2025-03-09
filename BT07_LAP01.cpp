#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <limits>
#include <algorithm>
#define Lendl cout<<endl
using namespace std;

bool isValidName(const string &name);       // kiểm tra tên hợp lệ
void formatName(string &name);              // Chuẩn hóa tên
float getValidScore(const string &subject); // Nhập điểm
class Student
{
private:
    float math;
    float eng;
    float viet;
    float avg;       // điểm trung bình
    string capicity; // học lực
    string name;

public:
    friend class StudentManager;

    Student() // Constuctor dùng để ghi thông tin của sinh viên
    {
        WriteInfor();
        CalcAvg();
        Classificate();
    }

    void WriteInfor()
    {
        do
        {
            cout << "Nhap ten hoc sinh: ";
            getline(cin, name);
        } while (!isValidName(name));
        formatName(name);

        math = getValidScore("Toan");
        eng = getValidScore("Tieng Anh");
        viet = getValidScore("Ngu Van");
    }
    void CalcAvg()
    { // tính điểm trung bình
        avg = (2 * math + eng + viet) / 4;
    }

    void Classificate()
    { // Phân loại học sinh
        if (avg >= 9)
        {
            capicity = "Xuat Sac";
        }
        else if (avg >= 8 && avg < 9)
        {
            capicity = "Gioi";
        }
        else if (avg >= 6.5 && avg < 8)
        {
            capicity = "Kha";
        }
        else if (avg >= 5 && avg < 6.5)
        {
            capicity = "Trung Binh";
        }
        else if (avg < 5)
        {
            capicity = "Yeu";
        }
    }

    void GetInfor()
    {
        this->CalcAvg();
        this->Classificate();
        cout << name << endl;
        cout << "Diem toan: " << math << endl
             << "Diem Tieng Anh: " << eng << endl
             << "Diem Ngu Van: " << viet << endl;
        cout << "Diem trung binh: " << avg << "\nHoc Luc : " << capicity << endl;
    }
};
class StudentManager
{
private:
    int Number_Student;
    vector<Student> Infor; // Dùng để quản lí danh sách học sinh
public:
    StudentManager()
    {
        Number_Student = 0;
    }
    void AddStudent()
    { // Điền thông tin của n sinh viên
        cout << "So luong hoc sinh: ";
        cin >> Number_Student;
        cin.ignore();
        for (int i = 0; i < Number_Student; i++)
        {
            Student temp;
            Infor.push_back(temp);
        }
    }

    void DisplayStudent()
    {
        if (Infor.empty())
        {
            cout << "Khong co du lieu hoc sinh: ";
            return;
        }
        for (int i = 0; i < Number_Student; i++)
        {
            cout << "Thong tin cua hoc sinh thu: " << i + 1 << endl;
            Infor[i].GetInfor();
            cout << endl;
        }
    }

    Student HighestAvg()
    { // Tìm và trả về học sinh có điêm trung bình cao nhất
        float HighestScore = Infor[0].avg, currScore = 0;
        Student HavingHighest(Infor[0]);

        for (int i = 0; i < Number_Student; i++)
        {
            currScore = Infor[i].avg;
            if (currScore >= HighestScore)
            {
                HighestScore = currScore;
                HavingHighest = Infor[i];
            }
        }
        return HavingHighest;
    }

    vector<Student> LowestMathScore()
    { // Trả về danh sách học sinh có điểm toán thấp nhất
        vector<Student> result;
        if (Infor.empty())
            return result; // Nếu danh sách rỗng, trả về danh sách rỗng

        // Tìm điểm toán thấp nhất
        double minMath = Infor[0].math;
        for (const auto &student : Infor)
        {
            if (student.math < minMath)
            {
                minMath = student.math;
            }
        }

        // Lưu danh sách học sinh có điểm toán thấp nhất
        for (const auto &student : Infor)
        {
            if (student.math == minMath)
            {
                result.push_back(student);
            }
        }

        return result;
    }

    vector<Student> FindStudent()
    { // Tim kiem danh sach hoc sinh theo tu khoa

        vector<Student> ans;

        string lowerKey;
        cout << "Nhap ten ban muon tim ( khong can nhap day du ten): ";
        getline(cin, lowerKey);

        transform(lowerKey.begin(), lowerKey.end(), lowerKey.begin(), ::tolower);
        // Chuyển về chữ thường để tìm kiếm
        for (int i = 0; i < Number_Student; i++)
        {
            string currName = Infor[i].name;
            // Chuyển tên thành chữ thường
            transform(currName.begin(), currName.end(), currName.begin(), ::tolower);
            if (currName.find(lowerKey) != string::npos)
            {
                ans.push_back(Infor[i]);
            }
        }
        return ans; // Trả về NULL khi không tìm kiếm được
    }
};
int main()
{
    

    int cnt = 2;
    while (cnt < 11)
    {   
        StudentManager ClassA;
        cout<<"Case: "<<cnt<<endl;
        ClassA.AddStudent();

        cout<<"\nHoc sinh co diem trung binh cao nhat: ";
        ClassA.HighestAvg().GetInfor();

        cout<<"\nDanh sach hoc sinh co diem toan thap nhat: ";
        vector<Student> lowest = ClassA.LowestMathScore();
        for (Student a : lowest)
        {
            a.GetInfor();
        }

        vector<Student> find = ClassA.FindStudent();
        for (Student a : find)
        {
            a.GetInfor();
        }
        cnt++;

        Lendl;
    }

    system("pause");
    return 0;
}

// Hàm kiểm tra họ tên hợp lệ (không chứa số và có độ dài hợp lý)
bool isValidName(const string &name)
{
    if (name.length() < 2 || name.length() > 50)
        return false; // Giới hạn độ dài hợp lý

    for (char c : name)
    {
        if (isdigit(c))
            return false; // Không chứa số
    }
    return true;
}

// Hàm chuẩn hóa họ tên (viết hoa chữ cái đầu, còn lại viết thường)
void formatName(string &name)
{
    stringstream ss(name);
    string word, formattedName;

    while (ss >> word)
    {
        word[0] = toupper(word[0]);
        for (size_t i = 1; i < word.length(); i++)
        {
            word[i] = tolower(word[i]);
        }
        formattedName += word + " ";
    }

    if (!formattedName.empty())
    {
        formattedName.pop_back(); // Xoa dau cach cuoi cung
    }

    name = formattedName;
}
// Nhập điểm , và kiểm có đúng chuẩn không
float getValidScore(const string &subject)
{
    float score;
    while (true)
    {
        cout << "Nhap diem " << subject << ": ";
        cin >> score;

        if (cin.fail() || score < 0 || score > 10)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Diem khong hop le! Nhap lai.\n";
        }
        else
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return score;
        }
    }
}