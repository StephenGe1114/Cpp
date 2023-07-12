 ///
 /// @file    copyConstructor.cc
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

int main(void)
{
	Computer c1("xiaomi", 6666);
	cout << "c1 = ";
	c1.print();
	cout << endl;

	Computer c2 = c1; // Computer c2(c1)
	cout << "c2 = ";
	c2.print();
	return 0;
}

