#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	ll t;
	t=1;
	cin>>t;
	while(t--){
		string a,b;
		cin>>a>>b;
		ll n=a.length(),m=b.length();
		unordered_map<char,ll> umap1;
		ll p=n-m;
		for(ll i=0;i<n;i++){
			umap1[a[i]]++;
		}
		for(ll i=0;i<m;i++){
			--umap1[b[i]];
			if(umap1[b[i]]==0)
				umap1.erase(b[i]);
		}
		string c,d;
		for(auto& itr:umap1){
			ll count=itr.second;
			for(ll i=0;i<count;i++)
				c=c+itr.first;
		}
		sort(c.begin(),c.end());
		char l='a';
		for(ll i=0;i<b.length();i++){
			if(b[i]>l)
				l=b[i];
		}
		ll i=0;
		while(i!=p){
			if(b[0]>c[i]){
				d=d+c[i];
				i++;
			}
			else if(b[0]<c[i]){
				d=d+b+c.substr(i,p);
				break;
			}
			else{	if(l>c[i]){	
					d=d+c[i];
					i++;
				}
				else{
					d=d+b+c.substr(i,p);
					break;
				}
			}
		}
		if(n!=d.length())
			d=d+b;

		cout<<d<<"\n";
	}
}
