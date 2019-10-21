#include <stdio.h>
#include <stdlib.h>


void my_Assert(int expression)
{
	if(!expression){
		printf("%s:%s:%d failed.\n",__func__,__FILE__,__LINE__);
		abort();
	}
}

void foo(int num)
{
	my_Assert( ((num >= 0) && (num <= 100)));

	printf("foo: num = %d\n", num);
}

void main(int argc, char *argv[])
{
	int num;
	
	if (argc < 2){
	fprintf(stderr, "Usage: assert_test aNumber\n(0 <= aNumber <=\n");
	exit(1);
	}
	
	num = atoi(argv[1]);
	foo(num);
}


