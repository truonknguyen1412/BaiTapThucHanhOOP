#include <iostream>
using namespace std;
#include <cmath>
#include <iomanip>
const double PI = 3.14159265358979323846;
class Diem{
	private:
		double x, y;
	public:
		Diem(){
			x = y = 0;
		}
		void Nhap(){
			cout << "Nhap gia tri x va y: "; cin >> x >> y;
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
		void tinhTien(double dx, double dy){
        	x += dx;
        	y += dy;
	    }
	    void quay(double goc_degree) { 
	        double rad = goc_degree * PI / 180.0;
	        double new_x = x * cos(rad) - y * sin(rad);
	        double new_y = x * sin(rad) + y * cos(rad);
	        x = new_x; y = new_y;
    	}
    	double Phongto(double k){
    		x *= k;
    		y *= k;
		}
};
class TamGiac{
	private:
		Diem A,B,C;
	public:
		void Nhap(){
			cout << "Nhap A: "; A.Nhap();
			cout << "Nhap B: "; B.Nhap();
			cout << "Nhap C: "; C.Nhap();
		}
		void Xuat(){
			cout << "A = "; A.Xuat();
			cout << "\nB = "; B.Xuat();
			cout << "\nC = "; C.Xuat();
		}
		double canh(Diem P, Diem Q){
			return sqrt(pow(P.getX() - Q.getX(),2) + pow(P.getY() - Q.getY(),2));
		}
		double Chuvi(){
			double a = canh(A,B);
			double b = canh(A,C);
			double c = canh(B,C);
			return a + b + c;
		}
		double dientich(){
			double a = canh(A,B);
			double b = canh(A,C);
			double c = canh(B,C);
			double p = (a + b + c) / 2;
			return sqrt(p * (p - a) * (p - b) * (p - c));	
		}
		void LoaiTamGiac(){
			double a = canh(A,B);
			double b = canh(A,C);
			double c = canh(B,C);
			if(a == b || a == c || b == c) cout << "Tam Giac Can";
			else if(a == b && b == c) cout << "Tam Giac Deu";
			else if(pow(a,2) + pow(b,2) == pow(c,2) || pow(b,2) + pow(c,2) == pow(a,2) || pow(a,2) + pow(c,2) == pow(b,2)){
				if(a == b || a == c || b == c){
					cout << "Tam Giac Vuong Can";
				}
				else cout << "Tam Giac Vuong";
			}
			else cout << "Tam Giac Thuong";
		}
	    void tinhTien(double dx, double dy){
	        A.tinhTien(dx,dy);
	        B.tinhTien(dx,dy);
	        C.tinhTien(dx,dy);
	    }

	    double phongTo(double k){
	        A.Phongto(k);
	        B.Phongto(k);
	        C.Phongto(k);
	    }
	
	    void quay(double goc_degree){
	        double rad = goc_degree * PI / 180;
	        A.quay(rad);
	        B.quay(rad);
	        C.quay(rad);
	    }
};
int main(){
	TamGiac tg;

    tg.Nhap();
    tg.Xuat();

    cout << "Chu vi: " << tg.Chuvi() << endl;
    cout << "Dien tich: " << tg.dientich() << endl;
	cout << "Loai Tam Giac la: " ;
	tg.LoaiTamGiac();
	
	cout << fixed << setprecision(2);
    double dx, dy;
    cout << "\nNhap tinh tien: ";
    cin >> dx >> dy;
    tg.tinhTien(dx,dy);
    tg.Xuat();

    double k;
    cout << "\nNhap he so phong to: ";
    cin >> k;
    tg.phongTo(k);
    tg.Xuat();

    double goc;
    cout << "\nNhap goc quay: ";
    cin >> goc;
    tg.quay(goc);
    tg.Xuat();

    return 0;
}
