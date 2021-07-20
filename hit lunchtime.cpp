#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n,count=0,p,l=0,cc=0,k;
	    cin>>n;
	    int a[n],c[101]={0};
	    if(n%4==0&&n>=4){
	        for(int i=0;i<n;i++){
	            cin>>a[i];
	            c[a[i]]++;
	            }
	            k=n;
	        while(k-->=0){
	            if(c[a[k]]!=0)
	                cc++;
	        }
	        k=n;
	        int b[cc],op=0;
	        for(int i=0;i<n;i++){
	            if(c[a[i]]!=0){
	                b[op]=a[i];
	                op++;
	            }
	       }
	       
	        
	        if(c[a[0]]==n)
	                cout<<"-1\n";
	        p=n/4;
	        for(int i=0;i<n;i++){
	            if(c[a[i]]>p)
	                l=1;
	        }
	        if(l==0){
	            for(int i=0;i<cc;i++){
	                
	            }
	            
	        }
	        
	        
	        if(l==1)
	            cout<<"-1\n";
	   }
	   else
	        cout<<"-1\n";
	}
	  
    
	return 0;
}