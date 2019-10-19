#include <stdio.h>
#include "add_func.h"
#include "sub_func.h"
#include "mul_func.h"
#include "div_func.h"

void main()
{
	float result;	
	result = func_Add(12,36);
	printf("더한값은 : %f \n",result);

	result = func_Sub(12,36);
	printf("뺀값은 : %f \n", result);

	result = func_Mul(12,36);
	printf("곱한 값은 : %f \n", result);

	result = func_Div(12,36);
	printf("나눈 값은 : %f \n", result);
}
