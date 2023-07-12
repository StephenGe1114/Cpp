 ///
 /// @file    Point.cc
 /// @author  gsw(1499186594@qq.com)
 ///
   

#include <iostream>
using std::cout;
using std::endl;

class Point
{
public:
	// 如果没有定义任何构造函数，系统会提供一个默认构造函数
	//
	// 构造函数的作用：就是初始化数据成员
	//
	Point()
		: _ix(0), _iy(0) // 初始化表达式（初始化列表）, 这里才是真正的对数据成员初始化
	{
		cout << "Point()" << endl;
	}

	// 一旦定义了自己的构造函数，系统就不会再提供默认构造函数;
	// 如果还想调用默认构造函数创建对象，就必须要手动提供
	//
	// 构造函数时可以重载的
	//
	Point(int ix, int iy)
		: _ix(ix), _iy(iy)
	{
		cout << "Point(int,int)" << endl;
		//_ix = ix;// 赋值语句
		//_iy = iy;
	}

	void print()
	{
		cout << "(" << _ix
			 << "," << _iy
			 << ")" << endl;
	}

private:
	int _ix;
	int _iy;
};

int main(void)
{
	Point pt; // 这里调用系统提供的默认构造函数
	// Point pt();   不能这样写，是一个函数声明，而不是创建对象
	pt.print();

	Point pt2(1, 2);
	pt2.print();

	int a = 3;
	int b(4); // 初始化
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;

	return 0;
}

