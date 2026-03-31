#include <iostream>
#include <cmath>
using namespace std;
class SoPhuc{
	private:
		double thuc, ao;
	public:
		SoPhuc(){
			thuc = ao = 0;
		}
		SoPhuc(double thuc, double ao){
			this->thuc = thuc;
			this->ao = ao;
		}
		void Nhap();
		void Xuat();
		SoPhuc operator + (const SoPhuc& sp2);
		SoPhuc operator - (const SoPhuc& sp2);
		SoPhuc operator * (const SoPhuc& sp2);
		SoPhuc operator / (const SoPhuc& sp2);
};
void SoPhuc::Nhap(){
	cout << "Nhap phan thuc: "; cin >> thuc;
	cout << "Nhap phan ao: "; cin >> ao;
}
void SoPhuc::Xuat(){
	cout << thuc;
	if(ao >= 0) cout << "+" << ao << "i";
	else cout << ao << "i";
}
SoPhuc SoPhuc::operator + (const SoPhuc& ps2){
	return SoPhuc(this->thuc + ps2.thuc, this->ao + ps2.ao);
}
SoPhuc SoPhuc::operator - (const SoPhuc& ps2){
	return SoPhuc(this->thuc - ps2.thuc, this->ao - ps2.ao);
}
SoPhuc SoPhuc::operator * (const SoPhuc& ps2){
	double thuc2 = this->thuc * ps2.thuc - this->ao * ps2.ao;
	double ao2 = this->thuc * ps2.thuc + this->ao * ps2.ao;
	return SoPhuc(thuc2, ao2);
}
SoPhuc SoPhuc::operator / (const SoPhuc& sp2){
	double mauso = sp2.thuc * sp2.thuc + sp2.ao + sp2.ao;
	if(mauso == 0){
		cout << "\nLoi. Mau so bang 0";
		return SoPhuc(0,0);
	}
	double thuc2 = (this->thuc * sp2.thuc + this->ao * sp2.ao) / mauso;
	double ao2 = (this->thuc * sp2.thuc - this->ao * sp2.ao) / mauso;
	return SoPhuc(thuc2, ao2);
}
	int main(){
	SoPhuc sp1, sp2, kq;

    cout << "--- Nhap So Phuc 1 ---\n";
    sp1.Nhap();
    cout << "--- Nhap So Phuc 2 ---\n";
    sp2.Nhap();

    cout << "\nSo phuc 1: "; sp1.Xuat();
    cout << "\nSo phuc 2: "; sp2.Xuat();

    cout << "\n\n--- Ket qua su dung Operator ---";
    kq = sp1 + sp2;
    cout << "\nTong: "; kq.Xuat();
    kq = sp1 - sp2;
    cout << "\nHieu: "; kq.Xuat();
    kq = sp1 * sp2;
    cout << "\nTich: "; kq.Xuat();
    kq = sp1 / sp2;
    cout << "\nThuong: "; kq.Xuat();
    cout << endl;
    return 0;
}
