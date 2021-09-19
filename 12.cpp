#include<iostream>
#include<cmath>
using namespace std;
struct Data{
	int x,i;
};
typedef struct Data DATA;
struct Node{
	Data data;
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
NODE *CreateNode(int x,int i){
	NODE *p=new NODE;
	p->data.x=x;
	p->data.i=i;
	p->pNext=NULL;
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
void EnterLinkdList(List &l,int &n){
	cout<<"Nhap n:";
	cin>>n;
	int x;
	cout<<"Nhap x:";
	cin>>x;
	for(int i=1;i<=n;i++){
		NODE *p=CreateNode(x,i);
		InsertInLast(l,p);
	}
}
void OutLinkdList(LIST l){
	for(NODE *k=l.pHead;k!=NULL;k=k->pNext){
		cout<<k->data.i<<"\t";
	}
}
int Factorial(int n){
	int Fct=1;
	for(int i=1;i<=n;i++){
		Fct*=i;
	}
	return Fct;
}
int Exponential(int x,int n){
	int Ept;
	Ept=pow(x,n);
	return Ept;	
}
void SumOfData(LIST l){
	float Sum=0;
	for(NODE *k=l.pHead;k!=NULL;k=k->pNext){
		int Fct=Factorial(k->data.i);
		int Ept=Exponential(k->data.x,k->data.i);
		Sum+=(float)Ept/Fct;
	}
	cout<<Sum;
}
int main(){
	LIST l;
	int n;
	Create(l);
	EnterLinkdList(l,n);
//	OutLinkdList(l);
	SumOfData(l);
	return 0;
}
