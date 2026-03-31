#include <iostream>
using namespace std;
class Year{
	private:
		int Ngay, Thang, Nam;
	public:
		Year(){}
		void Nhap();
		void Xuat();
		void NgayThangNamTiepTheo();
};
bool Lanamnhuan(int nam){
	return (nam % 4 == 0 && nam % 100 != 0 || nam % 400 == 0);
}
void Year::Nhap(){
	cout << "Nhap ngay: "; cin >> Ngay;
	cout << "Nhap thang: "; cin >> Thang;
	cout << "Nhap Nam: "; cin >> Nam;
}
int Songaytrongthang(int thang, int nam){
	switch(thang){
		case 1: case 3: case 5: case 7: case 8: case 10: case 12:
			return 31;
		case 4: case 6: case 9: case 11:
			return 30;
		case 2:
			if(Lanamnhuan(nam)) return 29;
			else return 28;
		default:
			return 0;
	}
}
void Year::Xuat(){
	cout << Ngay << "/" << Thang << "/" << Nam << endl;
}
void Year::NgayThangNamTiepTheo(){
	Ngay++; 
	if(Ngay > Songaytrongthang(Thang, Nam)){
		Ngay = 1;
		Thang++;
		if(Thang > 12){
			Thang = 1;
			Nam++;
		}
	}	
}
int main(){
	Year date;
	date.Nhap();
	date.Xuat();
	cout << endl;
	date.NgayThangNamTiepTheo();
	cout << "Ngay tiep theo la: ";
	date.Xuat();
	return 0;
}


