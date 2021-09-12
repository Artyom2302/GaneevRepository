#include <iostream>//in out �����
#include <vector>//������ � ������������� ���������
#include <sstream>// ��� ������ �� �������� getline()
#include <clocale>// ��� �������� �����
#include  <conio.h>// ��� ����� � ���������� _getch()
#include <cstring> //
#include <iomanip>//��������������� �����
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
	unsigned int workshops;//����
	unsigned int workshopsinwork;//���� � ������
	double performance;//�������������
	};
//������� ��������
bool CheckInt(string s) {
	if (!((s.size() != 0) && (s[0] != '0')))
		return false;
	
	for (size_t i = 0; i < s.size(); i++)
		if (!isdigit(s[i]))
			return false;

	return true;
}


bool CheckFloat(string s) {
	if ((s.size() == 0) || (s[0] == '0')) {
		return false;
	}
	int tochka = 0;
	for (size_t i = 0; i < s.size(); i++)
	{
		if (s[i] == '.') {//�������� �� �����
			tochka += 1;
		}
		if (tochka > 1) {// ������� ���� ����� ������ �����
			return false;
		}
		if (!(isdigit(s[i]) || (s[i] == '.')))
			return false;
	}
	return true;
}


bool CheckPipeId(string value, vector <pipe>& pipesf) {
	
	for (size_t i = 0; i < pipesf.size(); i++) {
		if ((value) == to_string(pipesf[i].id))
		{
			return  true;
			break;
		}
	}
	return false;
}

bool CheckCompressorId(string value, vector <compressor>& compressorf) {
	for (size_t i = 0; i < compressorf.size(); i++) {
		if ((value) == to_string(compressorf[i].id))
		{
			return  true;
			break;
		}
	}
	return false;

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
		"8. ���� 8" << endl <<
		"0. �����" << endl;
	}

