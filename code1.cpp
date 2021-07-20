#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){
    fastio
    ll t;
    cin>>t;
    while(t--){
        ll n,a;
        cin>>n;
        ll f=0;
        for(ll i=0;i<n;i++){
            cin>>a;
            if(a%2==0){
                f=1;
            }
        }
        if(f==0)
            cout<<"YES\n";
        else cout<<"NO\n";
    }
}
