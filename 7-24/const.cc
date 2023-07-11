 ///
 /// @file    const.cc
 /// @author  gsw(1499186594@qq.com)
 ///
   

#include <iostream>
using std::cout;
using std::endl;

// 一个程序经历的阶段:
// 编辑 --> 预处理(预编译) --> 编译 --> 汇编 --> 链接 --> 执行

// 宏定义发生的时机:预处理, 只是简单的字符串的替换
// （使用宏定义的过程中，有很大的概率会出现问题）
//
//
// const关键字发生的时机: 编译, 有类型检查
//(使用const关键字可以减少犯错的概率)
//
//
// 尽量使用const关键字替换宏定义

#define MAX 1000

int test0(void)
{
	int num = 2;
	cout << num * MAX << endl;

	return 0;
}

void test1()
{
	// const int num;//error, 常量必须要进行初始化
	const int value = 1;
	// value = 2;//error  常量的值不能进行修改
	cout << "value = " << value << endl;
}

int main(void)
{
	test0();
	test1();
	return 0;
}

