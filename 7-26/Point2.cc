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
	Point(int ix = 0, int iy = 0)
		: _ix(ix), _iy(iy), _ref(_ix) // 引用成员的初始化必须要放在初始化列表中进行
	{
		cout << "Point(int = 0, int = 0)" << endl;
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
	int _ix;
	int _iy;
	int &_ref;
};

int main(void)
{
	Point pt(1, 2);
	pt.print();
	return 0;
}

