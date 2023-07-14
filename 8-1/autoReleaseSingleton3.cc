 ///
 /// @file    autoReleaseSingleton3.cc
 /// @author  gsw(1499186594@qq.com)
 ///
   

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <iostream>
using std::cout;
using std::endl;

// 单例对象的自动释放:
// 1.方法二：atexit + pthread_once

class Singleton
{
public:
	static Singleton *getInstance()
	{
		// 多线程环境是线程安全的
		pthread_once(&_once, init);
		return _pInstance;
	}

	static void init()
	{
		_pInstance = new Singleton();
		atexit(destroy);
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
	static pthread_once_t _once;
};

Singleton *Singleton::_pInstance = NULL; // 懒(饿)汉模式 --> 懒加载 (只在需要的时候创建单例对象)
pthread_once_t Singleton::_once = PTHREAD_ONCE_INIT;

int main(void)
{
	Singleton *p1 = Singleton::getInstance();
	Singleton *p2 = Singleton::getInstance();

	printf("p1 = %p\n", p1);
	printf("p2 = %p\n", p2);

	return 0;
}

