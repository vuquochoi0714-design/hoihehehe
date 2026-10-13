#include <iostream>
using namespace std;
struct Node{
    int data;
    Node *left;
    Node *right;
};
Node* taoNode(int x){
    Node *p=new Node;
    p->data=x;
    p->left=NULL;
    p->right=NULL;
    return p;
}
void themNode(Node *&root,int x){
    if(root==NULL){
        root=taoNode(x);
        return;
    }
    if(x<root->data)
        themNode(root->left,x);
    else if(x>root->data)
        themNode(root->right,x);
}
void NLR(Node *root){
    if(root!=NULL){
        cout<<root->data<<" ";
        NLR(root->left);
        NLR(root->right);
    }
}
void LNR(Node *root){
    if(root!=NULL){
        LNR(root->left);
        cout<<root->data<<" ";
        LNR(root->right);
    }
}
void LRN(Node *root){
    if(root!=NULL){
        LRN(root->left);
        LRN(root->right);
        cout<<root->data<<" ";
    }
}
int demNode(Node *root){
    if(root==NULL) return 0;
    return 1+demNode(root->left)+demNode(root->right);
}
int chieuCao(Node *root){
    if(root==NULL) return 0;
    int trai=chieuCao(root->left);
    int phai=chieuCao(root->right);
    return (trai>phai?trai:phai)+1;
}
bool timKiem(Node *root,int x){
    if(root==NULL) return false;
    if(root->data==x) return true;
    if(x<root->data)
        return timKiem(root->left,x);
    return timKiem(root->right,x);
}
void xoaCay(Node *&root){
    if(root!=NULL){
        xoaCay(root->left);
        xoaCay(root->right);
        delete root;
        root=NULL;
    }
}
int main(){
    Node *root=NULL;
    int n,x;
    cout<<"Nhap so node: ";
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<"Nhap gia tri: ";
        cin>>x;
        themNode(root,x);
    }
    cout<<"NLR: ";
    NLR(root);
    cout<<"\nLNR: ";
    LNR(root);
    cout<<"\nLRN: ";
    LRN(root);
    cout<<"\nSo node: "<<demNode(root);
    cout<<"\nChieu cao: "<<chieuCao(root);
    cout<<"\nNhap gia tri can tim: ";
    cin>>x;
    if(timKiem(root,x))
        cout<<"Tim thay";
    else
        cout<<"Khong tim thay";
    xoaCay(root);
    return 0;
}