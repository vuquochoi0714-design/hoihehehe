#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;
const int MAX = 100;
struct BenhNhan {
    int ma;
    char ten[30];
    int tuoi;
    int gioDen;
    int uuTien;
};

struct Node {
    BenhNhan data;
    Node* next;
};

struct Queue {
    Node* front;
    Node* rear;
};

void khoiTaoQueue(Queue &q)
{
    q.front = q.rear = NULL;
}

bool rong(Queue q)
{
    return q.front == NULL;
}

void enqueue(Queue &q, BenhNhan bn)
{
    Node *p = new Node;
    p->data = bn;
    p->next = NULL;

    if(rong(q))
        q.front = q.rear = p;
    else
    {
        q.rear->next = p;
        q.rear = p;
    }
}

bool dequeue(Queue &q, BenhNhan &bn)
{
    if(rong(q))
        return false;

    Node *p = q.front;
    bn = p->data;

    q.front = q.front->next;

    if(q.front == NULL)
        q.rear = NULL;

    delete p;
    return true;
}

void inBenhNhan(BenhNhan bn)
{
    cout << left
         << setw(8) << bn.ma
         << setw(15) << bn.ten
         << setw(8) << bn.tuoi
         << setw(10) << bn.gioDen
         << setw(10) << bn.uuTien
         << endl;
}

void hienThi(BenhNhan ds[], int n)
{
    if(n == 0)
    {
        cout << "Danh sach rong!\n";
        return;
    }

    cout << left
         << setw(8) << "Ma"
         << setw(15) << "Ten"
         << setw(8) << "Tuoi"
         << setw(10) << "Gio"
         << setw(10) << "UuTien"
         << endl;

    for(int i=0;i<n;i++)
        inBenhNhan(ds[i]);
}

bool trungMa(BenhNhan ds[], int n, int ma)
{
    for(int i=0;i<n;i++)
        if(ds[i].ma == ma)
            return true;

    return false;
}

void themBenhNhan(BenhNhan ds[], int &n)
{
    BenhNhan bn;

    cout << "Ma: ";
    cin >> bn.ma;

    if(trungMa(ds,n,bn.ma))
    {
        cout << "Ma da ton tai!\n";
        return;
    }

    cout << "Ten: ";
    cin >> bn.ten;

    cout << "Tuoi: ";
    cin >> bn.tuoi;

    cout << "Gio den: ";
    cin >> bn.gioDen;

    cout << "Uu tien: ";
    cin >> bn.uuTien;

    ds[n++] = bn;

    cout << "Them thanh cong!\n";
}

void duLieuMau(BenhNhan ds[], int &n)
{
    ds[n++] = {101,"An",25,8,2};
    ds[n++] = {102,"Binh",70,7,1};
    ds[n++] = {103,"Chi",40,9,3};
    ds[n++] = {104,"Dung",65,8,1};
    ds[n++] = {105,"Ha",35,10,2};

    cout << "Da tao du lieu mau!\n";
}

void sapXepTheoMa(BenhNhan ds[], int n)
{
    for(int i=1;i<n;i++)
    {
        BenhNhan x = ds[i];
        int j = i-1;

        while(j>=0 && ds[j].ma > x.ma)
        {
            ds[j+1] = ds[j];
            j--;
        }

        ds[j+1] = x;
    }
}

int binarySearch(BenhNhan ds[], int n, int ma)
{
    int l = 0;
    int r = n-1;

    while(l <= r)
    {
        int mid = (l+r)/2;

        if(ds[mid].ma == ma)
            return mid;

        if(ds[mid].ma < ma)
            l = mid + 1;
        else
            r = mid - 1;
    }

    return -1;
}

void timBenhNhan(BenhNhan ds[], int n)
{
    BenhNhan temp[MAX];

    for(int i=0;i<n;i++)
        temp[i] = ds[i];

    sapXepTheoMa(temp,n);

    int ma;
    cout << "Nhap ma can tim: ";
    cin >> ma;

    int vt = binarySearch(temp,n,ma);

    if(vt == -1)
        cout << "Khong tim thay!\n";
    else
        inBenhNhan(temp[vt]);
}

