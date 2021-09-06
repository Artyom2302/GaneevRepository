#include <iostream>//in out �����
#include <vector>//������ � ������������� ���������
#include <sstream>// ��� ������ �� �������� getline()
#include <clocale>// ��� �������� �����
#include  <conio.h>// ��� ����� � ���������� _getch()
#include <cstring> //
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
	unsigned int workshops;
	unsigned int workshopsinwork;
	double performance;
	
};
//������� ��������
bool checkint(string s) {
	if ((s.size() != 0) && (s[0] != '0')) {
		for (size_t i = 0; i < s.size(); i++)
		{
			if (isdigit(s[i]))
			{
				continue;
			}
			else {
				return false;
			}

		}
		return true;
	}
	else
	{
		return false;
	}
}
bool checkfloat(string s) {
	if ((s.size() != 0) && (s[0] != '0')) {
		int tochka = 0;
		for (size_t i = 0; i < s.size(); i++)
		{
			if (s[i] == '.') {//�������� �� �����
				tochka += 1;
			}
			if (tochka > 1) {// ������� ���� ����� ������ �����
				return false;
			}
			if (isdigit(s[i])||(s[i]=='.'))
			{
				continue;
			}
			else {
				return false;
			}

		}
		return true;
	}
	else
	{
		return false;
	}
}
//bool checkid ( ){
//
//
//}
//�������� ������� ���� ������ �����
void addpipe(vector <pipe>& pipesf) //pipesf -������ ���� ��� �������
{
	system("cls");
	pipesf.resize(pipesf.size()+1);
	//c������ ���������� ���� string ��� ���������� � ������� 
	string value1;
	
	cout << "������� ID: ";
	while (true){
		getline(cin, value1);
		if (checkint(value1) ){
			pipesf[pipesf.size() - 1].id = stoi(value1);
			break;
		}
		else
		{
			cout << "������� �������� ����� !!! ID:  ";
		}
	}
	
	cout << endl << "������� �����: " ;
	while (true) {
		getline(cin, value1);
		if (checkfloat(value1)) {
			pipesf[pipesf.size() - 1].length = stoi(value1);
			break;
		}
		else
		{
			cout << "������� �������� ����� !!! �����:  ";
		}
	}
	
	cout << endl << "������� �������: ";
	while (true) {
		getline(cin, value1);
		if (checkfloat(value1)) {
			pipesf[pipesf.size() - 1].diameter = stoi(value1);
			break;
		}
		else
		{
			cout << "������� �������� ����� !!! �������:  ";
		}
	}
	cout << endl << "������� 1,���� ����� � ������� ��� "  
		<< "������� 0,���� ����� � ��������� ��� �����������: " ;
	while (true)
	{
		getline(cin, value1);
		if (value1 != "1" && value1 != "0")
		{
			cout << "������� ���� 0(���� ����� � ��������� ��� ����������� ���������), ���� 1(���� ����� � �������) ";
		}
		else {
			if (value1=="1")
			{
				pipesf[pipesf.size() - 1].repair = true;
				
			}
			else {
				pipesf[pipesf.size() - 1].repair = false;
			
			}
			break;
		
		}
		
	}

	
}
void mainmenu()
	{
	cout << "1. �������� �����" << endl <<
		"2. �������� ��" << endl <<
		"3. �������� ���� ��������" << endl <<
		"4. ������������� �����" << endl <<
		"5. ������������� ��" << endl <<
		"6. ���������" << endl <<
		"7. ���������" << endl <<
		"0. �����" << endl;
	}

int main() {
	setlocale(LC_CTYPE, "rus");//��������� �������� ����� 
	//c������� ���� link="http://www.c-cpp.ru/content/getch-getche"
	int menustatus;
	bool join,quit;
	vector <pipe> pipes ;
	pipes.resize(0);
	while (true)
	{
		system("cls");
		mainmenu();
		menustatus = _getch();
		while (true)
		{
			switch (menustatus)
			{
			case 49:
				addpipe(pipes);
				join = true;
				break;
			case 50:
				break;
			case 51:
				break;
			case 52:
				break;
			case 53:
				break;
			case 54:
				break;
			case 55:
				break;
			case 56:
				break;
			default:
				join = true;
				break;
			}
			if (join) {
				break;
			}
			
		}

		
	
	}
	
	
	_getch();
	return 0;
	
}
