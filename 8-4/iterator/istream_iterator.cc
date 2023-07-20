 ///
 /// @file    istream_iterator.cc
 /// @author  gsw(1499186594@qq.com)
 ///
   

#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
using std::cin;
using std::cout;
using std::endl;
using std::istream_iterator;
using std::ostream_iterator;
using std::vector;

int main(void)
{
	// int num;
	// cin >> num;

	vector<int> numbers;			// ==>   numbers.push_back(num);
	istream_iterator<int> isi(cin); // 适配器设计模式的实现, 开始输入数据

	// 目标： 是要从终端获取数据, 再放入容器
	//
	// 手段： 将终端（输入流）看成一个容器A，要把数据从容器A复制到容器B，
	//	     既然是对容器进行操作，那就可以借助于迭代器来完成
	// 解决方案: istream_iterator  -> 类模板 -> 实现的是输入迭代器的功能

	// copy(isi, istream_iterator<int>(), numbers.begin());
	copy(isi, istream_iterator<int>(), std::back_inserter(numbers)); // 插入迭代器

	copy(numbers.begin(), numbers.end(), ostream_iterator<int>(cout, "\n"));

	return 0;
}

