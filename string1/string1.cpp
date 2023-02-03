#define _CRT_SECURE_NO_WARNINGS 1
#include <cstring>
#include"string1.h"
using std::cin;
using std::cout;
using std::endl;
//initializing static member
int string1::num_strings = 0;
//class methods
string1::string1(const char * string)
{
	len = std::strlen(string);
	str = new char[len + 1];
	std::strcpy(str, string);
	num_strings++;
}
string1::string1(const string1 &st)
{
	num_strings++;
	len = st.len;
	str = new char[len + 1];
	std::strcpy(str, st.str);
}
string1::string1()
{
	len = 4;
	str = new char[len + 1];
	str[0] = '\0';
	num_strings++;
}

string1::~string1()
{
	--num_strings;
	cout << str << "deleted" << endl;
	delete[] str;
}

string1 & string1::operator=(const string1 &st)
{
	if (this == &st)
	{
		return *this;
	}
	delete[]str;
	len = st.len;
	str = new char[len + 1];
	std::strcpy(str, st.str);
	return *this;
}

string1& string1::operator=(const char * s)//从C字符串创建字符串
{
	delete[] str;
	len = std::strlen(s);
	str = new char[len + 1];
	std::strcpy(str, s);
	return *this;
}

char& string1::operator[](int i)
{
	return str[i];
}
//read only char access for const string

const char & string1::operator[](int i) const
{
	return str[i];
}

int string1::howmany()
{
	return num_strings;
}

bool operator<(const string1 &st1, const string1 &st2)
{
	return (std::strcmp(st1.str,st2.str)<0);
}

bool operator>(const string1 &str1, const string1 &str2)
{
	return str1<str2;
}

bool operator==(const string1 &str1, const string1 &str2)
{
	return (std::strcmp(str1.str, str2.str) == 0);
}

ostream & operator<<(ostream & os, const string1 &str1)
{
	// TODO: 在此处插入 return 语句
	os << str1.str;
	return os;
}

istream & operator>>(istream & is, string1 &str1)
{
	char temp[string1::CINLIM];
	is.get(temp, string1::CINLIM);
	if (is)
	{
		str1 = temp;
	}
	while (is&&is.get()!='\n')
	{
		continue;
	}
	return is;
}
