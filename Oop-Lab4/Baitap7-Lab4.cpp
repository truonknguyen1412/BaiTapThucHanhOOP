#include <iostream>
#include <vector>

using namespace std;

class CVector {
public:
    int n;
    vector<double> v;
    CVector(int chieu = 0) : n(chieu), v(chieu, 0) {}
    
    void GanDuLieu(const vector<double>& data) {
        v = data;
        n = data.size();
    }

    friend ostream& operator<<(ostream& out, const CVector& cv) {
        out << "(";
        for (int i = 0; i < cv.n; i++) out << cv.v[i] << (i == cv.n - 1 ? "" : ", ");
        out << ")";
        return out;
    }
};

class CMatrix {
private:
    int iDong, iCot;
    vector<vector<double>> data;

public:
    CMatrix(int r = 0, int c = 0) : iDong(r), iCot(c) {
        data.assign(iDong, vector<double>(iCot, 0));
    }

    void GanDuLieu(int r, int c, const vector<vector<double>>& d) {
        iDong = r;
        iCot = c;
        data = d;
    }

    friend ostream& operator<<(ostream& out, const CMatrix& m) {
        for (int i = 0; i < m.iDong; i++) {
            for (int j = 0; j < m.iCot; j++) out << m.data[i][j] << "\t";
            out << endl;
        }
        return out;
    }

    CVector operator*(const CVector& vec) {
        if (iCot != vec.n) return CVector(0);
        CVector res(iDong);
        for (int i = 0; i < iDong; i++)
            for (int j = 0; j < iCot; j++)
                res.v[i] += data[i][j] * vec.v[j];
        return res;
    }

    CMatrix operator*(const CMatrix& other) {
        if (iCot != other.iDong) return CMatrix(0, 0);
        CMatrix res(iDong, other.iCot);
        for (int i = 0; i < iDong; i++)
            for (int j = 0; j < other.iCot; j++)
                for (int k = 0; k < iCot; k++)
                    res.data[i][j] += data[i][k] * other.data[k][j];
        return res;
    }
};

int main() {
    CMatrix A, B;
    CVector V(3);

    A.GanDuLieu(2, 3, {
        {1, 2, 3},
        {4, 5, 6}
    });

    B.GanDuLieu(3, 2, {
        {7, 8},
        {9, 10},
        {11, 12}
    });

    V.GanDuLieu({1, 0, 2});

    cout << "Ma tran A (2x3):\n" << A << endl;
    cout << "Ma tran B (3x2):\n" << B << endl;
    cout << "Vector V (3 chieu): " << V << endl;

    CMatrix tichMaTran = A * B;
    cout << "\nKet qua A * B (Ma tran 2x2):\n" << tichMaTran << endl;

    CVector tichVector = A * V;
    cout << "Ket qua A * V (Vector 2 chieu): " << tichVector << endl;

    return 0;
}
