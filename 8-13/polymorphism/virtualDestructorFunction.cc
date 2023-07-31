 ///
 /// @file    virtualDestructorFunction.cc
 /// @author  gsw(1499186594@qq.com)
 ///
   
#include <string.h>
#include <iostream>
using std::cout;
using std::endl;

class Base
{
public:
	Base(const char *pdata)
		: _pdata(new char[strlen(pdata) + 1]())
	{
		cout << "Base(const char*)" << endl;
		strcpy(_pdata, pdata);
	}

	virtual void display() const
	{
		cout << _pdata << endl;
	}

	// 一旦类中定义了虚函数，哪怕只有一个，也要将析构函数设置成虚函数
	virtual ~Base()
	{
		delete[] _pdata;
		cout << "~Base()" << endl;
	}

private:
	char *_pdata;
};

class Derived
	: public Base
{
public:
	Derived(const char *pdata, const char *pdata2)
		: Base(pdata), _pdata2(new char[strlen(pdata2) + 1]())
	{
		cout << "Derived(const char *, const char *)" << endl;
		strcpy(_pdata2, pdata2);
	}

	void display() const
	{
		cout << _pdata2 << endl;
	}

	// 一旦将基类析构函数设置成虚函数之后，派生类析构函数会自动成为虚函数，
	// 无论是否在其前面加不加virtual关键字
	~Derived()
	{
		delete[] _pdata2;
		cout << "~Derived()" << endl;
	}

private:
	char *_pdata2;
};

int main(void)
{
	Base *pbase = new Derived("hello", "world");
	pbase->display();
	// Derived * pderived = dynamic_cast<Derived*>(pbase);//dynamic_cast是专门处理基类与派生类之间转换的
	// delete pderived;
	delete pbase;
	return 0;
}

