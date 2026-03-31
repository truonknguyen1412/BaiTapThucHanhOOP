#include <iostream>
using namespace std;
class GioPhutGiay{
	private:
		int gio, phut, giay;
	public:
		GioPhutGiay(){}
		GioPhutGiay(int gio, int phut, int giay){
			this->gio = gio;
			this->phut = phut;
			this->giay = giay;
		}
		void Nhap();
		void Xuat();
		void TinhCongThemMotGiay();
};
void GioPhutGiay::Nhap(){
	do{
		cout << "Nhap gio: "; cin >> gio;
		if(gio < 0 || gio > 23) cout << "Gio khong hop le. Vui long nhap lai\n";
	} while(gio < 0 || gio > 23);
	do{
		cout << "Nhap phut: "; cin >> phut;
		if(phut < 0 || phut > 60) cout << "Phut khong hop le. Vui long nhap lai\n";
	} while(phut < 0 || phut > 60);
	do{
		cout << "Nhap giay: "; cin >> giay;
		if(giay < 0 || giay > 60) cout << "Giay khong hop le. Vui long nhap lai\n";
	} while(giay < 0 || giay > 60);
}
void GioPhutGiay::Xuat(){
	cout << gio << ":" << phut << ":" << giay << endl;
}
void GioPhutGiay::TinhCongThemMotGiay(){
	giay++;
	if(giay == 60){
		giay = 00;
		phut++;
		if(phut == 60){
			phut = 00;
			gio++;
			if(gio = 24); gio = 00;
		}
	}
}
int main(){
	GioPhutGiay x;
	x.Nhap();
	x.Xuat();
	x.TinhCongThemMotGiay();
	cout << "Cong them mot giay la: ";
	x.Xuat();
	return 0;
}	
