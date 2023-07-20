 ///
 /// @file    template.h
 /// @author  gsw(1499186594@qq.com)
 ///
   

#ifndef __TEMPLATE_H__
#define __TEMPLATE_H__

// 模板的实现是可以分成声明和实现的;
// 但是在include头文件的时候，必须要看到模板的全部实现;
// 否则编译不通过
template <typename Type>
Type add(Type x, Type y);

#include "template.txx"

#endif

