 ///
 /// @file    multiDerived1.cc
 /// @author  gsw(1499186594@qq.com)
 ///
   
#include <iostream>
using std::cout;
using std::endl;

class A
{
public:
	void show() const
	{
		cout << "A::print()" << endl;
	}
};

class B
{
public:
	void show() const
	{
		cout << "B::display()" << endl;
	}
};

class C
{
public:
	void show() const
	{
		cout << "C::show()" << endl;
	}
};

class D
	: public A,
	  public B,
	  public C
{
};
int main(void)
{
	D d;
	// d.print();
	// d.display();
	// d.show(); // 多基派生产生的第一种问题：成员名冲突
	d.A::show(); // 解决方案：采用作用域限定符
	d.B::show();
	d.C::show();
	return 0;
}

