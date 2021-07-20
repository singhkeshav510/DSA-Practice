#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
string dectobin(ll n) 
{   string s = bitset<64> (n).to_string(); 
    const auto loc1 = s.find('1'); 
    if(loc1 != string::npos) 
        return s.substr(loc1); 
    return "0"; 
} 
ll bintodec(string s){   
    ll n=0;
    for(ll i=0;i<s.length();i++){
        if(s[i]=="1")
            n+=pow(2,i);
    }
    return n; 
} 
ll binary_convert(ll mini,ll maxi){
    string binx=dectobin(mini),biny=dectobin(maxi);
    string binxy=binx+biny;
    string binyx=biny+binx;
    for(ll i=0;i<binxy.length();i++){
        if(binxy[i]=="1"&&binyx[i]=="1"){
            binxy[i]="0";binyx[i]="0";
        }
    }
    mini=bintodec(binxy);
    maxi=bintodec(binyx);
    return abs(maxi-mini);
}
int main(){
    fastio
    ll t;
    cin>>t;
    while(t--){
       ll n,mini=INT_MAX,maxi=INT_MIN,a;
       cin>>n;
       for(ll i=0;i<n;i++){
           cin>>a;
           mini=min(mini,a);
           maxi=max(maxi,a);
       }
       cout<<binary_convert(mini,maxi)<<"\n";
    }
}
