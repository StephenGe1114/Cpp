 ///
 /// @file    1.cc
 /// @author  gsw(1499186594@qq.com)
 ///
  
/*实现String类的其它运算符的重载*/

#include <string.h>
#include <iostream>
using std::cout;
using std::endl;

class String
{
public:
    String();
    String(const char *);
    String(const String &); // 这里的s能否直接访问_pstr
    ~String();
    String &operator=(const String &);
    String &operator=(const char *);

    String &operator+=(const String &);
    String &operator+=(const char *); // 写到这里了

    char &operator[](std::size_t index);
    const char &operator[](std::size_t index) const;

    std::size_t size() const;
    const char *c_str() const;

    friend bool operator==(const String &, const String &);
    friend bool operator!=(const String &, const String &);

    friend bool operator<(const String &, const String &);
    friend bool operator>(const String &, const String &);
    friend bool operator<=(const String &, const String &);
    friend bool operator>=(const String &, const String &);

    friend std::ostream &operator<<(std::ostream &os, const String &s);
    friend std::istream &operator>>(std::istream &is, String &s);

private:
    char *_pstr;
};

String operator+(const String &rhs, const String &lhs)
{
    char *pstr = new char[strlen(rhs.c_str()) + strlen(lhs.c_str()) + 1]();
    strcpy(pstr, rhs.c_str());
    strcat(pstr, lhs.c_str());
    return pstr;
}

String operator+(const String &rhs, const char *str)
{
    char *pstr = new char[strlen(rhs.c_str()) + strlen(str) + 1]();
    strcpy(pstr, rhs.c_str());
    strcat(pstr, str);
    return pstr;
}

String operator+(const char *str, const String &lhs)
{
    char *pstr = new char[strlen(lhs.c_str()) + strlen(str) + 1]();
    strcpy(pstr, str);
    strcat(pstr, lhs.c_str());
    return pstr;
}

String::String()
    : _pstr(new char[1]())
{
}

String::String(const char *pstr)
    : _pstr(new char[strlen(pstr) + 1]())
{
    strcpy(_pstr, pstr);
}

String::String(const String &s)
    : _pstr(new char[strlen(s._pstr) + 1]())
{
    strcpy(_pstr, s._pstr);
}

String::~String()
{
    if (_pstr)
    {
        delete[] _pstr;
    }
}

String &String::operator=(const String &s)
{
    if (this != &s)
    {
        delete[] _pstr;
        _pstr = new char[strlen(s._pstr) + 1]();
        strcpy(_pstr, s._pstr);
    }
    return *this;
}

String &String::operator=(const char *pstr)
{
    delete[] _pstr;
    _pstr = new char[strlen(pstr) + 1]();
    strcpy(_pstr, s._pstr);
    return *this;
}

String &String::operator+=(const String &s)
{
    char *pstr = new char[strlen(_pstr) + strlen(s._pstr) + 1]();
    strcpy(pstr, _pstr);
    delete[] _pstr;
    strcat(pstr, s._pstr);
    _pstr = pstr;
    return *this;
}

String &String::operator+=(const char *str)
{
    char *pstr = new char[strlen(_pstr) + strlen(str) + 1]();
    strcpy(pstr, _pstr);
    delete[] _pstr;
    strcat(pstr, str);
    _pstr = pstr;
    return *this;
}

char &String::operator[](std::size_t index)
{
    return _pstr[index];
}

const char &String::operator[](std::size_t index) const
{
    return _pstr[index];
}

std::size_t String::size() const
{
    return strlen(_pstr);
}

const char *String::c_str() const
{
    return _pstr;
}

bool operator==(const String &lhs, const String &rhs)
{
    return !strcmp(lhs._pstr, rhs._pstr);
}
bool operator!=(const String &lhs, const String &rhs)
{
    return !(lhs == rhs);
}

bool operator<(const String &lhs, const String &rhs)
{
    return strcmp(lhs._pstr, rhs._pstr) < 0;
}

bool operator>(const String &lhs, const String &rhs)
{
    return strcmp(lhs._pstr, rhs._pstr) > 0;
}
bool operator<=(const String &lhs, const String &rhs)
{
    return strcmp(lhs._pstr, rhs._pstr) <= 0;
}
bool operator>=(const String &lhs, const String &rhs)
{
    return strcmp(lhs._pstr, rhs._pstr) >= 0;
}

std::ostream &operator<<(std::ostream &os, const String &s)
{
    os << s._pstr;
    return os;
}

std::istream &operator>>(std::istream &is, String &s)
{
    is >> s._pstr;
    return is;
}

