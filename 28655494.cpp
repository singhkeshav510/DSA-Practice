#include<bits/stdc++.h>
using namespace std;
bool comp(long long int a, long long int b)
{
    return (a < b);
}
long long int palin(long long int * arr,long long int j , long long int k , long long int n , long long int m)
{
        long long int * curr = arr+j*m+k;
        long long int count = 0;

        long long int vd = n-j-1;
        long long int vu = j;
        long long int hr = m-k-1;
        long long int hl = k;

        long long int min = std::min({vd,vu,hr,hl},comp);
        for(long long int i=1;i<=min;i++)
        {
                if((*(curr+i*m)==*(curr-i*m))&&(*(curr+i)==*(curr-i)))
                {
                        count++;
                }
                else
                        break;
        }
        return count;
}
int main()
{
        long long int t;
        cin>>t;
        for(long long int i=0;i<t;i++)
        {
                long long int count=0;
                long long int n,m;
                cin>>n>>m;
                long long int mat[n][m];
                for(long long int j=0;j<n;j++)
                {
                        for(long long int k=0;k<m;k++)
                        {
                                cin>>mat[j][k];
                        }
                }
                for(long long int j=0;j<n;j++)
                {
                        for(long long int k=0;k<m;k++)
                        {
                                count++;
                                if(j!=0&&k!=0&&j!=n-1&&k!=m-1)
                                {
                                        long long int tot=palin((long long int*)mat,j,k,n,m);
                                        count = count+tot;
                                }
                        }
                }
                cout<<count<<"\n";
        }
}
