
#include "Thread.h"

#include <unistd.h>
#include <stdlib.h>

#include <iostream>
#include <memory>
using std::cout;
using std::endl;
using std::unique_ptr;

class MyThread
	: public wd::Thread
{
	void run()
	{
		int cnt = 10;
		while (cnt--)
		{
			int number = ::rand() % 100;
			::sleep(1);
			cout << ">> subthread " << pthread_self() << ": number = " << number << endl;
		}
	}
};

int main(void)
{
	cout << "mainThread: " << pthread_self() << endl;
	unique_ptr<wd::Thread> p(new MyThread());
	p->start();
	cout << "mainThread: subthread  " << p->getThreadId() << endl;
	p->join();

	return 0;
}
