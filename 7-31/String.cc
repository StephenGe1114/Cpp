 ///
 /// @file    String.cc
 /// @author  gsw(1499186594@qq.com)
 ///
   

#include <stdio.h>
#include <string.h>
#include <iostream>
using std::cout;
using std::endl;

class String
{
public:
	String()
		: _pstr(new char[1]())
	{
		cout << "String()" << endl;
		// printf("_pstr = %p\n", _pstr);
	}

	String(const char *pstr)
		: _pstr(new char[strlen(pstr) + 1]())
	{
		cout << "String(const char *)" << endl;
		strcpy(_pstr, pstr);
	}

	String(const String &rhs)
		: _pstr(new char[strlen(rhs._pstr) + 1]())
	{
		strcpy(_pstr, rhs._pstr);
	}

	// s1 = s2;
	String &operator=(const String &rhs)
	{
		if (this != &rhs) // 自复制
		{
			delete[] _pstr; // 回收做操作数的空间

			_pstr = new char[strlen(rhs._pstr) + 1](); // 深拷贝
			strcpy(_pstr, rhs._pstr);
		}
		return *this;
	}

	~String()
	{
		delete[] _pstr;
	}

	void print() const
	{
		cout << _pstr << endl; // 当cout执行打印空指针的时候，程序直接崩了
	}

private:
	char *_pstr;
};

int main(void)
{
	String s1;
	s1.print();

	String s2("hello,world");
	s2.print();

	return 0;
}

