#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

// --- L?P CHA NHAN VIEN ---
class NhanVien {
protected:
    string maNV, hoTen, email, sdt;
    int tuoi;
    long long luongCoBan;

public:
    virtual void nhap() {
        cout << "Nhap ma NV: "; cin >> maNV;
        cin.ignore();
        cout << "Nhap ho ten: "; getline(cin, hoTen);
        cout << "Nhap tuoi: "; cin >> tuoi;
        cout << "Nhap SDT: "; cin >> sdt;
        cout << "Nhap email: "; cin >> email;
        cout << "Nhap luong co ban: "; cin >> luongCoBan;
    }

    virtual void xuat() {
        cout << left << setw(10) << maNV << setw(20) << hoTen << setw(10) << tuoi 
             << setw(15) << sdt << setw(20) << email << setw(15) << tinhLuong();
    }

    virtual long long tinhLuong() = 0; // Ham thuan ao

    string getHoTen() { return hoTen; }
    virtual string getType() = 0; 
};

// --- L?P LAP TRINH VIEN ---
class LapTrinhVien : public NhanVien {
private:
    int soGioOvertime;
public:
    void nhap() override {
        NhanVien::nhap();
        cout << "Nhap so gio overtime: "; cin >> soGioOvertime;
    }
    void xuat() override {
        NhanVien::xuat();
        cout << " | Gio OT: " << soGioOvertime << " (LTV)" << endl;
    }
    long long tinhLuong() override {
        return luongCoBan + (soGioOvertime * 200000);
    }
    string getType() override { return "LTV"; }
};

// --- L?P KIEM CHUNG VIEN ---
class KiemChungVien : public NhanVien {
private:
    int soLoiPhatHien;
public:
    void nhap() override {
        NhanVien::nhap();
        cout << "Nhap so loi phat hien: "; cin >> soLoiPhatHien;
    }
    void xuat() override {
        NhanVien::xuat();
        cout << " | So loi: " << soLoiPhatHien << " (KCV)" << endl;
    }
    long long tinhLuong() override {
        return luongCoBan + (soLoiPhatHien * 50000);
    }
    string getType() override { return "KCV"; }
};

// --- L?P QU?N L? ---
class QuanLyNhanVien {
private:
    vector<NhanVien*> ds;
public:
    void nhapDS() {
        int n, loai;
        cout << "Nhap so luong nhan vien: "; cin >> n;
        for(int i = 0; i < n; i++) {
            cout << "Chon loai (1: Lap trinh vien, 2: Kiem chung vien): ";
            cin >> loai;
            NhanVien* nv;
            if(loai == 1) nv = new LapTrinhVien();
            else nv = new KiemChungVien();
            nv->nhap();
            ds.push_back(nv);
        }
    }

    void xuatDS() {
        cout << "\n--- DANH SACH NHAN VIEN ---\n";
        for(auto nv : ds) nv->xuat();
    }

    double tinhLuongTrungBinh() {
        if(ds.empty()) return 0;
        long long tong = 0;
        for(auto nv : ds) tong += nv->tinhLuong();
        return (double)tong / ds.size();
    }

    void xuatLuongThapHonTB() {
        double tb = tinhLuongTrungBinh();
        cout << "\n--- NV CO LUONG THAP HON TB (" << tb << ") ---\n";
        for(auto nv : ds) {
            if(nv->tinhLuong() < tb) nv->xuat();
        }
    }

    void xuatMaxMin() {
        if(ds.empty()) return;
        NhanVien *maxNV = ds[0], *minNV = ds[0];
        for(auto nv : ds) {
            if(nv->tinhLuong() > maxNV->tinhLuong()) maxNV = nv;
            if(nv->tinhLuong() < minNV->tinhLuong()) minNV = nv;
        }
        cout << "\nNV LUONG CAO NHAT: "; maxNV->xuat();
        cout << "NV LUONG THAP NHAT: "; minNV->xuat();
    }

    void xuatLTVMax_KCVMin() {
        NhanVien *maxLTV = nullptr, *minKCV = nullptr;
        for(auto nv : ds) {
            if(nv->getType() == "LTV") {
                if(!maxLTV || nv->tinhLuong() > maxLTV->tinhLuong()) maxLTV = nv;
            }
            if(nv->getType() == "KCV") {
                if(!minKCV || nv->tinhLuong() < minKCV->tinhLuong()) minKCV = nv;
            }
        }
        if(maxLTV) { cout << "\nLTV LUONG CAO NHAT: "; maxLTV->xuat(); }
        if(minKCV) { cout << "\nKCV LUONG THAP NHAT: "; minKCV->xuat(); }
    }

    ~QuanLyNhanVien() {
        for(auto nv : ds) delete nv;
    }
};

int main() {
    QuanLyNhanVien ql;
    ql.nhapDS();      // Cau a
    ql.xuatDS();      // Cau b
    ql.xuatLuongThapHonTB(); // Cau c
    ql.xuatMaxMin();  // Cau d, e
    ql.xuatLTVMax_KCVMin(); // Cau f, g
    return 0;
}
