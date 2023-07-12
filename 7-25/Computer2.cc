 ///
 /// @file    Computer2.cc
 /// @author  gsw(1499186594@qq.com)
 ///
   

#include "Computer.h" //如果分成头文件与实现文件，在实现文件的第一行，一定要放自己的头文件

#include <string.h>
#include <iostream>
using std::cout;
using std::endl;

// 在类之外实现成员函数
void Computer::setBrand(const char *brand)
{
	strcpy(_brand, brand);
}

void Computer::setPrice(float price)
{
	_price = price;
}

void Computer::print()
{
	cout << "brand: " << _brand << endl;
	cout << "price: " << _price << endl;
}

