 ///
 /// @file    heapStudent.cc
 /// @author  gsw(1499186594@qq.com)
 ///
   

#include <string.h>
#include <stdlib.h>
#include <iostream>
using std::cout;
using std::endl;

class Student
{
public:
	Student(int id, const char *name)
		: _id(id), _name(new char[strlen(name) + 1]())
	{
		strcpy(_name, name);
		cout << "Student(int, const char*)" << endl;
	}

	void print() const
	{
		cout << "id: " << _id << endl
			 << "name: " << _name << endl;
	}

	void destroy()
	{
		// this->~Student();
		delete this;
	}

	static void *operator new(size_t sz)
	{
		cout << "void * operator new(size_t)" << endl;
		void *ret = malloc(sz);
		return ret;
	}

	static void operator delete(void *ret)
	{
		free(ret);
		cout << "void operator delete(void*) " << endl;
	}

private:
	~Student()
	{
		delete[] _name;
		cout << "~Student()" << endl;
	}

private:
	int _id;
	char *_name;
};

class Point
{
public:
	Point() { cout << "Point()" << endl; }
	~Point() { cout << "~Point()" << endl; }
};

// 需求: 只能生成堆对象，不能生成栈对象
// 解决方案: 将析构函数放在private区域

int main(void)
{
	// Student s(101, "Alice");//error

	Student *pstu = new Student(100, "Mike"); // ok
	pstu->print();

	pstu->destroy();

	// delete pstu;
	return 0;
}

