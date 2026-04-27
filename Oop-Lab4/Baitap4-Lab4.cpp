#include <iostream>

using namespace std;

class CDate {
private:
    int iNgay, iThang, iNam;

    bool LaNamNhuan(int y) const {
        return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
    }

    int SoNgayTrongThang(int m, int y) const {
        int ngay[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if (m == 2 && LaNamNhuan(y)) return 29;
        return ngay[m];
    }

    long long ToTotalDays() const {
        long long total = iNgay;
        for (int y = 1; y < iNam; ++y) total += (LaNamNhuan(y) ? 366 : 365);
        for (int m = 1; m < iThang; ++m) total += SoNgayTrongThang(m, iNam);
        return total;
    }

    void FromTotalDays(long long total) {
        iNam = 1;
        while (total > (LaNamNhuan(iNam) ? 366 : 365)) {
            total -= (LaNamNhuan(iNam) ? 366 : 365);
            iNam++;
        }
        iThang = 1;
        while (total > SoNgayTrongThang(iThang, iNam)) {
            total -= SoNgayTrongThang(iThang, iNam);
            iThang++;
        }
        iNgay = (int)total;
    }

public:
    CDate(int d = 1, int m = 1, int y = 1) : iNgay(d), iThang(m), iNam(y) {}

    CDate operator+(int n) {
        CDate res;
        res.FromTotalDays(this->ToTotalDays() + n);
        return res;
    }

    CDate operator-(int n) {
        CDate res;
        res.FromTotalDays(this->ToTotalDays() - n);
        return res;
    }

    long long operator-(const CDate& other) const {
        return this->ToTotalDays() - other.ToTotalDays();
    }

    CDate& operator++() {
        *this = *this + 1;
        return *this;
    }

    CDate& operator--() {
        *this = *this - 1;
        return *this;
    }

    friend istream& operator>>(istream& in, CDate& d) {
        in >> d.iNgay >> d.iThang >> d.iNam;
        return in;
    }

    friend ostream& operator<<(ostream& out, const CDate& d) {
        out << d.iNgay << "/" << d.iThang << "/" << d.iNam;
        return out;
    }
};

int main() {
    CDate ngayGui, ngayRut;
    double tienGoc, laiSuatNam;

    cout << "Nhap ngay gui (d m y): "; cin >> ngayGui;
    cout << "Nhap ngay rut (d m y): "; cin >> ngayRut;
    cout << "Nhap tien goc: "; cin >> tienGoc;
    cout << "Nhap lai suat nam (%): "; cin >> laiSuatNam;

    long long soNgay = ngayRut - ngayGui;

    if (soNgay < 0) {
        cout << "Ngay khong hop le!" << endl;
    } else {
        double tienLai = tienGoc * (laiSuatNam / 100.0) * (soNgay / 365.0);
        cout << "So ngay gui: " << soNgay << endl;
        cout << "Tien lai: " << (long long)tienLai << endl;
        cout << "Tong tien: " << (long long)(tienGoc + tienLai) << endl;
    }

    return 0;
}
