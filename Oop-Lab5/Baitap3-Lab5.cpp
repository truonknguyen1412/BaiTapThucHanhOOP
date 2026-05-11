#include <iostream>
#include <cmath>
#include <string>
#include <vector>
using namespace std;
class TruongDH {
	protected:
		string mssv, hoten, diachi;
		int tinchi;
		double dtb;
	public:
		virtual ~TruongDH(){
		}
		virtual void Nhap(){
			cin.ignore();
			cout << "Nhap ma so sinh vien: "; getline(cin, mssv);
			cout << "Nhap ho va ten: "; getline(cin, hoten);
			cout << "Nhap dia chi: "; getline(cin,diachi);
			cout << "Nhap tong so tin chi: "; cin >> tinchi;
			cout << "Nhap diem trung binh: "; cin >> dtb;
		}
		virtual void Xuat(){
			cout << "Ma so sinh vien: " << mssv << endl;
			cout << "Ho va ten cua sinh vien: " << hoten << endl;
			cout << "Tong so tin chi cua sinh vien la: " << tinchi << endl;
			cout << "Diem trung binh cua sinh vien la: " << dtb << endl;
		}
		virtual bool Xettotnghiep() = 0;
		virtual int getLoai() = 0;
		double getDTB(){
			return this->dtb;
		}
};
class SinhVienCaoDang : public TruongDH{
	private:
		double diemthitotnghiep;
	public:
		void Nhap() override {
			TruongDH::Nhap();
			cout << "Nhap diem thi tot nghiep: "; cin >> diemthitotnghiep;
		}
		void Xuat() override{
			TruongDH::Xuat();
			cout << "Diem thi tot nghiep cua sinh vien: " << diemthitotnghiep <<endl;
		}
		bool Xettotnghiep() override{
			if(tinchi >= 120 && dtb >= 5.0 && diemthitotnghiep >= 5.0){
				return true;
			}
			return false;
		}
		int getLoai() override{
			return 1;
		}
};
class SinhVienDaiHoc : public TruongDH{
	private:
		string tenluanvan;
		double diemluanvan;
	public:
		void Nhap() override{
			TruongDH::Nhap();
			cin.ignore();
			cout << "Nhap ten luan van: "; getline(cin,tenluanvan);
			cout << "Nhap diem luan van: "; cin >> diemluanvan;
		}
		void Xuat() override{
			TruongDH::Xuat();
			cout << "Ten luan van cua sinh vien: " << tenluanvan << endl;
			cout << "Diem luan van cua sinh vien: " << diemluanvan << endl;
		}
		bool Xettotnghiep() override{
			if(tinchi >= 170 && dtb >= 5.0 && diemluanvan >= 5.0){
				return true;
			}
			return false;
		}
		int getLoai() override{
			return 2;
		}
};
int main() {
    vector<TruongDH*> ds;
    int n;

    cout << "Nhap so luong sinh vien: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        int loai;
        cout << "\nChon he dao tao (1: Cao dang, 2: Dai hoc): ";
        cin >> loai;

        TruongDH* sv = nullptr;
        if (loai == 1) {
            sv = new SinhVienCaoDang();
        } else if (loai == 2) {
            sv = new SinhVienDaiHoc();
        }

        if (sv != nullptr) {
            cout << "--- Nhap thong tin SV " << i + 1 << " ---" << endl;
            sv->Nhap();
            ds.push_back(sv);
        }
    }

    cout << "\n=== B. DANH SACH TOAN BO SINH VIEN ===" << endl;
    for (TruongDH* sv : ds) {
        sv->Xuat();
    }

    cout << "\n=== C. DANH SACH SINH VIEN DU DIEU KIEN TOT NGHIEP ===" << endl;
    bool coSVDau = false;
    for (TruongDH* sv : ds) {
        if (sv->Xettotnghiep()) {
            sv->Xuat();
            coSVDau = true;
        }
    }
    if (!coSVDau) cout << "Khong co sinh vien nao du dieu kien." << endl;

    cout << "\n=== D. DANH SACH SINH VIEN KHONG DU DIEU KIEN TOT NGHIEP ===" << endl;
    bool coSVRot = false;
    for (TruongDH* sv : ds) {
        if (!sv->Xettotnghiep()) {
            sv->Xuat();
            coSVRot = true;
        }
    }
    if (!coSVRot) cout << "Tat ca sinh vien deu du dieu kien." << endl;

    TruongDH* maxDaiHoc = nullptr;
    double maxDiemDH = -1;
    TruongDH* maxCaoDang = nullptr;
    double maxDiemCD = -1;

    for (TruongDH* sv : ds) {
        if (sv->getLoai() == 2) {
            if (sv->getDTB() > maxDiemDH) {
                maxDiemDH = sv->getDTB();
                maxDaiHoc = sv;
            }
        } else if (sv->getLoai() == 1) {
            if (sv->getDTB() > maxDiemCD) {
                maxDiemCD = sv->getDTB();
                maxCaoDang = sv;
            }
        }
    }

    cout << "\n=== E. SINH VIEN DAI HOC CO DIEM TB CAO NHAT ===" << endl;
    if (maxDaiHoc != nullptr) maxDaiHoc->Xuat();
    else cout << "Khong co sinh vien he Dai hoc." << endl;

    cout << "\n=== F. SINH VIEN CAO DANG CO DIEM TB CAO NHAT ===" << endl;
    if (maxCaoDang != nullptr) maxCaoDang->Xuat();
    else cout << "Khong co sinh vien he Cao dang." << endl;

    int rotCaoDang = 0;
    int rotDaiHoc = 0;
    for (TruongDH* sv : ds) {
        if (!sv->Xettotnghiep()) {
            if (sv->getLoai() == 1) rotCaoDang++;
            else if (sv->getLoai() == 2) rotDaiHoc++;
        }
    }

    cout << "\n=== G. THONG KE SO SINH VIEN KHONG DU DIEU KIEN ===" << endl;
    cout << "- He Cao dang: " << rotCaoDang << " sinh vien." << endl;
    cout << "- He Dai hoc: " << rotDaiHoc << " sinh vien." << endl;

    for (TruongDH* sv : ds) {
        delete sv;
    }
    ds.clear();

    return 0;
}
