 ///
 /// @file    1.cc
 /// @author  gsw(1499186594@qq.com)
 ///
   
/*实现一个模板形式的单例类，要求对于任意类型的类经过Singleton的处理之后，
  　都能获取一个单例对象，并且可以传递任意参数*/

#include <stdio.h>
#include <string.h>
#include <iostream>
using std::cout;
using std::endl;

template <typename T>
class Singleton
{
    class AutoRelease
    {
    public:
        AutoRelease()
        {
            cout << "AutoRelease()" << endl;
        }

        ~AutoRelease()
        {
            cout << "~AutoRelease()" << endl;
            if (_pInstance)
            {
                delete _pInstance;
            }
        }
    };

public:
    template <typename... Args>
    static T *getInstance(Args... args);

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
    static T *_pInstance;
    static AutoRelease _ar;
};

template <typename T>
T *Singleton<T>::_pInstance = nullptr;

template <typename T>
typename Singleton<T>::AutoRelease Singleton<T>::_ar;

template <typename T>
template <typename... Args>
T *Singleton<T>::getInstance(Args... args)
{
    if (!_pInstance)
    {
        _pInstance = new T(args...);
        _ar;
    }
    return _pInstance;
}

class Point
{
public:
    Point(int ix, int iy)
        : _ix(ix), _iy(iy)
    {
        cout << "Point()" << endl;
    }

    ~Point()
    {
        cout << "~Point()" << endl;
    }

private:
    int _ix;
    int _iy;
};

class Computer
{
public:
    Computer(const char *name, int price)
    {
        cout << "Computer()" << endl;
        strcpy(_name, name);
        _price = price;
    }

    ~Computer()
    {
        cout << "~Computer()" << endl;
    }

private:
    char _name[128];
    int _price;
};

int main(void)
{
    Computer *p1 = Singleton<Computer>::getInstance("Xiaomi", 6666);
    Computer *p2 = Singleton<Computer>::getInstance("Xiaomi", 6666);

    Point *p3 = Singleton<Point>::getInstance(1, 2);
    Point *p4 = Singleton<Point>::getInstance(1, 2);

    printf("p1 = %p\np2 = %p\np3 = %p\np4 = %p\n", p1, p2, p3, p4);
    return 0;
}
