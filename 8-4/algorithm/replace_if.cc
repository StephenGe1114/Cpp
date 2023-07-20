 ///
 /// @file    replace_if.cc
 /// @author  gsw(1499186594@qq.com)
 ///

#include <iostream>
#include <algorithm>
#include <vector>
using std::cout;
using std::endl;
using std::for_each;
using std::replace_if;
using std::vector;

int main(void)
{
	vector<int> numbers{1, 2, 3, 4, 5, 6};
	std::less<int> lt; // lt(num1, num2); bind1st -> lt(3, num2)
					   //				bind2nd -> lt(num1, 3)

	// replace_if(numbers.begin(), numbers.end(), std::bind1st(lt, 3), 8);
	replace_if(numbers.begin(), numbers.end(), [](int num)
			{
			    return num < 3;
			}, 8);
	for_each(numbers.begin(), numbers.end(), [](int num)
			 { cout << num << " "; });

	return 0;
}

