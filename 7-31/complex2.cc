 ///
 /// @file    complex2.cc
 /// @author  gsw(1499186594@qq.com)
 ///
   

#include <iostream>
using std::cout;
using std::endl;

class Complex
{
public:
	Complex(double dreal, double dimag)
		: _dreal(dreal), _dimag(dimag)
	{
		cout << "Complex(double, double)" << endl;
	}

	void display() const
	{ // 欧拉公式    i^2 = -1
		cout << _dreal;
		if (_dimag > 0)
			cout << " + " << _dimag << "i" << endl;
		else if (_dimag < 0)
			cout << " - " << (-1) * _dimag << "i" << endl;
		else
			cout << endl;
	}

	friend Complex operator+(const Complex &, const Complex &);

private:
	double _dreal;
	double _dimag;
};

#if 0
// 运算符重载时，其参数必须是自定义类类型或者是枚举类型
int operator+(int x, int y)
{
	return x - y;
}
#endif

// 友元函数
Complex operator+(const Complex &lhs, const Complex &rhs)
{
	return Complex(lhs._dreal + rhs._dreal,
				   lhs._dimag + rhs._dimag);
}

int main(void)
{
	Complex c1(1, 2);
	c1.display();
	Complex c2(-3, -6);
	c2.display();

	Complex c3 = c1 + c2;
	c3.display();

	return 0;
}

