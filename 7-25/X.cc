 ///
 /// @file    X.cc
 /// @author  gsw(1499186594@qq.com)
 ///
   

#include <iostream>
using std::cout;
using std::endl;

class Demo
{
public:
	Demo(int iy)
		: _iy(iy) // 数据成员在初始化表达式中的顺序并不是初始化的顺序
		  ,
		  _ix(_iy) // 数据成员初始化顺序是由其声明的顺序决定的
	{
		cout << "Demo(int)" << endl;
	}

	void print()
	{
		cout << "(" << _ix
			 << "," << _iy
			 << ")" << endl;
	}

private:
	int _ix;
	int _iy;
};

int main(void)
{
	Demo demo(10);
	demo.print();
}

