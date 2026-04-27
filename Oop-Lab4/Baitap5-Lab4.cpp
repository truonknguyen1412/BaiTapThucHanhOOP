#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

class DaThuc {
private:
    int n;
    vector<double> a;

public:
    DaThuc(int bac = 0) {
        n = bac;
        a.assign(n + 1, 0);
    }

    friend istream& operator>>(istream& in, DaThuc& dt) {
        cout << "Nhap bac cua da thuc: ";
        in >> dt.n;
        dt.a.assign(dt.n + 1, 0);
        for (int i = dt.n; i >= 0; i--) {
            cout << "He so x^" << i << ": ";
            in >> dt.a[i];
        }
        return in;
    }

    friend ostream& operator<<(ostream& out, const DaThuc& dt) {
        bool first = true;
        for (int i = dt.n; i >= 0; i--) {
            if (dt.a[i] == 0) continue;
            if (!first && dt.a[i] > 0) out << " + ";
            if (dt.a[i] < 0) out << " - ";
            double val = abs(dt.a[i]);
            if (val != 1 || i == 0) out << val;
            if (i > 0) out << "x";
            if (i > 1) out << "^" << i;
            first = false;
        }
        if (first) out << "0";
        return out;
    }

    double TinhGiaTri(double x) {
        double res = 0;
        for (int i = n; i >= 0; i--) {
            res = res * x + a[i];
        }
        return res;
    }

    DaThuc operator+(const DaThuc& other) {
        int maxBac = max(n, other.n);
        DaThuc res(maxBac);
        for (int i = 0; i <= maxBac; i++) {
            double h1 = (i <= n) ? a[i] : 0;
            double h2 = (i <= other.n) ? other.a[i] : 0;
            res.a[i] = h1 + h2;
        }
        return res;
    }

    DaThuc operator*(const DaThuc& other) {
        int maxBac = n + other.n;
        DaThuc res(maxBac);
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= other.n; j++) {
                res.a[i + j] += a[i] * other.a[j];
            }
        }
        return res;
    }
};

int main() {
    DaThuc p1, p2;
    cout << "Nhap da thuc P1:\n"; cin >> p1;
    cout << "Nhap da thuc P2:\n"; cin >> p2;

    cout << "\nP1 = " << p1;
    cout << "\nP2 = " << p2;

    DaThuc tong = p1 + p2;
    cout << "\nP1 + P2 = " << tong;

    DaThuc tich = p1 * p2;
    cout << "\nP1 * P2 = " << tich;

    double x;
    cout << "\n\nNhap x de tinh P1(x): "; cin >> x;
    cout << "P1(" << x << ") = " << p1.TinhGiaTri(x) << endl;

    return 0;
}
