#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007
#define mk make_pair
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
ll check(vector<ll> &v){
    for()
}
void solve(){
    ll n,m;
    cin>>n>>m;
    map<pair<ll,ll>,ll> mp;
    if(m==0){
        cout<<-1<<"\n";
        return;
    }
    ll a,b,c=1,flag=0;
    for(ll i=0;i<m;i++){
        cin>>a>>b>>c;
        if(mp[mk(a,b)]==0||mp[mk(b,a)]==0){
            if(c==0){
                mp[mk(a,b)]=1;mp[mk(b,a)]=1;
            }
            else {
                vector<ll> v(2*c);
                for(ll i=0;i;<2*c;i++){
                    cin>>v[i];
                }
                if(flag==0&&(mp[mk(b,a)]!=check(v))){
                    flag=1;
                }

                mp[mk(b,a)]=;
            }
        }
        else {
            if(flag==0&&c!=mp[mk(a,b)]){
                flag=1;
            }
            else{
                vector<ll> v(2*c);
                for(ll i=0;i;<2*c;i++){
                    cin>>v[i];
                }
                if(flag==0&&(mp[mk(b,a)]!=check(v))){
                    flag=1;
                }
            }
        }
    }
    if(flag==1){
        cout<<0<<"\n";
        return;
    }
    bool visited[n+1];
    memset(visited,false,sizeof(visited));
    for(auto itr=mp.begin();itr!=mp.end();itr++){
        if(!visited[(itr->first).first]){
                visited[(itr->first).first]=true;
        }
    }
    for(ll i=1;i<n+1;i++){
        if(!visited[i]){
            flag=1;

        }
    }
    if(flag==1){
        cout<<-1<<"\n";
        return;
    }


}
int main(){
    fastio
    ll t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}