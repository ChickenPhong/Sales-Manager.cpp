#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <sstream>
#include <conio.h>
#include <iomanip>
#include <windows.h> // doi mau
using namespace std;
struct SanPham
{
	string ma;
	string ten;
	int soLuong;
}; 
struct DongSP
{
	string ma;
	string ten;
	vector<SanPham> dsSP;
};
struct HoaDon
{
	string thoiGian;
	string phanLoai;
};

void TextColor(int x)//X là mã màu
{
     HANDLE h= GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, x);
}
void menu()
{
	TextColor(13);
	cout << "\n                    ___________________________________________________                      ";
	cout << "\n                    |     ====Chuong trinh quan ly kho hang KPV====   |                  ";
	cout << "\n                    |_________________________________________________|                   ";
	TextColor(11);
	cout << "\n           __________________________________________________________________";
	cout << "\n          |";
	TextColor(14);
	cout << "      1. Nhap don hang";
	TextColor(11);
	cout << "         |";
	TextColor(14);
	cout << "         2.Xuat don hang";
	TextColor(11);
	cout << "          |          ";
	TextColor(11);
	cout << "\n          |_______________________________|__________________________________|";
	TextColor(11);
	cout << "\n          |";
	TextColor(14);
	cout << "                 3.Tim san pham trong kho hang";
	TextColor(11);
	cout << "                    | ";
	cout << "\n          |__________________________________________________________________|";
	cout << "\n          |";
	TextColor(14);
	cout << "                 4. Xuat thong tin kho hien tai";
	TextColor(11);
	cout << "                   |       ";
	cout << "\n          |__________________________________________________________________|";
	TextColor(11);
	cout << "\n          |";
	TextColor(14);
	cout << "                            5. Exit";     
	TextColor(11);
	cout << "                               |";
	cout << "\n          |__________________________________________________________________|";
	cout << "\n";
	TextColor(10);
	cout << "\n     _________   ";
    cout << "\n    | ^    ^  |  ";
    cout << "\n    |    -    |  ";
    cout << "\n     ---------   ";
	cout << "Ban muon ROBO thuc hien chuc nang nao ^ ^ .... ";
}
void docFile(vector<DongSP> &dsDongSP)
{
	dsDongSP.clear();
	ifstream f("Data.json");
	int soDongSP;
	f >> soDongSP;
	string chuoiTam;
	for (int j = 0; j < soDongSP; j++)
	{
		DongSP dong;
		int soSP;
		f >> dong.ma >> soSP;
		getline(f, chuoiTam);
		fflush(stdin);
		getline(f, dong.ten);
		for (int i = 0; i < soSP; i++)
		{
			SanPham sp;
			f >> sp.ma >> sp.soLuong;
			getline(f, chuoiTam);
			fflush(stdin);
			getline(f, sp.ten);
			dong.dsSP.push_back(sp);
		}
		dsDongSP.push_back(dong);
	}
	f.close();
}
void luuFile(vector<DongSP> dsDongSP)
{
	ofstream f("data.json");
	f << dsDongSP.size() << endl;
	f << " ____________________________________ " << endl;
	f << "|  Nguoi nhap hang: Tran Quoc Phong  |" << endl;
	f << "|____________________________________| " << endl;
	for (int j = 0; j < dsDongSP.size(); j++)
	{
		cout << "\n";
		DongSP dong = dsDongSP.at(j);
		f << " " << endl;
		f <<"Ma dong: " << dong.ma << " / Tong so luong: " << dong.dsSP.size() << " " << dong.ten << endl;;
	
		for (int i = 0; i < dong.dsSP.size(); i++)
		{
			SanPham sp = dong.dsSP.at(i);
			f <<"STT: " << i + 1 << endl;
			f <<"Ma dinh danh: "<< sp.ma <<" " << "| So luong: " << sp.soLuong << "_ " << sp.ten << "_ " << "Thang 04/2023" << endl;
		
		}
	}
	f.close();
}
bool dangNhap()
{
	ifstream f("DangNhap.json");
	string tenDangNhap, matKhau, tenDangNhap_tam;
	f >> tenDangNhap >> matKhau;
	f.close();
	bool k = false;
	int dem = 0, i = 0, j = 0;
	do
	{
		dem++;
		TextColor(14);
		cout << "\n                                * * * * * * * * * * * * * * * * * * * * *" << endl;
		cout << "\n                                *        ";
		TextColor(14);
		cout << "DANG   NHAP   HE   THONG       ";
		TextColor(14);
		cout << "*" << endl;
		cout << "\n                                * * * * * * * * * * * * * * * * * * * * *" << endl;
		cout << "\n" << endl;
		TextColor(9);
		cout << "\n           _____________________________";
			TextColor(11);
		cout << "<";
			TextColor(9);
		cout << "_________________________________";
			TextColor(11);
		cout << "<";
			TextColor(9);
		cout << "___________________";
		TextColor(11);
		cout << "\n          v";
		TextColor(9);
		cout << "\n          |";
		TextColor(15);
		cout << "   Ten dang nhap : ";
		TextColor(11);
		cin >> tenDangNhap_tam;
		TextColor(11);
		cout << "          v       ";
		TextColor(9);
		cout << "\n          |";
		TextColor(15);
		cout << "   Mat khau      : ";
		bool ktrql = true;
		char *matKhau_tam = new char[matKhau.size() + 1];
		char tmp;
		i = 0;
		do
		{TextColor(11);
			tmp = getch();
			if (tmp != 13)
			{
				matKhau_tam[i] = tmp;
				cout << "*";
				i++;
			}
		} while (tmp != 13);
		for (j = 0; j < i; j++)
			if (matKhau[j] != matKhau_tam[j])
				ktrql = false;
		if (i != matKhau.size())
			ktrql = false;
		if (tenDangNhap_tam == tenDangNhap && ktrql == true)
		{
				TextColor(9);
			cout << "\n";
			cout << "          |___________";
			TextColor(11);
			cout <<">";
			TextColor(9);
			cout << "_________________";
			TextColor(11);
			cout <<">";
			TextColor(9);
			cout << "________________";
			cout <<"\n                                                         |";
			TextColor(11);
			cout << "\n                                                         v"; 
			TextColor(9);
			cout << "\n                                                         |";
			TextColor(11);
			cout << "\n                                                         v"; 
			TextColor(10);     
			cout << "\n                                         ====   Dang nhap thanh cong   ====         "; 
			cout << "\n                                       ";
			cout << "\n                                                                     ";
			cout<< "\n";
			TextColor(8);
			cout << "\nNhan Enter de tiep tuc!    ";
			cout << "\n";
			system("pause");
			cout << "\n";
			system("cls");
				TextColor(13);
		cout << "\n                       __________________________________________________________";
		cout << "\n                      |  Chao mung ban den voi he thong quan li KPV !           |";
		cout << "\n                      | Va toi la ROBO. Toi se ho tro het minh vi ban (0 w 0)   |";
		cout << "\n                      |_________________________________________________________|";
		TextColor(10);
		cout << "\n      _____________  /               ";
		cout << "\n     |   ^     ^   |                  ";
		cout << "\n     |      W      |                  ";
		cout << "\n       ------------                   ";
		cout << "\n     ______||_______                  ";
		cout << "\n     |             |                  ";
		cout << "\n     |             |                  ";
		cout << "\n";
		TextColor(13);
		cout << "\n _____________________________________________________________ ";
		cout << "\n|  Ban hay nhan Enter de di den chuong trinh quan ly nao ^ ^  |";
		cout << "\n|_____________________________________________________________|";
		cout <<"\n";
		
			TextColor(7);
			cout << "\n";
			system("pause");
			system("cls");
			return true;
		}
		else
			if (dem < 3) {
				system("cls");
			
					TextColor(12);
		cout << "\n                 _____________________________________________________________________________________ ";
	    cout << "\n                |   Ban da nhap sai tai khoan hoac mat khau ";
		TextColor(14);
		cout << dem;
		TextColor(12);
		cout << " lan (Sai 3 lan se thoat khoi he thong)  |";
    	cout << "\n                |_____________________________________________________________________________________|";
    		TextColor(10);
		cout << "\n _____________ /                 ";
		cout << "\n |  _     _  |                  ";
		cout << "\n |     _     |                  ";
		cout << "\n  -----------                   ";
		}
			else
			{
			system("cls");
			 TextColor(13);
		cout << "\n                 _____________________________________________________________ ";
	    cout << "\n                |   Ban da nhap sai tai khoan hoac mat khau qua 3 lan !       |";
	    cout << "\n                |   Theo quy dinh, Ban se bi thoat khoi he thong !            |";
	    cout << "\n                |   ROBO xin loi vi su bat tien nay T T                       |";
    	cout << "\n                |_____________________________________________________________|";
    		TextColor(9);
		cout << "\n _____________ /                ";
		cout << "\n |  _     _  |                  ";
        cout << "\n |  U  .  U  |                  ";
		cout << "\n |         | |                  ";
		cout << "\n  -----------                   ";
			TextColor(7);
			cout << "\n";	
				break;
			}
	} while (dem < 3 && k == false);
	return false;
}
bool checkMaSP(vector<DongSP> dsDongSP, string ma)
{
	for (int i = 0; i < dsDongSP.size(); i++)
		for (int j = 0; j < dsDongSP.at(i).dsSP.size(); j++)
			if (ma == dsDongSP.at(i).dsSP.at(j).ma)
				return false;
	return true;
}
int getSoNgauNhien(int min, int max)
{
	srand(time(0));
	return rand() % (max - min + 1) + min;
}
string getMaSP(vector<DongSP> dsDongSP, int i)
{
	string ma = dsDongSP.at(i).ma;
	ostringstream conVert;
	while (true)
	{
		int so = getSoNgauNhien(100000, 999999);
		conVert << so;
		if (checkMaSP(dsDongSP, conVert.str()) == false)
		{
			continue;
		}
		return conVert.str();
	}
}
void nhapKho(vector<DongSP> &dsDongSP)
{
	if (dsDongSP.size() == 0)
	{
		cout << "Hien khong co dong san pham nao !" << endl;
		return;
	}
	string c;
	system("cls");
		TextColor(10);
		cout << "\n _____________                  ";
		cout << "\n |  o     o  |                  ";
		cout << "\n |     W     |                  ";
		cout << "\n  -----------   ";
	TextColor(15);
	cout << " ban co muon ROBO goi y dien thoai hoac laptop nao khong ^ ^ (";
	TextColor(14);
	cout << "yes";
	TextColor(15);
	cout << " /";
	TextColor(14);
	cout << " no";
	TextColor(15);
	cout << ") : ";
		TextColor(11);
	cin >> c;
	while (c != "yes" && c != "no")
	{
		system("cls");
		TextColor(10);
		cout << "\n _____________                  ";
		cout << "\n |  o     o  |                  ";
		cout << "\n |     W     |                  ";
		cout << "\n  -----------   ";
	TextColor(15);
	cout << " ban co muon ROBO goi y dien thoai hoac laptop nao khong ^ ^ (";
	TextColor(14);
	cout << "yes";
	TextColor(15);
	cout << " /";
	TextColor(14);
	cout << " no";
	TextColor(15);
	cout << ") : ";
		TextColor(11);
	cin >> c;
	}
	if (c == "yes") {
	system("cls");
	TextColor(15);
	cout << "\n   ROBO xin goi y nhung san pham dang thinh hanh ma co the ban dang can ^ ^ ";
	TextColor(11); cout << "\n ___________________________________________ ";
	TextColor(14); cout << "  _________________________________________";
	TextColor(11); cout << "\n|                  | 1. Samsung             |";
	TextColor(14); cout << " |            |  8. MacBook                |";
	TextColor(11); cout << "\n|                  | 2. Realme              |";
	TextColor(14); cout << " |            |  9. MSI                    |";
	TextColor(11); cout << "\n|                  | 3. Xioami              |";
	TextColor(14); cout << " |            | 10. Asus                   |";
	TextColor(11); cout << "\n|";
	TextColor(15); cout <<"  Dien thoai";
	TextColor(11); cout << "      | 4. Iphone              |";
	TextColor(14); cout << " |";
	TextColor(15); cout << "  Laptop";
	TextColor(14); cout << "    | 11. Dell                   |";
	TextColor(11); cout << "\n|                  | 5. Oppo                |";
	TextColor(14); cout << " |            | 12. Acer                   |";
	TextColor(11); cout << "\n|                  | 6. ViVo                |";
	TextColor(14); cout << " |            | 13. Lenovo                 |";
	TextColor(11); cout << "\n|                  | 7. TCL                 |";
	TextColor(14); cout << " |            | 14. HP                     |";
	TextColor(11); cout << "\n|___________________________________________|";
	TextColor(14); cout << " |_________________________________________|";
	cout << "\n";
	TextColor(8);	
	cout << "\n (Neu ban khong can goi y thi hay nhan phim 0)";
	cout << "\n"; //khuc nay
	TextColor(7);
	int chon;
	cout << "\n ban muon ROBO goi y dong Dien Thoai Hoac Laptop nao: ";
	cin >> chon;

	if (chon == 0) {
			system("pause");
	}
	else if (chon == 1) {
		system("cls");
		TextColor(7);
		cout << "\n                    ROBO da tim kiem                                                  ";
		cout << "\n                  Va thay rang nhung mau duoi day dang thinh hanh trong thang 3 nay!  ";
		TextColor(10);
		cout << "\n _____________  /               ";
		cout << "\n |  o     o  |                  ";
		cout << "\n |     W     |                  ";
		cout << "\n  -----------";
		TextColor(13);
		cout << "      _____________________________________________________________             ";
		cout << "\n                  |   van con nhieu mau Samsung khac nhung ROBO xin             |";
		cout << "\n                  | khong de cap den do nhung dong dien thoai do khong duoc hot |  ";
		cout <<"\n                  |_____________________________________________________________|";
		cout << "\n";
		TextColor(11);
		cout << "\n_________________________________________________________";
		cout << "\n| Samsung Galaxy s22 ultra   |  Samsung Galaxy S21 FE   |";
		cout << "\n|____________________________|__________________________|";
		cout << "\n| Samsung Galaxy S23 Plus    |  Samsung Galaxy A23      |";
		cout << "\n|____________________________|__________________________|";
		cout << "\n| Samsung Galaxy Z Flip4     |  Samsung Galaxy A34 5G   |";
		cout << "\n|____________________________|__________________________|";
		cout << "\n| Samsung Galaxy Z Fold4     |  Samsung Galaxy A73      |";
		cout << "\n|____________________________|__________________________|       ";
    	TextColor(8);
		system("pause");
	}
	else if (chon == 2) {
			system("cls");
			TextColor(7);
		cout << "\n                    ROBO da tim kiem                                                  ";
		cout << "\n                  Va thay rang nhung mau duoi day dang thinh hanh trong thang 3 nay!  ";
		TextColor(10);
		cout << "\n _____________  /               ";
		cout << "\n |  o     o  |                  ";
		cout << "\n |     W     |                  ";
		cout << "\n  -----------";
			TextColor(11);
		cout << "\n____________________________________________";
		cout << "\n| Realme C30s       |  Realme 10           |";
		cout << "\n|___________________|______________________|";
		cout << "\n| Realme 9 series   |  Realme C55          |";
		cout << "\n|___________________|______________________|";
		cout << "\n| Realme C35        |  Realme C25Y         |";
		cout << "\n|___________________|______________________|      ";
		TextColor(8);
		system("pause");
	}
		else if (chon == 3) {
				system("cls");
		TextColor(7);
		cout << "\n                    ROBO da tim kiem                                                  ";
		cout << "\n                  Va thay rang nhung mau duoi day dang thinh hanh trong thang 3 nay!  ";
		TextColor(10);
		cout << "\n _____________  /               ";
		cout << "\n |  o     o  |                  ";
		cout << "\n |     W     |                  ";
		cout << "\n  -----------";
		TextColor(13);
		cout << "      _____________________________________________________________             ";
		cout << "\n                  |   van con nhieu mau Xiaomi khac nhung ROBO xin              |";
		cout << "\n                  | khong de cap den do nhung dong dien thoai do khong duoc hot |  ";
		cout <<"\n                  |_____________________________________________________________|";
		cout << "\n";
		TextColor(11);
		cout << "\n__________________________________________________________________";
		cout << "\n| Xiaomi Redmi Note 11              |  Xiaomi 13 series          |";
		cout << "\n|___________________________________|____________________________|";
		cout << "\n| Xiaomi Redmi Note 11 Pro Series   |  Xiaomi 12                 |";
		cout << "\n|___________________________________|____________________________|";
		cout << "\n| Xiaomi Redmi 10 (2022)            |  Xiaomi 11T 5G             |";
		cout << "\n|___________________________________|____________________________|";
		cout << "\n| Xiaomi Redmi 12C                  |  POCO C40                  |";
		cout << "\n|___________________________________|____________________________|      ";
		TextColor(8);
		system("pause");
	}
		else if (chon == 4) {
				system("cls");
		TextColor(7);
		cout << "\n                   ROBO da tim kiem                                                   ";
		cout << "\n                  Va thay rang nhung mau duoi day dang thinh hanh trong thang 3 nay!  ";
		TextColor(10);
		cout << "\n _____________  /               ";
		cout << "\n |  o     o  |                  ";
		cout << "\n |     W     |                  ";
		cout << "\n  -----------";
		cout << "\n";
		TextColor(11);
		cout << "\n__________________________________________________";
		cout << "\n| iPhone 14 Pro Max     |  iPhone 14             |";
		cout << "\n|_______________________|________________________|";
		cout << "\n| iPhone 14 Plus        |  iPhone 13 Pro         |";
		cout << "\n|_______________________|________________________|";
		cout << "\n| iPhone 13 Pro Max     |  iPhone 13             |";
		cout << "\n|_______________________|________________________|";
		cout << "\n| iPhone SE (2022)      |  iPhone 12             |";
		cout << "\n|_______________________|________________________|";
		cout << "\n| iPhone 12 Pro Max     |  iPhone 11             |";
		cout << "\n|_______________________|________________________|      ";
		TextColor(8);
		system("pause");
	}
		else if (chon == 5) {
				system("cls");
		TextColor(7);
		cout << "\n                   ROBO da tim kiem                                                   ";
		cout << "\n                  Va thay rang nhung mau duoi day dang thinh hanh trong thang 3 nay!  ";
		TextColor(10);
		cout << "\n _____________  /               ";
		cout << "\n |  o     o  |                  ";
		cout << "\n |     W     |                  ";
		cout << "\n  -----------";
		TextColor(13);
		cout << "      _____________________________________________________________             ";
		cout << "\n                  |   van con nhieu mau OPPO khac nhung ROBO xin                |";
		cout << "\n                  | khong de cap den do nhung dong dien thoai do khong duoc hot |  ";
		cout <<"\n                  |_____________________________________________________________|";
		cout << "\n";
		TextColor(11);
		cout << "\n____________________________________________________";
		cout << "\n| OPPO Reno8 T 5G       |  OPPO Reno8 series       |";
		cout << "\n|_______________________|__________________________|";
		cout << "\n| OPPO Find X5 Pro 5G   |  OPPO A55                |";
		cout << "\n|_______________________|__________________________|";
		cout << "\n| OPPO Reno6 series     |  OPPO Reno7 series       |";
		cout << "\n|_______________________|__________________________|";
		cout << "\n| OPPO Reno8 T          |  OPPO A77s               |";
		cout << "\n|_______________________|__________________________|      ";
		TextColor(8);
		system("pause");
	}
		else if (chon == 6) {
				system("cls");
		TextColor(7);
		cout << "\n                   ROBO da tim kiem                                                   ";
		cout << "\n                  Va thay rang nhung mau duoi day dang thinh hanh trong thang 3 nay!  ";
		TextColor(10);
		cout << "\n _____________  /               ";
		cout << "\n |  o     o  |                  ";
		cout << "\n |     W     |                  ";
		cout << "\n  -----------";
		TextColor(13);
		cout << "      _____________________________________________________________             ";
		cout << "\n                  |   van con nhieu mau Vivo khac nhung ROBO xin                |";
		cout << "\n                  | khong de cap den do nhung dong dien thoai do khong duoc hot |  ";
		cout <<"\n                  |_____________________________________________________________|";
		cout << "\n";
		TextColor(11);
		cout << "\n__________________________________________________";
		cout << "\n| Vivo V25 series      |  Vivo Y21 series        |";
		cout << "\n|______________________|_________________________|";
		cout << "\n| Vivo V25 Pro 5G      |  Vivo V23 series        |";
		cout << "\n|______________________|_________________________|";
		cout << "\n| Vivo Y35             |  Vivo Y55               |";
		cout << "\n|______________________|_________________________|       ";
		TextColor(8);
		system("pause");
	}
		else if (chon == 7) {
				system("cls");
		TextColor(7);
		cout << "\n                   ROBO da tim kiem                                                   ";
		cout << "\n                  Va thay rang nhung mau duoi day dang thinh hanh trong thang 3 nay!  ";
		TextColor(10);
		cout << "\n _____________  /               ";
		cout << "\n |  o     o  |                  ";
		cout << "\n |     W     |                  ";
		cout << "\n  -----------";
		TextColor(11);
		cout << "\n............................................";
		cout << "\n. TCL 30+       .  TCL 30 SE               .";
		cout << "\n............................................      ";
		TextColor(8);
		system("pause");
	}
		else if (chon == 8) {
				system("cls");
		TextColor(7);
		cout << "\n                   ROBO da tim kiem                                                   ";
		cout << "\n                  Va thay rang nhung mau duoi day dang thinh hanh trong thang 3 nay!  ";
		cout << "\n _____________  /               ";
		cout << "\n |  o     o  |                  ";
		cout << "\n |     W     |                  ";
		cout << "\n  -----------";
		TextColor(13);
		cout << "      _____________________________________________________________             ";
		cout << "\n                  |   van con nhieu mau MacBook khac nhung ROBO xin             |";
		cout << "\n                  | khong de cap den do nhung dong laptop do khong duoc hot     |  ";
		cout <<"\n                  |_____________________________________________________________|";
		cout << "\n";
		TextColor(14);
		cout << "\n_______________________________________________________________________";
		cout << "\n| MacBook Pro 14 inch M2 Pro 2023     |  MacBook Air M2 2022          |";
		cout << "\n|_____________________________________|_______________________________|";
		cout << "\n| MacBook Air M1 2020                 |  MacBook Pro 16 M1 Pro 2021   |";
		cout << "\n|_____________________________________|_______________________________|";
		cout << "\n| MacBook Pro M1 2020                 |  MacBook Pro M2 2022          |";
		cout << "\n|_____________________________________|_______________________________|      ";
	
		TextColor(8);
		system("pause");
	}
		else if (chon == 9) {
				system("cls");
		TextColor(7);
		cout << "\n                   ROBO da tim kiem                                                   ";
		cout << "\n                  Va thay rang nhung mau duoi day dang thinh hanh trong thang 3 nay!  ";
		TextColor(10);
		cout << "\n _____________  /               ";
		cout << "\n |  o     o  |                  ";
		cout << "\n |     W     |                  ";
		cout << "\n  -----------";
		TextColor(13);
		cout << "      _____________________________________________________________             ";
		cout << "\n                  |   van con nhieu mau MSI khac nhung ROBO xin                 |";
		cout << "\n                  | khong de cap den do nhung dong laptop do khong duoc hot     |  ";
		cout <<"\n                  |_____________________________________________________________|";
		cout << "\n";
		TextColor(14);
		cout << "\n____________________________________________________________________________";
		cout << "\n| MSI Gaming GF63 Thin 11UC i5     |  MSI Gaming Pulse GL66 11UDK i7       |";
		cout << "\n|__________________________________|_______________________________________|";
		cout << "\n| MSI Modern 14 B11SBU i5          |  MSI Creator Z16P B12UGST i7          |";
		cout << "\n|__________________________________|_______________________________________|";
		cout << "\n| MSI Gaming GF63 Thin 11SC i5     |  MSI Gaming GE66 Raider 11UH i7       |";
		cout << "\n|__________________________________|_______________________________________|";
		cout << "\n| MSI Modern 14 B11MOU i3          |  MSI Gaming Stealth 15M A11UEK i7     |";
		cout << "\n|__________________________________|_______________________________________|";
		cout << "\n| MSI Gaming GS66 Stealth 11UG i7  |  MSI Gaming GF63 Thin 11UD i7         |";
		cout << "\n|__________________________________|_______________________________________|      ";
		TextColor(8);
		system("pause");
	}
		else if (chon == 10) {
				system("cls");
		TextColor(7);
		cout << "\n                   ROBO da tim kiem                                                   ";
		cout << "\n                  Va thay rang nhung mau duoi day dang thinh hanh trong thang 3 nay!  ";
		TextColor(10);
		cout << "\n _____________  /               ";
		cout << "\n |  o     o  |                  ";
		cout << "\n |     W     |                  ";
		cout << "\n  -----------";
		TextColor(13);
		cout << "      _____________________________________________________________             ";
		cout << "\n                  |   van con nhieu mau Asus khac nhung ROBO xin                |";
		cout << "\n                  | khong de cap den do nhung dong laptop do khong duoc hot     |  ";
		cout <<"\n                  |_____________________________________________________________|";
		cout << "\n";
			TextColor(14);
		cout << "\n____________________________________________________________________________";
		cout << "\n| Asus TUF Gaming F15 FX506LHB        |  Asus Gaming ROG Strix G15         |";
		cout << "\n|_____________________________________|____________________________________|";
		cout << "\n| Asus Vivobook 15 OLED               |  Asus Vivobook X515EA i3           |";
		cout << "\n|_____________________________________|____________________________________|";
		cout << "\n| Asus Vivobook 15 X1502ZA i7         |  Asus Gaming ROG Strix G17         |";
		cout << "\n|_____________________________________|____________________________________|";
		cout << "\n| Asus Gaming ROG Strix G15           |  Asus Gaming ROG Strix SCAR 15     |";
		cout << "\n|_____________________________________|____________________________________|      ";
		TextColor(8);
		system("pause");
	}
		else if (chon == 11) {
				system("cls");
		TextColor(7);
		cout << "\n                   ROBO da tim kiem                                                   ";
		cout << "\n                  Va thay rang nhung mau duoi day dang thinh hanh trong thang 3 nay!  ";
		TextColor(10);
		cout << "\n _____________  /               ";
		cout << "\n |  o     o  |                  ";
		cout << "\n |     W     |                  ";
		cout << "\n  -----------";
		TextColor(13);
		cout << "      _____________________________________________________________             ";
		cout << "\n                  |   van con nhieu mau Dell khac nhung ROBO xin                |";
		cout << "\n                  | khong de cap den do nhung dong laptop do khong duoc hot     |  ";
		cout <<"\n                  |_____________________________________________________________|";
		cout << "\n";
			TextColor(14);
		cout << "\n____________________________________________________________________________";
		cout << "\n| Dell Vostro 3510 i5                 |  Dell Gaming G15 5511 i5           |";
		cout << "\n|_____________________________________|____________________________________|";
		cout << "\n| Dell Inspiron 16 5620 i7            |  Dell Vostro 5620 i5               |";
		cout << "\n|_____________________________________|____________________________________|";
		cout << "\n| Dell Gaming Alienware m15 R6 i7     |  Dell Vostro 3400 i7               |";
		cout << "\n|_____________________________________|____________________________________|";
		cout << "\n| Dell Inspiron 15 5515 R7            |  Dell Gaming G15 5515 R7           |";
		cout << "\n|_____________________________________|____________________________________|      ";
		TextColor(8);
		system("pause");
	}
		else if (chon == 12) {
				system("cls");
		TextColor(7);
		cout << "\n                   ROBO da tim kiem                                                   ";
		cout << "\n                  Va thay rang nhung mau duoi day dang thinh hanh trong thang 3 nay!  ";
		TextColor(10);
		cout << "\n _____________  /               ";
		cout << "\n |  o     o  |                  ";
		cout << "\n |     W     |                  ";
		cout << "\n  -----------";
		TextColor(13);
		cout << "      _____________________________________________________________             ";
		cout << "\n                  |   van con nhieu mau Acer khac nhung ROBO xin                |";
		cout << "\n                  | khong de cap den do nhung dong laptop do khong duoc hot     |  ";
		cout <<"\n                  |_____________________________________________________________|";
		cout << "\n";
			TextColor(14);
		cout << "\n_______________________________________________________________________________________";
		cout << "\n| Acer Aspire 7 Gaming A715 42G           |  Acer Aspire 5 A514 54 511G i5            |";
		cout << "\n|_________________________________________|___________________________________________|";
		cout << "\n| Acer Aspire 7 Gaming A715 43G           |  Acer Aspire 3 A315 58 382Z i3            |";
		cout << "\n|_________________________________________|___________________________________________|";
		cout << "\n| Acer Nitro 5 Tiger AN515 58 773Y i7     |  Acer Nitro 5 Gaming AN515 57 5669 i5     |";
		cout << "\n|_________________________________________|___________________________________________|";
		cout << "\n| Acer Aspire 7 Gaming A715 75G           |  Acer Swift 3 SF314 512 56QN i5           |";
		cout << "\n|_________________________________________|___________________________________________|";
		TextColor(8);
		system("pause");
	}
		else if (chon == 13) {
				system("cls");
		TextColor(7);
		cout << "\n                   ROBO da tim kiem                                                   ";
		cout << "\n                  Va thay rang nhung mau duoi day dang thinh hanh trong thang 3 nay!  ";
		TextColor(10);
		cout << "\n _____________  /               ";
		cout << "\n |  o     o  |                  ";
		cout << "\n |     W     |                  ";
		cout << "\n  -----------";
		TextColor(13);
		cout << "      _____________________________________________________________             ";
		cout << "\n                  |   van con nhieu mau Lenovo khac nhung ROBO xin              |";
		cout << "\n                  | khong de cap den do nhung dong laptop do khong duoc hot     |  ";
		cout <<"\n                  |_____________________________________________________________|";
		cout << "\n";
			TextColor(14);
		cout << "\n________________________________________________________________________________";
		cout << "\n| Lenovo Ideapad 3 15IAU7 i3            |  Lenovo Ideapad 5 Pro 14ITL6 i5      |";
		cout << "\n|_______________________________________|______________________________________|";
		cout << "\n| Lenovo Ideapad Gaming 3 15IAH7 i5     |  Lenovo Ideapad 5 Pro 14IAP7 i5      |";
		cout << "\n|_______________________________________|______________________________________|";
		cout << "\n| Lenovo Yoga Slim 7 Pro 14IHU5 i5      |  Lenovo Legion 5 15IAH7 i5           |";
		cout << "\n|_______________________________________|______________________________________|";
		cout << "\n| Lenovo Yoga 7 14IAL7 i7               |  Lenovo ThinkPad E15 Gen 4 i7        |";
		cout << "\n|_______________________________________|______________________________________|      ";
		TextColor(8);
		system("pause");
	}
		else if (chon == 14) {
				system("cls");
		TextColor(7);
		cout << "\n                   ROBO da tim kiem                                                   ";
		cout << "\n                  Va thay rang nhung mau duoi day dang thinh hanh trong thang 3 nay!  ";
		TextColor(10);
		cout << "\n _____________  /               ";
		cout << "\n |  o     o  |                  ";
		cout << "\n |     W     |                  ";
		cout << "\n  -----------";
		TextColor(13);
		cout << "      _____________________________________________________________             ";
		cout << "\n                  |   van con nhieu mau HP khac nhung ROBO xin                  |";
		cout << "\n                  | khong de cap den do nhung dong laptop do khong duoc hot     |  ";
		cout <<"\n                  |_____________________________________________________________|";
		cout << "\n";
			TextColor(14);
		cout << "\n__________________________________________________________________________";
		cout << "\n| HP 15s fq5078TU i5                  |  HP 15s fq2716TU i3              |";
		cout << "\n|_____________________________________|__________________________________|";
		cout << "\n| HP Pavilion 15 eg2056TU i5          |  HP Pavilion 14 dv2033TU i5      |";
		cout << "\n|_____________________________________|__________________________________|";
		cout << "\n| HP Gaming VICTUS 15 fa0111TX i5     |  HP Elitebook X360 1040 G9 i7    |";
		cout << "\n|_____________________________________|__________________________________|";
		cout << "\n| HP Elitebook Dragonfly G3 i7        |  HP Envy X360 13 bf0090TU i7     |";
		cout << "\n|_____________________________________|__________________________________|      ";
		TextColor(8);
		system("pause");
	}
	cout << "\n";
		TextColor(7);
	cout << "\n-------------------------------------------------------------------------------------";
	cout << "\n -Danh sach thong tin dong san pham : " << endl;
	cout << "|" << setw(6) << "STT" << "|" << setw(10) << "Ma dong" << "|" << setw(40) << "Ten dong" << "|" << endl;
	for (int i = 0; i < dsDongSP.size(); i++)
	{
		cout << "|" << setw(6) << i + 1 << "|" << setw(10) << dsDongSP.at(i).ma << "|" << setw(40) << dsDongSP.at(i).ten << "|" << endl;
	}
	cout << "\n Moi Ban dang nhap don hang :";
	TextColor(5);
	cout << " ( Neu ban khong muon nhap thi hay nhan 0 de quay lai menu )";
		TextColor(7);
	cout << "\n--------------------------------------------------------------------------------------";
		cout << "\n";
	}
	else if (c == "no") {
		system("cls");
		cout << "\n";
		TextColor(7);
	cout << "\n---------------------------------------------------------------------------------------";
	cout << "\n -Danh sach thong tin dong san pham : " << endl;
	cout << "|" << setw(6) << "STT" << "|" << setw(10) << "Ma dong" << "|" << setw(40) << "Ten dong" << "|" << endl;
	for (int i = 0; i < dsDongSP.size(); i++)
	{
		cout << "|" << setw(6) << i + 1 << "|" << setw(10) << dsDongSP.at(i).ma << "|" << setw(40) << dsDongSP.at(i).ten << "|" << endl;
	}
	cout << "\n Moi Ban dang nhap don hang :";
	TextColor(5);
	cout << " ( Neu ban khong muon nhap thi hay nhan 0 de quay lai menu )";
		TextColor(7);
	cout << "\n---------------------------------------------------------------------------------------";
		cout << "\n";
	}
	while (true)
	{
		string maDong;
			TextColor(10);
		cout << "\n     Moi ban nhap ma dong san pham : ";
			TextColor(7);
		cin >> maDong;
		if (maDong == "0")
			break;
		int i = 0;
		for (i = 0; i < dsDongSP.size(); i++)
			if (maDong == dsDongSP.at(i).ma)
				break;
		if (i == dsDongSP.size())
		{
			TextColor(12);
			cout << "Ma dong san pham khong ton tai. Moi ban nhap lai! " << endl;
			continue;
		}
		SanPham sp;
			TextColor(10);
		cout << "     Moi ban nhap ten models       :";
		fflush(stdin);
		TextColor(7);
		getline(cin, sp.ten);
		sp.ma = getMaSP(dsDongSP, i);
		sp.soLuong = 0;
		do
		{
			TextColor(10);
			cout << "     Moi ban nhap so luong (>0)    : ";
			TextColor(7);
			cin >> sp.soLuong;
		} while (sp.soLuong <= 0);
		dsDongSP.at(i).dsSP.push_back(sp);
		TextColor(7);
		cout << "\n------------ ";
		TextColor(10);
	cout << " Nhap kho thanh cong ";
	TextColor(7);
		cout << "  ---------- ";
		cout << "\n";
	}
	TextColor(7);
	cout << "\n";
}
void timSanPham(vector<DongSP> dsDongSP)
{
	string ma;
	 TextColor(9);
	cout << "\nNhap ma dinh danh ma ban can tim : ";
	 TextColor(7);
	cin >> ma;
	cout <<"\n";
	int i, j;
	for (i = 0; i < dsDongSP.size(); i++)
	{
		for (j = 0; j < dsDongSP.at(i).dsSP.size(); j++)
			if (ma == dsDongSP.at(i).dsSP.at(j).ma)
				break;
		if (j < dsDongSP.at(i).dsSP.size())
			break;
	}
	if (i < dsDongSP.size())
	{
		cout << "Thong tin san pham tim thay : " << endl;
		cout << "-Thong tin dong : " << endl;
		cout << "|" << setw(10) << "Ma dong" << "|" << setw(40) << "Ten dong" << "|" << endl;
		cout << "|" << setw(10) << dsDongSP.at(i).ma << "|" << setw(40) << dsDongSP.at(i).ten << "|" << endl;
		cout << "----------------------------------------------------------------------------";
		cout << "\n";
		cout << "-Thong tin san pham : " << endl;
		TextColor(11);
		cout << "|";
		TextColor(13);
		cout << setw(10) << "Ma dong";
		TextColor(11);
		cout << "|";
		TextColor(13);
		cout << setw(15) << "Ma dinh danh";
		TextColor(11); 
		cout << "|";
		TextColor(13);
		cout << setw(40) << "Ten models";
		TextColor(11);
		cout << "|";
		TextColor(13);
		cout << setw(15) << "So luong";
		TextColor(11);
		cout << "|";
		TextColor(13);
		cout << setw(19) << "Ngay nhap hang";
		TextColor(11); 
		cout << "|" << endl;
		TextColor(11);
		cout << "|";
		TextColor(14);
		cout << setw(10) << dsDongSP.at(i).ma;
		TextColor(11);
		cout << "|";
		TextColor(14); 
		cout << setw(15) << dsDongSP.at(i).dsSP.at(j).ma;
		TextColor(11);
		cout << "|";
		TextColor(14);
		cout << setw(40) << dsDongSP.at(i).dsSP.at(j).ten;
		TextColor(11); 
		cout << "|";
		TextColor(14);
		cout << setw(15) << dsDongSP.at(i).dsSP.at(j).soLuong;
		TextColor(11); 
		cout << "|";
		TextColor(14);
		cout << setw(19) << "Thang 04/2023";
		TextColor(11); 
		cout << "|" << endl;
		TextColor(8);
		
	}
	else
	{
		cout << "Ma san pham khong ton tai !" << endl;
	}
}
void xuatThongTinKho(vector<DongSP> &dsDongSP)
{
	system("cls");
	cout << "\n------------------------------------------------------------------------------";
	cout << "\n";
	cout << "-Danh sach thong tin dong san pham : " << endl;
	cout << "|" << setw(6) << "STT" << "|" << setw(10) << "Ma dong" << "|" << setw(40) << "Ten dong" << "|" << endl;
	for (int i = 0; i < dsDongSP.size(); i++)
	{
		cout << "|" << setw(6) << i + 1 << "|" << setw(10) << dsDongSP.at(i).ma << "|" << setw(40) << dsDongSP.at(i).ten << "|" << endl;
	}
	cout << "------------------------------------------------------------------------------"<< endl;
	cout << "\n";
    TextColor(10);
	cout << "-Danh sach thong tin san pham ma ban da nhap: " << endl;
	TextColor(11); cout << "\n _____________________________________________________________________________________________________________";
	TextColor(11); cout << "\n|";
	TextColor(13); cout << setw(6) << "STT ";
	TextColor(11); cout << "|";
	TextColor(13); cout << setw(10) << "Ma dong ";
	TextColor(11); cout << "|";
	TextColor(13); cout << setw(15) << "Ma dinh danh  ";
	TextColor(11); cout << "|";
	TextColor(13); cout << setw(40) << "Ten models               ";
	TextColor(11); cout << "|";
	TextColor(13); cout << setw(15) << "So luong   ";
	TextColor(11); cout << "|";
	TextColor(13); cout << setw(18) << "Ngay nhap hang  ";
	TextColor(11); cout << "|" << endl;
	               cout << "|______|__________|_______________|________________________________________|_______________|__________________|";
	int stt = 0;
	for (int i = 0; i < dsDongSP.size(); i++)
		for (int j = 0; j < dsDongSP.at(i).dsSP.size(); j++)
		{
			stt++;
	TextColor(11); cout << "\n|";
	TextColor(14); cout << "  " << stt << setw(4);
	TextColor(11); cout << "|"; 
	TextColor(14); cout << "   "<< dsDongSP.at(i).ma<< setw(5);
	TextColor(11); cout << "|";
	TextColor(14); cout << "    "<< dsDongSP.at(i).dsSP.at(j).ma<< setw(6);
	TextColor(11); cout << "|";
	TextColor(14); cout << setw(40) << dsDongSP.at(i).dsSP.at(j).ten;
	TextColor(11); cout << "|";
	TextColor(14); cout << setw(15) << dsDongSP.at(i).dsSP.at(j).soLuong;
	TextColor(11); cout << "|";
	TextColor(14); cout << setw(18) << "Thang 04/2023  ";
	TextColor(11); cout << "|" << endl;
                   cout << "|______|__________|_______________|________________________________________|_______________|__________________|";
	TextColor(8);
		}
}
void luuFileTruocXuatKho_Xoa(vector<DongSP> dsDongSP, string noiDung)
{
	int so = 0;
	while (true)
	{
		so++;
		ostringstream conVert;
		conVert << so;
		string fileName = "Data_" + noiDung + "_" + conVert.str() + ".json";
		ifstream file(fileName.c_str());
		if (file.is_open())
		{
			file.close();
			continue;
		}
		break;
	}
	ostringstream conVert;
	conVert << so;
	string fileName = "Data_truoc_" + noiDung + "_" + conVert.str() + ".json";
	ofstream f(fileName.c_str());
	f << dsDongSP.size() << endl;
	f << " ____________________________________ " << endl;
	f << "|  Nguoi nhap hang: Tran Quoc Phong  |" << endl;
	f << "|____________________________________| " << endl;
	for (int j = 0; j < dsDongSP.size(); j++)
	{
		cout << "\n";
		DongSP dong = dsDongSP.at(j);
		f << " " << endl;
		f <<"Ma dong: " << dong.ma << " / Tong so luong: " << dong.dsSP.size() << " " << dong.ten << endl;;
		for (int i = 0; i < dong.dsSP.size(); i++)
		{
			SanPham sp = dong.dsSP.at(i);
			f <<"STT: " << i + 1 << endl;
			f <<"Ma dinh danh: "<< sp.ma << " | So luong: " << sp.soLuong << "_ " << sp.ten << "_ " << "Thang 04/2023" << endl;
		}
	}
	f.close();
}
void luuFileTruocXuatKho_Xoa1(vector<DongSP> dsDongSP, string noiDung)
{
	int so = 0;
	while (true)
	{
		so++;
		ostringstream conVert;
		conVert << so;
		string fileName = "Data_" + noiDung + "_" + conVert.str() + ".json";
		ifstream file(fileName.c_str());
		if (file.is_open())
		{
			file.close();
			continue;
		}
		break;
	}
	ostringstream conVert;
	conVert << so;
	string fileName = "Data_truoc_" + noiDung + "_" + conVert.str() + ".json";
	ofstream f(fileName.c_str());
	f << dsDongSP.size() << endl;
	f << " ____________________________________ " << endl;
	f << "|  Nguoi nhap hang: Tran Quoc Phong  |" << endl;
	f << "|____________________________________| "<< endl;
	for (int j = 0; j < dsDongSP.size(); j++)
	{
		cout << "\n";
		DongSP dong = dsDongSP.at(j);
		f << " " << endl;
		f <<"Ma dong: " << dong.ma << " / Tong so luong: " << dong.dsSP.size() << " " << dong.ten << endl;;
		for (int i = 0; i < dong.dsSP.size(); i++)
		{
			SanPham sp = dong.dsSP.at(i);
			f <<"STT: " << i + 1 << endl;
			f <<"Ma dinh danh: "<< sp.ma << " | So luong: " << sp.soLuong << "_ " << sp.ten << "_ " << "Thang 04/2023" << endl;
		}
	}
	f.close();
}
void xuatKho(vector<DongSP> &dsDongSP)
{
	int o;
	system("cls");
	if (dsDongSP.size() == 0)
	{
		cout << "Hien khong co dong san pham nao !" << endl;
		return;
	}
	cout << "\n1. Xuat don hang (trong kho)";
	cout << "\n2. Xoa don hang ";
		TextColor(10);
		cout << "\n _____________                  ";
		cout << "\n |  o     o  |                  ";
		cout << "\n |     W     |                  ";
		cout << "\n  -----------   ";
	cout << " ban muon ROBO thuc hien chuc nang nao ^ ^ ....";
	TextColor(15);
	cin >> o;
	while (o != 1 && o != 2) {
		system("cls");
	cout << "\n1. Xuat don hang (trong kho)";
	cout << "\n2. Xoa don hang ";
		TextColor(10);
		cout << "\n _____________                  ";
		cout << "\n |  o     o  |                  ";
		cout << "\n |     W     |                  ";
		cout << "\n  -----------   ";
	cout << " ban muon ROBO thuc hien chuc nang nao ^ ^ ....";
		TextColor(15);
	cin >> o;
}
 if (o == 1) {
	while (true)
	{
		string ma;
		xuatThongTinKho(dsDongSP);
		TextColor(10);
		cout << "\n";
		cout << "\nNhap ma dinh danh can xuat ";
		TextColor(7);
		cout << "(0 de thoat ) ";
		TextColor(9);
		cout << ": ";
		TextColor(7);
		cin >> ma;
		if (ma == "0")
			break;
		int i, j;
		for (i = 0; i < dsDongSP.size(); i++)
		{
			for (j = 0; j < dsDongSP.at(i).dsSP.size(); j++)
				if (ma == dsDongSP.at(i).dsSP.at(j).ma)
					break;
			if (j < dsDongSP.at(i).dsSP.size())
				break;
		}
		if (i == dsDongSP.size())
		{
		TextColor(15);
			cout << "Ma dinh danh khong ton tai !" << endl;
			continue;
		}
		int soLuong = 0;
		do
		{
			TextColor(10);
			cout << "Nhap so luong ma ban muon xuat kho [1->" << dsDongSP.at(i).dsSP.at(j).soLuong << "] : ";
			TextColor(7);
			cin >> soLuong;
	TextColor(10);
	cout << "\n         ==== Xuat kho thanh cong ====  ";
		TextColor(8);
		cout << "\n                            ";
		system("pause");
		} while (soLuong<1 || soLuong>dsDongSP.at(i).dsSP.at(j).soLuong);
		luuFileTruocXuatKho_Xoa(dsDongSP, "XuatKho");
		dsDongSP.at(i).dsSP.at(j).soLuong -= soLuong;
		if (dsDongSP.at(i).dsSP.at(j).soLuong == 0)
		{
			luuFileTruocXuatKho_Xoa(dsDongSP, "xuat-het-SP");
			dsDongSP.at(i).dsSP.erase(dsDongSP.at(i).dsSP.begin() + j);
		}
		luuFile(dsDongSP);
	}
}
else if (o == 2) {
while (true)
	{
		string ma;
		xuatThongTinKho(dsDongSP);
		TextColor(10);
		cout << "\n";
		cout << "\nNhap ma dinh danh can xoa ";
		TextColor(7);
		cout << "(0 de thoat ) ";
		TextColor(9);
		cout << ": ";
		TextColor(7);
		cin >> ma;
		if (ma == "0")
			break;
		int i, j;
		for (i = 0; i < dsDongSP.size(); i++)
		{
			for (j = 0; j < dsDongSP.at(i).dsSP.size(); j++)
				if (ma == dsDongSP.at(i).dsSP.at(j).ma)
					break;
			if (j < dsDongSP.at(i).dsSP.size())
				break;
		}
		if (i == dsDongSP.size())
		{
		TextColor(15);
			cout << "Ma san pham khong ton tai !" << endl;
			continue;
		}
		int soLuong = 0;
		do
		{
			TextColor(10);
			cout << "Nhap so luong ma ban muon xoa khoi kho [1->" << dsDongSP.at(i).dsSP.at(j).soLuong << "] : ";
			TextColor(7);
			cin >> soLuong;
	TextColor(14);
	cout << "\n         ---> Xoa khoi kho thanh cong <---  ";
		TextColor(8);
		cout << "\n                            ";
		system("pause");
		} while (soLuong<1 || soLuong>dsDongSP.at(i).dsSP.at(j).soLuong);
		luuFileTruocXuatKho_Xoa1(dsDongSP, "XoaKhoiKho");
		dsDongSP.at(i).dsSP.at(j).soLuong -= soLuong;
		if (dsDongSP.at(i).dsSP.at(j).soLuong == 0)
		{
			luuFileTruocXuatKho_Xoa1(dsDongSP, "XoaSP_khoiKho");
			dsDongSP.at(i).dsSP.erase(dsDongSP.at(i).dsSP.begin() + j);
		}
		luuFile(dsDongSP);
	}	
}

	cout << "\n" << endl;

	TextColor(8);
	cout << "\n"<< endl;
}
int main()
{
	if (dangNhap() != true)
		return 0;
	vector<DongSP> dsDongSP;
	docFile(dsDongSP);
	int choice = 0;
	do
	{system("cls");
		menu();
			TextColor(15);
		cin >> choice;
		if (choice == 1)
		{
			nhapKho(dsDongSP);
			luuFile(dsDongSP);
			system("pause");
		}
		if (choice == 3)
		{
			timSanPham(dsDongSP);
			system("pause");
		}
		if (choice == 2)
		{
			xuatKho(dsDongSP);
			system("pause");
		}
		if (choice == 4)
		{
			xuatThongTinKho(dsDongSP);
			cout << "\n";
			system("pause");
		}
		if (choice == 5) {
			system("cls");
		TextColor(11);
		cout << "\n                       ________________________________________";
		cout << "\n                      |    ROBO cam on ban da toi he thong !   |";
		cout << "\n                      |     Chuc ban mot ngay tot lanh  ^ ^    |";
		cout << "\n                      |________________________________________|";
		TextColor(10);
		cout << "\n      _____________  /               ";
		cout << "\n     |   ^     ^   |                  ";
		cout << "\n     |      W      |                  ";
		cout << "\n       ------------                   ";
		cout << "\n     ______||_______                  ";
		cout << "\n     |             |                  ";
		cout << "\n     |             |                  ";
		cout << "\n" << endl;
		TextColor(8);
			system("pause");
			break;
		}
	} while (choice != 0);
	return 0;
}


 
    
    
    
    
    
