 ///
 /// @file    virtual.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-08-15 11:06:06
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Base
{
public:
	Base() : _base(100){}

	virtual void a() {	cout << "Base::a()" << endl;	}	
	virtual void b() {	cout << "Base::b()" << endl;	}	
	virtual void c() {	cout << "Base::c()" << endl;	}	
private:
	long _base;
};
 
//证明虚函数表的存在
int main(void)
{
	cout << "sizeof(long) = " << sizeof(long) << endl;

	Base base;

	long ** p = (long**)&base;

	long * p1 = (long *) &base;
	long * pVtable = (long *) *p1;
	
	typedef void (*Function)();
	Function f = (Function) *pVtable;
	f();
	f = (Function) *(pVtable + 1);
	f();
	f = (Function) *(pVtable + 2);
	f();

#if 1
	for(int idx = 0; idx != 3; ++idx)
	{
		long pAddress = p[0][idx];
		Function f = (Function)pAddress;
		f();
	}

	long value = (long)p[1];
	cout << "value = " << value << endl;
#endif
	cout << p1[1] << endl;


	return 0;
}
