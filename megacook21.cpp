#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    unsigned int t;
    cin>>t;
    while(t--){
        int r=0;
        unsigned int n,k,m;
        cin>>n>>k>>m;
        unsigned int a,x[m+1]={0},y[m+1]={0},z[m+1]={0},A[n+1]={0};
        A[0]=1;y[0]=1;z[0]=1;x[0]=1;
        for(int i=1;i<=m;i++){
            cin>>a>>y[i]>>z[i];
            if(a<=k){
                x[i]=a;
                if(y[i]==i)
                    A[z[i]]=x[i];
            }
            else r=1;
        }
        
        
        
    }
    
}