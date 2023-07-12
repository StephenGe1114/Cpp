 ///
 /// @file    Computer3.cc
 /// @author  gsw(1499186594@qq.com)
 ///
   

#include <string.h>
#include <iostream>
using std::cout;
using std::endl;

class Computer
{
public:
	Computer(const char *brand, float price)
		: _brand(new char[strlen(brand) + 1]()), _price(price)
	{
		cout << "Computer(const char *, float)" << endl;
		strcpy(_brand, brand);
	}

	void print()
	{
		cout << "brand: " << _brand << endl;
		cout << "price: " << _price << endl;
	}

	~Computer()
	{
		cout << "~Computer()" << endl;
		delete[] _brand;
	}

private:
	char *_brand;
	float _price;
};

Computer gComputer("Thinkpad", 7777);

int main(void)
{
	cout << "sizeof(float) = " << sizeof(float) << endl;
	cout << "sizeof(Computer) = " << sizeof(Computer) << endl;
	// Computer c1("xiaomi", 6666);//栈对象，当其生命周期结束时，也会自动调用析构函数
	// c1.print();
	// c1.~Computer();//可以显式调用析构函数，但不推荐这样做

	// int * p1 = new int(1);
	// delete p1;
	gComputer.print();
	cout << endl;

	Computer *pc = new Computer("Mac", 10000);
	pc->print();

	delete pc; // 会调用Computer的析构函数

	return 0;
}

