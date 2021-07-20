#include<iostream>
#include<string>
using namespace std;
int main()
{	
	int a,b;
	int *p=a;
	cout << "Enter the values" << "\n";
	cin >> a >> b;
	cout << "a=" <<a <<"\n"<< "b=" <<b<<"\n";
	
	cout << "pointer is " << p <<"\n";
	*p=b;
	cout << "pointer is " << p;
	return 0;
}
