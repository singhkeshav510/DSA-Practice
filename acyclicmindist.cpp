#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
class Graph{
    ll N;
    vector<ll> *adj;
    vector<ll> d;
    public:
    Graph(ll);
    void add_edge(ll,ll);
    ll graphdiff(ll ,ll);
    void value();
    void pathNodes(ll u,ll v,vector<ll>,bool*);
};
Graph::Graph(ll n){
    this->N=n;
    adj=new vector<ll>[n];
}

void Graph::add_edge(ll u,ll v){
  adj[u].push_back(v);
  adj[v].push_back(u);
}

void Graph::value(){
    ll c;
    for(ll i=0;i<N;i++){
        cin>>c;
        d.push_back(c);
    }
}

ll Graph::graphdiff(ll u,ll v){
    bool *visit=new bool[N];
    for(ll i=0;i<N;i++){
        visit[i]=false;
    }
    vector<ll> diff;
    pathNodes(u,v,diff,visit); 
    ll min=INT_MAX;
    for(ll i=0;i<diff.size()-1;i++){
        for(ll k=i+1;k<diff.size();k++){
                if(d[diff[i]]!=d[diff[k]]){
                    if(abs(d[diff[i]]-d[diff[k]])<min){
                            min=abs(d[diff[i]]-d[diff[k]]);
                    }
                }
        }
    }  
    return min; 
}

void Graph::pathNodes(ll u,ll v,vector<ll> diff,bool visited[]){
    visited[u]=true;
    diff.push_back(u);
     if (u == v){ 
        return;
    } 
    else { 
        vector<ll>::iterator i; 
        for (i = adj[u].begin(); i != adj[u].end(); ++i) 
            if (!visited[*i]) 
                pathNodes(*i, v, diff,visited); 
    }
    return; 
}
int main(){
    fastio
    ll t;
    cin>>t;
    while(t--){
        ll n,q;
        cin>>n>>q;
        Graph g(n);
        g.value();
        ll u,v;
        for(ll i=0;i<n-1;i++){
            cin>>u>>v;
            g.add_edge(u-1,v-1);
        }
        for(ll i=0;i<q;i++){
            cin>>u>>v;
            cout<<g.graphdiff(u-1,v-1)<<"\n";
        }
    }
}
