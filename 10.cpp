#include<iostream>
using namespace std;
struct node{
	int data;
	struct node *pNext;	
};
typedef struct node NODE;
struct list{
	NODE pHead;
	NODE pTail;
};
typedef struct list LIST; 
//void Create(LIST &l){
//	l.pHead=NULL;
//	l.pTail=NULL;
//}
NODE *CreateNode(int x){
	NODE *p=new NODE;
	p->data=x;
	p->pNext=NULL;
	return p;
}
void InsertInFirst(LIST &l, NODE *p){
	if(l.pHead==NULL){
		l.pHead=p;
	}
	else{
		p->pNext=l.pHead;
		l.pHead=p;
	}
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
void InputLinkdList(LIST &l,int &n){
	cout<<"Nhap n:";
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		cout<<"Nhap x:";
		cin>>x;
		NODE *p=CreateNode(x);
		InsertInLast(l,p);
	}
}
void OutLinkdList(LIST l){
	for(NODE *k=l.pHead;k!=NULL;k=k.pNext){
		cout<<k->data<<"\t";
	}
}

int main(){
	LIST l;
	int n;
//	Create(l);
	InputLinkdList(l,n);
	OutLinkdList(l);
}