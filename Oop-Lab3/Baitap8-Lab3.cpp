#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

class cNhanVienSX {
private:
    string msnv, ho_ten, ngay_sinh;
    int so_sp;
    double don_gia;
    
public:
    cNhanVienSX(string msnv, string ht, string ns, int sosp, double dongia) {
        this->msnv = msnv;
        this->ho_ten = ht;
        this->ngay_sinh = ns;
        this->so_sp = sosp;
        this->don_gia = dongia;
    }
    
    cNhanVienSX() {
        msnv = ho_ten = ngay_sinh = "";
        so_sp = 0;
        don_gia = 0;
    }
    
    double getluong() {
        return so_sp * don_gia; 
    }
    
    string getho_ten() {
        return this->ho_ten;
    }
    
    int getNamSinh() {
        int dodai = ngay_sinh.length();
        string nam = ngay_sinh.substr(dodai - 4); 
        return atoi(nam.c_str()); 
    }
    
    void Nhap() {
        cout << "Nhap ma so nhan vien: "; getline(cin >> ws, msnv);
        cout << "Nhap ho va ten: "; getline(cin, ho_ten);
        cout << "Nhap ngay thang nam sinh (dd/mm/yyyy): "; getline(cin, ngay_sinh);
        cout << "Nhap so san pham da gia cong: "; cin >> so_sp;
        cout << "Nhap don gia 1 san pham: "; cin >> don_gia;
    }
    
    void Xuat() {
        cout << "Ma NV: " << msnv 
             << " | Ho ten: " << ho_ten 
             << " | Ngay sinh: " << ngay_sinh 
             << " | So SP: " << so_sp 
             << " | Don gia: " << don_gia
             << " | Luong thuc nhan: " << getluong() << endl;
    }
};

class listNhanVienSX { 
private:
    vector<cNhanVienSX> ds;
    
public:
    void NhapDanhSach() {
        int n;
        cout << "Nhap so luong nhan vien san xuat: "; cin >> n;
        for(int i = 0; i < n; i++) {
            cout << "\n--- Nhap thong tin nhan vien thu " << i + 1 << " ---" << endl;
            cNhanVienSX nv;
            nv.Nhap();
            ds.push_back(nv);
        }
    }
    
    void XuatDanhSach() {
        for(int i = 0; i < ds.size(); i++) {
            ds[i].Xuat();
        }
    }
    
    void LuongThapNhat() {
        if(ds.size() == 0) return;
        
        double minLuong = ds[0].getluong(); 
        
        for(int i = 1; i < ds.size(); i++) {
            if(ds[i].getluong() < minLuong) { 
                minLuong = ds[i].getluong(); 
            }
        }
        
        cout << "\n--- Nhan vien co luong thap nhat (" << minLuong << ") ---" << endl;
        for(int i = 0; i < ds.size(); i++) {
            if(ds[i].getluong() == minLuong) {
                ds[i].Xuat();
            }
        }
    }
    
    void TongLuong() { 
        double sum = 0; 
        for(int i = 0; i < ds.size(); i++) {
            sum += ds[i].getluong();
        }
        cout << "\nTong luong ma cong ty phai tra la: " << sum << endl;
    }
    
    void NhanVienGiaNhat() {
        if(ds.size() == 0) return;
        
        int minnam = ds[0].getNamSinh(); 
        
        for(int i = 1; i < ds.size(); i++) {
            if(ds[i].getNamSinh() < minnam) { 
                minnam = ds[i].getNamSinh(); 
            }
        }
        
        cout << "\n--- Nhan vien gia nhat (sinh nam " << minnam << ") ---" << endl;
        for(int i = 0; i < ds.size(); i++) {
            if(ds[i].getNamSinh() == minnam) { 
                ds[i].Xuat();
            }
        }
    }
    
    void NhanVienTangDanTheoLuong() {
        for(int i = 0; i < ds.size() - 1; i++) {
            for(int j = i + 1; j < ds.size(); j++) {
                if(ds[i].getluong() > ds[j].getluong()) {
                    cNhanVienSX tam = ds[i];
                    ds[i] = ds[j];
                    ds[j] = tam;
                }
            }
        }
    }	
};

int main() {
    listNhanVienSX congty;
    
    congty.NhapDanhSach();
    
    cout << "\n============= DANH SACH NHAN VIEN =============" << endl;
    congty.XuatDanhSach();
    
    congty.LuongThapNhat(); 
    congty.TongLuong();
    congty.NhanVienGiaNhat();
    
    cout << "\n====== DANH SACH SAU KHI SAP XEP LUONG ======" << endl;
    congty.NhanVienTangDanTheoLuong(); 
    congty.XuatDanhSach();
    
    return 0;
}
