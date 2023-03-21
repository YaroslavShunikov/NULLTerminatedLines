#include<iostream>
#include<windows.h>
#include <string>
using namespace std;
#define delimiter "-------------------------------------------------------------------------------------"

int StringLenght(const char* str);
void to_upper(char str[]);              //Перевод в верхний регистр
void to_lower(char str[]);				//Перевод в нихижний регистр 
void shrink(char str[]);				//удаляет лишние пробелы из строки
//bool is_palindrome(const char str[]);
bool is_int_number(const char str[]);
int to_int_number(const char str[]);
bool is_bin_number(const char str[]);
int  bin_to_dec(const char str[]);
bool is_hex_number(const char str[]);

void main()
{
	setlocale(LC_ALL, "");
	/*char str[] = {"Hello"};
	cout << str << endl;*/

	const int n = 256;
	char str[n] = {};
	cout << "Введите строку: "; //cin >>str ;
	SetConsoleCP(1251);
	cin.getline(str, n);
	SetConsoleCP(866);
	cout << str << endl;
	cout << "Размер строки: " << StringLenght(str) << endl;
	to_upper(str);
	cout << str << endl << endl;
	to_lower(str);
	cout << str << endl << endl;
	shrink(str);
	cout << str<< endl<<endl;
	cout<<"Строка" << (is_int_number(str)?" ":"Не")<<"десятичное число" << endl;
	cout << to_int_number(str) << endl;
	cout << "Строка" << (is_bin_number(str) ? " " : " НЕ ") << "двоичное число" << endl;
	cout<<bin_to_dec(str)<<endl;
	cout << "Строка" << (is_hex_number(str) ? " " : " НЕ ") << "шестнадцатиричное число" << endl;
}

int StringLenght(const char* str)
{
	int i = 0;
	for (; str[i]; i++);
	return i;
}
void to_upper(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		if (str[i] >= 'a' && str[i] <= 'z')str[i] -= 32;
		if (str[i] >= 'а' && str[i] <= 'я')str[i] -= 32;
	}
}
void to_lower(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		if (str[i] >= 'A' && str[i] <= 'Z')str[i] += 32;
		if (str[i] >= 'А' && str[i] <= 'Я')str[i] += 32;
	}
}
void shrink(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		while (str[i] == 32 && str[i + 1] == 32)
		{
			//цикл сдвига фрагмента массива
			for (int j = i; str[j]; j++)
			{
				str[j] = str[j + 1];
			}
		}
	}
}
bool is_int_number(const char str[])
{
	for (int i = 0; str[i]; i++)
	{
		if (str[i] < '0' || str[i]>'9') return false;
	}
	return true;
}
int to_int_number(const char str[])
{
	
	if (is_int_number(str) == true)//|| (is_hex_number(str)))
	{
		int n = StringLenght(str);
		int value=((int)str[0]-48);
		int walle;
		int eva = 1;
		for (int i = n-1; i>0; i--)
		{
			value *= 10;
			
		}
		value+= ((int)str[n-1] - 48);
		for (int i = n - 2; i > 0; i--)
		{
			walle = ((int)str[i]-48)*pow(10,eva);
			value += walle;

			eva++;
		}
		return value;

	}
	else return 0;
}
bool is_bin_number(const char str[])
{
	for (int i = 0; str[i]; i++)
	{
		if (str[i] != '1' && str[i] != '0')
		{
			return false;
		}
	}
	return true;
}
int  bin_to_dec(const char str[])
{
	if (is_bin_number(str) == true)
	{
		return(to_int_number(str));
	}
	else return 0;
}
bool is_hex_number(const char str[])
{
	for (int i = 0; str[i]; i++)
	{
	
		if ((str[i] < '0' || str[i] > '9') &&(str[i] < 'A' || str[i] > 'F')&&(str[i] < 'a' || str[i] > 'f'))
			
			{
				return false;
			}
	}
	return true;
}