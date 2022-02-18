#include <iostream>
using namespace std;
const int MAX = 100;

struct SinhVien {
  char ma[11];
  char* hoTen;
  //void nhap();
  //void xuat();
};
//void SinhVien::nhap()
//{
//	cout << "Nhap ma: ";
//	cin >> ma;
//	cin.ignore();
//	hoTen = new char[50];
//	cout << "Nhap ho ten: ";
//	cin.getline(hoTen, 50);
//}
//void SinhVien::xuat()
//{
//	cout << ma << "\t| " << hoTen << endl;
//}
void nhapSinhVien(SinhVien& sv) {
  cout << "Nhap ma: ";
  cin >> sv.ma;
  cin.ignore();
  sv.hoTen = new char[50];
  cout << "Nhap ho ten: ";
  cin.getline(sv.hoTen, 50);
}
void xuatSinhVien(SinhVien sv) {
  cout << sv.ma << "\t| " << sv.hoTen << endl;
}
struct Lop {
  SinhVien ds[110];
  int soLuong;
};
struct LopDong {
  SinhVien* ds;
  int soLuong;
};
//struct DaySo
//{
//	int *arr;
//	int soLuong;
//};
//void nhapDaySo(DaySo &ds)
//{
//	do {
//		cout << "Co may ptu trong day so? ";
//		cin >> ds.soLuong;
//	} while (ds.soLuong <= 0);
//	ds.arr = new int[ds.soLuong];
//	for (int i = 0; i < ds.soLuong; i++)
//	{
//		cout << "NHap 1 so nguyen: ";
//		cin >> ds.arr[i];
//	}
//}
//void xuatDaySo(DaySo ds)
//{
//	cout << "-------------DAY SO-------------" << endl;
//	for (int i = 0; i < ds.soLuong; i++)
//	{
//		cout << ds.arr[i]<<" ";
//	}
//	cout << endl;
//}
//int timMax(DaySo ds)
//{
//	int max = ds.arr[0];
//	for (int i = 1; i < ds.soLuong; i++)
//		if (ds.arr[i] > max)
//			max = ds.arr[i];
//	return max;
//}
//
//int viTriDuongDauTien(DaySo ds) {
//	for (int i = 0; i < ds.soLuong; i++)
//		if (ds.arr[i] > 0)
//			return i;
//}
//int timViTriMin(DaySo ds)
//{
//	int vitri=0;
//	for (int i = 1; i < ds.soLuong; i++)
//		if (ds.arr[i] < ds.arr[vitri])
//			vitri = i;
//	return vitri;
//}
bool kiemTraSHT(int x) {
  int  tong = 1;
  for (int i = 2; i <= x / 2; i++)
    if (x % i == 0)
      tong = tong + i;

  if (tong == x)
    return true;
  return false;
}
//
//int tongPTSHT(DaySo ds)
//{
//	int tong = 0;
//	for (int i = 0; i<ds.soLuong; i++)
//	{
//		if (kiemTraSHT(ds.arr[i]) == true)
//			tong += ds.arr[i];
//	}
//	return tong;
//}
//


char* layTen(char* s) {
  char* ten;
  int n = strlen(s) - 1;
  int i = n;
  while (s[i] != ' ' && i >= 0) i--;
  if (i == -1) {
    ten = s;
    return NULL;
  }
  int lenten = n - i;
  ten = new char[lenten + 1];
  for (int x = 0; x < lenten; x++) {
    ten[x] = s[i + x + 1];
  }
  ten[lenten] = '\0';
  return ten;
}


void lietKeSVCoTen(LopDong lop, char* ten) {
  for (int i = 0; i < lop.soLuong; i++) {
    if (strcmp(layTen(lop.ds[i].hoTen), ten) == 0)
      xuatSinhVien(lop.ds[i]);
  }
}

void test(int a[]) {
  for (int i = 0; a[i] = (-1 && i < 10); i++) {
    cout << a[i] << " ";
  }
}

long long bieuThuc1(int n) {
  long long s = 0;
  for (int i = 1; i < n; i++)
    s += i * i;
  return s;
}