void xoaBenhNhan(BenhNhan ds[], int &n)
{
    int ma;

    cout << "Nhap ma can xoa: ";
    cin >> ma;

    int vt = -1;

    for(int i=0;i<n;i++)
    {
        if(ds[i].ma == ma)
        {
            vt = i;
            break;
        }
    }

    if(vt == -1)
    {
        cout << "Khong tim thay!\n";
        return;
    }

    for(int i=vt;i<n-1;i++)
        ds[i] = ds[i+1];

    n--;
    cout << "Xoa thanh cong!\n";
}

void capNhat(BenhNhan ds[], int n)
{
    int ma;

    cout << "Nhap ma can sua: ";
    cin >> ma;

    for(int i=0;i<n;i++)
    {
        if(ds[i].ma == ma)
        {
            cout << "Ten moi: ";
            cin >> ds[i].ten;
            cout << "Tuoi moi: ";
            cin >> ds[i].tuoi;
            cout << "Uu tien moi: ";
            cin >> ds[i].uuTien;
            cout << "Cap nhat thanh cong!\n";
            return;
        }
    }

    cout << "Khong tim thay!\n";
}
void taoQueue(BenhNhan ds[], int n, Queue &q)
{
    for(int i=0;i<n;i++)
        enqueue(q, ds[i]);

    cout << "Da tao queue!\n";
}
void tiepNhan(Queue &q)
{
    BenhNhan bn;

    if(dequeue(q,bn))
    {
        cout << "Benh nhan dang kham:\n";
        inBenhNhan(bn);
    }
    else
        cout << "Queue rong!\n";
}
void hienThiQueue(Queue q)
{
    Node *p = q.front;

    while(p != NULL)
    {
        inBenhNhan(p->data);
        p = p->next;
    }
}
void lonTuoiNhat(BenhNhan ds[], int n)
{
    int vt = 0;

    for(int i=1;i<n;i++)
    {
        if(ds[i].tuoi > ds[vt].tuoi)
            vt = i;
    }
    cout << "Benh nhan lon tuoi nhat:\n";
    inBenhNhan(ds[vt]);
}
int main()
{
    BenhNhan ds[MAX];
    int n = 0;

    Queue q;
    khoiTaoQueue(q);

    int chon;

    do
    {
        cout << "\n===== QUAN LY BENH NHAN =====\n";
        cout << "1. Them benh nhan\n";
        cout << "2. Hien thi danh sach\n";
        cout << "3. Du lieu mau\n";
        cout << "4. Tim theo ma\n";
        cout << "5. Tao Queue\n";
        cout << "6. Tiep nhan benh nhan\n";
        cout << "7. Hien thi Queue\n";
        cout << "8. Xoa benh nhan\n";
        cout << "9. Cap nhat benh nhan\n";
        cout << "10. Benh nhan lon tuoi nhat\n";
        cout << "0. Thoat\n";
        cout << "Chon: ";
        cin >> chon;

        switch(chon)
        {
            case 1:
                themBenhNhan(ds,n);
                break;

            case 2:
                hienThi(ds,n);
                break;

            case 3:
                duLieuMau(ds,n);
                break;

            case 4:
                timBenhNhan(ds,n);
                break;

            case 5:
                taoQueue(ds,n,q);
                break;

            case 6:
                tiepNhan(q);
                break;

            case 7:
                hienThiQueue(q);
                break;

            case 8:
                xoaBenhNhan(ds,n);
                break;

            case 9:
                capNhat(ds,n);
                break;

            case 10:
                lonTuoiNhat(ds,n);
                break;

            case 0:
                cout << "Ket thuc chuong trinh\n";
                break;

            default:
                cout << "Lua chon khong hop le!\n";
        }

    }while(chon != 0);

    return 0;
}
