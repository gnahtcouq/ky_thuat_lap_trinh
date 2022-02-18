/*
    bac 4
    i == j ._. -> duong cheo chinh

    i + j = bac - 1 ._. -> duong cheo phu

    i + j <= bac - 1 -> j <= bac - 1 - i

    duong cheo chinh chia ra lam 2 tam giac
    Tam giac duoi ben trai (kem duong cheo chinh)
    Tam giac tren ben phai (kem duong cheo chinh)

    Tam giac duoi ben phai (kem duong cheo phu) i + j >= bac - 1
    Tam giac tren ben trai (kem duong cheo phu) i + j <= bac - 1

*/

#include <iostream>
using namespace std;
const int MAX = 50;

struct MaTranVuong {
  int data[MAX][MAX];
  int bac;
};

void docMaTran(MaTranVuong& mtv);
void xuatMaTran(MaTranVuong mtv);
void inTamGiacTrenBenTrai(MaTranVuong mtv);
void inTamGiacDuoiBenPhai(MaTranVuong mtv);
void inTamGiacDuoiBenTrai(MaTranVuong mtv);
void inTamGiacTrenBenPhai(MaTranVuong mtv);

int main() {
  MaTranVuong mtv;
  docMaTran(mtv);
  xuatMaTran(mtv);

  cout << "\nTam giac tren ben trai" << endl;
  inTamGiacTrenBenTrai(mtv);

  cout << "\nTam giac duoi ben phai" << endl;
  inTamGiacDuoiBenPhai(mtv);

  cout << "\nTam giac duoi ben trai" << endl;
  inTamGiacDuoiBenTrai(mtv);

  cout << "\nTam giac tren ben phai" << endl;
  inTamGiacTrenBenPhai(mtv);

  cout << endl;
  system("pause");
  return 0;
}

void docMaTran(MaTranVuong& mtv) {
  FILE* f;
  f = fopen("mtv.txt", "r");
  if (f == NULL) {
    cout << "Loi mo file";
    exit(1);
  }
  fscanf(f, "%d", &mtv.bac);
  for (int i = 0; i < mtv.bac; i++)
    for (int j = 0; j < mtv.bac; j++)
      fscanf(f, "%d", &mtv.data[i][j]);
  fclose(f);
}

void xuatMaTran(MaTranVuong mtv) {
  cout << "\nMa tran vuong da nhap: " << endl;
  for (int i = 0; i < mtv.bac; i++) {
    for (int j = 0; j < mtv.bac; j++)
      cout << mtv.data[i][j] << "\t";
    cout << endl;
  }
}

void inTamGiacTrenBenTrai(MaTranVuong mtv) {
  for (int i = 0; i < mtv.bac; i++) {
    for (int j = 0; j < mtv.bac; j++)
      if (j <= mtv.bac - 1 - i)
        cout << mtv.data[i][j] << "\t";
    cout << endl;
  }
}

void inTamGiacDuoiBenPhai(MaTranVuong mtv) {
  for (int i = 0; i < mtv.bac; i++) {
    for (int j = 0; j < mtv.bac; j++)
      if (j >= mtv.bac - 1 - i)
        cout << mtv.data[i][j] << "\t";
      else
        cout << "\t";
    cout << endl;
  }
}

void inTamGiacDuoiBenTrai(MaTranVuong mtv) {
  for (int i = 0; i < mtv.bac; i++) {
    for (int j = 0; j < mtv.bac; j++)
      if (i >= j)
        cout << mtv.data[i][j] << "\t";
    cout << endl;
  }
}

void inTamGiacTrenBenPhai(MaTranVuong mtv) {
  for (int i = 0; i < mtv.bac; i++) {
    for (int j = 0; j < mtv.bac; j++)
      if (i <= j)
        cout << mtv.data[i][j] << "\t";
      else
        cout << "\t";
    cout << endl;
  }
}