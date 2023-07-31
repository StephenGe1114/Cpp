 ///
 /// @file    public_Point3D.cc
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
		cout << "(" << getX() // _ix, _iy: 公有继承时，派生类内部是不能访问基类的私有成员
			 << "," << getY()
			 << "," << _iz
			 << ")" << endl;
	}

private:
	int _iz;
};

int main(void)
{
	Point3D pt(1, 2, 3);
	pt.display();
	pt.getX(); // getX()  public
			   // pt.getY();//getY()  protected
}

   
