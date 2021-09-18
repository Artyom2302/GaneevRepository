#include <iostream>//in out поток
#include <vector>//работа с динамическими массивами
#include <sstream>// для работы со строками getline()
#include <clocale>// для русского языка
#include  <conio.h>// Для ввода с клавиатуры _getch()
#include <cstring> //
#include <iomanip>//форматированный вывод
#include <fstream>
#include <cstdlib>// rand



using namespace std;

//Cоздание структуры Труба
struct pipe {
	unsigned int id, diameter;
	double length;
	bool repair;
};
//Cоздание структуры Компрессорная станция
struct compressor {
	unsigned int id;
	string name;
	unsigned int workshops;//цехи
	unsigned int workshopsinwork;//цехи в работе
	double performance;//эффективность
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
	cout << "1. Добавить трубу" << endl <<
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
	

	cout<<"Труба\nID №"<<p.id

	 << endl << "Введите длину: " ;//заменить на do while 

	do {
		getline(cin, value1);

		if (!(CheckDouble(value1))) {
			
			cout << "Значение введено неверно\nВведите еще раз: ";
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
			cout << "Введите значение верно !!! Длина:  ";
		}
	}*/
	
	cout << endl << "Введите диаметр: ";
	do {
		getline(cin, value1);

		if (!(CheckInt(value1))) 
		{	
			cout << "Значение введено неверно\nВведите еще раз: ";
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
			cout << "Введите значение верно !!! Диаметр:  ";
		}
	}*/
	cout << endl << "Введите 1,если труба в ремонте или "  
		<< "введите 0,если труба в пригодном для экплуатации: \n" ;
	
	do
	{
		value2 = _getch();

		if (value2 != '0' && value2 != '1') {cout << "Нажмите клавишу верно!!!\n";}

	} while (value2 != '0'  && value2 != '1');
	
	value2 == '1' ? p.repair = true : p.repair = false;
	/*while (true)
	{
		
		value2 = _getch();
		if (value2 != '1' && value2 != '0')
		{
			cout << "Введите либо 0(Если труба в пригодном для экплуатации состоянии), либо 1(Если труба в ремонте) \n";
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

	cout << endl << "Введите имя: ";
	getline(cin, comp.name);

	cout << "Введите общее количество цехов: ";
	/*while (true) {
		getline(cin, value1);
		if (CheckInt(value1)) {
			compressor[compressor.size() - 1].workshops = stoi(value1);
			break;
		}
		else
		{
			cout << "Введите целочисленное число: ";
		}
	}*/

	do
	{
		getline(cin, value);
		if (!(CheckInt(value)))
		{
			cout << "Введите целочисленное число!!!\n ";
		}

	} while (!(CheckInt(value)));
	comp.workshops = stoi(value);
	
	
	cout << "Введите  количество цехов в работе: ";
	/*while (true) {
		getline(cin, value1);
		if ((CheckInt(value1) && (stoi(value1) <= compressor[compressor.size() - 1].workshops))||value1=="0") {
			compressor[compressor.size() - 1].workshopsinwork = stoi(value1);
			break;
		}
		else
		{
			cout << "Введите целочисленное число,не превышающее количества рабочих цехов: ";
		}
	}*/
	
	
	do
	{	getline(cin, value);
			if (!((CheckInt(value) && (stoi(value) <= comp.workshops)) || value == "0"))
				{
				cout << "Введите целочисленное число,не превышающее количества рабочих цехов!!!\n";
				}

	} while (!((CheckInt(value) && (stoi(value) <= comp.workshops)) || value == "0"));
	comp.workshopsinwork = stod(value);
	
	cout << endl << "Введите эффективность в %: ";
	/*while (true) {
		getline(cin, value);
		if (CheckDouble(value)&& stod(value)<100 &&stod(value)>10) {
			comp.performance = stod(value);
			break;
		}
		else
		{
			cout << "Введите значение верно !!! Эффективность:  ";
		}
	}*/
	do
	{
		getline(cin, value);
		if (!(CheckDouble(value) && stod(value) < 100 && stod(value) > 10))
		{
			cout << "Введите значение верно !!! Эффективность:  ";
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
	cout << "Общая информация\n";

	cout << "Трубы\n";
	cout << setw(10) << "Id " << setw(20) << "Длина" << setw(20) << "Диаметр" << setw(40) << "Состояние(В ремонте или нет)\n";


	for (size_t i = 0; i < pipes.size(); i++)
	{
		cout << setw(10) << pipes[i].id << setw(20) << pipes[i].length << setw(20) << pipes[i].diameter;

		if (pipes[i].repair) {
			cout << setw(40) << "В ремонте\n";
		}
		else
		{
			cout << setw(40) << "В эксплуатации\n";
		}

	}


	for (size_t i = 0; i < 100; i++)
	{
		cout << "-";
	}
	cout << "\nКомпрессорные станции\n";

	cout << setw(10) << "Id " << setw(20) << "Название" << setw(30) << "Общее количество цехов"
		<< setw(30) << "Количество цехов в работе" << setw(20) << "Эффективность" <<  endl;


	for (size_t i = 0; i < compressors.size(); i++)
	{
		cout << setw(10) << compressors[i].id << setw(20) << compressors[i].name << setw(30) << compressors[i].workshops<<setw(30)
			<< compressors[i].workshopsinwork << setw(20)<<compressors[i].performance<<endl;
		
	}
	
	cout << "\n\nДля возращения в меню нажмите 0";
	
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
		cout << "Введите ID трубы,которую ходите поменять: ";
		getline(cin,value);
		if (CheckInt(value))
		{
			pipeindex = SearchPipeIdIndex(pipes, stoi(value));
			break;
		}
		else 
		{
			"Введите верно значение id: ";
		}

	} while (true);
	/*cout << endl << "Введите 1,если труба в ремонте или "
		<< "введите 0,если труба в пригодном для экплуатации: \n";
	
	
	while (true)
	{
		value2 = _getch();
		if (value2 != '1' && value2 != '0')
		{
			cout << "Введите либо 0(Если труба в пригодном для экплуатации состоянии), либо 1(Если труба в ремонте) \n";
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
		{	cout << "Труба сейчас находится в ремонте для изменения её состояния нажмите 0";
			value2 = _getch();
		} while (value2!='0');
		pipes[pipeindex].repair = false;
	}
	else
	{
		do
		{
			cout << "Труба сейчас находится в экспуатации для изменения её состояния нажмите 1";
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
		cout << "Введите ID компрессора ,в котором ходите поменять: ";
		getline(cin, value);
		if (CheckInt(value))
		{
			compressorindex = SearchCompressorIdIndex(compressors, stoi(value));
			break;
		}
		else
		{
			"Введите верно значение id: ";
		}
	
	} while (true);

}

void Saveinfo(const vector <pipe>  &pipes,const vector <compressor> &compressors) {
	ofstream fout;
	fout.open("data.txt",'w');
	fout << "Общая информация\n";

	fout << "Трубы\n";
	fout << setw(10) << "Id " << setw(20) << "Длина" << setw(20) << "Диаметр" << setw(40) << "Состояние(В ремонте или нет)\n";


	for (size_t i = 0; i < pipes.size(); i++)
	{
		fout << setw(10) << pipes[i].id << setw(20) << pipes[i].length << setw(20) << pipes[i].diameter;

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

	}
	fout.close();
}


int main() {
	setlocale(LC_CTYPE, "rus");//установка русского языка 
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
