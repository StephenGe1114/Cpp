 ///
 /// @file    derivedCopyControl2.cc
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
	Derived(const char *pbase, const char *pdervied)
		: Base(pbase), _pdervied(new char[strlen(pdervied)]())
	{
		cout << "Derived()" << endl;
		strcpy(_pdervied, pdervied);
	}

	Derived(const Derived &rhs)
		: Base(rhs) // 手动调用
		  ,
		  _pdervied(new char[strlen(rhs._pdervied)]())
	{
		strcpy(_pdervied, rhs._pdervied);
		cout << "Derived(const Derived&)" << endl;
	}

	Derived &operator=(const Derived &rhs)
	{
		cout << "Derived & operator=(const Derived &)" << endl;
		if (this != &rhs)
		{
			Base::operator=(rhs); // 手动调用基类相应函数
			delete[] _pdervied;
			_pdervied = new char[strlen(rhs._pdervied)]();
			strcpy(_pdervied, rhs._pdervied);
		}
		return *this;
	}

	~Derived()
	{
		cout << "~Derived()" << endl;
		delete[] _pdervied;
	}

	friend std::ostream &operator<<(std::ostream &os, const Derived &rhs);

private:
	char *_pdervied;
};

std::ostream &operator<<(std::ostream &os, const Derived &rhs)
{
	rhs.print(os);
	os << ", " << rhs._pdervied;
	return os;
}

int main(void)
{
	Derived d1("hello", "world");
	cout << "d1 = " << d1 << endl;

	cout << "进行复制构造:" << endl;
	Derived d2 = d1;
	cout << "d2 = " << d2 << endl
		 << endl;

#if 1
	Derived d3("hi", "shenzhen");
	cout << "d3 = " << d3 << endl;

	cout << endl
		 << "进行赋值运算:" << endl;
	d3 = d1;
	cout << "d3 = " << d3 << endl;
#endif

	return 0;
}
