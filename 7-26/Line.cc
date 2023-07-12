 ///
 /// @file    Line.cc
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

	void print()
	{
		cout << "(" << this->_ix
			 << "," << this->_iy
			 << ")";
	}

	~Point()
	{
	}

private:
	int _ix;
	int _iy;
};

class Line
{
public:
	// 系统提供的默认构造函数
	Line()
		: _pt1(), _pt2()
	{
	}

	Line(int x1, int y1, int x2, int y2)
		: _pt1(x1, y1) // 对象成员的构造也要放在初始化表达式之中进行
		  ,
		  _pt2(x2, y2) // 即使没有显式调用，系统也会调用相应的默认构造函数
	{
		cout << "Line()" << endl;
	}

	void printLine()
	{
		_pt1.print();
		cout << " ---> ";
		_pt2.print();
		cout << endl;
	}

private:
	Point _pt1;
	Point _pt2;
};

int main(void)
{
	// Point pt(1, 2);
	// pt.print();

	Line line;
	line.printLine();
	return 0;
}

