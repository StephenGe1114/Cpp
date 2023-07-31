 ///
 /// @file    circle_reference2.cc
 /// @author  gsw(1499186594@qq.com)
 ///
   
#include <iostream>
#include <memory>
using std::cout;
using std::endl;
using std::shared_ptr; // 强引用智能指针
using std::weak_ptr;   // 弱引用智能指针, 并不能访问托管的资源

class Child; // 类的前向声明

class Parent
{
public:
	Parent() { cout << "Parent()" << endl; }
	~Parent() { cout << "~Parent()" << endl; }

	weak_ptr<Child> _pChild;
};

class Child
{
public:
	Child() { cout << "Child()" << endl; }
	~Child() { cout << "~Child()" << endl; }
	shared_ptr<Parent> _pParent;
};

int main(void)
{
	shared_ptr<Parent> parent(new Parent());
	shared_ptr<Child> child(new Child());

	cout << "parent's use_count () = " << parent.use_count() << endl;
	cout << "child's use_count () = " << child.use_count() << endl;
	cout << "进行互指之后：" << endl;
	// 问题： shared_ptr的循环引用会导致内存泄漏
	parent->_pChild = child;  // wp = sp; 弱引用智能指针进行复制或者赋值 不会导致引用计数加1
	child->_pParent = parent; // 当shared_ptr对象被销毁时，引用计数先减1，直到引用计数变为0时，才会
							  // 真正释放所托管的对象
	cout << "parent's use_count () = " << parent.use_count() << endl;
	cout << "child's use_count () = " << child.use_count() << endl;

	return 0;
}