void addpipe(vector <pipe>& pipesf) //pipesf -������ ���� ��� �������
{ 
	string value1;
	int key;
	char value2;

	system("cls");
	pipesf.resize(pipesf.size() + 1);
	
	
	cout << "������� ID: ";
	while (true) {
		getline(cin, value1);	
		if (CheckPipeId(value1,pipesf))
		{
			cout << "����� ID ��� ����������\n������ ������������ ID: ";
			for (size_t i = 0; i < pipesf.size()-1; i++)
			{
				cout << pipesf[i].id<< " ";
			}
		}
		else {
			if (CheckInt(value1)) {
				pipesf[pipesf.size() - 1].id = stoi(value1);
				break;
			}
			else {
				cout << "\n������� ������������� �����: ";
			}
		}

	}

	cout << endl << "������� �����: " ;
	while (true) {
		getline(cin, value1);
		if (CheckFloat(value1)) {
			pipesf[pipesf.size() - 1].length = stod(value1);
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
		if (CheckFloat(value1)) {
			pipesf[pipesf.size() - 1].diameter = stod(value1);
			break;
		}
		else
		{
			cout << "������� �������� ����� !!! �������:  ";
		}
	}
	cout << endl << "������� 1,���� ����� � ������� ��� "  
		<< "������� 0,���� ����� � ��������� ��� �����������: \n" ;
	
	while (true)
	{
		
		value2 = _getch();
		if (value2 != '1' && value2 != '0')
		{
			cout << "������� ���� 0(���� ����� � ��������� ��� ����������� ���������), ���� 1(���� ����� � �������) \n";
		}
		else {
			if (value2=='1')
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
void addcompressor(vector <compressor>& compressorf) //compressorf-������ ���� ��� �������
{
	system("cls");
	compressorf.resize(compressorf.size() + 1);
	string value1;

	cout << "������� ID: ";
	while (true) {
		getline(cin, value1);
		if (CheckCompressorId(value1, compressorf))
		{
			cout << "����� ID ��� ����������\n������ ������������ ID: ";
			for (size_t i = 0; i < compressorf.size() - 1; i++)
			{
				cout << compressorf[i].id << " ";
			}
		}
		else {
			if (CheckInt(value1)) {
				compressorf[compressorf.size() - 1].id = stoi(value1);
				break;
			}
			else {
				cout << "\n������� ������������� �����: ";
			}
		}

	}

	cout << endl << "������� ���: ";
	getline(cin, compressorf[compressorf.size() - 1].name);

	cout << "������� ����� ���������� �����: ";
	while (true) {
		getline(cin, value1);
		if (CheckInt(value1)) {
			compressorf[compressorf.size() - 1].workshops = stoi(value1);
			break;
		}
		else
		{
			cout << "������� ������������� �����: ";
		}
	}
	
	cout << "�������  ���������� ����� � ������: ";
	while (true) {
		getline(cin, value1);
		if (CheckInt(value1) && (stoi(value1) <= compressorf[compressorf.size() - 1].workshops)) {
			compressorf[compressorf.size() - 1].workshopsinwork = stoi(value1);
			break;
		}
		else
		{
			cout << "������� ������������� �����,�� ����������� ���������� ������� �����: ";
		}
	}
	
	
	cout << endl << "������� �������������: ";
	while (true) {
		getline(cin, value1);
		if (CheckFloat(value1)) {
			compressorf[compressorf.size() - 1].performance = stod(value1);
			break;
		}
		else
		{
			cout << "������� �������� ����� !!! �������������:  ";
		}
	}
}
void outinfo(vector <pipe>& pipes , vector <compressor>& compressor) {
	char menuexit;
do
{
	system("cls");

	cout.width(50);
	cout << "����� ����������\n";

	cout << "�����\n";
	cout << setw(10) << "Id " << setw(20) << "�����" << setw(20) << "�������" << setw(40) << "���������(� ������� ��� ���)\n";


	for (size_t i = 0; i < pipes.size(); i++)
	{
		cout << setw(10) << pipes[i].id << setw(20) << pipes[i].length << setw(20) << pipes[i].diameter;

		if (pipes[i].repair) {
			cout << setw(40) << "� �������\n";
		}
		else
		{
			cout << setw(40) << "� ������������\n";
		}

	}


	for (size_t i = 0; i < 100; i++)
	{
		cout << "-";
	}
	cout << "\n������������� �������\n";

	cout << setw(10) << "Id " << setw(20) << "��������" << setw(30) << "����� ���������� �����"
		<< setw(30) << "���������� ����� � ������" << setw(20) << "�������������" <<  endl;


	for (size_t i = 0; i < compressor.size(); i++)
	{
		cout << setw(10) << compressor[i].id << setw(20) << compressor[i].name << setw(30) << compressor[i].workshops<<setw(30)
			<< compressor[i].workshopsinwork << setw(20)<<compressor[i].performance<<endl;
		
	}
	cout << "\n\n��� ���������� � ���� ������� 0";
	
	menuexit = _getch();

} 
while (menuexit!='0');
}



int main() {
	setlocale(LC_CTYPE, "rus");//��������� �������� ����� 
	//c������� ���� link="http://www.c-cpp.ru/content/getch-getche"
	

	int menustatus;
	bool join,quit;
	vector <pipe> pipes ;
	pipes.resize(0);
	vector <compressor> compressor;
	compressor.resize(0);
	

	join = false;
	quit = false;
	while (true)
	{
		system("cls");
		mainmenu();
		menustatus = _getch();
		while (true) //mainmenu
		{
			switch (menustatus)
			{//submenus
			case '1':
				addpipe(pipes);
				join = true;
				break;

			case '2':
				addcompressor(compressor);
				join = true;
				break;

			case '3':
				outinfo(pipes, compressor);
				join = true;
				break;
			case '4':
				break;

			case '5':
				break;

			case '6':
				break;

			case '7':
				break;

			case '8':
				break;

			case '0':
				join = true;
				quit = true;
				break;
			default:
				join = true;
				break;
			}
			if (join) {
				if (quit) {

					exit(0);
				}
			break;
			}
				
		}
	}
	_getch();
	return 0;
	
}
