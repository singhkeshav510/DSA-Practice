#include<bits/stdc++.h>
using namespace std;
int palindrome(unsigned int k)
{   unsigned r=0,rm;
	while(k != 0)
    {   rm =k%10;
        r=r*10+rm;
        k/= 10;
    }
	if(r==k)
		return 0;
	else
		return -1;

}
int dtb(unsigned int n)
{	unsigned int l=0,y;
	while(n!=0)
	{l=l*10+n%2;
	n/=10;
	}
	y=palindrome(l);
	return y;
}
int main()
{	unsigned int n;
	int i,j;
	cout << "enter the number";
	getchar();
	cin >> n;
	for(i=0;i<100;i++)
	{	++n;
		j=dtb(n);
		if(j==0)
		{  cout << "number just after it pl is"<<" "<< n;
			break;
		}
	}
	return 0;
}

	
