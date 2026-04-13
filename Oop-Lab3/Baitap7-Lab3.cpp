#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;
class NhanVien{
	private:
		string msnv, ho_ten, ngay_sinh;
		double luong;
	public:
		NhanVien(string msnv, string ht, string ns, double luong){
			this->msnv = msnv;
			ho_ten = ht;
			ngay_sinh = ns;
			this->luong = luong;
		}
		NhanVien(){
			msnv = ho_ten = ngay_sinh = " ";
			luong = 0;
		}
		double getluong(){
			return this->luong;
		}
		string getho_ten(){
			return this->ho_ten;
		}
		int getngay_sinh(){
			int dodai = ngay_sinh.length();
			string nam = ngay_sinh.substr(dodai - 4);
			return atoi(nam.c_str());
		}
		void Nhap(){
			cout << "Nhap ma so nhan vien: "; getline(cin >> ws, msnv);
			cout << "Nhap ho va ten: "; getline(cin,ho_ten);
			cout << "Nhap ngay thang nam sinh: "; getline(cin,ngay_sinh);
			cout << "Nhap luong cua nhan vien: "; cin >>luong;
		}
		void Xuat(){
			cout << "Ma so nhan vien: " << msnv << endl;
			cout << "Ho va ten cua nhan vien: " << ho_ten << endl;
			cout << "Ngay thang nam sinh cua nhan vien: " << ngay_sinh << endl;
			cout << "Luong cua nhan vien: " << luong << endl;
		}
};
class listNhanVien{
	private:
		vector<NhanVien> ds;
	public:
		void NhapDanhSach(){
			int n;
			cout << "Nhap so luong nhan vien: "; cin >> n;
			for(int i = 0; i < n; i++){
				cout << "Nhap thong tin nhan vien thu " << i + 1 << ":" << endl;
				NhanVien nv;
				nv.Nhap();
				ds.push_back(nv);
			}
		}
		void XuatDanhSach(){
			for(int i = 0; i < ds.size(); i++){
				ds[i].Xuat();
			}
		}
		void LuongCaoNhat(){
			if(ds.size() == 0) return;
			double temp = ds[0].getluong();
			for(int i = 0; i < ds.size(); i++){
				if(ds[i].getluong() > temp){
					temp = ds[i].getluong();
				}
			}
			cout << "Nhan vien san xuat co luong cao nhat (" << temp << "):" << endl;
			for(int i = 0; i < ds.size(); i++){
				if(ds[i].getluong() == temp){
					ds[i].Xuat();
				}
			}
		}
		void TongLuong(){
			double sum = 0;
			for(int i = 0; i < ds.size(); i++){
				sum += ds[i].getluong();
			}
			cout << "Tong luong ma cong ty phai tra la: " << sum << endl;
		}
		void NhanVienGiaNhat(){
			if(ds.size() == 0) return;
			int minnam = ds[0].getngay_sinh();
			for(int i = 0; i < ds.size(); i++){
				if(ds[i].getngay_sinh() < minnam){
					minnam = ds[i].getngay_sinh();
				}
			}
			cout << "Nhan vien gia nhat (sinh nam " << minnam << "): " << endl;
			for(int i = 0; i < ds.size(); i++){
				if(ds[i].getngay_sinh() == minnam){
					ds[i].Xuat();
				}
			}
		}
		void NhanVienTangDanTheoLuong(){
			for(int i = 0; i < ds.size(); i++){
				for(int j = i + 1; j < ds.size(); j++){
					if(ds[i].getluong() > ds[j].getluong()){
						NhanVien tam = ds[i];
						ds[i] = ds[j];
						ds[j] = tam;
					}
				}
			}
		}	
};
int main(){
	listNhanVien congty;
	congty.NhapDanhSach();
	cout << "Danh sach nhan vien: " << endl;
	congty.XuatDanhSach();
	congty.LuongCaoNhat();
	congty.TongLuong();
	congty.NhanVienGiaNhat();
	cout << "Danh sach sau khi sap xep theo luong: " << endl;
	congty.NhanVienTangDanTheoLuong();
	congty.XuatDanhSach();
	return 0;
}
