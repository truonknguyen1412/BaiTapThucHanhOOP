#include <iostream>
#include <cmath>
#include <string>
#include <vector>
using namespace std;
class NhanVien {
	protected:
		string ho_ten, ngay_sinh;
	public:
		virtual void Nhap(){
			cin.ignore();
			cout << "Nhap ho ten: "; getline(cin,ho_ten);
			cout << "Nhap ngay sinh: "; getline(cin,ngay_sinh);
		}
		virtual void Xuat(){
			cout << "Ho va ten: " << ho_ten << endl;
			cout << "Ngay sinh: " << ngay_sinh <<endl;
		}
		virtual double tinhluong() = 0;
		virtual int laytuoi(){
			int nam;
			nam = stoi(ngay_sinh.substr(6,4));
			return 2026 - nam;
		}
		virtual ~NhanVien(){
		}
};
class NhanVienSX : public NhanVien {
	private:
		double luongcanban;
		int sosanpham;
	public:
		double tinhluong() override {
			return luongcanban + sosanpham * 5000;
		}
		void Nhap() override {
			NhanVien :: Nhap();
			cout << "Nhap luong can ban: "; cin >> luongcanban;
			cout << "Nhap so san pham: "; cin >> sosanpham;
		}
		void Xuat() override {
			NhanVien :: Xuat();
			cout << "Loai: Nhan Vien San Xuat" << endl;
			cout << "Luong: " << tinhluong() << endl;
		}
};
class NhanVienVP : public NhanVien{
	private:
		int songaylamviec;
	public:
		void Nhap() override {
			NhanVien :: Nhap();
			cout << "Nhap so ngay lam viec: "; cin >> songaylamviec;
		}
		double tinhluong() override{
			return songaylamviec * 100000;
		}
		void Xuat() override {
			NhanVien :: Xuat();
			cout << "Loai: Nhan Vien Van Phong" << endl;
			cout << "Luong: " << tinhluong() << endl;
		}
};
int main(){
	vector <NhanVien*> ds;
	int n;
	cout << "Nhap so nhan vien: "; cin >> n;
	for(int i = 0; i < n; i++){
		int loai;
		cout << "\n1. Nhan Vien San Xuat";
		cout << "\n2. Nhan Vien Van Phong" << endl;
		cout << "Chon Loai: ";
		cin >> loai;
		NhanVien* nv;
		if(loai == 1){
			nv = new NhanVienSX();
		}
		else if(loai == 2){
			nv = new NhanVienVP();
		}
		else return 0;
		nv->Nhap();
		ds.push_back(nv);
	}
	double tongluong = 0;
	cout << "Danh Sach Nhan Vien" << endl;
	for (int i = 0; i < ds.size(); i++){
		ds[i]->Xuat();
		cout << "Luong: " << ds[i]->tinhluong() << endl;
		tongluong += ds[i]->tinhluong();
	}
	cout << "Tong luong cong ty phai tra la: " << tongluong << endl;
	for(int i = 0; i <ds.size(); i++){
		delete ds[i];
	}
	return 0;
}
