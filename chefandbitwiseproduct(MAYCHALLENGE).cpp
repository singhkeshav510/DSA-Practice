#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define lli long long int
#define vi vector<int>
#define vpii vector<pair<int,int> >
#define f first
#define s second
#define all(x) x.begin() , x.end()
#define mii map<int,int>
#define mod6 1000000007
#define setbits(x) __builtin_popcountll(x)
#define zerobits(x) __builtin_ctzll(x)
#define mk(arr,n,type) type *arr=new type[n]
#define w(x) int x;cin>>x;while(x--)
#define ps(x,y) fixed<<setprecision(y)<<x
#define FOR(i,a,n) for(int i = a;i<n;i++)
#define FORD(i,a,n) for(int i = a;i<=n;i++)
#define FORR(i,n,a) for(int i = n;i>=a;i--)
#define endl "\n"


int main() {
    w(x) {
        lli a,b,l,r,curr = 0;
        cin >>a>>b>>l>>r;
        vector<lli>arr;
        bool flag = true;

        for(lli i = 62;i>=0;i--) {
            lli p = (1LL << i);
            if((l&p) == (r&p) && flag) {
                curr += (r&p);
                continue;
            }
            if(flag) {flag = !flag;}
            if(r&p) {
                arr.pb(curr+p-1);
            }
            curr += (r&p);
        }
        arr.pb(r);
        arr.pb(l);
        sort(arr.begin(),arr.end());
        lli ans = arr[0];
        for(lli z : arr) {
            if((a&z)*(b&z) > (a&ans)*(b&ans)) {ans = z;}
        }
        for(lli i = 62;i>=0;i--) {
            lli p = (1LL << i);
            if((ans&p) == 0) {
                continue;
            }
            if((a&p) == 0 && (b&p) == 0 && ans-p >= l) {
                ans -=p;
            }
        }
        cout<<ans<<endl;
        
    }
    return 0;
}

