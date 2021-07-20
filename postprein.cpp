#include<bits/stdc++.h>
using namespace std;
int search(int in[],int t,int n){
	for(int i=0;i<n;i++){
		if(in[i]==t)
			return i;
	}
}
void postorder(int in[],int pre[],int p){
	int r=search(in,pre[0],p);
	if(r!=0){
		postorder(in,pre+1,r);}
	if(r!=p-1)
		postorder(in+r+1,pre+r+1,p-r-1);
	cout<<pre[0];


}
int main(){
	int in[]={4,2,5,1,3,6},pre[]={1,2,4,5,3,6};
	int p=sizeof(in)/sizeof(int);
	postorder(in,pre,p);
}
