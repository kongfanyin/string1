#define _CRT_SECURE_NO_WARNINGS 1
#ifndef STRING_H

#define STRING_H
#include <iostream>
using std::istream;
using std::ostream;
class string1
{
public:
	//costuctors and other methods
	string1(const char* string);
	string1(const string1 &);//copy constructor
	string1();//default constructor
	~string1();//destructor
	//overload operator methods
	string1& operator=(const string1 &);
	string1& operator=(const char* str);
	char operator[](int i);
	const char & operator[](int i)const;
	//overload operator friend
	friend bool operator<(const string1 &, const string1 &);
	friend bool operator>(const string1 &, const string1 &);
	friend bool operator==(const string1 &, const string1 &);
	friend ostream& operator>>(ostream& os, const string1 &);
	friend istream& operator<<(istream & is, string1 &);
	int length()const
	{
		return len;
	};
	//static function
	static int howmany();
private:
	char* str;
	int len;
	static int num_strings;
	static const int CINLIM = 80;
};


#endif // !STRING_H
