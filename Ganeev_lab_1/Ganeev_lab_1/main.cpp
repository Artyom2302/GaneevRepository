#include <iostream>
#include <vector>
#include <sstream>
#include <clocale>
using namespace std;
//C������� ��������� �����
struct pipe {
	unsigned int id;
	double length,
		diameter;
	bool repair;
};
//C������� ��������� ������������� �������
struct compressor {
	unsigned int id;
	string name;
	unsigned int allworkshops;
	unsigned int workshopsinwork;
	double performance;
	
};

int main() {
	setlocale(LC_CTYPE, "rus");//��������� �������� ����� 
	//c������� ����
	cout << "1. �������� �����" << endl<<
		"2. �������� ��" << endl <<
		"3. �������� ���� ��������" << endl <<
		"4. ������������� �����" << endl <<
		"5. ������������� ��" << endl <<
		"6. ���������" << endl <<
		"7. ���������" << endl <<
		"0. �����" << endl ;
	int button;
	cin >>button ;
	if (button==0)
	{
		exit(0);
	}
	return 0;
}