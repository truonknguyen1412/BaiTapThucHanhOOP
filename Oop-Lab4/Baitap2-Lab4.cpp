#include <iostream>
#include <cmath>
using namespace std;
class PhanSo{
	private:
		int tu, mau;
	public:
		PhanSo(int t = 0, int m = 1){
			this->tu = t;
			this->mau = (mau == 0) ? 1 : m;
			Rutgon();
		}
		int getTu(){
			return this->tu;
		}
		int getMau(){
			return this->mau;
		}
		int timUCLN(int a, int b){
			a = abs(a); b = abs(b);
			while(b != 0){
				int tam = a % b;
				a = b;
				b = tam;
			}
			return a;
		}
		void Rutgon(){
        int ucln = timUCLN(tu, mau);
        tu /= ucln;
        mau /= ucln;
        if (mau < 0) { tu = -tu; mau = -mau; }
    	}
		PhanSo operator+ (const PhanSo& b){
			return PhanSo(this->tu * b.mau + b.tu * this->mau, this->mau * b.mau);
		}
		PhanSo operator- (const PhanSo& b){
			return PhanSo(this->tu * b.mau - b.tu * this->mau, this->mau * b.mau);
		}
		PhanSo operator* (const PhanSo& b){
			return PhanSo(this->tu * b.tu, this->mau * b.mau);
		}
		PhanSo operator/ (const PhanSo& b){
			return PhanSo(this->tu * b.mau, b.tu * this->mau);
		}
		bool operator> (PhanSo& b){
			return this->tu * b.mau > b.tu * this->mau;
		}
		bool operator< (PhanSo& b){
			return this->tu * b.mau < b.tu * this->mau;
		}
		bool operator== (PhanSo& b){
			return this->tu * b.mau == b.tu * this->mau;
		}
		friend istream& operator>> (istream& in, PhanSo& ps){
			in >> ps.tu >> ps.mau;
			ps.Rutgon();
			return in;
		}
		friend ostream& operator<< (ostream& out, PhanSo ps){
			if(ps.mau == 1) out << ps.tu;
			else out << ps.tu << "/" << ps.mau;
			return out;
		}
};
int main(){
    PhanSo a, b;
    cout << "Nhap phan so a:\n"; cin >> a;
    cout << "Nhap phan so b:\n"; cin >> b;

    cout << "\nKet qua cac phep tinh:" << endl;
    cout << a << " + " << b << " = " << (a + b) << endl;
    cout << a << " - " << b << " = " << (a - b) << endl;
    cout << a << " * " << b << " = " << (a * b) << endl;
    cout << a << " / " << b << " = " << (a / b) << endl;

    cout << "\nSo sanh:" << endl;
    if (a > b) cout << a << " lon hon " << b << endl;
    else if (a < b) cout << a << " nho hon " << b << endl;
    else cout << "Hai phan so bang nhau" << endl;
}
