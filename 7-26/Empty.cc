 ///
 /// @file    Empty.cc
 /// @author  gsw(1499186594@qq.com)
 ///
   

#include <stdio.h>
#include <iostream>
using std::cout;
using std::endl;

// 空类占据的空间是一个字节，就是为了当空类创建不同的对象时，
// 以示区分
class Empty
{
};

int main(void)
{
	cout << "sizeof(Empty) = " << sizeof(Empty) << endl;
	Empty e1; // 默认(无参)构造函数
	Empty e2;

	printf("&e1 = %p\n", &e1);
	printf("&e2 = %p\n", &e2);

	Empty e3 = e1; // 调用复制构造函数

	e3 = e2; // 赋值运算符函数

	// 对象要销毁时，会调用析构函数

	return 0;
}

