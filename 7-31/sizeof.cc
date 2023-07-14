 ///
 /// @file    sizeof.cc
 /// @author  gsw(1499186594@qq.com)
 ///
   

#include <stdio.h>
#include <iostream>
using std::cout;
using std::endl;

int main(void)
{
	int a = 10;
	printf("sizeof(a) = %d\n", sizeof a);
	printf("sizeof(a) = %d\n", sizeof(int));

	return 0;
}

