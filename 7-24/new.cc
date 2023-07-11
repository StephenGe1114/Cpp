 ///
 /// @file    new.cc
 /// @author  gsw(1499186594@qq.com)
 ///
   
#include <string.h>
#include <stdlib.h>
#include <iostream>
using std::cout;
using std::endl;

// malloc/free与new/delete的差别是什么?
//
// 1. malloc/free是标准库函数, new/delete 是表达式
// 2. malloc只负责开辟空间，但并不会进行初始化;
//    new表达式开辟空间之后，也会进行初始化

void test0(void)
{
	int *p = (int *)malloc(sizeof(int)); // 开辟堆空间
	*p = 10;
	cout << "*p = " << *p << endl;

	int *p2 = (int *)malloc(sizeof(int) * 10);
	::memset(p2, 0, sizeof(int) * 10);
	// bzero();
	for (int idx = 0; idx < 10; ++idx)
		p2[idx] = idx;

	free(p);
	free(p2);
}

void test1(void)
{
	int *p = new int(1);
	cout << "*p = " << *p << endl;

	int *p2 = new int[10]();
	for (int idx = 0; idx < 10; ++idx)
		p2[idx] = idx;

	delete p;
	delete[] p2;
}

int main(void)
{
	test0();
	test1();

	return 0;
}

