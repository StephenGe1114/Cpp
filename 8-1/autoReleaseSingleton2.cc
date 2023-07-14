 ///
 /// @file    autoReleaseSingleton2.cc
 /// @author  gsw(1499186594@qq.com)
 ///
   

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using std::cout;
using std::endl;

// 单例对象的自动释放:
// 1.方法一：嵌套类 + 静态对象

class Singleton
{
public:
	static Singleton *getInstance()
	{
		if (_pInstance == NULL)
		{
			_pInstance = new Singleton();
			atexit(destroy);
		}
		return _pInstance;
	}

	static void destroy()
	{
		if (_pInstance)
			delete _pInstance;
	}

private:
	Singleton() { cout << "Singleton()" << endl; }
	~Singleton() { cout << "~Singleton()" << endl; }

private:
	static Singleton *_pInstance;
};

Singleton *Singleton::_pInstance = NULL; // 懒(饿)汉模式 --> 懒加载 (只在需要的时候创建单例对象)

int main(void)
{
	// AutoRelease ar;

	Singleton *p1 = Singleton::getInstance();
	Singleton *p2 = Singleton::getInstance();

	printf("p1 = %p\n", p1);
	printf("p2 = %p\n", p2);

	// Singleton::detroy();//有可能忘记

	return 0;
}

