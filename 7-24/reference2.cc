 ///
 /// @file    reference2.cc
 /// @author  gsw(1499186594@qq.com)
 ///
   

#include <iostream>
using std::cout;
using std::endl;

// 引用作为函数的返回值

int arr[5] = {0, 1, 2, 3, 4};

int &func(int idx) // 返回值是引用，返回的变量生命周期一定要大于函数本身
{
	return arr[idx];
}

int func1()
{
	int number = 10;
	return number; // 一旦执行return语句时，就会被复制
}

// 不要返回一个局部变量的引用
int &func2()
{
	int number = 10;
	return number;
}

int *func3()
{
	int number = 10;
	return &number;
}

// 不要轻易返回一个堆空间变量的引用，
// 除非有了一个回收空间的策略
int &func4()
{
	int *p = new int(11);
	return *p;
}

int main(void)
{
	cout << func(0) << endl;

	func(0) = 10;
	cout << "arr[0] = " << arr[0] << endl;

	// cout <<	func2() << endl;

	int a = 3, b = 4;
	int c = a + b + func4(); // 每调用一次func4函数，就会产生一次内存泄漏
	cout << "c = " << c << endl;

	int &ref = func4();
	cout << "ref = " << ref << endl;
	delete &ref;

	return 0;
}

