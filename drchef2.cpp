#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
int main()
{fastio
 int test;
 cin>>test;
 while(test--)
 {
  int n;
  cin>>n;
  ll x;
  cin>>x;
  ll ar[n+1];
  for(int i=0;i<n;i++)
  {
   cin>>ar[i];

  }
  bool v[n+1]={0};
  for(int i=0;i<n;i++)v[i]=0;
  sort(ar,ar+n);
  ll tm=ar[n-1]*2,as=0;
  while(tm>x)
  {
   as++;
   tm=(tm+1)/2;
   ll po=lower_bound(ar,ar+n,tm)-ar;
   if(!v[po])
   {
    tm=ar[po];
    v[po]=1;
   }

  }
  for(int i=0;i<n;i++)
  {
   if(!v[i])
   as++;
  }
  cout<<as<<endl;
 
  
 }
 return 0;
}