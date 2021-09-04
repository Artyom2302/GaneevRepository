#include <iostream>
#include <vector>
#include <sstream>
#include <clocale>
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
	unsigned int allworkshops;
	unsigned int workshopsinwork;
	double performance;
	
};

int main() {
	setlocale(LC_CTYPE, "rus");//установка русского языка 
	//cоздание меню
	cout << "1. Добавить трубу" << endl<<
		"2. Добавить КС" << endl <<
		"3. Просмотр всех объектов" << endl <<
		"4. Редактировать трубу" << endl <<
		"5. Редактировать КС" << endl <<
		"6. Сохранить" << endl <<
		"7. Загрузить" << endl <<
		"0. Выход" << endl ;
	int button;
	cin >>button ;
	if (button==0)
	{
		exit(0);
	}
	return 0;
}