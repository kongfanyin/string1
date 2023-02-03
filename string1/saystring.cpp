#define _CRT_SECURE_NO_WARNINGS 1
#include"string1.h"
#include<iostream>
const int ArSize = 10;
const int MaxLen = 81;
int main(char argc, char** argv)
{
	using std::cout;
	using std::cin;
	using std::endl;
	string1 name;
	cout << "Hi£¬what's your name.>>\n";
	cin >> name;

	cout << name << ",please enter to up to " << ArSize << " short saying <enpty line to quit>: \n";
	string1 saying[ArSize];//array of object
	char temp[MaxLen];//tempprary string storage
	int i;
	for (i = 0; i < ArSize; i++)
	{
		cout << i + 1 << ":  ";
		cin.get(temp, MaxLen);
		while (cin&&cin.get()!='\n')
		{
			continue;
		}
		if (!cin||temp[0]=='\0')//empty line
		{
			break;
		}
		else
		{
			saying[i] = temp;//overload assignment []
		}
	}
	int total = i;//total num of lines read
	if (total > 0)
	{
		cout << "here are your saying:\n";
		for (i = 0; i < total; i++)
		{
			cout << saying[i][0] << ": " << saying[i] << endl;
		}
		int shortest = 0;
		int first = 0;
		for (i = 1; i < total; i++)
		{
			if (saying[i].length() < saying[shortest].length())
				shortest = i;
			if (saying[i] < saying[first])
				first = i;
		}
		cout << "shortest saying:\n" << saying[shortest] << endl;
		cout << "first alphabetically:\n" << saying[first] << endl;
		cout << "this program used " << string1::howmany() << "string object .Bye.\n ";
	}
	else
	{
		cout << "no input,bye\n";
	}
	return 0;
}