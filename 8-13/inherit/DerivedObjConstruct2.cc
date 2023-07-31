 ///
 /// @file    DerivedObjConstruct2.cc
 /// @author  gsw(1499186594@qq.com)
 ///
   
#include <iostream>
using std::cout;
using std::endl;

class Base
{
public:
	Base() : _dbase(0)
	{
		cout << "Base()" << endl;
	}

	Base(double dbase)
		: _dbase(dbase)
	{
		cout << "Base(double)" << endl;
	}

	double getBase() const { return _dbase; }

	~Base() { cout << "~Base()" << endl; }

private:
	double _dbase;
};

class Point
{
public:
	Point(int ix = 0, int iy = 0)
		: _ix(ix), _iy(iy)
	{
		cout << "Point(int = 0,int = 0)" << endl;
	}

	int getX() const { return _ix; }

protected:
	int getY() const { return _iy; }

public:
	void display() const
	{
		cout << "(" << _ix
			 << "," << _iy
			 << ")" << endl;
	}

private:
	int _ix;
	int _iy;
};

class Derived
	: public Base
{
public:
	Derived()
		: Base(), _pt()
	{
		cout << "Derived()" << endl;
	}

	Derived(double dBase, double dDerived)
		: Base(dBase), _dDerived(dDerived), _pt(1, 2)
	{
		cout << "Derived(double,double)" << endl;
	}

	void display() const
	{
		cout << "Derived::display()" << endl;
		cout << "Base::dbase = " << getBase() << endl;
		cout << "Derived::dDerived = " << _dDerived << endl;
		_pt.display();
	}

	~Derived()
	{ // 在派生类析构函数中，是没有主动调用基类的析构函数的
		// 但最终的结果中，是能看到基类析构函数调用的过程的
		cout << "~Derived()" << endl;
	}

private:
	double _dDerived;
	Point _pt;
};

// 派生类对象的构造：有问题的说法( 先调基类的构造函数，再调派生类构造函数)
// 1. 首先调用派生类的构造函数
// 2. 然后在执行派生类构造函数过程之中，要执行初始化列表；
// 3. 再在初始化列表执行的过程中调用了基类的构造函数

int main(void)
{
	Derived d(11.11, 22.22); // 调用默认构造函数创建对象
	d.display();

	return 0;
}

