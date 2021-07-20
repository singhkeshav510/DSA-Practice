#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
	ll t;
	cin>>t;
	for(ll i=0;i<t;i++)
	{
		ll n,x;
		cin>>n>>x;
		ll arr[n];
		for(ll j=0;j<n;j++)
			cin>>arr[j];
		ll count=0;
		sort(arr,arr+n);
		int flag=0;
		for(ll j=0;j<n;j++)
		{
			if(arr[j]<x)
				count++;
			else
			{
				if(arr[j]==x)
				{
					count++;
					if(flag==0)
						flag=2;
				}
				else
				{
					while(arr[j]>x)
					{
						count++;
						x=x*2;
						if(flag==0)
							flag=1;
					}
					x=arr[j];
				}
			}
		}
		if(flag==1)
			cout<<count+1<<"\n";
		else
			cout<<count<<"\n";
	}
}
