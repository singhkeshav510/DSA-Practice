#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,b,sum=0;
    cin>>n>>b;
    clock_t t; 
    t = clock(); 
    vector<int> v1(n),v2(b+1,0),v3(n,0);
    for(int i=0;i<n;i++){
        cin>>v1[i];
        v2[v1[i]-1]+=1;
    }
    
    for(int i=0;i<b+1;i++){
        sum+=v2[i];
        v2[i]=sum;
    }
    
    for(int i=0;i<n;i++){
        v3[v2[v1[i]-1]-1]=v1[i];
        v2[v1[i]-1]=v2[v1[i]-1]-1;
    }
    
    for(int i=0;i<n;i++){
        cout<<v3[i]<<"\t";
    }
    cout<<"\n";
    t = clock()-t; 
    double time_taken = ((double)t)/CLOCKS_PER_SEC;
    cout<<time_taken;
    
}