float bieuThuc2(int n) {
  float s = 0;
  for (int i = 1; i <= n; i++)
    s += pow(-1, i + 1) / i;
  return s;
}

float bieuThuc2B(int n) {
  float s = 0;
  for (int i = 1; i <= n; i++)
    if (i % 2 == 0)
      s -= 1.0 / i;
    else
      s += 1.0 / i;
  return s;
}

float bieuThuc2c(int n) {
  float s = 0;
  float dau = 1.0;
  for (int i = 1; i <= n; i++) {
    s += dau / i;
    dau = -dau;
  }
  return s;
}
float bieuThuc2d(int n) {
  float s = 0;
  for (int i = 1; i <= n; i += 2)
    s += 1.0 / i;
  for (int i = 2; i <= n; i += 2)
    s -= 1.0 / i;
  return s;
}

struct DaySo {
  int data[MAX];
  int soLuong;

};


int demSoDuong(DaySo ds) {
  int dem = 0;
  for (int i = 0; i < ds.soLuong; i++) {
    if (ds.data[i] > 0)
      dem++;
  }
  return dem;
}

DaySo demSoDuong2(DaySo ds) {
  DaySo tam;
  tam.soLuong = 0;
  for (int i = 0; i < ds.soLuong; i++) {
    if (ds.data[i] > 0)
      tam.data[tam.soLuong++] = ds.data[i];
  }
  return tam;
}

bool duongLonNhat(DaySo ds, int& max) {
  bool flag = false;
  for (int i = 0; i < ds.soLuong; i++) {
    if (ds.data[i] > 0) {
      if (!flag) {
        max = ds.data[i];
        flag = true;
      }
      else {
        if (max < ds.data[i])
          max = ds.data[i];
      }
    }
  }
  return flag;
}
int timViTriMax(DaySo ds) {
  int vt = -1;//ko co so duong nao
  for (int i = 0; i < ds.soLuong; i++) {
    if (ds.data[i] > 0) {
      if (vt == -1) {
        vt = i;
      }
      else if (ds.data[i] > ds.data[vt]) {
        vt = i;
      }
    }
  }
  return vt;
}
bool kiemTraCoSoHoanThien(DaySo ds) {
  for (int i = 0; i < ds.soLuong; i++) {
    if (kiemTraSHT(ds.data[i]))
      return true;
  }
  return false;
}

bool kiemTraNhoHonMin(DaySo ds, int a) {
  int min = ds.data[0];
  for (int i = 1; i < ds.soLuong; i++) {
    if (ds.data[i] < ds.data[min])
      min = ds.data[i];
  }
  if (a < min)
    return true;
  else
    return false;
}

bool kiemTraLonHonMax(DaySo ds, int a) {
  int max = ds.data[0];
  for (int i = 1; i < ds.soLuong; i++) {
    if (ds.data[i] > ds.data[max])
      max = ds.data[i];
  }
  if (a > max)
    return true;
  else
    return false;
}
bool kiemTraDoiXung(DaySo ds) {
  for (int i = 0; i < ds.soLuong / 2; i++)
    if (ds.data[i] != ds.data[ds.soLuong - 1 - i])
      return false;
  return true;
}
bool kiemTraAmLe(DaySo ds) {
  for (int i = 0; i < ds.soLuong; i++) {
    if (ds.data[i] < 0 && ds.data[i] % 2 != 0)
      return true;
  }
  return false;
}


bool kiemTraTang(DaySo ds) {
  for (int i = 0; i < ds.soLuong - 1; i++) {
    if (ds.data[i] >= ds.data[i + 1])
      return false;
  }
  return true;
}

//bool kiemTraTang(DaySo ds)
//{
//	for (int i = 0; i < ds.soLuong ; i++)
//	{
//		if (!kiemTraSHT(ds.data[i]))
//			return false;
//	}
//	return true;
//}
bool kiemTraNguyenTo(int n) {
  if (n < 2)
    return false;
  for (int i = 2; i <= sqrt(n); i++)
    if (n % i == 0)
      return false;
  return true;
}
struct MaTranVuong {
  int data[MAX][MAX];
  int bac;// so dong = so cot
};

