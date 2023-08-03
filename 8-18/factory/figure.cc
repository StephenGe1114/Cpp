 ///
 /// @file    figure.cc
 /// @author  gsw(1499186594@qq.com)
 ///
  
#include <math.h>
#include <iostream>
#include <memory>
using std::cout;
using std::endl;
using std::unique_ptr;
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

	virtual ~Figure() {}
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
		cout << "Circle()" << endl;
	}

	~Circle() { cout << "~Circle()" << endl; }

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
		cout << "Rectangle()" << endl;
	}

	~Rectangle() { cout << "~Rectangle()" << endl; }

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
		cout << "Triangle()" << endl;
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

	~Triangle() { cout << "~Triangle()" << endl; }

private:
	double _a;
	double _b;
	double _c;
};

// 工厂模式：
//	满足单一职责原则，也满足开闭原则，还满足依赖倒置原则
//
// 适用场景:
//	1. 产品多样化
//	2. 产品的创建本身比较复杂, 复杂对象
//	3. 如果是简单对象，完全没有必要使用工厂模式
//
class Factory
{
public:
	virtual Figure *createFigure() = 0;

	virtual ~Factory() {}
};

class CircleFactory
	: public Factory
{
public:
	Figure *createFigure()
	{
		// load xml
		// 获取节点信息
		// 最终获取到半径
		Figure *p = new Circle(10);
		return p;
	}
};

class RectangleFactory
	: public Factory
{
	Figure *createFigure()
	{
		// load xml
		// 获取节点信息
		// 最终获取到长和宽
		Figure *p = new Rectangle(10, 20);
		return p;
	}
};

class TriangleFactory
	: public Factory
{
public:
	Figure *createFigure()
	{
		// load xml
		// 获取节点信息
		// 最终获取到三边
		Figure *p = new Triangle(3, 4, 5);
		return p;
	}
};

int main(void)
{
	unique_ptr<Factory> circleFactory(new CircleFactory());
	unique_ptr<Figure> pcircle(circleFactory->createFigure());

	unique_ptr<Factory> rectangleFactory(new RectangleFactory());
	unique_ptr<Figure> prectangle(rectangleFactory->createFigure());

	unique_ptr<Factory> triangleFactory(new TriangleFactory());
	unique_ptr<Figure> ptriangle(triangleFactory->createFigure());

	test(pcircle.get());
	test(prectangle.get());
	test(ptriangle.get());

	return 0;
}

