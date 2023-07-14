 ///
 /// @file    Demo.cc
 /// @author  gsw(1499186594@qq.com)
 ///
   

#include <iostream>
using std::cout;
using std::endl;

void display()
{
	static int counter = 0;
	cout << "display()" << endl;
	++counter;
}

struct Foo
{
	Foo() : counter(0) {}
	int operator()(int x, int y)
	{
		++counter;
		return x * y;
	}

	int operator()(int x, int y, int z)
	{
		return x + y + z;
	}

	int counter;
};

int main(void)
{
	display(); // 函数调用
	Foo foo;
	cout << foo(3, 4) << endl; // 重载了函数调用运算符的类创建的对象，称为 函数对象
							   // 函数对象携带了状态  ==> 闭包  ==> lambda表达式 (匿名函数对象)
	cout << foo.counter << endl;
	cout << foo(3, 4, 5) << endl;

	Foo foo1;
	return 0;
}

