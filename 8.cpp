#include<iostream>
#include<cmath>
using namespace std;
float PS(int n){
	if(n==0){
		return 0;
	}
	int dem=PS(n/10);
	dem++;
	return dem;
}
main(){
	int n=374855;
	float s=PS(n);
	cout<<s;
}