#include<iostream>
using namespace std;
struct Sinhvien{
	int ID;
	char ht[30];
	int ns;
};
typedef struct Sinhvien SV;
struct Class{
	SV *LOP;
	char tenlop[30];
	int ss;
	struct Class *pNext;
};
typedef struct Class CLASS;
struct Node{
	CLASS *data;
	struct Node *pNext;
};
typedef struct Node NODE;
NODE *pHead=NULL;

CLASS *CreateSub(){
	CLASS *p=new CLASS;
	p->LOP=new SV;
	cout<<"Nhap ID:";
	cin>>p->LOP->ID;
	cin.ignore();
	cout<<"Nhap ho ten:";
	cin.getline(p->LOP->ht,30);
	cout<<"Nhap nam sinh:";
	cin>>p->LOP->ns;
	p->pNext=NULL;
	return p;
}
void InsertSubHead(CLASS *p){
	CLASS *phead=NULL;
	if(phead==NULL){
		phead=p;
	}
	else{
		p->pNext=phead;
		phead=p;
	}
}
void EnterClass(int n){
	for(int i=1;i<=n;i++){
		CLASS *p=CreateSub();
		InsertSubHead(p);
	}
}
NODE *CreateNode(){
	NODE *p=new NODE;
	p->data= new CLASS;
	cin.ignore();
	cout<<"Nhap ten lop:";
	cin.getline(p->data->tenlop,30);
	cout<<"Nhap si so:";
	cin>>p->data->ss;
	EnterClass(p->data->ss);
	p->pNext=NULL;
	return p;
}
void InsertHead(NODE *p){
	if(pHead==NULL){
		pHead=p;
	}
	else{
		p->pNext=pHead;
		pHead=p;
	}
}
void EnterNode(){
	int n;
	cout<<"Nhap so luong lop:";
	cin>>n;
	for(int i=1;i<=n;i++){
		NODE *p=CreateNode();
		InsertHead(p);
		system("cls");
	}	
}
void OutList(){
	CLASS *phead=NULL;
	for(NODE *k=pHead;k!=NULL;k=k->pNext){
		cout<<"Ten lop :"<<k->data->tenlop<<endl;
		cout<<"Si so   :"<<k->data->ss<<endl;	
		for(CLASS *h=phead;h!=NULL;h=h->pNext){
			cout<<"ID      :"<<h->LOP->ID<<endl;
			cout<<"Ho ten  :"<<h->LOP->ht<<endl;
			cout<<"Nam sinh:"<<h->LOP->ns<<endl;
		}	
	}
}

int main(){
	EnterNode();
	OutList();
	return 0;
}

