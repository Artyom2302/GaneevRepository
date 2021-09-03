#include <sstream>
#include <iostream>
#include <vector>
using namespace std;
void LearnTypes() {
	cout <<  endl << "please enter new value:";
	int x = 1;
	float f = 0;
	double d = 0;
	char ch = 'a';
	bool b = true;
	cin >> x;
	cout << endl << x + 1
		<< endl << x * 3
		<< endl << (double)x / 2. << endl;
	x += 2;//x=x+2;
	int a1 = x++;//x=x+1;
	int a2 = ++x;
	x = 7;
	cout << (x >> 1) << endl//111>>11
		<< (x << 1) << endl;//111<<1110
}
struct Student {
	string name;
	double score;
};
void hello() {
	string s;
	cout << "Type your name please ";
	getline(cin, s);
	cout << endl << "Hello , " << s << endl;
}
int main() 
{
	
	//LearnTypes();
	//hello
	int mass[5]= {1 , 2 ,3};//cтатический массив определенного размера
	vector <int> v;
	vector <Student> group ;
	size_t n=0;
	cin >> n;
	v.resize(n);
	group.resize(n);
	/*Student s = {"Ivan",5 };
	group[0] = s;
	s.score-=0.5;*///why?

	group[0] = { "Ivan",5 };
	group[0].score -= 0.5;
	return 0;
	
}