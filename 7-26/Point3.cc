 ///
 /// @file    Point3.cc
 /// @author  gsw(1499186594@qq.com)
 ///
   

#include <iostream>
using std::cout;
using std::endl;

class Point
{
public:
	Point(int ix = 0, int iy = 0)
		: _ix(ix), _iy(iy)
	{
		cout << "Point(int = 0, int = 0)" << endl;
	}

#if 0
	void print(/*  Point * const this  */)
	{
		cout << "void print()" << endl;
		_ix = 100;
		cout << "(" << this->_ix
			 << "," << this->_iy
			 << ")" << endl;
	}
#endif

	void setX(int ix)
	{
		_ix = ix;
	}

#if 1
	// 以后一旦某个函数不会修改数据成员的值，都应该讲其设为const成员函数
	//
	// const成员函数的作用就是用来读取数据成员的
	//
	void print(/*     const Point * const this      */) const
	{
		// this->_ix = 120;
		cout << "void print() const" << endl;
		cout << "(" << this->_ix
			 << "," << this->_iy
			 << ")" << endl;

		// setX(10);//const 成员函数不能调用非const成员函数
	}
#endif

	~Point()
	{
	}

private:
	int _ix;
	int _iy;
};

void func(const Point &rhs)
{
	rhs.print();
}

int main(void)
{
	const int a = 3;
	cout << "a = " << a << endl;

	const Point pt(1, 2); // const对象只能调用const成员函数
	pt.print();

	Point pt2(3, 4); // 非const对象可以调用const成员函数
	pt2.print();
	return 0;
}

