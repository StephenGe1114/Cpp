 ///
 /// @file    virtual2.cc
 /// @author  gsw(1499186594@qq.com)
 ///
   
#include <iostream>
using std::cout;
using std::endl;

class Base
{
public:
	// 构造函数不能声明为虚函数，为什么？
	// 答：根据虚函数被激活的条件，可以看出，虚函数执行时，
	//	  是在对象创建完毕之后；对象创建完毕之后才有了虚函数指针
	//
	// virtual
	Base(double ibase)
		: _ibase(ibase), _ix(_ibase)
	{
		cout << "Base(int)" << endl;
	}

	// 1. 虚函数的实现原理：虚表(虚函数表)
	// 使用virtual修饰一个函数之后，该函数成为虚函数，
	// 同时类占据的空间之中会多一个虚函数指针, 该虚函数
	// 指针位于对象存储空间的最开始的位置，指向的是一张
	// 虚函数表，虚函数表里面存储的是相应虚函数的入口地址

	// 2. 虚函数机制被激活的条件,如何展现动态多态特性？
	//> 基类定义虚函数，派生类覆盖（重定义）虚函数
	//> 创建派生类对象
	//> 用基类指针(引用)指向派生类对象
	//> 用基类指针(引用)调用虚函数
	//
	virtual void display() const
	{
		cout << "Base::_ibase = " << _ibase << endl;
	}

	void print(int value) const
	{
		cout << "Base::print()  value = " << value << endl;
	}

private:
	double _ibase;

protected:
	double _ix;
};

class Derived
	: public Base
{
public:
	Derived(double ibase, double iderived)
		: Base(ibase), _iderived(iderived), _ix(_iderived)
	{
		cout << "Derived(int,int)" << endl;
	}

	void print() const
	{
		cout << "Derived::print()" << endl;
	}

	void display() const
	{
		cout << "Derived::_iderived = " << _iderived << endl;
	}

#if 1
	virtual void display(double dvalue) const
	{
		cout << "Derived::_ix = " << _ix << endl; // 基类的同名_ix被隐藏
		cout << "Base::_ix = " << Base::_ix << endl;
		cout << "Derived::_iderived = " << _iderived << endl;
		cout << "Derived::display(double) dvalue = " << dvalue << endl;
	}
#endif

private:
	double _iderived;
	double _ix;
};
// 多态展现：同一种行为，不同对象表现不同
//
// 当调用虚函数时，被真正执行的函数只与传递过来的对象有关，而与指针类型无关
//
void display(Base *pbase)
{
	pbase->display();
	// pbase->display(10.1);//error, Base内部没有相应的函数, 编译无法通过
}

void display(Base &base)
{
	base.display();
}

int test0(void)
{
	Base base(1);
	Derived derived(10, 11);
	display(&base);
	display(&derived);
	cout << endl;

	cout << "采用引用传递:" << endl;
	display(base);
	display(derived);

	Base &ref = derived;
	ref.display();

	return 0;
}

int test1(void)
{
	cout << "sizeof(Base) = " << sizeof(Base) << endl;
	cout << "sizeof(Derived) = " << sizeof(Derived) << endl;

	return 0;
}

void test2(void)
{
	Base base(1);
	Derived derived(11, 12);

	base.print(10);

	derived.print(); // 基类的print() 被隐藏
	// derived.print(20);//基类的同名函数print(int)被隐藏oversee
}

void test3(void)
{
	Base base(1);
	Derived derived(11, 12);

	base.display();			 // 通过对象名调用虚函数时，并不表现出多态特性, 直接去代码区找相应函数
	derived.display();		 // 与虚函数无关, 在这种情况下采用的是隐藏
	derived.Base::display(); // 如果想调用基类的函数，必须要使用作用域限定符

	cout << endl;
	derived.display(100);
}

int main(void)
{
	test0();
	cout << "-----------------" << endl;
	test1();
	cout << "-----------------" << endl;
	test2();
	cout << "-----------------" << endl;
	test3();
	return 0;
}
