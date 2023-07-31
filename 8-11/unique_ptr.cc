 ///
 /// @file    unique_ptr.cc
 /// @author  gsw(1499186594@qq.com)
 ///
   

#include <stdio.h>
#include <iostream>
#include <string>
#include <memory>
#include <vector>
using std::cout;
using std::endl;
using std::string;
using std::unique_ptr;
using std::vector;

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

private:
	int _ix;
	int _iy;
};

unique_ptr<Point> getValue()
{
	unique_ptr<Point> up(new Point(10, 11));
	return up;
}

int test0(void)
{
	Point *pt = new Point(1, 2);
	unique_ptr<Point> up(pt);
	up->display();

	cout << "up'get() = " << up.get() << endl;
	cout << "pt = " << pt << endl
		 << endl;

	// unique_ptr<Point> up2(up);//独享所有权的智能指针，不能进行复制或赋值

	// unique_ptr<Point> up3(new Point(3, 4));
	// up3 = up;

	unique_ptr<Point> up4 = getValue(); // getValue返回值是一个右值，unique_ptr定义了具有移动语义的函数
	cout << "up4'get = " << up4.get() << endl;
	up4->display();

	vector<unique_ptr<Point>> points; // ptr_vector<Point> 如果要将智能指针结合容器来操作元素，其
									  // 效率低于指针容器的
	// points.push_back(up4);//error
	points.push_back(std::move(up4)); // unique_ptr可以转移

	up4.reset(new Point(7, 8)); // 如果还想继续使用，必须重新对对象进行托管
	up4->display();
	cout << "..." << endl;

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
{ // 自定义删除器
	unique_ptr<FILE, Fpcloser> up(fopen("test.txt", "w+"), Fpcloser());
	string msg("hello,world!");
	fwrite(msg.c_str(), 1, msg.size(), up.get());
}

int main(void)
{
	test0();
	cout << "----------------------------" << endl;
	test1();
	return 0;
}

