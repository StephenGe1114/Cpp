 ///
 /// @file    multiDerived2.cc
 /// @author  gsw(1499186594@qq.com)
 ///
   
#include <iostream>
using std::cout;
using std::endl;

class A
{
public:
	A() : _ia(0) { cout << "A()" << endl; }

	A(double ia) : _ia(ia) {}

	void show() const
	{
		cout << "&A::_ia = " << &_ia << endl;
		cout << "A::print(), A::_ia = " << _ia << endl;
	}

private:
	double _ia;
};

class B
	: virtual public A // 虚继承
{
public:
	B() : A(10) {}

	void display() const
	{
		cout << "B::display()" << endl;
	}

	double _ib;
};

class C
	: virtual public A
{
public:
	C() : A(20) {}
	void print() const
	{
		cout << "C::print()" << endl;
	}

	double _ic;
};

class D
	: public B,
	  public C
{
	double _id;
};

int main(void)
{
	D d;
	d.show();	 // 多基派生时的第二种问题：菱形继承产生的存储二义性问题
	d.B::show(); // 直接通过作用域限定符是无法解决该问题的
	d.C::show(); // 解决方案：采用虚继承
	d.A::show();
	return 0;
}

