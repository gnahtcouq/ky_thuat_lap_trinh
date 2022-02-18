#include <iostream>
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
  cout << "Nhap ma nv: ";
  cin >> nv.ma;
  cin.ignore();
  cout << "Nhap ten nv: ";
  cin.getline(nv.ten, 50);
  cout << "Nhap tuoi: ";
  cin >> nv.tuoi;
  cin.ignore();
  cout << "Nhap chuc vu: ";
  cin.getline(nv.chucVu, 50);
  cout << "He so luong: ";
  cin >> nv.heSoLuong;
  //Chon pb?
  xuatDanhSachPhongBan();
  int x;
  do {
    cout << "Chon phong ban theo STT: ";
    cin >> x;
  } while (x <= 0 || x > dspb.soLuong);
  strcpy_s(nv.maPB, dspb.ds[x - 1].ma);
  cin.ignore();
}
void xuatNhanVien(NhanVien nv) {
  cout << nv.ma << "\t" << nv.ten << "\t" << nv.tuoi << "\t" << nv.chucVu << "\t" << nv.heSoLuong << "\t" << layTenPB(nv.maPB) << endl;
}
void xuatDanhSachNhanVien() {
  for (int i = 0; i < dsnv.soLuong; i++)
    xuatNhanVien(dsnv.ds[i]);

}
char* layTenPB(char ma[]) {
  for (int i = 0; i < dspb.soLuong; i++)
    if (strcmp(dspb.ds[i].ma, ma) == 0)
      return dspb.ds[i].ten;
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
  cout << "Nhap ma PB: ";
  cin >> pb.ma;
  cin.ignore();
  cout << "Nhap ten PB: ";
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
void nhapDanhSachNhanVien() {
  do {
    cout << "Co bao nhieu nhan vien: ";
    cin >> dsnv.soLuong;
  } while (dsnv.soLuong <= 0 || dsnv.soLuong > MAX);
  for (int i = 0; i < dsnv.soLuong; i++) {
    nhapNhanVien(dsnv.ds[i]);
  }
}
//void xuatDanhSachNhanVien()
//{
//	for (int i = 0; dsnv.soLuong; i++)
//		xuatNhanVien(dsnv.ds[i]);
//}
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






//void xuatNhanVien(NhanVien nv)
//{
//
//	cout << nv.ten << "\t" << nv.tuoi << "\t" << nv.chucVu << "\t" << nv.heSoLuong << endl;
//}
void nhapDanhSachNhanVien(DanhSachNhanVien& dsnv) {
  do {
    cout << "Nhap so NV: ";
    cin >> dsnv.soLuong;
  } while (dsnv.soLuong <= 0 || dsnv.soLuong > MAX);
  cin.ignore();
  for (int i = 0; i < dsnv.soLuong; i++) {
    nhapNhanVien(dsnv.ds[i]);
  }
}
//void xuatDanhSachNhanVien(DanhSachNhanVien dsnv)
//{
//	for (int i = 0; i < dsnv.soLuong; i++)
//	{
//		xuatNhanVien(dsnv.ds[i]);
//	}
//}

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


bool them(DanhSachNhanVien& dsnv, NhanVien nvMoi)//them nvMoi vao cuoi ds
{
  if (dsnv.soLuong == MAX)
    return false;
  dsnv.ds[dsnv.soLuong++] = nvMoi;
  //dsnv.soLuong = dsnv.soLuong + 1;
}
bool capNhat(DanhSachNhanVien& dsnv, char ten[]) {
  for (int i = 0; i < dsnv.soLuong; i++)
    if (strcmp(dsnv.ds[i].ten, ten) == 0) {
      int chon;
      do {
        cout << "1. Cap nhat ten: " << endl;
        cout << "2. Cap nhat tuoi: " << endl;
        cout << "3. Cap nhat chuc vu: " << endl;
        cout << "4. Cap nhat he so luong: " << endl;
        cout << "0. Thoat" << endl;
        cout << "Ban muon cap nhat gi? ";
        cin >> chon;
        if (chon == 0)
          break;
        if (chon == 1) {
          cin.ignore();
          cout << "Nhap ten moi: ";
          cin.getline(dsnv.ds[i].ten, 50);
        }
        else if (chon == 2) {
          cout << "Nhap tuoi: ";
          cin >> dsnv.ds[i].tuoi;
        }
        else if (chon == 3) {
          cin.ignore();
          cout << "Nhap chuc vu: ";
          cin.getline(dsnv.ds[i].chucVu, 50);
        }
        else if (chon == 4) {
          cout << "Nhap he so luong moi: ";
          cin >> dsnv.ds[i].heSoLuong;
        }
        else
          cout << "Chon sai roi";

      } while (1);
      return true;
    }
  return false;
}

int main() {
  //nhapDanhSachPhongBan();
  docDanhSachPhongBan("phongban.dat");
  docDanhSachNhanVien(dsnv, "nhanvien.dat");
  //nhapDanhSachNhanVien(dsnv);
  //ghiDanhSachNhanVien(dsnv, "nhanvien.dat");
  xuatDanhSachNhanVien();

  cout << endl;
  system("pause");
  return 0;
}