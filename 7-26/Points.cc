 ///
 /// @file    Points.cc
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

	void print() const
	{
		cout << "(" << this->_ix
			 << "," << this->_iy
			 << ")" << endl;
	}

	~Point()
	{
		cout << "~Point()" << endl;
	}

private:
	int _ix; // 加上const关键字之后，一旦对象创建完毕，该成员就不能再修改
	int _iy;
};

int main(void)
{
	int arr[5];

	Point(1, 2).print(); // 匿名对象

	Point points[5] = {
		Point(1, 2),
		Point(3, 4),
		Point(5, 6)};
	points[0].print();
	return 0;
}

