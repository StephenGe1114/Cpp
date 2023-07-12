 ///
 /// @file    io2.cc
 /// @author  gsw(1499186594@qq.com)
 ///
   

#include <string.h>

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

using std::fstream;
using std::ifstream;
using std::ofstream;
using std::string;

vector<string> file;

void test0(void)
{
	// 文件输入流要求打开的文件必须存在
	// ifstream ifs("test.txt");
	ifstream ifs("io2.cc");
	if (!ifs)
	{
		cout << "ifstream open error!" << endl;
		return;
	}

	string line;
	// while(ifs >> s1)  //以空格作为分隔符
	while (std::getline(ifs, line)) // 通过输入流获取一行数据
	{
		file.push_back(line);
	}

	for (auto &line : file)
	{
		cout << line << "\n";
	}

	ifs.close();
}

void test1(void)
{
	test0();
	string filename = "test.txt";

	// 如果文件不存在，就创建一个；
	// 如果文件存在，则会清空文件的内容，再重新写入
	ofstream ofs(filename);
	if (!ofs.good())
	{
		cout << "ofstream open error!" << endl;
		return;
	}
	for (auto &line : file)
	{
		ofs << line << "\n";
	}
}

void test2(void)
{
	string filename = "test.txt";

	// ofs对象跟filename所代表的文件绑定起来
	//  indicator 游标
	//
	//  fopen
	//  fclose
	//  fread
	//  fwrite
	//  ftell
	//  fseek
	//
	ofstream ofs(filename, std::ios::app); // 在文件的末尾添加新的内容
	if (!ofs.good())
	{
		cout << "ofstream open error!" << endl;
		return;
	}

	cout << "pos = " << ofs.tellp() << endl;

	string line = "this is a new line";
	ofs << line;

	ofs.close();
}

void test3(void)
{
	fstream fs;
	fs.open("test2.txt");
	if (!fs)
	{
		cout << " fstream open error!" << endl;
		return;
	}

	int number;
	for (int idx = 0; idx != 5; ++idx)
	{
		cin >> number;
		fs << number << " ";
	}

	cout << "pos = " << fs.tellp() << endl;
	fs.seekg(std::ios::beg);

	for (int idx = 0; idx != 5; ++idx)
	{
		fs >> number;
		cout << number << " " << endl;
	}

	fs.close();
}

void test4(void)
{
	// ate是针对于文件输入流
	ifstream ifs("test2.txt", std::ios::ate);
	if (!ifs)
	{
		cout << " ifstream open error!" << endl;
		return;
	}

	// 一次性拿到一个文件全部信息
	size_t length = ifs.tellg();
	cout << "pos = " << length << endl;
	ifs.seekg(std::ios::beg);

	char buff[length + 1];
	memset(buff, 0, length + 1);
	ifs.read(buff, length + 1); // 使用read的方式读取一个文件的所有内容

	string content(buff);
	cout << content << endl;

	ifs.close();
}

int main(void)
{
	//test1();
	//test2();
	//test3();
	test4();
	return 0;
}

