 ///
 /// @file    Thread.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-08-20 09:47:14
 ///
 
#ifndef __WD_THREAD_H__
#define __WD_THREAD_H__
#include <pthread.h>


namespace wd
{

class Thread
{
public:
	Thread()
	: _pthid(0)
	, _isRunning(false)
	{}

	virtual	~Thread();

	void start();
	void join();

	pthread_t getThreadId() const {	return _pthid;	}

private:
	virtual void run() =0;

	static void * threadFunc(void * arg);
private:
	pthread_t _pthid;
	bool _isRunning;
};

}//end of namespace wd


#endif
