#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

int main(){
    fastio
    ll t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        ll n=s.length(),q;
        cin>>q;
        ll a;
        while(q--){
            ll f=0,ans=0;
            cin>>a;
            stack<char> st;
            for(ll i=a-1;i<n;i++){
                if(st.empty()&&s[i]==')'){
                    continue;
                }

                if(s[i]=='('){
                    st.push(s[i]);
                }
                else{
                    char p=st.top();
                    st.pop();
                    if(st.empty()){
                        ans=i;
                        break;
                    }
                }
                
            }
            if(!st.empty())
                cout<<-1<<"\n";
            else cout<<ans+1<<"\n";
        }
        
    }
}