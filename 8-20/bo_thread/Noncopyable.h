 ///
 /// @file    Noncopyable.h
 /// @author  gsw(1499186594@qq.com)
 ///
   

#ifndef __WD_NONCOPYABLE_H__
#define __WD_NONCOPYABLE_H__

class Noncopyable
{
protected:
	Noncopyable() {}
	~Noncopyable(){}

	Noncopyable(const Noncopyable &) = delete;
	Noncopyable & operator=(const Noncopyable &) = delete;
};


#endif


