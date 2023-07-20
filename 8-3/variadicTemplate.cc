 ///
 /// @file    variadicTemplate.cc
 /// @author  gsw(1499186594@qq.com)
 ///
   

#include <iostream>
using std::cout;
using std::endl;

template <typename... Args> // Args 称为模板参数包, 在声明的时候，...在左边的
void display(Args... args)	// args称为函数参数包, 在使用时，需要展开参数包，...在右边
{
	cout << sizeof...(Args) << endl; // 在编译期就能拿到可变参数的个数
	cout << sizeof...(args) << endl; // 求取可变参数的个数
}

int test0(void)
{
	int a = 1;
	double b = 2.2;
	std::string s = "hello,world";
	display(a, b, s, 'A');

	return 0;
}

// 递归调用的出口
/*
void print()
{
	cout << endl;
}
*/

template <typename T>
void print(T t)
{
	cout << t << endl;
}

template <typename T, typename... Args>
void print(T t, Args... args)
{
	cout << t << "\n";
	print(args...);
}

void test1(void)
{
	int a = 1;
	double b = 2.2;
	std::string s = "hello,world";
	print(a, b, s, 'A');
	// 第一次调用
	// cout << a << ",";
	// print(b, s, 'A');
	// 第二次调用
	//   cout << b << ",";
	//   print(s, 'A');
	//
	// 第三次调用
	//	cout << s << ",";
	//	print('A');
	//
	// 第四次调用
	//	cout << 'A' << ",";
	//	print();
}

template <typename T>
T sum(T t)
{
	return t;
}

template <typename T, typename... Args>
T sum(T t, Args... args)
{
	return t += sum(args...);
}

void test2(void)
{
	cout << sum(1, 2, 3, 4) << endl;
	// return 1 += sum(2, 3, 4);
	// return 1 += (2 += sum(3, 4))
	// return 1 += (2 += (3 += sum(4)))
	// return 1 += (2 += (3 += 4))
}

int main(void)
{
	test2();

	return 0;
}

