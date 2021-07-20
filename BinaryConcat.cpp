#include <bits/stdc++.h> 
using namespace std; 
#define ll long long int

void decb(ll arr[], ll n) 
{ 
	ll k = log2(n); 
	while (n > 0) { 
		arr[k--] = n % 2; 
		n /= 2; 
	} 
} 
ll bind(ll arr[], ll n) 
{ 
	ll ans = 0; 
	for (ll i = 0; i < n; i++) 
		ans += arr[i] << (n - i - 1); 
	return ans; 
} 
// above functions are available on gfg well before
ll conc(ll m, ll n) 
{ 
	ll k = log2(m) + 1; 
	ll l = log2(n) + 1; 

	ll a[k] = { 0 }, b[l] = { 0 }; 

	
	ll c[k + l] = { 0 }; 
	decb(a, m); 
	decb(b, n); 
	ll in = 0; 
	for (ll i = 0; i < k; i++) 
		c[in++] = a[i]; 
	for (ll i = 0; i < l; i++) 
		c[in++] = b[i]; 
	return (bind(c, k + l)); 
} 

int main() 
{ 
    ll tc;
    ll n1;
    cin>>tc;
    for(ll j=0;j<tc;j++)
    {
        cin>>n1;
        ll arr[n1];
        ll maa=-100;
        ll maa1=-100;
        ll sa1,sa2;
        ll sa11,sa21;
        ll maa2=-100;
        for (ll i=0;i<n1;i++)
        {
            cin>>arr[i];
            maa=max(maa,arr[i]);
        }
        if(n1>900)
        {
            for(ll i=0;i<n1;i++)
            {
                sa1=conc(maa,arr[i]);
                sa2=conc(arr[i],maa);
                maa1=max(maa1,abs(sa1-sa2));
            }
            cout<<maa1<<endl;
        }
        else
        {
            for(ll i=0;i<n1;i++)
            {
                for(ll j=0;j<n1;j++)
                {
                    sa11=conc(arr[j],arr[i]);
                    sa21=conc(arr[i],arr[j]);
                    maa2=max(maa2,abs(sa11-sa21));
                }
            }
            cout<<maa2<<endl;
        }
    }
	return 0; 
}