#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAX 100
unsigned getnugly(unsigned n){
	unsigned u[n];
	unsigned i2=0,i3=0,i5=0;
	unsigned n2 = 2; 
    unsigned n3 = 3; 
    unsigned n5 = 5; 
	unsigned un=1;
	u[0]=1;
	for(int i=1;i<n;i++){
		un=min(n2,min(n3,n5));
		u[i] = un; 
       if (un == n2) 
       { 
           i2 = i2+1; 
           n2 = u[i2]*2; 
       } 
       if (un == n3) 
       { 
           i3 = i3+1; 
           n3 = u[i3]*3; 
       } 
       if (un == n5) 
       { 
           i5 = i5+1; 
           n5 = u[i5]*5; 
       } 
    }
    return un;
}

int main(){
	int n;
	cin>>n;
	cout<<getnugly(n);
}