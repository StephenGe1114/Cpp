 ///
 /// @file    1.cc
 /// @author  gsw(1499186594@qq.com)
 ///
   
/*单例模式*/

#include <iostream>
using std::cout;
using std::endl;

class Singleton
{
public:
    static Singleton *getInstance()
    {
        if (!_pInstance)
        {
            _pInstance = new Singleton();
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

private:
    Singleton()
    {
        cout << "Singleton()" << endl;
    }

    ~Singleton()
    {
        cout << "~Singleton()" << endl;
    }

private:
    static Singleton *_pInstance;
};

Singleton *Singleton::_pInstance = nullptr;
