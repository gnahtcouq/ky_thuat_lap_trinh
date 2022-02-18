#include <iostream>
#include <cstring>
using namespace std;
const int MAX = 100;

struct PhongBan {
  char ma[10], ten[50];
};
struct DanhSachPhongBan {
  PhongBan ds[MAX];
  int soLuong;
};
char* layTenPB(char ma[]);
void xuatDanhSachPhongBan();
void xuatNhanVien(NhanVien n);
void nhapDanhSachNhanvien();
void nhapNhanVien(NhanVien& nv);
struct NhanVien {
  char ma[10];
  char maPB[10];
  char ten[50];
  int tuoi;
  char chucVu[50];
  float heSoLuong;
};
struct DanhSachNhanVien {
  NhanVien ds[100];
  int soLuong;
};
DanhSachNhanVien dsnv;
DanhSachPhongBan dspb;

void nhapNhanVien(NhanVien& nv) {
  cout << "Nhap ma nhan vien: ";
  cin >> nv.ma;
  cin.ignore();

  cout << "Nhap ten nhan vien: ";
  cin.getline(nv.ten, 50);
  cout << "Nhap tuoi: ";
  cin >> nv.tuoi;
  cin.ignore();
  cout << "Nhap chuc vu: ";
  cin.getline(nv.chucVu, 50);
  cout << "He so luong: ";
  cin >> nv.heSoLuong;
  // Chon pb?
  xuatDanhSachPhongBan();
  int x;
  do {
    cout << "Chon phong ban theo STT: ";
    cin >> x;
  } while (x <= 0 || x > dspb.soLuong);
  strcpy(nv.maPB, dspb.ds[x - 1].ma);
  cin.ignore();
}

void xuatNhanVien(NhanVien nv) {
  cout << nv.ma << "\t" << nv.ten << "\t" << nv.tuoi << "\t" << nv.chucVu << "\t" << nv.heSoLuong << "\t" << layTenPB(nv.maPB) << endl;
}

void xuatDanhSachNhanVien() {
  for (int i = 0; i < dsnv.soLuong;i++)
    xuatNhanVien(dsnv.ds[i]);
}

char* layTenPB(char ma[]) {
  for (int i = 0; i < dspb.soLuong; i++)
    if (strcmp(dspb.ds[i].ma, ma) == 0)
      return dspb.ds[i].ten;
}

bool ghiDanhSachPhongBan(char* tenFile) {
  FILE* f;
  fopen_s(&f, tenFile, "wb");
  if (f == NULL)
    return false;
  fwrite(&dspb.soLuong, sizeof(int), 1, f);
  fwrite(&dspb.ds, sizeof(NhanVien), dspb.soLuong, f);
  fclose(f);
  return true;
}

bool docDanhSachPhongBan(char* tenFile) {
  FILE* f;
  fopen_s(&f, tenFile, "rb");
  if (f == NULL)
    return false;
  fread(&dspb.soLuong, sizeof(int), 1, f);
  fread(&dspb.ds, sizeof(PhongBan), dspb.soLuong, f);
  fclose(f);
  return true;
}

void xuatPhongBan(PhongBan pb) {
  cout << pb.ma << "\t" << pb.ten << endl;
}

void xuatDanhSachPhongBan() {
  for (int i = 0; i < dspb.soLuong; i++) {
    cout << i + 1 << ". " << dspb.ds[i].ma << "\t" << dspb.ds[i].ten << endl;
  }
}

void nhapPhongBan(PhongBan& pb) {
  cout << "Nhap ma phong ban: ";
  cin >> pb.ma;
  cin.ignore();
  cout << "Nhap ten phong ban: ";
  cin.getline(pb.ten, 50);
}

void nhapDanhSachPhongBan() {
  do {
    cout << "Co bao nhieu phong ban: ";
    cin >> dspb.soLuong;
  } while (dspb.soLuong <= 0 || dspb.soLuong > MAX);
  for (int i = 0; i < dspb.soLuong; i++) {
    nhapPhongBan(dspb.ds[i]);
  }
}

void nhapDanhSachNhanvien() {
  do {
    cout << "Co bao nhieu nhan vien: ";
    cin >> dsnv.soLuong;
  } while (dsnv.soLuong <= 0 || dsnv.soLuong > MAX);
  for (int i = 0; i < dsnv.soLuong; i++) {
    nhapNhanVien(dsnv.ds[i]);
  }
}



int main() {

  cout << endl;
  return 0;
}