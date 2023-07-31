 ///
 /// @file    private_Point3D.cc
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
	//: private Point //实现继承
	: Point // 默认情况下 就是 private继承
{
public:
	Point3D(int ix, int iy, int iz)
		: Point(ix, iy), _iz(iz)
	{
		cout << "Point3D(int,int,int)" << endl;
	}

	// _ix, _iy: 私有继承时，派生类内部是不能访问基类的私有成员
	// 如果采用的是私有继承，除了基类的私有成员之外，其他的成员在派生类内部都是private
	void print() const
	{
		cout << "(" << getX() // private
			 << "," << getY() // private
			 << "," << _iz
			 << ")" << endl;
	}

private:
	int _iz;
};

class Point4D
	: private Point3D
{
	void show() const
	{
//		display(); // error
	}
};

int main(void)
{
	Point3D pt(1, 2, 3);
	// pt.display();//private
	// pt.getX();//private
	// pt.getY();//private
	pt.print();
}

