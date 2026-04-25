#include <iostream>
#include <cmath>
using namespace std;
class SoPhuc{
	private:
		double thuc;
		double ao;
	public:
		SoPhuc(double real = 0.0, double fake = 0.0){
			thuc = real;
			ao = fake;
		}
		double getThuc(){
			return this->thuc;
		}
		double getAo(){
			return this->ao;
		}
		void Nhap(){
			cout << "Nhap phan thuc: "; cin >> thuc;
			cout << "Nhap phan ao: "; cin >> ao;
		}
		void Xuat(){
			cout << thuc;
			if(ao >= 0){
				cout << "+" << ao << "i";
			}
			else cout << "-" << -ao << "i";
			cout << endl;
		}
		SoPhuc Tong(const SoPhuc& b){
			return SoPhuc(thuc + b.thuc, ao + b.ao);
		}
		SoPhuc Hieu(const SoPhuc& b){
			return SoPhuc(this->thuc - b.thuc, this->ao - b.ao);
		}
		SoPhuc Tich(const SoPhuc& b){
			return SoPhuc(this->thuc * b.thuc - this->ao * b.ao, this->thuc * b.ao + this->ao * b.thuc);
		}
		SoPhuc Thuong(const SoPhuc& b){
			double mau = b.thuc * b.thuc + b.ao * b.ao;
			if(mau == 0){
				cout << "Loi chia so phuc bang 0" << endl;
				return SoPhuc(0,0); 
			}
			return SoPhuc((this->thuc * b.thuc + this->ao * b.ao) / mau, (this->ao * b.thuc - this->thuc * b.ao) / mau);
		}
		SoPhuc operator+ (const SoPhuc& b) {
			return Tong(b);
		}
		SoPhuc operator- (const SoPhuc& b){
			return Hieu(b);
		}
		SoPhuc operator* (const SoPhuc& b){
			return Tich(b);
		}
		SoPhuc operator/ (const SoPhuc& b){
			return Thuong(b);
		}
		bool operator== (const SoPhuc& b){
			return (this->thuc == b.thuc) && (this->ao == b.ao);
		}
		bool operator!= (const SoPhuc& b){
			return !(*this == b);
		}
		friend ostream& operator << (ostream& out, const SoPhuc& sp){
			out << sp.thuc;
			if(sp.ao >= 0){
				out << "+" << sp.ao << "i";
			}
			else out << "-" << -sp.ao << "i";
			return out;
		}
		friend istream& operator >> (istream& in, SoPhuc& sp){
			cout << "Nhap phan thuc: "; in >> sp.thuc;
			cout << "Nhap phan ao: "; in >> sp.ao;
			return in;
		}
};
int main(){
	SoPhuc a, b;
	cout << "--- Nhap so phuc A ---" << endl;
	cin >> a;
	cout << "--- Nhap so phuc B ---" << endl;
	cin >> b;
	cout << "\n--- KET QUA ---" << endl;
	cout << "So phuc a = " << a << endl;
	cout << "So phuc b = " << b << endl;
	cout << "a + b = " << a + b << endl;
	cout << "a - b = " << a - b << endl;
	cout << "a * b = " << a * b << endl;
	cout << "a / b = " << a / b << endl;
	if (a == b) {
	    cout << "Hai so phuc a va b bang nhau!" << endl;
	} else {
	    cout << "Hai so phuc a va b khac nhau!" << endl;
	}
	
	return 0;
}
