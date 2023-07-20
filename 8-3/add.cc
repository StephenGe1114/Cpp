 ///
 /// @file    add.cc
 /// @author  gsw(1499186594@qq.com)
 ///
   

#include <string.h>
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

// 模板 相当于是代码生成器
//
//		  实例化
// 函数模板 -->  模板函数
//		模板参数推导
//
// 类模板  --> 模板类

// 模板参数列表
// 参数有2种:
//	> 类型参数
//	> 非类型参数, 整型

// 在C++11之后，函数模板也是可以设置默认值的
template <typename Type, int kSize = 10>
Type multiply(Type x, Type y)
{
	return x * y * kSize;
}

// 函数模板的声明
template <typename Type>
Type add(Type x, Type y);

// 函数模板与函数模板之间也可以重载
template <typename Type>
Type add(Type x, Type y, Type z)
{
	return x + y + z;
}

// 模板特化, 不能独立存在, 必须先有通用版本，而后才有特化版本
template <>
const char *add<const char *>(const char *p1, const char *p2)
{
	char *ptmp = new char[strlen(p1) + strlen(p2) + 1]();
	strcpy(ptmp, p1);
	strcat(ptmp, p2);
	return ptmp;
}

/*
//普通函数跟函数模板可以重载
int add(int x, int y)
{	//普通函数的执行会优先于函数模板的执行
	cout << "int add(int,int)" << endl;
	return x + y;
}

double add(double x, double y)
{
	return x + y;
}

char add(char x, char y)
{
	return x + y;
}
*/

int main(void)
{
	int a = 3, b = 4, c = 5;
	;
	double d1 = 11.11, d2 = 22.22;
	char c1 = 'A', c2 = 1;
	std::string s1 = "hello";
	std::string s2 = "world";

	const char *p1 = "hello";
	const char *p2 = "world";

	cout << "add(a, b) = " << add(a, b) << endl;			 //  隐式实例化
	cout << "add(d1, d2) = " << add<double>(d1, d2) << endl; // 显式实例化
	cout << "add(c1, c2) = " << add(c1, c2) << endl;
	cout << "add(a, b, c) = " << add(a, b, c) << endl;
	cout << "add(s1, s2) = " << add(s1, s2) << endl;
	cout << "add(p1, p2) = " << add(p1, p2) << endl;
	cout << endl;

	// 在模板之前，是不能在函数调用时改变常量的值；
	// 有了模板之后，可以在实参传递时改变常量的值
	cout << "multiply(a, b) = " << multiply<int, 5>(a, b) << endl;
	cout << multiply(a, b) << endl;

	return 0;
}

// 函数模板的实现
template <typename Type>
Type add(Type x, Type y)
{
	cout << "Type add(Type, Type)" << endl;
	return x + y;
}

