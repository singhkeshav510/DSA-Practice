#include<bits/stdc++.h>
using namespace std;
int* spiral(int m,int n,int a[][])
{	int s;
	s=m*n;
	int p[s]={0};
	int l=0,k=0,i,t=0;
	while (k < m && l < n) 
	{
        for (i = l; i < n; ++i) {
            p[t]=a[k][i];
	    t++;
		cout << a[k][i] << " ";
        }
        k++;
        for (i = k; i < m; ++i) {
            p[t]=a[i][n-1];
	    t++;
		cout << a[i][n - 1] << " ";
        }
        n--;
        if (k < m) {
            for (i = n - 1; i >= l; --i) {
                p[t]=a[m-1][i];
		t++;
		    cout << a[m - 1][i] << " ";
            }
            m--;
        }
        if (l < n) {
            for (i = m - 1; i >= k; --i) {
                p[t]=a[i][l];
		    cout << a[i][l] << " ";
            }
            l++;
        }
    }
	return p;
}

int main(){
	int r,c;
	cout << "enter the number of rows and columns";
	cin >> r >>c;
	int a[r][c],s;
	s=r*c;
	for(int i=0;i<r;i++)
		for(int j=0;j<c;j++)
			cin >> a[i][j];
	int* p=spiral(r,c,a);
	sort(p,p+s);
	cout << "sorted spiral form is :" << "\n";
	for(int i=0;i<s;i++)
		cout << p[i] << "\n";
	cout << "enter the number you want to search" << "\n";
	int x;
	cin >> x;
	if(binary_search(p,p + s,x))
		cout<<"element found";

}
