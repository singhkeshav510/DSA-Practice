#include<bits/stdc++.h>
using namespace std;
#define ll long long
void partition3(vector<ll> &a, int l, int r, int &i, int &j) 
{   i = l-1, j = r; 
    int p = l-1, q = r; 
    int v = a[r]; 
    while (true) 
    {
        while (a[++i] < v); 
        while (v < a[--j]) 
            if (j == l) 
                break; 
        if (i >= j) break; 
        swap(a[i], a[j]); 
        if (a[i] == v) 
        { 
            p++; 
            swap(a[p], a[i]); 
        }
        if (a[j] == v) 
        { 
            q--; 
            swap(a[j], a[q]); 
        } 
    } 
    swap(a[i], a[r]); 
    j = i-1; 
    for (int k = l; k < p; k++, j--) 
        swap(a[k], a[j]); 
    i = i+1; 
    for (int k = r-1; k > q; k--, i++) 
        swap(a[i], a[k]); 
} 

void randomized_quick_sort(vector<ll> &a, int l, int r) {
  if(r<=l)return;
  int i,j;
  partition3(a, l, r,i,j);
  randomized_quick_sort(a, l,j);
  randomized_quick_sort(a, i, r);
}

int main() {
  int n;
  cin >> n;
  vector<ll> a(n);
  for (int i = 0; i<n; ++i) {
    cin>>a[i];
  }
  randomized_quick_sort(a, 0, a.size()-1);
  for (int i=0;i<n;++i) {
    cout<<a[i]<<' ';
  }
}
