 ///
 /// @file    Stack.cc
 /// @author  gsw(1499186594@qq.com)
 ///
   

#include <iostream>
using std::cout;
using std::endl;

class Stack
{
public:
	Stack(int size = 10)
		: _top(-1), _size(size), _array(new int[_size]())
	{
	}

	bool full() const
	{
		return _top == _size - 1;
	}

	bool empty() const
	{
		return _top == -1;
	}

	int top() const
	{
		return _array[_top];
	}

	void push(int number)
	{
		if (!full())
		{
			_array[++_top] = number;
		}
		else
		{
			cout << "stack has full, cannot push any element!" << endl;
		}
	}

	void pop()
	{
		if (!empty())
		{
			--_top;
		}
		else
		{
			cout << "stack has empty " << endl;
		}
	}

	~Stack()
	{
		delete[] _array;
	}

private:
	int _top;
	int _size;
	int *_array;
};

int main(void)
{
	Stack stack;
	cout << "此时栈是否为空? " << stack.empty() << endl;
	stack.push(1);
	cout << "此时栈是否为空? " << stack.empty() << endl;

	for (int idx = 2; idx != 11; ++idx)
	{
		stack.push(idx);
	}
	cout << "此时栈是否已满? " << stack.full() << endl;

	while (!stack.empty())
	{
		cout << stack.top() << endl;
		stack.pop();
	}
	cout << "此时栈是否为空? " << stack.empty() << endl;
	return 0;
}

