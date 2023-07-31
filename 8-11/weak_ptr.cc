 ///
 /// @file    weak_ptr.cc
 /// @author  gsw(1499186594@qq.com)
 ///
   
#include <iostream>
#include <memory>

using std::cout;
using std::endl;
using std::shared_ptr;
using std::weak_ptr;

class Point
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
	// weak_ptr虽然不能直接访问所托管的资源，但
	// 它知道所托管的资源是否还存活
	weak_ptr<Point> wp;

	{
		// shared_ptr在多线程环境下不能保证是线程安全的
		shared_ptr<Point> sp(new Point(1, 2));

		wp = sp; // 一定涉及到运算符重载的知识

		cout << "wp' use_count() = " << wp.use_count() << endl;
		cout << "sp' use_count() = " << sp.use_count() << endl;

		// 由于weak_ptr无法直接访问资源，它必须要进行提升
		shared_ptr<Point> sp2 = wp.lock();
		if (sp2)
		{
			cout << "weak_ptr提升成功" << endl;
			cout << "*sp2 = " << *sp2 << endl;
		}
		else
		{
			cout << "weak_ptr提升失败, 所托管的对象已经被销毁啦" << endl;
		}
	}
	cout << "在语句块之外：" << endl;

	shared_ptr<Point> sp2 = wp.lock();
	if (sp2)
	{
		cout << "weak_ptr提升成功" << endl;
		cout << "*sp2 = " << *sp2 << endl;
	}
	else
	{
		cout << "weak_ptr提升失败, 所托管的对象已经被销毁啦" << endl;
	}
}

int main(void)
{
	test0();
	return 0;
}

