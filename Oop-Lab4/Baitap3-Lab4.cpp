#include <iostream>
#include <iomanip>
#include <windows.h>

using namespace std;

class CTime {
private:
    int iGio, iPhut, iGiay;

    void ChuanHoa() {
        iPhut += iGiay / 60;
        iGiay %= 60;
        if (iGiay < 0) { iGiay += 60; iPhut--; }

        iGio += iPhut / 60;
        iPhut %= 60;
        if (iPhut < 0) { iPhut += 60; iGio--; }

        iGio %= 24;
        if (iGio < 0) iGio += 24;
    }

public:
    CTime(int h = 0, int m = 0, int s = 0) : iGio(h), iPhut(m), iGiay(s) {
        ChuanHoa();
    }

    CTime operator+(int s) {
        return CTime(iGio, iPhut, iGiay + s);
    }

    CTime operator-(int s) {
        return CTime(iGio, iPhut, iGiay - s);
    }

    CTime& operator++() {
        iGiay++;
        ChuanHoa();
        return *this;
    }

    CTime& operator--() {
        iGiay--;
        ChuanHoa();
        return *this;
    }

    friend istream& operator>>(istream& in, CTime& t) {
        in >> t.iGio >> t.iPhut >> t.iGiay;
        t.ChuanHoa();
        return in;
    }

    friend ostream& operator<<(ostream& out, const CTime& t) {
        out << setfill('0') << setw(2) << t.iGio << ":"
            << setw(2) << t.iPhut << ":"
            << setw(2) << t.iGiay;
        return out;
    }

    void VeDongHo() {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        COORD pos = { 60, 0 };
        SetConsoleCursorPosition(hConsole, pos);
        cout << "[" << *this << "]";
    }
};

int main() {
    CTime t;
    cout << "Nhap thoi gian (gio phut giay): ";
    cin >> t;

    cout << "Thoi gian hien tai: " << t << endl;

    while (true) {
        t.VeDongHo();
        Sleep(1000);
        ++t;
    }

    return 0;
}
