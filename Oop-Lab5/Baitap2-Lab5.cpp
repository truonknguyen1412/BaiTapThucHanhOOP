#include <iostream>
#include <cmath>
#include <string>
#include <vector>
using namespace std;
class BatDongSan {
	protected:
		string maGD, ngayGD;
		double dongia;
		double dientich;
	public:
		virtual ~BatDongSan(){
		}
		virtual void Nhap(){
			cin.ignore();
			cout << "Nhap ma giao dich: "; getline(cin, maGD);
			cout << "Nhap ngay giao dich: "; getline(cin,ngayGD);
			cout << "Nhap don gia: "; cin >> dongia;
			cout << "Nhap dien tich: "; cin >> dientich;
		}
		virtual void Xuat(){
			cout << "Ma Giao Dich: " << maGD << endl;
			cout << "Ngay Giao Dich" << ngayGD << endl;
			cout << "Don gia: " << dongia << endl;
			cout << "Dien tich: " << dientich << endl;
		}
		virtual double tinhthanhtien() = 0;
		virtual int getLoai() = 0;
		string getNgayGD() {
        	return ngayGD;
    	}
};
class GiaoDichDat : public BatDongSan {
	private:
		char loaidat;
	public:
		void Nhap() override {
			BatDongSan::Nhap();
			cout << "Nhap loai dat (A, B, C): "; cin >> loaidat; 
		}
		void Xuat() override {
			BatDongSan::Xuat();
			cout << "Loai dat la: " << loaidat << "\nThanh tien: " << tinhthanhtien() << endl;
		}
		double tinhthanhtien(){
			if(loaidat == 'A' || loaidat == 'a'){
				return dientich * dongia * 1.5;
			}
			else {
				return dientich * dongia; 
			}
		}
		int getLoai() override {
			return 1;
		}
};
class GiaoDichNhaPho : public BatDongSan {
	private:
		string loainha;
	public:
		void Nhap() override {
			BatDongSan::Nhap();
			cin.ignore();
			cout << "Loai nha (nha cao cap, nha thuong): "; getline(cin,loainha);
		}
		void Xuat() override {
			BatDongSan::Xuat();
			cout << "Loai nha: " << loainha << endl;
			cout << "Thanh tien: " << tinhthanhtien() << endl;
		}
		double tinhthanhtien() override {
			if(loainha == "Nha cao cap" || loainha == "nha cao cap"){
				return dientich * dongia;
			}
			else if(loainha == "Nha thuong" || loainha == "nha thuong"){
				return dientich * dongia * 0.9;
			}
			else return 0;
		}
		int getLoai(){
			return 2;
		}
};
class GiaoDichChungCu : public BatDongSan {
	private:
		string macan;
		int tang;
	public:
		void Nhap() override {
			BatDongSan::Nhap();
			cin.ignore();
			cout << "Nhap ma can: "; getline(cin,macan);
			cout << "Nhap tang: "; cin >> tang;
		}
		void Xuat() override{
			BatDongSan::Xuat();
			cout << "Ma can: " << macan << endl;
			cout << "Thanh tien: " << tinhthanhtien() << endl;
		}
		double tinhthanhtien() override{
			if(tang == 1){
				return dientich * dongia * 2;
			}
			else if(tang >= 15){
				return dientich * dongia * 1.2;
			}
			else return dientich * dongia;
		}
		int getLoai(){
			return 3;
		}
};
int main() {
    vector<BatDongSan*> ds;
    int n;
    
    cout << "Nhap so luong giao dich: ";
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        int loai;
        cout << "\nChon loai giao dich (1-Dat, 2-Nha Pho, 3-Chung Cu): ";
        cin >> loai;
        
        BatDongSan* bds = nullptr;
        if (loai == 1) {
            bds = new GiaoDichDat();
        } else if (loai == 2) {
            bds = new GiaoDichNhaPho();
        } else if (loai == 3) {
            bds = new GiaoDichChungCu();
        }
        
        if (bds != nullptr) {
            cout << "--- Nhap thong tin ---" << endl;
            bds->Nhap();
            ds.push_back(bds);
        }
    }
    
    int slDat = 0, slNhaPho = 0, slChungCu = 0;
    double tongTienChungCu = 0;
    
    for (BatDongSan* bds : ds) {
        if (bds->getLoai() == 1) slDat++;
        else if (bds->getLoai() == 2) slNhaPho++;
        else if (bds->getLoai() == 3) {
            slChungCu++;
            tongTienChungCu += bds->tinhthanhtien();
        }
    }
    
    cout << "\n=== TONG SO LUONG GIAO DICH ===" << endl;
    cout << "Dat: " << slDat << ", Nha Pho: " << slNhaPho << ", Chung Cu: " << slChungCu << endl;
    
    cout << "\n=== TRUNG BINH THANH TIEN CHUNG CU ===" << endl;
    if (slChungCu > 0) {
        cout << tongTienChungCu / slChungCu << endl;
    } else {
        cout << "Khong co giao dich chung cu." << endl;
    }
    
    BatDongSan* maxNhaPho = nullptr;
    double maxTien = 0;
    
    for (BatDongSan* bds : ds) {
        if (bds->getLoai() == 2) {
            if (bds->tinhthanhtien() > maxTien) {
                maxTien = bds->tinhthanhtien();
                maxNhaPho = bds;
            }
        }
    }
    
    cout << "\n=== GIAO DICH NHA PHO CO GIA TRI CAO NHAT ===" << endl;
    if (maxNhaPho != nullptr) {
        maxNhaPho->Xuat();
    } else {
        cout << "Khong co giao dich nha pho." << endl;
    }
    
    cout << "\n=== DANH SACH GIAO DICH THANG 12/2024 ===" << endl;
    bool coThang12 = false;
    for (BatDongSan* bds : ds) {
        if (bds->getNgayGD().find("/12/2024") != string::npos) {
            bds->Xuat();
            cout << "------------------" << endl;
            coThang12 = true;
        }
    }
    if (!coThang12) {
        cout << "Khong co giao dich trong thang 12/2024." << endl;
    }
    
    for (BatDongSan* bds : ds) {
        delete bds;
    }
    ds.clear();
    
    return 0;
}

