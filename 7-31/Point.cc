 ///
 /// @file    Point.cc
 /// @author  gsw(1499186594@qq.com)
 ///
   

#include <math.h>
#include <iostream>
using std::cout;
using std::endl;

class Point
{
public:
	Point(int ix = 0, int iy = 0)
		: _ix(ix), _iy(iy)
	{
		cout << "Point(int,int) " << endl;
	}

	void print() const
	{
		cout << "(" << _ix
			 << "," << _iy
			 << ")";
	}

	// 友元函数之普通函数(非成员函数)
	friend float distance(const Point &lhs, const Point &rhs);

private:
	int _ix;
	int _iy;
};

float distance(const Point &lhs, const Point &rhs)
{
	return sqrt((lhs._ix - rhs._ix) * (lhs._ix - rhs._ix) +
				(lhs._iy - rhs._iy) * (lhs._iy - rhs._iy));
}

int main(void)
{
	Point pt1(1, 2), pt2(3, 4);
	pt1.print();
	cout << "到";
	pt2.print();
	cout << "的距离是:" << distance(pt1, pt2) << endl;
	return 0;
}

