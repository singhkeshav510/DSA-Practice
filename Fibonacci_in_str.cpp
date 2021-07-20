#include<bits/stdc++.h>
using namespace std;
void print(int l,int m)
{       if(l==m)
        cout << "yes";
        else cout << "no";
}
void work(int t,string s)
{int n,k,l=0,m,a[61]={0};
for (int i=0;i<t;i++)
    {getchar();
        cout << "enter string";
    getline(cin,s);//getline() takes \n as input

      for(int j=0;j<s.length();j++)
      {if(s[j]>='a'&&s[j]<='z')
     { n=int(s[j])-97;
        a[n]++;}
        else if(s[j]>='1'&&s[j]<='2')
     { n=int(s[j])-92;
        a[n]++;}
        else if(s[j]>='A'&&s[j]<='Z')
     { n=int(s[j])-65;
        a[n]++;}
      }
      k=sizeof(s)/sizeof(s[0]);
      sort(a,a+k);
        for(int h=0;h<59;h++)
        {if(a[h]+a[h+1]!=a[h+2])
            break;
            else if(a[h]+a[h+1]==a[h+2])
                l++;
                m=h+1;
        }
        print(l,m);
      }
}

int main()
{   string s;
    int t;
    cout << " enter testcases";
    cin >> t;
    work(t,s);

        return 0;

}
