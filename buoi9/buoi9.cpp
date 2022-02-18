#include <iostream>
#include <math.h>
using namespace std;

int tong(int a[], int n) {
  if (n == 1)
    return a[0];
  return tong(a, n - 1) + a[n - 1];
}

float tinhBieuThuc4(int n) {
  if (n == 1)
    return 1;
  // if (n%2 == 0)
  //   return tinhBieuThuc4(n - 1) - 1.0 / n;
  // else
  //   return tinhBieuThuc4(n - 1) + 1.0 / n;

  // C2
  return tinhBieuThuc4(n - 1) * pow(-1, n + 1) / n;
}

int tinhBieuThuc5(int n, int k) {
  if (k == 0 || k == n)
    return 1;
  if (k > n)
    return 0;
  if (k == 1)
    return n;
  return tinhBieuThuc5(n - 1, k) + tinhBieuThuc5(n - 1, k - 1);
}

void thapPhanSangNhiPhan(int a) {
  if (a == 0 || a == 1)
    cout << a;
  else {
    thapPhanSangNhiPhan(a / 2);
    cout << a % 2;
  }
}

void inTamGiacPascal(int n) {
  if (n == 0) {
    cout << "1" << endl;
    return;
  }
  inTamGiacPascal(n - 1);
  for (int i = 0; i <= n; i++)
    cout << tinhBieuThuc5(n, i) << " ";
  cout << endl;
}


int main() {
  // int a[] = { 1, 2, 3, 4, 5 };
  // cout << tong(a, 5);
  inTamGiacPascal(4);

  system("pause");
  return 0;
}