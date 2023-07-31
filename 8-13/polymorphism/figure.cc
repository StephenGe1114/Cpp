 ///
 /// @file    figure.cc
 /// @author  gsw(1499186594@qq.com)
 ///
   
#include <math.h>
#include <iostream>
using std::cout;
using std::endl;

//
// 多态的实现： 继承 + 虚函数
//
// 满足面向对象设计原则之一：
//	对修改关闭，对扩展开放
class Figure
{
public:
	virtual void display() const = 0;

	virtual double area() = 0;
};

void test(Figure *fig)
{
	fig->display();
	cout << "的面积:" << fig->area() << endl;
}

class Circle
	: public Figure
{
public:
	Circle(double radius)
		: _radius(radius)
	{
	}

	void display() const
	{
		cout << "circle";
	}

	double area()
	{
		return 3.14159 * _radius * _radius;
	}

private:
	double _radius;
};

class Rectangle
	: public Figure
{
public:
	Rectangle(double length, double width)
		: _length(length), _width(width)
	{
	}

	void display() const
	{
		cout << "rectangle";
	}

	double area()
	{
		return _length * _width;
	}

private:
	double _length;
	double _width;
};

class Triangle
	: public Figure
{
public:
	Triangle(double a, double b, double c)
		: _a(a), _b(b), _c(c)
	{
	}

	void display() const
	{
		cout << "triangle";
	}

	double area()
	{ // 海伦公式
		double p = (_a + _b + _c) / 2;
		return sqrt(p * (p - _a) * (p - _b) * (p - _c));
	}

private:
	double _a;
	double _b;
	double _c;
};

int main(void)
{
	Circle circle(10);
	Rectangle rectangle(10, 20);
	Triangle triangle(3, 4, 5);
	test(&circle);
	test(&rectangle);
	test(&triangle);

	return 0;
}

