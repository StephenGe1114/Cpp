 ///
 /// @file    io1.cc
 /// @author  gsw(1499186594@qq.com)
 ///
   

#include <iostream>
#include <limits>

using std::cin;
using std::cout;
using std::endl;
using std::string;

void printCin()
{
	cout << "cin' badbit = " << cin.bad() << endl;
	cout << "cin' failbit = " << cin.fail() << endl;
	cout << "cin' eofbit = " << cin.eof() << endl;
	cout << "cin' goodbit = " << cin.good() << endl;
}

// 整型数据: bool/char/short/int/long long

int test0(void)
{
	cout << "sizeof(cout) = " << sizeof(cout) << endl;
	cout << "sizeof(cin) = " << sizeof(cin) << endl;

	printCin();
	int number;
	while (cin >> number)
	{
		cout << "number = " << number << endl;
	}
	printCin();
	cout << endl
		 << "重置流的状态:";
	cin.clear(); // 重置流的状态
	// cin.ignore(1024, '\n');// 清空缓冲区
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // 清空缓冲区
	printCin();

	string s;
	cin >> s;
	cout << "s = " << s << endl;

	return 0;
}

void test1(void)
{
	int number;
	cout << ">> pls input an interger: ";
	while (cin >> number, !cin.eof())
	{
		if (cin.bad())
		{
			cout << "cin has breaken!" << endl;
			return;
		}
		else if (cin.fail())
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << ">> pls input an interger: ";
			continue;
		}
		cout << "number = " << number << endl;
	}
	printCin();
	cout << "111111" << endl;
}

int main(void)
{
	test0();
	cout << "------------------------------------------------" << endl << endl;
	test1();
	return 0;
}

