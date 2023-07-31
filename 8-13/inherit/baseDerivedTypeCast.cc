 ///
 /// @file    baseDerivedTypeCast.cc
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
		cout << "Point(int,int)" << endl;
	}

	int getX() const { return _ix; }

protected:
	int getY() const { return _iy; }

public:
	void display() const
	{
		cout << "(" << _ix
			 << "," << _iy
			 << ")" << endl;
	}

private:
	int _ix;
	int _iy;
};

class Point3D
	: public Point // 接口继承
{
public:
	Point3D(int ix, int iy, int iz)
		: Point(ix, iy), _iz(iz)
	{
		cout << "Point3D(int,int,int)" << endl;
	}

	void print() const
	{
		cout << "(" << getX()
			 << "," << getY()
			 << "," << _iz
			 << ")" << endl;
	}

private:
	int _iz;
};

// 参数传递时, 基类与派生类的转换关系为
//	可以把一个派生类对象赋值给基类对象
//	可以把一个基类指针指向派生类对象
//	可以用一个基类引用绑定到派生类对象
//
// 规则: 存储空间大的能适应存储空间小的;反过来不行
void func1(const Point &pt)
{
	pt.display();
}

void func2(const Point3D &pt)
{
	pt.print();
}

int test0(void)
{
	Point3D pt3D(1, 2, 3);
	func1(pt3D); // const Point & pt = pt3D;  //

	Point pt2(4, 5); // const Point3D & pt = pt2;

	// func2(pt2);
	return 0;
}

int test1(void)
{
	Point pt1(1, 2);
	Point3D pt3D(3, 4, 5);

	pt1 = pt3D; // Point & operator=(const Point &)
	pt1.display();

	pt3D = pt1; // Point3D & operator=(const Point3D &)

	Point *p1 = &pt3D;
	p1->display();

	Point3D *p2 = &pt1;
	p2->print();

	return 0;
}

int main()
{
	test0();
	cout << "------------------------------" << endl;
    test1();
	return 0;
}
