 ///
 /// @file    stream.cc
 /// @author  gsw(1499186594@qq.com)
 ///
   

#include <iostream>
#include <fstream>

using std::cout;
using std::endl;
using std::ifstream;

int main(void)
{
	// 流对象都是不能进行复制的
	ifstream ifs("String.cc");
	ifstream ifs2(ifs);

	return 0;
}

