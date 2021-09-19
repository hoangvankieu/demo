#include<iostream>
using namespace std;
struct fraction{
	int mumerator,denominator;
};	
void fraction2(fraction *&ptr){
	cout<<"Enter numerator:";
	cin>>ptr->mumerator;
	cout<<"Enter denominator:";
	cin>>ptr->denominator;
}
int UCLN(fraction *ptr){
	int ucln;
	for(int i=1;i<=ptr->mumerator;i++){
	 	if(ptr->mumerator%i==0 && ptr->denominator%i==0){
	 		ucln=i;
		}
	}
	return ucln;
}
void Reduce_Fraction(fraction *ptr){
	int ucln=UCLN(ptr);
	cout<<ptr->mumerator/ucln<<"/"<<ptr->denominator/ucln;
}
int UCLN2(int a,int b){
	int ucln;
	for(int i=1;i<=b;i++){
		if(a%i==0 && b%i==0){
			ucln=i;
		}
	}       
	return ucln;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                
}
void plus_2_fraction(fraction *ptr,fraction *ptr2){
	int a=ptr->mumerator*ptr2->denominator + ptr->denominator*ptr2->mumerator;
	int b=ptr->denominator*ptr2->denominator;
	int ucln=UCLN2(a,b);
	cout<<a/ucln<<"/"<<b/ucln;
}
void product_of_2_fraction(fraction *ptr,fraction *ptr2){
	int a=ptr->mumerator*ptr2->mumerator;
	int b=ptr->denominator*ptr2->denominator;
	int ucln=UCLN2(a,b);
	cout<<a/ucln<<"/"<<b/ucln;
}
void quotient_2_fraction(fraction *ptr,fraction *ptr2){
	int a=ptr->mumerator*ptr2->denominator;
	int b=ptr->denominator*ptr2->mumerator;
	int ucln=UCLN2(a,b);
	cout<<a/ucln<<"/"<<b/ucln;
}
struct complex_number{
	int a,b;
};
void Enter_Complex_Number(complex_number *ptr){
	cout<<"Enter The Real Part:";
	cin>>ptr->a;
	cout<<"Enter Virtual Part:";
	cin>>ptr->b;
	cout<<"Z= ";
	if(ptr->b>0 && ptr->a!=0){
		cout<<ptr->a<<"+"<<ptr->b<<"i";
	}
	else if(ptr->b<0&& ptr->a!=0){
		cout<<ptr->a<<ptr->b<<"i";
	}
	else if(ptr->a==0 && ptr->b!=0){
		cout<<ptr->b<<"i";
	}
	else if(ptr->b==0){
		cout<<ptr->a;
	}	
}
void Sum_Complex_Number(complex_number *ptr,complex_number *ptr2){
	int a=ptr->a+ptr2->a;
	int b=ptr->b+ptr2->b;
	cout<<"Sum a & b:";
	cout<<"\nZ= ";
	if(b>0 && a!=0){
		cout<<a<<"+"<<b<<"i";
	}
	else if(b<0&& a!=0){
		cout<<a<<b<<"i";
	}
	else if(a==0 && b!=0){
		cout<<b<<"i";
	}
	else if(b==0){
		cout<<a;
	}	
}
void Complement_Complex_Number(complex_number *ptr,complex_number *ptr2){
	int a=ptr->a-ptr2->a;
	int b=ptr->b-ptr2->b;
	cout<<"Sum a & b:";
	cout<<"\nZ= ";
	if(b>0 && a!=0){
		cout<<a<<"+"<<b<<"i";
	}
	else if(b<0&& a!=0){
		cout<<a<<b<<"i";
	}
	else if(a==0 && b!=0){
		cout<<b<<"i";
	}
	else if(b==0){
		cout<<a;
	}	
}
void Product_Complex_Number(complex_number *ptr,complex_number *ptr2){
	int a=ptr->a*ptr2->a-ptr->b*ptr2->b;
	int b=ptr->a*ptr2->b+ptr->b*ptr2->a;
	cout<<"Sum a & b:";
	cout<<"\nZ= ";
	if(b>0 && a!=0){
		cout<<a<<"+"<<b<<"i";
	}
	else if(b<0&& a!=0){
		cout<<a<<b<<"i";
	}
	else if(a==0 && b!=0){
		cout<<b<<"i";
	}
	else if(b==0){
		cout<<a;
	}	
}
main(){
	fraction a,b,*ptr,*ptr2;
	ptr=&a;
	ptr2=&b;
	complex_number c,d,*ptr3,*ptr4;
	ptr3=&c;
	ptr4=&d;
	Enter_Complex_Number(ptr3);
	cout<<endl;
	Enter_Complex_Number(ptr4);
	cout<<endl;
	Product_Complex_Number(ptr3,ptr4);
	delete ptr,ptr2;
	
}