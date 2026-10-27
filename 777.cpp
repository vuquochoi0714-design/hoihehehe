#include <iostream>
#include <string>
using namespace std;
struct Product {
    int maSP;
    string tenSP;
    int soLuong;
    double donGia;
};
struct Node {
    Product data;
    Node* left;
    Node* right;
};
Node* createNode(Product p) {
    Node* newNode = new Node;
    newNode->data = p;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}
Node* insert(Node* root, Product p) {
    if (root == nullptr)
        return createNode(p);
    if (p.maSP < root->data.maSP)
        root->left = insert(root->left, p);
    else if (p.maSP > root->data.maSP)
        root->right = insert(root->right, p);
    else
        cout << "Ma san pham da ton tai\n";
    return root;
}
Node* search(Node* root, int maSP) {
    if (root == nullptr || root->data.maSP == maSP)
        return root;
    if (maSP < root->data.maSP)
        return search(root->left, maSP);
    return search(root->right, maSP);
}
void printProduct(Product p) {
    cout << "\nMa SP: " << p.maSP << endl;
    cout << "Ten SP: " << p.tenSP << endl;
    cout << "So luong: " << p.soLuong << endl;
    cout << "Don gia: " << p.donGia << endl;
}
void inorder(Node* root) {
    if (root == nullptr)
        return;
    inorder(root->left);
    cout << root->data.maSP << " - "
         << root->data.tenSP << " - "
         << root->data.soLuong << " - "
         << root->data.donGia << endl;
    inorder(root->right);
}
int countNodes(Node* root) {
    if (root == nullptr)
        return 0;
    return 1 + countNodes(root->left)
             + countNodes(root->right);
}
int height(Node* root) {
    if (root == nullptr)
        return 0;
    int left = height(root->left);
    int right = height(root->right);
    return (left > right ? left : right) + 1;
}
Node* minValueNode(Node* node) {
    Node* current = node;
    while (current && current->left != nullptr)
        current = current->left;
    return current;
}
Node* deleteNode(Node* root, int maSP) {
    if (root == nullptr)
        return root;
    if (maSP < root->data.maSP)
        root->left = deleteNode(root->left, maSP);
    else if (maSP > root->data.maSP)
        root->right = deleteNode(root->right, maSP);
    else {
        if (root->left == nullptr && root->right == nullptr) {
            delete root;
            return nullptr;
        }
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        Node* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data.maSP);
    }
    return root;
}
void freeTree(Node* root) {
    if (root == nullptr)
        return;
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}
Product inputProduct() {
    Product p;
    cout << "Nhap ma SP: ";
    cin >> p.maSP;
    cin.ignore();
    cout << "Nhap ten SP: ";
    getline(cin, p.tenSP);
    cout << "Nhap so luong: ";
    cin >> p.soLuong;
    cout << "Nhap don gia: ";
    cin >> p.donGia;
    return p;
}
void menu() {
    cout << "\n         MENU       \n";
    cout << "1. Them san pham\n";
    cout << "2. Tim kiem san pham\n";
    cout << "3. Xoa san pham\n";
    cout << "4. Hien thi danh sach\n";
    cout << "5. Thong ke\n";
    cout << "0. Thoat\n";
    cout << "                          \n";
}
int main() {
    Node* root = nullptr;
    int choice;
    do {
        menu();
        cout << "Nhap lua chon: ";
        cin >> choice;
        switch (choice) {
        case 1: {
            Product p = inputProduct();
            root = insert(root, p);
            break;
        }
        case 2: {
            int maSP;
            cout << "Nhap ma can tim: ";
            cin >> maSP;
            Node* result = search(root, maSP);
            if (result != nullptr)
                printProduct(result->data);
            else
                cout << "Khong tim thay san pham\n";
            break;
        }
        case 3: {
            int maSP;
            cout << "Nhap ma can xoa: ";
            cin >> maSP;
            root = deleteNode(root, maSP);
            cout << "Da xu ly xoa!\n";
            break;
        }
        case 4:
            cout << "\nDanh sach san pham:\n";
            inorder(root);
            break;
        case 5:
            cout << "\nSo nut: " << countNodes(root) << endl;
            cout << "Chieu cao cay: " << height(root) << endl;
            break;
        case 0:
            cout << "Ket thuc chuong trinh \n";
            break;
        default:
            cout << "Lua chon khong hop le\n";
        }
    } while (choice != 0);
    freeTree(root);
    return 0;
}