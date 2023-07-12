 ///
 /// @file    Computer.cc
 /// @author  gsw(1499186594@qq.com)
 ///
   

#include <string.h>
#include <iostream>
using std::cout;
using std::endl;

class Computer
{
public:
	Computer(const char *brand, double price)
		: _brand(new char[strlen(brand) + 1]()), _price(price)
	{
		cout << "Computer(const char *, float)" << endl;
		strcpy(_brand, brand);

		_totalPrice += _price;
	}

	Computer(const Computer &rhs)
		: _brand(new char[strlen(rhs._brand) + 1]()), _price(rhs._price)
	{
		cout << "Computer(const Computer &)" << endl;
		strcpy(_brand, rhs._brand);
	}

	Computer &operator=(const Computer &rhs)
	{
		cout << "Comuter & operator=(const Computer &)" << endl;
		if (this != &rhs)
		{
			delete[] _brand;
			_brand = new char[strlen(rhs._brand) + 1]();
			strcpy(_brand, rhs._brand);

			_price = rhs._price;
		}
		return *this;
	}

	void print()
	{
		cout << "brand: " << this->_brand << endl;
		cout << "price: " << this->_price << endl;
	}

	// 静态成员函数没有隐含的this指针,
	// 不能访问非静态的数据成员和成员函数
	// 只能访问静态数据成员和静态成员函数
	static void printTotalPrice()
	{
		// cout << "brand: " << _brand << endl;
		// cout << "price: " << _price << endl;
		// print();
		cout << "totalPrice: " << _totalPrice << endl;
	}

	~Computer()
	{
		cout << "~Computer()" << endl;
		_totalPrice -= _price;
		delete[] _brand;
	}

private:
	char *_brand;
	double _price;

	static double _totalPrice; // 被该类的所有对象共享, 并不占据对象的存储空间
};

// 静态数据成员必须在类之外进行初始化
double Computer::_totalPrice = 0;

void test1(void)
{
	cout << "sizeof(Computer) = " << sizeof(Computer) << endl;
	Computer c1("xiaomi", 6666);
	cout << "c1 = ";
	c1.print();
	// c1.printTotalPrice();

	Computer::printTotalPrice(); // 静态成员函数可以直接类名进行调用
	cout << endl;

	Computer c2("Mac", 10000);
	cout << "c2 = ";
	c2.print();
	// c2.printTotalPrice();
	Computer::printTotalPrice();
	cout << endl;
}

int main(void)
{
	test1();
	return 0;
}

