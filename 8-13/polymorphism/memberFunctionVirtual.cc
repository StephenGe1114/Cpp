 ///
 /// @file    memberFunctionVirtual.cc
 /// @author  gsw(1499186594@qq.com)
 ///
   
#include <iostream>
using std::cout;
using std::endl;

class Base
{
public:
	Base(double dbase)
		: _dbase(dbase)
	{
		cout << "Base(double)" << endl;
	}

	virtual void display() const
	{
		cout << "Base::_dbase = " << _dbase << endl;
	}

	void callFunc1()
	{
		this->display(); // 展现动态多态
	}

	void callFunc2()
	{
		Base::display(); // 静态联编
	}

private:
	double _dbase;
};

class Derived
	: public Base
{
public:
	Derived(double ibase, double ddreived)
		: Base(ibase), _dderived(ddreived)
	{
		cout << "Derived()" << endl;
	}

	void display() const
	{
		cout << "Derived::_dderived = " << _dderived << endl;
	}

private:
	double _dderived;
};

int main(void)
{
	Base base(1);
	base.callFunc1();
	base.callFunc2();
	cout << endl;

	Derived d1(10, 11);
	d1.callFunc1();
	d1.callFunc2();

	return 0;
}

