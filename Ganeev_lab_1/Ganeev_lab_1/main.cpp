#include <iostream>//in out поток
#include <vector>//работа с динамическими массивами
#include <sstream>// для работы со строками getline()
#include <clocale>// для русского языка
#include  <conio.h>// Для ввода с клавиатуры _getch()
#include <cstring> //
#include <iomanip>//форматированный вывод
using namespace std;

//Cоздание структуры Труба
struct pipe {
	unsigned int id;
	double length,
		diameter;
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

//Создание объекта типа данных труба
void addpipe(vector <pipe>& pipesf) //pipesf -вектор труб для функции
{
	system("cls");
	pipesf.resize(pipesf.size()+1);
	//cоздаем переменные типа string для считывания с консоли 
	string value1;
	int key;
	cout << "Введите ID: ";
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
				cout << "Введено уже существующее значение\nCписок использованный id:";
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
				cout << "Введите значение корректно!!!";
			}
		}
		
	}
	
	cout << endl << "Введите длину: " ;
	while (true) {
		getline(cin, value1);
		if (checkfloat(value1)) {
			pipesf[pipesf.size() - 1].length = stod(value1);
			break;
		}
		else
		{
			cout << "Введите значение верно !!! Длина:  ";
		}
	}
	
	cout << endl << "Введите диаметр: ";
	while (true) {
		getline(cin, value1);
		if (checkfloat(value1)) {
			pipesf[pipesf.size() - 1].diameter = stod(value1);
			break;
		}
		else
		{
			cout << "Введите значение верно !!! Диаметр:  ";
		}
	}
	cout << endl << "Введите 1,если труба в ремонте или "  
		<< "введите 0,если труба в пригодном для экплуатации: \n" ;
	char value2;
	while (true)
	{
		
		value2 = _getch();
		if (value2 != '1' && value2 != '0')
		{
			cout << "Введите либо 0(Если труба в пригодном для экплуатации состоянии), либо 1(Если труба в ремонте) \n";
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
void addpipe(vector <compressor>& compressorf) //compressorf-вектор труб для функции
{
	system("cls");
	compressorf.resize(compressorf.size() + 1);
	string value1;

	cout << "Введите ID: ";
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
			cout << "Введите значение корректно(ID может быть занят,для просмотра этого нужно просмотреть все компрессорные станции) !!! ID:  ";
		}
	}

	cout << endl << "Введите имя: ";
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
			cout << "Введите значение корректно(ID может быть занят,для просмотра этого нужно просмотреть все компрессорные станции) !!! ID:  ";
		}
	}

	
	


}
void mainmenu()
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
void outinfo(vector <pipe>& pipes /*, vector <compressor>& compressor*/) {
	char menuexit;
do
{
	system("cls");
	cout.width(50);
	cout << "Общая информация\n";
	cout.width(45);
	cout << "Трубы\n";
	cout.width(20);
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
	cout << "\n\nДля возращения в меню нажмите 0";
	
	menuexit = _getch();

} 
while (menuexit!='0');
	
	
	

}

int main() {
	setlocale(LC_CTYPE, "rus");//установка русского языка 
	//cоздание меню link="http://www.c-cpp.ru/content/getch-getche"
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
