#include <iostream>//in out �����
#include <vector>//������ � ������������� ���������
#include <sstream>// ��� ������ �� ��������
#include <clocale>// ��� �������� �����
#include  <conio.h>// ��� ����� � ����������
#include <cstring>
#include <string>
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
//�������� ������� ���� ������ �����
void addpipe(vector <pipe>& pipesf) //pipesf -������ ���� ��� �������
{
	system("cls");
	pipesf.resize(pipesf.size()+1);
	//c������ ���������� ���� string ��� ���������� � ������� 
	string value1;
	
	
	while (true){
		cout << "������� ID: ";
		getline(cin, value1);
		if (checkint(value1) ){
			pipesf[pipesf.size() - 1].id = stoi(value1);
			break;
		}
		else
		{
			cout << "������� �������� ����� !!! \n";
		}
	}
	
	cout << endl << "������� �����: " ;
	cin >> pipesf[pipesf.size()-1].length;
	cout << endl << "������� �������: ";
	cin >> pipesf[pipesf.size()-1].diameter;
	cout << endl << "������� 1,���� ����� � ������� ��� " ;
	cout << "������� 0,���� ����� � ��������� ��� �����������: " ;
	cin >> pipesf[pipesf.size()-1].repair;
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
				cout << "������� ���� �� ������������� ���� ������!!!";
				break;
			}
			
			
		}

		
	
	}
	
	
	_getch();
	return 0;
	
}