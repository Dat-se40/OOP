#include<iostream>
#include<string>
#include<vector>
#include <sstream>
#include <limits>
#include <algorithm>
using namespace std;

// kí tự đặc biệt
const string specialSymbol = " ~!@#$%^&*(){}|;'<,./\\-_+=";
const vector<string> Set_of_Pakage = {"Long Term", "Short Term"};

bool isValidName(const string &name);       // kiểm tra tên hợp lệ
void formatName(string &name);              // Chuẩn hóa tên
void transform(string &key);				// dùng để tìm kiếm 
//Long Term: dai han, short term: ngan ha , Immediate: khong ki han 
class Date{
private:
    int day;
    int month;
    int year;
    int limit_day;// giới hạn ngày của tháng
public:
    Date() {}
    Date( int d , int m , int y): day(d) , month(m), year(y) {}

    friend class Passbook;
    friend class PassBookManager;
    bool isLeapYear()// Kiểm tra năm nhuận
    {
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }

    void CalcLimitDay(){ // tính toán giới hạn ngày của tháng
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

    friend istream &operator>>(istream &in, Date &d1){ // Nhập ngày
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

    friend ostream &operator<<(ostream &out, const Date &d1){// Xuất ngày
        out << d1.month << "/" << d1.day << "/" << d1.year;
        return out;
    }

    bool operator<(const Date &operand) const {// So sánh ngày
        if (year != operand.year) return year < operand.year;
        if (month != operand.month) return month < operand.month;
        return day < operand.day;
    }

 };
const Date Today(3,10,2025); // ngày hien tai//
float interest_rate_Today = 4 ; // lãi suất nếu rút đúng hạng
float early_withdraw_rate_Today  = 0.5; // lãi suất nếu rút sốm

class User{
private:
	string user_code ; 
	string user_name ;
	string IDcard ;	
public: 

	User(){};

	friend class Passbook;
	friend class PassBookManager;

	void SetUserCode(){//Nhap ma
		do{
			cout<<"Nhap ma khach hang: ";
			cin>>user_code;
		}while(!isTrueUserCode() );
		cin.ignore();
	}

	bool isTrueUserCode(){// nhập mã sổ, có kiểm tra
		if( user_code.length() < 0 || user_code.length() > 5 ){
			cout<<"Do dai cua ma phai co so ki tu khong qua 5\n";
			return false;
		}

		for( char idx : user_code){
			if( specialSymbol.find(idx) != string::npos) return false;
		}
		return true ;
	}

	void SetIDcard(){ // nhập chứng minh nhân dân
		do{
			cout<<"Nhap so CMND: ";
			cin>>IDcard;
		}while(!this->isTrueIDcard());
		cin.ignore();
	}

	bool isTrueIDcard(){// kiểm tra số chưng minh nhân dân 
		if(IDcard.empty()){
			cout<<"so CMND khong duoc de trong\n";
		}
		if( IDcard.length() == 9 || IDcard.length() == 12) {

			for( char idx : IDcard){
			if( isdigit(idx) == false){
				cout<<"So CMND chi chua so\n";
				return false ; 
			}
			if(specialSymbol.find(idx) != string::npos){
				cout<<"So CMND chi chua ki tuc dac biet\n";
				return false ; 
			}

		}
		}else{
			cout<<"Do dai cua so CMND la 9 hoac 12\n";
			return false ; 
		}
		
		return true ;
	}

	void SetUserName(){// Nhập tên
		do{
			cout<<"Nhap ten nguoi dung: ";
			getline(cin, user_name);
		}while(!isValidName(user_name));
		formatName(user_name);
	}

	void SetInfor(){
		SetUserName();
		SetUserCode();
		SetIDcard();
	}

	void GetInfor(){
		cout<<"Ten nguoi dung: "<<user_name<<endl;
		cout<<"So chung minh nhan dan: "<<IDcard<<endl;
		cout<<"Ma so nguoi dung: "<<user_code<<endl;
	}

};
class Passbook{
private: 
	string package ; 
	double balance ; 
	Date open_Date ;
	User customer ;
	float interest_rate  = interest_rate_Today; // Lãi xuất tính theo phần trăm 
	double interest; // tien lai
	int tenure_months; // Kỳ hạn gửi (tính theo tháng)
public:
	friend class PassBookManager;
	Passbook(){
		customer.SetInfor();
		GetBalance();
		cout<<"Nhap ngay mo the:\n"; 
		GetOpeningDate();
		//CalcInterest(); 
		cin.ignore();
	};

	void GetBalance(){
		do{
			cout<<"Nhap so tien tiet kiem: ";
			cin>>balance;
		}while( cin.fail() || balance <= 0  );
	}

	void GetInfor(){
		customer.GetInfor();
		cout<<"Ngay mo the: "<<open_Date<<endl;
		//cout<<"So tien co lai: "<<interest<<endl;
	}

	void GetOpeningDate(){
		do{
			cin>>open_Date;
		}while( Today < open_Date );
	}
	void UpdateInterestRate_Package(){// Chọn kỳ hạn , gói cước, áp dụng cho 1 sổ
		int i = 0 ; 
		do{	
			cout<<"\n=====Chon goi tiet kiem=====\n";
			cout<<"1. Ky gui dai han\n";
			cout<<"2. Ky gui ngan han\n";
			cout<<"Nhap lua chon:"; cin>>i ; 
		}while( i < 1 || i> 2);
		package = Set_of_Pakage[i-1];

		// Chọn kỳ hạn gửi
        if (package == "Long Term") {
            do {
                cout << "Nhap ky han gui (toi thieu 6 thang): ";
                cin >> tenure_months;
				cout<<"nNhap phan tram lai xuat: "; 
				cin>>interest_rate_Today;
            } while (tenure_months < 6);
        } else {

            do {
                cout << "Nhap ky han gui (<6 thang): ";
                cin >> tenure_months;
				cout<<"Nhap phan tram lai xuat neu rut som:";
				cin>>early_withdraw_rate_Today;
            } while (tenure_months >= 6 || tenure_months <= 0);

        }
		CalcInterest();
	}
	void CalcInterest(){
		//So thang gui
		int months_elapsed = (Today.year - open_Date.year) * 12 + (Today.month - open_Date.month);

	 	if( tenure_months <= months_elapsed){// Dung ki han 

	 		interest = balance*(interest_rate/100)*(months_elapsed/12.0);
	 	}else{// Rut truoc ki han 

	 		 float early_withdraw_rate = early_withdraw_rate_Today;
            interest = balance * (early_withdraw_rate / 100) * (months_elapsed / 12.0);
	 	}
	}

	double GetInterestRate(){ // Trả về tiền lãi
		return 	interest;
	}

	bool MatchesKey(const string& key){// tìm kiếm
		string lowerCode = customer.user_code;
		 transform(lowerCode);
		return key == customer.IDcard|| key == lowerCode;
	}

	void Withdraw() {// rút tiền 
    	double amount;
    	cout << "Nhap so tien muon rut: ";
    	cin >> amount;

    	if (amount <= 0) {
        	cout << "So tien khong hop le!\n";
        	return;
   	 	}

    	if (amount > balance) {
        	cout << "So du khong du de rut!\n";
        	return;
    	}

    	// Cập nhật lại số dư và xuất tiền
    	balance -= amount;
    	cout << "Ban da rut thanh cong: " << amount << " VND\n";
    	cout << "So du con lai: " << balance + interest<< " VND\n";
}


	float GetInterest(){ return interest; }
};

class PassBookManager{
private: 
	int number_PassBook ; 
	vector<Passbook> list;
public:
	PassBookManager(){
		UpateTodayRule() ; 
		SetList();
	}

	void UpateTodayRule(){ // Cập nhật lãi xuất, áp dụng cho tất cả các sổ 
		cout<<"===== Cap nhat ngay: "<< Today<<" ======\n ";
		do{
			cout<<"Nhap phan tram lai xuat: ";
			cin>>interest_rate_Today;
		}while( interest_rate_Today < 0 || interest_rate_Today > 100);

		do{
			cout<<"Nhap phan tram lai xuat neu rut som : ";
			cin>>early_withdraw_rate_Today;
		}while( early_withdraw_rate_Today < 0 || early_withdraw_rate_Today > 100);
	}

	void SetList(){//Nhập danh sách
		cout<<"Nhap so luong so tiet kiem: ";
		cin>>number_PassBook ; 
		cin.ignore();

		for( int i =0 ; i < number_PassBook ; i++){
			cout<<"===== Nhap thong tin so thu: "<<i+1<<"====== \n";
			Passbook temp; 
			list.push_back(temp);
		}
	}

	void GetList(){// In danh sách

		for( int i =0 ; i < number_PassBook ; i++){
			cout<<"===== Thong tin so thu: "<<i+1<<"====== \n";
			list[i].GetInfor();
		}
		cout<<endl;
	}

	vector<Passbook> Search(){// Tìm kiếm theo từ khóa trong CMND và mã số của các sổ
		if( list.empty()){
			cout<<"Danh sach rong";
			return {};
		} 
		cout<<"Nhap tu khoa ban muon tim (CMND/Ma so): ";
		vector<Passbook> ans;
		string key  ; 
		cin>>key;
		transform(key);
		for( int i = 0 ; i < number_PassBook ; i++)
			if( list[i].MatchesKey(key) ) ans.push_back(list[i]);
		return ans;
	}

	vector<Passbook> SearchInRange(){// Tìm kiếm theo ngày mở sổ
		if(list.empty()) return {};
		Date d1, d2; 
		cout<<"Nhap ngay thu nhat va ngay thu hai (d1<s2) ";
		cin>>d1>>d2 ; 	
		vector<Passbook> ans ; 
		for( Passbook idx : list){
			if( idx.open_Date < d2 &&   d1 < idx.open_Date) ans.push_back(idx);
		}
		return ans;
	}

	void SortByBalance() {// Sắp xếp theo số dư tài khoảnn
    sort(list.begin(), list.end(), [](const Passbook &a, const Passbook &b) {
        return a.balance < b.balance;
    	});
	}

	void SortByOpenDate() { // Sắp xếp theo ngày mở sổ
    sort(list.begin(), list.end(), [](const Passbook &a, const Passbook &b) {
        return a.open_Date < b.open_Date;
    	});
	}

	void WithdrawAPassbook(){// Rút tài khoản
		int n; 
		
		do{
			cout<<" Nhap so ma ban muon rut tien ( theo tu danh sach ) : ";
			cin>>n;
		}while( n <= 0 || n > number_PassBook);

		list[n-1].Withdraw();
	}


};
	void Print(const vector<Passbook> &a){
		if(a.empty() ) {
			cout<<"Khong tim thay: ";
			return ; 
		}
		cout<<"Ket qua tim kiem: \n"; 
		for( auto idx : a){
			idx.GetInfor();
		}
	}
int main(){
	Passbook argi ;
	argi.GetInfor();
	argi.UpdateInterestRate_Package();
	argi.Withdraw();
	system("pause");
	return 0;
}

bool isValidName(const string &name){
    if (name.length() < 2 || name.length() > 50){
    	cout<<"Do dai khong hop le\n ";
		 return false;
    }// Giới hạn độ dài hợp lý
        

    for (char c : name)
    {
        if (isdigit(c)){
        	cout<<"Ten khong duoc chua so\n";
        	 return false; // Không chứa số
        }	
           
 
    }
    return true;
}

// Hàm chuẩn hóa họ tên (viết hoa chữ cái đầu, còn lại viết thường)
void formatName(string &name){
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
void transform(string &key){
	for( unsigned int i = 0  ; i < key.length() ; i++){
		if( isdigit(key[i]) ) continue ; 
		key[i] = ( isupper(key[i]) )? tolower(key[i]) : key[i];
	}
}