 ///
 /// @file    TaskQueue.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-08-20 11:54:36
 ///
 
#include "TaskQueue.h"


using namespace wd;

TaskQueue::TaskQueue(size_t queSize)
: _queSize(queSize)
, _mutex()
, _notFull(_mutex)
, _notEmpty(_mutex)
{}

bool TaskQueue::empty()  const
{
	return _que.size() == 0;
}

bool TaskQueue::full() const
{
	return _que.size() == _queSize;
}

// push方法运行在生产者线程
void TaskQueue::push(const ElemType & value)
{
	MutexLockGuard autolock(_mutex);
	while(full()) {       //使用while是为了防止条件变量被异常唤醒
		_notFull.wait();
	}

	_que.push(value);
	_notEmpty.notify();
}

//运行在消费者线程
ElemType TaskQueue::pop()
{
	MutexLockGuard autolock(_mutex);
	while(empty()) {
		_notEmpty.wait();
	}

	ElemType tmp = _que.front();
	_que.pop();
	_notFull.notify();

	return tmp;
}

