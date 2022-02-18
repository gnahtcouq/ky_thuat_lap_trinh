#include <iostream>
#include <string.h>
#include <string>
using namespace std;

#define KTM 100
struct Matrix {
  int data[KTM][KTM];
  int n;
};
void docMaTran(Matrix& a);
void xuatMaTran(Matrix a);
void inTamGiacDuoiBenTrai(Matrix a);
int timMax_TamGiacDuoiBenTrai(Matrix a);
int tinhTongDong(Matrix a, int x);
int soSanhTongDong(Matrix a, int x, int y);


#define MAX 100
struct MangSo {
  int n;
  double data[MAX];
};
bool kiemTraMangTang(MangSo a);
void tachMangNguyenDuongChiaHetCho3(MangSo x, MangSo &y);


// substr(s, x, y); Cat chuoi con trong doan x, y cua chuoi s
string trichChuoiConTuChuoiMe(string s, int start, int end) {
  char ketqua[100];
	int idx = 0;
	for(int i = start; i <= end; i++)
		ketqua[idx++] = s[i];
	ketqua[idx] = '\0';
	return ketqua;
}

string trichChuoiConTuChuoiMe_2(string s, int pos, int num) {
  char ketqua[100];
	int idx = 0;
	for(int i = pos; i < pos + num; i++)
		ketqua[idx++] = s[i];
	ketqua[idx] = '\0';
	return ketqua;
}

int main() {

  string s = "CongNgheThongTin";
  int start = 8, end = 12;

  string s2 = trichChuoiConTuChuoiMe(s, start, end);
  cout << "\n\n\n\ns = " << s;
  cout << "\ns2 = " << s2;

  int pos = 8, num = 5;
  string s3 = trichChuoiConTuChuoiMe_2(s, pos, num);
  cout << "\n\n\n\ns = " << s;
  cout << "\ns3 = " << s3;



  // Matrix a;
  // docMaTran(a);
  // xuatMaTran(a);

  // cout << "\nTam giac duoi ben trai" << endl;
  // inTamGiacDuoiBenTrai(a);
  // cout << "\nMax = " << timMax_TamGiacDuoiBenTrai(a);

  // int x, y;
  // cout << "\nNhap dong x: ";
  // cin >> x;
  // cout << "\nNhap dong y: ";
  // cin >> y;
  // int ketqua = soSanhTongDong(a, x, y);
  // if (ketqua == 1)
  //   cout << "\nTong dong x > Tong dong y";
  // else
  //   cout << "\nTong dong x < Tong dong y";
  // if (ketqua == 0)
  //   cout << "\nTong dong x = Tong dong y";

  // Tong dong 3 = 123
  // Tong dong 4 = 29


  // MangSo a;
  // a.n = 5;
  // a.data[0] = 4;
  // a.data[1] = 2;
  // a.data[2] = 1;
  // a.data[3] = 5;
  // a.data[4] = 3;
  // int ketqua = kiemTraMangTang(a);
  // if (ketqua == false)
  //   cout << "\nMang khong tang";
  // else
  //   cout << "\nMang tang dan";

  // MangSo y;
  // tachMangNguyenDuongChiaHetCho3(a, y);

  cout << endl;
  system("pause");
  return 0;
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

int timMax_TamGiacDuoiBenTrai(Matrix a) {
  int max = a.data[0][0];
  for (int i = 0; i < a.n; i++) {
    for (int j = 0; j < a.n; j++)
      if (i >= j)
        if (a.data[i][j] > max)
          max = a.data[i][j];
  }
  return max;
}

int tinhTongDong(Matrix a, int x) {
  int tong = 0;
  for (int j = 0; j < a.n; j++) {
    tong += a.data[x][j];
  }
  return tong;
}

int soSanhTongDong(Matrix a, int x, int y) {
  if (tinhTongDong(a, x) > tinhTongDong(a, y))
    return 1;
  else
    return -1;
  return 0;
}

bool kiemTraMangTang(MangSo a) {
  for (int i = 0; i < a.n - 1; i++) {
    if (a.data[i] > a.data[i + 1])
      return false;
  }
  return true;
}

void tachMangNguyenDuongChiaHetCho3(MangSo x, MangSo &y) {
  int ny = 0;
  for (int i = 0; i < x.n; i++) {
    if ((int)x.data[i] % 3 == 0) {
      y.data[ny] = x.data[i];
      ny++;
    }
  }
  cout << "\nMang y: ";
  for (int i = 0; i < ny; i++)
    cout << y.data[i] << " ";
}

