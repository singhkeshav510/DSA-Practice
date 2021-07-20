#include<bits/stdc++.h>//sum max
using namespace std;
void hourglass(int a[6][6])
{   int p[16],k=0,l;
    l=a[0][0];
    for(int i=0;i<4;i++)
      {  for(int j=0;j<4;j++)
        {
        p[k]=a[i][j]+a[i][j+1]+a[i][j+2]+a[i+1][j+1]+a[i+2][j]+a[i+2][j+1]+a[i+2][j+2];
            
        if(p[k]>l)
            l=p[k];
            k++;
        }
            
      }
      cout << l;

}
int main(){
    int ar[6][6];
    for(int i=0;i<6;i++)
        for(int j=0;j<6;j++)
            {
                cin >> ar[i][j];
            }
    hourglass(ar);
}

