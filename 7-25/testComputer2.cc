 ///
 /// @file    testComputer2.cc
 /// @author  gsw(1499186594@qq.com)
 ///
   

#include "Computer.h"
#include <iostream>
using std::cout;
using std::endl;

int main(void)
{
	Computer com;
	com.setBrand("外星人");
	com.setPrice(10000);
	com.print();

	return 0;
}

