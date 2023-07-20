 ///
 /// @file    insert_iterators.cc
 /// @author  gsw(1499186594@qq.com)
 ///
   

#include <iostream>
#include <iterator>
#include <vector>
#include <list>
#include <algorithm>
using std::back_insert_iterator;
using std::copy;
using std::cout;
using std::endl;
using std::front_insert_iterator;
using std::insert_iterator;
using std::list;
using std::ostream_iterator;
using std::vector;

int main(void)
{
	vector<int> vec{1, 2, 3};
	list<int> li{4, 5, 6};

	// 在尾部添加元素的迭代器，内部会调用 push_back方法， 使用的容器有vector, deque, list
	copy(vec.begin(), vec.end(), back_insert_iterator<list<int>>(li)); //
	copy(li.begin(), li.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

	// 在头部添加元素的迭代器，内部会调用 push_front方法， 使用的容器有deque, list
	copy(vec.begin(), vec.end(), front_insert_iterator<list<int>>(li));
	copy(li.begin(), li.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

	// 在任意位置添加元素的迭代器，内部会调用insert方法，基本上所有的容器都适用
	// 但是vector,deque不推荐使用
	auto lit = li.begin();
	++lit;
	++lit;
	copy(vec.begin(), vec.end(), insert_iterator<list<int>>(li, lit));
	copy(li.begin(), li.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
	return 0;
}

