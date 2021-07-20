#include<bits/stdc++.h>
using namespace std;
int check(string p,string m,int index){
    int i=0;
    while(i!=p.length()&&index!=m.length()){
        if(p[i]<=m[index]){
            i++;index++;
        }
        else return 0;
    }
    return 1;
}
void solve(){
    string s,p,q="";
    cin>>s>>p;
    int n=s.length();
    int arr[26];
    memset(arr,0,sizeof(arr));
    for(int i=0;i<n;i++)
        arr[s[i]-97]+=1;
    for(int i=0;i<p.length();i++)
        arr[p[i]-97]=arr[p[i]-97]-1;
    char c;
    int i=0,f=0;
    string m="";
    while(i!=26){
        if(arr[i]>0){
            m+=(char)(i+97);
            arr[i]=arr[i]-1;
            if(arr[i]==0)
                i++;
        }
        else i++;
    }
    if(p[0]<m[0]){
        q=p+m;
        cout<<q<<"\n";
        return;
    }
    else{
        for(int i=0;i<m.length();i++){
            if(p[0]>m[i]){
                continue;
            }
    
            if(p[0]<m[i]){
                f=1;
                q=m.substr(0,i)+p+m.substr(i,m.length()-1);
                break;
            }
            else if(check(p,m,i)){
                         f=1;
                        q=m.substr(0,i)+p+m.substr(i,m.length());
                        break;
                }
        }
    }
    if(f==0){
        q=m+p;
    }
    cout<<q<<"\n";
    return;
}

int main(){
    int t;
    t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
