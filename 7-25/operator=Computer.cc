 ///
 /// @file    operator=Computer.cc
 /// @author  gsw(1499186594@qq.com)
 ///
   

#include <string.h>
#include <iostream>
using std::cout;
using std::endl;

class Computer
{
public:
	Computer(const char *brand, float price)
		: _brand(new char[strlen(brand) + 1]()), _price(price)
	{
		cout << "Computer(const char *, float)" << endl;
		strcpy(_brand, brand);
	}

#if 0
	//系统提供的复制构造函数
	Computer(const Computer & rhs)
	: _brand(rhs._brand) // (浅拷贝)
	, _price(rhs._price)
	{
		cout << "Computer(const Computer &)" << endl;
	}
#endif
	Computer(const Computer &rhs)
		: _brand(new char[strlen(rhs._brand) + 1]()), _price(rhs._price)
	{
		cout << "Computer(const Computer &)" << endl;
		strcpy(_brand, rhs._brand); // 先开空间，再复制  （深拷贝）
	}

	// 系统提供的赋值运算符函数 不满足需求
#if 0
	Computer & operator=(const Computer & rhs)
	{
		this->_brand = rhs._brand;
		this->_price = rhs._price;
		return *this;
	}
#endif
	Computer &operator=(const Computer &rhs)
	{
		if (this != &rhs)
		{ // 1. 考虑自复制问题
			// 2. 回收左操作数开辟的空间
			delete[] _brand;

			// 3. 再进行深拷贝
			_brand = new char[strlen(rhs._brand) + 1]();
			strcpy(_brand, rhs._brand);

			_price = rhs._price;
		}
		return *this;
	}

	void print()
	{
		cout << "brand: " << _brand << endl;
		cout << "price: " << _price << endl;
	}

	~Computer()
	{
		cout << "~Computer()" << endl;
		delete[] _brand;
	}

private:
	char *_brand;
	float _price;
};

int test0(void)
{
	Computer c1("xiaomi", 6666);
	cout << "c1 = ";
	c1.print();
	cout << endl;

	// 调用复制构造函数
	Computer c2 = c1; // => Computer c2(c1)
	cout << "c2 = ";
	c2.print();
	return 0;
}

void test1(void)
{
	Computer c1("xiaomi", 6666);
	cout << "c1 = ";
	c1.print();
	cout << endl;

	Computer c2("Mac", 10000);
	cout << "c2 = ";
	c2.print();
	cout << endl;

	// c2 对象已经存在了, 此时要进行赋值
	// 调用赋值运算符函数
	c2 = c1; // c2.operator=(c1);
	cout << "c2 = ";
	c2.print();
	cout << endl;

	c1 = c1;
}

int main(void)
{
	test1();
	return 0;
}

