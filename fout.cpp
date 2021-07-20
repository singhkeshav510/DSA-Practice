#include<iostream>
#include<fstream>
using namespace std;
int main(){
	ofstream fout;
	fout.open("mydata.txt");
	fout << "This is the testing of  the file";
	fout.close();
}
	
