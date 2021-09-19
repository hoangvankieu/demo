#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
struct Complex_number{
	int a,b;
};
void Complex_Number_Array(Complex_number *ptr,int n){
	for(int i=0;i<n;i++){
		cout<<"Enter complex number "<<i<<":\n";
		cout<<"Enter the real part:";
		cin>>(ptr+i)->a;
		cout<<"Enter virtual part:";
		cin>>(ptr+i)->b;
	}	
}
void Out_Array(Complex_number *ptr,int n){
	for(int i=0;i<n;i++){
		cout<<(ptr+i)->a<<"+"<<(ptr+i)->b<<"i\t";
	}
}
void Sum_Array(Complex_number *ptr,int n){
	int a=0,b=0;
	for(int i=0;i<n;i++){
		a+=(ptr+i)->a;
		b+=(ptr+i)->b;
	}
	cout<<a<<"+"<<b<<"i";
}
struct Student{
	char msv[20],ten[30];
	int ns;
	float toan,ly,hoa,tbc;
};
void Enter_List(Student *ptr,int n){
	for(int i=0;i<n;i++){
		cout<<"Enter student number "<<i+1<<":\n";
		cin.ignore();
		cout<<"Enter MSV:";
		cin.getline((ptr+i)->msv,20);
		cout<<"Enter name:";
		cin.getline((ptr+i)->ten,30);
		cout<<"Enter year of Birth:";
		cin>>(ptr+i)->ns;
		cout<<"Enter toan:";
		cin>>(ptr+i)->toan;
		cout<<"Enter ly:";
		cin>>(ptr+i)->ly;
		cout<<"Enter hoa:";
		cin>>(ptr+i)->hoa;
		(ptr+i)->tbc=((ptr+i)->toan+(ptr+i)->ly+(ptr+i)->hoa)/3;
	}
}
void Out_List(Student *ptr,int n){
	cout<<setw(5)<<left<<"STT";
	cout<<setw(10)<<left<<"MSV";
	cout<<setw(20)<<left<<"TEN";
	cout<<setw(15)<<left<<"NAM SINH";
	cout<<setw(7)<<left<<"TOAN";
	cout<<setw(7)<<left<<"LY";
	cout<<setw(7)<<left<<"HOA";
	cout<<setw(10)<<left<<"TBC";
	cout<<endl;
	cout<<setfill('-');
	cout<<setw(80)<<"-"<<endl;
	cout<<setfill(' ');
	for(int i=0;i<n;i++){
		cout<<setw(5)<<i+1<<left;
		cout<<setw(10)<<left<<(ptr+i)->msv;
		cout<<setw(20)<<left<<(ptr+i)->ten;
		cout<<setw(15)<<left<<(ptr+i)->ns;
		cout<<setw(7)<<left<<(ptr+i)->toan;
		cout<<setw(7)<<left<<(ptr+i)->ly;
		cout<<setw(7)<<left<<(ptr+i)->hoa;
		cout<<setw(10)<<left<<(ptr+i)->tbc;
		cout<<endl;
	}
}
void Search_Max_Avr(Student *ptr,int n){
	int Max=(ptr+0)->tbc;
	for(int i=0;i<n;i++){
		if((ptr+i)->tbc>Max){
			Max=(ptr+i)->tbc;
		}
	}
	cout<<"Sinh vien co diem TBC cao nhat:"<<endl;
	for(int i=0;i<n;i++){
		if((ptr+i)->tbc==Max){
		cout<<setw(5)<<i+1<<left;
		cout<<setw(10)<<left<<(ptr+i)->msv;
		cout<<setw(20)<<left<<(ptr+i)->ten;
		cout<<setw(15)<<left<<(ptr+i)->ns;
		cout<<setw(7)<<left<<(ptr+i)->toan;
		cout<<setw(7)<<left<<(ptr+i)->ly;
		cout<<setw(7)<<left<<(ptr+i)->hoa;
		cout<<setw(10)<<left<<(ptr+i)->tbc;
		cout<<endl;
		}
	}
}
void swap(Student *&a,Student *&b){
	Student *c;
	c=*(&a);
	a=b;
	b=c;
}
void Sort(Student *ptr,int n){
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if((ptr+i)->tbc>(ptr+j)->tbc){
				swap(*(ptr+i),*(ptr+j));
			}
		}
	}
	Out_List(ptr,n);
}
void Sort_math(Student *ptr,int n){
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if((ptr+i)->toan<(ptr+j)->toan){
				swap(*(ptr+i),*(ptr+j));
			}
		}
	}
	Out_List(ptr,n);
}
void Search_Std(Student *ptr,int n){
	for(int i=0;i<n;i++){
		if((ptr+i)->tbc>=5 && (ptr+i)->toan>=3 && (ptr+i)->ly>=3 &&(ptr+i)->hoa>=3){
		cout<<setw(5)<<i+1<<left;
		cout<<setw(10)<<left<<(ptr+i)->msv;
		cout<<setw(20)<<left<<(ptr+i)->ten;
		cout<<setw(15)<<left<<(ptr+i)->ns;
		cout<<setw(7)<<left<<(ptr+i)->toan;
		cout<<setw(7)<<left<<(ptr+i)->ly;
		cout<<setw(7)<<left<<(ptr+i)->hoa;
		cout<<setw(10)<<left<<(ptr+i)->tbc;
		cout<<endl;
		}
	}
}
void Search_Age_Biggest(Student *ptr,int n){
	int max=2021-(ptr+0)->ns;
	for(int i=1;i<n;i++){
		if(2021-(ptr+i)->ns>max){
		cout<<setw(5)<<i+1<<left;
		cout<<setw(10)<<left<<(ptr+i)->msv;
		cout<<setw(20)<<left<<(ptr+i)->ten;
		cout<<setw(15)<<left<<(ptr+i)->ns;
		cout<<setw(7)<<left<<(ptr+i)->toan;
		cout<<setw(7)<<left<<(ptr+i)->ly;
		cout<<setw(7)<<left<<(ptr+i)->hoa;
		cout<<setw(10)<<left<<(ptr+i)->tbc;
		cout<<endl;
		}
	}
}
main(){
	Student *ptr;
	int n;
	cout<<"Enter element number:";
	cin>>n;
	
	ptr=new Student[n];
	Enter_List(ptr,n);
	Out_List(ptr,n);
	Search_Max_Avr(ptr,n);
	cout<<endl;
	Sort_math(ptr,n);
	delete ptr;
}