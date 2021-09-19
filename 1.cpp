#include<iostream>
using namespace std;
void Enter_Array(int *&a,int &n){
	cout<<"Enter Number Element In Array:";
	cin>>n;
	a=new int[n];
	cout<<"Enter Element:";
	for(int i=0;i<n;i++){
		cout<<"a["<<i<<"]=";
		cin>>a[i];
	}
}
void Out_Array(int *a,int n){
	for(int i=0;i<n;i++){
		cout<<a[i]<<"\t";
	}
}
void Move_Right(int *a,int &n,int pst){
	for(int i=n;i>=pst;i--){
		a[i]=a[i-1];
	}
	a=new int(n++);
}
void Insert_Element(int *a,int &n){
	int elmt,pst;
	cout<<"Enter Element:";
	cin>>elmt;
	cout<<"Enter Position:";
	cin>>pst;
	Move_Right(a,n,pst);
	a[pst]=elmt;
}
void Move_Left(int *a,int &n,int pst){
	for(int i=pst;i<n;i++){
		a[i]=a[i+1];
	}
	a=new int(n--);
}
void Delete_Element(int *a,int &n){
	int pst;
	cout<<"Enter position:";
	cin>>pst;
	Move_Left(a,n,pst);
	Out_Array(a,n);
}
main(){
	int *a=nullptr,n;
	Enter_Array(a,n);
	Out_Array(a,n);
	cout<<endl;
	Delete_Element(a,n);
	delete a;	
}