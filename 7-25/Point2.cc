 ///
 /// @file    Point2.cc
 /// @author  gsw(1499186594@qq.com)
 ///
   

#include <iostream>
using std::cout;
using std::endl;

class Point
{
public:
	Point()
		: _ix(0), _iy(0) // 初始化表达式（初始化列表）, 这里才是真正的对数据成员初始化
	{
		cout << "Point()" << endl;
	}

	Point(int ix, int iy)
		: _ix(ix), _iy(iy)
	{
		cout << "Point(int,int)" << endl;
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
	Point pt; // 这里调用系统提供的默认构造函数
	// Point pt();   不能这样写，是一个函数声明，而不是创建对象
	pt.print();

	Point pt2(1, 2); // 栈上的对象被销毁时就会自动调用析构函数
	pt2.print();
	pt2.~Point();

	int a = 3;
	int b(4); // 初始化
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;

	return 0;
}

int main(void)
{
	test0();
	return 0;
}

