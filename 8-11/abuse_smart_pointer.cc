 ///
 /// @file    abuse_smart_pointer.cc
 /// @author  gsw(1499186594@qq.com)
 ///
   
#include <iostream>
#include <memory>
using std::cout;
using std::endl;
using std::shared_ptr;
using std::unique_ptr;

class Point
	: public std::enable_shared_from_this<Point> // 继承辅助类
{
public:
	Point(int ix = 0, int iy = 0)
		: _ix(ix), _iy(iy)
	{
		cout << "Point(int,int) " << endl;
	}

	~Point()
	{
		cout << "~Point()" << endl;
	}

	void display() const
	{
		cout << "(" << _ix
			 << "," << _iy
			 << ")" << endl;
	}

	shared_ptr<Point> addPoint(Point *pt)
	{
		_ix += pt->_ix;
		_iy += pt->_iy;
		return shared_from_this(); // 在类内部返回本对象的shared_ptr智能指针
		// return shared_ptr<Point>(this);
	}

	friend std::ostream &operator<<(std::ostream &os, const Point &rhs);

private:
	int _ix;
	int _iy;
};

std::ostream &operator<<(std::ostream &os, const Point &rhs)
{
	os << "(" << rhs._ix
	   << "," << rhs._iy
	   << ")";
	return os;
}

void test0(void)
{
	Point *pt = new Point(1, 2);
	unique_ptr<Point> up(pt);
	unique_ptr<Point> up2(pt);

	up->display();
	up2->display();
}

void test1(void)
{
	// 将一个原生裸指针交给两个不同的智能指针进行托管
	Point *pt = new Point(1, 2);
	shared_ptr<Point> sp(pt);
	// shared_ptr<Point> sp2(pt);
	shared_ptr<Point> sp2(sp);

	sp->display();
	sp2->display();
}

void test2(void)
{
	shared_ptr<Point> sp(new Point(1, 2));
	shared_ptr<Point> sp2(new Point(3, 4));

	sp2.reset(sp.get());
}

void test3(void)
{
	unique_ptr<Point> sp(new Point(1, 2));
	unique_ptr<Point> sp2(new Point(3, 4));

	sp2.reset(sp.get());
}

void test4(void)
{
	shared_ptr<Point> sp(new Point(1, 2));
	shared_ptr<Point> sp2(new Point(3, 4));

	shared_ptr<Point> sp3(sp->addPoint(sp2.get()));
}

int main(void)
{
//	test0();
//	test1();
//	test2();
//	test3();
	test4();
	return 0;
}
