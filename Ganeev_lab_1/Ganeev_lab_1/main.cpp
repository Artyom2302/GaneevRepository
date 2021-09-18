#include <iostream>//in out �����
#include <vector>//������ � ������������� ���������
#include <sstream>// ��� ������ �� �������� getline()
#include <clocale>// ��� �������� �����
#include  <conio.h>// ��� ����� � ���������� _getch()
#include <cstring> //
#include <iomanip>//��������������� �����
#include <fstream>
#include <cstdlib>// rand



using namespace std;

//C������� ��������� �����
struct pipe {
	unsigned int id, diameter;
	double length;
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

int RandomId() {
	return rand();
}

bool CheckDouble(string s) {
	if (s.size() == 0)  {
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


bool CheckPipeId(int value,const vector <pipe>	&pipesf) {
	
	for (size_t i = 0; i < pipesf.size(); i++) {
		if (value ==pipesf[i].id)
		{
			return  true;
			break;
		}
	}
	return false;
}

bool CheckCompressorId(int value,const vector <compressor> &compressorf) {
	for (size_t i = 0; i < compressorf.size(); i++) {
		if (value == compressorf[i].id)
		{
			return  true;
			break;
		}
	}
	return false;

}

void MainMenu()
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

pipe AddPipe(const vector <pipe>& pipes) //���������� 
{ 
	string value1;
	int key;
	char value2;
	pipe p;

	
	do
	{
		p.id = rand();
	} while ((CheckPipeId(p.id,pipes)));
	

	cout<<"�����\nID �"<<p.id

	 << endl << "������� �����: " ;//�������� �� do while 

	do {
		getline(cin, value1);

		if (!(CheckDouble(value1))) {
			
			cout << "�������� ������� �������\n������� ��� ���: ";
		}

	} while (!(CheckDouble(value1)));
	p.length = stod(value1);

	/*while (true) {
		getline(cin, value1);
		if (CheckFloat(value1)) {
			p.length = stod(value1);
			break;
		}
		else
		{
			cout << "������� �������� ����� !!! �����:  ";
		}
	}*/
	
	cout << endl << "������� �������: ";
	do {
		getline(cin, value1);

		if (!(CheckInt(value1))) 
		{	
			cout << "�������� ������� �������\n������� ��� ���: ";
		}

	} while (!(CheckInt(value1)));

	p.diameter = stoi(value1);


	/*while (true) {
		getline(cin, value1);
		if (CheckInt(value1)) {
			p.diameter = stoi(value1);
			break;
		}
		else
		{
			cout << "������� �������� ����� !!! �������:  ";
		}
	}*/
	cout << endl << "������� 1,���� ����� � ������� ��� "  
		<< "������� 0,���� ����� � ��������� ��� �����������: \n" ;
	
	do
	{
		value2 = _getch();

		if (value2 != '0' && value2 != '1') {cout << "������� ������� �����!!!\n";}

	} while (value2 != '0'  && value2 != '1');
	
	value2 == '1' ? p.repair = true : p.repair = false;
	/*while (true)
	{
		
		value2 = _getch();
		if (value2 != '1' && value2 != '0')
		{
			cout << "������� ���� 0(���� ����� � ��������� ��� ����������� ���������), ���� 1(���� ����� � �������) \n";
		}
		else {
			if (value2=='1')
			{
				p.repair = true;	
			}
			else {
				p.repair = false;
			}
			break;
		
		}
		
	}*/
	return p;
	
}

compressor AddCompressor( const vector <compressor>	&compressors)
{
	compressor comp ;
	string value;
	do
	{
		comp.id = rand();
	} while ((CheckCompressorId(comp.id, compressors)));

	cout << endl << "������� ���: ";
	getline(cin, comp.name);

	cout << "������� ����� ���������� �����: ";
	/*while (true) {
		getline(cin, value1);
		if (CheckInt(value1)) {
			compressor[compressor.size() - 1].workshops = stoi(value1);
			break;
		}
		else
		{
			cout << "������� ������������� �����: ";
		}
	}*/

	do
	{
		getline(cin, value);
		if (!(CheckInt(value)))
		{
			cout << "������� ������������� �����!!!\n ";
		}

	} while (!(CheckInt(value)));
	comp.workshops = stoi(value);
	
	
	cout << "�������  ���������� ����� � ������: ";
	/*while (true) {
		getline(cin, value1);
		if ((CheckInt(value1) && (stoi(value1) <= compressor[compressor.size() - 1].workshops))||value1=="0") {
			compressor[compressor.size() - 1].workshopsinwork = stoi(value1);
			break;
		}
		else
		{
			cout << "������� ������������� �����,�� ����������� ���������� ������� �����: ";
		}
	}*/
	
	
	do
	{	getline(cin, value);
			if (!((CheckInt(value) && (stoi(value) <= comp.workshops)) || value == "0"))
				{
				cout << "������� ������������� �����,�� ����������� ���������� ������� �����!!!\n";
				}

	} while (!((CheckInt(value) && (stoi(value) <= comp.workshops)) || value == "0"));
	comp.workshopsinwork = stod(value);
	
	cout << endl << "������� ������������� � %: ";
	/*while (true) {
		getline(cin, value);
		if (CheckDouble(value)&& stod(value)<100 &&stod(value)>10) {
			comp.performance = stod(value);
			break;
		}
		else
		{
			cout << "������� �������� ����� !!! �������������:  ";
		}
	}*/
	do
	{
		getline(cin, value);
		if (!(CheckDouble(value) && stod(value) < 100 && stod(value) > 10))
		{
			cout << "������� �������� ����� !!! �������������:  ";
		}

	} while (!(CheckDouble(value) && stod(value) < 100 && stod(value) > 10));
	comp.performance = stod(value);
	return comp;
}

void OutInfo(vector <pipe>& pipes , vector <compressor>& compressors) {
	char menuexit;

do
{

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


	for (size_t i = 0; i < compressors.size(); i++)
	{
		cout << setw(10) << compressors[i].id << setw(20) << compressors[i].name << setw(30) << compressors[i].workshops<<setw(30)
			<< compressors[i].workshopsinwork << setw(20)<<compressors[i].performance<<endl;
		
	}
	
	cout << "\n\n��� ���������� � ���� ������� 0";
	
	menuexit = _getch();

} 

while (menuexit!='0');
}

int SearchPipeIdIndex(vector <pipe>& pipes,int value) {
	for (size_t i = 0; i < pipes.size() - 1; i++)
	{
		if (pipes[i].id == value)
		{
			return i;
			break;
		}
	}
	return 0;
}

int SearchCompressorIdIndex(vector <compressor>& compressors, int value) {
	for (size_t i = 0; i < compressors.size() - 1; i++)
	{
		if (compressors[i].id == value)
		{
			return i;
			break;
		}
	}
	return 0;
}

void EditPipe(vector <pipe>& pipes) {
	string value;
	char value2;
	int pipeindex ;
	system("cls");
	do
	{
		cout << "������� ID �����,������� ������ ��������: ";
		getline(cin,value);
		if (CheckInt(value))
		{
			pipeindex = SearchPipeIdIndex(pipes, stoi(value));
			break;
		}
		else 
		{
			"������� ����� �������� id: ";
		}

	} while (true);
	/*cout << endl << "������� 1,���� ����� � ������� ��� "
		<< "������� 0,���� ����� � ��������� ��� �����������: \n";
	
	
	while (true)
	{
		value2 = _getch();
		if (value2 != '1' && value2 != '0')
		{
			cout << "������� ���� 0(���� ����� � ��������� ��� ����������� ���������), ���� 1(���� ����� � �������) \n";
		}
		else {
			if (value2 == '1')
			{
				pipes[pipeindex].repair = true;
			}
			else {
				pipes[pipeindex].repair = false;
			}
			break;

		}

	}*/
	
	if (pipes[pipeindex].repair)
	{
		do
		{	cout << "����� ������ ��������� � ������� ��� ��������� � ��������� ������� 0";
			value2 = _getch();
		} while (value2!='0');
		pipes[pipeindex].repair = false;
	}
	else
	{
		do
		{
			cout << "����� ������ ��������� � ����������� ��� ��������� � ��������� ������� 1";
			value2 = _getch();
		} while (value2 != '1');
		pipes[pipeindex].repair = true;
	}

	
	
}

void EditCompressor(vector <compressor> compressors) {
	string value;
	char value2;
	int compressorindex;
	system("cls");
	do
	{
		cout << "������� ID ����������� ,� ������� ������ ��������: ";
		getline(cin, value);
		if (CheckInt(value))
		{
			compressorindex = SearchCompressorIdIndex(compressors, stoi(value));
			break;
		}
		else
		{
			"������� ����� �������� id: ";
		}
	
	} while (true);

}

void Saveinfo(const vector <pipe>  &pipes,const vector <compressor> &compressors) {
	ofstream fout;
	fout.open("data.txt",'w');
	fout << "����� ����������\n";

	fout << "�����\n";
	fout << setw(10) << "Id " << setw(20) << "�����" << setw(20) << "�������" << setw(40) << "���������(� ������� ��� ���)\n";


	for (size_t i = 0; i < pipes.size(); i++)
	{
		fout << setw(10) << pipes[i].id << setw(20) << pipes[i].length << setw(20) << pipes[i].diameter;

		if (pipes[i].repair) {
			fout << setw(40) << "� �������\n";
		}
		else
		{
			fout << setw(40) << "� ������������\n";
		}

	}


	for (size_t i = 0; i < 100; i++)
	{
		fout << "-";
	}
	fout << "\n������������� �������\n";

	fout << setw(10) << "Id " << setw(20) << "��������" << setw(30) << "����� ���������� �����"
		<< setw(30) << "���������� ����� � ������" << setw(20) << "�������������" << endl;


	for (size_t i = 0; i < compressors.size(); i++)
	{
		fout << setw(10) << compressors[i].id << setw(20) << compressors[i].name << setw(30) << compressors[i].workshops << setw(30)
			<< compressors[i].workshopsinwork << setw(20) << compressors[i].performance << endl;

	}
	fout.close();
}


int main() {
	setlocale(LC_CTYPE, "rus");//��������� �������� ����� 
	int menustatus;
	bool join=false,quit=false;
	vector <pipe> pipes ;
	pipes.resize(0);
	vector <compressor> compressor;
	compressor.resize(0);
	
	while (true)
	{
		
		system("cls");
		MainMenu(); 

		menustatus = _getch();
	
		while (true) //mainmenu
		{ 
		
			switch (menustatus)
			{//submenus
			case '1':

				pipes.push_back(AddPipe(pipes));
				join = true;
				break;

			case '2':
				compressor.push_back(AddCompressor(compressor));
				join = true;
				break;

			case '3':

				OutInfo(pipes, compressor);
				join = true;
				break;

			case '4':

				EditPipe(pipes);
				join = true;
				break;

			case '5':
				break;

			case '6':

				Saveinfo(pipes, compressor);
				join = true;
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
