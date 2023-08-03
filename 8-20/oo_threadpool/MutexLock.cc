 ///
 /// @file    MutexLock.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-08-20 11:44:51
 ///
 
#include "MutexLock.h"

using namespace wd;


MutexLock::MutexLock()
: _islocking(false)
{
	pthread_mutex_init(&_mutex, NULL);	
}

MutexLock::~MutexLock()
{
	pthread_mutex_destroy(&_mutex);
}

void MutexLock::lock()
{
	pthread_mutex_lock(&_mutex);
	_islocking = true;
}

void MutexLock::unlock()
{
	pthread_mutex_unlock(&_mutex);
	_islocking = false;
}


