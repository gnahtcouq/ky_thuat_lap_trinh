#include <iostream>
#include <cstring>
using namespace std;

const int MAX = 50;

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
  cin.ignore();
}

void xuatNhanVien(NhanVien nv) {
  cout << nv.ten << "\t" << nv.tuoi << "\t" << nv.chucVu << "\t" << nv.heSoLuong << endl;
}

void nhapDanhSachNhanVien(DanhSachNhanVien& dsnv) {
  do {
    cout << "Nhap so nhan vien: ";
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

bool them(DanhSachNhanVien& dsnv, NhanVien nvMoi) { // them nhan vien moi vao cuoi danh sach
  if (dsnv.soLuong == MAX)
    return false;
  dsnv.ds[dsnv.soLuong++] = nvMoi;
  // dsnv.soLuong = dsnv.soLuong + 1;
}

int soNhanVienHeSoHon3(DanhSachNhanVien dsnv) {
  int dem = 0;
  for (int i = 0; i < dsnv.soLuong; i++) {
    if (dsnv.ds[i].heSoLuong > 3)
      dem++;
  }
  return dem;
}

bool ghiDanhSachNhanVienHeSoTren3(DanhSachNhanVien ds, char* tenFile) {
  FILE* f;
  fopen_s(&f, tenFile, "wb");
  if (f == NULL)
    return false;
  DanhSachNhanVien dshs3 = dsNhanVienHeSonHon3(ds);
  fwrite(&dshs3.soLuong, sizeof(int), 1, f);
  fwrite(&dshs3.ds, sizeof(NhanVien), dshs3.soLuong, f);
  fclose(f);
  return true;
}

int soNhanVienXuatSac(DanhSachNhanVien dsnv, float luongCB) {
  int dem = 0;
  for (int i = 0; i < dsnv.soLuong; i++) {
    if (dsnv.ds[i].heSoLuong * luongCB / 24 >= 150000)
      dem++;
  }
  return dem;
}

bool ghiDanhSachNhanVien2(DanhSachNhanVien ds, char* tenFile) {
  FILE* f;
  fopen_s(&f, tenFile, "wb");
  if (f == NULL)
    return false;
  fwrite(&ds.soLuong, sizeof(int), 1, f);
  fwrite(&ds.ds, sizeof(NhanVien), ds.soLuong, f);
  int soNVXS = soNhanVienXuatSac(ds, 600000);
  int soNV3 = soNhanVienHeSoHon3(ds);
  fwrite(&soNVXS, sizeof(int), 1, f);
  fwrite(&soNV3, sizeof(int), 1, f);
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

DanhSachNhanVien dsNhanVienHeSonHon3(DanhSachNhanVien dsnv) {
  DanhSachNhanVien kq;
  kq.soLuong = 0;
  for (int i = 0; i < dsnv.soLuong; i++) {
    if (dsnv.ds[i].heSoLuong > 3)
      kq.ds[kq.soLuong++] = dsnv.ds[i];
  }
  return kq;
}

DanhSachNhanVien dsCongNhanLuongCao1(DanhSachNhanVien dsnv) {
  float max = 0;
  for (int i = 0; i < dsnv.soLuong; i++) {
    if (strcmp(dsnv.ds[i].chucVu, "CN") == 0 && dsnv.ds[i].heSoLuong > max)
      max = dsnv.ds[i].heSoLuong;
  }
  DanhSachNhanVien kq;
  kq.soLuong = 0;
  if (max == 0)
    return kq;
  for (int i = 0; i < dsnv.soLuong; i++) {
    if (strcmp(dsnv.ds[i].chucVu, "CN") == 0 && dsnv.ds[i].heSoLuong == max)
      kq.ds[kq.soLuong++] = dsnv.ds[i];
  }
  return kq;
}

int main() {
  DanhSachNhanVien ds1;
  NhanVien nv1;

  cout << endl;
  return 0;
}