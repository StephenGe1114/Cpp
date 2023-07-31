 ///
 /// @file    lvalue_rvalue.cc
 /// @author  gsw(1499186594@qq.com)
 ///
   

#include <iostream>
#include <vector>
#include <string>
using std::cout;
using std::endl;
using std::string;
using std::vector;

int test0(void)
{
	int a = 1;
	int b = 2;
	int *pFlag = &a;
	vector<int> vec;

	vec.push_back(1);

	//&(a + b);//右值

	//&(a++);// 后置++  返回的是a变化之前的值，是一个临时变量，右值
	&(++a);
	&pFlag;

	&vec[0];
	//&100;//右值

	//&string("hello");//匿名对象, 右值

	string s1 = "hello";
	string s2 = "world";
	//&(s1 + s2);//右值

	const int &m = 1; // C++11之前， 只有const引用能够绑定到右值
	const int &n = a; // 但同时const引用也能绑定到右值
					  // 这就意味着如果const引用作为函数的参数时，
					  // 是无法区分出传递过来的实参是左值还是右值

	// 右值引用只能绑定到右值，不能绑定到左值
	// int && ref1 = 1;
	// int && ref2 = a;

	return 0;
}

void test1(void)
{
	int a = 10;
	int b = std::move(a); // std::move本质上是一个强制转换
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
}

int main(void)
{
	test1();
	return 0;
}

