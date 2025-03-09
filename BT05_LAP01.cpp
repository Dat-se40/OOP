#include <iostream>
#include <string>
using namespace std;

class Date
{
private:
    int day;
    int month;
    int year;
    int limit_day;// giới hạn ngày của tháng
    string DayOfWeek;

public:
    Date() {}

    bool isLeapYear()// Kiểm tra năm nhuận
    {
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }

    void CalcLimitDay()
    {
        if (month == 1 || month == 3 || month == 5 || month == 7 ||
            month == 8 || month == 10 || month == 12)
        {
            limit_day = 31;
        }
        else if (month == 2)
        {
            limit_day = isLeapYear() ? 29 : 28;
        }
        else
        {
            limit_day = 30;
        }
    }

    friend istream &operator>>(istream &in, Date &d1)
    {
        cout << "Nhap nam: ";
        in >> d1.year;

        do
        {
            cout << "Nhap thang: ";
            in >> d1.month;
        } while (d1.month < 1 || d1.month > 12);

        d1.CalcLimitDay();

        do
        {
            cout << "Nhap ngay: ";
            in >> d1.day;
        } while (d1.day < 1 || d1.day > d1.limit_day);

        return in;
    }

    friend ostream &operator<<(ostream &out, const Date &d1)
    {
        out << d1.month << "/" << d1.day << "/" << d1.year;
        return out;
    }

    Date PreviousDay()
    {
        Date PreDay = *this;
        PreDay.day--;

        if (PreDay.day == 0)
        {
            PreDay.month--;
            if (PreDay.month == 0)
            {
                PreDay.month = 12;
                PreDay.year--;
            }
            PreDay.CalcLimitDay();
            PreDay.day = PreDay.limit_day;
        }
        return PreDay;
    }

    Date NextDay()
    {
        Date NDay = *this;
        NDay.day++;

        if (NDay.day > NDay.limit_day)
        {
            NDay.day = 1;
            NDay.month++;
            if (NDay.month > 12)
            {
                NDay.month = 1;
                NDay.year++;
            }
            NDay.CalcLimitDay(); // Fix lỗi khi chuyển sang tháng mới
        }
        return NDay;
    }

    string getDayOfWeek()
    {
        int temp_month = month;
        int temp_year = year;

        if (temp_month < 3)
        {
            temp_month += 12;
            temp_year -= 1;
        }

        int k = temp_year % 100;
        int j = temp_year / 100;

        int h = (day + (13 * (temp_month + 1)) / 5 + k + (k / 4) + (j / 4) + (5 * j)) % 7;

        string days[] = {"Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};
        DayOfWeek = days[h];
        return DayOfWeek;
    }
};

int main()
{
    Date d1;
    int cnt = 5;
    while (cnt < 10)
    {
        cout << "Case: " << cnt << endl;
        cin >> d1;
        cout << "Thu cua ngay hien tai: " << d1.getDayOfWeek() << endl;
        // cout << "Ngay truoc do: " << d1.PreviousDay() << endl;
        // cout << "Ngay ke tiep: " << d1.NextDay() << endl;
        cnt++;
    }

    return 0;
}
