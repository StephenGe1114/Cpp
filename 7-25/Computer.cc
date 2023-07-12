 ///
 /// @file    Computer.cc
 /// @author  gsw(1499186594@qq.com)
 ///
   

#include <string.h>
#include <iostream>
using std::cout;
using std::endl;

// 代码风格
//
// code review   代码走查
//
// 代码写出来之后，其实都是给人看的  --> 可读性 -> 写代码的实力
//

class Computer
{		// 类内部
public: // 类对外提供的接口（服务、功能）
	// 成员函数
	void setBrand(const char *brand)
	{
		strcpy(_brand, brand);
	}

	void setPrice(float price)
	{
		_price = price;
	}

	void print()
	{
		cout << "brand: " << _brand << endl;
		cout << "price: " << _price << endl;
	}

private:
	char _brand[20]; // m_brand数据成员
	float _price;	 // price_
};

int main(void)
{
	int a;

	Computer com;
	com.setBrand("战神"); // .   成员访问运算符
	com.setPrice(8888);
	com.print();

	// com._price = 10000;//error 对于私有成员，不能在类之外访问, 体现的是类的封装特性

	return 0;
}

