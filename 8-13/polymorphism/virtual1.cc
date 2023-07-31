 ///
 /// @file    virtual1.cc
 /// @author  gsw(1499186594@qq.com)
 ///
   
#include <iostream>
using std::cout;
using std::endl;

class Base
{
public:
	Base(double ibase)
		: _ibase(ibase)
	{
		cout << "Base(int)" << endl;
	}

	// 1. 虚函数的实现原理：虚表(虚函数表)
	// 使用virtual修饰一个函数之后，该函数成为虚函数，
	// 同时类占据的空间之中会多一个虚函数指针, 该虚函数
	// 指针位于对象存储空间的最开始的位置，指向的是一张
	// 虚函数表，虚函数表里面存储的是相应虚函数的入口地址

	// 2. 如何激活虚函数机制,如何展现动态多态特性？
	//> 基类定义虚函数，派生类覆盖（重定义）虚函数
	//> 创建派生类对象
	//> 用基类指针指向派生类对象
	//> 用基类指针调用虚函数
	//
	virtual void display() const
	{
		cout << "Base::_ibase = " << _ibase << endl;
	}

private:
	double _ibase;
};

class Derived
	: public Base
{
public:
	Derived(double ibase, double iderived)
		: Base(ibase), _iderived(iderived)
	{
		cout << "Derived(int,int)" << endl;
	}

#if 1
	void display() const
	{
		cout << "Derived::_iderived = " << _iderived << endl;
	}
#endif

private:
	double _iderived;
};
// 多态展现：同一种行为，不同对象表现不同
//
// 当调用虚函数时，被真正执行的函数只与传递过来的对象有关，而与指针类型无关
//
void display(Base *pbase)
{
	pbase->display();
}

int test0(void)
{
	Base base(1);
	Derived derived(10, 11);
	display(&base);
	display(&derived);

	return 0;
}

int test1(void)
{
	cout << "sizeof(Base) = " << sizeof(Base) << endl;
	cout << "sizeof(Derived) = " << sizeof(Derived) << endl;

	return 0;
}

int main(void)
{
	test0();
	cout << "-------------------" << endl;
	test1();
	return 0;
}

