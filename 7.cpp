#include<iostream>
using namespace std;
short tohop(short n,short k){
	short nk=1,kk=1,n_k=1;
	for(short i=1;i<=n;i++){
		nk*=i;
	}
	for(short i=1;i<=k;i++){
		kk*=i;
    }
	for(short i=1;i<=n-k;i++){
		n_k*=i;
	}
	int p=nk/(kk*n_k);
	return p;
    
}
main(){
	short n,k;
    cin>>n>>k;
    int h=tohop(n,k);
    cout<<h; 
}