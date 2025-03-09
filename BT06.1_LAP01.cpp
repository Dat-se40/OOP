#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

void input(vector<int> &a)
{
    for (int &x : a)
    {
        cin >> x;
    }
}
vector<int> CreateLPS(vector<int> pattern)
{ // Đánh dấu vị trí xuất hiện đầu tiên của phần tử
    vector<int> lps(pattern.size(), 0);
    int j = 0; // Con trỏ cho tiền tố
    for (int i = 1; i < pattern.size(); i++)
    { // Bắt đầu từ 1 (không tính phần tử đầu tiên)
        while (j > 0 && pattern[i] != pattern[j])
        {
            j = lps[j - 1]; // Quay lui
        }
        if (pattern[i] == pattern[j])
        {
            j++;
            lps[i] = j; // Cập nhật độ dài tiền tố
        }
    }
    return lps;
}

void Knuth_Morris(vector<int> code, vector<int> pattern)
{
    vector<int> lps = CreateLPS(pattern);
    int i = 0, j = 0, cnt = 0;

    while (i < code.size())
    {
        if (code[i] == pattern[j])
        {
            i++;
            j++;
        }
        if (j == pattern.size())
        { // Khi tìm thấy mẫu khớp hoàn toàn
            cout << i - j << " ";
            j = lps[j - 1]; // Quay lại vị trí phù hợp theo LPS
            cnt++;          // tăng biến đếm số lần
        }
        else if (i < code.size() && code[i] != pattern[j])
        {
            if (j != 0)
            {
                j = lps[j - 1]; // Quay lại vị trí có thể tiếp tục
            }
            else
            {
                i++;
            }
        }
    }
    cout << endl;
    cout << "So lan: " << cnt << endl;
}

int main()
{
    int n, m, cnt = 8; // nhập lần lượt độ dài của mảng A  , mảng B
   
    while (cnt < 10)
    {
        cout << "Case: " << cnt << endl;

        cin >> n >> m;

        vector<int> pattern(n, 0);
        vector<int> source(m, 0);

        input(pattern);
        input(source);
        Knuth_Morris(source, pattern);

        cnt++;
    }

    system("pause");
    return 0;
}
