#include <iostream>
#include <math.h>
using namespace std;
struct MangNguyen {
  int n;
  int data[50];
};

void nhapDaySo(MangNguyen& ds);
void xuatDaySo(MangNguyen ds);
bool KiemTraChinhPhuong(int x);
void xuatChinhPhuong(MangNguyen ds);
int timSoChinhPhuongLonNhat(MangNguyen ds);

const int MAX = 100;
struct Matrix {
  int n;
  int data[MAX][MAX];
};

void docMaTran(Matrix& a);
void xuatMaTran(Matrix a);
void inTamGiacTrenBenPhai(Matrix a);
void xuatCacSoLaBoiCuaNTamGiacTrenBenPhai(Matrix a, int n);
int tongBoiN(Matrix a, int n);
MangNguyen timSoChan(Matrix a);


void nhapMang(int* a, int n);
void xuatMang(int* a, int n);
void xuatViTriChan(int* a, int n);

int main() {
  // MangNguyen ds;
  // int n;
  // cout << "\nNhap n can kiem tra la so chinh phuong: ";
  // cin >> n;
  // bool check = KiemTraChinhPhuong(n);
  // if (check)
  //   cout << n << " la so chinh phuong";
  // else
  //   cout << n << " khong phai la so chinh phuong";

  // nhapDaySo(ds);
  // xuatDaySo(ds);

  // cout << "\nCac so chinh phuong co trong mang nguyen la: ";
  // xuatChinhPhuong(ds);


  // int result = timSoChinhPhuongLonNhat(ds);
  // if (result == -1)
  //   cout << "\nKhong co so chinh phuong lon nhat";
  // else
  //   cout << "\nSo chinh phuong lon nhat = " << result;





  // MangNguyen ds;
  // Matrix a;
  // docMaTran(a);
  // xuatMaTran(a);
  // cout << "\nTam giac tren ban phai: " << endl;
  // inTamGiacTrenBenPhai(a);

  // int n;
  // cout << "\nNhap n = ";
  // cin >> n;
  // cout << "\nCac so la boi cua " << n << " trong tam giac tren ben phai: ";
  // xuatCacSoLaBoiCuaNTamGiacTrenBenPhai(a, n);
  // int tong = tongBoiN(a, n);
  // cout << "\nTong cac so la boi cua " << n << " trong tam giac tren ben phai = " << tong;

  // timSoChan(a);


  int n;
  cout << "\nNhap so luong phan tu = ";
  cin >> n;
  int* a = new int[n]; // cap phat bo nho cho con tro
  nhapMang(a, n);
  xuatMang(a, n);
  cout << "\nCac phan tu o vi tri chan: ";
  xuatViTriChan(a, n);

  system("pause");
  return 0;
}

void nhapDaySo(MangNguyen& ds) {
  do {
    cout << "\nNhap so luong phan tu: ";
    cin >> ds.n;
    if (ds.n < 1 || ds.n > 50)
      cout << "\nNhap sai. Hay nhap lai";
  } while (ds.n < 1 || ds.n > 50);

  for (int i = 0; i < ds.n; i++) {
    cout << "\nNhap phan tu thu " << i + 1 << " = ";
    cin >> ds.data[i];
  }
}

void xuatDaySo(MangNguyen ds) {
  for (int i = 0; i < ds.n; i++)
    cout << ds.data[i] << " ";
}

bool KiemTraChinhPhuong(int x) {
  return sqrt((float)x) == (int)sqrt((float)x);
}

void xuatChinhPhuong(MangNguyen ds) {
  for (int i = 0; i < ds.n; i++)
    if (KiemTraChinhPhuong(ds.data[i]))
      cout << ds.data[i] << " ";
}

int timSoChinhPhuongLonNhat(MangNguyen ds) {
  int soChinhPhuongDauTien;
  for (int i = 0; i < ds.n; i++) {
    if (KiemTraChinhPhuong(ds.data[i]))
      soChinhPhuongDauTien = ds.data[i];
    else
      return -1;
  }
  int soChinhPhuongLonNhat = soChinhPhuongDauTien;
  for (int i = 0; i < ds.n; i++)
    if (KiemTraChinhPhuong(ds.data[i]))
      if (ds.data[i] > soChinhPhuongLonNhat)
        soChinhPhuongLonNhat = ds.data[i];
  return soChinhPhuongLonNhat;
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

void inTamGiacTrenBenPhai(Matrix a) {
  for (int i = 0; i < a.n; i++) {
    for (int j = 0; j < a.n; j++)
      if (i <= j)
        cout << a.data[i][j] << "\t";
      else
        cout << "\t";
    cout << endl;
  }
}

void xuatCacSoLaBoiCuaNTamGiacTrenBenPhai(Matrix a, int n) {
  for (int i = 0; i < a.n; i++)
    for (int j = 0; j < a.n; j++)
      if (i <= j && a.data[i][j] % n == 0)
        cout << a.data[i][j] << " ";
}

int tongBoiN(Matrix a, int n) {
  int tong = 0;
  for (int i = 0; i < a.n; i++)
    for (int j = 0; j < a.n; j++)
      if (i <= j && a.data[i][j] % n == 0)
        tong += a.data[i][j];
  return tong;
}

MangNguyen timSoChan(Matrix a) {
  MangNguyen ds;
  int m = 0;
  ds.n = 0;
  for (int i = 0; i < a.n; i++)
    for (int j = 0; j < a.n; j++)
      if (a.data[i][j] % 2 == 0) {
        ds.n++;
        ds.data[m++] = a.data[i][j];
      }
  cout << "\nSo luong cac so chan = " << ds.n << endl;
  cout << "Mang chua cac so chan: ";
  xuatDaySo(ds);
  return ds;
}

void nhapMang(int* a, int n) {
  for (int i = 0; i < n; i++) {
    cout << "\nNhap vao a[" << i << "]= ";
    cin >> a[i];
  }
}
void xuatMang(int* a, int n) {
  for (int i = 0; i < n; i++)
    cout << a[i] << " ";
}

void xuatViTriChan(int* a, int n) {
  for (int i = 0; i < n; i++)
    if (i % 2 == 0)
      cout << a[i] << " ";
}