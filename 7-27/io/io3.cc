 ///
 /// @file    io3.cc
 /// @author  gsw(1499186594@qq.com)
 ///
   

#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
using std::cout;
using std::endl;
using std::ifstream;
using std::istringstream;
using std::ostringstream;
using std::string;
using std::stringstream;

void test0(void)
{
	int num1 = 10;
	int num2 = 20;

	//
	// sprintf
	//
	stringstream ss;
	ss << "num1= " << num1 << " num2= " << num2;

	cout << ss.str() << endl;
	string str;
	int number;
	while (!ss.eof())
	{
		ss >> str >> number;
		cout << "str：" << str << endl;
		cout << "number:" << number << endl;
	}
}

string int2str(int number)
{
	ostringstream oss;
	oss << number;
	return oss.str();
}

// 对配置文件的解析
void readConfiguration(const string &filename)
{
	ifstream ifs(filename);
	if (!ifs)
	{
		cout << "ifstream open error!" << endl;
		return;
	}
	string key;
	string value;

	string line;
	while (getline(ifs, line))
	{
		istringstream iss(line);
		iss >> key >> value;
		cout << key << " --> " << value << endl;
	}
}

int main(void)
{
	test0();
	readConfiguration("config.txt");
	return 0;
}

