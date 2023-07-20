 ///
 /// @file    reverse_iterator.cc
 /// @author  gsw(1499186594@qq.com)
 ///
   

#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

int main(void)
{
	vector<int> numbers{1, 2, 3, 4, 5, 6};
	vector<int>::reverse_iterator rit;
	for (rit = numbers.rbegin(); rit != numbers.rend(); ++rit)
	{
		cout << *rit << " ";
	}
	cout << endl;

	return 0;
}