bool kiemTraNguyenTo(MaTranVuong mt) {
  for (int i = 0; i < mt.bac; i++) {
    for (int j = 0; j < mt.bac; j++) {
      if (kiemTraNguyenTo(mt.data[i][j]))
        return true;
    }

  }
  return false;
}
bool kiemTraDonVi(MaTranVuong mt) {
  for (int i = 0; i < mt.bac; i++) {
    for (int j = 0; j < mt.bac; j++) {
      if (i == j) {
        if (mt.data[i][j] != 1)
          return false;
      }
      else if (mt.data[i][j] != 0)
        return false;
    }
  }
  return true;
}
bool kiemTraDoiXung(MaTranVuong mt) {
  for (int i = 0; i < mt.bac; i++) {
    for (int j = 0; j < i; j++) {
      if (mt.data[i][j] != mt.data[j][i])
        return false;
    }
  }
  return true;
}
bool kiemTraPTCucTieu(DaySo ds) {
  if (ds.soLuong <= 0)
    return false;
  if (ds.soLuong == 1)
    return false;
  if (ds.data[0] < ds.data[1])
    return true;
  if (ds.data[ds.soLuong - 1] < ds.data[ds.soLuong - 2])
    return true;
  for (int i = 1; i < ds.soLuong - 1; i++) {
    if (ds.data[i - 1] > ds.data[i] && ds.data[i] < ds.data[i + 1])
      return true;
  }
  return false;
}
bool ghiDaySo(char* tenFile, DaySo ds) {
  FILE* f;
  fopen_s(&f, tenFile, "w");
  if (f == NULL) {
    cout << "Khong mo duoc file";
    return false;
  }
  else {
    fprintf_s(f, "%d\n", ds.soLuong);
    for (int i = 0; i < ds.soLuong; i++)
      fprintf_s(f, "%d ", ds.data[i]);
    fclose(f);
    return true;
  }
}
bool docDaySo(char* tenFile, DaySo& ds) {
  FILE* f;
  fopen_s(&f, tenFile, "r");
  if (f == NULL) {
    cout << "Khong mo duoc file";
    return false;
  }
  else {
    fscanf_s(f, "%d", &ds.soLuong);
    for (int i = 0; i < ds.soLuong; i++) {
      fscanf_s(f, "%d", &ds.data[i]);
    }
    fclose(f);
    return true;
  }
}

bool ghiMaTranVuong(char* tenFile, MaTranVuong mtv) {
  FILE* f;
  fopen_s(&f, tenFile, "w");
  if (f == NULL) {
    cout << "Khong mo duoc file";
    return false;
  }
  else {
    fprintf_s(f, "%d\n", mtv.bac);
    for (int i = 0; i < mtv.bac; i++) {
      for (int j = 0; j < mtv.bac; j++)
        fprintf_s(f, "%d ", mtv.data[i][j]);
      fprintf_s(f, "\n");
    }
    fclose(f);
    return true;
  }
}

bool docMaTranVuong(char* tenFile, MaTranVuong& mtv) {
  FILE* f;
  fopen_s(&f, tenFile, "r");
  if (f == NULL) {
    cout << "Khong mo duoc file";
    return false;
  }
  else {
    fscanf_s(f, "%d", &mtv.bac);
    for (int i = 0; i < mtv.bac; i++) {
      for (int j = 0; j < mtv.bac; j++)
        fscanf_s(f, "%d", &mtv.data[i][j]);
    }
    fclose(f);
    return true;
  }
}


