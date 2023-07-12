 ///
 /// @file    Student.cc
 /// @author  gsw(1499186594@qq.com)
 ///
   

#include <string.h>
#include <stdlib.h>
#include <iostream>
using std::cout;
using std::endl;

// 针对于任意类型都能重新定义开辟空间的方式
void *operator new(size_t sz)
{
	cout << "void * operator new(size_t)" << endl;
	void *ret = malloc(sz);
	return ret;
}

void operator delete(void *ret)
{
	free(ret);
	cout << "void operator delete(void*) " << endl;
}

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

	~Student()
	{
		delete[] _name;
		cout << "~Student()" << endl;
	}

#if 1
	// 重定义开辟空间的方式
	//
	// 只针对于自定类类型Student起作用
	static void *operator new(size_t sz)
	{
		cout << "void * operator new2(size_t)" << endl;
		void *ret = malloc(sz);
		return ret;
	}

	static void operator delete(void *ret)
	{
		free(ret);
		cout << "void operator delete2(void*) " << endl;
	}
#endif

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

int main(void)
{
	Student *pstu = new Student(100, "Mike");
	pstu->print();

	delete pstu;
	cout << endl;

	Point *pt = new Point;
	delete pt;

	return 0;
}

