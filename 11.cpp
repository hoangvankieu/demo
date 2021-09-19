#include<iostream>
#include<cmath>
using namespace std;
struct Data{
	int x,i;
};
typedef struct Data DATA;
struct Node{
	DATA *data;
	struct Node *pNext;
};
typedef struct Node NODE;
struct List{
	NODE *pHead;
	NODE *pTail;
};
typedef struct List LIST;
void capphat(DATA *&data){
	data=new DATA;
}
void create(LIST &l){
	l.pHead=NULL;
	l.pTail=NULL;
}
NODE *CreateNode(int x,int i){
	NODE *p=new NODE;
	capphat(p->data);
	p->data->i=i;
	p->data->x=x;
	p->pNext=NULL;
	return p;
}
void InsertInLast(LIST &l, NODE *p){
	if(l.pHead==NULL){
		l.pHead=l.pTail=p;
	}
	else{
		l.pTail->pNext=p;
		l.pTail=p;
	}
}
void EnterLinkdList(LIST &l,int &n){
	cout<<"Nhap n:";
	cin>>n;
	int x;
	cout<<"Nhap x:";
	cin>>x;
	for(int k=1;k<=n;k++){
		NODE *p=CreateNode(x,k);
		InsertInLast(l,p);
	}
}
void OutList(LIST l){
	for(NODE *k=l.pHead;k!=NULL;k=k->pNext){
		cout<<k->data->x<<k->data->i;
	}
}
void SumofData(LIST l){
	int sum=0;
	for(NODE *k=l.pHead;k!=NULL;k=k->pNext){
		sum+=pow(k->data->x,k->data->i);
	}
	cout<<sum;
}
main(){
	LIST l;
	int n;
	create(l);
	EnterLinkdList(l,n);
	SumofData(l);
}
