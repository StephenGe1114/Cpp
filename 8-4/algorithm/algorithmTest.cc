 ///
 /// @file    algorithmTest.cc
 /// @author  gsw(1499186594@qq.com)
 ///
   

#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
using std::cout;
using std::endl;
using std::ostream_iterator;
using std::unique;
using std::vector;

int test0(void)
{
	vector<int> numbers{1, 2, 2, 2, 3, 3, 4, 4, 5, 6};
	copy(numbers.begin(), numbers.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

	numbers.erase(unique(numbers.begin(), numbers.end()), numbers.end());

	copy(numbers.begin(), numbers.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
	return 0;
}

void test1(void)
{
	vector<int> numbers{1, 2, 2, 3, 3, 4, 2, 4, 5, 6};
	copy(numbers.begin(), numbers.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
	// erase-remove惯用法
	numbers.erase(std::remove(numbers.begin(), numbers.end(), 2), numbers.end());
	copy(numbers.begin(), numbers.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

	/*
	 *	// 这种方式不推荐使用
		for(auto it = numbers.begin(); it != numbers.end(); ++it)
		{
			if(*it == 2) {
				numbers.erase(it);
			}
		}
		*/
}

void test2(void)
{ // 在遍历容器的过程中，尽量不要删除或者添加元素，因为有可能产生一些不可以预测的情况
	vector<int> numbers;
	numbers.push_back(1);
	bool flag = true;
	for (auto it = numbers.begin(); it != numbers.end(); ++it)
	{
		cout << *it << " ";
		if (flag)
		{
			numbers.push_back(2); // 导致了迭代器it已经失效
			flag = false;
		}
	}
}

int main(void)
{
	test1();
	cout << "------------------------------------------------" << endl;
	test2();
	return 0;
}

