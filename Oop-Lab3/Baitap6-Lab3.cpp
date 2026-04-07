#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;
class ThiSinh{
	private:
		string ma, ten, ns;
		double toan, van, anh;
		int n;
	public:
		ThiSinh(){
			ma = ten = ns = " ";
			toan = van = anh = 0.0;
			n = 0;
		}
		ThiSinh(string ma, string ten, string ns, double toan, double van, double anh, int n){
			this->ma = ma;
			this->ten = ten;
			this->ns = ns;
			this->toan = toan;
			this->van = van;
			this->anh = anh;
			this->n = n;
		}
		void Nhap(){
			cout << "Nhap ma thi sinh: "; getline(cin,ma);
			cout << "Nhap ten thi sinh: "; getline(cin,ten);
			cout << "Nhap ngay thang nam sinh thi sinh: "; getline(cin,ns);
			cout << "Nhap diem cua mon toan van anh: ";
			cin >> toan >> van >> anh;
			cout << endl;	
		}
		float TongDiem(){
			return toan + van + anh;
		} 
		void Xuat(){
			cout << "Ma: " << left << setw(10) << ma;
			cout << "Ten: " << left << setw(20) << ten;
			cout << "Ngay sinh: " << left << setw(12) << ns;
			cout << "Toan: " << left << setw(5) << toan;
			cout << "Van: " << left << setw(5) << van;
			cout << "Anh: " << left << setw(5) << anh;
			cout << "Tong diem: " << TongDiem() << endl;
		}
};
class listThiSinh{
	private:
		ThiSinh* ds;
		int n;
	public:
		listThiSinh(){
			ds = NULL;
			n = 0;
		}
		~listThiSinh(){
			delete [] ds;
		}
		void NhapDanhSach(){
			cout << "Nhap so luong thi sinh: "; cin >>n;
			delete[] ds;
			ds = new ThiSinh[n];
			for(int i = 0; i < n; i++){
				cout << "Nhap thong tin thi sinh thu " << i + 1 <<endl;
				cin.ignore();
				ds[i].Nhap();
			}
		}
		void XuatDanhSach(){
			for(int i = 0; i < n; i++){
				ds[i].Xuat();
			}
		}
		void ThiSinhTren15(){
			cout << "Danh sach thi sinh co tong diem tren 15 la: ";
			bool cothisinh = false;
			for(int i = 0; i < n; i++){
				if(ds[i].TongDiem() > 15){
					ds[i].Xuat();
					cothisinh = true;
				}
			}
			if(!cothisinh) cout << "Khong co thi sinh nao co tong diem tren 15" <<endl;
		}
		void ThiSinhCaoNhat(){
			if(n == 0) return;
			cout << "Thi sinh co tong diem cao nhat la: ";
			double max = ds[0].TongDiem();
			for(int i = 0; i < n; i++){
				if(ds[i].TongDiem() > max){
					max = ds[i].TongDiem();
				}
			}
			for(int i = 0; i < n; i++){
				if(ds[i].TongDiem() == max){
					ds[i].Xuat();
				}
			}
		}
		void SapXep(){
			for(int i = 0; i < n; i++){
				for(int j = i + 1; j < n; i++){
					if(ds[i].TongDiem() > ds[j].TongDiem()){
						swap(ds[i],ds[j]);
					}
				}
			}
			cout << "Danh sach thi sinh sap xep giam danh theo tong diem: ";
			XuatDanhSach();
		}
};
int main(){
	listThiSinh list;
	list.NhapDanhSach();
	cout << "Danh sach thi sinh vua nhap: " << endl;
	list.XuatDanhSach();
	list.ThiSinhTren15();
	list.ThiSinhCaoNhat();
	list.SapXep();
	return 0;
}
