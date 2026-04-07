#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>
using namespace std;
class Array{
	private:
		int* a;
		int n;
	public:
		bool LaSoNguyenTo(int n){
			if(n < 2) return false;
			for(int i = 2; i <= sqrt(n); i++){
				if(n % i == 0) return false;
			}
			return true;
		}
		Array(){
			a = NULL;
			n = 0;
		}
		~Array(){
			delete[] a;
		}
		void TaoMangNgauNhien(int size){
			n = size;
			a = new int[n];
			srand(time(NULL));
			for(int i = 0; i < n; i++){
				a[i] = rand() % 100;
			}
		}
		void XuatMang(){
			for(int i = 0; i < n; i++){
				cout << a[i] << " ";
			}
			cout <<endl;
		}
		int DemSo(int x){
			int count = 0;
			for(int i = 0; i < n; i++){
				if(a[i] == x) count++;
			}
			return count;
		}
		bool KiemTraTangDan(){
			for(int i = 0; i < n - 1; i++){
				if(a[i] > a[i + 1]) return false;
			}
			return true;
		}
		int TimLeNhoNhat(){
			int minle = -1;
			for(int i = 0; i < n; i++){
				if(a[i] % 2 != 0){
					if(minle == -1 || a[i] < minle) minle = a[i];
				}
			}
			return minle;
		}
		int TimNguyenToLonNhat(){
			int max = -1;
			for(int i = 0; i < n; i++){
				if(LaSoNguyenTo(a[i])){
					if(max == -1 || a[i] > max) max = a[i];
				}
			}
			return max;
		}
		void SapXep(bool tangDan = true) {
	        for (int i = 0; i < n - 1; i++) {
	            for (int j = i + 1; j < n; j++) {
	                if (tangDan) {
	                    if (a[i] > a[j]) swap(a[i], a[j]);
	                } else {
	                    if (a[i] < a[j]) swap(a[i], a[j]);
	                }
	            }
	        }
	    }	
};
int main() {
    Array arr;
    int n, x;

    cout << "Nhap so phan tu cua mang: ";
    cin >> n;

    arr.TaoMangNgauNhien(n);
    
    cout << "Mang vua tao ngau nhien: ";
    arr.XuatMang();

    cout << "\nNhap gia tri x can dem: ";
    cin >> x;
    cout << "So lan xuat hien cua " << x << " la: " << arr.DemSo(x) << endl;

    if (arr.KiemTraTangDan()) 
        cout << "Mang dang tang dan." << endl;
    else 
        cout << "Mang khong tang dan." << endl;

    int leMin = arr.TimLeNhoNhat();
    if (leMin != -1) cout << "So le nho nhat: " << leMin << endl;
    else cout << "Khong co so le trong mang." << endl;

    int ntMax = arr.TimNguyenToLonNhat();
    if (ntMax != -1) cout << "So nguyen to lon nhat: " << ntMax << endl;
    else cout << "Khong co so nguyen to trong mang." << endl;

    cout << "\nMang sau khi sap xep tang dan: ";
    arr.SapXep(true);
    arr.XuatMang();

    return 0;
}

