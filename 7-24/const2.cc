 ///
 /// @file    const2.cc
 /// @author  gsw(1499186594@qq.com)
 ///
   
#include <iostream>
using std::cout;
using std::endl;

// int (*p) []  vs     int * p []
// 数组指针   vs   指针数组
// int (*p)()  vs   int * pfunc()
// 函数指针   vs   指针函数

// 常量指针  vs  指针常量

void test0(void)
{
	int num1 = 10;
	int num2 = 11;
	const int *pa = &num1; // 常量指针(pointer to const)
	//*pa = 20;//error  不能通过指针pa更改所指变量的值
	pa = &num2; // 可以改变指针pa的指向

	int const *pb = &num1;
	//*pb = 20;//error
	pb = &num2;

	int *const pc = &num1; // 指针常量(const pointer)
	*pc = 20;			   // 可以通过指针pc改变所指变量的值
	// pc = &num2;//error, 不能改变指针的指向

	const int *const pd = &num1; // 两者都不能进行修改
}

int main(void)
{
	test0();
	return 0;
}

