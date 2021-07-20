#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    int n;
    cin>>n;
    ll a[n]={0},x[n]={0},t;
    cin>>a[0];
    x[0]=0;
    a[0]=a[0]+x[0];
    for(int i=1;i<n;i++){
        cin>>a[i];
        x[i]=max(x[i-1],a[i-1]);
        a[i]=a[i]+x[i];
    }
    for(int i=0;i<n;i++){
        
        cout<<a[i]<<" ";
    }
    
}
