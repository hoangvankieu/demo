#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;
struct Sinhvien{
	int ID;
	char ht[30];
};
typedef struct Sinhvien SV;
struct Class{
	SV *Lop;
	char tenlop[5];
	int ss;	
};
typedef struct Class CLASS;
struct Node{
	CLASS *data;
	struct Node *pNext;
};
typedef struct Node NODE;
NODE *pHead=NULL,*pTail=NULL;

NODE *CreateNode(){
	NODE *p=new NODE;
	p->data=new CLASS;
	cout<<"Nhap ten lop:";
	cin.getline(p->data->tenlop,5);
	cout<<"Nhap si so:";
	cin>>p->data->ss;
	p->data->Lop=new SV[p->data->ss];
	for(int i=0;i<p->data->ss;i++){
		cout<<"Nhap ID:";
		cin>>p->data->Lop[i].ID;
		cin.ignore();
		cout<<"Nhap ho va ten:";
		cin.getline(p->data->Lop[i].ht,30);	
	}
	p->pNext=NULL;
	return p;
}
void InsertHead(NODE *p){
	if(pHead==NULL){
		pHead=pTail=p;
	}
	else{
		p->pNext=pHead;
		pHead=p;
	} 
}
void EnterList(){
	int n;
	cout<<"Nhap so lop:";
	cin>>n;
	system("cls");
	for(int i=1;i<=n;i++){
		if(i==1)cin.ignore();
		NODE *p=CreateNode();
		InsertHead(p);
		system("cls");
	}
}
void OutList(){
	for(NODE *k=pHead;k!=NULL;k=k->pNext){
		cout<<"Ten lop"<<k->data->tenlop<<endl;
		for(int i=0;i<k->data->ss;i++){
			cout<<k->data->Lop[i].ht<<endl;
		}
	}
}
int main(){
	EnterList();
	OutList();
	return 0;
}