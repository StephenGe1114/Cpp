 ///
 /// @file    auto_ptr.cc
 /// @author  gsw(1499186594@qq.com)
 ///
   

#include <iostream>
#include <memory>
using std::cout;
using std::endl;

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

int main(void)
{
	Point *pt = new Point(1, 2);
	std::auto_ptr<Point> ap(pt);
	cout << "pt = " << pt << endl;
	cout << "ap.get() = " << ap.get() << endl;

	cout << "point：";
	ap->display();
	cout << endl;

	std::auto_ptr<Point> ap2(ap); // 在语法层面来说，该表达式是要进行复制的
	ap->display();				  // 但实际执行的时候，已经发生了所有权的转移
	ap2->display();				  // 该操作存在缺陷, 现在已不推荐使用

	return 0;
}

