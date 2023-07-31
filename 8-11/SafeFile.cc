 ///
 /// @file    SafeFile.cc
 /// @author  gsw(1499186594@qq.com)
 ///
   

#include <stdio.h>
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

class SafeFilePointer
{
public:
	SafeFilePointer(FILE *fp)
		: _fp(fp)
	{
	}

	void write(const string &msg)
	{
		fwrite(msg.c_str(), 1, msg.size(), _fp);
	}

	~SafeFilePointer()
	{
		if (_fp)
		{
			fclose(_fp);
			cout << ">> fclose()" << endl;
		}
	}

private:
	FILE *_fp;
};

int main(void)
{
	SafeFilePointer sf(fopen("test.txt", "w+"));
	string msg("hello,world");

	sf.write(msg);

	return 0;
}

