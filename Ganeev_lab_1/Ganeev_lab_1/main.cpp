#include <iostream>//in out �����
#include <vector>//������ � ������������� ���������
#include <sstream>// ��� ������ �� �������� getline()
#include <clocale>// ��� �������� �����
#include  <conio.h>// ��� ����� � ���������� _getch()
#include <cstring> //
#include <iomanip>//��������������� �����
#include <fstream>
#include <cstdlib>// rand
#include <windows.h>
#include <unordered_map>



using namespace std;

//C������� ��������� �����
struct pipe {
	unsigned int id, diameter;
	double length;
	bool repair;
};
//C������� ��������� ������������� �������
struct compressor {
	unsigned int id=0;
	string name;
	unsigned int workshops=0;//����
	unsigned int workshopsinwork=0;//���� � ������
	double performance=0;//�������������
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
bool CheckDouble(string s) {
	if (s.size() == 0) {
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
bool CheckAllSpace(string s) {
	for (size_t i = 0; i < s.size(); i++)
	{
		if (s[i]!=' ')
		{
			return false;
		}
	}
	return true;
}
//����� ������� ��������
void Seporator(ostream &out =cout) {
	for (size_t i = 0; i < 25; i++)
	{
		out<<"----";
	}
	out << endl;
}



double EnterUDouble() {
	string value;
	do {
		getline(cin, value);
		if (!(CheckDouble(value))) {

			cout << "�������� ������� �������\n������� ��� ���: ";
		}
	} while (!(CheckDouble(value)));
		 return stod(value);
}
int EnterUInt() {
	string value;
	do
	{
		getline(cin, value);
		if (!(CheckInt(value))) {
			cout << "������� ������������� ��������: ";
		}

	} while (!(CheckInt(value)));
	return stoi(value);
}
int RandomId() {
	return rand();
}




bool CheckPipeId(int value,const vector <pipe>	&pipes) {
	
	for (size_t i = 0; i < pipes.size(); i++) {
		if (value ==pipes[i].id)
		{
			return  true;
			break;
		}
	}
	return false;
}

bool CheckCompressorId(int value,const vector <compressor> &compressors) {
	for (size_t i = 0; i < compressors.size(); i++) {
		if (value == compressors[i].id)
		{
			return  true;
			break;
		}
	}
	return false;

}

void MainMenu()
	{
	cout <<endl<< "1. �������� �����" << endl <<
		"2. �������� ��" << endl <<
		"3. �������� ���� ��������" << endl <<
		"4. ������������� �����" << endl <<
		"5. ������������� ��" << endl <<
		"6. ���������" << endl <<
		"7. ���������" << endl <<
		"0. �����" << endl<<
		"������� ����� ����: "<<	endl;
	}

char GetPipeStatus(){
	char x;
	do
	{
	x = _getch();
	if (x != '0' && x != '1') { cout << "������� ������� �����!!!\n"; }
	} while (x!='1' && x!='0');
	return x;
}
pipe AddPipe(int id) //���������� 
{ 
	string value1;
	int key;
	char value2;
	pipe p;

	p.id = id;

	cout<<"�����\nID �"<<p.id << endl

	  << "������� �����: " ;

	p.length = EnterUDouble();

	
	cout << endl << "������� �������: ";
	
	p.diameter = EnterUInt();


	cout << endl << "������� 1,���� ����� � ������� ��� "  
		<< "������� 0,���� ����� � ��������� ��� �����������: \n" ;
	
	value2 = GetPipeStatus();
	
	value2 == '1' ? p.repair = true : p.repair = false;

	return p;
	
}

compressor AddCompressor(int id)//�������� id
{
	compressor comp ;
	string value;
	
		
	comp.id = id;


	cout << "������������� �������\nID �" << comp.id
	 << endl << "������� ���: ";

	do{

	getline(cin, comp.name);

	} while (comp.name=="" || CheckAllSpace(comp.name));
	

	cout << "������� ����� ���������� �����: ";
	comp.workshops = EnterUInt();

	cout << "�������  ���������� ����� � ������: ";
	do
	{	getline(cin, value);
			if (!((CheckInt(value) && (stoi(value) <= comp.workshops)) || value == "0"))
				{
				cout << "������� ������������� �����,�� ����������� ����� ���������� �����!!!\n";
				}

	} while (!((CheckInt(value) && (stoi(value) <= comp.workshops)) || value == "0"));
	comp.workshopsinwork = stoi(value);
	

	cout << endl << "������� ������������� � %: ";
	do
	{
		getline(cin, value);
		if (!(CheckDouble(value) && stod(value) <= 100 && stod(value) >= 0))
		{
			cout << "������� �������� ����� !!! �������������:  ";
		}

	} while (!(CheckDouble(value) && stod(value) <= 100 && stod(value) >= 0));
	comp.performance = stod(value);
	return comp;
}

void OutInfo(const pipe &p){
	cout << setw(10) << p.id << setw(20) << p.length << setw(20) << p.diameter
	 << setw(40) <<((p.repair) ? "� �������\n" : "� ������������\n");
}
void OutInfo(const compressor &comp) {
	cout << setw(10) << comp.id << setw(20) << comp.name << setw(30) << comp.workshops << setw(30)
		<< comp.workshopsinwork << setw(20) << comp.performance << endl;
}
void HeaderPipe() {
	cout << setw(10) << "Id " << setw(20) << "�����" << setw(20) << "�������" << setw(40) << "���������(� ������� ��� ���)\n";
}
void HeaderCompressor() {
	cout << setw(10) << "Id " << setw(20) << "��������" << setw(30) << "����� ���������� �����"
		<< setw(30) << "���������� ����� � ������" << setw(20) << "�������������" << endl;
}



//int SearchPipeIndexById(int id, unordered_map <int, pipe> pipesmap) {
//	if (pipesmap.find(id)!=pipesmap.end()) {
//		return id;
//	}
//	return -1;
//}

//int SearchCompressorIndexById( int id,const vector <compressor>& compressors) {
//	for (size_t i = 0; i < compressors.size(); i++)
//	{
//		if ( id== compressors[i].id)
//		{
//			return i;
//		}
//	}
//	return -1;
//}

string EnterFileName(char WriteOrLoad) {
	string filename;
	if (WriteOrLoad=='w') {
		cout << "������� ��� �����, � ������� ������ ��������� :";
		cin >> filename;
		filename += ".txt";
		return filename;
	}
	else if(WriteOrLoad == 'l') {
		cout << "������� ��� �����, � ������� ������ ��������� :";
		cin >> filename;
		filename += ".txtbuff.txt";
		return filename;
	}
	else { return "err"; }
	
	
}

void EditPipe(pipe &p) {
	p.repair = !p.repair;
}

void EditCompressor( compressor &comp) {
	string value;
	cout << "������� ����� ���������� ����� � ������: ";
	do
	{
		getline(cin, value);
		if (!((CheckInt(value) && (stoi(value) <= comp.workshops)) || value == "0"))
		{
			cout << "������� ������������� �����,�� ����������� ����� ���������� �����!!!\n";
		}

	} while (!((CheckInt(value) && (stoi(value) <= comp.workshops)) || value == "0"));
	comp.workshopsinwork = stoi(value);
}

void SaveInfo(const unordered_map <int ,pipe> &pipes, const unordered_map <int, compressor> &compressors) {
	ofstream fout,fbuff;
	string filename= EnterFileName('w');
	fout.open(filename, 'w');
	filename += "buff.txt";
	fbuff.open(filename, 'w');

	fout << "����� ����������\n";
	fout << "�����\n";
	fout << setw(10) << "Id " << setw(20) << "�����" << setw(20) << "�������" << setw(40) << "���������(� ������� ��� ���)\n";
	for (auto &p:pipes)
	{
		fout << setw(10) << p.second.id << setw(20) << p.second.length << setw(20) << p.second.diameter;
		fbuff <<"�����\n"<< p.second.id << endl << p.second.length << endl << p.second.diameter << endl << p.second.repair << endl;
		if (p.second.repair) {
			fout << setw(40) << "� �������\n";
		}
		else
		{
			fout << setw(40) << "� ������������\n";
		}

	}

	fout << "\n������������� �������\n";
	fout << setw(10) << "Id " << setw(20) << "��������" << setw(30) << "����� ���������� �����"
		<< setw(30) << "���������� ����� � ������" << setw(20) << "�������������" << endl;


	for (auto &c:compressors)
	{
		fout << setw(10) << c.second.id << setw(20) << c.second.name << setw(30) << c.second.workshops << setw(30)
			<< c.second.workshopsinwork << setw(20) << c.second.performance << endl;
		fbuff <<"��\n" << c.second.id << endl << c.second.name << endl << c.second.workshops << endl
			<< c.second.workshopsinwork << endl << c.second.performance << endl;

	}
	fout.close();
	fbuff.close();
}
void LoadInfo(unordered_map <int, pipe> &pipes, unordered_map <int, compressor> &compressors) {
	string str;
	string filename = EnterFileName('l');
	ifstream in(filename);
	pipe pipebuff;
	compressor compressorbuff;
	if (in.is_open()) {
		do
		{
			getline(in, str);
			if (str == "�����") {
				getline(in, str);
				pipebuff.id = stoi(str);

				getline(in, str);
				pipebuff.length = stof(str);

				getline(in, str);
				pipebuff.diameter = stoi(str);

				getline(in, str);
				pipebuff.repair = stoi(str);
				pipes.insert({pipebuff.id,pipebuff});
			}
			else if (str == "��") {//else
				getline(in, str);
				compressorbuff.id = stoi(str);
				getline(in, str);
				compressorbuff.name = str;
				getline(in, str);
				compressorbuff.workshops = stoi(str);
				getline(in, str);
				compressorbuff.workshopsinwork = stoi(str);
				getline(in, str);
				compressorbuff.performance = stod(str);
				compressors.insert({ compressorbuff.id,compressorbuff});

			}
		} while (str != "");
	}
	else {
		cout << "������ ����� �� ����������!!!";
	}
	
	in.close();
}



int main() {
	setlocale(LC_CTYPE,"Russian");
	vector <pipe> pipes;
	vector <compressor> compressors;
	int compressorsid=0,pipesid=0;
	unordered_map <int, pipe> pipesmap;
	unordered_map <int, compressor> compressorsmap;
	while (true)
	{
		MainMenu();
		switch (EnterUInt())
		{
		case 1:
		{
			pipesid += 1;
			pipe p = AddPipe(pipesid);
			pipesmap.insert({ p.id, p });
			cout << "������� ����� �� ���������� ����������������:\n";
			HeaderPipe();
			OutInfo(p);
			break;
		}

		case 2: {
			compressorsid += 1;
			compressor comp= AddCompressor(compressorsid);
			compressorsmap.insert({compressorsid,comp});
			cout << "������� ������������� ������� �� ���������� ����������������:\n";
			HeaderCompressor();
			OutInfo(comp);
			break;
		}
		case 3:
			Seporator();
			if (pipesmap.size()!=0)
			{
				cout << "�����\n";
				HeaderPipe();
				for(auto& p: pipesmap )
				{
					OutInfo(p.second);
				}
			}
			else
			{
				cout << "��� �� ����� �����\n";
			}
			Seporator();
		
			if (compressorsmap.size() != 0) {
				cout << "������������� �������\n";
				HeaderCompressor();
				for (auto &c:compressorsmap	)
				{
					OutInfo(c.second);
				}
			}
			else
			{
				cout << "��� �� ����� ������������� �������\n";
			}
			Seporator();
			break;

		case 4:
			if (pipesmap.size() == 0)
			{
				cout << "��� �� ����� �����\n";
			}
			else {
				auto pipeid = 0u;
				do
				{
					cout << "������� c����������� id: ";
					pipeid = EnterUInt();
				} while (pipesmap.find(pipeid) == pipesmap.end());
				cout << (pipesmap[pipeid].repair ? "\n����� � �������\n" :"\n����� � ������������\n");//�������� �������
				cout << "��� ��������� ������� ����� �������\n";
				_getch();
				EditPipe(pipesmap[pipeid]);
			}
			break;

		case 5:
			if (compressors.size() == 0)
			{
				cout << "��� �� ����� ������������� �������\n";
			}
			else {
			
				unsigned int compressorid = 0;
				do
				{
					cout << "������� c����������� id: ";
					compressorid = EnterUInt();
				} while (compressorsmap.find(compressorid)==compressorsmap.end());
				EditCompressor(compressors[compressorid]);
			}

			break;

		case 6:
			SaveInfo(pipesmap, compressorsmap);
			break;

		case 7:
			pipesmap.clear();
			compressorsmap.clear();
			LoadInfo(pipesmap, compressorsmap);
			break;

		case 8:
			
			break;

		case 0:
			return 0;

		default:
			break;
		}

	}
	
	return 0;

}
