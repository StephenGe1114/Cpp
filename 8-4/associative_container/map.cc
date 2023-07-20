 ///
 /// @file    map.cc
 /// @author  gsw(1499186594@qq.com)
 ///
   

#include <iostream>
#include <map>
#include <string>
using std::cout;
using std::endl;
using std::map;
using std::string;

int array[5] = {1, 2, 3, 4, 5};

template <typename Container>
void display(const Container &c)
{
	typename Container::const_iterator it;
	for (it = c.begin(); it != c.end(); ++it)
	{
		cout << it->first << " --> " << it->second << endl;
	}
}

void test0(void)
{
	// map里面存放的元素是std::pair
	//
	// map默认情况下， 按升序的方式进行排列
	// 不能存放挂关键字相同的元素
	//
	map<int, string, std::greater<int>> cities{
		std::pair<int, string>(1, "北京"),
		std::pair<int, string>(2, "上海"),
		std::make_pair(3, "广州"),
		std::make_pair(4, "深圳"),
		std::make_pair(1, "杭州")};
	display(cities);

	// map可以使用下标访问运算符, 它既可以查找元素，也可以添加元素，还可以修改元素
	//
	// 如果下标对应的元素存在，可以直接访问到, 也可以直接赋值或者修改值
	// 如果下标不存在，则直接创建一个相应的元素，但value的值是一个默认值
	//

	cout << cities[1] << endl;
	cout << cities[0] << endl
		 << endl;
	cities[2] = "武汉";
	cities[0] = "南京";
	display(cities);
}

void test1(void)
{
	// map里面存放的元素是std::pair
	//
	// map默认情况下， 按升序的方式进行排列
	// 不能存放挂关键字相同的元素
	//
	map<string, string, std::greater<string>> cities{
		std::pair<string, string>("aa", "北京"),
		std::pair<string, string>("bb", "上海"),
		std::make_pair("cc", "广州"),
		std::make_pair("dd", "深圳"),
		std::make_pair("aa", "杭州")};
	display(cities);

	// map可以使用下标访问运算符, 它既可以查找元素，也可以添加元素，还可以修改元素
	//
	// 如果下标对应的元素存在，可以直接访问到, 也可以直接赋值或者修改值
	// 如果下标不存在，则直接创建一个相应的元素，但value的值是一个默认值
	//

	cout << cities["aa"] << endl;
	cout << cities["bb"] << endl
		 << endl;
	cities["cc"] = "武汉";
	cities["ee"] = "南京";
	display(cities);
}

int main(void)
{
	test0();
	cout << "------------------------------------------" << endl;
	test1();
	return 0;
}

