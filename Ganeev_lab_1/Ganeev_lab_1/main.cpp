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
bool checkint(string s) {
	if (!((s.size() != 0) && (s[0] != '0')))
		return false;
	
	for (size_t i = 0; i < s.size(); i++)
		if (!isdigit(s[i]))
			return false;

	return true;
}
bool checkfloat(string s) {
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

//�������� ������� ���� ������ �����
void addpipe(vector <pipe>& pipesf) //pipesf -������ ���� ��� �������
{
	system("cls");
	pipesf.resize(pipesf.size()+1);
	//c������ ���������� ���� string ��� ���������� � ������� 
	string value1;
	int key;
	cout << "������� ID: ";
	while (true){
		getline(cin, value1);
		for (size_t i = 0; i <pipesf.size(); i++){
			if ((value1)==to_string(pipesf[i].id))
			{
				key = 1;
				break;
			}
			else { key = 0; }
			}
			if (key == 1) {
				cout << "������� ��� ������������ ��������\nC����� �������������� id:";
				for (size_t i = 0; i < pipesf.size() - 1; i++)
				{
					cout << pipesf[i].id << endl;
				}
			}
			
			else{
				if (checkint(value1)) {
				pipesf[pipesf.size() - 1].id = stoi(value1); 
				break;
				}
				
			else
			{
				cout << "������� �������� ���������!!!";
			}
		}
		
	}
	
	cout << endl << "������� �����: " ;
	while (true) {
		getline(cin, value1);
		if (checkfloat(value1)) {
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
		if (checkfloat(value1)) {
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
	char value2;
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
void addpipe(vector <compressor>& compressorf) //compressorf-������ ���� ��� �������
{
	system("cls");
	compressorf.resize(compressorf.size() + 1);
	string value1;

	cout << "������� ID: ";
	while (true) {
		getline(cin, value1);
		for (size_t i = 0; i < compressorf.size(); i++)
		{
			if ((value1) == to_string(compressorf[i].id))
			{
				value1 = 1.1;
				break;
			}
		}
		if (checkint(value1)) {
			compressorf[compressorf.size() - 1].id = stoi(value1);
			break;
		}
		else
		{
			cout << "������� �������� ���������(ID ����� ���� �����,��� ��������� ����� ����� ����������� ��� ������������� �������) !!! ID:  ";
		}
	}

	cout << endl << "������� ���: ";
	getline(cin, compressorf[compressorf.size() - 1].name);
	cout << "";
	while (true) {
		getline(cin, value1);
		if (checkint(value1)) {
			compressorf[compressorf.size() - 1].id = stoi(value1);
			break;
		}
		else
		{
			cout << "������� �������� ���������(ID ����� ���� �����,��� ��������� ����� ����� ����������� ��� ������������� �������) !!! ID:  ";
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
void outinfo(vector <pipe>& pipes /*, vector <compressor>& compressor*/) {
	char menuexit;
do
{
	system("cls");
	cout.width(50);
	cout << "����� ����������\n";
	cout.width(45);
	cout << "�����\n";
	cout.width(20);
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
				
				break;
			case '3':
				outinfo(pipes);
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
