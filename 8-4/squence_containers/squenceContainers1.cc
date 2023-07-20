 ///
 /// @file    squenceContainers1.cc
 /// @author  gsw(1499186594@qq.com)
 ///
   

#include <iostream>
#include <vector>
#include <deque>
#include <list>
using std::cout;
using std::deque;
using std::endl;
using std::list;
using std::vector;

template <typename Container>
void display(const Container &c)
{
	typename Container::const_iterator cit;
	for (cit = c.begin(); cit != c.end(); ++cit)
	{
		cout << *cit << " ";
	}
	cout << endl;
}

void test0(void)
{
	int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	// vector<int> numbers(10, 1);

	// vector<int> numbers(array, array + 10);
	// C++11的构造方式
	vector<int> numbers{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	display(numbers);

	/*
		//迭代器范围： 左闭右开的区间 [  )
		vector<int>::const_iterator cit;
		for(cit = numbers.begin(); cit != numbers.end(); ++cit)
		{
			cout << *cit << " ";
		}
		cout << endl;
		*/

	// display(numbers);

	deque<int> deNumbers(array, array + 10);
	display(deNumbers);

	list<int> listNumbers(array, array + 10);
	display(listNumbers);
}

void test1(void)
{
	// vector没有提供push_front/pop_front操作, 原因是：如果提供，其时间复杂度为O(N)

	vector<int> vecNumbers{1, 2, 3, 4, 5};
	vecNumbers.push_back(6);											  // 时间复杂度 O(1)
	vector<int>::iterator it = vecNumbers.insert(vecNumbers.begin(), 11); // 时间复杂度O(N)
	cout << *it << endl;

	cout << "vecNumbers[0] = " << vecNumbers[0] << endl;
	// vecNumbers.clear();
	cout << "vecNumbers.size() = " << vecNumbers.size() << endl;
	cout << "vecNumbers.capacity() = " << vecNumbers.capacity() << endl;
	vecNumbers.shrink_to_fit(); // 释放掉不需要的内存， size() == capacity()
	cout << "vecNumbers.size() = " << vecNumbers.size() << endl;
	cout << "vecNumbers.capacity() = " << vecNumbers.capacity() << endl;
	display(vecNumbers);

	cout << endl;

	deque<int> deNumbers{1, 2, 3, 4, 5};
	deNumbers.push_back(6); // 时间复杂度 O(1)
	deNumbers.push_front(0);
	deque<int>::iterator dit = deNumbers.insert(++deNumbers.begin(), 12); // 时间复杂度O(N)
	cout << *dit << endl;
	cout << "deNumbers[0] = " << deNumbers[0] << endl;
	deNumbers.clear();
	// deque没有capacity()
	display(deNumbers);

	cout << endl;

	list<int> liNumbers{1, 2, 3, 4, 5};
	liNumbers.push_back(6); // 时间复杂度 O(1)
	liNumbers.push_front(0);
	list<int>::iterator lit = liNumbers.insert(++liNumbers.begin(), 13); // 时间复杂度O(1)
	liNumbers.insert(liNumbers.begin(), vecNumbers.begin(), vecNumbers.end());
	cout << *lit << endl;

	auto lit2 = liNumbers.end();
	cout << *--lit2 << endl;
	// list不支持下标访问运算符, 只支持双向访问（向前或向后）
	// cout << "liNumbers[0] = " << liNumbers[0] << endl;
	liNumbers.clear();
	// list没有capacity();
	display(liNumbers);
}

int main(void)
{
	// test0();
	test1();

	return 0;
}

