#include <iostream>//in out поток
#include <vector>//работа с динамическими массивами
#include <sstream>// для работы со строками
#include <clocale>// для русского языка
#include  <conio.h>// Для ввода с клавиатуры
#include <cstring>
#include <string>
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
	unsigned int workshops;
	unsigned int workshopsinwork;
	double performance;
	
};
//Функция проверки
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
//Создание объекта типа данных труба
void addpipe(vector <pipe>& pipesf) //pipesf -вектор труб для функции
{
	system("cls");
	pipesf.resize(pipesf.size()+1);
	//cоздаем переменные типа string для считывания с консоли 
	string value1;
	
	
	while (true){
		cout << "Введите ID: ";
		getline(cin, value1);
		if (checkint(value1) ){
			pipesf[pipesf.size() - 1].id = stoi(value1);
			break;
		}
		else
		{
			cout << "Введите значение верно !!! \n";
		}
	}
	
	cout << endl << "Введите длину: " ;
	cin >> pipesf[pipesf.size()-1].length;
	cout << endl << "Введите диаметр: ";
	cin >> pipesf[pipesf.size()-1].diameter;
	cout << endl << "Введите 1,если труба в ремонте или " ;
	cout << "введите 0,если труба в пригодном для экплуатации: " ;
	cin >> pipesf[pipesf.size()-1].repair;
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

int main() {
	setlocale(LC_CTYPE, "rus");//установка русского языка 
	//cоздание меню link="http://www.c-cpp.ru/content/getch-getche"
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
				cout << "Нажмите одну из перечисленных выше кнопок!!!";
				break;
			}
			
			
		}

		
	
	}
	
	
	_getch();
	return 0;
	
}