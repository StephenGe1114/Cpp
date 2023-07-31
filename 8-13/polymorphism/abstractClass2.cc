 ///
 /// @file    abstractClass2.cc
 /// @author  gsw(1499186594@qq.com)
 ///
   
#include <iostream>
using std::cout;
using std::endl;

// 定义了protected型构造函数的类 也称为抽象类
class Base
{
public:
	void display() const
	{
		cout << "Base::_base = " << _base << endl;
	}

protected:
	Base(int base)
		: _base(base)
	{
		cout << "Base(int)" << endl;
	}

private:
	int _base;
};

class Derived
	: protected Base
{
public:
	Derived(int base)
		: Base(base)
	{
		cout << "Derived(int)" << endl;
	}

	void print() const
	{
		display();
	}
};

int main(void)
{
	// Base base;//error;
	Derived d(10);
	d.print();

	Base *pbase = (Base *)(&d);
	pbase->display();
	return 0;
}
