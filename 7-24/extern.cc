 ///
 /// @file    extern.cc
 /// @author  gsw(1499186594@qq.com)
 ///
   

// C++语言支持函数重载
//

#include <stdio.h>
#include <iostream>
using std::cout;
using std::endl;

// 按着C的方式进行调用
//
// 实现C和C++的混合编程 , C++兼容C代码的方式
#ifdef __cpluscplus
extern "C"
{
#endif

	int add(int x, int y)
	{
		return x + y;
	}

#ifdef __cpluscplus
} // end of extern "C"
#endif

int add(int x, int y, int z)
{
	return x + y + z;
}

double add(double x, double y, double z)
{
	return x + y + z;
}

int main(void)
{
	int a = 3, b = 4, c = 5;
	printf("a + b = %d\n", add(a, b));
	printf("a + b +c = %d\n", add(a, b, c));

	double d1 = 1.1, d2 = 2.2, d3 = 3.3;
	cout << "d1 + d2 + d3 = " << add(d1, d2, d3) << endl;

	return 0;
}

