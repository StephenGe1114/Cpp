 ///
 /// @file    complex3.cc
 /// @author  gsw(1499186594@qq.com)
 ///
   

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

	Complex operator+(const Complex &rhs)
	{
		return Complex(_dreal + rhs._dreal, _dimag + rhs._dimag);
	}

private:
	double _dreal;
	double _dimag;
};

int main(void)
{
	Complex c1(1, 2);
	c1.display();
	Complex c2(-3, -6);
	c2.display();

	Complex c3 = c1 + c2;
	c3.display();
	cout << endl;

	Complex c4 = c1 + 5; // c1.operator+(5);   //ok
	cout << "c4 = ";
	c4.display();

	Complex c5 = 5 + c1;

	return 0;
}

