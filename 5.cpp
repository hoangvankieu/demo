#include<iostream>
using namespace std;
void Input_Array(int *&ptr,int &n){
	cout<<"Enter number element:";
	cin>>n;
	ptr=new int[n];
	cout<<"Enter element:";
	for(int i=0;i<n;i++){
		cin>>*(ptr+i);
	}
}
void Output_Array(int *ptr,int n){
	for(int i=0;i<n;i++){
		cout<<*(ptr+i)<<"\t";
	}
}
void Delete(int *ptr,int &n,int pst){
	for(int i=pst;i<n-1;i++){
		*(ptr+i)=*(ptr+i+1);
	}
	ptr=new int[n--];
}
void Search_big_k(int *ptr,int n){
	int k;
	cout<<"\nPosition need search:";
	cin>>k;
	while(k>0){
		int max=*(ptr+0);
		for(int i=0;i<n;i++){
			if(*(ptr+i)>max){
				max=*(ptr+i);	
			}
		}
		for(int j=0;j<n;j++){
			if(*(ptr+j)==max){
				Delete(ptr,n,j);
				j--;
			}
		}
		k--;
	}
	int max=*(ptr+0);
	for(int i=0;i<n;i++){
		if(*(ptr+i)>max){
			max=*(ptr+i);
		}
	}
	cout<<max;
}
bool Up(int a,int b){
	return a>b;	
}
bool Down(int a,int b){
	return a<b;	
}
void swap(int *&a,int *&b){
	int *c=a;
	a=b;
	b=c;
}
void Sort(int *ptr,int n,bool (*ptr2)(int,int)){
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(ptr2(*(ptr+i),*(ptr+j))){
				swap(*(ptr+i),*(ptr+j));
			}
		}
	}
}
main(){
	int *ptr,n;
	Input_Array(ptr,n);
	Output_Array(ptr,n);
	Sort(ptr,n,Up);
	cout<<endl;
	Output_Array(ptr,n);
	Sort(ptr,n,Down);
	cout<<endl;
	Output_Array(ptr,n);
}