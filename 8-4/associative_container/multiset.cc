 ///
 /// @file    multiset.cc
 /// @author  gsw(1499186594@qq.com)
 ///
   

#include <math.h>
#include <iostream>
#include <set>
#include <utility>
#include <string>
using std::cout;
using std::endl;
using std::multiset;
using std::string;

template <typename Container>
void display(const Container &c)
{
	typename Container::const_iterator sit = c.begin();
	while (sit != c.end())
	{
		cout << *sit << " ";
		++sit;
	}
	cout << endl;
}

void test0(void)
{
	// multiset默认情况下，会按升序的方式进行排列
	// multiset能存放重复的元素
	//
	// multiset的底层实现采用的是红黑树 --> 动态平衡二叉树 --> 左右子树的高度差不会超过1
	//							  --> 查找任意元素的时间复杂度为O(logN) --> 二分查找
	//
	int array[10] = {3, 2, 6, 5, 3, 4, 7, 8, 1, 5};
	multiset<int, std::greater<int>> multisetInt(array, array + 10);
	display(multisetInt);

	// multiset不能使用下标访问运算符
	// multisetInt[0];
	// multiset<int>::iterator it = multisetInt.begin();
	//*it = 10;//error, 只能读取multiset中的元素，但是不能进行修改

	// 添加新的元素
	auto ret = multisetInt.insert(10);
	cout << "*ret = " << *ret << endl;
	display(multisetInt);

	// 查找方式
	size_t cnt = multisetInt.count(3);
	cout << "cnt = " << cnt << endl;

#if 1
	auto iter = multisetInt.find(5);
	cout << *iter << endl;
	++iter;
	cout << *iter << endl;
#endif
	std::pair<multiset<int>::iterator, multiset<int>::iterator> mret = multisetInt.equal_range(5);
	cout << endl
		 << ">> equal_range：" << endl;
	while (mret.first != mret.second)
	{
		cout << *(mret.first) << endl;
		++(mret.first);
	}
}

class Point
{
public:
	Point(int ix, int iy)
		: _ix(ix), _iy(iy)
	{
	}

	friend std::ostream &operator<<(std::ostream &os, const Point &rhs);

	float distance() const
	{
		return sqrt(_ix * _ix + _iy * _iy);
	}

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

bool operator<(const Point &lhs, const Point &rhs)
{
	return lhs.distance() < rhs.distance();
}

struct Compare
{
	bool operator()(const Point &lhs, const Point &rhs) const
	{
		return lhs.distance() < rhs.distance();
	}
};

void test1(void)
{
	// multiset<Point, Compare> multisetPoint{
	multiset<Point> multisetPoint{
		Point(1, 2),
		Point(3, 4),
		Point(5, 6),
		Point(-1, 3),
		Point(1, 2),
	};
	for (auto &point : multisetPoint)
	{
		cout << point << endl;
	}
}

void test2(void)
{
	std::pair<string, int> value("hello", 100);
	cout << value.first << " --> " << value.second << endl;
}

int main(void)
{
	test0();
	cout << "------------------------------------------" << endl;
	test1();
	cout << "------------------------------------------" << endl;
	test2();
	return 0;
}

