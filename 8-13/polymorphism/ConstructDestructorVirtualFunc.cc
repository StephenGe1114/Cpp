 ///
 /// @file    ConstructDestructorVirtualFunc.cc
 /// @author  gsw(1499186594@qq.com)
 ///
   
#include <iostream>
using std::cout;
using std::endl;

// 在构造函数和析构函数之中调用虚函数，只会采用静态联编

class Base0
{
public:
	Base0() { cout << "Base0()" << endl; }
	virtual void func1() { cout << "Base0::func1()" << endl; }
	virtual void func2() { cout << "Base0::func2()" << endl; }
	~Base0() { cout << "~Base0()" << endl; }
};

class Base1
	: public Base0
{
public:
	Base1()
		: Base0()
	{
		cout << "Base1()" << endl;
		func1();
	}
#if 1
	virtual
	void func1() {	cout << "Base1::func1()" << endl;	}
	virtual
	void func2() {	cout << "Base1::func2()" << endl;	}
#endif

	~Base1()
	{
		func2();
		cout << "~Base1()" << endl;
	}
};

class Sub
	: public Base1
{
public:
	Sub()
		: Base1()
	{
		cout << "Sub()" << endl;
	}
	virtual void func1() { cout << "Sub::func1()" << endl; }
	virtual void func2() { cout << "Sub::func2()" << endl; }

	~Sub()
	{
		cout << "~Sub()" << endl;
	}
};

int main(void)
{
	Sub sub;

	return 0;
}

