 ///
 /// @file    pureVirtualFunc.cc
 /// @author  gsw(1499186594@qq.com)
 ///
   
#include <iostream>
using std::cout;
using std::endl;

// 定义了纯虚函数的类称为抽象类, 不能创建对象
//
// 抽象类的作用是作为接口存在, 其内部的纯虚函数要交给其派生类来实现
//
class Base
{
public:
	virtual void display() const = 0; // 纯虚函数，只有声明，没有实现

	virtual void print() const = 0;
};

class Derived1
	: public Base
{ // 一个派生类一定要实现抽象类的所有的纯虚函数，
  // 否则该派生类也会称为抽象类
public:
	void display() const
	{
		cout << "Derived1::display()" << endl;
	}
};

class Dervied2
	: public Derived1
{
public:
	void print() const
	{
		cout << "Dervied2::print()" << endl;
	}
};

void test(Base *pbase)
{
	pbase->display();
	pbase->print();
}

int main(void)
{
	// Derived1 d1;
	Dervied2 d2;
	test(&d2);

	return 0;
}

