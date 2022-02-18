#include <iostream>
using namespace std;
#define MAX 100

struct NhanVien {
  char ten[50];
  int tuoi;
  char chucVu[50];
  float heSoLuong;
};
struct DanhSachNhanVien {
  NhanVien ds[100];
  int soLuong;
};
void nhapNhanVien(NhanVien& nv);
void xuatNhanVien(NhanVien nv);
void nhapDanhSachNhanVien(DanhSachNhanVien& dsnv);
void xuatDanhSachNhanVien(DanhSachNhanVien dsnv);
bool ghiDanhSachNhanVien(DanhSachNhanVien ds, char* tenFile);
bool docDanhSachNhanVien(DanhSachNhanVien& ds, char* tenFile);
int soNhanVienHeSoHon3(DanhSachNhanVien dsnv);
int soNhanVienXuatSac(DanhSachNhanVien dsnv, float luongCB);
DanhSachNhanVien xuatDanhSachNhanVienHeSoTren3(DanhSachNhanVien dsnv);
bool ghiDanhSachNhanVienHeSoTren3(DanhSachNhanVien ds, char* tenFile);
bool docDanhSachNhanVien2(DanhSachNhanVien& ds, char* tenFile, int& soNVXS, int& soNV3);

int main() {
  NhanVien nv;
  DanhSachNhanVien ds1, ds2;
  int soNVXS, soNV3;


  // nhapDanhSachNhanVien(ds1);
  // if(ghiDanhSachNhanVien(ds1, "nhanvien.dat"))
  //   cout << "\nDa ghi thanh cong" << endl;
  // else
  //   cout << "\nGhi file khong duoc" << endl;
  // xuatDanhSachNhanVien(ds1);



  // if (docDanhSachNhanVien(ds1, "nhanvien.dat")) {
  //   cout << "\nThong tin cua cac nhan vien vua doc la: " << endl;
  //   xuatDanhSachNhanVien(ds1);
  //   cout << "\nCo " << soNhanVienHeSoHon3(ds1) << " co he so luong > 3";
  //   cout << "\nCo " << soNhanVienXuatSac(ds1, 600000) << " nhan vien xuat sac";
  // }
  // else {
  //   cout << "\nDoc khong duoc";
  //   exit;
  // }

  // if (ghiDanhSachNhanVienHeSoTren3(ds1, "nhanvien2.dat"))
  //   cout << "\nDa ghi thanh cong" << endl;
  // else
  //   cout << "\nGhi file khong duoc" << endl;



  if (docDanhSachNhanVien2(ds2, "nhanvien2.dat", soNVXS, soNV3)) {
    cout << "\nThong tin cua danh sach nhan vien co HS luong tren 3 va XL xuat sac: " << endl;
    xuatDanhSachNhanVien(ds2);
  }
  else {
    cout << "\nDoc khong duoc";
    exit;
  }

  cout << endl;
  system("pause");
  return 0;
}

void nhapNhanVien(NhanVien& nv) {
  cout << "Nhap ten nhan vien: ";
  cin.getline(nv.ten, 50);
  cout << "Nhap tuoi: ";
  cin >> nv.tuoi;
  cin.ignore();
  cout << "Nhap chuc vu: ";
  cin.getline(nv.chucVu, 50);
  cout << "He so luong: ";
  cin >> nv.heSoLuong;
  cout << endl;
  cin.ignore();
}

void xuatNhanVien(NhanVien nv) {
  cout << nv.ten << "\t" << nv.tuoi << "\t" << nv.chucVu << "\t" << nv.heSoLuong << endl;
}

void nhapDanhSachNhanVien(DanhSachNhanVien& dsnv) {
  do {
    cout << "\nNhap so luong nhan vien: ";
    cin >> dsnv.soLuong;
  } while (dsnv.soLuong <= 0 || dsnv.soLuong > MAX);
  cin.ignore();
  for (int i = 0; i < dsnv.soLuong; i++) {
    nhapNhanVien(dsnv.ds[i]);
  }
}

void xuatDanhSachNhanVien(DanhSachNhanVien dsnv) {
  for (int i = 0; i < dsnv.soLuong; i++) {
    xuatNhanVien(dsnv.ds[i]);
  }
}

bool ghiDanhSachNhanVien(DanhSachNhanVien ds, char* tenFile) {
  FILE* f;
  fopen_s(&f, tenFile, "wb");
  if (f == NULL)
    return false;
  fwrite(&ds.soLuong, sizeof(int), 1, f);
  fwrite(&ds.ds, sizeof(NhanVien), ds.soLuong, f);
  fclose(f);
  return true;
}

bool docDanhSachNhanVien(DanhSachNhanVien& ds, char* tenFile) {
  FILE* f;
  fopen_s(&f, tenFile, "rb");
  if (f == NULL)
    return false;
  fread(&ds.soLuong, sizeof(int), 1, f);
  fread(&ds.ds, sizeof(NhanVien), ds.soLuong, f);
  fclose(f);
  return true;
}

int soNhanVienHeSoHon3(DanhSachNhanVien dsnv) {
  int dem = 0;
  for (int i = 0; i < dsnv.soLuong; i++) {
    if (dsnv.ds[i].heSoLuong > 3)
      dem++;
  }
  return dem;
}

int soNhanVienXuatSac(DanhSachNhanVien dsnv, float luongCB) {
  int dem = 0;
  for (int i = 0; i < dsnv.soLuong; i++) {
    if (dsnv.ds[i].heSoLuong * luongCB / 24 >= 150000)
      dem++;
  }
  return dem;
}

DanhSachNhanVien danhSachNhanVienHeSoTren3(DanhSachNhanVien dsnv) {
  DanhSachNhanVien ketqua;
  ketqua.soLuong = 0;
  for (int i = 0; i < dsnv.soLuong; i++) {
    if (dsnv.ds[i].heSoLuong > 3)
      ketqua.ds[ketqua.soLuong++] = dsnv.ds[i];
  }
  return ketqua;
}

bool ghiDanhSachNhanVienHeSoTren3(DanhSachNhanVien ds, char* tenFile) {
  FILE* f;
  fopen_s(&f, tenFile, "wb");
  if (f == NULL)
    return false;
  DanhSachNhanVien dshs3 = danhSachNhanVienHeSoTren3(ds);
  fwrite(&dshs3.soLuong, sizeof(int), 1, f);
  fwrite(&dshs3.ds, sizeof(NhanVien), dshs3.soLuong, f);
  fclose(f);
  return true;
}

bool docDanhSachNhanVien2(DanhSachNhanVien& ds, char* tenFile, int& soNVXS, int& soNV3) {
  FILE* f;
  fopen_s(&f, tenFile, "rb");
  if (f == NULL)
    return false;
  fread(&ds.soLuong, sizeof(int), 1, f);
  fread(&ds.ds, sizeof(NhanVien), ds.soLuong, f);
  fread(&soNVXS, sizeof(int), 1, f);
  fread(&soNV3, sizeof(int), 1, f);
  fclose(f);
  return true;
}