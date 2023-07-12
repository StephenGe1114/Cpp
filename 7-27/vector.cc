 ///
 /// @file    vector.cc
 /// @author  gsw(1499186594@qq.com)
 ///
   

#include <iostream>
#include <string>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

void printCapacity(vector<int> & vec)
{
	cout << "vec's size = " << vec.size() << endl;
	cout << "vec's capacity = " << vec.capacity() << endl;
}


int main(void)
{
	//动态数组扩容的策略：
	//	  当数组的元素个数与能容纳元素的个数相等时，
	//	  1. 申请空间的大小是原来的空间的2倍,
	//	  2. 把原来空间的数据复制新空间之上
	//	  3. 回收原来申请的空间
	//	  4. 添加新的元素

	vector<int> numbers;
	//numbers.reserve(100);
	cout << "sizeof(numbers) = " << sizeof(numbers) << endl;
	printCapacity(numbers);
	numbers.push_back(1);
	printCapacity(numbers);
	numbers.push_back(2);
	printCapacity(numbers);
	numbers.push_back(3);
	printCapacity(numbers);
	numbers.push_back(4);
	printCapacity(numbers);
	numbers.push_back(5);
	printCapacity(numbers);
	numbers.push_back(6);
	printCapacity(numbers);
	numbers.push_back(7);
	printCapacity(numbers);
	numbers.push_back(8);
	cout << "sizeof(numbers) = " << sizeof(numbers) << endl;

	for(size_t idx = 0; idx != numbers.size(); ++idx)
	{
		cout << numbers[idx] << " ";
	}
	cout << endl << endl;


	for(auto & number : numbers)
	{
		cout << number << " ";
	}
	cout << endl << endl;

}

