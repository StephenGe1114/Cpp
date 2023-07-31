 ///
 /// @file    multiDerivedVirtual.cc
 /// @author  gsw(1499186594@qq.com)
 ///
   
#include <iostream>
using std::cout;
using std::endl;

class A
{
public:
	virtual void a() { cout << "A::a()" << endl; }
	virtual void b() { cout << "A::b()" << endl; }
	virtual void c() { cout << "A::c()" << endl; }
};

class B
{
public:
	virtual void a() { cout << "B::a()" << endl; }
	virtual void b() { cout << "B::b()" << endl; }
	void c() { cout << "B::c()" << endl; }
	void d() { cout << "B::d()" << endl; }
};

class C
	: public A,
	  public B
{
public:
	virtual void a() { cout << "C::a()" << endl; }

	void c() { cout << "C::c()" << endl; }
	void d() { cout << "C::d()" << endl; }
};
int main(void)
{
	cout << "sizeof(A) = " << sizeof(A) << endl;
	cout << "sizeof(B) = " << sizeof(B) << endl;
	cout << "sizeof(C) = " << sizeof(C) << endl;
#if 1
	C c;

	A *pA = &c;
	pA->a();
	pA->b();
	pA->c();
#endif
	cout << endl;

	B *pB = &c;
	pB->a(); // C::a()
	pB->b(); // B::b()
	pB->c(); // B::c()
	pB->d(); // B::d()

	cout << endl;
	C *pc = &c;
	pc->a();
	// pc->b();//error, 产生二义性
	pc->c();
	pc->d();

	cout << "pA = " << pA << endl;
	cout << "pB = " << pB << endl;
	cout << "pc = " << pc << endl;

	return 0;
}
