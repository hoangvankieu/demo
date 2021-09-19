#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;
void nhap(int *a,int n){
	for(int i=0;i<n;i++){
		a[i]=rand()%100+1;
	}
}
void xuat(int *a,int n){
	for(int i=0;i<n;i++){
		cout<<a+i<<"\t";
	}
}
int main()
{
	int *a,n;
	n=100;
	cout<<a<<endl;
	nhap(a,n);
	xuat(a,n);
}