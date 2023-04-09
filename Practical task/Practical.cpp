#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class MyString
{
public:
	MyString();
	MyString(string s);
	MyString(const MyString &obj);
	~MyString();
	void update();
	void print();
	void set(string s);

private:
	string *str;
};

int main()
{
	system("chcp 1251");
	system("cls");

	string s;
	cout << "Введите строку символов: ";
	getline(cin, s);

	MyString mystring0(s);
	mystring0.print();
	mystring0.update();
	
	MyString mystring1(mystring0);
	mystring1.print();

	MyString mystring2;
	mystring2.print();

	system("pause");
	return 0;
}

MyString::MyString()
{
	this->str = new string("???");

	cout << "Здесь сработал конструктор по умолчанию для " << this << endl;
}

MyString::MyString(string s)
{
	this->str = new string(s);

	cout << "Здесь сработал конструктор для " << this << endl;
}

MyString::MyString(const MyString& obj)
{
	this->str = new string(*obj.str);

	cout << "Здесь сработал конструктор копирования для " << this << endl;
}

MyString::~MyString()
{
	delete str;

	cout << "Здесь сработал деструктор для " << this << endl;
}

void MyString::set(string s)
{
	this->str = new string(s);
}

void MyString::print()
{
	cout << *str << endl;
}

void MyString::update()
{
	ofstream out;
	out.open("update.txt");

	if (out.is_open())
		out << *str << endl;
	else
	{
		cout << "Ошибка при открытии файла!" << endl;
		exit(1);
	}

	if (str->length() <= 5) return;

	for (unsigned int i = 0; i < str->length(); i++)
	{
		if (str->at(i) == '.')
			str->replace(i, 1, "");
	}

	out << *str;
	out.close();
}