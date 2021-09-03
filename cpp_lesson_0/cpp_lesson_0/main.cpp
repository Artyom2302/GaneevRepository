#include <iostream>
using namespace std;
int main() 
{
	cout << "hello,World" << endl<<"please enter new value:";
	int x = 1;
	float f=0;
	double d=0;
	char ch = 'a';
	bool b = true;
	cin  >> x ;
	cout << endl << x + 1
	<< endl << x * 3
	 << endl << (double)x/2.<<endl;
	x += 2;//x=x+2;
	int a1=x++;//x=x+1;
	int a2=++x;
	x = 7;
	cout << (x >> 1) << endl;
	return 0;
	
}