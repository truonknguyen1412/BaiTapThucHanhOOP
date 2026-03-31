//Bai Tap 2:
#include <iostream>
#include <cmath>
using namespace std;
class Phanso{
	private:
		int tu, mau;
	public:
		Phanso(int t, int m){
			tu = t;
			mau = m;
		}
		Phanso(){}
		int timUCLN(int a, int b) {
    		a = abs(a); b = abs(b);
    		while (b != 0) {
        		int r = a % b;
        		a = b;
        		b = r;
    		}
    		return a;
		}
		void RutGon() {
    		int ucln = timUCLN(tu, mau);
    		tu /= ucln;
    		mau /= ucln;
    		if (mau < 0) { 
        		tu = -tu;
        		mau = -mau;
    		}
		}
		void Nhap(){
			cout << "Nhap phan so dau tien: "; cin >> tu;
			do {
				cout << "Nhap mau so khac 0; "; cin >> mau;
				if(mau == 0) cout << "Mau so phai khac 0. Vui long nhap lai: ";
			} while(mau == 0);
		}
		void Xuat(){
			if(mau == 1) cout << tu;
			else if(tu == 0) cout << "0";
			else cout << tu << "/" << mau; 
		}
		Phanso Tong(Phanso ps2){
			Phanso kq;
			kq.tu = this->tu * ps2.mau + ps2.tu * this->mau;
			kq.mau = this->mau * ps2.mau;
			kq.RutGon();
			return kq;
		}
		Phanso Hieu(Phanso ps2){
			Phanso kq;
			kq.tu = this->tu * ps2.mau - ps2.tu * this->mau;
			kq.mau = this->mau * ps2.mau;
			kq.RutGon();
			return kq;
		}
		Phanso Tich(Phanso ps2){
			Phanso kq;
			kq.tu = this->tu * ps2.tu;
			kq.mau = this->mau * ps2.mau;
			kq.RutGon();
			return kq;
		}
		Phanso Thuong(Phanso ps2){
			Phanso kq;
			kq.tu = this->tu * ps2.mau;
			kq.mau = this->mau * ps2.tu;
			kq.RutGon();
			return kq;
		}
		int SoSanh(Phanso ps2) {
        	double v1 = (double)this->tu / this->mau;
        	double v2 = (double)ps2.tu / ps2.mau;
        	if (v1 > v2) return 1;
        	if (v1 < v2) return -1;
        	return 0;
    	}
};
int main() {
    Phanso ps1, ps2, kq;

    cout << "--- Nhap Phan So 1 ---\n";
    ps1.Nhap();
    cout << "--- Nhap Phan So 2 ---\n";
    ps2.Nhap();

    cout << "\nPhan so 1: "; ps1.Xuat();
    cout << "\nPhan so 2: "; ps2.Xuat();

    cout << "\n\n--- Ket qua phep tinh (da rut gon) ---";
    kq = ps1.Tong(ps2);
    cout << "\nTong: "; kq.Xuat();

    kq = ps1.Hieu(ps2);
    cout << "\nHieu: "; kq.Xuat();

    kq = ps1.Tich(ps2);
    cout << "\nTich: "; kq.Xuat();

    kq = ps1.Thuong(ps2);
    cout << "\nThuong: "; kq.Xuat();

    cout << "\n\n--- So sanh ---";
    int ss = ps1.SoSanh(ps2);
    if (ss == 1) cout << "\nPhan so 1 lon hon phan so 2";
    else if (ss == -1) cout << "\nPhan so 1 nho hon phan so 2";
    else cout << "\nHai phan so bang nhau";

    cout << endl;
    return 0;
}

