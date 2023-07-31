 ///
 /// @file    derivedCopyControl.cc
 /// @author  gsw(1499186594@qq.com)
 ///
   
#include <string.h>
#include <iostream>

using std::cout;
using std::endl;

class Base
{
public:
	Base(const char *pbase)
		: _pbase(new char[strlen(pbase) + 1]())
	{
		strcpy(_pbase, pbase);
		cout << "Base(const char * pbase)" << endl;
	}

	Base(const Base &rhs)
		: _pbase(new char[strlen(rhs._pbase) + 1]())
	{
		strcpy(_pbase, rhs._pbase);
		cout << "Base(const Base & rhs)" << endl;
	}

	Base &operator=(const Base &rhs)
	{
		cout << "Base & operator=(const Base &)" << endl;
		if (this != &rhs)
		{
			delete[] _pbase;
			_pbase = new char[strlen(rhs._pbase) + 1]();
			strcpy(_pbase, rhs._pbase);
		}
		return *this;
	}

	~Base()
	{
		delete[] _pbase;
		cout << "~Base()" << endl;
	}

	void print(std::ostream &os) const { os << _pbase; }

	friend std::ostream &operator<<(std::ostream &os, const Base &rhs);

private:
	char *_pbase;
};

std::ostream &operator<<(std::ostream &os, const Base &rhs)
{
	os << rhs._pbase;
	return os;
}

class Derived
	: public Base
{
public:
	Derived(const char *pbase)
		: Base(pbase)
	{
		cout << "Derived()" << endl;
	}

	~Derived()
	{
		cout << "~Derived()" << endl;
	}

	friend std::ostream &operator<<(std::ostream &os, const Derived &rhs);
};

std::ostream &operator<<(std::ostream &os, const Derived &rhs)
{
	rhs.print(os);
	return os;
}

int main(void)
{
	Derived d1("hello");
	cout << "d1 = " << d1 << endl;

	cout << "进行复制构造:" << endl;
	Derived d2 = d1;
	cout << "d2 = " << d2 << endl
		 << endl;

	Derived d3("world");
	cout << "d3 = " << d3 << endl;

	cout << endl
		 << "进行赋值运算:" << endl;
	d3 = d1;
	cout << "d3 = " << d3 << endl;

	return 0;
}

