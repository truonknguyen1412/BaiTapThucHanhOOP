#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

class cDaThuc {
private:
    int bac;
    double* heSo;

    void ChuanHoa() {
        while (bac > 0 && heSo[bac] == 0) {
            bac--;
        }
    }

public:
    cDaThuc() {
        bac = 0;
        heSo = new double[1];
        heSo[0] = 0;
    }

    cDaThuc(int n) {
        bac = n;
        heSo = new double[bac + 1];
        for (int i = 0; i <= bac; i++) {
            heSo[i] = 0;
        }
    }

    cDaThuc(const cDaThuc& other) {
        bac = other.bac;
        heSo = new double[bac + 1];
        for (int i = 0; i <= bac; i++) {
            heSo[i] = other.heSo[i];
        }
    }

    ~cDaThuc() {
        delete[] heSo;
    }

    void Nhap() {
        cout << "Nhap bac cua da thuc: ";
        cin >> bac;
        
        delete[] heSo;
        heSo = new double[bac + 1];
        
        for (int i = bac; i >= 0; i--) {
            cout << "He so cua x^" << i << ": ";
            cin >> heSo[i];
        }
    }

    void Xuat() {
        bool laSoDauTien = true;
        for (int i = bac; i >= 0; i--) {
            if (heSo[i] != 0) {
                if (!laSoDauTien) {
                    if (heSo[i] > 0) cout << " + ";
                    else cout << " - ";
                } else {
                    if (heSo[i] < 0) cout << "-";
                    laSoDauTien = false;
                }
                
                double giaTriTuyetDoi = abs(heSo[i]);
                if (giaTriTuyetDoi != 1 || i == 0) cout << giaTriTuyetDoi;
                if (i > 0) cout << "x";
                if (i > 1) cout << "^" << i;
            }
        }
        if (laSoDauTien) cout << "0";
        cout << endl;
    }

    double TinhGiaTri(double x) {
        double ketQua = 0;
        for (int i = 0; i <= bac; i++) {
            ketQua += heSo[i] * pow(x, i);
        }
        return ketQua;
    }

    cDaThuc Cong(const cDaThuc& B) {
        int maxBac = max(bac, B.bac);
        cDaThuc kq(maxBac);

        for (int i = 0; i <= maxBac; i++) {
            double heSoA = (i <= bac) ? heSo[i] : 0;
            double heSoB = (i <= B.bac) ? B.heSo[i] : 0;
            kq.heSo[i] = heSoA + heSoB;
        }
        kq.ChuanHoa();
        return kq;
    }

    cDaThuc Tru(const cDaThuc& B) {
        int maxBac = max(bac, B.bac);
        cDaThuc kq(maxBac);

        for (int i = 0; i <= maxBac; i++) {
            double heSoA = (i <= bac) ? heSo[i] : 0;
            double heSoB = (i <= B.bac) ? B.heSo[i] : 0;
            kq.heSo[i] = heSoA - heSoB;
        }
        kq.ChuanHoa();
        return kq;
    }
};

int main() {
    cDaThuc A, B;

    cout << "--- NHAP DA THUC A ---" << endl;
    A.Nhap();
    cout << "Da thuc A vua nhap: ";
    A.Xuat();

    cout << "\n--- NHAP DA THUC B ---" << endl;
    B.Nhap();
    cout << "Da thuc B vua nhap: ";
    B.Xuat();

    cout << "\n--- KIEM THU CAC PHEP TOAN ---" << endl;
    double x;
    cout << "Nhap gia tri x de tinh P(x) cho da thuc A: ";
    cin >> x;
    cout << "P(" << x << ") = " << A.TinhGiaTri(x) << endl;

    cDaThuc Tong = A.Cong(B);
    cout << "\nTong hai da thuc A + B = ";
    Tong.Xuat();

    cDaThuc Hieu = A.Tru(B);
    cout << "Hieu hai da thuc A - B = ";
    Hieu.Xuat();

    return 0;
}
