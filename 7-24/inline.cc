 ///
 /// @file    inline.cc
 /// @author  gsw(1499186594@qq.com)
 ///
   

#include <stdio.h>
#include <iostream>
using std::cout;
using std::endl;

// 带参数的宏定义
// 执行的时机：预处理, 进行的是字符串的替换，没有函数调用的开销, 可以提高程序的执行效率
//
// 对于简短的语句，定义为函数之后，函数的执行会有开销
//
// 但是在使用带参数的宏定义时，容易产生错误

#define Max(x, y) ((x) > (y) ? (x) : (y))
#define Multiply(x, y) (x) * (y)

// inline函数 --> 内联函数
// 也会在调用该函数时，用语句替换, 没有函数调用的开销
//
// 相比带参数的宏定义的优势： 有类型检查
inline int max(int x, int y)
{
	return x > y ? x : y;
}

inline int multiply(int x, int y)
{
	return x * y;
}

int main(void)
{
	int a = 3, b = 4, c = 5;
	printf("Max(a,b) = %d\n", Max(a, b));
	printf("Multiply(a + b, c) = %d\n", Multiply(a + b, c)); // a + b*c
	cout << max(a, b) << endl;
	cout << multiply(a + b, c) << endl;

	return 0;
}

