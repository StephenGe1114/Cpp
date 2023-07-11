 ///
 /// @file    bool.cc
 /// @author  gsw(1499186594@qq.com)
 ///
   

#include <iostream>
using std::cout;
using std::endl;

int main(void)
{
	// if() //0  代表的是false, 非0 代表的true
	bool b1 = 100;
	bool b2 = 0;
	bool b3 = -10;
	bool b4 = true;
	bool b5 = false;

	cout << "b1 = " << b1 << endl;
	cout << "b2 = " << b2 << endl;
	cout << "b3 = " << b3 << endl;
	cout << "b4 = " << b4 << endl;
	cout << "b5 = " << b5 << endl;
	cout << "sizeof(bool) = " << sizeof(bool) << endl;

	return 0;
}

