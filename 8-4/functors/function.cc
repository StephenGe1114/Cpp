 ///
 /// @file    function.cc
 /// @author  gsw(1499186594@qq.com)
 ///
   

#include <iostream>
#include <functional>
using std::cout;
using std::endl;

void display()
{
	cout << "display()" << endl;
}

void print()
{
	cout << "print()" << endl;
}

typedef void (*Function)();

void callFunction(Function f)
{
	if (f)
	{
		f();
	}
}

void test0(void)
{
	Function f = display; // 注册函数指针
	f();

	f = print;
	f();
}
void test1(void)
{
	callFunction(display);
	callFunction(print);
}

int add(int x, int y)
{
	return x + y;
}

struct Foo
{
	int add(int x, int y)
	{
		return x + y;
	}

	void display(int x, int y)
	{
		cout << "x = " << x << ", y = " << y << endl;
	}

	int value = 100;
};

int test2(void)
{
	// test1();
	auto f1 = std::bind(&add, 1, 2); // 提前绑定函数的实参
	cout << "f1() = " << f1() << endl;

	// 占位符
	std::function<int(int)> f2 = std::bind(&add, 1, std::placeholders::_1);
	cout << "f2(10) = " << f2(10) << endl;
	auto f3 = std::bind(add, std::placeholders::_1, std::placeholders::_2);
	cout << "f3(10, 20) = " << f3(10, 20) << endl;
	Foo foo;
	//
	// bind除了可以绑定普通函数外，还可以绑定成员函数
	// 当bind绑定成员函数时，必须在成员函数前加上取地址符号&
	//
	// 使用bind时，有几个形参就要绑定几个形参，如果不提前绑定的
	// 必须要使用占位符占住形参相对应的位置
	// 占位符的数字代表的是实参传递时的位置
	//
	auto f4 = std::bind(&Foo::add, &foo, std::placeholders::_1, std::placeholders::_4);
	cout << "f4(20) = " << f4(20, 10, 30, 40) << endl;

	return 0;
}

void func(int x1, int &ref)
{
	cout << "x1 = " << x1 << ", ref = " << ref << endl;
}

int test3(void)
{
	int num = 10;

	// bind提前绑定参数时，采用的是值传递, 意味着会发生复制
	auto f = std::bind(func, num, std::ref(num)); // std::ref 是引用包装器
	Foo foo;
	num = 20;
	f();
	cout << endl;

	// 对于成员函数，第一个参数是this指针
	// 但使用std::bind提前绑定this参数时，既可以是对象，也可以是指针
	std::function<int(int, int)> f2 = std::bind(&Foo::add, foo, std::placeholders::_1, std::placeholders::_2);
	cout << "f2(1, 2) = " << f2(1, 2) << endl;
	return 0;
}

void test4()
{
	Foo foo;
	// std::bind居然还可以绑定到数据成员上
	auto f = std::bind(&Foo::value, foo);
	cout << "f() = " << f() << endl;
}
void test5(void)
{
	// std::function是一个类模板，可以把他看成是函数的容器
	std::function<void()> f;
	f = display;
	f();
	f = print;
	f();

	f = std::bind(&Foo::display, Foo(), 1, 2); // 替换多态的实现
	f();
}

int main(void)
{

	test0();
	cout << "-----------------------------------------------------" << endl;
	test1();
	cout << "-----------------------------------------------------" << endl;
	test2();
	cout << "-----------------------------------------------------" << endl;
	test3();
	cout << "-----------------------------------------------------" << endl;
	test4();
	cout << "-----------------------------------------------------" << endl;
	test5();
	return 0;
}

