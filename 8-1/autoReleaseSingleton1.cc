 ///
 /// @file    autoReleaseSingleton1.cc
 /// @author  gsw(1499186594@qq.com)
 ///
   

#include <stdio.h>
#include <iostream>
using std::cout;
using std::endl;

// 单例对象的自动释放:
// 1.方法一：嵌套类 + 静态对象

class Singleton
{
	class AutoRelease // 只为Singleton提供服务
	{
	public:
		AutoRelease() { cout << "AutoRelease()" << endl; }

		~AutoRelease()
		{
			if (_pInstance)
			{
				delete _pInstance;
				cout << "~AutoRelease()" << endl;
			}
		}
	};

public:
	static Singleton *getInstance()
	{ // 在多线程环境下并不是线程安全的
		// 1. 解决方案： 加锁 mutex.lock();
		if (_pInstance == NULL)
		{
			_pInstance = new Singleton();
		}
		return _pInstance;
	}

private:
	Singleton() { cout << "Singleton()" << endl; }
	~Singleton() { cout << "~Singleton()" << endl; }

private:
	static Singleton *_pInstance;
	static AutoRelease _ar;
};

// Singleton * Singleton::_pInstance = NULL;// 懒(饿)汉模式 --> 懒加载 (只在需要的时候创建单例对象)
Singleton *Singleton::_pInstance = getInstance(); // 饱汉模式 (多线程安全的)
Singleton::AutoRelease Singleton::_ar;

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

