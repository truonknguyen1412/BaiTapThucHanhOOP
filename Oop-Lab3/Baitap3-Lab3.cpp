#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
class PhanSo{
	private:
		int tu, mau;
	public:
		PhanSo(){
			tu = 0;
			mau = 1;
		}
		PhanSo(int tu, int mau){
			this->tu = tu;
			this->mau = mau;
		}
		void Nhap(){
			cout << "Nhap toan hang tu: "; cin >> tu;
			do{
				cout << "Nhap toan hang mau: ";
				cin >> mau;
				if(mau == 0) cout << "Khong hop le. Vui long nhap lai:";
			} while(mau == 0);
		}
		static void Nhap(vector<PhanSo> &ds){
			int n;
			cout << "Nhap so luong phan so: "; cin >> n;
			ds.resize(n);		
			for(int i = 0; i < ds.size(); i++){
				cout << "Nhap phan so thu " << i + 1 << ":" << endl;
				ds[i].Nhap();
			}	
		}
		void Xuat(){
			cout << tu << "/" << mau <<endl;
		}
		static void Xuat(vector<PhanSo> &ds){
			for(int i = 0; i < ds.size(); i++){
				ds[i].Xuat();
			}
		}
		
		int getTu(){ return this->tu;}
		int getMau(){ return this->mau;}
		double giatri(){
			return (double)tu / mau;
		}
		PhanSo TinhTong();
		static void TimMaxMin(vector<PhanSo> &ds){
			if (ds.empty()) return;
			PhanSo max = ds[0];
			PhanSo min = ds[0];
			for(int i = 0; i < ds.size(); i++){
				if(ds[i].giatri() > max.giatri()){
					max = ds[i];
				}
				if(ds[i].giatri() < min.giatri()){
					min = ds[i];
				}
			}
			cout << "Phan so lon nhat la: "; max.Xuat(); cout <<endl;
			cout << "Phan so nho nhat la: "; min.Xuat(); cout << endl;
		}
		bool kiemtrasonguyento(){
			if(tu < 2) return false;
			for(int i = 2; i*i <= tu; i++){
				if(tu % i == 0) return false;
			}
			return true;
		}
		static void TimTuSoNguyenTo(vector<PhanSo> &ds){
			if (ds.empty()) return;
			bool timthay = false;
			int maxtu = -1;
			PhanSo timduoc;
			for(int i = 0; i < ds.size(); i++){
				if(ds[i].kiemtrasonguyento() == true){
					if(ds[i].getTu() > maxtu){
						maxtu = ds[i].getTu();
						timduoc = ds[i];
						timthay = true;
					}
				}
			}
			if(timthay){
				cout << "Phan so co tu la so nguyen to lon nhat la: ";
				timduoc.Xuat();
				cout << endl;
			}
			else cout << "Khong co phan so nao co tu la so nguyen to" << endl;
		}
		static void SapXepTangDan(vector<PhanSo> &ds){
			if (ds.empty()) return;
			for(int i = 0; i < ds.size(); i++){
				for(int j = i + 1; j < ds.size(); j++){
					if(ds[i].giatri() > ds[j].giatri()){
						swap(ds[i],ds[j]);
					}
				}
			}
			cout << "Danh sach khi sap xep tang dan la: ";
			Xuat(ds);
		}
		static void SapXepGiamDan(vector<PhanSo> &ds){
			if (ds.empty()) return;
			for(int i = 0; i < ds.size(); i++){
				for(int j = i + 1; j < ds.size(); j++){
					if(ds[i].giatri() < ds[j].giatri()){
						swap(ds[i],ds[j]);
					}
				}
			}
			cout << "Danh sach khi sap xep giam dan la: ";
			Xuat(ds);
		}
		PhanSo TinhTong(PhanSo ps2){
	        PhanSo kq;
	        kq.tu = this->tu * ps2.mau + ps2.tu * this->mau;
	        kq.mau = this->mau * ps2.mau;
	        return kq;
    	}
    	static void TinhTongDS(vector<PhanSo> &ds){
	        if (ds.empty()) return;
	        PhanSo tong = ds[0];
	        for (int i = 1; i < ds.size(); i++) {
	            tong = tong.TinhTong(ds[i]);
	        }
	        cout << "Tong cac phan so la: ";
	        tong.Xuat(); 
	        cout << endl;
    	}
};

	

int main(){
	vector<PhanSo> ds; 
    
    PhanSo::Nhap(ds);
    
    cout << "\n--- DANH SACH VUA NHAP ---" << endl;
    PhanSo::Xuat(ds);
    
    cout << "\n--- KET QUA YEU CAU ---" << endl;
    PhanSo::TinhTongDS(ds);
    PhanSo::TimMaxMin(ds);
    PhanSo::TimTuSoNguyenTo(ds);
    
    cout << "\n--- SAP XEP ---" << endl;
    PhanSo::SapXepTangDan(ds);
    cout << endl;
    PhanSo::SapXepGiamDan(ds);
    
    return 0;
}



