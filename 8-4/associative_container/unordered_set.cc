 ///
 /// @file    unordered_set.cc
 /// @author  gsw(1499186594@qq.com)
 ///


#include <iostream>
#include <unordered_set>
using std::cout;
using std::endl;
using std::unordered_set;

class Point
{
public:
	Point(int ix = 0, int iy = 0)
		: _ix(ix), _iy(iy)
	{
		cout << "Point(int=0, int= 0)" << endl;
	}

	int getX() const { return _ix; }
	int getY() const { return _iy; }

	~Point()
	{
		cout << "~Point()" << endl;
	}

	friend std::ostream &operator<<(std::ostream &os, const Point &rhs);
	friend bool operator==(const Point &lhs, const Point &rhs);

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

// 判断两个对象是否相等
bool operator==(const Point &lhs, const Point &rhs)
{
	return lhs._ix == rhs._ix &&
		   rhs._iy == rhs._iy;
}

// 为了直接使用官方的hash的默认设置方式
// 需要重载的hash在std当中
namespace std
{
	// std::hash
	// 实现是std::hash的一个特化版本
	template <>
	struct hash<Point>
	{
		size_t operator()(const Point &lhs) const
		{
			return (std::hash<int>()(lhs.getX()) << 1) ^ (std::hash<int>()(lhs.getY()) >> 1);
		}
	};
} // end of namespace std

struct PointHasher
{
	size_t operator()(const Point &lhs) const
	{
		return (std::hash<int>()(lhs.getX()) << 1) ^ (std::hash<int>()(lhs.getY()) >> 1);
	}
};

void test0(void)
{
	unordered_set<int> sets{5, 3, 2, 1, 3, 2, 8, 0, 9};
	for (auto &elem : sets)
	{
		cout << elem << endl;
	}
}

void test1(void)
{
	unordered_set<Point> sets{
		Point(1, 2),
		Point(3, 4),
		Point(1, 2),
		Point(5, 6)};

	for (auto &elem : sets)
	{
		cout << elem << endl;
	}
}

void test2(void)
{
	unordered_set<Point, PointHasher> sets{
		Point(1, 2),
		Point(3, 4),
		Point(1, 2),
		Point(5, 6)};

	for (auto &elem : sets)
	{
		cout << elem << endl;
	}
}

int main(void)
{
	test0();
	cout << "--------------------------------------------" << endl;
	test1();
	cout << "--------------------------------------------" << endl;
	test2();

	return 0;
}

