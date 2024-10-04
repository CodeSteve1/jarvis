#include <stdio.h>
#include "addition.h"
#include "multiplication.h"
#include "app2.h"
//#include "multiplication.h"
int main()
{
    int add_val = Addition(5, 5);
    printf("Added_value is : %d \n", add_val);
    int mul_val = Multiplication(5, 5);
    printf("Multiplied Value is : %d \n", mul_val);
    APP2();
    return 0;
    
}