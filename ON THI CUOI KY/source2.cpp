#include <iostream>
#include <string.h>
using namespace std;
#define MAX 50

struct DaySoThuc {
  int n;
  float data[MAX];
};

void nhapDaySo(DaySoThuc &ds);
void xuatDaySo(DaySoThuc ds);
void xuatSoAm(DaySoThuc ds);
bool kiemTraToanSoNguyen(DaySoThuc ds);


const int MAX2 = 100;
struct Matrix {
  int data[MAX][MAX];
  int n;
};
void docMaTran(Matrix& a);
void xuatMaTran(Matrix a);
void inTamGiacDuoiBenTrai(Matrix a);
int tinhTongTamGiacDuoiBenTrai(Matrix a);
void hoanViDong(Matrix &m, int i, int j);

int main() {
  // DaySoThuc ds;
  // nhapDaySo(ds);
  // xuatDaySo(ds);

  // cout << "\nXuat so am: ";
  // xuatSoAm(ds);

  // bool check = kiemTraToanSoNguyen(ds);
  // if (check)
  //   cout << "\nDay chua toan so nguyen";
  // else
  //   cout << "\nKhong phai la day chua toan so nguyen";



  Matrix a;
  docMaTran(a);
  xuatMaTran(a);
  cout << "\nTam giac duoi ben trai: " << endl;
  inTamGiacDuoiBenTrai(a);

  int tong = tinhTongTamGiacDuoiBenTrai(a);
  cout << "\nTong tam giac duoi ben trai = " << tong;

  int i, j;
  cout << "\nNhap dong can hoan doi: ";
  cin >> i;
  cout << "Hoan doi voi dong: ";
  cin >> j;
  hoanViDong(a, i, j);


  system("pause");
  return 0;
}

void nhapDaySo(DaySoThuc &ds) {
  do {
    cout << "\nNhap so luong phan tu: ";
    cin >> ds.n;
    if (ds.n < 1 || ds.n > MAX)
      cout << "\nNhap sai. Hay nhap lai";
  } while (ds.n < 1 || ds.n > MAX);

  for (int i = 0; i < ds.n; i++) {
    cout << "\nNhap phan tu thu " << i + 1 << " = ";
    cin >> ds.data[i];
  }
}

void xuatDaySo(DaySoThuc ds) {
  for (int i = 0; i < ds.n; i++)
    cout << ds.data[i] << " ";
}

void xuatSoAm(DaySoThuc ds) {
  int dem = 0;
  int dem2 = 0;
  for (int i = 0; i < ds.n; i++)
    if (ds.data[i] < 0)
      dem++;
  if (dem == 0)
    cout << "\nDay so khong co so am";
  for (int i = 0; i < ds.n; i++)
    if (dem < 10 && ds.data[i] < 0)
      cout << ds.data[i] << " ";
  for (int i = ds.n - 1; i > 0; i--)
    if (dem > 10 && ds.data[i] < 0) {
      cout << ds.data[i] << " ";
      if (dem2 == 9)
        break;
      dem2++;
    }
}

bool kiemTraToanSoNguyen(DaySoThuc ds) {
  for (int i = 0; i < ds.n; i++)
    if (ds.data[i] != (int)ds.data[i])
      return false;
  return true;
}

void docMaTran(Matrix& a) {
  FILE* f;
  f = fopen("a.txt", "r");
  if (f == NULL) {
    cout << "Loi mo file";
    exit(1);
  }
  fscanf(f, "%d", &a.n);
  for (int i = 0; i < a.n; i++)
    for (int j = 0; j < a.n; j++)
      fscanf(f, "%d", &a.data[i][j]);
  fclose(f);
}

void xuatMaTran(Matrix a) {
  for (int i = 0; i < a.n; i++) {
    for (int j = 0; j < a.n; j++)
      cout << a.data[i][j] << "\t";
    cout << endl;
  }
}

void inTamGiacDuoiBenTrai(Matrix a) {
  for (int i = 0; i < a.n; i++) {
    for (int j = 0; j < a.n; j++)
      if (i >= j)
        cout << a.data[i][j] << "\t";
    cout << endl;
  }
}

int tinhTongTamGiacDuoiBenTrai(Matrix a) {
  int tong = 0;
  for (int i = 0; i < a.n; i++)
    for (int j = 0; j < a.n; j++)
      if (i >= j)
        tong += a.data[i][j];
  return tong;
}

void hoanViDong(Matrix &m, int i, int j) {
  for (int u = 0; u < m.n; u++)
    swap(m.data[i][u], m.data[j][u]);
  cout << "\nMa tran sau khi hoan doi" << endl;
  xuatMaTran(m);
}
