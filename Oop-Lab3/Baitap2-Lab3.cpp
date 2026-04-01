#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>
const double PI = 3.14;
using namespace std;
class Diem{
	private:
		double x,y;
	public:
		Diem(){
			x = y = 0;
		}
		void Nhap(){
			cin >> x >> y;
		}
		void Xuat(){
			cout << "(" << x << "," << y << ")" <<endl;
		}
		double getX(){
			return this->x;
		}
		double getY(){
			return this->y;
		}
		void TinhTien(double dx, double dy){
			x += dx;
			y += dy;
		}
		void phongTo(double k){
		    x *= k;
		    y *= k;
		}
		
		void quay(double rad){
		    double new_x = x * cos(rad) - y * sin(rad);
		    double new_y = x * sin(rad) + y * cos(rad);
		    x = new_x;
    		y = new_y;
		}
};
class cDaGiac {
private:
    vector<Diem> ds;

    double khoangCach(Diem A, Diem B) {
        return sqrt(pow(A.getX() - B.getX(), 2) +  pow(A.getY() - B.getY(), 2));
    }

public:
    void Nhap() {
        int n;
        cout << "Nhap so dinh: ";
        cin >> n;

        ds.resize(n);

        for (int i = 0; i < n; i++) {
            cout << "Nhap diem " << i+1 << ": ";
            ds[i].Nhap();
        }
    }

    void Xuat() {
        cout << "Da giac gom cac diem:\n";
        for (int i = 0; i < ds.size(); i++) {
            ds[i].Xuat();
            cout << " ";
        }
        cout << endl;
    }

    double ChuVi() {
        double cv = 0;
        int n = ds.size();

        for (int i = 0; i < n; i++) {
            cv += khoangCach(ds[i], ds[(i+1)%n]); 
        }
        return cv;
    }

    double DienTich() {
        double S = 0;
        int n = ds.size();

        for (int i = 0; i < n; i++) {
            int j = (i + 1) % n;
            S += ds[i].getX() * ds[j].getY();
            S -= ds[j].getX() * ds[i].getY();
        }

        return abs(S) / 2;
    }

    void tinhTien(double dx, double dy) {
        for (int i = 0; i < ds.size(); i++) {
            ds[i].TinhTien(dx, dy);
        }
    }

	void phongTo(double k){
	    for(int i = 0; i < ds.size(); i++){
	        ds[i].phongTo(k);
	    }
	}
	
	void thuNho(double k){
	    if(k == 0) return;
	    for(int i = 0; i < ds.size(); i++){
	        ds[i].phongTo(1.0 / k);
	    }
	}
	
	void quay(double goc_degree){
	    double rad = goc_degree * M_PI / 180;
	    for(int i = 0; i < ds.size(); i++){
	        ds[i].quay(rad);
	    }
	}
};

int main() {
    cDaGiac dg;

    dg.Nhap();
    dg.Xuat();

    cout << fixed << setprecision(2);
    cout << "Chu vi: " << dg.ChuVi() << endl;
    cout << "Dien tich: " << dg.DienTich() << endl;

    double dx, dy;
    cout << "\nNhap tinh tien (dx dy): ";
    cin >> dx >> dy;
    dg.tinhTien(dx, dy);

    cout << "Sau tinh tien:\n";
    dg.Xuat();

    double k;
    cout << "\nNhap he so phong to: ";
    cin >> k;
    dg.phongTo(k);

    cout << "Sau phong to:\n";
    dg.Xuat();

    double k2;
    cout << "\nNhap he so thu nho: ";
    cin >> k2;
    dg.thuNho(k2);

    cout << "Sau thu nho:\n";
    dg.Xuat();

    double goc;
    cout << "\nNhap goc quay (degree): ";
    cin >> goc;
    dg.quay(goc);

    cout << "Sau quay:\n";
    dg.Xuat();

    return 0;
}
