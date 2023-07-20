 ///
 /// @file    templateStack.cc
 /// @author  gsw(1499186594@qq.com)
 ///
   

#include <iostream>
#include <vector>
#include <string>
using std::cout;
using std::endl;
using std::string;
using std::vector;

// 在C++11之前，类模板的模板参数就可以设置默认值
template <typename Type, size_t kSize = 10>
class Stack
{
public:
	Stack()
		//: _top(-1)
		: _data()
	{
		_data.reserve(kSize);
	}

	template <typename T>
	void display(T t);

	bool full() const;
	bool empty() const;

	void push(const Type &element);
	void pop();
	Type top();

private:
	// int _top;
	vector<Type> _data;
};

template <typename Type, size_t kSize>
bool Stack<Type, kSize>::full() const
{
	return _data.size() == kSize;
}

template <typename Type, size_t kSize>
bool Stack<Type, kSize>::empty() const
{
	return _data.size() == 0;
}

template <typename Type, size_t kSize>
void Stack<Type, kSize>::push(const Type &element)
{
	if (!full())
	{
		_data.push_back(element);
		//++_top;
	}
	else
	{
		cout << "stack is full, cannot push data any more !" << endl;
	}
}

template <typename Type, size_t kSize>
void Stack<Type, kSize>::pop()
{
	if (!empty())
	{
		_data.pop_back();
		//--_top;
	}
	else
	{
		cout << "stack is empty, no more data!" << endl;
	}
}

template <typename Type, size_t kSize>
Type Stack<Type, kSize>::top()
{
	// return _data[_top];
	return _data.back();
}

template <typename Type, size_t kSize>
template <typename T>
void Stack<Type, kSize>::display(T t)
{
	cout << "t = " << t << endl;
}

int test0(void)
{
	vector<int> numbers;
	Stack<int> stack;
	cout << "此时栈是否为空?" << stack.empty() << endl;
	stack.push(1);
	cout << "此时栈是否为空?" << stack.empty() << endl;

	for (int idx = 2; idx != 11; ++idx)
	{
		stack.push(idx);
	}
	cout << "此时栈是否已满?" << stack.full() << endl;

	while (!stack.empty())
	{
		cout << stack.top() << endl;
		stack.pop();
	}
	cout << "此时栈是否为空?" << stack.empty() << endl;
	return 0;
}

int test1(void)
{
	Stack<string> stack;
	cout << "此时栈是否为空?" << stack.empty() << endl;
	char ch = 'a';
	stack.push(string(3, ch));
	cout << "此时栈是否为空?" << stack.empty() << endl;

	for (int idx = 1; idx != 11; ++idx)
	{
		string str(3, ch + idx);
		stack.push(str);
	}
	cout << "此时栈是否已满?" << stack.full() << endl;

	while (!stack.empty())
	{
		cout << stack.top() << endl;
		stack.pop();
	}
	cout << "此时栈是否为空?" << stack.empty() << endl;
	return 0;
}

int main(void)
{
	test1();
	return 0;
}

