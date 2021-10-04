#include <iostream>//in out поток
#include <vector>//работа с динамическими массивами
#include <sstream>// для работы со строками getline()
#include <clocale>// для русского языка
#include  <conio.h>// Для ввода с клавиатуры _getch()
#include <cstring> //
#include <iomanip>//форматированный вывод
#include <fstream>
#include <cstdlib>// rand
#include <windows.h>




using namespace std;

//Cоздание структуры Труба
struct pipe {
	unsigned int id, diameter;
	double length;
	bool repair;
};
//Cоздание структуры Компрессорная станция
struct compressor {
	unsigned int id=0;
	string name;
	unsigned int workshops=0;//цехи
	unsigned int workshopsinwork=0;//цехи в работе
	double performance=0;//эффективность
	 };
//Функция проверки
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
		if (s[i] == '.') {//проверка на точки
			tochka += 1;
		}
		if (tochka > 1) {// возврат если точек больше одной
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
//Конец функции проверки
void Seporator() {
	for (size_t i = 0; i < 25; i++)
	{
		cout<<"----";
	}
	cout << endl;
}

double EnterUDouble() {
	string value;
	do {
		getline(cin, value);
		if (!(CheckDouble(value))) {

			cout << "Значение введено неверно\nВведите еще раз: ";
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
			cout << "Введите целочисленное значение: ";
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
	cout <<endl<< "1. Добавить трубу" << endl <<
		"2. Добавить КС" << endl <<
		"3. Просмотр всех объектов" << endl <<
		"4. Редактировать трубу" << endl <<
		"5. Редактировать КС" << endl <<
		"6. Сохранить" << endl <<
		"7. Загрузить" << endl <<
		"0. Выход" << endl;
	}

pipe AddPipe(const vector <pipe>& pipes) //переделать 
{ 
	string value1;
	int key;
	char value2;
	pipe p;

	
	do
	{
		p.id = rand();
	} while ((CheckPipeId(p.id,pipes)));
	

	cout<<"Труба\nID №"<<p.id << endl

	  << "Введите длину: " ;

	p.length = EnterUDouble();

	
	cout << endl << "Введите диаметр: ";
	
	p.diameter = EnterUInt();


	cout << endl << "Введите 1,если труба в ремонте или "  
		<< "введите 0,если труба в пригодном для экплуатации: \n" ;
	
	do
	{
		value2 = _getch();

		if (value2 != '0' && value2 != '1') {cout << "Нажмите клавишу верно!!!\n";}

	} while (value2 != '0'  && value2 != '1');
	
	value2 == '1' ? p.repair = true : p.repair = false;

	return p;
	
}

compressor AddCompressor( const vector <compressor>	&compressors)//передать id
{
	compressor comp ;
	string value;
	
	do
	{
		comp.id = rand();
	} while ((CheckCompressorId(comp.id, compressors)));

	cout << "Компрессорная станция\nID №" << comp.id
	 << endl << "Введите имя: ";

	do{

	getline(cin, comp.name);

	} while (comp.name=="" || CheckAllSpace(comp.name));
	

	cout << "Введите общее количество цехов: ";
	comp.workshops = EnterUInt();

	cout << "Введите  количество цехов в работе: ";
	do
	{	getline(cin, value);
			if (!((CheckInt(value) && (stoi(value) <= comp.workshops)) || value == "0"))
				{
				cout << "Введите целочисленное число,не превышающее общее количество цехов!!!\n";
				}

	} while (!((CheckInt(value) && (stoi(value) <= comp.workshops)) || value == "0"));
	comp.workshopsinwork = stoi(value);
	

	cout << endl << "Введите эффективность в %: ";
	do
	{
		getline(cin, value);
		if (!(CheckDouble(value) && stod(value) <= 100 && stod(value) >= 0))
		{
			cout << "Введите значение верно !!! Эффективность:  ";
		}

	} while (!(CheckDouble(value) && stod(value) <= 100 && stod(value) >= 0));
	comp.performance = stod(value);
	return comp;
}

//void OutInfo(vector <pipe>& pipes, vector <compressor>& compressors)//переделать 
//{
//	char menuexit;
//
//	do
//	{
//
//		cout.width(50);
//		cout << "Общая информация\n";
//
//		cout << "Трубы\n";
//		cout << setw(10) << "Id " << setw(20) << "Длина" << setw(20) << "Диаметр" << setw(40) << "Состояние(В ремонте или нет)\n";
//
//
//		for (size_t i = 0; i < pipes.size(); i++)
//		{
//			cout << setw(10) << pipes[i].id << setw(20) << pipes[i].length << setw(20) << pipes[i].diameter;
//
//			cout << setw(40) << pipes[i].repair? "В ремонте\n":"В эксплуатации\n";
//
//		}
//
//
//		for (size_t i = 0; i < 100; i++)
//		{
//			cout << "-";
//		}
//		cout << "\nКомпрессорные станции\n";
//
//		cout << setw(10) << "Id " << setw(20) << "Название" << setw(30) << "Общее количество цехов"
//			<< setw(30) << "Количество цехов в работе" << setw(20) << "Эффективность" << endl;
//
//
//		for (size_t i = 0; i < compressors.size(); i++)
//		{
//			cout << setw(10) << compressors[i].id << setw(20) << compressors[i].name << setw(30) << compressors[i].workshops << setw(30)
//				<< compressors[i].workshopsinwork << setw(20) << compressors[i].performance << endl;
//
//		}
//
//		cout << "\n\nДля возращения в меню нажмите 0";
//
//		menuexit = _getch();
//
//	}
//
//	while (menuexit != '0');
//}
void OutInfo(const pipe &p){
	cout << setw(10) << p.id << setw(20) << p.length << setw(20) << p.diameter
	 << setw(40) <<((p.repair) ? "В ремонте\n" : "В эксплуатации\n");
}
void OutInfo(const compressor &comp) {
	cout << setw(10) << comp.id << setw(20) << comp.name << setw(30) << comp.workshops << setw(30)
		<< comp.workshopsinwork << setw(20) << comp.performance << endl;
}
void HeaderPipe() {
	cout << setw(10) << "Id " << setw(20) << "Длина" << setw(20) << "Диаметр" << setw(40) << "Состояние(В ремонте или нет)\n";
}
void HeaderCompressor() {
	cout << setw(10) << "Id " << setw(20) << "Название" << setw(30) << "Общее количество цехов"
		<< setw(30) << "Количество цехов в работе" << setw(20) << "Эффективность" << endl;
}



int SearchPipeIndexById(int id,const vector <pipe> &pipes) {
	for (size_t i = 0; i < pipes.size(); i++)
	{
		if (id == pipes[i].id) {
			return i;
		}
		
	}
	return -1;
}

int SearchCompressorIndexById( int id,const vector <compressor>& compressors) {
	for (size_t i = 0; i < compressors.size(); i++)
	{
		if ( id== compressors[i].id)
		{
			return i;
		}
	}
	return -1;
}



void EditPipe(pipe &p) {
	p.repair = !p.repair;
}

void EditCompressor( compressor &comp) {
	string value;
	cout << "Введите новое количество цехов в работе: ";
	do
	{
		getline(cin, value);
		if (!((CheckInt(value) && (stoi(value) <= comp.workshops)) || value == "0"))
		{
			cout << "Введите целочисленное число,не превышающее общее количество цехов!!!\n";
		}

	} while (!((CheckInt(value) && (stoi(value) <= comp.workshops)) || value == "0"));
	comp.workshopsinwork = stoi(value);
}

void SaveInfo(const vector <pipe>  &pipes,const vector <compressor> &compressors) {
	ofstream fout,fbuff;
	fout.open("data.txt",'w');
	fbuff.open("buff.txt", 'w');
	fout << "Общая информация\n";
	fout << "Трубы\n";
	fout << setw(10) << "Id " << setw(20) << "Длина" << setw(20) << "Диаметр" << setw(40) << "Состояние(В ремонте или нет)\n";
	for (size_t i = 0; i < pipes.size(); i++)
	{
		fout << setw(10) << pipes[i].id << setw(20) << pipes[i].length << setw(20) << pipes[i].diameter;
		fbuff <<"Труба\n"<< pipes[i].id << endl << pipes[i].length << endl << pipes[i].diameter << endl << pipes[i].repair << endl;
		if (pipes[i].repair) {
			fout << setw(40) << "В ремонте\n";
		}
		else
		{
			fout << setw(40) << "В эксплуатации\n";
		}

	}


	for (size_t i = 0; i < 100; i++)
	{
		fout << "-";
	}
	fout << "\nКомпрессорные станции\n";
	fout << setw(10) << "Id " << setw(20) << "Название" << setw(30) << "Общее количество цехов"
		<< setw(30) << "Количество цехов в работе" << setw(20) << "Эффективность" << endl;


	for (size_t i = 0; i < compressors.size(); i++)
	{
		fout << setw(10) << compressors[i].id << setw(20) << compressors[i].name << setw(30) << compressors[i].workshops << setw(30)
			<< compressors[i].workshopsinwork << setw(20) << compressors[i].performance << endl;
		fbuff <<"КС\n" << compressors[i].id << endl << compressors[i].name << endl << compressors[i].workshops << endl
			<< compressors[i].workshopsinwork << endl << compressors[i].performance << endl;

	}
	fout.close();
	fbuff.close();
}
void LoadInfo(vector <pipe>& pipes, vector <compressor>& compressors) {
	string str;
	ifstream in("buff.txt");
	pipe pipebuff;
	compressor compressorbuff;
	if (in.is_open()) {
		do
		{
			getline(in, str);
			if (str == "Труба") {
				getline(in, str);
				pipebuff.id = stoi(str);

				getline(in, str);
				pipebuff.length = stof(str);

				getline(in, str);
				pipebuff.diameter = stoi(str);

				getline(in, str);
				pipebuff.repair = stoi(str);
				pipes.push_back(pipebuff);
			}
			if (str == "КС") {
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
				compressors.push_back(compressorbuff);

			}
		} while (str != "");
	}
	

	in.close();
}

int main() {
	setlocale(LC_CTYPE,"Russian");
	vector <pipe> pipes;
	vector <compressor> compressors;


	while (true)
	{
		MainMenu();
		switch (_getch())
		{
		case '1':
		{
			pipe p = AddPipe(pipes);
			pipes.push_back(p);
			cout << "Введена труба со следующими характеристиками:\n";
			HeaderPipe();
			OutInfo(p);
			break;
		}
			

		case '2': {
			compressor comp= AddCompressor(compressors);
			compressors.push_back(comp);
			cout << "Введена компрессорная станция со следующими характеристиками:\n";
			HeaderCompressor();
			OutInfo(comp);
			break;
		}
			

		case '3':
			Seporator();
			if (pipes.size()!=0)
			{
				cout << "Трубы\n";
				HeaderPipe();
				for (size_t i = 0; i < pipes.size(); i++)
				{
					OutInfo(pipes[i]);
				}
			}
			else
			{
				cout << "Нет ни одной трубы\n";
			}
			Seporator();
		
			if (compressors.size() != 0) {
				cout << "Компрессорные станции\n";
				HeaderCompressor();
				for (size_t i = 0; i < compressors.size(); i++)
				{
					OutInfo(compressors[i]);
				}
			}
			else
			{
				cout << "Нет ни одной компрессорной станции\n";
			}
			Seporator();
			break;

		case '4':
			if (pipes.size() == 0)
			{
				cout << "Нет ни одной трубы\n";
			}
			else {
				int pipeindex;
				auto pipeid = 0u;
				do
				{
					cout << "Введите cуществующий id: ";
					pipeid = EnterUInt();
					pipeindex = SearchPipeIndexById(pipeid, pipes);
				} while (SearchPipeIndexById(pipeid, pipes) == -1);


				cout << (pipes[pipeindex].repair ? "\nТруба в ремонте\n" :"\nТруба в эксплуатации\n");
				cout << "Для изменения нажмите любую клавишу\n";
				_getch();
				EditPipe(pipes[pipeindex]);
			}
			break;

		case '5':
			if (compressors.size() == 0)
			{
				cout << "Нет ни одной компрессорной станции\n";
			}
			else {
				int compressorindex = 0;
				unsigned int compressorid = 0;
				do
				{
					cout << "Введите cуществующий id: ";
					compressorid = EnterUInt();
					compressorindex = SearchCompressorIndexById(compressorid, compressors);
				} while (SearchCompressorIndexById(compressorid, compressors) == -1);


				EditCompressor(compressors[compressorindex]);
			}

			break;

		case '6':
			SaveInfo(pipes, compressors);
			break;

		case '7':
			pipes = {};
			compressors = {};
			LoadInfo(pipes, compressors);
			break;

		case '8':
			break;

		case '0':
			return 0;

		default:
			break;
		}

	}
	_getch();
	return 0;

}
