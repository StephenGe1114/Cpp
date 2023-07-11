 ///
 /// @file    namespace2.cc
 /// @author  gsw(1499186594@qq.com)
 ///
   
#include <iostream>

namespace A
{

	void displayA()
	{
		std::cout << "A::displayA() " << std::endl; // 作用域限定符
	}

} // end of namespace A

using namespace A;

void cout()
{
	std::cout << "cout() " << std::endl;
}

int main(void)
{
	displayA();
	cout();
	return 0;
}
