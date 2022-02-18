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
struct MaTranVuong
{
    int data[MAX][MAX];
    int bac;
};
struct DaySo
{
    int data[MAX];
    int soLuong;
};
void docMaTran(MaTranVuong &mtv);
void xuatMaTran(MaTranVuong mtv);
void inTamGiacTrenBenTrai(MaTranVuong mtv);
void inTamGiacDuoiBenPhai(MaTranVuong mtv);

bool ghiDaySo(char *tenFile, DaySo ds);
bool docDaySo(char *tenFile, DaySo &ds);
void nhapDS(DaySo &ds);
void xuatDS(DaySo ds);
bool themDaySo(DaySo &ds, int x, int vitrithem);
bool themDau(DaySo &ds, int x);
bool themCuoi(DaySo &ds, int x);
void sapXepTangDan(DaySo &ds);
int tim(DaySo ds, int x);
void tachAmDuong(DaySo ds, DaySo &dsAm, DaySo &dsDuong);
DaySo gop(DaySo ds1, DaySo ds2);

int main()
{
    // MaTranVuong mtv;
    // docMaTran(mtv);
    // xuatMaTran(mtv);

    // cout << "\nTam giac tren ben trai" << endl;
    // inTamGiacTrenBenTrai(mtv);

    // cout << "\nTam giac duoi ben phai" << endl;
    // inTamGiacDuoiBenPhai(mtv);

    int x, vitrithem;
    DaySo ds1;
    if (docDaySo("data.txt", ds1))
    {
        cout << "\nDay so: ";
        xuatDS(ds1);
        cout << "\nMuon them so nao? ";
        cin >> x;
        cout << "\nThem vao vi tri nao? ";
        cin >> vitrithem;
        themDaySo(ds1, x, vitrithem);
        cout << "\nDay so sau khi them: ";
        xuatDS(ds1);
        themCuoi(ds1, 100);
        cout << "\nDay so sau khi them cuoi: ";
        xuatDS(ds1);

        sapXepTangDan(ds1);
        cout << "\nDay so sau khi sap xep tang dan: ";
        xuatDS(ds1);

    }

    cout << endl;
    system("pause");
    return 0;
}

void docMaTran(MaTranVuong &mtv)
{
    FILE *f;
    f = fopen("mtv.txt", "r");
    if (f == NULL)
    {
        cout << "Loi mo file";
        exit(1);
    }
    fscanf(f, "%d", &mtv.bac);
    for (int i = 0; i < mtv.bac; i++)
        for (int j = 0; j < mtv.bac; j++)
            fscanf(f, "%d", &mtv.data[i][j]);
    fclose(f);
}

void xuatMaTran(MaTranVuong mtv)
{
    cout << "\nMa tran vuong da nhap: " << endl;
    for (int i = 0; i < mtv.bac; i++)
    {
        for (int j = 0; j < mtv.bac; j++)
            cout << mtv.data[i][j] << "\t";
        cout << endl;
    }
}

void inTamGiacTrenBenTrai(MaTranVuong mtv)
{
    for (int i = 0; i < mtv.bac; i++)
    {
        for (int j = 0; j <= mtv.bac - 1 - i; j++)
            cout << mtv.data[i][j] << "\t";
        cout << endl;
    }
}

void inTamGiacDuoiBenPhai(MaTranVuong mtv)
{
    for (int i = 0; i < mtv.bac; i++)
    {
        for (int j = 0; j < mtv.bac; j++)
            if (j >= mtv.bac - 1 - i)
                cout << mtv.data[i][j] << "\t";
            else
                cout << "\t";
        cout << endl;
    }
}

bool ghiDaySo(char *tenFile, DaySo ds)
{
    FILE *f;
    fopen_s(&f, tenFile, "w");
    if (f == NULL)
    {
        cout << "Khong mo duoc file";
        return false;
    }
    else
    {
        fprintf_s(f, "%d\n", ds.soLuong);
        for (int i = 0; i < ds.soLuong; i++)
            fprintf_s(f, "%d ", ds.data[i]);
        fclose(f);
        return true;
    }
}
bool docDaySo(char *tenFile, DaySo &ds)
{
    FILE *f;
    fopen_s(&f, tenFile, "r");
    if (f == NULL)
    {
        cout << "Khong mo duoc file";
        return false;
    }
    else
    {
        fscanf(f, "%d", &ds.soLuong);
        for (int i = 0; i < ds.soLuong; i++)
        {
            fscanf(f, "%d", &ds.data[i]);
        }
        fclose(f);
        return true;
    }
}

void nhapDS(DaySo &ds)
{
    cout << "\nNhap so phan tu: ";
    cin >> ds.soLuong;
    for (int i = 0; i < ds.soLuong; i++)
    {
        cout << "a[" << i << "] = ";
        cin >> ds.data[i];
    }
}

void xuatDS(DaySo ds)
{
    for (int i = 0; i < ds.soLuong; i++)
        cout << ds.data[i] << " ";
}

bool themDaySo(DaySo &ds, int x, int vitrithem)
{
    if (vitrithem < 0 || vitrithem > ds.soLuong || ds.soLuong == MAX)
        return false; // Khong them duoc

    for (int i = ds.soLuong; i >= vitrithem; i--)
    {
        ds.data[i + 1] = ds.data[i];
    }
    ds.data[vitrithem] = x;
    ds.soLuong++;
    return true;
}

bool themDau(DaySo &ds, int x)
{
    return themDaySo(ds, x, 0);
}

bool themCuoi(DaySo &ds, int x)
{
    return themDaySo(ds, x, ds.soLuong);
}

void sapXepTangDan(DaySo &ds){
	int t;
	for (int i = 0; i < ds.soLuong-1; i++) {
		t = i+1;
		for (int j = i + 2; j < ds.soLuong; j++) {
			if (ds.data[j] < ds.data[t]) {
				t = j;
				
			}
		}
		if (ds.data[t] < ds.data[i])
			swap(ds.data[t], ds.data[i]);
	}
}

int tim(DaySo ds, int x)// tra ve vi tri dau tien ma tim thay x. Neu ko tim thay => -1
{
	for (int i = 0; i < ds.soLuong; i++)
	{
		if (ds.data[i] == x)
			return i;
	}
	return -1;
}
void tachAmDuong(DaySo ds, DaySo &dsAm, DaySo &dsDuong)
{
	dsDuong.soLuong = 0;
	dsAm.soLuong = 0;
	for (int i = 0; i < ds.soLuong; i++)
	{
		if (ds.data[i] > 0)
			dsDuong.data[dsDuong.soLuong++] = ds.data[i];
		else if (ds.data[i] < 0)
			dsAm.data[dsAm.soLuong++] = ds.data[i];
	}
}
DaySo gop(DaySo ds1, DaySo ds2)
{
	DaySo ds;
	ds = ds1;
	ds.soLuong = ds1.soLuong + ds2.soLuong;

	for (int i = 0; i<ds2.soLuong; i++)
	{
		ds.data[ds1.soLuong + i] = ds2.data[i];
	}
	return ds;
}
