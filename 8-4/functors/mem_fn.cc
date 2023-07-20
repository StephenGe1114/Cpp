 ///
 /// @file    mem_fn.cc
 /// @author  gsw(1499186594@qq.com)
 ///
   

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using std::cout;
using std::endl;
using std::vector;

class Number
{
public:
	Number(int ivalue)
		: _ivalue(ivalue)
	{
		cout << "Number(int)" << endl;
	}

	void display() const { cout << _ivalue << " "; }

	bool isEven() const
	{
		return (_ivalue % 2 == 0);
	}

	bool isPrime() const
	{
		if (_ivalue == 1)
			return false;
		for (int idx = 2; idx <= _ivalue / 2; ++idx)
		{
			if (_ivalue % idx == 0)
			{
				return false;
			}
		}
		return true;
	}

private:
	int _ivalue;
};

int main(void)
{
	vector<Number> numbers;
	for (int idx = 1; idx != 20; ++idx)
	{
		numbers.push_back(Number(idx));
	}

	auto f = std::mem_fn(&Number::display);
	f(&numbers[0]);

	for_each(numbers.begin(), numbers.end(), std::mem_fn(&Number::display));
	cout << endl;

	numbers.erase(std::remove_if(numbers.begin(), numbers.end(), std::mem_fn(&Number::isEven)),
				  numbers.end());
	for_each(numbers.begin(), numbers.end(), std::mem_fn(&Number::display));
	cout << endl;

	numbers.erase(std::remove_if(numbers.begin(), numbers.end(), std::mem_fn(&Number::isPrime)),
				  numbers.end());
	for_each(numbers.begin(), numbers.end(), std::mem_fn(&Number::display));
	cout << endl;

	return 0;
}

