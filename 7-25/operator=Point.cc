 ///
 /// @file    operator=Point.cc
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

	// 系统提供一个赋值运算符函数
#if 0
	Point & operator=(const Point & rhs)
	{
		_ix = rhs._ix;
		_iy = rhs._iy;
		return *this;// this代表的是当前对象本身
	}
#endif

	// 隐含的this指针, 作为成员函数的第一个参数
	void print(/*     Point * const this     */)
	{
		// this = 0x100;
		cout << "(" << this->_ix
			 << "," << this->_iy
			 << ")" << endl;
	}
	void show();

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

void test1()
{
	int a = 3; // 初始化
	int b = 4;
	a = b; // 赋值语句

	Point pt1(1, 2);
	Point pt2(3, 4);
	cout << "pt1 = ";
	pt1.print();
	cout << "pt2 = ";
	pt2.print();

	cout << "执行赋值操作:" << endl;
	pt2 = pt1;
	cout << "pt2 = ";
	pt1.print();
}

int main(void)
{
	test1();
	return 0;
}

