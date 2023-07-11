 ///
 /// @file    namespace3.cc
 /// @author  gsw(1499186594@qq.com)
 ///
  
#include <iostream>

using std::cout; // using声明机制, 只会引入一个单独的实体
using std::endl;

int num = 1;

// 命名空间类似于黑洞
namespace B
{
	void displayC(); // 在命名空间中的函数声明
}

namespace A
{
	int num = 10;
	void displayA()
	{
		cout << "A::displayA()" << endl;
		B::displayC();
	}

	namespace C
	{
		int num = 22;
		void displayC()
		{
			cout << "A::C::num = " << num << endl;
			cout << "A::C::displayC()" << endl;
		}
	}

} // end of namespace

namespace B
{
	int num = 100;
	void displayB(int num)
	{
		cout << "形参num = " << num << endl;
		cout << "B::num = " << B::num << endl;
		cout << "A::num = " << A::num << endl;
		cout << "全局变量num = " << ::num << endl; // 匿名的命名空间, C的库函数都位于匿名命名空间
		A::displayA();
	}

	void displayC()
	{
		cout << "displayC() " << endl;
	}

} // end of namespace B

using A::displayA;
int main(void)
{
	displayA();
	B::displayB(1000);

	A::C::displayC(); // 命名空间的嵌套

	return 0;
}

