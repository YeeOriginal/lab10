#include <iostream>

using namespace std;

#include "internet_work_protocol.h"
#include "file_reader.h"
#include "constants.h"

int main()
{
	//Лабораторная работа №10
	//Вариант 5: Протокол работы в интернете
	//Иванов Иван
	
	internet_work_protocol* protocols[MAX_FILE_ROWS_COUNT];
	int size = NULL;

	try
	{
		read("data.txt", protocols, size);
		for(int i = 0; i < size; i++)
		{
			cout << "Время начала работы: " << protocols[i]->start.hour << protocols[i]->start.minute << protocols[i]->start.seconds << endl;
			cout << "Время конца работы: " << protocols[i]->finish.hour << protocols[i]->finish.minute << protocols[i]->finish.seconds << endl;
			cout << "Получено байт: " << protocols[i]->recieved.byte << endl;
			cout << "Отправлено байт: " << protocols[i]->sent.byte << endl;
			cout << "Название процесса: " << protocols[i]->title << endl;
			cout << "\n";
		}
		for (int i = 0; i < size; i++)
		{
			delete protocols[i];
		}
	}
	catch (const char* error)
	{
		cout << error << endl;
	}

	return 0;
}