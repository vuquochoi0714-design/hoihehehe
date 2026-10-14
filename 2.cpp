#include <iostream>
#include <fstream>
#include <string>
using namespace std;
const int MAX = 1000;
struct SinhVien{
    string maSV;
    string hoTen;
    float gpa;
    int tinChi;
    int kyLuat;
};
SinhVien ds[MAX];
SinhVien hopLe[MAX];
SinhVien biLoai[MAX];
int n = 0;
int slHopLe = 0;
int slBiLoai = 0;
bool duDieuKien(SinhVien sv){
    return sv.gpa >= 3.2 &&
           sv.tinChi >= 24 &&
           sv.kyLuat == 0;
}
void tachDanhSach(){
    slHopLe = 0;
    slBiLoai = 0;
    for(int i = 0; i < n; i++){
        if(duDieuKien(ds[i]))
            hopLe[slHopLe++] = ds[i];
        else
            biLoai[slBiLoai++] = ds[i];
    }
}
bool xepTruoc(SinhVien a, SinhVien b){
    if(a.gpa > b.gpa) return true;
    if(a.gpa < b.gpa) return false;
    if(a.tinChi > b.tinChi) return true;
    if(a.tinChi < b.tinChi) return false;
    return a.maSV < b.maSV;
}
void insertionSort(){
    for(int i = 1; i < slHopLe; i++){
        SinhVien key = hopLe[i];
        int j = i - 1;
        while(j >= 0 && !xepTruoc(hopLe[j], key)){
            hopLe[j + 1] = hopLe[j];
            j--;
        }
        hopLe[j + 1] = key;
    }
}
void selectionSort(){
    for(int i = 0; i < slHopLe - 1; i++){
        int max = i;
        for(int j = i + 1; j < slHopLe; j++){
            if(xepTruoc(hopLe[j], hopLe[max]))
                max = j;
        }
        SinhVien temp = hopLe[i];
        hopLe[i] = hopLe[max];
        hopLe[max] = temp;
    }
}
void bubbleSort(){
    for(int i = 0; i < slHopLe - 1; i++){
        for(int j = 0; j < slHopLe - i - 1; j++){
            if(!xepTruoc(hopLe[j], hopLe[j + 1])){
                SinhVien temp = hopLe[j];
                hopLe[j] = hopLe[j + 1];
                hopLe[j + 1] = temp;
            }
        }
    }
}
void hienThi(SinhVien a[], int soLuong){
    for(int i = 0; i < soLuong; i++){
        cout << a[i].maSV << " ";
        cout << a[i].hoTen << " ";
        cout << a[i].gpa << " ";
        cout << a[i].tinChi << " ";
        cout << a[i].kyLuat << endl;
    }
}
void topK(){
    int k;
    cout << "Nhap K: ";
    cin >> k;
    if(k > slHopLe)
        k = slHopLe;
    for(int i = 0; i < k; i++){
        cout << i + 1 << ". ";
        cout << hopLe[i].maSV << " ";
        cout << hopLe[i].hoTen << " ";
        cout << hopLe[i].gpa << endl;
    }
}
void ghiFile(string tenFile, SinhVien a[], int soLuong){
    ofstream f(tenFile);
    f << "MaSV,HoTen,GPA,TinChi,KyLuat\n";
    for(int i = 0; i < soLuong; i++){
        f << a[i].maSV << ","
          << a[i].hoTen << ","
          << a[i].gpa << ","
          << a[i].tinChi << ","
          << a[i].kyLuat << endl;
    }
    f.close();
}
int main(){
    ds[n++] = {"SV08","NguyenVanA",3.70,30,0};
    ds[n++] = {"SV02","TranVanB",3.85,28,0};
    ds[n++] = {"SV05","LeVanC",3.70,33,0};
    ds[n++] = {"SV01","PhamVanD",3.20,25,0};
    ds[n++] = {"SV07","HoangVanE",3.90,22,0};
    ds[n++] = {"SV06","VoVanF",3.70,33,0};
    ds[n++] = {"SV03","NguyenVanG",3.10,40,0};
    ds[n++] = {"SV04","TranVanH",3.85,28,1};
    tachDanhSach();
    int luaChon;
    do{
        cout << "\n===== MENU =====\n";
        cout << "1. Hien thi hop le\n";
        cout << "2. Hien thi bi loai\n";
        cout << "3. Insertion Sort\n";
        cout << "4. Selection Sort\n";
        cout << "5. Bubble Sort\n";
        cout << "6. Top K\n";
        cout << "7. Ghi file\n";
        cout << "0. Thoat\n";
        cout << "Chon: ";
        cin >> luaChon;
        switch(luaChon){
            case 1:
                hienThi(hopLe, slHopLe);
                break;
            case 2:
                hienThi(biLoai, slBiLoai);
                break;
            case 3:
                insertionSort();
                hienThi(hopLe, slHopLe);
                break;
            case 4:
                selectionSort();
                hienThi(hopLe, slHopLe);
                break;
            case 5:
                bubbleSort();
                hienThi(hopLe, slHopLe);
                break;
            case 6:
                topK();
                break;
            case 7:
                ghiFile("valid.csv", hopLe, slHopLe);
                ghiFile("rejected.csv", biLoai, slBiLoai);
                ghiFile("ranked.csv", hopLe, slHopLe);
                cout << "Da ghi file\n";
                break;
        }
    }
    while(luaChon != 0);
    return 0;
}