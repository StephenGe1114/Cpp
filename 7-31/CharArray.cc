 ///
 /// @file    CharArray.cc
 /// @author  gsw(1499186594@qq.com)
 ///
   

#include <string.h>
#include <iostream>
using std::cout;
using std::endl;

class CharArray
{
public:
	CharArray(int size)
		: _size(size), _pdata(new char[_size]())
	{
	}

	char &operator[](size_t idx)
	{
		// cout << "char & operator[](size_t)" << endl;
		if (idx < _size)
		{
			return _pdata[idx];
		}
		else
		{
			static char nullchar = '\0';
			cout << "下标越界!" << endl;
			return nullchar;
		}
	}

	size_t size() const { return _size; }

	~CharArray()
	{
		delete[] _pdata;
	}

private:
	size_t _size;
	char *_pdata;
};

int main(void)
{
	const char *pstr = "hello,world";
	CharArray ca(strlen(pstr) + 1);

	for (size_t idx = 0; idx != ca.size(); ++idx)
	{
		ca[idx] = pstr[idx]; // 修改
	}
	cout << endl;

	for (size_t idx = 0; idx != ca.size(); ++idx)
	{
		cout << ca[idx] << endl;
	}

	return 0;
}

