#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >>t;
    while(t-->0){
        vector<int> v;
        int n;
        cin>>n;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            v.push_back(x);
           
        }
        vector<int>::iterator it;
        it=v.begin();
        while(v.size()>=3){
            if(v[1]>=v[0]){
                if(v[2]>=v[1])
                    v.erase(it+1);
                else if(v[2]>=v[0])
                    v.erase(it+2);
                else v.erase(it);
            }
            else {
                if(v[2]>=v[0])
                    v.erase(it);
                else if(v[2]>=v[1])
                    v.erase(it+2);
                else v.erase(it+1);
            }
        }
        cout<<v[0]<<" "<<v[1];
        cout<<"\n";
    }
}