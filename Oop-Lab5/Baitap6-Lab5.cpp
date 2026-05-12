#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>

using namespace std;

class KhachHang {
protected:
    string hoTen;
    int soLuong;
    double donGia;
public:
    virtual void nhap(ifstream &is) {
        is.ignore();
        getline(is, hoTen);
        is >> soLuong >> donGia;
    }
    
    string getHoTen() { return hoTen; }
    virtual double tinhTien() = 0; 
    virtual ~KhachHang() {}
};

class KhachHangA : public KhachHang {
public:
    double tinhTien() override {
        double thanhTien = soLuong * donGia;
        return thanhTien + (thanhTien * 0.1); 
    }
};

class KhachHangB : public KhachHang {
private:
    int soNam;
public:
    void nhap(ifstream &is) override {
        KhachHang::nhap(is);
        is >> soNam;
    }
    double tinhTien() override {
        double phanTramKM = max(soNam * 0.05, 0.5);
        double thanhTien = (soLuong * donGia) * (1 - phanTramKM);
        return thanhTien + (thanhTien * 0.1);
    }
};

class KhachHangC : public KhachHang {
public:
    double tinhTien() override {
        double thanhTien = (soLuong * donGia) * 0.5;
        return thanhTien + (thanhTien * 0.1);
    }
};

class QuanLyKhachHang {
private:
    vector<KhachHang*> ds;
    int x, y, z;
public:
    void docFile(string filename) {
        ifstream is(filename);
        if (!is.is_open()) return;

        is >> x >> y >> z;

        for (int i = 0; i < x; ++i) {
            KhachHang* kh = new KhachHangA();
            kh->nhap(is);
            ds.push_back(kh);
        }
        for (int i = 0; i < y; ++i) {
            KhachHang* kh = new KhachHangB();
            kh->nhap(is);
            ds.push_back(kh);
        }
        for (int i = 0; i < z; ++i) {
            KhachHang* kh = new KhachHangC();
            kh->nhap(is);
            ds.push_back(kh);
        }
        is.close();
    }

    void ghiFile(string filename) {
        ofstream os(filename);
        if (!os.is_open()) return;

        os << x << " " << y << " " << z << endl;
        double tongCongTy = 0;

        for (auto kh : ds) {
            double tien = kh->tinhTien();
            os << kh->getHoTen() << endl;
            os << (long long)tien << endl;
            tongCongTy += tien;
        }

        os << (long long)tongCongTy << endl;
        os.close();
    }

    ~QuanLyKhachHang() {
        for (auto kh : ds) delete kh;
    }
};

int main() {
    QuanLyKhachHang ql;
    ql.docFile("XYZ.INP");
    ql.ghiFile("XYZ.OUT");
    return 0;
}
