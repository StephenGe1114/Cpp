 ///
 /// @file    typeCastFunction2.cc
 /// @author  gsw(1499186594@qq.com)
 ///
   

#include <math.h>
#include <iostream>
using std::cout;
using std::endl;

class Complex
{
public:
	Complex(double dreal = 0, double dimag = 0)
		: _dreal(dreal), _dimag(dimag)
	{
		cout << "Complex(double, double)" << endl;
	}

	friend std::ostream &operator<<(std::ostream &os, const Complex &rhs);

private:
	double _dreal;
	double _dimag;
};

std::ostream &operator<<(std::ostream &os, const Complex &rhs)
{
	os << rhs._dreal;
	if (rhs._dimag > 0)
		os << " + " << rhs._dimag << "i";
	else if (rhs._dimag < 0)
		os << " - " << (-1) * rhs._dimag << "i";
	return os;
}

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

	// 类型转换函数:
	// 1. 成员函数形式
	// 2. 没有参数
	// 3. 没有返回值类型，但是在函数体内必须以传值方式返回一个目标类型的变量
	//
	// 4. 能不要使用就不要使用
	operator int()
	{
		cout << "operator int()" << endl;
		return _ix * _iy;
	}

#if 0
	operator Complex()
	{
		return Complex(_ix, _iy);
	}
#endif

private:
	int _ix;
	int _iy;
};

int main(void)
{
	Point pt1(1, 2);
	cout << "pt1 = " << pt1 << endl; // 会自动将Point对象转换成int型数据

	return 0;
}

