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
	Point(int ix = 0, int iy = 0)
		: _ix(ix), _iy(iy)
	{
		cout << "Point(int = 0, int = 0)" << endl;
		//_ix = ix;//赋值语句, 并不是初始化
		//_iy = iy;
	}

	void print(/*  Point * const this  */)
	{
		// this = 0x1000;
		cout << "(" << this->_ix
			 << "," << this->_iy
			 << ")" << endl;
	}

	~Point()
	{
	}

private:
	const int _ix; // 加上const关键字之后，一旦对象创建完毕，该成员就不能再修改
	const int _iy;
};

int main(void)
{
	Point pt(1, 2);
	pt.print();
	return 0;
}

