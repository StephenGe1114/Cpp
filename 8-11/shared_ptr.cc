 ///
 /// @file    shared_ptr.cc
 /// @author  gsw(1499186594@qq.com)
 ///
   
#include <iostream>
#include <string>
#include <memory>
using std::cout;
using std::endl;
using std::shared_ptr;
using std::string;

class Point
{
public:
	Point(int ix = 0, int iy = 0)
		: _ix(ix), _iy(iy)
	{
		cout << "Point(int,int) " << endl;
	}

	~Point()
	{
		cout << "~Point()" << endl;
	}

	void display() const
	{
		cout << "(" << _ix
			 << "," << _iy
			 << ")" << endl;
	}

	friend std::ostream &operator<<(std::ostream &os, const Point &rhs);

private:
	int _ix;
	int _iy;
};

std::ostream &operator<<(std::ostream &os, const Point &rhs)
{
	os << "(" << rhs._ix
	   << "," << rhs._iy
	   << ")";
	return os;
}

int test0(void)
{
	Point *pt = new Point(1, 2);
	shared_ptr<Point> sp(pt);
	cout << "pt = " << pt << endl;
	cout << "sp'get() = " << sp.get() << endl;
	cout << "*sp = " << *sp << endl;

	sp->display();

	cout << "sp's use_count = " << sp.use_count() << endl
		 << endl;
	cout << "进行复制之后:" << endl;
	shared_ptr<Point> sp2(sp); // 表达值语义 --> 复制
	cout << "sp2'get() = " << sp2.get() << endl;
	cout << "sp2's use_count = " << sp2.use_count() << endl;
	cout << "sp's use_count = " << sp.use_count() << endl;
	cout << "*sp2 = " << *sp2 << endl;
	sp2->display();

	return 0;
}

struct Fpcloser
{
	void operator()(FILE *fp)
	{
		if (fp)
		{
			fclose(fp);
			cout << ">> fclose(fp)" << endl;
		}
	}
};

void test1(void)
{
	// shared_ptr自定义删除器的方式
	shared_ptr<FILE> sp(fopen("test.txt", "w+"), Fpcloser()); // 函数模板的隐式实例化
	string msg("hello,shenzhen!");
	fwrite(msg.c_str(), 1, msg.size(), sp.get());
}

int main(void)
{
	test0();
	cout << "-----------------------------------------------" << endl;
	test1();
	return 0;
}

