 ///
 /// @file    memory.cc
 /// @author  gsw(1499186594@qq.com)
 ///
   

#include <stdio.h>
#include <string.h>
#include <iostream>
using std::cout;
using std::endl;

int a = 0;
char *p1;
const int x = 100; // 文字常量区

int test0(void)
{
    cout << sizeof(int) << endl;
	int b;
	char s[] = "123456"; // 栈上
	char *p2;
	const char *p3 = "123456"; // 文字常量区, 只读
	//*p3 = 'x';

	static int c = 0;
	c++;
	const int y = 10; // 栈上, 与其生命周期有关

	p1 = new char[10];
	p2 = new char[5];
	strcpy(p1, "123456");
	printf("&123456 = %p\n", &"123456");

	printf("&a = %p\n", &a);
	printf("&p1 = %p\n", &p1);
	printf("p1 = %p\n", p1);
	printf("&b = %p\n", &b);
	printf("s = %p\n", s);
	printf("&p2 = %p\n", &p2);
	printf("p2 = %p\n", p2);
	printf("&p3 = %p\n", &p3);
	printf("p3 = %p\n", p3);
	printf("&c = %p\n", &c);
	printf("&test0 = %p\n", &test0);
	printf("&x = %p\n", &x);
	printf("&y = %p\n", &y);

	return 0;
}

int main(void)
{
	test0();
	return 0;
}

