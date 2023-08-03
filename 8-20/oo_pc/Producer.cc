 ///
 /// @file    Producer.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-08-20 11:37:00
 ///
 
#include "Producer.h"
#include "TaskQueue.h"

#include <unistd.h>
#include <stdlib.h>

#include <iostream>
using std::cout;
using std::endl;
 
using namespace wd;

Producer::Producer(TaskQueue & taskQue)
: _taskQue(taskQue)
{};

void Producer::run()
{
	::srand(::clock());
	int cnt = 10;
	while(cnt--)
	{
		int number = ::rand() % 100;
		::sleep(1);
		_taskQue.push(number);
		cout << "producer thread " << pthread_self() << " prudoce a number:" << number << endl;
	}
}
