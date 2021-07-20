#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
	ll t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		unordered_map<char,int>um,um2;
		string a,b;
		cin>>a>>b;
		string c,d;
		sort(a.begin(),a.end());
		for(int i=0;i<b.length();i++)
			um[b[i]]++;
		for(int i=0;i<a.length();i++)
		{
			if(um.find(a[i])==um.end())
			{
				if((int)a[i]<=(int)b[0])
					c+=a[i];
				else
					d+=a[i];
			}
			else
			{
				if(um2.find(a[i])==um2.end() || um2[a[i]]<um[a[i]])
					um2[a[i]]++;
				else
				{
					if((int)a[i]<=(int)b[0])
         	                               c+=a[i];
	                                else
                	                        d+=a[i];
				}
			}
		}
		string ans = c+b+d;
		cout<<ans<<"\n";
	}
}

