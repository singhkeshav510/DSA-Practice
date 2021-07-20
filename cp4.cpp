#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int

bool check(int x){
	
    while(x!=0){
        if(x%10==4){
            return true;
        }
        x/=10;
    }
    return false;
}
int binarysearch(int start,int end ){
    if(start>end){
        return 0;
    }
    if(start==end){
        if(check(start)&&start!=0){
            return 1;
        }
        return 0;
    }
    int mid=(start+end)/2;

    return binarysearch(start,mid)+binarysearch(mid+1,end);
}

int main(){
    int t;
    t=1;
    cin>>t;
    while(t--){
        int x;
        cin>>x;
        int start=0,end=x;
        int count=binarysearch(start,end);
        cout<<x-count<<"\n";
        
    }
    return 0;
}
