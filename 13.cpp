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
NODE *CreateNode(int x){
	NODE *p=new NODE;
	p->data=x;
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
void EnterList(LIST &l,int &n){
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
void Insert_p_then_q(LIST &l){
	int s;
	cout<<"Nhap s:";
	cin>>s;
	NODE *q=CreateNode(s);
	int x;
	cout<<"Nhap x:";
	cin>>x;
	NODE *p=CreateNode(x);
	for(NODE *k=l.pHead;k!=NULL;k=k->pNext){
		if(q->data==k->data){
			p->pNext=k->pNext;
			k->pNext=p;
		}
	}		
}
void OutList(LIST l){
	for(NODE *k=l.pHead;k!=NULL;k=k->pNext){
		cout<<k->data<<"\t";
	}
}
int main(){
	LIST l;
	int n;
	Create(l);
	EnterList(l,n);
	Insert_p_then_q(l);
	OutList(l);	
}