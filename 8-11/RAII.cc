 ///
 /// @file    RAII.cc
 /// @author  gsw(1499186594@qq.com)
 ///
   

#include <iostream>
using std::cout;
using std::endl;

template <typename T>
class RAII
{
public:
	RAII(T *p) : _p(p) {}
	~RAII()
	{
		if (_p)
			delete _p;
	}

	RAII(const RAII &) = delete;
	RAII &operator=(const RAII &) = delete;

	T *operator->()
	{
		return _p;
	}

	T &operator*()
	{
		return *_p;
	}

	T *get() { return _p; }

	void reset(T *p)
	{
		if (_p)
			delete _p;
		_p = p;
	}

private:
	T *_p;
};

class Point
{
public:
	Point(int ix = 0, int iy = 0)
		: _ix(ix), _iy(iy)
	{
		cout << "Point(int,int)" << endl;
	}

	~Point() { cout << "~Point()" << endl; }

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

int main(void)
{
	RAII<Point> pPoint(new Point(1, 2));
	pPoint->display();
	(*pPoint).display();
	cout << endl;

	cout << "执行reset之后:" << endl;
	pPoint.reset(new Point(3, 4));
	pPoint->display();

//	RAII<Point> p2(pPoint);

	return 0;
}

