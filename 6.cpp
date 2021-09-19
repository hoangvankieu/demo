#include<iostream>
using namespace std;
struct Student{
	char ID[20];
	char name_std[30];
	int YearOfBrith;
	float mark;
};
struct School{
	char name_class[10];
	int number;
	Student *HS;	
};
Student *Input_List_std(int ss){
	Student *HS=new Student[ss];
	for(int i=0;i<ss;i++){
		cout<<"Enter student number"<<i+1<<":\n";
		cout<<"Enter student ID:";
		cin.ignore();
		cin.getline((HS+i)->ID,20);
		cout<<"Enter student name:";
		cin.getline((HS+i)->name_std,30);
		cout<<"Enter mark:";
		cin>>(HS+i)->mark;
	}
	return HS;
}
void Input_List_School(School *ptr,int n){
	for(int i=0;i<n;i++){
		cout<<"Enter class number"<<i+1<<":\n";
		cout<<"Enter class name:";
		cin.ignore();
		cin.getline((ptr+i)->name_class,20);
		cout<<"Enter class number:";
		cin>>((ptr+i)->number);
		((ptr+i)->HS)=Input_List_std((ptr+i)->number);
	}
}
void Out_list(School *ptr,int n){
	for(int i=0;i<n;i++){
		cout<<"Class"<<i+1<<":\n";
		cout<<"Name class:\n"<<(ptr+i)->name_class;
		cout<<"Class number:\n"<<(ptr+i)->number;
		for(int j=0;j<(ptr+i)->number;j++){
			Student *HS=(ptr+i)->HS;
			cout<<"ID:"<<(HS+j)->ID<<endl;
			cout<<"Name:"<<(HS+j)->name_std<<endl;
			cout<<"Mark:"<<(HS+j)->mark<<endl;
		}
	}
}
main(){
	School *ptr;
	int n;
	cout<<"Enter n:";
	cin>>n;
	ptr=new School[n];
	Input_List_School(ptr,n);
	Out_list(ptr,n);
}