void xuatMaTranVuong(MaTranVuong mtv) {
  for (int i = 0; i < mtv.bac; i++) {
    for (int j = 0; j < mtv.bac; j++)
      cout << mtv.data[i][j] << " ";
    cout << endl;
  }
}
void inTamGiacTrenBenTrai(MaTranVuong mtv) {
  for (int i = 0; i < mtv.bac; i++) {
    for (int j = 0; j <= mtv.bac - 1 - i; j++)
      cout << mtv.data[i][j] << " ";
    cout << endl;
  }
}
void inTamGiacDuoiPhai(MaTranVuong mtv) {
  for (int i = 0; i < mtv.bac; i++) {
    for (int j = 0; j < mtv.bac; j++)
      if (j < mtv.bac - 1 - i)
        cout << "\t";
      else
        cout << mtv.data[i][j] << "\t";
    cout << endl;
  }

}
bool themDaySo(DaySo& ds, int x, int viTri) {
  if (viTri < 0 || viTri>ds.soLuong || ds.soLuong == MAX)
    return false;
  for (int i = ds.soLuong; i >= viTri; i--)
    ds.data[i + 1] = ds.data[i];
  ds.data[viTri] = x;
  ds.soLuong++;
  return true;
}
bool themDau(DaySo& ds, int x) {
  return themDaySo(ds, x, 0);
}
bool themCuoi(DaySo& ds, int x) {
  return themDaySo(ds, x, ds.soLuong);
}
void xuatDaySo(DaySo ds) {
  for (int i = 0; i < ds.soLuong; i++)
    cout << ds.data[i] << " ";
  cout << endl;
}


void sapTang(DaySo& ds) {
  for (int i = 0; i < ds.soLuong - 1; i++) {
    for (int j = i + 1; j < ds.soLuong; j++) {
      if (ds.data[i] > ds.data[j])
        swap(ds.data[i], ds.data[j]);
    }
  }
}

void tangDan(DaySo& ds) {
  int t;
  for (int i = 0; i < ds.soLuong - 1; i++) {
    t = i + 1;
    for (int j = i + 2; j < ds.soLuong; j++) {
      if (ds.data[j] < ds.data[t]) {
        t = j;

      }
    }
    if (ds.data[t] < ds.data[i])
      swap(ds.data[t], ds.data[i]);
  }
}
//void sapTang(DaySo& ds) {
//	int j, temp;
//	for (int i = 0; i < ds.soLuong; i++) {
//		j = i - 1;
//		temp = ds.data[i];
//		while (j >= 0 && ds.data[j] > ds.data[i]) {
//			ds.data[j + 1] = ds.data[j];
//			j--;
//		}
//		ds.data[j + 1] = temp;
//	}
//}
int tim(DaySo ds, int x)// tra ve vi tri dau tien ma tim thay x. Neu ko tim thay => -1
{
  for (int i = 0; i < ds.soLuong; i++) {
    if (ds.data[i] == x)
      return i;
  }
  return -1;
}
void tachAmDuong(DaySo ds, DaySo& dsAm, DaySo& dsDuong) {
  dsDuong.soLuong = 0;
  dsAm.soLuong = 0;
  for (int i = 0; i < ds.soLuong; i++) {
    if (ds.data[i] > 0)
      dsDuong.data[dsDuong.soLuong++] = ds.data[i];
    else if (ds.data[i] < 0)
      dsAm.data[dsAm.soLuong++] = ds.data[i];
  }
}
DaySo gop(DaySo ds1, DaySo ds2) {
  DaySo ds;
  ds = ds1;
  ds.soLuong = ds1.soLuong + ds2.soLuong;

  for (int i = 0; i < ds2.soLuong; i++) {
    ds.data[ds1.soLuong + i] = ds2.data[i];
  }
  return ds;
}
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
  cout << "Nhap ten nv: ";
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
    cout << "Nhap so NV: ";
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

bool ghiDanhDachNhanVien(DanhSachNhanVien ds, char* tenFile) {
  FILE* f;
  fopen_s(&f, tenFile, "wb");
  if (f == NULL)
    return false;
  fwrite(&ds.soLuong, sizeof(int), 1, f);
  fwrite(&ds.ds, sizeof(NhanVien), ds.soLuong, f);
  fclose(f);
  return true;
}

