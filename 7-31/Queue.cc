 ///
 /// @file    Queue.cc
 /// @author  gsw(1499186594@qq.com)
 ///
   

#include <iostream>
using std::cout;
using std::endl;

class Queue
{
public:
	Queue(int size = 10)
		: _size(size), _head(0), _tail(0), _array(new int[_size]())
	{
	}

	bool empty() const
	{
		return _head == _tail;
	}

	bool full() const
	{
		return _head == ((_tail + 1) % _size);
	}

	void push(int number)
	{
		if (!full())
		{
			_array[_tail++] = number;
			_tail %= _size;
		}
		else
		{
			cout << "queue is full, cannnot push any more data！" << endl;
		}
	}

	void pop()
	{
		if (!empty())
		{
			++_head;
			_head %= _size;
		}
		else
		{
			cout << "queue is empty, no more data !" << endl;
		}
	}

	int front() const
	{
		return _array[_head];
	}

	int back() const
	{
		return _array[(_tail - 1 + _size) % _size];
	}

	~Queue()
	{
		delete[] _array;
	}

private:
	int _size;
	int _head;
	int _tail;
	int *_array;
};

int main(void)
{
	Queue que;
	cout << "此时队列是否为空? " << que.empty() << endl;
	que.push(1);
	cout << "此时队列是否为空? " << que.empty() << endl;

	for (int idx = 2; idx != 11; ++idx)
	{
		que.push(idx);
	}
	cout << "队头的元素是： " << que.front() << endl;
	cout << "队尾的元素是: " << que.back() << endl;

	que.pop();
	que.push(10);
	cout << "队头的元素是： " << que.front() << endl;
	cout << "队尾的元素是: " << que.back() << endl;

	cout << "此时队列是否已满? " << que.full() << endl;

#if 1
	while (!que.empty())
	{
		cout << que.front() << endl;
		que.pop();
	}
	cout << "此时队列是否为空? " << que.empty() << endl;
#endif
	return 0;
}

