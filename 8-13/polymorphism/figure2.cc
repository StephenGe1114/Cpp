 ///
 /// @file    figure2.cc
 /// @author  gsw(1499186594@qq.com)
 ///
   
#include <math.h>
#include <iostream>
#include <functional>
using std::cout;
using std::endl;

//
// 多态的实现： 基于对象--> std::function + std::bind
// 这种方式灵活性更强，类与类之间的关系基本上是解耦, 松散的
//
// std::function --> 类模板 --> 容纳一个函数标签, 看成是一个函数的容器
// std::bind --> 函数模板 --> 返回值是函数对象
//

class Figure
{
public:
	using DisplayCallback = std::function<void()>;
	using AreaCallback = std::function<double()>;

	// 注册回调函数
	void setDisplayCallback(DisplayCallback &&cb)
	{
		_displayCallback = std::move(cb);
	}

	void setAreaCallback(AreaCallback &&cb)
	{
		_areaCallback = std::move(cb);
	}

	// 执行回调函数
	void handleDisplayCallback()
	{
		if (_displayCallback)
			_displayCallback();
	}

	double handleAreaCallback()
	{
		if (_areaCallback)
			return _areaCallback();
		else
			return 0;
	}

private:
	DisplayCallback _displayCallback;
	AreaCallback _areaCallback;
};

void test(Figure &fig)
{
	fig.handleDisplayCallback();
	cout << "的面积:" << fig.handleAreaCallback() << endl;
}

class Circle
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
{
public:
	Rectangle(double length, double width)
		: _length(length), _width(width)
	{
	}

	void print() const
	{
		cout << "rectangle";
	}

	double calcArea()
	{
		return _length * _width;
	}

private:
	double _length;
	double _width;
};

class Triangle
{
public:
	Triangle(double a, double b, double c)
		: _a(a), _b(b), _c(c)
	{
	}

	void show() const
	{
		cout << "triangle";
	}

	double getArea()
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
	Figure fig;
	fig.setDisplayCallback(std::bind(&Circle::display, &circle));
	fig.setAreaCallback(std::bind(&Circle::area, &circle));
	test(fig);

	fig.setDisplayCallback(std::bind(&Rectangle::print, &rectangle));
	fig.setAreaCallback(std::bind(&Rectangle::calcArea, &rectangle));
	test(fig);

	fig.setDisplayCallback(std::bind(&Triangle::show, &triangle));
	fig.setAreaCallback(std::bind(&Triangle::getArea, &triangle));
	test(fig);

	return 0;
}