bool docDanhDachNhanVien(DanhSachNhanVien& ds, char* tenFile) {
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
DanhSachNhanVien dsNhanVienHeSoHon3(DanhSachNhanVien dsnv) {
  DanhSachNhanVien kq;
  kq.soLuong = 0;
  for (int i = 0; i < dsnv.soLuong; i++) {
    if (dsnv.ds[i].heSoLuong > 3)
      kq.ds[kq.soLuong++] = dsnv.ds[i];
  }
  return kq;
}

int soNhanVienXuatSac(DanhSachNhanVien dsnv, float luongCB) {
  int dem = 0;
  for (int i = 0; i < dsnv.soLuong; i++) {
    if (dsnv.ds[i].heSoLuong * luongCB / 24 >= 150000)
      dem++;
  }
  return dem;
}
bool ghiDanhSachNhanVienHeSoTren3(DanhSachNhanVien ds, char* tenFile) {
  FILE* f;
  fopen_s(&f, tenFile, "wb");
  if (f == NULL)
    return false;
  DanhSachNhanVien dshs3 = dsNhanVienHeSoHon3(ds);
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
int main1() {
  DanhSachNhanVien ds1;
  NhanVien nv1;
  int soNVXS, soNV3;
  //nhapDanhSachNhanVien(ds1);
  if (docDanhDachNhanVien(ds1, "nvien_2.dat"))
    //if (docDanhSachNhanVien2(ds1, "nhanvien2.dat",soNVXS,soNV3))
  {
    //cout << "Doc thanh cong";
    cout << "\n Thong tin cua cac nv vua doc la: " << endl;
    xuatDanhSachNhanVien(ds1);
    /*char tenNv[50];
    cout << "Cho biet ten nv can cap nhat: ";
    cin.getline(tenNv, 50);
    capNhat(ds1,tenNv);
    if (ghiDanhDachNhanVien(ds1, "nhanvien.dat"))
      cout << "Da ghi thanh cong";
    else
      cout << "Ghi file khong duoc";*/
      /*cout << "Nhap thong nv can them: ";
      nhapNhanVien(nv1);
      if (them(ds1, nv1))
      {
        if (ghiDanhDachNhanVien(ds1, "nhanvien.dat"))
          cout << "Da ghi thanh cong";
        else
          cout << "Ghi file khong duoc";
      }
      else
        cout << "Danh sach da day";*/
        //DanhSachNhanVien dscnLuongCao = dsCongNhanLuongCao1(ds1);
        ////xuatDanhSachNhanVien(dscnLuongCao);
        //ghiDanhDachNhanVien(dscnLuongCao,"nvien_2.dat");
  }
  else {
    cout << "Doc khong duoc"; exit;
  }

  /*if (ghiDanhDachNhanVien2(ds1, "nhanvien2.dat"))
    cout << "Da luu thanh cong";
  else
    cout << "Luu khong duoc";*/

    //MaTranVuong mtv1;
    //if (docMaTranVuong("mtv.txt", mtv1) == NULL)
    //	cout << "Doc file khong duoc";
    //else
    //	//Xuat matranvuong
    //{
    //	xuatMaTranVuong(mtv1);
    //	cout << endl << "Tam giac tren trai: " << endl;
    //	inTamGiacDuoiPhai(mtv1);
    //	//int k, p;
    //	//cout << "\nMuon hoan doi 2 dong nao? ";
    //	//cin >> k >> p;
    //	//if (k < 0 || k >= mtv1.bac || p < 0 || p >= mtv1.bac)
    //	//	cout << "GIa tri 2 dong khong hop le.";
    //	//else
    //	//{
    //	//	for (int j = 0; j < mtv1.bac; j++)
    //	//		swap(mtv1.data[k][j], mtv1.data[p][j]);
    //	//	//Xuat 
    //	//	cout << endl << "Ma tran sau khi hoan doi:" << endl;
    //	//	xuatMaTranVuong(mtv1);
    //	//	if (ghiMaTranVuong("mtv.txt", mtv1))
    //	//		cout << "Da luu";
    //	//	else
    //	//		cout << "Luu khong thanh cong";
    //	//}
    //}
  cout << endl;
  system("pause");
  return 0;
}