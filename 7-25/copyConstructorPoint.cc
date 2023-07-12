 ///
 /// @file    copyConstructorPoint.cc
 /// @author  gsw(1499186594@qq.com)
 ///
   

#include <iostream>
using std::cout;
using std::endl;

class Point
{
public:
	Point()
		: _ix(0), _iy(0)
	{
		cout << "Point()" << endl;
	}

	Point(int ix, int iy)
		: _ix(ix), _iy(iy)
	{
		cout << "Point(int,int)" << endl;
	}

	// 系统会自动复制构造函数
	//
	// 1. 复制构造函数的参数中的引用不能删掉：
	//		如果删除，根据复制构造函数的调用时机的第一种情况，接着会
	//		无限调用复制构造函数本身，进入到无穷递归的情况，直到栈溢出
	// 2. 复制构造函数参数中的const不可以删除:
	//		如果删除，当传递过来的参数是一个右值（无法直接取地址，非持久的对象）
	//		非const引用不能绑定到右值之上，编译会出错
	//
	Point(const Point &rhs)
		: _ix(rhs._ix), _iy(rhs._iy)
	{
		cout << "Point(const Point &)" << endl;
	}

	void print()
	{
		cout << "(" << _ix
			 << "," << _iy
			 << ")" << endl;
	}

	// 系统提供的析构函数
	~Point()
	{
		// 其作用是用来做清理工作的，不建议显式调用
		cout << "~Point()" << endl;
	}

private:
	int _ix;
	int _iy;
};

int test0(void)
{
	int a = 3;
	int b = a;
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;

	Point pt1(1, 2); // 栈上的对象被销毁时就会自动调用析构函数
	cout << "pt1 = ";
	pt1.print();
	cout << endl;

	Point pt2 = pt1; // pt2是一个新对象, 调用复制构造函数 Point(const Point rhs) // const Point rhs = pt1
	cout << "pt2 = ";
	pt2.print();

	return 0;
}

// 函数的值传递
void func1(Point p) // Point p = pt;
{
	p.print();
}

Point func2()
{
	Point p(3, 4);
	p.print();
	return p; // 进行复制 ,调用复制构造函数
}

int func3()
{
	int a = 1;
	return a;
}

void test1()
{
	Point pt(1, 2);
	func1(pt);
}

void test2()
{

	Point pt = func2(); // 调用复制构造函数Point(Point & rhs)   // Point & rhs = func2();
}

int main(void)
{
	//test0();
	//test1();
	test2();
	return 0;
}

