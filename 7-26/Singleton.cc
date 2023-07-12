 ///
 /// @file    Singleton.cc
 /// @author  gsw(1499186594@qq.com)
 ///
   

#include <iostream>
using std::cout;
using std::endl;

// 单例模式:
// 要求：在内存中只能创建一个对象
// 1. 该对象不能栈(全局)对象
// 2. 该对象只能放在堆中
//
// 应用场景:
// 1. 直接替换任意的全局对象(变量)
// 2. 配置文件
// 3. 词典类

#include <stdio.h>

class Singleton
{
public:
	static Singleton *getInstance()
	{
		if (NULL == _pInstance)
		{
			_pInstance = new Singleton(); // 在类内部掉用构造函数
		}
		return _pInstance;
	}

	static void destroy()
	{
		if (_pInstance)
		{
			delete _pInstance;
		}
	}

	void print()
	{
		cout << "Singleton::print()" << endl;
	}

private:
	Singleton() { cout << "Singleton()" << endl; }
	~Singleton() { cout << "~Singleton()" << endl; }

private:
	static Singleton *_pInstance;

	// 数据成员
};

Singleton *Singleton::_pInstance = NULL;

// Singleton s3;
// static Singleton s4;

int main(void)
{
	// Singleton s1;//error 栈对象, 必须让该语句无法编译通过
	// Singleton s2;
	// Singleton * p1 = new Singleton();//必须让该语句无法编译通过
	// Singleton * p2 = new Singleton();
#if 1
	Singleton *p1 = Singleton::getInstance();
	Singleton *p2 = Singleton::getInstance();
#endif
	printf("p1 = %p\n", p1);
	printf("p2 = %p\n", p2);

	Singleton::getInstance()->print();

	// delete p1;//error, 希望该语句编译无法通过

	Singleton::destroy();

	return 0;
}

