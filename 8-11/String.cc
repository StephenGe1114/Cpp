 ///
 /// @file    String.cc
 /// @author  gsw(1499186594@qq.com)
 ///
   

#include <string.h>
#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

class String
{
public:
	String()
		: _pstr(new char[1]())
	{
		cout << "String()" << endl;
	}

	String(const char *pstr)
		: _pstr(new char[strlen(pstr) + 1]())
	{
		strcpy(_pstr, pstr);
		cout << "String(const char * pstr)" << endl;
	}

	// 具有值语义（复制控制）的函数
	// 复制构造函数
	String(const String &rhs)
		: _pstr(new char[strlen(rhs._pstr) + 1]())
	{
		strcpy(_pstr, rhs._pstr);
		cout << "String(const String &)" << endl;
	}

	// 赋值运算符函数
	String &operator=(const String &rhs)
	{
		cout << "String & operator=(const String &)" << endl;
		if (this != &rhs)
		{ // 自复制
			delete[] _pstr;
			_pstr = new char[strlen(rhs._pstr) + 1]();
			strcpy(_pstr, rhs._pstr);
		}
		return *this;
	}

#if 1
	// 具有移动语义的函数 的执行要优先于 具有值语义的函数
	// 移动构造函数
	String(String &&rhs)
		: _pstr(rhs._pstr)
	{
		rhs._pstr = nullptr;
		cout << "String(String &&)" << endl;
	}

	// 移动赋值运算符函数
	String &operator=(String &&rhs) // 这里的右值引用本身变成了左值
	{
		if (this != &rhs)
		{
			cout << "String & operator=(String &&)" << endl;
			delete[] _pstr;
			_pstr = rhs._pstr;
			rhs._pstr = nullptr; // 移动意味着修改
		}
		return *this;
	}
#endif

	~String()
	{
		delete[] _pstr;
		cout << "~String()" << endl;
	}

	friend std::ostream &operator<<(std::ostream &os, const String &rhs);

private:
	char *_pstr;
};

std::ostream &operator<<(std::ostream &os, const String &rhs)
{
	os << rhs._pstr;
	return os;
}

String &&func()
{
	return String("hello");
}

// 右值引用本身是不是右值？
// 答： 右值引用本身是左值还是右值，取决于它有没有名字；
//	   有名字的就是左值，没有名字就是右值

int test0(void)
{
#if 1
	vector<String> vec;
	vec.push_back("Hello,world");
#endif

	String s1 = "hello,world";
	cout << "s1 = " << s1 << endl;
	cout << endl;
	String s2("hello,world");
	cout << "s2 = " << s2 << endl;
	cout << endl;

	s2 = String("wangdao");
	cout << "s2 = " << s2 << endl;
	cout << endl;

	//	s2 = std::move(s2);// 一般不会这样使用

	String s3 = std::move(s2); // std::move 显式的将一个左值转换成右值
							   // 意味着该语句之后，就不会再使用s2
	cout << "s3 = " << s3 << endl;
	// cout << "s2 = " << s2 << endl;//无法正常执行

	cout << "对s2 重新进行赋值之后，才可以正常使用:" << endl;
	s2 = "shenzen";
	cout << "s2 = " << s2 << endl;

	cout << "...." << endl;
	return 0;
}

void test1(void)
{
	//&func(); // 右值引用是右值, 没有名字
}

int main(void)
{
	test0();
	cout << "-----------------------" << endl;
//	test1();
	return 0;
}

