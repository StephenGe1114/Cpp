 ///
 /// @file    string.cc
 /// @author  gsw(1499186594@qq.com)
 ///
   

// #include "add.h"   //自定义头文件放在C头文件上面

#include <stdlib.h> //C的头文件写在C++头文件之前
#include <string.h>

#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

void test0(void)
{
	char str1[] = "hello,world";
	char str2[100] = "nanjing";
	const char *str3 = "cpppractice"; // C 风格的字符串类型

	cout << sizeof(str1) << endl;
	// strcat(str1, str2);//str1 会越界
	// cout << "str1 = " << str1 << endl;
	cout << "str3 = " << str3 << endl;

	// 字符串拼接的操作
	int len = strlen(str1) + strlen(str2) + 1;
	char *pstr = (char *)malloc(len);
	memset(pstr, 0, len);
	strcpy(pstr, str1);
	strcat(pstr, str2);
	cout << "pstr = " << pstr << endl;

	free(pstr);
}

void test1(void)
{
	string s1 = "hello,world"; // C风格字符串转换成C++风格的字符串
	string s2 = "nanjing";
	cout << "s1 = " << s1 << endl;
	cout << "s2 = " << s2 << endl;

	// C++字符串拼接
	string s3 = s1 + s2;
	cout << "s3 = " << s3 << endl;
	string s4 = s1 + "nanjing";
	cout << "s4 = " << s4 << endl;
	string s5 = "hello,world" + s2;
	cout << "s5 = " << s5 << endl;
	string s6 = s1 + 'A';
	cout << "s6 = " << s6 << endl;
	cout << endl;

	s1.append(s2);
	cout << "s1 = " << s1 << endl;
}

int main(void)
{
	test0();
	test1();
	return 0;
}

