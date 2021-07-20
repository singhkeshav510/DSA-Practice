#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
void solve(){
     ll n;
        cin>>n;
        map<ll,ll> map1,map2;
        vector<ll> a(n),b(n);
        unordered_map<ll,ll> umap;
        for(ll i=0;i<n;i++){
                cin>>a[i];
                if(map1.find(a[i])==map1.end()){
                    if(map2.find(a[i])==map2.end()){
                        map2[a[i]]=0;
                    }
                    map1[a[i]]=1;
                }
                else map1[a[i]]++;
                umap[a[i]]++;
        }
        for(ll i=0;i<n;i++){
            cin>>b[i];
            if(map2.find(b[i])==map2.end()){
                if(map1.find(b[i])==map1.end()){
                        map1[b[i]]=0;
                    }
                    map2[b[i]]=1;
                }
            else map2[b[i]]++;
            umap[b[i]]++;
        }
        ll flag=0;
        for(auto itr=umap.begin();itr!=umap.end();itr++){
            if((itr->second)%2!=0){
                    flag=1;
                    break;
            }
           // cout<<itr->first<<" "<<itr->second<<"\n";
        }
        if(flag==1){
            cout<<"-1\n";
            
        }
        else{
        ll cost=0;
        auto itr1=map1.begin();
        ll min4=itr1->first;
        vector<ll> u;
		vector<ll> v;

		for(auto i:map1){
			ll x = i.first;
			if((map1[x] - map2[x]) > 0){
				for(ll j=0;j<(map1[x]-map2[x])/2;j++){
					u.pb(x);
				}
			}
		}

		for(auto i:map2){
			ll x = i.first;
			if((map2[x] - map1[x]) > 0){
				for(ll j=0;j<(map2[x]-map1[x])/2;j++){
					v.pb(x);
				}
			}
		}		

		sort(u.begin(),u.end());
		sort(v.begin(),v.end(),greater<ll>());
		for(ll i=0;i<u.size();i++){
			cost = cost + min(min(u[i],v[i]),2*min4);
		}

        cout<<cost<<"\n";
        }
}
int main(){
    fastio
    ll t;
    cin>>t;
    while(t--){
       solve();
    }
}