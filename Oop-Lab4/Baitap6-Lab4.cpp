#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class CVector {
private:
    int n;
    vector<double> v;

public:
    CVector(int chieu = 0) {
        n = chieu;
        v.assign(n, 0);
    }

    friend istream& operator>>(istream& in, CVector& cv) {
        cout << "Nhap so chieu: ";
        in >> cv.n;
        cv.v.assign(cv.n, 0);
        for (int i = 0; i < cv.n; i++) {
            cout << "Toa do " << i + 1 << ": ";
            in >> cv.v[i];
        }
        return in;
    }

    friend ostream& operator<<(ostream& out, const CVector& cv) {
        out << "(";
        for (int i = 0; i < cv.n; i++) {
            out << cv.v[i] << (i == cv.n - 1 ? "" : ", ");
        }
        out << ")";
        return out;
    }

    CVector operator+(const CVector& other) {
        if (n != other.n) return CVector(0);
        CVector res(n);
        for (int i = 0; i < n; i++) {
            res.v[i] = v[i] + other.v[i];
        }
        return res;
    }

    CVector operator-(const CVector& other) {
        if (n != other.n) return CVector(0);
        CVector res(n);
        for (int i = 0; i < n; i++) {
            res.v[i] = v[i] - other.v[i];
        }
        return res;
    }

    double TichVoHuong(const CVector& other) {
        if (n != other.n) return 0;
        double res = 0;
        for (int i = 0; i < n; i++) {
            res += v[i] * other.v[i];
        }
        return res;
    }

    double DoDai() {
        double sum = 0;
        for (double x : v) sum += x * x;
        return sqrt(sum);
    }
};

int main() {
    CVector v1, v2;
    cin >> v1;
    cin >> v2;

    cout << "v1 = " << v1 << endl;
    cout << "v2 = " << v2 << endl;

    CVector tong = v1 + v2;
    cout << "v1 + v2 = " << tong << endl;

    cout << "Tich vo huong: " << v1.TichVoHuong(v2) << endl;
    cout << "Do dai v1: " << v1.DoDai() << endl;

    return 0;
}
