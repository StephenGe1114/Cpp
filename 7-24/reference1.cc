 ///
 /// @file    reference1.cc
 /// @author  gsw(1499186594@qq.com)
 ///
   
#include <iostream>
using std::cout;
using std::endl;

// 引用与指针的差别?
// 相同点:  都有地址的概念
//
// 不同点:
// 1. 指针是可以独立存在的; 但是引用不行
// 2. 引用必须要进行初始化，指针没有必要
// 3. 指针可以设置为NULL， 但是引用不行
// 4. 引用一旦进行初始化之后，不会再改变其指向；但指针可以
//
// 引用是受限制的指针

void test0(void)
{
	int num = 100;
	int &ref = num; // 引用是一个变量的别名, 引用的初始化
	cout << "num = " << num << endl;
	cout << "ref = " << ref << endl;
	cout << "&num = " << &num << endl;
	cout << "&ref = " << &ref << endl;

	ref = 200;
	cout << "修改引用之后:" << endl;
	cout << "num = " << num << endl;
	cout << "ref = " << ref << endl;

	// int & ref1;//error,  引用是不能独立存在的，必须要绑定到某一个变量上
}

// 引用作为函数的参数

// 参数的传递：值传递
#if 0
void swap(int x, int y)
{
	int temp = x;
	x = y;
	y = temp;
}
#endif

// 参数的传递: 地址传递 --> 值传递
void swap(int *px, int *py)
{
	int temp = *px;
	*px = *py;
	*py = temp;
}

// 引用传递它减少了数据的复制, 可以提高程序的执行效率
//
// 引用传递操作的就是实参本身
//
void swap(int &x, int &y)
{
	int temp = x;
	x = y;
	y = temp;
}

void test1(void)
{
	int a = 3, b = 4;
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	swap(a, b); // 引用传递比地址传递更直观
	// swap(&a, &b);
	cout << "交换之后:" << endl;
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
}

int main(void)
{
	// test0();
	test1();

	return 0;
}

