#include<iostream>
using namespace std;
struct Node{
	int data;
	struct Node *pNext;
};
typedef struct Node NODE;
struct List{
	NODE *pHead;
	NODE *pTail;
};
typedef struct List LIST;
void Create(LIST &l){
	l.pHead=NULL;
	l.pTail=NULL;
}
NODE* CreateNode(int x){
	NODE *p=new NODE;
	p->data=x;
	return p;
}
void InsertInLast(LIST &l,NODE *p){
	if(l.pHead==NULL){
		l.pHead=l.pTail=p;
	}
	else{
		l.pTail->pNext=p;
		l.pTail=p;
	}
}
void EnterList(LIST &l,int &n){
	cout<<"Nhap n:";
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		cout<<"Nhap x:";
		cin>>x;
		NODE *p=CreateNode(x);
		if(i==n){
			p->pNext=NULL;
		}
		InsertInLast(l,p);
	}
}
void InsertInPosition(LIST &l){
	int q,x;
	cout<<"Nhap vi tri muon chen";
	cin>>q;
	cout<<"Nhap gia tri x:";
	cin>>x;
	int dem=1;
	for(NODE *k=l.pHead;k!=NULL;k=k->pNext){
		if(dem==q-1){
			NODE *p=CreateNode(x);
			p->pNext=k->pNext;
			k->pNext=p;
		}
		dem++;
	}
}
void Del(LIST &l){
	int dem=1;
	NODE *g=new NODE;
	g=l.pHead;
	for(NODE *k=l.pHead;k!=NULL;k=k->pNext){
		if(dem==1){
			l.pHead=k->pNext;
			cout<<g->data;
			g->pNext=NULL;
			dem=0;	
		}
	}
}
int count(LIST &l){
	int dem=0;
	for(NODE *k=l.pHead;k!=NULL;k=k->pNext){
		dem++;
	}
	return dem;
}
void DelpTail(LIST &l){
	int dem=1;
	int h=count(l);
	for(NODE *k=l.pHead;k!=NULL;k=k->pNext){
		if(dem==h-1){
			k->pNext=NULL;
			l.pTail=k;
		}
		dem++;
	}
}
void OutList(LIST l){
	for(NODE *k=l.pHead;k!=NULL;k=k->pNext){
		cout<<k->data<<"\t";
	}
}

int main(){
	int n;
	LIST l;
	Create(l);
	EnterList(l,n);
	DelpTail(l);
	OutList(l);
	return 0;
}