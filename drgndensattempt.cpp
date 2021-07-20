#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
class Point{
    public:
    ll y;
    ll taste;
};
bool check(vector<Point> &v,ll xi,ll xf){
    ll max=v[xi].y;
    ll f=0;
    if(xi==xf){
        return true;
    }
    else if(xi>xf){
        for(ll i=xi-1;i>=xf;i--){
            if(max<=v[i].y&&xi!=xf){
                f=1;
            }
        }
        if(f==1)
            return false;
        return true;
    }
    else {
        for(ll i=xi+1;i<=xf;i++){
            if(max<=v[i].y&&xi!=xf){
                f=1;
            }
        }
        if(f==1)
            return false;
        return true;
    }
}
ll calculateTaste(vector<Point> &v,ll xi,ll xf){
    if(v[xi].y<=v[xf].y)
    return -1;
    if(xi==xf)
        return v[xi].taste;
    
    if(xi<xf){
        ll tastiness=0;
        if(check(v,xi,xf)){
            ll f=0;
            tastiness+=v[xi].taste;
            for(ll i=xi+1;i<xf;i++){
                if(check(v,i,xf)){
                    tastiness+=v[i].taste;
                }
                
            }
            tastiness+=v[xf].taste;
            return tastiness;
        }
        else return -1;
    }
    else{
        ll tastiness=0;
        if(check(v,xi,xf)){
            ll f=0;
            tastiness+=v[xi].taste;
            for(ll i=xi-1;i>xf;i--){
                if(check(v,i,xf)){
                    tastiness+=v[i].taste;
                }
            }
            tastiness+=v[xf].taste;
            return tastiness;
        }
        else return -1;
    }
}
int main(){
    fastio
    ll n,q;
    cin>>n>>q;
    vector<Point> v(n+1);
    for(ll i=1;i<=n;i++){
        cin>>v[i].y;
    }
    for(ll i=1;i<=n;i++){
        cin>>v[i].taste;
    }
    for(ll i=0;i<q;i++){
        ll cas,b,c;
        cin>>cas;
        if(cas==1){
            cin>>b>>c;
            v[b].taste=c;
        }
        else {
            cin>>b>>c;
            cout<<calculateTaste(v,b,c)<<"\n";
        }
    }
    return 0;
}